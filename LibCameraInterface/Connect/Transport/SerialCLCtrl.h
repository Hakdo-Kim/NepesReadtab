#ifndef __SERIAL_CAMERALINK_CONTROL_H__
#define __SERIAL_CAMERALINK_CONTROL_H__


#include "SerialCL.h"


class CSerialCLCtrl
{
public:
	CSerialCLCtrl();
	virtual ~CSerialCLCtrl();

	BOOL CheckPort(LPCTSTR pszCom);
	int SearchSerialPort(SERIALPORT_INFO* pstInfo, const int nLen);

	BOOL Open(LPCTSTR lpszDevice, DWORD dwBaudrate);
	void Close();

	BOOL Send(BYTE* pInput, DWORD dwInputLen, BYTE* pOutput = NULL, DWORD* pdwOutputLen = NULL, const BOOL bNoRespose = FALSE, DWORD dwWaitTime = 0);

	BOOL Read(void* pData, DWORD dwLen, DWORD* pdwRead = 0);
	BOOL Write(void* pData, DWORD dwLen, DWORD* pdwWrite = 0);

	HANDLE GetSerialHandle();

	BOOL IsOpen();



protected:
	CSerialCL	m_SerialCL;

};




#endif