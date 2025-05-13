#include "stdafx.h"
#include "SerialCtrl.h"

#include "Util/Util.h"


CSerialCtrl::CSerialCtrl()
{
}

CSerialCtrl::~CSerialCtrl()
{
	;
}

BOOL CSerialCtrl::CheckPort(LPCTSTR pszCom)
{
	return CSerial::CheckPort(pszCom);
}

int CSerialCtrl::SearchSerialPort(SERIALPORT_INFO* pstInfo, const int nLen)
{
	return CSerial::SearchSerialPort(pstInfo, nLen);
}

HANDLE CSerialCtrl::GetSerialHandle()
{
	return m_Serial.GetHandle();
}

BOOL CSerialCtrl::IsOpen()
{
	return m_Serial.IsOpen();
}


BOOL CSerialCtrl::Open(LPCTSTR lpszDevice, DWORD dwBaudrate)
{
	BOOL bResult = FALSE;

	if(NULL==lpszDevice)
		return bResult;

	if(m_Serial.IsOpen())
		m_Serial.Close();

	DWORD dwResult = m_Serial.Open(lpszDevice);

	//if(SUCCEEDED(dwResult))
	if(ERROR_SUCCESS==dwResult)
	{
		EBAUDRATE eSpeed = EBAUDRATE_UNKNOWN;

		if(110==dwBaudrate)				eSpeed = EBAUDRATE_110;
		else if(300==dwBaudrate)		eSpeed = EBAUDRATE_300;
		else if(600==dwBaudrate)		eSpeed = EBAUDRATE_600;
		else if(1200==dwBaudrate)		eSpeed = EBAUDRATE_1200;
		else if(2400==dwBaudrate)		eSpeed = EBAUDRATE_2400;
		else if(4800==dwBaudrate)		eSpeed = EBAUDRATE_4800;
		else if(9600==dwBaudrate)		eSpeed = EBAUDRATE_9600;
		else if(14400==dwBaudrate)		eSpeed = EBAUDRATE_14400;
		else if(19200==dwBaudrate)		eSpeed = EBAUDRATE_19200;
		else if(38400==dwBaudrate)		eSpeed = EBAUDRATE_38400;
		else if(56000==dwBaudrate)		eSpeed = EBAUDRATE_56000;
		else if(57600==dwBaudrate)		eSpeed = EBAUDRATE_57600;
		else if(115200==dwBaudrate)		eSpeed = EBAUDRATE_115200;
		else if(128000==dwBaudrate)		eSpeed = EBAUDRATE_128000;
		else if(256000==dwBaudrate)		eSpeed = EBAUDRATE_256000;
		else	return FALSE;
	
		dwResult = m_Serial.Set(eSpeed);
	}

	//if(SUCCEEDED(dwResult))
	if(ERROR_SUCCESS==dwResult)
	{
		bResult = TRUE;
	}
	else
	{
		m_Serial.Close();
	}

	return bResult;	
}

void CSerialCtrl::Close()
{
	m_Serial.Close();
}

BOOL CSerialCtrl::Send(BYTE* pInput, DWORD dwInputLen, BYTE* pOutput, DWORD* pdwOutputLen, const BOOL bWaitRespose, DWORD dwWaitTime)
{
	DWORD dwLen = 0;
	DWORD dwResult = FALSE;

	if(0<dwInputLen)
	{
		dwResult = m_Serial.Write(pInput, dwInputLen, &dwLen);
		if(FAILED(dwResult))
			return FALSE;
	}

	if(dwWaitTime>0)
		CUtil::Sleep(dwWaitTime);


	if(0<*pdwOutputLen)
	{
		dwResult = m_Serial.Read(pOutput, *pdwOutputLen, &dwLen);
		if (FAILED(dwResult))
			return FALSE;

		*pdwOutputLen = dwLen;
	}

	return TRUE;
}

BOOL CSerialCtrl::Read(void* pData, DWORD dwLen, DWORD* pdwRead)
{
	DWORD dwReaded = 0;
	DWORD dwResult = FALSE;

	dwResult = m_Serial.Read(pData, dwLen, &dwReaded);
	if (FAILED(dwResult))
		return FALSE;
	
	if (pdwRead)
		*pdwRead = dwReaded;

	return TRUE;
}


BOOL CSerialCtrl::Write(void* pData, DWORD dwLen, DWORD* pdwWrite)
{
	DWORD dwWritten = 0;
	DWORD dwResult = FALSE;

	dwResult = m_Serial.Write(pData, dwLen, &dwWritten);
	if (FAILED(dwResult))
		return FALSE;
	
	if (pdwWrite)
		*pdwWrite = dwWritten;

	return TRUE;
}