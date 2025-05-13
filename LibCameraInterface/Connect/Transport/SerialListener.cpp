#include "stdafx.h"
#include "SerialListener.h"

#include "Util/Util.h"

CSerialListener::CSerialListener()
{
	m_hThread	= NULL;
	m_dwThreadId= 0;

	m_hEvent	= NULL;

	m_bStop		= FALSE;
	m_hWnd		= NULL;

	m_bConnected = FALSE;

	memset(m_szReadBuffer, 0x00, MAX_PATH);

}

CSerialListener::~CSerialListener()
{
	StopListener();
}

void CSerialListener::SetMessageWindow(HWND hWnd)
{
	m_hWnd = hWnd;
}

const TCHAR* CSerialListener::GetInputString()
{
	return m_szReadBuffer;
}

void CSerialListener::ResetInputString()
{
	memset(m_szReadBuffer, 0x00, MAX_PATH);
}


BOOL CSerialListener::IsConnected()
{
	return m_bConnected;
}



BOOL CSerialListener::StartListener(LPCTSTR lpszDevice, DWORD dwBaudrate, DWORD dwId, HWND hWnd)
{
	if (NULL == lpszDevice)
		return FALSE;

	if (m_bConnected)
	{
		StopListener();

		m_bConnected = FALSE;
	}

	m_dwListenerId = dwId;

	m_bStop = FALSE;
	m_hWnd = hWnd;
	
	m_bConnected = this->Open(lpszDevice, dwBaudrate);
	if (FALSE == m_bConnected)
		return FALSE;

	m_hEvent = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_hEvent)
	{
		StopListener();
		return FALSE;
	}

	m_hThread = ::CreateThread(0, 0, ThreadProc, LPVOID(this), 0, &m_dwThreadId);
	if (NULL == m_hThread)
	{
		StopListener();		
		return FALSE;
	}


	return TRUE;
}

void CSerialListener::StopListener()
{
	m_bStop = TRUE;

	this->Close();

	if (m_hEvent)
		::CloseHandle(m_hEvent);

	if (m_hThread)
		::CloseHandle(m_hThread);

	m_hEvent = NULL;
	m_hThread = NULL;

	m_bConnected = FALSE;

}

DWORD WINAPI CSerialListener::ThreadProc(LPVOID lpArg)
{
	CSerialListener* pSerialListener = (CSerialListener*)lpArg;

	return pSerialListener->ThreadProc();
}

DWORD CSerialListener::ThreadProc(void)
{
	do
	{
		if (m_hEvent)
			::ResetEvent(m_hEvent);
		else
			break;

		OVERLAPPED ovInternal = { 0 };
		ovInternal.hEvent = m_hEvent;

		// Wait Event...
		HANDLE hFile = this->GetSerialHandle();
		if (!::WaitCommEvent(hFile, LPDWORD(&m_eEvent), &ovInternal))
		{
			switch (::WaitForSingleObject(ovInternal.hEvent, INFINITE))
			{
			case WAIT_OBJECT_0:
				// The overlapped operation has completed
				break;
			case WAIT_TIMEOUT:
				::CancelIo(hFile);
				break;
			default:
				break;
			}
		}
		else
		{
			::SetEvent(ovInternal.hEvent);
		}

		if (::WaitForSingleObject(m_hEvent, INFINITE) != WAIT_OBJECT_0)
		{
			break;
		}
		else
		{

			DWORD dwErrors = 0;
			::ClearCommError(hFile, &dwErrors, 0);

			// read buffer

			BYTE pRead[MAX_PATH] = { 0, };
			int nReadIdx = 0;

			do
			{
				BYTE pBuffer[MAX_PATH] = { 0, };
				DWORD dwBuf = 0;
				if (FALSE == this->Read(pBuffer, MAX_PATH, &dwBuf) || 1>dwBuf)
				{
					break;
				}

				memcpy(pRead + nReadIdx, pBuffer, dwBuf);
				nReadIdx += dwBuf;

			} while (FALSE==CUtil::StringSearch((TCHAR*)pRead, _T("\r\n")));


			if (0 < nReadIdx)
			{
				int nPos = 0;
				memset(m_szReadBuffer, 0x00, MAX_PATH);

				if (CUtil::StringSearch((TCHAR*)pRead, _T("\r\n"), &nPos))
				{
					CUtil::StringCopy(m_szReadBuffer, (TCHAR*)pRead, nPos);
				}
				else
				{
					CUtil::StringCopy(m_szReadBuffer, (TCHAR*)pRead, CUtil::StringLength((TCHAR*)pRead));
				}

				if (m_hWnd)
				{
					::SendMessage(m_hWnd, WM_NOTIFY_SERIAL_INPUT, m_dwListenerId, 0);
				}


			}

		}

		if (TRUE == m_bStop)
		{
			DWORD dwErrors = 0;
			::ClearCommError(hFile, &dwErrors, 0);
		}

	} while (FALSE == m_bStop);

	return 0;
}