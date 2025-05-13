#pragma once

#include "CameraInterfaceDef.h"

#include "../Command/DefineCommand.h"
#include "../Command/CommandEthernet.h"

class CEthernetClient
{
public:
	CEthernetClient(void);
	virtual ~CEthernetClient(void);

protected:

	CCommandEthernet m_CommandEthernet;

	SOCKET	m_hSocketClient;
	HANDLE	m_hThreadClient;
	BOOL	m_bStopClient;
	HANDLE	m_hEventClient;
	
	HANDLE				m_hEventClientStop;
	CRITICAL_SECTION	m_CriticalSection;

	BOOL m_bBroadCastClient;


	static DWORD WINAPI ThreadClientProc(LPVOID lpArg);
	DWORD ThreadClientProc(void);


	// Client Information
	TCHAR	m_szIpAddress[MAX_NAME_LEN];
	DWORD	m_dwPort;
	TYPE_PROTOCOL m_eProtocol;


public:

	BOOL IsOpen ();
	BOOL GetClientInfo(TCHAR* pszIpAddr, DWORD* pdwPort, TYPE_PROTOCOL* peProtocol);
	
	const TYPE_PROTOCOL GetProtocolType();


	BOOL Open (LPCTSTR pszAddress, DWORD dwPort, TYPE_PROTOCOL eProtocol = TYPE_PROTOCOL_UDP);
	BOOL Open (SOCKET hSocket, HANDLE hEvent, DWORD dwIpAddress, DWORD dwPort);
	BOOL OpenBroadCastClient(LPCTSTR pszAddress, DWORD dwPort);
	void Close ();

	BOOL SendBroadcastPacket (const INFO_COMMAND* pstCmd);


	BOOL GetWidth(DWORD* pdwValue);
	BOOL GetHeight(DWORD* pdwValue);
	BOOL GetMaxWidth(DWORD* pdwValue);
	BOOL GetMaxHeight(DWORD* pdwValue);
	BOOL GetPixelFormat(DWORD* pdwValue);

protected:

	BOOL SendCommand(INFO_ARGUMENT& stArg);



	int Write (BYTE* pBuf, DWORD dwLen);
	int Read (BYTE* pBuf, DWORD dwLen);



};
