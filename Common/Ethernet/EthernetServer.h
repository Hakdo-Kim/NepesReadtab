#pragma once
#include "Ethernet.h"
#include "EthernetClient.h"

#include <vector>

class CEthernetServer : public CEthernet
{
public:
	CEthernetServer();
	virtual ~CEthernetServer();

	virtual BOOL IsOpen();
	virtual BOOL Open(const TCHAR* pszIpAddr, const TCHAR* pszPort, const TCHAR* pszProtocol, FuncNotifyEthernetListener Func = NULL, void* pArg = NULL);
	virtual void Close();

	const int GetCountConnectedClinet();
	CEthernetClient* GetConnectedClinet(int nIdx);

	void DeleteClient(CEthernetClient* pClient);

protected:
	SOCKET	m_hSocket;
	HANDLE	m_hSocketEvent;

	std::vector<CEthernetClient*> m_ClientList;




	const int GetConnectedClientCount();

	static int WINAPI AcceptCondition(WSABUF* pk_CallerId,
		WSABUF* pk_CallerData,
		QOS* pk_SQOS,
		QOS* pk_GQOS,
		WSABUF* pk_CalleeId,
		WSABUF* pk_CalleeData,
		UINT* pu32_Group,
		DWORD_PTR p_Param);

	static DWORD WINAPI ThreadProc(LPVOID lpArg);
	DWORD ThreadProc(void);

};

