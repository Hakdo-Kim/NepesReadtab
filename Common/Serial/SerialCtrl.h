#pragma once

#include "Common.h"
#include "Serial.h"

class CSerialCtrl
{
public:
	CSerialCtrl();
	virtual ~CSerialCtrl();
	
	static BOOL CheckPort(LPCTSTR pszCom);

	BOOL Open(LPCTSTR lpszDevice, DWORD dwBaudrate);
	void Close();

	BOOL Send(BYTE* pInput, DWORD dwInputLen, BYTE* pOutput = NULL, DWORD* pdwOutputLen = NULL, const BOOL bWaitRespose = FALSE, DWORD dwWaitTime=0);

	BOOL Read(void* pData, DWORD dwLen, DWORD* pdwRead = 0);
	BOOL Write(void* pData, DWORD dwLen, DWORD* pdwWrite = 0);

	HANDLE GetSerialHandle();

	BOOL IsOpen();

	
	const TCHAR* GetDeviceName();
	const DWORD GetDeviceSpeed();

protected:
	CSerial m_Serial;

	TCHAR m_szDevice[128];
	DWORD m_dwBaudrate;

#ifdef DEF_DUMP_SERIAL_MESSAGE
	HANDLE m_hDumpFile;
#endif
};
