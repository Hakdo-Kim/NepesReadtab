#include "StdAfx.h"
#include "EmulFile.h"

#include "Util/Util.h"


CEmulFile::CEmulFile()
{
	::InitializeCriticalSection(&m_CriticalSection);

	m_hThreadEmul	= NULL;
	m_bStopEmul		= FALSE;
	
	m_hEventEmulStop= NULL;
	m_hEventFps		= NULL;

	m_pFunc			= NULL;
	m_pFuncArg		= NULL;

	m_bSuspend		= FALSE;
	m_bSingleFrame	= FALSE;

	m_bUpdated		= FALSE;

#ifdef DEF_TRIGGER_COUNT
	m_dwTriggerCount = 0;
#endif
	

	memset(&m_stEmul, 0x00, sizeof(INFO_CONNECT_EMUL));

	memset(&m_stFileData, 0x00, sizeof(WIN32_FIND_DATA));
	m_hSearch = INVALID_HANDLE_VALUE;

}

CEmulFile::~CEmulFile()
{
	Close();

	::DeleteCriticalSection(&m_CriticalSection);
}

BOOL CEmulFile::IsOpen ()
{
	if( NULL==m_hThreadEmul )
		return FALSE;

	return TRUE;
}

BOOL CEmulFile::Open(const INFO_CONNECT_EMUL* pInfo)
{
	if(NULL==pInfo)
		return FALSE;
	memcpy(&m_stEmul, pInfo, sizeof(INFO_CONNECT_EMUL));

	// Check Directory End Character.
	CUtil::StringCopy(m_stEmul.m_szDirPath, m_stEmul.m_szFilePath);

	if (FALSE == CUtil::IsDirectory(m_stEmul.m_szDirPath))
	{
		TCHAR* pCh = _tcsrchr(m_stEmul.m_szDirPath, _T('\\'));
		if (pCh) *pCh = 0;
	}

	// Thread Setting...
	m_hEventEmulStop = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_hEventEmulStop)
	{
		Close();
		return FALSE;
	}

	m_hEventFps = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_hEventFps)
	{
		Close();
		return FALSE;
	}

	TCHAR szPath[MAX_FILE_PATH_LEN] = { 0, };
	CUtil::StringFormat(szPath, MAX_FILE_PATH_LEN, _T("%s\\*.*"), m_stEmul.m_szDirPath);

	m_hSearch = ::FindFirstFile(szPath, &m_stFileData);
	if (INVALID_HANDLE_VALUE == m_hSearch)
	{
#ifdef 	DEF_LPAPP
		CUtil::GetCurrentDirectory(m_stEmul.m_szDirPath, MAX_FILE_PATH_LEN);
		CUtil::StringFormat(szPath, MAX_FILE_PATH_LEN, _T("%s\\*.*"), m_stEmul.m_szDirPath);
		
		m_hSearch = ::FindFirstFile(szPath, &m_stFileData);
		if (INVALID_HANDLE_VALUE == m_hSearch)
		{
			Close();
			return FALSE;
		}
#else
		Close();
		return FALSE;
#endif
	}

	DWORD dwThreadId = 0;
	m_hThreadEmul = ::CreateThread(0, 0, ThreadEmulProc, LPVOID(this), 0, &dwThreadId);

	Stop();	// Supend thread

	return TRUE;
}


BOOL CEmulFile::Update(const INFO_CONNECT_EMUL* pInfo)
{
	if (NULL == pInfo)
		return FALSE;

	this->Stop();

	CUtil::StringCopy(m_stEmul.m_szName, pInfo->m_szName);
	CUtil::StringCopy(m_stEmul.m_szFilePath, pInfo->m_szFilePath);
	CUtil::StringCopy(m_stEmul.m_szDirPath, m_stEmul.m_szFilePath);
	TCHAR* pCh = _tcsrchr(m_stEmul.m_szDirPath, _T('\\'));
	if (pCh) *pCh = 0;

	m_stEmul.m_bCameraEmulator = pInfo->m_bCameraEmulator;
	m_stEmul.m_dwFps = pInfo->m_dwFps;
	m_stEmul.m_bCycleDir = pInfo->m_bCycleDir;

	memcpy(&m_stEmul.m_stFrame, &pInfo->m_stFrame, sizeof(INFO_FRAME));

	m_bUpdated = TRUE;

	return TRUE;
}


void CEmulFile::Close()
{
	m_bStopEmul = TRUE;
	m_bSuspend	= TRUE;

	if(m_hEventEmulStop)
	{
		if(m_hEventFps)
			::SetEvent(m_hEventFps);

		::ResetEvent(m_hEventEmulStop);
		::WaitForSingleObject(m_hEventEmulStop, 5000);

		::CloseHandle(m_hEventEmulStop);
	}

	if(m_hEventFps)
	{
		::ResetEvent(m_hEventFps);
		::CloseHandle(m_hEventFps);
	}

	if (m_hThreadEmul)
	{
		::CloseHandle(m_hThreadEmul);
	}

	m_hThreadEmul	= NULL;
	m_bStopEmul		= FALSE;

	m_hEventEmulStop= NULL;
	m_hEventFps		= NULL;

	if (INVALID_HANDLE_VALUE != m_hSearch)
	{
		::FindClose(m_hSearch);
		m_hSearch = INVALID_HANDLE_VALUE;
	}

}

INFO_EMUL_FRAME* CEmulFile::LoadFrame(const TCHAR* pszPath, const INFO_CONNECT_EMUL* pstEmul)
{
	TCHAR szPath[MAX_FILE_PATH_LEN] = { 0, };
	CUtil::StringFormat(szPath, MAX_FILE_PATH_LEN, _T("%s\\*.*"), m_stEmul.m_szDirPath);

	INFO_EMUL_FRAME* pstFrame = NULL;
	if (m_bUpdated)
	{
		m_bUpdated = FALSE;
		pstFrame = LoadUpdatedFileFrame();
		if (pstFrame)
			return pstFrame;	
	}

	if (pstEmul->m_bCycleDir)
	{
		int nCycleCount = 0;
				
		do
		{
			if (INVALID_HANDLE_VALUE != m_hSearch)
			{
				do
				{
					//if (FILE_ATTRIBUTE_ARCHIVE & m_stFileData.dwFileAttributes)
					if (CheckAttribute(m_stFileData.dwFileAttributes))
					{
						CUtil::StringFormat(szPath, MAX_FILE_PATH_LEN, _T("%s\\%s"), m_stEmul.m_szDirPath, m_stFileData.cFileName);
						pstFrame = LoadFileFrame(szPath);

						if (pstFrame)
						{
							CUtil::StringCopy(pstFrame->m_szFilePath, szPath);
							CUtil::StringCopy(m_stEmul.m_szFilePath, szPath);

							if (!::FindNextFile(m_hSearch, &m_stFileData))
							{
								// Research...
								::FindClose(m_hSearch);
								CUtil::StringFormat(szPath, MAX_FILE_PATH_LEN, _T("%s\\*.*"), m_stEmul.m_szDirPath);
								m_hSearch = ::FindFirstFile(szPath, &m_stFileData);

								nCycleCount++;
							}

							return pstFrame;
						}
					}
					else
					{
						if (pstFrame)
						{
							if (pstFrame->m_pBuf)
								delete[] pstFrame->m_pBuf;
							delete pstFrame;
							pstFrame = NULL;
						}
					}

				} while (::FindNextFile(m_hSearch, &m_stFileData));

				// Research...
				::FindClose(m_hSearch);
				CUtil::StringFormat(szPath, MAX_FILE_PATH_LEN, _T("%s\\*.*"), m_stEmul.m_szDirPath);
				m_hSearch = ::FindFirstFile(szPath, &m_stFileData);

				nCycleCount++;
			}
			else
			{
				break;
			}

			if (m_bStopEmul || m_bSuspend || 1 < nCycleCount)
				break;

		} while (1);
	}
	else
	{
		INFO_EMUL_FRAME* pstFrame = LoadFileFrame(pstEmul->m_szFilePath);
		return pstFrame;
	}

	return NULL;
}

INFO_EMUL_FRAME* CEmulFile::LoadEmulFrame(const TCHAR* pszPath, const INFO_CONNECT_EMUL* pstEmul)
{
	if (NULL == pszPath || NULL == pstEmul || FALSE == CUtil::IsExistFile(pszPath))
		return NULL;

	DWORD dwX		= pstEmul->m_stFrame.m_dwX;
	DWORD dwY		= pstEmul->m_stFrame.m_dwY;
	DWORD dwWidth	= pstEmul->m_stFrame.m_dwWidth;
	DWORD dwHeight	= pstEmul->m_stFrame.m_dwHeight;
	BYTE  nBit		= 8;

	if(TYPE_DATABIT_08 == pstEmul->m_stFrame.m_eDataBit)		nBit = 8;
	else if(TYPE_DATABIT_12 == pstEmul->m_stFrame.m_eDataBit)	nBit = 12;
	else if(TYPE_DATABIT_16 == pstEmul->m_stFrame.m_eDataBit)	nBit = 16;
	else if(TYPE_DATABIT_24 == pstEmul->m_stFrame.m_eDataBit)	nBit = 24;
	else if(TYPE_DATABIT_32 == pstEmul->m_stFrame.m_eDataBit)	nBit = 32;
	else if(TYPE_DATABIT_36 == pstEmul->m_stFrame.m_eDataBit)	nBit = 36;
	else if(TYPE_DATABIT_48 == pstEmul->m_stFrame.m_eDataBit)	nBit = 48;
	else
		return NULL;
	
	DWORD dwLen = (DWORD)(dwWidth * dwHeight * nBit / 8.0);
	BYTE* pBuffer = new BYTE[dwLen];
	if (NULL == pBuffer)
		return NULL;
	memset(pBuffer, 0x00, dwLen);
	
	BOOL bResult = CUtil::LoadImageBuffer(pszPath, pBuffer, dwLen, dwX, dwY, dwWidth, dwHeight, nBit);
	if(FALSE==bResult)
	{
		delete [] pBuffer;
		return NULL;
	}

	INFO_EMUL_FRAME* pstFrmae = new INFO_EMUL_FRAME;
	memset(pstFrmae, 0x00, sizeof(INFO_EMUL_FRAME));

	CUtil::StringCopy(pstFrmae->m_szFilePath, pszPath);

	pstFrmae->m_dwWidth		= dwWidth;
	pstFrmae->m_dwHeight	= dwHeight;
	pstFrmae->m_nBit		= nBit;
	
	pstFrmae->m_pBuf		= pBuffer;
	pstFrmae->m_dwBufLen	= dwLen;

	return pstFrmae;
}

INFO_EMUL_FRAME* CEmulFile::LoadFileFrame(const TCHAR* pszPath)
{
	if (NULL == pszPath || FALSE == CUtil::IsExistFile(pszPath))
		return NULL;

	INFO_EMUL_FRAME* pstFrmae = new INFO_EMUL_FRAME;
	memset(pstFrmae, 0x00, sizeof(INFO_EMUL_FRAME));

	CUtil::StringCopy(pstFrmae->m_szFilePath, pszPath);

	BOOL bResult = CUtil::LoadImageBuffer(pszPath, 
										&(pstFrmae->m_pBuf),
										&(pstFrmae->m_dwBufLen),
										&(pstFrmae->m_dwWidth),
										&(pstFrmae->m_dwHeight),
										&(pstFrmae->m_nBit));
	if (FALSE == bResult)
	{
		if (pstFrmae->m_pBuf)
			delete[] pstFrmae->m_pBuf;
		delete pstFrmae;

		return NULL;
	}	

	return pstFrmae;
}


INFO_EMUL_FRAME* CEmulFile::LoadUpdatedFileFrame()
{
	TCHAR szPath[MAX_FILE_PATH_LEN] = { 0, };
	CUtil::StringFormat(szPath, MAX_FILE_PATH_LEN, _T("%s\\*.*"), m_stEmul.m_szDirPath);


	INFO_EMUL_FRAME* pstFrame = LoadFileFrame(m_stEmul.m_szFilePath);
	if (pstFrame)
	{
		TCHAR szName[MAX_PATH] = { 0, };
		const TCHAR* pCH = _tcsrchr(m_stEmul.m_szFilePath, _T('\\'));
		CUtil::StringCopy(szName, pCH + 1);

		BOOL bFind = FALSE;
		BOOL bLastFile = FALSE;

		int nLoopCount = 0;

		do
		{
			if (INVALID_HANDLE_VALUE != m_hSearch)
			{
				do
				{
					//if (FILE_ATTRIBUTE_ARCHIVE & m_stFileData.dwFileAttributes)
					if (CheckAttribute(m_stFileData.dwFileAttributes))
					{
						bFind = CUtil::StringCompare(m_stFileData.cFileName, szName);
						if (bFind)
						{
							bLastFile = !::FindNextFile(m_hSearch, &m_stFileData);
							break;
						}
					}
				} while (::FindNextFile(m_hSearch, &m_stFileData));

				if (FALSE == bFind || bLastFile)
				{
					// Research...
					::FindClose(m_hSearch);
					CUtil::StringFormat(szPath, MAX_FILE_PATH_LEN, _T("%s\\*.*"), m_stEmul.m_szDirPath);
					m_hSearch = ::FindFirstFile(szPath, &m_stFileData);

					if (2 <= nLoopCount)
					{
						if (pstFrame)
						{
							if (pstFrame->m_pBuf)
								delete[] pstFrame->m_pBuf;
							delete pstFrame;
							return NULL;
						}
						return NULL;
					}
					nLoopCount++;
				}
			}
			else
			{
				break;
			}

		} while (FALSE == bFind);
	}

	return pstFrame;
}

//#define LOCALFILE_LOADTEST 

BOOL CEmulFile::Start(BOOL bSingleFrame)
{
	DWORD dwResult = ::ResumeThread(m_hThreadEmul);

#ifdef LOCALFILE_LOADTEST
	OutputDebugString(_T("CEmulFile::Start ID \r\n"));
#endif
	
	m_bSuspend = FALSE;
	m_bSingleFrame = bSingleFrame;

#ifdef DEF_TRIGGER_COUNT
	if (FALSE == m_bSingleFrame)
		m_dwTriggerCount = 0;
	else
		m_dwTriggerCount++;
#endif

	//CUtil::PrintDebugString(_T("start \r\n"));
	return SUCCEEDED(dwResult);
}

void CEmulFile::Stop()
{
#ifdef DEF_TRIGGER_COUNT
	if (FALSE == m_bSingleFrame || 1 > m_dwTriggerCount)
		m_dwTriggerCount = 0;
	else
		m_dwTriggerCount--;
#endif

	//CUtil::PrintDebugString(_T("stop \r\n"));
	m_bSuspend = TRUE;
}

const INFO_CONNECT_EMUL* CEmulFile::GetDeviceInfo()
{
	return &m_stEmul;
}

BOOL CEmulFile::SetEventFunc(FuncAcquisitionEvent pFunc, void* pUserData)
{
	if(FALSE==m_bSuspend)
	{
		DWORD dwDeltaMsec = GetAcquisitionEventTime();
		this->Stop();

		CUtil::Sleep(dwDeltaMsec*2);
	}

	m_pFunc			= pFunc;
	m_pFuncArg		= pUserData;

	return TRUE;
}

DWORD WINAPI CEmulFile::ThreadEmulProc(LPVOID lpArg)
{
	CEmulFile* pEmulFile = (CEmulFile*)lpArg;

	return pEmulFile->ThreadEmulProc();
}

DWORD CEmulFile::ThreadEmulProc(void)
{
	DWORD dwDeltaMsec = 0;
	
	m_bStopEmul = FALSE;

	INFO_FILE* pstFile = NULL;

#ifdef 	LOCALFILE_LOADTEST
	OutputDebugString(_T("CEmulFile::ThreadEmulProc ID \r\n"));
#endif
	
	do
	{
		dwDeltaMsec = GetAcquisitionEventTime();
#ifdef LOCALFILE_LOADTEST
		OutputDebugString(_T("CEmulFile::ThreadEmulProc ID \r\n"));
#endif
		if(FALSE==m_bSuspend)
		{
			
			//::WaitForSingleObject(m_hEventFps, dwDeltaMsec);
			//::ResetEvent(m_hEventFps);
			
			if (m_bStopEmul)
			{
#ifdef LOCALFILE_LOADTEST
				OutputDebugString(_T("CEmulFile::ThreadEmulProc ID : m_bStopEmul \r\n"));
#endif
				break;
			}

			if (FALSE == m_bStopEmul && FALSE == m_bSuspend)
			{
				TCHAR szPath[MAX_FILE_PATH_LEN] = { 0, };
				CUtil::StringFormat(szPath, MAX_FILE_PATH_LEN, _T("%s\\*.*"), m_stEmul.m_szDirPath);

				INFO_EMUL_FRAME* pFrame = LoadFrame(szPath, &m_stEmul);
				if (pFrame)
				{
					if (m_pFunc)
					{
						pstFile = new INFO_FILE;
						memset(pstFile, 0x00, sizeof(INFO_FILE));

						CUtil::StringCopy(pstFile->m_szPathName, m_stEmul.m_szDirPath);
						TCHAR* pCh = _tcsrchr(m_stEmul.m_szFilePath, '\\');
						CUtil::StringCopy(pstFile->m_szFileName, pCh + 1);

						pstFile->m_stImgBuf.m_dwWidth = pFrame->m_dwWidth;
						pstFile->m_stImgBuf.m_dwHeight = pFrame->m_dwHeight;
						pstFile->m_stImgBuf.m_nBit = pFrame->m_nBit;
						pstFile->m_stImgBuf.m_dwPitch = pstFile->m_stImgBuf.m_dwWidth * pstFile->m_stImgBuf.m_nBit / 8;
#ifdef LOCALFILE_LOADTEST
						OutputDebugString(_T("CEmulFile::ThreadEmulProc ID : call Acq \r\n"));
#endif

						//CUtil::PrintDebugString(_T("acq \r\n"));
						(*m_pFunc)(pFrame->m_pBuf, pFrame->m_dwBufLen, pstFile, m_pFuncArg);
					}

					delete[] pFrame->m_pBuf;
					delete pFrame;

					if (m_bSingleFrame)
					{
#ifdef DEF_TRIGGER_COUNT
						if (1 >= m_dwTriggerCount)
						{
							m_dwTriggerCount = 0;
							this->Stop();
						}
						else
						{
							m_dwTriggerCount--;
						}
#else
						this->Stop();
#endif
					}
				}
				else
				{
#ifdef LOCALFILE_LOADTEST
					OutputDebugString(_T("CEmulFile::ThreadEmulProc ID : m_pFunc NULL \r\n"));
#endif
					
					// Fail to Load...
					if (m_bSingleFrame)
					{
						this->Stop();
					}
				}
			}
			else
			{
#ifdef LOCALFILE_LOADTEST
				OutputDebugString(_T("CEmulFile::ThreadEmulProc ID : FALSE != m_bStopEmul || FALSE != m_bSuspend NULL \r\n"));
#endif
			}

			::ResetEvent(m_hEventFps);
			::WaitForSingleObject(m_hEventFps, dwDeltaMsec);
			//::ResetEvent(m_hEventFps);
		}
		else
		{
			CUtil::Sleep(dwDeltaMsec);
		}
	} while (FALSE == m_bStopEmul);


	if(m_hEventEmulStop)
		SetEvent(m_hEventEmulStop);

	return 0;
}

BOOL CEmulFile::IsCycleDirectory()
{
	const INFO_CONNECT_EMUL* pstEmul = GetDeviceInfo();
	return pstEmul->m_bCycleDir;
}

DWORD CEmulFile::GetAcquisitionEventTime()
{
	const DWORD MSEC	= 1000;
	const DWORD DEFFPS	= 25;

	if(0==m_stEmul.m_dwFps)
		return MSEC/DEFFPS;

	return MSEC/m_stEmul.m_dwFps;
}

BOOL CEmulFile::CheckAttribute(DWORD dwFileAttr)
{
	if (FILE_ATTRIBUTE_COMPRESSED & dwFileAttr ||
		FILE_ATTRIBUTE_DIRECTORY & dwFileAttr ||
		FILE_ATTRIBUTE_SYSTEM & dwFileAttr ||
		FILE_ATTRIBUTE_HIDDEN & dwFileAttr )
	{
		return FALSE;
	}
	return TRUE;
}