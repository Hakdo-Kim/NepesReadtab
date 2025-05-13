#include "stdafx.h"
#include "Serial.h"
#include "tchar.h"

#pragma warning(disable:4996)

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
		m_hOverlapped = ::CreateEvent(0,true,false,0);
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
