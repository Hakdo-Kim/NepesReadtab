#ifndef __SERIAL_LISTENER_H__
#define __SERIAL_LISTENER_H__

#include "SerialCtrl.h"

#define WM_NOTIFY_SERIAL_INPUT			(WM_USER+0x10)


class CSerialListener : public CSerialCtrl
{
public :
	CSerialListener();
	~CSerialListener();

	BOOL StartListener(LPCTSTR lpszDevice, DWORD dwBaudrate, DWORD dwId = 0, HWND hWnd = NULL);
	void StopListener();

	void SetMessageWindow(HWND hWnd);
	
	const TCHAR* GetInputString();
	void ResetInputString();

	BOOL IsConnected();

protected:
	static DWORD WINAPI ThreadProc(LPVOID lpArg);
	DWORD ThreadProc(void);

protected:
	BOOL	m_bConnected;

	DWORD	m_dwListenerId;

	HANDLE	m_hThread;
	DWORD	m_dwThreadId;
	HANDLE	m_hEvent;
	BOOL	m_bStop;

	EEVENT	m_eEvent;

	HWND	m_hWnd;

	TCHAR	m_szReadBuffer[MAX_PATH];

};



#endif