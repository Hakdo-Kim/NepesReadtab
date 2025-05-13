#include "StdAfx.h"
#include "EthernetClient.h"

#include "Connect/Command/DefineEthernet.h"
#include "Util/Util.h"

CEthernetClient::CEthernetClient(void)
{
	m_hSocketClient		= INVALID_SOCKET;
	m_hThreadClient		= NULL;
	m_hEventClient		= NULL;
	
	m_hEventClientStop	= NULL;
	m_bStopClient		= FALSE;

	m_bBroadCastClient	= FALSE;

	memset(m_szIpAddress, 0x00, sizeof(TCHAR)*MAX_NAME_LEN);
	m_dwPort	= 0;
	m_eProtocol	= TYPE_PROTOCOL_NONE;

	::InitializeCriticalSection(&m_CriticalSection);
}

CEthernetClient::~CEthernetClient(void)
{
	Close();

	::DeleteCriticalSection(&m_CriticalSection);
}


BOOL CEthernetClient::IsOpen ()
{
	if( INVALID_SOCKET==m_hSocketClient )
		return FALSE;

	return TRUE;
}



BOOL CEthernetClient::Open (SOCKET hSocket, HANDLE hEvent, DWORD dwIpAddress, DWORD dwPort)
{
	if( INVALID_SOCKET==hSocket || NULL==hEvent)
		return FALSE;

	if(this->IsOpen())
		this->Close();

	m_hSocketClient	= hSocket;
	m_hEventClient	= hEvent;

	// Thread Setting...
	m_hEventClientStop = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_hEventClientStop)
		return FALSE;

	DWORD dwThreadId = 0;
	m_hThreadClient = ::CreateThread(0, 0, ThreadClientProc, LPVOID(this), 0, &dwThreadId);



	{
		// Client Information
		CUtil::StringFormat(m_szIpAddress, MAX_NAME_LEN, _T("%d.%d.%d.%d"), 
								dwIpAddress & 0xFF,
								(dwIpAddress >> 8) & 0xFF,
								(dwIpAddress >> 16) & 0xFF,
								(dwIpAddress >> 24) & 0xFF );
		m_dwPort	= dwPort;
		m_eProtocol	= TYPE_PROTOCOL_TCP;
	}

	return TRUE;
	
}


BOOL CEthernetClient::Open(LPCTSTR pszAddress, DWORD dwPort, TYPE_PROTOCOL eProtocol)
{
	if(NULL==pszAddress)
		return FALSE;

	if(this->IsOpen())
		this->Close();

	// Create socket
	if(TYPE_PROTOCOL_TCP == eProtocol)
		m_hSocketClient = socket(PF_INET, SOCK_STREAM, 0);
	else if(TYPE_PROTOCOL_UDP == eProtocol)
		m_hSocketClient = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (INVALID_SOCKET==m_hSocketClient)
		return FALSE;

	// Create socket event
	m_hEventClient = WSACreateEvent();
	if (WSA_INVALID_EVENT==m_hEventClient)
		return FALSE;

	if (SOCKET_ERROR==WSAEventSelect(m_hSocketClient, m_hEventClient, FD_ALL_EVENTS))
		return FALSE;


	// Setting socket...
	struct sockaddr_in stAddr;
	memset( &stAddr, NULL, sizeof(stAddr) );
	stAddr.sin_family		= AF_INET;
	stAddr.sin_addr.s_addr	= inet_addr( pszAddress );
	stAddr.sin_port			= htons( (u_short)dwPort );

	// Connect timeout...
	ULONG nonBlk = TRUE;
	if(SOCKET_ERROR == ioctlsocket(m_hSocketClient, FIONBIO, &nonBlk))
		return FALSE;
		
	if(SOCKET_ERROR == connect(m_hSocketClient, (struct sockaddr *)&stAddr, sizeof(stAddr)))
		return FALSE;

	fd_set stFdset;
	struct timeval stTime;

	FD_ZERO(&stFdset);
	FD_SET(m_hSocketClient, &stFdset);
	stTime.tv_sec	= 1;
	stTime.tv_usec	= 0;

	select(m_hSocketClient + 1, &stFdset, NULL, NULL, &stTime);
	if (!FD_ISSET(m_hSocketClient, &stFdset))
	{
		closesocket(m_hSocketClient);
		m_hSocketClient = INVALID_SOCKET;

		return FALSE;
	}


	// Thread Setting...
	m_hEventClientStop = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_hEventClientStop)
		return FALSE;

	DWORD dwThreadId = 0;
	m_hThreadClient = ::CreateThread(0, 0, ThreadClientProc, LPVOID(this), 0, &dwThreadId);



	{
		CUtil::StringCopy(m_szIpAddress, pszAddress);
		m_dwPort	= dwPort;
		m_eProtocol	= eProtocol;
	}

	return TRUE;
}


BOOL CEthernetClient::OpenBroadCastClient(LPCTSTR pszAddress, DWORD dwPort)
{
	if(NULL==pszAddress)
		return FALSE;

	if(this->IsOpen())
		this->Close();

	m_bBroadCastClient = TRUE;

	const BOOL bDontRout	= TRUE;

	m_hSocketClient = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (INVALID_SOCKET==m_hSocketClient)
		return FALSE;

	struct sockaddr_in stAddr;
	memset( &stAddr, NULL, sizeof(stAddr) );
	stAddr.sin_family		= AF_INET;
	stAddr.sin_addr.s_addr	= inet_addr( pszAddress );
	stAddr.sin_port			= htons( (u_short)dwPort );

	int nRes = bind(m_hSocketClient, (sockaddr*)&stAddr, sizeof(stAddr));
	if(SOCKET_ERROR!=nRes)
		nRes = setsockopt(m_hSocketClient, SOL_SOCKET, SO_DONTROUTE, (char*) &bDontRout, sizeof(bDontRout));

	{
		CUtil::StringCopy(m_szIpAddress, pszAddress);
		m_dwPort	= dwPort;
		m_eProtocol	= TYPE_PROTOCOL_UDP_BROADCAST;
	}

	return TRUE;
}

BOOL CEthernetClient::SendBroadcastPacket (const INFO_COMMAND* pstCmd )
{
	if(FALSE==this->IsOpen() || NULL==pstCmd || FALSE==m_bBroadCastClient )
		return FALSE;

	// Setting socket...
	const BOOL bBroadcast	= TRUE;
	const int nTimeOut		= 500;
    
	int nRes = setsockopt(m_hSocketClient, SOL_SOCKET, SO_BROADCAST, (char*) &bBroadcast, sizeof(bBroadcast));

	if(SOCKET_ERROR!=nRes)
		nRes = setsockopt(m_hSocketClient, SOL_SOCKET, SO_RCVTIMEO, (char*) &nTimeOut, sizeof(nTimeOut));

	if(SOCKET_ERROR!=nRes)
	{
		// Send Broadcast packet....
		struct sockaddr_in stAddr;
		memset( &stAddr, NULL, sizeof(stAddr) );
		stAddr.sin_family		= AF_INET;
		stAddr.sin_addr.s_addr	= inet_addr( _T("255.255.255.255") );
		stAddr.sin_port			= htons( ETHERNET_PORT_GVCP );

		nRes = sendto(m_hSocketClient, (char*)pstCmd->m_Request, pstCmd->m_dwRequestLen, 0, (sockaddr*) &stAddr, sizeof(SOCKADDR));
		if( SOCKET_ERROR==nRes || pstCmd->m_dwRequestLen!=nRes )
			return FALSE;
	}

	return TRUE;

}



void CEthernetClient::Close ()
{

	m_bStopClient = TRUE;

	if(m_hEventClientStop)
	{
		::SetEvent(m_hEventClient);		

		::ResetEvent(m_hEventClientStop);
		::WaitForSingleObject(m_hEventClientStop, 5000);

		::CloseHandle(m_hEventClientStop);
	}

	if(m_hThreadClient)
		::CloseHandle(m_hThreadClient);


	if(m_hEventClient)
		WSACloseEvent(m_hEventClient);


	if(INVALID_SOCKET!=m_hSocketClient)
		closesocket(m_hSocketClient);

	
	m_hSocketClient		= INVALID_SOCKET;
	m_hThreadClient		= NULL;
	m_hEventClient		= NULL;
	
	m_hEventClientStop	= NULL;
	m_bStopClient		= FALSE;


	memset(m_szIpAddress, 0x00, sizeof(TCHAR)*MAX_NAME_LEN);
	m_dwPort	= 0;
	m_eProtocol	= TYPE_PROTOCOL_NONE;

}

BOOL CEthernetClient::GetClientInfo(TCHAR* pszIpAddr, DWORD* pdwPort, TYPE_PROTOCOL* peProtocol)
{
	if(NULL==pszIpAddr || NULL==pdwPort || NULL==peProtocol)
		return FALSE;

	CUtil::StringCopy(pszIpAddr, m_szIpAddress);
	*pdwPort	= m_dwPort;
	*peProtocol	= m_eProtocol;

	return TRUE;
}

const TYPE_PROTOCOL CEthernetClient::GetProtocolType()
{
	if (FALSE==IsOpen ())
		return TYPE_PROTOCOL_NONE;

	return m_eProtocol;
}

int CEthernetClient::Write (BYTE* pBuf, DWORD dwLen)
{
	if(NULL==pBuf || 0>=dwLen)
		return 0;

	int nVal = send( m_hSocketClient, (char*)pBuf, (int)dwLen, NULL );

	return nVal;
}
int CEthernetClient::Read (BYTE* pBuf, DWORD dwLen)
{
	if(NULL==pBuf || 0>=dwLen)
		return 0;

	int nVal =  recv( m_hSocketClient, (char*)pBuf, (int)dwLen, NULL );
	
	return nVal;
}


DWORD WINAPI CEthernetClient::ThreadClientProc(LPVOID lpArg)
{
	CEthernetClient* pEthernetClient = (CEthernetClient*)lpArg;

	return pEthernetClient->ThreadClientProc();
}

DWORD CEthernetClient::ThreadClientProc(void)
{
	DWORD dwResult = 0;

	WSANETWORKEVENTS stNetworkEvent;
	memset(&stNetworkEvent, 0x00, sizeof(WSANETWORKEVENTS));

	m_bStopClient = FALSE;

	do
	{
		dwResult = ::WaitForSingleObject(m_hEventClient, INFINITE);
		if ( WSA_WAIT_FAILED != dwResult  && WSA_WAIT_FAILED != dwResult )
		{
			if (SOCKET_ERROR==::WSAEnumNetworkEvents(m_hSocketClient, m_hEventClient, &stNetworkEvent))
				break;

			if (FD_READ & stNetworkEvent.lNetworkEvents)
			{
				if (stNetworkEvent.iErrorCode[FD_ACCEPT_BIT])
					break;
			}
			else if (FD_WRITE & stNetworkEvent.lNetworkEvents)
			{
				if (stNetworkEvent.iErrorCode[FD_ACCEPT_BIT])
					break;
			}
		}

	} while (FALSE == m_bStopClient);

	if (FALSE == m_bStopClient)
	{
		this->Close();

		// todo
		// send message to user...
	}
	else
	{
		if(m_hEventClientStop)
			SetEvent(m_hEventClientStop);
	}

	return 0;
}

BOOL CEthernetClient::SendCommand(INFO_ARGUMENT& stArg)
{
	::EnterCriticalSection(&m_CriticalSection);

	INFO_COMMAND  stCmd;
	BOOL bResult = m_CommandEthernet.MuxCommand(stArg, stCmd);
	if(bResult)
	{
		// Send command...
		int nWritten = Write (stCmd.m_Request, stCmd.m_dwRequestLen);
		//if( nWritten != stCmd.m_dwRequestLen)
		//	bResult = FALSE;
	}

	// Wait response...
		

	// Parse command...
	if(bResult)
		bResult = m_CommandEthernet.DemuxCommand(stArg, stCmd);

	::LeaveCriticalSection(&m_CriticalSection);

	return bResult;
}


BOOL CEthernetClient::GetWidth(DWORD* pdwValue)
{
	if(NULL==pdwValue)
		return FALSE;
	
	// Compose command..
	INFO_ARGUMENT stArg;
	m_CommandEthernet.MakeArgument(stArg, TYPE_ARGUMENT_WIDTH, TYPE_OPCODE_READ, NULL, 0, pdwValue, sizeof(DWORD));

	BOOL bResult = SendCommand(stArg);
	return bResult;
}

BOOL CEthernetClient::GetHeight(DWORD* pdwValue)
{
	if(NULL==pdwValue)
		return FALSE;

	// Compose command..
	INFO_ARGUMENT stArg;
	m_CommandEthernet.MakeArgument(stArg, TYPE_ARGUMENT_HEIGHT, TYPE_OPCODE_READ, NULL, 0, pdwValue, sizeof(DWORD));

	BOOL bResult = SendCommand(stArg);
	return bResult;
}

BOOL CEthernetClient::GetMaxWidth(DWORD* pdwValue)
{
	if(NULL==pdwValue)
		return FALSE;
	
	// Compose command..
	INFO_ARGUMENT stArg;
	m_CommandEthernet.MakeArgument(stArg, TYPE_ARGUMENT_MAX_WIDTH, TYPE_OPCODE_READ, NULL, 0, pdwValue, sizeof(DWORD));
	
	BOOL bResult = SendCommand(stArg);
	return bResult;
}

BOOL CEthernetClient::GetMaxHeight(DWORD* pdwValue)
{
	if(NULL==pdwValue)
		return FALSE;
	
	// Compose command..
	INFO_ARGUMENT stArg;
	m_CommandEthernet.MakeArgument(stArg, TYPE_ARGUMENT_MAX_HEIGHT, TYPE_OPCODE_READ, NULL, 0, pdwValue, sizeof(DWORD));

	BOOL bResult = SendCommand(stArg);
	return bResult;
}

BOOL CEthernetClient::GetPixelFormat(DWORD* pdwValue)
{
	if(NULL==pdwValue)
		return FALSE;
	
	// Compose command..
	INFO_ARGUMENT stArg;
	m_CommandEthernet.MakeArgument(stArg, TYPE_ARGUMENT_PIXEL_FORMAT, TYPE_OPCODE_READ, NULL, 0, pdwValue, sizeof(DWORD));

	BOOL bResult = SendCommand(stArg);
	return bResult;
}