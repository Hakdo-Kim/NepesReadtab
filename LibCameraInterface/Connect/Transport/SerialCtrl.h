#pragma once

#include "Serial.h"

class CSerialCtrl
{
public:
	CSerialCtrl();
	virtual ~CSerialCtrl();
	
	static BOOL CheckPort(LPCTSTR pszCom);
	static int SearchSerialPort(SERIALPORT_INFO* pstInfo, const int nLen);

	BOOL Open(LPCTSTR lpszDevice, DWORD dwBaudrate);
	void Close();

	BOOL Send(BYTE* pInput, DWORD dwInputLen, BYTE* pOutput = NULL, DWORD* pdwOutputLen = NULL, const BOOL bWaitRespose = FALSE, DWORD dwWaitTime=0);

	BOOL Read(void* pData, DWORD dwLen, DWORD* pdwRead = 0);
	BOOL Write(void* pData, DWORD dwLen, DWORD* pdwWrite = 0);

	HANDLE GetSerialHandle();

	BOOL IsOpen();

protected:

	CSerial m_Serial;

};
