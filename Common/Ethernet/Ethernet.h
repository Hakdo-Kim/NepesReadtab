#pragma once
#include "afxwin.h"
#include "Common.h"
#include "EthernetDef.h"


class CEthernet
{
public:
	CEthernet();
	virtual ~CEthernet();

	//
	virtual BOOL IsOpen() = 0;
	virtual BOOL Open(const TCHAR* pszIpAddr, const TCHAR* pszPort, const TCHAR* pszProtocol, FuncNotifyEthernetListener Func = NULL, void* pArg = NULL) = 0;
	virtual void Close() = 0;


	const TCHAR* GetInputString();
	void ResetInputString();

	const TCHAR* GetIpAddress();
	const TCHAR* GetPort();
	const TCHAR* GetProtocol();


protected:
	BOOL	m_bOpen;

	HANDLE	m_hThread;
	DWORD	m_dwThreadId;
	HANDLE	m_hEvent;
	BOOL	m_bStop;

	FuncNotifyEthernetListener m_FuncNotify;
	void*	m_pArg;

	TCHAR	m_szReadBuffer[MAX_PATH];
	BOOL	m_bSkipThreadRead;


	//
	TCHAR m_szIpAddr[MAX_NAME_LEN];
	TCHAR m_szPort[MAX_NAME_LEN];
	TCHAR m_szProtocol[MAX_NAME_LEN];

};
