#include "StdAfx.h"
#include <mstcpip.h>

#include "EthernetServer.h"
#include "Util/Util.h"


CEthernetServer::CEthernetServer(void)
{
	m_hSocketListen		= INVALID_SOCKET;
	m_hThreadListen		= NULL;
	m_hEventListen		= NULL;


	m_hEventListenStop	= NULL;
	m_bStopListen		= FALSE;

	::InitializeCriticalSection(&m_CriticalSection);

}

CEthernetServer::~CEthernetServer(void)
{
	Close ();

	::DeleteCriticalSection(&m_CriticalSection);
}

const int CEthernetServer::GetConnectedClientCount()
{
	const int nCount = m_ClientArray.size();
	return nCount;
}

const INFO_CLIENT* CEthernetServer::GetConnectedClientInfo(int nIdx)
{
	const int nCount = GetConnectedClientCount();
	if(0>nIdx || nCount<=nIdx)
		return NULL;

	return m_ClientArray[nIdx];
}



BOOL CEthernetServer::IsOpen ()
{
	if( INVALID_SOCKET==m_hSocketListen )
		return FALSE;

	return TRUE;
}

BOOL CEthernetServer::Open (LPCTSTR pszAddress, DWORD dwPort, TYPE_PROTOCOL eProtocol)
{	
	if(this->IsOpen())
		this->Close();

	// Create socket
	if(TYPE_PROTOCOL_TCP == eProtocol)
		m_hSocketListen = socket(PF_INET, SOCK_STREAM, 0);
	else if(TYPE_PROTOCOL_UDP == eProtocol)
		m_hSocketListen = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);

	if(INVALID_SOCKET==m_hSocketListen)
        return FALSE;


	// Create socket event
	m_hEventListen = WSACreateEvent();
	if (WSA_INVALID_EVENT==m_hEventListen)
		return FALSE;

	if (SOCKET_ERROR==WSAEventSelect(m_hSocketListen, m_hEventListen, FD_ALL_EVENTS))
		return FALSE;

	// Setting socket...
	struct sockaddr_in stAddr;
	memset(&stAddr, 0x00, sizeof(sockaddr_in));
	stAddr.sin_family		= AF_INET; 
    stAddr.sin_addr.s_addr	= inet_addr(pszAddress); 
    stAddr.sin_port			= htons((u_short)dwPort); 

	if( SOCKET_ERROR == bind(m_hSocketListen, (sockaddr*)&stAddr, sizeof(stAddr)) )
        return FALSE;

	if( SOCKET_ERROR == listen(m_hSocketListen, WSA_MAXIMUM_WAIT_EVENTS) )
        return FALSE;

	const BOOL bKeepAlive = TRUE;
	if(bKeepAlive)
	{
		struct tcp_keepalive
		{
			u_long onoff;
			u_long keepalivetime;
			u_long keepaliveinterval;
		};

		tcp_keepalive keepAlive;  
		keepAlive.onoff				= 1;
		keepAlive.keepalivetime		= 3000;
		keepAlive.keepaliveinterval = 100;

		DWORD dwBytes = 0;

		if(SOCKET_ERROR==setsockopt(m_hSocketListen, SOL_SOCKET, SO_KEEPALIVE, (const char*) &bKeepAlive, sizeof(bKeepAlive)))
			return FALSE;

		if( SOCKET_ERROR == WSAIoctl(m_hSocketListen, 
								SIO_KEEPALIVE_VALS, 
								&keepAlive, 
								sizeof(tcp_keepalive),
								0,
								0,
								&dwBytes,
								NULL,
								NULL) )
		{
			return FALSE;
		}
		
	}

	

	// Thread Setting...
	m_hEventListenStop = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_hEventListenStop)
		return FALSE;

	DWORD dwThreadId = 0;
	m_hThreadListen = ::CreateThread(0, 0, ThreadListenProc, LPVOID(this), 0, &dwThreadId);

	return TRUE;
}

void CEthernetServer::Close ()
{
	m_bStopListen = TRUE;

	if(m_hEventListenStop)
	{
		::SetEvent(m_hEventListen);

		::ResetEvent(m_hEventListenStop);
		::WaitForSingleObject(m_hEventListenStop, 5000);

		::CloseHandle(m_hEventListenStop);
	}

	if(m_hThreadListen)
		::CloseHandle(m_hThreadListen);


	if(m_hEventListen)
		WSACloseEvent(m_hEventListen);


	if(INVALID_SOCKET!=m_hSocketListen)
		closesocket(m_hSocketListen);

	const int nCount = m_ClientArray.size();
	for(int i=0; i<nCount; i++)
	{
		INFO_CLIENT* pstClient = (INFO_CLIENT*) m_ClientArray[i];
		CEthernetClient* pClient = (CEthernetClient*)m_ClinetHashMap[pstClient->m_dwIpAddress];

		if(pstClient)
			delete pstClient;
		if(pClient)
			delete pClient;
	}

	std::vector<INFO_CLIENT*> cclear;		// vector memory leak ¹æÁö.
	m_ClientArray.swap(cclear);
	cclear.clear();
	m_ClientArray.clear();

	m_ClinetHashMap.clear();


	m_hSocketListen		= INVALID_SOCKET;
	m_hEventListen		= NULL;

	m_hThreadListen		= NULL;
	m_hEventListenStop	= NULL;
	m_bStopListen		= FALSE;
	
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

	if ( MAX_CAMERA_INTERFACE <= pThis->GetConnectedClientCount() )
		return CF_REJECT;
	else
		return CF_ACCEPT;
}


DWORD WINAPI CEthernetServer::ThreadListenProc(LPVOID lpArg)
{
	CEthernetServer* pEthernetServer = (CEthernetServer*)lpArg;

	return pEthernetServer->ThreadListenProc();
}

DWORD CEthernetServer::ThreadListenProc(void)
{
	DWORD dwRes = 0;	

	WSANETWORKEVENTS stNetworkEvent;
	memset(&stNetworkEvent, 0x00, sizeof(WSANETWORKEVENTS));

	m_bStopListen = FALSE;

	

	do
	{
		dwRes = ::WaitForSingleObject(m_hEventListen, INFINITE);
		if ( WSA_WAIT_FAILED != dwRes  && WSA_WAIT_FAILED != dwRes )
		{
			if (SOCKET_ERROR==::WSAEnumNetworkEvents(m_hSocketListen, m_hEventListen, &stNetworkEvent))
				break;

			if (FD_ACCEPT & stNetworkEvent.lNetworkEvents)
			{
				if (stNetworkEvent.iErrorCode[FD_ACCEPT_BIT])
					break;

				SOCKET hSocketAcept = NULL;
				HANDLE hEventAcept	= NULL;

				SOCKADDR_IN stAceptAddr;
				int nSize = sizeof(stAceptAddr);

				SOCKET hSocket = WSAAccept(m_hSocketListen, (LPSOCKADDR)&stAceptAddr, &nSize, AcceptCondition, (DWORD_PTR)this);
				if (INVALID_SOCKET==hSocket)
				{
					break;
				}

				hEventAcept = WSACreateEvent();
				if (WSA_INVALID_EVENT==hEventAcept)
				{
					closesocket(hSocket);
					break;
				}

				if (SOCKET_ERROR==WSAEventSelect(hSocket, hEventAcept, FD_ALL_EVENTS))
				{
					closesocket(hSocket);
					break;
				}


				{
					INFO_CLIENT stClient;
					memset(&stClient, 0x00, sizeof(INFO_CLIENT));

					//stClient.m_szName		= ;

					stClient.m_hSocket		= hSocket;
					stClient.m_hEvent		= hEventAcept;

					stClient.m_dwIpAddress	= stAceptAddr.sin_addr.s_addr;
					stClient.m_dwPort		= stAceptAddr.sin_port;


					AddClient(&stClient);
				}
			}
		}

	} while (FALSE == m_bStopListen);

	if (FALSE == m_bStopListen)
	{
		this->Close();

		// todo
		// send message to user...
	}
	else
	{
		if(m_hEventListenStop)
			SetEvent(m_hEventListenStop);
	}

	return 0;
}


BOOL CEthernetServer::IsExistClient(const INFO_CLIENT* pstClient)
{
	if(NULL==pstClient)
		return FALSE;

	const int nCount = m_ClientArray.size();
	for(int i=0; i<nCount; i++)
	{
		if(pstClient->m_dwIpAddress==m_ClientArray[i]->m_dwIpAddress)
			return TRUE;
	}

	return FALSE;
}

BOOL CEthernetServer::AddClient(const INFO_CLIENT* pstClient)
{
	if( NULL==pstClient || IsExistClient(pstClient) )
		return FALSE;

	::EnterCriticalSection(&m_CriticalSection);			//

	INFO_CLIENT* pInfo = new INFO_CLIENT;
	memset(pInfo, 0x00, sizeof(INFO_CLIENT));

	CUtil::StringCopy(pInfo->m_szName, pstClient->m_szName);
	pInfo->m_hSocket		= pstClient->m_hSocket;
	pInfo->m_hEvent			= pstClient->m_hEvent;
	pInfo->m_dwIpAddress	= pstClient->m_dwIpAddress;
	pInfo->m_dwPort			= pstClient->m_dwPort;


	CEthernetClient* pClinet = new CEthernetClient;
	BOOL bResult = pClinet->Open(pstClient->m_hSocket, pstClient->m_hEvent, pstClient->m_dwIpAddress, pstClient->m_dwPort);
	if(bResult)
	{
		m_ClientArray.push_back(pInfo);
		m_ClinetHashMap.insert(stdext::hash_map<DWORD, CEthernetClient*>::value_type(pstClient->m_dwIpAddress, pClinet));
	
	}
	::LeaveCriticalSection(&m_CriticalSection);			//

	return TRUE;
}

BOOL CEthernetServer::GetWidth(const int nIdx, DWORD* pdwValue)
{
	const int nCount = GetConnectedClientCount() ;
	if( 0>nIdx || nIdx >= nCount || NULL==pdwValue )
		return FALSE;

	const INFO_CLIENT* pstClient = m_ClientArray[nIdx];
	CEthernetClient* pClient = (CEthernetClient*)m_ClinetHashMap[pstClient->m_dwIpAddress];

	BOOL bResult = pClient->GetWidth(pdwValue);
	return bResult;
}

BOOL CEthernetServer::GetHeight(const int nIdx, DWORD* pdwValue)
{
	const int nCount = GetConnectedClientCount() ;
	if( 0>nIdx || nIdx >= nCount || NULL==pdwValue )
		return FALSE;

	const INFO_CLIENT* pstClient = m_ClientArray[nIdx];
	CEthernetClient* pClient = (CEthernetClient*)m_ClinetHashMap[pstClient->m_dwIpAddress];

	BOOL bResult = pClient->GetHeight(pdwValue);
	return bResult;
}

BOOL CEthernetServer::GetMaxWidth(const int nIdx, DWORD* pdwValue)
{
	const int nCount = GetConnectedClientCount() ;
	if( 0>nIdx || nIdx >= nCount || NULL==pdwValue )
		return FALSE;

	const INFO_CLIENT* pstClient = m_ClientArray[nIdx];
	CEthernetClient* pClient = (CEthernetClient*)m_ClinetHashMap[pstClient->m_dwIpAddress];

	BOOL bResult = pClient->GetMaxWidth(pdwValue);
	return bResult;
}

BOOL CEthernetServer::GetMaxHeight(const int nIdx, DWORD* pdwValue)
{
	const int nCount = GetConnectedClientCount() ;
	if( 0>nIdx || nIdx >= nCount || NULL==pdwValue )
		return FALSE;

	const INFO_CLIENT* pstClient = m_ClientArray[nIdx];
	CEthernetClient* pClient = (CEthernetClient*)m_ClinetHashMap[pstClient->m_dwIpAddress];

	BOOL bResult = pClient->GetMaxHeight(pdwValue);
	return bResult;
}

BOOL CEthernetServer::GetPixelFormat(const int nIdx, DWORD* pdwValue)
{
	const int nCount = GetConnectedClientCount() ;
	if( 0>nIdx || nIdx >= nCount || NULL==pdwValue )
		return FALSE;

	const INFO_CLIENT* pstClient = m_ClientArray[nIdx];
	CEthernetClient* pClient = (CEthernetClient*)m_ClinetHashMap[pstClient->m_dwIpAddress];

	BOOL bResult = pClient->GetPixelFormat(pdwValue);
	return bResult;
}


