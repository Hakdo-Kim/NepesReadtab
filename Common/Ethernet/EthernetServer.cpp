#include "stdafx.h"
#include <mstcpip.h>

#include "EthernetServer.h"

#include "Util/Util.h"

CEthernetServer::CEthernetServer()
{
	m_hSocket = NULL;
	m_hSocketEvent = NULL;
}
CEthernetServer::~CEthernetServer()
{
}

BOOL CEthernetServer::IsOpen()
{
	return m_bOpen;
}

BOOL CEthernetServer::Open(const TCHAR* pszIpAddr, const TCHAR* pszPort, const TCHAR* pszProtocol, FuncNotifyEthernetListener Func, void* pArg)
{
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

	if (SOCKET_ERROR == ::bind(m_hSocket, (sockaddr*)&stAddr, sizeof(stAddr)))
	{
		Close();
		return FALSE;
	}

	if (SOCKET_ERROR == ::listen(m_hSocket, WSA_MAXIMUM_WAIT_EVENTS))
	{
		Close();
		return FALSE;
	}

	const BOOL bKeepAlive = TRUE;
	if (bKeepAlive)
	{
		struct tcp_keepalive
		{
			u_long onoff;
			u_long keepalivetime;
			u_long keepaliveinterval;
		};

		tcp_keepalive keepAlive;
		keepAlive.onoff = 1;
		keepAlive.keepalivetime = 3000;
		keepAlive.keepaliveinterval = 100;

		DWORD dwBytes = 0;

		if (SOCKET_ERROR == ::setsockopt(m_hSocket, SOL_SOCKET, SO_KEEPALIVE, (const char*)&bKeepAlive, sizeof(bKeepAlive)))
		{
			Close();
			return FALSE;
		}

		if (SOCKET_ERROR == ::WSAIoctl(m_hSocket,
			SIO_KEEPALIVE_VALS,
			&keepAlive,
			sizeof(tcp_keepalive),
			0,
			0,
			&dwBytes,
			NULL,
			NULL))
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

void CEthernetServer::Close()
{
	m_bOpen = FALSE;
	m_bStop = TRUE;

	{
		const int nCount = m_ClientList.size();
		for (int i = 0; i < nCount; i++)
		{
			CEthernetClient* pClient = m_ClientList[i];
			if (pClient)
			{
				pClient->Close();
				delete pClient;
			}
		}

		m_ClientList.clear();
	}


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

const int CEthernetServer::GetCountConnectedClinet()
{
	int nCount = m_ClientList.size();
	return nCount;
}

CEthernetClient* CEthernetServer::GetConnectedClinet(int nIdx)
{
	const int nCount = m_ClientList.size();
	if (0 > nIdx || nCount <= nIdx)
	{
		return NULL;
	}
	return m_ClientList[nIdx];
}

void CEthernetServer::DeleteClient(CEthernetClient* pClient)
{
	const int nCount = GetCountConnectedClinet();
	int idx = -1;
	
	for (int i = 0; i < nCount; i++)
	{
		if (m_ClientList[i] == pClient)
		{
			idx = i;
			break;
		}
	}

	if (-1 < idx)
	{
		// delete vector...
		m_ClientList.erase(m_ClientList.begin() + idx);
	}

}



const int CEthernetServer::GetConnectedClientCount()
{
	const int nCount = m_ClientList.size();
	return nCount;
}

int WINAPI CEthernetServer::AcceptCondition(WSABUF* pk_CallerId,
	WSABUF* pk_CallerData,
	QOS* pk_SQOS,
	QOS* pk_GQOS,
	WSABUF* pk_CalleeId,
	WSABUF* pk_CalleeData,
	UINT* pu32_Group,
	DWORD_PTR p_Param)
{
	CEthernetServer* pThis = (CEthernetServer*)p_Param;

	if (MAX_SERVER_CONNECTABLECOUNT <= pThis->GetConnectedClientCount())
		return CF_REJECT;
	else
		return CF_ACCEPT;
}



DWORD WINAPI CEthernetServer::ThreadProc(LPVOID lpArg)
{
	CEthernetServer* pEthernetServer = (CEthernetServer*)lpArg;
	return pEthernetServer->ThreadProc();
}

DWORD CEthernetServer::ThreadProc(void)
{
	WSANETWORKEVENTS stNetworkEvent;
	memset(&stNetworkEvent, 0x00, sizeof(WSANETWORKEVENTS));

	DWORD dwRes = 0;
	do
	{
		dwRes = ::WaitForSingleObject(m_hSocketEvent, INFINITE);
		if (WSA_WAIT_FAILED != dwRes  && WSA_WAIT_FAILED != dwRes && FALSE == m_bStop)
		{
			if (SOCKET_ERROR == ::WSAEnumNetworkEvents(m_hSocket, m_hSocketEvent, &stNetworkEvent))
				break;

			if (FD_ACCEPT & stNetworkEvent.lNetworkEvents)
			{
				if (stNetworkEvent.iErrorCode[FD_ACCEPT_BIT])
					break;

				SOCKET hSocketAcept = NULL;
				HANDLE hEventAcept = NULL;

				SOCKADDR_IN stAceptAddr;
				int nSize = sizeof(stAceptAddr);

				SOCKET hSocket = ::WSAAccept(m_hSocket, (LPSOCKADDR)&stAceptAddr, &nSize, AcceptCondition, (DWORD_PTR)this);
				if (INVALID_SOCKET == hSocket)
				{
					break;
				}

				hEventAcept = ::WSACreateEvent();
				if (WSA_INVALID_EVENT == hEventAcept)
				{
					::closesocket(hSocket);
					break;
				}

				if (SOCKET_ERROR == ::WSAEventSelect(hSocket, hEventAcept, FD_ALL_EVENTS))
				{
					::closesocket(hSocket);
					break;
				}


				{
					CEthernetClient* pEthernetClient = new CEthernetClient;
					BOOL bCreate = pEthernetClient->Open(hSocket, hEventAcept, stAceptAddr.sin_addr.s_addr, stAceptAddr.sin_port, m_szProtocol, m_FuncNotify, m_pArg);
					if (bCreate)
					{
						m_ClientList.push_back(pEthernetClient);
					}
					else
					{
						pEthernetClient->Close();
						delete pEthernetClient;
					}
				}
			}
		}
	} while (FALSE == m_bStop);

	return 0;
}