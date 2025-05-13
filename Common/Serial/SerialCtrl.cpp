#include "stdafx.h"
#include "SerialCtrl.h"

#include "Util/Util.h"


CSerialCtrl::CSerialCtrl()
{
	memset(m_szDevice, 0x00, sizeof(TCHAR) * 128);
	m_dwBaudrate = 0;

#ifdef DEF_DUMP_SERIAL_MESSAGE
	{
		TCHAR szCurPath[MAX_FILE_PATH_LEN] = { 0, };
		TCHAR szDumpPath[MAX_FILE_PATH_LEN] = { 0, };

		SYSTEMTIME stLogTime;
		::GetLocalTime(&stLogTime);
		CUtil::GetCurrentDirectory(szCurPath, MAX_FILE_PATH_LEN);
		CUtil::StringFormat(szDumpPath, MAX_FILE_PATH_LEN, _T("%s\\%04d%02d%02d_%02d%02d%02d_serial_message.txt")
			, szCurPath,
			stLogTime.wYear,
			stLogTime.wMonth,
			stLogTime.wDay,
			stLogTime.wHour,
			stLogTime.wMinute,
			stLogTime.wSecond);

		m_hDumpFile = ::CreateFile(szDumpPath,
			GENERIC_READ | GENERIC_WRITE,
			FILE_SHARE_READ | FILE_SHARE_WRITE,
			NULL,
			CREATE_ALWAYS,
			FILE_FLAG_WRITE_THROUGH,
			NULL);
	}
#endif
}

CSerialCtrl::~CSerialCtrl()
{
	;
#ifdef DEF_DUMP_SERIAL_MESSAGE
	{
		if (INVALID_HANDLE_VALUE != m_hDumpFile)
		{
			::CloseHandle(m_hDumpFile);
		}
	}
#endif
}

BOOL CSerialCtrl::CheckPort(LPCTSTR pszCom)
{
	return CSerial::CheckPort(pszCom);
}

HANDLE CSerialCtrl::GetSerialHandle()
{
	return m_Serial.GetHandle();
}

BOOL CSerialCtrl::IsOpen()
{
	return m_Serial.IsOpen();
}


BOOL CSerialCtrl::Open(LPCTSTR lpszDevice, DWORD dwBaudrate)
{
	BOOL bResult = FALSE;

	if(NULL==lpszDevice)
		return bResult;

	if(m_Serial.IsOpen())
		m_Serial.Close();

	DWORD dwResult = m_Serial.Open(lpszDevice);

	//if(SUCCEEDED(dwResult))
	if(ERROR_SUCCESS==dwResult)
	{
		EBAUDRATE eSpeed = EBAUDRATE_UNKNOWN;

		if(110==dwBaudrate)				eSpeed = EBAUDRATE_110;
		else if(300==dwBaudrate)		eSpeed = EBAUDRATE_300;
		else if(600==dwBaudrate)		eSpeed = EBAUDRATE_600;
		else if(1200==dwBaudrate)		eSpeed = EBAUDRATE_1200;
		else if(2400==dwBaudrate)		eSpeed = EBAUDRATE_2400;
		else if(4800==dwBaudrate)		eSpeed = EBAUDRATE_4800;
		else if(9600==dwBaudrate)		eSpeed = EBAUDRATE_9600;
		else if(14400==dwBaudrate)		eSpeed = EBAUDRATE_14400;
		else if(19200==dwBaudrate)		eSpeed = EBAUDRATE_19200;
		else if(38400==dwBaudrate)		eSpeed = EBAUDRATE_38400;
		else if(56000==dwBaudrate)		eSpeed = EBAUDRATE_56000;
		else if(57600==dwBaudrate)		eSpeed = EBAUDRATE_57600;
		else if(115200==dwBaudrate)		eSpeed = EBAUDRATE_115200;
		else if(128000==dwBaudrate)		eSpeed = EBAUDRATE_128000;
		else if(256000==dwBaudrate)		eSpeed = EBAUDRATE_256000;
		else	return FALSE;
	
		dwResult = m_Serial.Set(eSpeed);
	}

	//if(SUCCEEDED(dwResult))
	if(ERROR_SUCCESS==dwResult)
	{
		bResult = TRUE;
	}
	else
	{
		m_Serial.Close();
	}

	CUtil::StringCopy(m_szDevice, lpszDevice);
	m_dwBaudrate = dwBaudrate;

	return bResult;	
}

void CSerialCtrl::Close()
{
	m_Serial.Close();

	memset(m_szDevice, 0x00, sizeof(TCHAR) * 128);
	m_dwBaudrate = 0;
}

BOOL CSerialCtrl::Send(BYTE* pInput, DWORD dwInputLen, BYTE* pOutput, DWORD* pdwOutputLen, const BOOL bWaitRespose, DWORD dwWaitTime)
{
	DWORD dwLen = 0;
	DWORD dwResult = FALSE;

	if(0<dwInputLen)
	{
		dwResult = m_Serial.Write(pInput, dwInputLen, &dwLen);
		if(FAILED(dwResult))
			return FALSE;
	}

	CUtil::Sleep(DEFAULT_SLEEP_SERIALPORT);
	if(dwWaitTime>0)
		CUtil::Sleep(dwWaitTime);

	if(0<*pdwOutputLen)
	{
		dwResult = m_Serial.Read(pOutput, *pdwOutputLen, &dwLen);
		if (FAILED(dwResult))
			return FALSE;

		*pdwOutputLen = dwLen;
	}

	return TRUE;
}

BOOL CSerialCtrl::Read(void* pData, DWORD dwLen, DWORD* pdwRead)
{
	DWORD dwReaded = 0;
	DWORD dwResult = FALSE;

	dwResult = m_Serial.Read(pData, dwLen, &dwReaded);
	if (FAILED(dwResult))
		return FALSE;
	
	if (pdwRead)
		*pdwRead = dwReaded;

#ifdef DEF_DUMP_SERIAL_MESSAGE
	{
		if (INVALID_HANDLE_VALUE != m_hDumpFile)
		{
			TCHAR szEthernet[MAX_FILE_PATH_LEN] = { 0, };
			SYSTEMTIME stLogTime;
			::GetLocalTime(&stLogTime);
			DWORD dwResult = 0;
			CUtil::StringFormat(szEthernet, MAX_FILE_PATH_LEN, _T("[%04d%02d%02d_%02d%02d%02d.%03d][%s][%s]\r\n"),
				stLogTime.wYear,
				stLogTime.wMonth,
				stLogTime.wDay,
				stLogTime.wHour,
				stLogTime.wMinute,
				stLogTime.wSecond,
				stLogTime.wMilliseconds,
				_T("READ"), pData);
			::WriteFile(m_hDumpFile, szEthernet, CUtil::StringLength(szEthernet), &dwResult, NULL);
		}
	}
#endif

	return TRUE;
}

BOOL CSerialCtrl::Write(void* pData, DWORD dwLen, DWORD* pdwWrite)
{
	DWORD dwWritten = 0;
	DWORD dwResult = FALSE;

#ifdef DEF_DUMP_SERIAL_MESSAGE
	{
		if (INVALID_HANDLE_VALUE != m_hDumpFile)
		{
			TCHAR szEthernet[MAX_FILE_PATH_LEN] = { 0, };
			SYSTEMTIME stLogTime;
			::GetLocalTime(&stLogTime);
			DWORD dwResult = 0;
			CUtil::StringFormat(szEthernet, MAX_FILE_PATH_LEN, _T("[%04d%02d%02d_%02d%02d%02d.%03d][%s][%s]\r\n"),
				stLogTime.wYear,
				stLogTime.wMonth,
				stLogTime.wDay,
				stLogTime.wHour,
				stLogTime.wMinute,
				stLogTime.wSecond,
				stLogTime.wMilliseconds,
				_T("WRITE"), pData);
			::WriteFile(m_hDumpFile, szEthernet, CUtil::StringLength(szEthernet), &dwResult, NULL);
		}
	}
#endif

	dwResult = m_Serial.Write(pData, dwLen, &dwWritten);
	if (FAILED(dwResult))
		return FALSE;
	
	if (pdwWrite)
		*pdwWrite = dwWritten;

	return TRUE;
}

const TCHAR* CSerialCtrl::GetDeviceName()
{
	return m_szDevice;
}

const DWORD CSerialCtrl::GetDeviceSpeed()
{
	return m_dwBaudrate;
}