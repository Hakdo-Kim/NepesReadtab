#include "stdafx.h"
#include "Serial.h"
#include "Util/Util.h"
#include "tchar.h"
#include "stdlib.h"


LONG OpenSubKeyByIndex(HKEY hKey,DWORD dwIndex,REGSAM samDesired,PHKEY phkResult,LPTSTR* lppSubKeyName);
LONG QueryStringValue(HKEY hKey,LPCTSTR lpValueName,LPTSTR* lppStringValue);


CSerial::CSerial()
{
	m_dwLastError	= ERROR_INVALID_HANDLE;

	m_hFile			= INVALID_HANDLE_VALUE;
	m_eEvent		= EEVENT_UNKNOWN;
	m_dwEventMask	= 0;

#ifdef SERIAL_OVERLAPPED
	m_hOverlapped	= NULL;
#endif
}

CSerial::~CSerial()
{
	
}

HANDLE CSerial::GetHandle()
{
	return m_hFile;
}

DWORD CSerial::GetLastError ()
{
	return m_dwLastError;
}

BOOL CSerial::IsOpen()
{
	if(INVALID_HANDLE_VALUE == m_hFile)
		return FALSE;

	return TRUE;
}

DWORD CSerial::Open (LPCTSTR lpszDevice, DWORD dwInQueue, DWORD dwOutQueue, BOOL bOverlapped)
{
	if(!IsOpen())
	{
		Close();
	}

	TCHAR szPort[128] = {0,};
	_stprintf(szPort, _T("\\\\.\\%s"), lpszDevice);

	m_hFile = ::CreateFile(szPort,
						   GENERIC_READ | GENERIC_WRITE,
						   0,
						   0,
						   OPEN_EXISTING,
						   bOverlapped ? FILE_FLAG_OVERLAPPED : 0,
						   0);

	if(INVALID_HANDLE_VALUE==m_hFile)
	{
		m_dwLastError = ::GetLastError();
		return m_dwLastError;
	}

#ifdef SERIAL_OVERLAPPED
	if (bOverlapped)
	{
		m_hOverlapped = ::CreateEvent(0, TRUE, FALSE, 0);
		if (0==m_hOverlapped)
		{
			m_dwLastError = ::GetLastError();
			Close();			
			return m_dwLastError;
		}
	}
#endif

	if (dwInQueue || dwOutQueue)
	{
		//_ASSERTE(dwInQueue >= 16);
		//_ASSERTE(dwOutQueue >= 16);

		if (!::SetupComm(m_hFile,dwInQueue,dwOutQueue))
		{
			DWORD dwLastError = ::GetLastError();
			Close();

			m_dwLastError = dwLastError;
			return m_dwLastError;	
		}
	}

	// Setting Event mask
	SetEventMask ();

	// Setting Read timeout
	SetReadTimeouts (EREADTIMEOUT_NONBLOCK);

	// Setting default config
	COMMCONFIG stConfig;
	memset(&stConfig, 0x00, sizeof(COMMCONFIG));
	DWORD dwSize = sizeof(stConfig);
	stConfig.dwSize = dwSize;
	if (::GetDefaultCommConfig(lpszDevice, &stConfig, &dwSize))
	{
		if (!::SetCommConfig(m_hFile, &stConfig, dwSize))
		{
			// Check result...
		}
	}
	else
	{
		// Check result...
	}

	m_dwLastError = ERROR_SUCCESS;

	return m_dwLastError;
}

DWORD CSerial::Close ()
{
	if(!IsOpen())
	{
		m_dwLastError = ERROR_SUCCESS;
		return m_dwLastError;
	}

#ifdef SERIAL_OVERLAPPED
	if(m_hOverlapped)
	{
		::CloseHandle(m_hOverlapped);
		m_hOverlapped = NULL;
	}
#endif

	::CloseHandle(m_hFile);
	m_hFile = INVALID_HANDLE_VALUE;

	return m_dwLastError;
}

DWORD CSerial::Set (EBAUDRATE eBaudrate, EDATABITS eDataBits, EPARITY eParity, ESTOPBITS eStopBits)
{
	if(!IsOpen())
	{
		m_dwLastError = ERROR_INVALID_HANDLE;
		return m_dwLastError;
	}

	DCB stDcb;
	memset(&stDcb, 0x00, sizeof(DCB));

	stDcb.DCBlength = sizeof(stDcb);

	if (!::GetCommState(m_hFile, &stDcb))
	{
		m_dwLastError = ::GetLastError();
		return m_dwLastError;
	}

	stDcb.BaudRate	= DWORD(eBaudrate);
	stDcb.ByteSize	= BYTE(eDataBits);
	stDcb.Parity	= BYTE(eParity);
	stDcb.StopBits	= BYTE(eStopBits);
	stDcb.fParity	= (eParity != EPARITY_NONE);

	if (!::SetCommState(m_hFile, &stDcb))
	{
		m_dwLastError = ::GetLastError();
		return m_dwLastError;
	}

	m_dwLastError = ERROR_SUCCESS;

	return m_dwLastError;
}

DWORD CSerial::SetEventMask (DWORD dwEventMask)
{
	if(!IsOpen())
	{
		m_dwLastError = ERROR_INVALID_HANDLE;
		return m_dwLastError;
	}

	if (!::SetCommMask(m_hFile,dwEventMask))
	{
		m_dwLastError = ::GetLastError();
		return m_dwLastError;
	}

	m_dwLastError = ERROR_SUCCESS;

	m_dwEventMask = dwEventMask;

	return m_dwLastError;
}

DWORD CSerial::SetReadTimeouts (EREADTIMEOUT eTimeout)
{
	if(!IsOpen())
	{
		m_dwLastError = ERROR_INVALID_HANDLE;
		return m_dwLastError;
	}

	// Set read timeout
	COMMTIMEOUTS stTimeout;

	if (!::GetCommTimeouts(m_hFile,&stTimeout))
	{
		m_dwLastError = ::GetLastError();
		return m_dwLastError;
	}

	switch (eTimeout)
	{
	case EREADTIMEOUT_BLOCK:
		stTimeout.ReadIntervalTimeout		= 0;
		stTimeout.ReadTotalTimeoutConstant	= 0;
		stTimeout.ReadTotalTimeoutMultiplier= 0;
		break;

	case EREADTIMEOUT_NONBLOCK:
		stTimeout.ReadIntervalTimeout		= MAXDWORD;
		stTimeout.ReadTotalTimeoutConstant	= 0;
		stTimeout.ReadTotalTimeoutMultiplier= 0;
		break;

	default:
		m_dwLastError = E_INVALIDARG;
		return m_dwLastError;
	}

	stTimeout.ReadIntervalTimeout=50;
	stTimeout.ReadTotalTimeoutConstant=50;
	stTimeout.ReadTotalTimeoutMultiplier=10;
	stTimeout.WriteTotalTimeoutConstant=50;
	stTimeout.WriteTotalTimeoutMultiplier=10;

	if (!::SetCommTimeouts(m_hFile,&stTimeout))
	{
		m_dwLastError = ::GetLastError();
		return m_dwLastError;
	}

	m_dwLastError = ERROR_SUCCESS;

	return m_dwLastError;
}


DWORD CSerial::Write (const void* pData, DWORD dwLen, DWORD* pdwWritten, LPOVERLAPPED lpOverlapped, DWORD dwTimeout)
{
	if(!IsOpen())
	{
		m_dwLastError = ERROR_INVALID_HANDLE;
		return m_dwLastError;
	}

#ifdef SERIAL_OVERLAPPED

	if (!m_hOverlapped && (lpOverlapped || (dwTimeout != INFINITE)))
	{
		m_dwLastError = ERROR_INVALID_FUNCTION;
		return m_dwLastError;
	}

	OVERLAPPED stOverlap;
	if (!lpOverlapped && m_hOverlapped)
	{
		memset(&stOverlap,0,sizeof(stOverlap));
		stOverlap.hEvent = m_hOverlapped;

		lpOverlapped = &stOverlap;
	}

	// Write the data
	if (!::WriteFile(m_hFile, pData, dwLen, pdwWritten, lpOverlapped))
	{
		DWORD dwLastError = ::GetLastError();

		if (ERROR_IO_PENDING != dwLastError)
		{
			m_dwLastError = dwLastError;
			return m_dwLastError;
		}

		if (lpOverlapped == &stOverlap)
		{
			// Wait for the overlapped operation to complete
			switch (::WaitForSingleObject(lpOverlapped->hEvent,dwTimeout))
			{
			case WAIT_OBJECT_0:
				// The overlapped operation has completed
				if (!::GetOverlappedResult(m_hFile,lpOverlapped,pdwWritten,FALSE))
				{
					m_dwLastError = ::GetLastError();
					return m_dwLastError;
				}
				break;

			case WAIT_TIMEOUT:
				CancelIo();
				m_dwLastError = ERROR_TIMEOUT;
				return m_dwLastError;

			default:
				m_dwLastError = ::GetLastError();
				return m_dwLastError;
			}
		}
	}
	else
	{
		if (lpOverlapped)
			::SetEvent(lpOverlapped->hEvent);
	}

#else
	if ( !::WriteFile(m_hFile, pData, dwLen, pdwWritten, 0) )
	{
		m_dwLastError = ::GetLastError();
		return m_dwLastError;
	}
#endif


	m_dwLastError = ERROR_SUCCESS;

	return m_dwLastError;
}

DWORD CSerial::Read (void* pData, DWORD dwLen, DWORD* pdwRead, LPOVERLAPPED lpOverlapped, DWORD dwTimeout)
{
	if(!IsOpen())
	{
		m_dwLastError = ERROR_INVALID_HANDLE;
		return m_dwLastError;
	}

#ifdef SERIAL_OVERLAPPED

	if (!m_hOverlapped && (lpOverlapped || (dwTimeout != INFINITE)))
	{
		m_dwLastError = ERROR_INVALID_FUNCTION;
		return m_dwLastError;
	}

	OVERLAPPED stOverlap;
	if (lpOverlapped == 0)
	{
		memset(&stOverlap,0,sizeof(stOverlap));
		stOverlap.hEvent = m_hOverlapped;

		lpOverlapped = &stOverlap;
	}
	
	// Read the data
	if (!::ReadFile(m_hFile, pData, dwLen, pdwRead, lpOverlapped))
	{
		DWORD dwLastError = ::GetLastError();

		// Overlapped operation in progress is not an actual error
		if (ERROR_IO_PENDING != dwLastError )
		{
			m_dwLastError = dwLastError;
			return m_dwLastError;
		}

		// We need to block if the client didn't specify an overlapped structure
		if (lpOverlapped == &stOverlap)
		{
			// Wait for the overlapped operation to complete
			switch (::WaitForSingleObject(lpOverlapped->hEvent,dwTimeout))
			{
			case WAIT_OBJECT_0:
				// The overlapped operation has completed
				if (!::GetOverlappedResult(m_hFile,lpOverlapped, pdwRead, FALSE))
				{
					// Set the internal error code
					m_dwLastError = ::GetLastError();
					return m_dwLastError;
				}
				break;

			case WAIT_TIMEOUT:
				CancelIo();
				m_dwLastError = ERROR_TIMEOUT;
				return m_dwLastError;

			default:
				m_dwLastError = ::GetLastError();
				return m_dwLastError;
			}
		}
	}
	else
	{
		if (lpOverlapped)
			::SetEvent(lpOverlapped->hEvent);
	}


#else
	if (!::ReadFile(m_hFile, pData, dwLen, pdwRead, 0))
	{
		m_dwLastError = ::GetLastError();
		return m_dwLastError;
	}	
#endif

	m_dwLastError = ERROR_SUCCESS;

	return m_dwLastError;
}


BOOL CSerial::CancelIo()
{
	BOOL bResult = FALSE;

	if(!IsOpen())
	{
		m_dwLastError = ERROR_INVALID_HANDLE;
		return m_dwLastError;
	}

	bResult = ::CancelIo(m_hFile);

	return bResult;
}

DWORD CSerial::Purge()
{
	if(!IsOpen())
	{
		m_dwLastError = ERROR_INVALID_HANDLE;
		return m_dwLastError;
	}

	if (!::PurgeComm(m_hFile, PURGE_TXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR))
	{
		m_dwLastError = ::GetLastError();
	}

	m_dwLastError = ERROR_SUCCESS;

	return m_dwLastError;
}

DWORD CSerial::Break()
{
	if(!IsOpen())
	{
		m_dwLastError = ERROR_INVALID_HANDLE;
		return m_dwLastError;
	}

	::SetCommBreak(m_hFile);
    ::Sleep(100);
    ::ClearCommBreak(m_hFile);

	m_dwLastError = ERROR_SUCCESS;

	return m_dwLastError;
}

EPORT CSerial::CheckPort(LPCTSTR pszCom)
{
	if(NULL==pszCom)
		return EPORT_UNKNOWNERR;

	TCHAR szPort[128] = {0,};
	_stprintf(szPort, _T("\\\\.\\%s"), pszCom);

	HANDLE hFile = ::CreateFile(szPort, 
						   GENERIC_READ|GENERIC_WRITE, 
						   0, 
						   0, 
						   OPEN_EXISTING, 
						   0,
						   0);

	if (INVALID_HANDLE_VALUE==hFile)
	{
		switch (::GetLastError())
		{
		case ERROR_FILE_NOT_FOUND:
			return EPORT_NOTAVAILABLE;

		case ERROR_ACCESS_DENIED:
			return EPORT_INUSE;

		default:
			return EPORT_UNKNOWNERR;
		}
	}

	::CloseHandle(hFile);

	return EPORT_AVAILABLE;
}


int CSerial::SearchSerialPort(SERIALPORT_INFO* pstInfo, const int nLen)
{
	int nCount = 0;

	OSVERSIONINFO stOsInfo;
	memset(&stOsInfo, 0x00, sizeof(OSVERSIONINFO));

	stOsInfo.dwOSVersionInfoSize=sizeof(stOsInfo);

	::GetVersionEx(&stOsInfo);

	switch(stOsInfo.dwPlatformId)
	{
	case VER_PLATFORM_WIN32_WINDOWS:
		nCount = SearchSerialPortWin9x(pstInfo, nLen);
		break;
		
	case VER_PLATFORM_WIN32_NT:
		{
			if(4>stOsInfo.dwMajorVersion)
			{
				::SetLastError(ERROR_OLD_WIN_VERSION);
				return 0;
			}
			else if(4==stOsInfo.dwMajorVersion)
			{
				::SetLastError(ERROR_APP_WRONG_OS);
				return 0;
			}
			else
			{
				nCount = SearchSerialPortWin2000(pstInfo, nLen);
			}

		}
		break;

	default:
		::SetLastError(ERROR_OLD_WIN_VERSION);
		return 0;
	}

	return nCount;
}

int CSerial::SearchSerialPortWin9x(SERIALPORT_INFO* pstInfo, const int nLen)
{
	return SearchSerialPort(TEXT("ENUM"), pstInfo, nLen);
}

int CSerial::SearchSerialPortWin2000(SERIALPORT_INFO* pstInfo, const int nLen)
{
	return SearchSerialPort(TEXT("SYSTEM\\CURRENTCONTROLSET\\ENUM"), pstInfo, nLen);
}

int CSerial::SearchSerialPort(LPCTSTR lpszEnumPath, SERIALPORT_INFO* pstInfo, const int nLen)
{
	static const TCHAR lpszPortsClass[]		= TEXT("PORTS");
	static const TCHAR lpszPortsClassGUID[]	= TEXT("{4D36E978-E325-11CE-BFC1-08002BE10318}");

	int nCount = 0;

	HKEY	hkEnum			= NULL;
	HKEY	hkEnumDepth1	= NULL;
	HKEY	hkEnumDepth2	= NULL;
	HKEY	hkEnumDepth3	= NULL;

	HKEY	hkDevice		=NULL;

	DWORD	dwDepth1		= 0;
	DWORD	dwDepth2		= 0;
	DWORD	dwDepth3		= 0;

	LPTSTR	lpszPortName		=NULL;
	LPTSTR	lpszFriendlyName	=NULL;
	LPTSTR	lpszTechnology		=NULL;

	BOOL	bFoundFriendlyName	= FALSE;

	TCHAR  lpszClass[sizeof(lpszPortsClass)/sizeof(lpszPortsClass[0])];
	DWORD  dwClassLen		= 0;
	TCHAR  lpszClassGUID[sizeof(lpszPortsClassGUID)/sizeof(lpszPortsClassGUID[0])];
	DWORD  dwClassGUIDLen	= 0;

	DWORD	dwResult		= ERROR_SUCCESS;

	if(ERROR_SUCCESS != ::RegOpenKeyEx(HKEY_LOCAL_MACHINE,lpszEnumPath,0,KEY_ENUMERATE_SUB_KEYS,&hkEnum))
	{
		return 0;
	}

	// Loop First
	for(dwDepth1=0; ERROR_SUCCESS==dwResult; dwDepth1++)
	{
		if(NULL!=hkEnumDepth1)
		{
			::RegCloseKey(hkEnumDepth1);
			hkEnumDepth1 = NULL;
		}

		dwResult = OpenSubKeyByIndex(hkEnum, dwDepth1, KEY_ENUMERATE_SUB_KEYS, &hkEnumDepth1, &lpszTechnology);
		if(ERROR_SUCCESS != dwResult)
		{
			if(ERROR_NO_MORE_ITEMS == dwResult)
			{
				dwResult = ERROR_SUCCESS;
				break;
			}
			else
			{
				dwResult=ERROR_INVALID_DATA;
				continue;
			}
		}		

		// Loop Second
		for(dwDepth2=0; ERROR_SUCCESS==dwResult; dwDepth2++)
		{
			if(NULL!=hkEnumDepth2)
			{
				::RegCloseKey(hkEnumDepth2);
				hkEnumDepth2 = NULL;
			}

			dwResult = OpenSubKeyByIndex(hkEnumDepth1, dwDepth2, KEY_ENUMERATE_SUB_KEYS, &hkEnumDepth2, NULL);
			if(ERROR_SUCCESS != dwResult)
			{
				if(ERROR_NO_MORE_ITEMS == dwResult)
				{
					dwResult = ERROR_SUCCESS;
					break;
				}
				else
				{
					dwResult=ERROR_INVALID_DATA;
					continue;
				}
			}

			// Loop Third
			for(dwDepth3=0; ERROR_SUCCESS==dwResult; dwDepth3++)
			{
				if(NULL!=hkEnumDepth3)
				{
					::RegCloseKey(hkEnumDepth3);
					hkEnumDepth3 = NULL;
				}

				dwResult = OpenSubKeyByIndex(hkEnumDepth2, dwDepth3, KEY_READ, &hkEnumDepth3, NULL);
				if(ERROR_SUCCESS != dwResult)
				{
					if(ERROR_NO_MORE_ITEMS == dwResult)
					{
						dwResult = ERROR_SUCCESS;
						break;
					}
					else
					{
						dwResult=ERROR_INVALID_DATA;
						continue;
					}
				}


				dwClassLen=sizeof(lpszClass);

				if( ERROR_SUCCESS == ::RegQueryValueEx(hkEnumDepth3,TEXT("CLASS"),NULL,NULL,(LPBYTE)lpszClass,&dwClassLen)
					&& 0 == _tcsicmp(lpszPortsClass,lpszClass) )
				{
					// success
				}
				else
				{
					dwClassGUIDLen=sizeof(lpszClassGUID);
					if( ERROR_SUCCESS == ::RegQueryValueEx(hkEnumDepth3,TEXT("CLASSGUID"),NULL,NULL,(LPBYTE)lpszClassGUID,&dwClassGUIDLen)
						&& 0== _tcsicmp(lpszPortsClassGUID,lpszClassGUID))
					{
					}
					else
					{
						dwResult = ERROR_SUCCESS;
						continue;
					}
				}

				// Search Port name
				dwResult = QueryStringValue(hkEnumDepth3, TEXT("PORTNAME"), &lpszPortName);
				if(ERROR_FILE_NOT_FOUND == dwResult)
				{
					if( NULL!= hkDevice)
					{
						::RegCloseKey(hkDevice);
						hkDevice = NULL;

					}

					if(ERROR_SUCCESS==::RegOpenKeyEx(hkEnumDepth3,TEXT("DEVICE PARAMETERS"),0,KEY_READ,&hkDevice))
					{
						dwResult = QueryStringValue(hkDevice,TEXT("PORTNAME"),&lpszPortName);
					}
				}

				if(ERROR_SUCCESS != dwResult)
				{
					if(ERROR_FILE_NOT_FOUND == dwResult)
					{
						dwResult = ERROR_SUCCESS;
					}
					else
					{
						dwResult=ERROR_INVALID_DATA;
						continue;
					}
				}

				if( 0!=_tcsncicmp(lpszPortName,TEXT("COM"),3) )
					continue;


				// Search Friendly name
				dwResult = QueryStringValue(hkEnumDepth3, TEXT("FRIENDLYNAME"), &lpszFriendlyName);
				if( ERROR_SUCCESS==dwResult )
				{
					bFoundFriendlyName = TRUE;
				}
				else if( ERROR_FILE_NOT_FOUND==dwResult )
				{
					bFoundFriendlyName = FALSE;
					dwResult = ERROR_SUCCESS;
				}
				else
				{
					dwResult=ERROR_INVALID_DATA;
					continue;
				}

				if( pstInfo && nLen>nCount )
				{
					//_tcscpy(pstInfo[nCount].m_szPortName, lpszPortName);
					CUtil::StringCopy(pstInfo[nCount].m_szPortName, lpszPortName);
					if(bFoundFriendlyName)
					{
						//_tcscpy(pstInfo[nCount].m_szFriendlyName, lpszFriendlyName);
						CUtil::StringCopy(pstInfo[nCount].m_szFriendlyName, lpszFriendlyName);
					}
					else
					{
						//_tcscpy(pstInfo[nCount].m_szFriendlyName, lpszPortName);
						CUtil::StringCopy(pstInfo[nCount].m_szFriendlyName, lpszPortName);
					}

					//_tcscpy(pstInfo[nCount].m_szTechnology, lpszTechnology);
					CUtil::StringCopy(pstInfo[nCount].m_szTechnology, lpszTechnology);
				}

				EPORT ePort = CheckPort(lpszPortName);				
				if(EPORT_AVAILABLE==ePort || EPORT_INUSE==ePort)
					nCount++;

			}
		}
	}

	if(lpszTechnology)			free(lpszTechnology);
	if(lpszFriendlyName)		free(lpszFriendlyName);
	if(lpszPortName)			free(lpszPortName);

	if(hkDevice)				::RegCloseKey(hkDevice);
	if(hkEnumDepth3)			::RegCloseKey(hkEnumDepth3);
	if(hkEnumDepth2)			::RegCloseKey(hkEnumDepth2);
	if(hkEnumDepth1)			::RegCloseKey(hkEnumDepth1);
	if(hkEnum)					::RegCloseKey(hkEnum);

	if(ERROR_SUCCESS!=dwResult)
	{
		::SetLastError(dwResult);
		nCount = -1;
	}

	return nCount;
}



// todo...
// common_lib로 소스 정리 후 이동..필요...


LONG OpenSubKeyByIndex(HKEY hKey,DWORD dwIndex,REGSAM samDesired,PHKEY phkResult,LPTSTR* lppSubKeyName)
{
  DWORD              dwError=0;
  BOOL               bLocalSubkeyName=FALSE;
  LPTSTR             lpSubkeyName=NULL;
  DWORD              cbSubkeyName=128*sizeof(TCHAR); /* an initial guess */
  FILETIME           filetime;

  if(lppSubKeyName==NULL){
    bLocalSubkeyName=TRUE;
    lppSubKeyName=&lpSubkeyName;
  }
  /* loop asking for the subkey name til we allocated enough memory */

  for(;;){
    free(*lppSubKeyName);
    if(!(*lppSubKeyName=(LPTSTR)malloc(cbSubkeyName))){
       dwError=ERROR_NOT_ENOUGH_MEMORY;
       goto end;
    }
    if(!(dwError=RegEnumKeyEx(hKey,dwIndex,*lppSubKeyName,&cbSubkeyName,
                              0,NULL,NULL,&filetime))){
      break; /* we did it */
    }
    else if(dwError==ERROR_MORE_DATA){ /* not enough space */
      dwError=0;
      /* no indication of space required, we try doubling */
      cbSubkeyName=(cbSubkeyName+sizeof(TCHAR))*2;
    }
    else goto end;
  }

  dwError=RegOpenKeyEx(hKey,*lppSubKeyName,0,samDesired,phkResult);

end:
  if(bLocalSubkeyName)free(*lppSubKeyName);
  return dwError;
}

LONG QueryStringValue(HKEY hKey,LPCTSTR lpValueName,LPTSTR* lppStringValue)
{
  DWORD cbStringValue=128*sizeof(TCHAR); /* an initial guess */

  for(;;){
    DWORD dwError;

    free(*lppStringValue);
    if(!(*lppStringValue=(LPTSTR)malloc(cbStringValue))){
      return ERROR_NOT_ENOUGH_MEMORY;
    }
    if(!(dwError=RegQueryValueEx(hKey,lpValueName,NULL,NULL,
                                 (LPBYTE)*lppStringValue,&cbStringValue))){
      return ERROR_SUCCESS;
    }
    else if(dwError==ERROR_MORE_DATA){
      /* not enough space, keep looping */
    }
    else return dwError;
  }
}
