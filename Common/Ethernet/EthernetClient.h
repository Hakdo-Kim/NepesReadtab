#pragma once
#include "Ethernet.h"

class CEthernetClient : public CEthernet
{
public:
	CEthernetClient();
	virtual ~CEthernetClient();

	virtual BOOL IsOpen();
	virtual BOOL Open(const TCHAR* pszIpAddr, const TCHAR* pszPort, const TCHAR* pszProtocol, FuncNotifyEthernetListener Func = NULL, void* pArg = NULL);
	virtual BOOL Open(SOCKET hSocket, HANDLE hEvent, DWORD dwIpAddress, DWORD dwPort, const TCHAR* pszProtocol, FuncNotifyEthernetListener Func = NULL, void* pArg = NULL);
	virtual void Close();

	virtual BOOL SendCommand(const void* pCmdBuf, const DWORD dwCmdLen, void* pResBuf, int& nResLen);

	virtual BOOL Read(void* pData, DWORD dwLen, int* pnRead = 0);
	virtual BOOL Write(void* pData, DWORD dwLen, int* pnWrite = 0);

protected:
	CRITICAL_SECTION m_CriticalSection;

	SOCKET	m_hSocket;
	HANDLE	m_hSocketEvent;

	const int TIMEOUT = 5000;

	static DWORD WINAPI ThreadProc(LPVOID lpArg);
	DWORD ThreadProc(void);

#ifdef DEF_DUMP_ETHERNET_PACKET
	HANDLE m_hDumpFile;
#endif
};

