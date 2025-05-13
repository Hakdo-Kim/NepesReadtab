#pragma once

#include <vector>
#include <hash_map>

#include "EthernetClient.h"

typedef struct
{
	TCHAR	m_szName[MAX_NAME_LEN];

	SOCKET	m_hSocket;
	HANDLE	m_hEvent;

	DWORD	m_dwIpAddress;
	DWORD	m_dwPort;

} INFO_CLIENT;


class CEthernetServer
{
public:
	CEthernetServer(void);
	~CEthernetServer(void);

	BOOL IsOpen ();

	BOOL Open (LPCTSTR pszAddress, DWORD dwPort, TYPE_PROTOCOL eProtocol = TYPE_PROTOCOL_UDP);
	void Close ();

	const int GetConnectedClientCount();
	const INFO_CLIENT* GetConnectedClientInfo(int nIdx);
	
	BOOL GetWidth(const int nIdx, DWORD* pdwValue);
	BOOL GetHeight(const int nIdx, DWORD* pdwValue);
	BOOL GetMaxWidth(const int nIdx, DWORD* pdwValue);
	BOOL GetMaxHeight(const int nIdx, DWORD* pdwValue);
	BOOL GetPixelFormat(const int nIdx, DWORD* pdwValue);




protected:

	SOCKET	m_hSocketListen;
	HANDLE	m_hThreadListen;
	BOOL	m_bStopListen;
	HANDLE	m_hEventListen;

	HANDLE				m_hEventListenStop;
	CRITICAL_SECTION	m_CriticalSection;

	// Client list...
	std::vector<INFO_CLIENT*> m_ClientArray;
	stdext::hash_map<DWORD, CEthernetClient*>	m_ClinetHashMap;	// Connected device; IP/Class Hashmap

	BOOL IsExistClient(const INFO_CLIENT* pstClient);
	BOOL AddClient(const INFO_CLIENT* pstClient);



	// Member Function
	static int WINAPI AcceptCondition(WSABUF* pk_CallerId,
							WSABUF* pk_CallerData,
							QOS* pk_SQOS,
							QOS* pk_GQOS,
							WSABUF* pk_CalleeId,
							WSABUF* pk_CalleeData,
							UINT* pu32_Group,
							DWORD_PTR p_Param);

	static DWORD WINAPI ThreadListenProc(LPVOID lpArg);
	DWORD ThreadListenProc(void);


};
