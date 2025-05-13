#include "stdafx.h"
#include "Ethernet.h"

CEthernet::CEthernet()
{
	/// Startup socket
	WSADATA stWsaData;
	int nRes = ::WSAStartup(MAKEWORD(2, 2), &stWsaData);
	if (0 == nRes)
	{
		if (2 != LOBYTE(stWsaData.wVersion) || 2 != HIBYTE(stWsaData.wVersion))
		{
			::WSACleanup();
		}
	}
	//*/


	m_bOpen = FALSE;

	m_hThread = NULL;
	m_dwThreadId = -1;
	m_hEvent = NULL;
	m_bStop = TRUE;

	m_bSkipThreadRead = FALSE;

	//
	memset(m_szIpAddr, 0x00, sizeof(TCHAR)*MAX_NAME_LEN);
	memset(m_szPort, 0x00, sizeof(TCHAR)*MAX_NAME_LEN);
	memset(m_szProtocol, 0x00, sizeof(TCHAR)*MAX_NAME_LEN);
}

CEthernet::~CEthernet()
{
	// Cleanup socket
	::WSACleanup();
}

const TCHAR* CEthernet::GetInputString()
{
	return m_szReadBuffer;
}

void CEthernet::ResetInputString()
{
	memset(m_szReadBuffer, 0x00, MAX_PATH);
}

const TCHAR* CEthernet::GetIpAddress()
{
	return m_szIpAddr;
}

const TCHAR* CEthernet::GetPort()
{
	return m_szPort;
}

const TCHAR* CEthernet::GetProtocol()
{
	return m_szProtocol;
}
