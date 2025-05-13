#include "StdAfx.h"
#include "LogFileHeater.h"

#include "Util/Util.h"

CLogFileHeater::CLogFileHeater()
{
	m_hFile = INVALID_HANDLE_VALUE;

#ifdef DEF_THREAD_LOG
	//
	m_bStop = TRUE;
	m_hThread = NULL;
	m_hEvent = NULL;
	m_hStopEvent = NULL;
#endif

	memset(m_szDirLocation, 0x00, sizeof(TCHAR)*MAX_FILE_PATH_LEN);
	memset(m_szLogFilePath, 0x00, sizeof(TCHAR)*MAX_FILE_PATH_LEN);
	memset(&m_stLogTime, 0x00, sizeof(SYSTEMTIME));

}

CLogFileHeater::~CLogFileHeater()
{
	Close();
}

void CLogFileHeater::UpdateLogDirectory(TCHAR* pszDirPath)
{
	if (NULL == pszDirPath)
		return;

	if (CUtil::StringCompare(m_szDirLocation, pszDirPath))
	{
		// do nothing...
	}
	else
	{
		CUtil::StringCopy(m_szDirLocation, pszDirPath);
		Close();
	}
}

BOOL CLogFileHeater::Open(const TCHAR* pszLocation)
{
	if (NULL == pszLocation)
		return FALSE;

	if (INVALID_HANDLE_VALUE != m_hFile)
		Close();

	CUtil::StringCopy(m_szDirLocation, pszLocation);
	::GetLocalTime(&m_stLogTime);

	CUtil::StringFormat(m_szLogFilePath, MAX_FILE_PATH_LEN, _T("%s\\%04d%02d%02d_%02d%02d%02d_heater.csv"),
		m_szDirLocation,
		m_stLogTime.wYear,
		m_stLogTime.wMonth,
		m_stLogTime.wDay,
		m_stLogTime.wHour,
		m_stLogTime.wMinute,
		m_stLogTime.wSecond);

	m_hFile = ::CreateFile(m_szLogFilePath,
		GENERIC_READ | GENERIC_WRITE,
		FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL,
		CREATE_ALWAYS,
		FILE_FLAG_WRITE_THROUGH,
		NULL);
	if (INVALID_HANDLE_VALUE == m_hFile)
		return FALSE;

	{
		char szLog[1024] = {0,};
		sprintf(szLog, _T("Create log file (%s)\r\n"),	m_szLogFilePath);
		Write(szLog);
		WriteHeader();
	}

#ifdef DEF_THREAD_LOG
	m_hEvent = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_hEvent)
	{
		Close();
		return FALSE;
	}
	m_hStopEvent = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_hStopEvent)
	{
		Close();
		return FALSE;
	}

	DWORD dwThreadId = 0;
	m_hThread = ::CreateThread(0, 0, ThreadProc, LPVOID(this), 0, &dwThreadId);
	if (NULL == m_hThread)
	{
		Close();
		return FALSE;
	}
	//::SetThreadPriority(m_hThread, PROC_THREAD_PRIORITY_FLAG);
	m_bStop = FALSE;
#endif

	return TRUE;
}

void CLogFileHeater::Close()
{
#ifdef DEF_THREAD_LOG
	m_bStop = TRUE;

	///
	if (m_hEvent)
	{
		::SetEvent(m_hEvent);

		if (m_hStopEvent)
		{
			::ResetEvent(m_hStopEvent);
			::WaitForSingleObject(m_hStopEvent, 5000);
			::CloseHandle(m_hStopEvent);
		}
		::CloseHandle(m_hEvent);
	}

	if (m_hThread)
		::CloseHandle(m_hThread);

	// Clear queue.
	{
		const int nText = 1024;
		char szText[nText] = { 0, };

		DWORD dwResult = 0;

		while (!m_LogQueue.empty())
		{
			INFO_LOG_BUF* pstLogBuf = (INFO_LOG_BUF*)m_LogQueue.front();
			m_LogQueue.pop();
			if (NULL == pstLogBuf)
				continue;

			// Write File...
			::WriteFile(m_hFile, pstLogBuf->m_pszLog, strlen(pstLogBuf->m_pszLog), &dwResult, NULL);
			//::FlushFileBuffers(m_hFile);

			if (pstLogBuf)
			{
				if (pstLogBuf->m_pszLog)
					delete[] pstLogBuf->m_pszLog;

				delete pstLogBuf;
			}
		}
	}

	m_hStopEvent = NULL;
	m_hEvent = NULL;
	m_hThread = NULL;
	//*/
#endif

	memset(m_szLogFilePath, 0x00, sizeof(TCHAR)*MAX_FILE_PATH_LEN);

	if (INVALID_HANDLE_VALUE != m_hFile)
	{
		::CloseHandle(m_hFile);
		m_hFile = INVALID_HANDLE_VALUE;
	}
}

BOOL CLogFileHeater::Write(char* pszLog)
{
#ifdef DEF_THREAD_LOG
	if (TRUE == m_bStop || NULL == m_hThread || NULL == pszLog)
		return FALSE;

	const int nLog = strlen(pszLog) + 1;

	INFO_LOG_BUF* pstLog = new INFO_LOG_BUF;
	if (pstLog)
	{
		SYSTEMTIME stTime;
		::GetLocalTime(&stTime);

		pstLog->m_pszLog = new char[nLog + 64];
		sprintf(pstLog->m_pszLog, _T("%04d%02d%02d %02d:%02d:%02d.%03d %s "), 
			stTime.wYear, stTime.wMonth, stTime.wDay, 
			stTime.wHour, stTime.wMinute, stTime.wSecond, stTime.wMilliseconds,
			pszLog);

		CSingleLock singleLock(&m_CriticalSection);
		singleLock.Lock();
		m_LogQueue.push(pstLog);
		singleLock.Unlock();

		SetLogEvent();
	}
#else
	if ( NULL==pszLog )
		return FALSE;

	if (INVALID_HANDLE_VALUE == m_hFile)
	{
		// Open Log File...
		this->Open(m_szDirLocation);
	}

	SYSTEMTIME stTime;
	::GetLocalTime(&stTime);

	char szString[1024] = { 0, };
	sprintf(szString, _T("%04d%02d%02d,%02d:%02d:%02d,%s"),
		stTime.wYear, stTime.wMonth, stTime.wDay,
		stTime.wHour, stTime.wMinute, stTime.wSecond, pszLog);

	DWORD dwResult = 0;
	if (INVALID_HANDLE_VALUE != m_hFile)
	{
		::WriteFile(m_hFile, szString, strlen(szString), &dwResult, NULL);
	}

#endif
	return TRUE;
}

BOOL CLogFileHeater::WriteHeader()
{
	SYSTEMTIME stTime;
	::GetLocalTime(&stTime);

	char szString[1024] = { 0, };
	
	std::string strHeader = "Date,Time";

	for (int i = 1; i < 27; i++){
		sprintf(szString, ",Heater %d", i);
		strHeader += szString;
	}
	strHeader += "\r\n";

	strcpy(szString, strHeader.c_str());

	//sprintf(szString, _T("Date,Time,Heater 1,Heater 2,Heater 3,Heater 4,Heater 5,Heater 6,Heater 7,Heater 8,Heater 9,\
						 Heater 10,Heater 11,Heater 12,Heater 13,Heater 14,Heater 15,Heater 16,Heater 17,Heater 18,\
						 Heater 19,Heater 20,Heater 21,Heater 22,Heater 23,Heater 24,Heater 25,Heater 26\r\n"));
	

	DWORD dwResult = 0;
	if (INVALID_HANDLE_VALUE != m_hFile)
	{
		::WriteFile(m_hFile, szString, strlen(szString), &dwResult, NULL);
	}
	
	return TRUE;
}

#ifdef DEF_THREAD_LOG
void CLogFileHeater::SetLogEvent()
{
	if (m_hEvent)
	{
		SetEvent(m_hEvent);
	}
}

DWORD WINAPI CLogFileHeater::ThreadProc(LPVOID lpArg)
{
	CLogFileHeater* pLogProc = (CLogFileHeater*)lpArg;

	return pLogProc->ThreadProc();
}

DWORD CLogFileHeater::ThreadProc(void)
{
	const int nText = 1024;
	char szText[nText] = { 0, };

	DWORD dwResult = 0;

	do
	{
		if (m_hEvent)
			::ResetEvent(m_hEvent);
		else
			break;

		if (::WaitForSingleObject(m_hEvent, INFINITE) != WAIT_OBJECT_0)
		{
			break;
		}
		else
		{
			if (m_bStop)
			{
				break;
			}

			while (!m_LogQueue.empty())
			{
				CSingleLock singleLock(&m_CriticalSection);
				singleLock.Lock();

				INFO_LOG_BUF* pstLogBuf = (INFO_LOG_BUF*)m_LogQueue.front();
				m_LogQueue.pop();

				singleLock.Unlock();

				if (NULL == pstLogBuf)
					continue;

				/*//
				{
					SYSTEMTIME stTime;
					::GetLocalTime(&stTime);

					if (m_stLogTime.wDay != stTime.wDay)
					{
						::FlushFileBuffers(m_hFile);
						::CloseHandle(m_hFile);
						m_hFile = INVALID_HANDLE_VALUE;

						TCHAR szPath[MAX_FILE_PATH_LEN] = { 0, };
						CUtil::StringFormat(szPath, MAX_FILE_PATH_LEN, _T("%s\\%04d%02d%02d_%02d%02d%02d_capture.log"),
							m_szDirLocation,
							stTime.wYear,
							stTime.wMonth,
							stTime.wDay,
							stTime.wHour,
							stTime.wMinute,
							stTime.wSecond );

						m_hFile = ::CreateFile(szPath,
							GENERIC_READ | GENERIC_WRITE,
							FILE_SHARE_READ | FILE_SHARE_WRITE,
							NULL,
							CREATE_ALWAYS,
							FILE_FLAG_WRITE_THROUGH,
							NULL);
						CUtil::StringCopy(m_szLogFilePath, szPath);
						m_stLogTime = stTime;
					}
				}
				//*/

				// Write File...
				::WriteFile(m_hFile, pstLogBuf->m_pszLog, strlen(pstLogBuf->m_pszLog), &dwResult, NULL);
				if (pstLogBuf)
				{
					if (pstLogBuf->m_pszLog)
						delete[] pstLogBuf->m_pszLog;

					delete pstLogBuf;
				}
			}
		}
	} while (FALSE == m_bStop);

	if (m_hStopEvent)
		::SetEvent(m_hStopEvent);

	m_bStop = TRUE;

	return 0;
}
#endif