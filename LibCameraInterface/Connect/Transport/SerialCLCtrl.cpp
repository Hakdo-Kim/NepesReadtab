#include "stdafx.h"
#include "SerialCLCtrl.h"

#include "Util/Util.h"

CSerialCLCtrl::CSerialCLCtrl()
{
	m_SerialCL.Init();
}

CSerialCLCtrl::~CSerialCLCtrl()
{
	m_SerialCL.Deinit();
}


BOOL CSerialCLCtrl::CheckPort(LPCTSTR pszCom)
{
	BOOL bResult = m_SerialCL.CheckPort(pszCom);

	return bResult;
}

int CSerialCLCtrl::SearchSerialPort(SERIALPORT_INFO* pstInfo, const int nLen)
{
	int nCount = m_SerialCL.SearchSerialPort(pstInfo, nLen);

	return nCount;
}

BOOL CSerialCLCtrl::Open(LPCTSTR lpszDevice, DWORD dwBaudrate)
{
	BOOL bResult = m_SerialCL.Open(lpszDevice, dwBaudrate);

	return bResult;
}

void CSerialCLCtrl::Close()
{
	m_SerialCL.Close();
}

BOOL CSerialCLCtrl::Send(BYTE* pInput, DWORD dwInputLen, BYTE* pOutput, DWORD* pdwOutputLen, const BOOL bNoRespose, DWORD dwWaitTime)
{
	DWORD dwLen = 0;
	BOOL bResult = FALSE;

	if(0<dwInputLen)
	{
		bResult = m_SerialCL.Flush();

		bResult = m_SerialCL.Write(pInput, dwInputLen);
		if(FALSE==bResult)
			return FALSE;
	}

	CUtil::Sleep(DEFAULT_SLEEP_CAMERALINK);
	if(0<dwWaitTime)
		CUtil::Sleep(dwWaitTime);

	if(0<*pdwOutputLen && FALSE==bNoRespose)
	{
		bResult = m_SerialCL.Read(pOutput, *pdwOutputLen, &dwLen);
		if(FALSE==bResult)
			return FALSE;

		*pdwOutputLen = dwLen;
	}

	return TRUE;
}


BOOL CSerialCLCtrl::Read(void* pData, DWORD dwLen, DWORD* pdwRead)
{
	DWORD dwReaded = 0;
	BOOL bResult = FALSE;

	bResult = m_SerialCL.Read(pData, dwLen, &dwReaded);
	if( bResult && pdwRead )
		*pdwRead = dwReaded;	

	return bResult;
}

BOOL CSerialCLCtrl::Write(void* pData, DWORD dwLen, DWORD* pdwWrite)
{
	BOOL bResult = FALSE;

	bResult = m_SerialCL.Write(pData, dwLen);
	if( bResult && pdwWrite )
		*pdwWrite = dwLen;

	return bResult;
}

HANDLE CSerialCLCtrl::GetSerialHandle()
{
	return NULL;
}

BOOL CSerialCLCtrl::IsOpen()
{
	return m_SerialCL.IsOpen();
}
