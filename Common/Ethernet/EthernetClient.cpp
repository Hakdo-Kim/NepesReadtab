#include "stdafx.h"
#include "EthernetClient.h"

#include "Util/Util.h"

CEthernetClient::CEthernetClient()
{
	::InitializeCriticalSection(&m_CriticalSection);

	m_hSocket = INVALID_SOCKET;
	m_hSocketEvent = NULL;
#ifdef DEF_DUMP_ETHERNET_PACKET
	{
		TCHAR szCurPath[MAX_FILE_PATH_LEN] = { 0, };
		TCHAR szDumpPath[MAX_FILE_PATH_LEN] = { 0, };

		CUtil::GetCurrentDirectory(szCurPath, MAX_FILE_PATH_LEN);
		CUtil::StringFormat(szDumpPath, MAX_FILE_PATH_LEN, _T("%s\\%d_ethernet_dump.txt"), szCurPath, ::GetTickCount());

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
CEthernetClient::~CEthernetClient()
{
	::DeleteCriticalSection(&m_CriticalSection);
#ifdef DEF_DUMP_ETHERNET_PACKET
	{
		if (INVALID_HANDLE_VALUE != m_hDumpFile)
		{
			::CloseHandle(m_hDumpFile);
		}
	}
#endif
}

BOOL CEthernetClient::IsOpen()
{
	return m_bOpen;
}

BOOL CEthernetClient::Open(const TCHAR* pszIpAddr, const TCHAR* pszPort, const TCHAR* pszProtocol, FuncNotifyEthernetListener Func, void* pArg)
{
	m_bOpen = FALSE;

	if (NULL == pszIpAddr || NULL == pszPort || NULL == pszProtocol)
		return FALSE;

	CUtil::StringCopy(m_szIpAddr, pszIpAddr);
	CUtil::StringCopy(m_szPort, pszPort);
	CUtil::StringCopy(m_szProtocol, pszProtocol);

	DWORD dwPort = CUtil::StringToDword((TCHAR*)pszPort, CUtil::StringLength((TCHAR*)pszPort));

	// Socket
	if (CUtil::StringICompare((TCHAR*)pszProtocol, _T("TCP")))
		m_hSocket = ::socket(PF_INET, SOCK_STREAM, 0);
	else if (CUtil::StringICompare((TCHAR*)pszProtocol, _T("UDP")))
		m_hSocket = ::socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	else
		return FALSE;

	if (INVALID_SOCKET == m_hSocket)
		return FALSE;

	m_hSocketEvent = ::WSACreateEvent();
	if (WSA_INVALID_EVENT == m_hSocketEvent)
	{
		Close();
		return FALSE;
	}
	if (SOCKET_ERROR == ::WSAEventSelect(m_hSocket, m_hSocketEvent, FD_ALL_EVENTS))
	{
		Close();
		return FALSE;
	}


	// Setting socket...
	struct sockaddr_in stAddr;
	memset(&stAddr, NULL, sizeof(stAddr));
	stAddr.sin_family = AF_INET;
	stAddr.sin_addr.s_addr = ::inet_addr(pszIpAddr);
	stAddr.sin_port = ::htons((u_short)dwPort);

	// Connect timeout...
	ULONG nonBlk = TRUE;
	if (SOCKET_ERROR == ::ioctlsocket(m_hSocket, FIONBIO, &nonBlk))
	{
		Close();
		return FALSE;
	}
	if (SOCKET_ERROR == ::connect(m_hSocket, (struct sockaddr *)&stAddr, sizeof(stAddr)))
	{
		const int nRes = ::WSAGetLastError();
		if (WSAEINVAL == nRes || WSAEWOULDBLOCK == nRes)
		{
			// Waiting socket ready...
			const int timeout = 250;
			struct timeval to = { 0, timeout * 1000 };
			fd_set fds;

			FD_ZERO(&fds);
			FD_SET(m_hSocket, &fds);

			int nReady = ::select(1, NULL, &fds, NULL, &to);	// ready to send
			// int nReady = ::select(1, &fds, NULL, NULL, &to); // ready to receive

			if (0 >= nReady)
			{
				Close();
				return FALSE;
			}
		}
	}
	else
	{
		fd_set stFdset;
		struct timeval stTime;

		FD_ZERO(&stFdset);
		FD_SET(m_hSocket, &stFdset);
		stTime.tv_sec = 1;
		stTime.tv_usec = 0;

		::select((int)(m_hSocket + 1), &stFdset, NULL, NULL, &stTime);
		if (!::FD_ISSET(m_hSocket, &stFdset))
		{
			Close();
			return FALSE;
		}
	}



	// Thread
	m_bStop = FALSE;
	m_hEvent = ::CreateEvent(0, true, false, 0);
	if (NULL == m_hEvent)
	{
		Close();
		return FALSE;
	}
	m_hThread = ::CreateThread(0, 0, ThreadProc, LPVOID(this), 0, &m_dwThreadId);
	if (NULL == m_hThread)
	{
		Close();
		return FALSE;
	}
	
	// Notify
	m_FuncNotify = Func;
	m_pArg = pArg;


	m_bOpen = TRUE;
	return TRUE;
}


BOOL CEthernetClient::Open(SOCKET hSocket, HANDLE hEvent, DWORD dwIpAddress, DWORD dwPort, const TCHAR* pszProtocol, FuncNotifyEthernetListener Func, void* pArg)
{
	m_bOpen = FALSE;

	if (INVALID_SOCKET == hSocket || WSA_INVALID_EVENT == hEvent || NULL == pszProtocol)
		return FALSE;

	CUtil::StringFormat(m_szIpAddr, MAX_NAME_LEN, _T("%d.%d.%d.%d"),
		(dwIpAddress & 0x000000FF),
		(dwIpAddress & 0x0000FF00) >> 8,
		(dwIpAddress & 0x00FF0000) >> 16,
		(dwIpAddress & 0xFF000000) >> 24);
	CUtil::StringFormat(m_szPort, MAX_NAME_LEN, _T("%d"), dwPort);
	CUtil::StringCopy(m_szProtocol, pszProtocol);

	// Socket
	m_hSocket = hSocket;
	m_hSocketEvent = hEvent;

	// Thread
	m_bStop = FALSE;
	m_hEvent = ::CreateEvent(0, true, false, 0);
	if (NULL == m_hEvent)
	{
		Close();
		return FALSE;
	}
	m_hThread = ::CreateThread(0, 0, ThreadProc, LPVOID(this), 0, &m_dwThreadId);
	if (NULL == m_hThread)
	{
		Close();
		return FALSE;
	}

	// Notify
	m_FuncNotify = Func;
	m_pArg = pArg;


	m_bOpen = TRUE;
	return TRUE;
}




void CEthernetClient::Close()
{
	m_bOpen = FALSE;
	m_bStop = TRUE;


	// Notify
	m_FuncNotify = NULL;
	m_pArg = NULL;

	// Thread
	if (m_hEvent)
	{
		::SetEvent(m_hEvent);
		::CloseHandle(m_hEvent);
	}
	if (m_hThread)
	{
		::CloseHandle(m_hThread);
	}

	m_hEvent = NULL;
	m_hThread = NULL;

	// Socket
	if (m_hSocketEvent)
		::WSACloseEvent(m_hSocketEvent);
	if (INVALID_SOCKET != m_hSocket)
		::closesocket(m_hSocket);

	m_hSocketEvent = NULL;
	m_hSocket = NULL;
}

BOOL CEthernetClient::SendCommand(const void* pCmdBuf, const DWORD dwCmdLen, void* pResBuf, int& nResLen)
{
	::EnterCriticalSection(&m_CriticalSection);
	m_bSkipThreadRead = TRUE;

	int nWrite = 0;
	int nRead = 0;

	DWORD dwStartTick = 0;
	DWORD dwEndTick = 0;

	BOOL bResult = Write((void*)pCmdBuf, dwCmdLen, &nWrite);
	/*//
	if (bResult)
	{
		DWORD dwCount = 0;
		bResult = FALSE;
		dwStartTick = ::GetTickCount();
		do
		{
			dwCount = 0;
			if (SOCKET_ERROR != ::ioctlsocket(m_hSocket, FIONREAD, &dwCount))
			{
				if (Read(pResBuf, nResLen, &nRead) && 2 < nRead)
				{
					bResult = TRUE;
				}
			}
			dwEndTick = ::GetTickCount();
		} while (FALSE == bResult && TIMEOUT > (int)(dwEndTick - dwStartTick));
	}
	//*/

	m_bSkipThreadRead = FALSE;
	::LeaveCriticalSection(&m_CriticalSection);

	return bResult;
}


BOOL CEthernetClient::Read(void* pData, DWORD dwLen, int* pnRead)
{
	if (FALSE == IsOpen() || NULL == pData || 0 >= dwLen)
		return FALSE;

	int nVal = ::recv(m_hSocket, (char*)pData, (int)dwLen, NULL);
	if (pnRead)
	{
		*pnRead = nVal;
	}
	return TRUE;

}

BOOL CEthernetClient::Write(void* pData, DWORD dwLen, int* pnWrite)
{
	if (FALSE == IsOpen() || NULL == pData || 0 >= dwLen)
		return FALSE;

	int nVal = ::send(m_hSocket, (char*)pData, (int)dwLen, NULL);
	if (pnWrite)
	{
		*pnWrite = nVal;
	}
	return TRUE;
}



DWORD WINAPI CEthernetClient::ThreadProc(LPVOID lpArg)
{
	CEthernetClient* pEthernetClient = (CEthernetClient*)lpArg;
	return pEthernetClient->ThreadProc();
}

DWORD CEthernetClient::ThreadProc(void)
{
	DWORD dwCount = 0;
	do
	{
		dwCount = 0;
		if (SOCKET_ERROR != ::ioctlsocket(m_hSocket, FIONREAD, &dwCount))
		{
			BYTE pRead[MAX_PATH] = { 0, };
			int nReadIdx = 0;

			// String Input...
			if (m_bSkipThreadRead)
				continue;

			if (Read(pRead, MAX_PATH, &nReadIdx) && 0 < nReadIdx)
			{
				CUtil::PrintDebugString(_T("\r\n[%d][%s]\r\n"), ::GetTickCount(), pRead);
#ifdef DEF_DUMP_ETHERNET_PACKET
				{
					if (INVALID_HANDLE_VALUE != m_hDumpFile)
					{
						TCHAR szEthernet[MAX_FILE_PATH_LEN] = { 0, };
						DWORD dwResult = 0;
						CUtil::StringFormat(szEthernet, MAX_FILE_PATH_LEN, _T("[%d][%s]\r\n"), ::GetTickCount(), pRead);
						::WriteFile(m_hDumpFile, szEthernet, CUtil::StringLength(szEthernet), &dwResult, NULL);
					}
				}
#endif
#if 1
				BOOL bFindCommand = FALSE;
				int nStart = 0;
				int nPos = 0;
				do
				{
					bFindCommand = CUtil::StringSearch((TCHAR*)pRead + nStart, _T("\r\n"), &nPos);
					if (bFindCommand)
					{
						if (0 < nStart)
						{
							int i = 0;
						}

						memset(m_szReadBuffer, 0x00, sizeof(TCHAR)*MAX_PATH);
						CUtil::StringCopy(m_szReadBuffer, (TCHAR*)pRead + nStart, nPos + 2);
						nStart += (nPos + 2);
						if (m_FuncNotify)
						{
							m_FuncNotify((DWORD)this, m_pArg);
						}
					}
				} while (bFindCommand && nReadIdx > nStart);
#else
				CUtil::StringFormat(m_szReadBuffer, MAX_PATH, _T("%s"), pRead);
				if (m_FuncNotify)
				{
					m_FuncNotify((DWORD)this, m_pArg);
				}
#endif
			}
			else if (0 == nReadIdx)
			{
				m_bStop = TRUE;
			}
		}
	} while (FALSE == m_bStop);

	// Disconnected ethernet...
	if (this->IsOpen())
	{
		FuncNotifyEthernetListener FuncNotify = m_FuncNotify;
		void* pArg = m_pArg;

		this->Close();

		FuncNotify((DWORD)this, pArg);
	}

	return 0;
}