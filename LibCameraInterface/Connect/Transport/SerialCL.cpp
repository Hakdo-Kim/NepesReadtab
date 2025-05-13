#include "stdafx.h"
#include "SerialCL.h"

#include "Util/Util.h"

#define CLSERIAL_DLL_MODULE				_T("clallserial.dll")
#define CLSERIAL64BIT_DLL_MODULE		_T("clallserial_x64.dll")



CSerialCL::CSerialCL()
{
	m_hDllInstance			= NULL;

	m_hSerialCL				= NULL;

	pclFlushPort			= NULL;
	pclGetErrorText			= NULL;
	pclGetNumPorts			= NULL;
	pclGetNumBytesAvail		= NULL;
	pclGetPortInfo			= NULL;
	pclGetSupportedBaudRates= NULL;
	pclSerialClose			= NULL;
	pclSerialInit			= NULL;
	pclSerialRead			= NULL;
	pclSerialWrite			= NULL;
	pclSetBaudRate			= NULL;
}

CSerialCL::~CSerialCL()
{
	;
}


BOOL CSerialCL::Init()
{
	BOOL bResult = FALSE;

	TCHAR szLocation[MAX_PATH] = {0,};
	CUtil::GetCurrentDirectory(szLocation, MAX_PATH);

	TCHAR szDllPath[MAX_PATH] = {0,};

#ifdef _WIN64
	CUtil::StringFormat(szDllPath, MAX_PATH, _T("%s\\%s"), szLocation, CLSERIAL64BIT_DLL_MODULE);
#else
	CUtil::StringFormat(szDllPath, MAX_PATH, _T("%s\\%s"), szLocation, CLSERIAL_DLL_MODULE);
#endif

	m_hDllInstance = ::LoadLibrary(szDllPath);

	if(m_hDllInstance)
	{
		pclFlushPort			= (INT32 (*)(hSerRef serialRef))::GetProcAddress(m_hDllInstance, "clFlushPort");
		pclGetErrorText			= (INT32 (*)(const INT8* manuName, INT32 errorCode, INT8* errorText, UINT32* errorTextSize))::GetProcAddress(m_hDllInstance, "clGetErrorText");
		pclGetNumPorts			= (INT32 (*)(UINT32* Ports))::GetProcAddress(m_hDllInstance, "clGetNumPorts");
		pclGetNumBytesAvail		= (INT32 (*)(hSerRef serialRef, UINT32* numBytes))::GetProcAddress(m_hDllInstance, "clGetNumBytesAvail");
		pclGetPortInfo			= (INT32 (*)(UINT32 serialIndex, INT8* manufacturerName, UINT32* nameBytes, INT8* portID, UINT32* IDBytes, UINT32* version))::GetProcAddress(m_hDllInstance, "clGetPortInfo");
		pclGetSupportedBaudRates= (INT32 (*)(hSerRef serialRef, UINT32* baudRates))::GetProcAddress(m_hDllInstance, "clGetSupportedBaudRates");
		pclSerialClose			= (void  (*)(hSerRef serialRef))::GetProcAddress(m_hDllInstance, "clSerialClose");
		pclSerialInit			= (INT32 (*)(UINT32 serialIndex, hSerRef* serialRefPtr))::GetProcAddress(m_hDllInstance, "clSerialInit");
		pclSerialRead			= (INT32 (*)(hSerRef serialRef, INT8* buffer, UINT32* bufferSize, UINT32 serialTimeout))::GetProcAddress(m_hDllInstance, "clSerialRead");
		pclSerialWrite			= (INT32 (*)(hSerRef serialRef, INT8* buffer, UINT32* bufferSize, UINT32 serialTimeout))::GetProcAddress(m_hDllInstance, "clSerialWrite");
		pclSetBaudRate			= (INT32 (*)(hSerRef serialRef, UINT32 baudRate))::GetProcAddress(m_hDllInstance, "clSetBaudRate");

		if( NULL==pclFlushPort || NULL==pclGetErrorText || NULL==pclGetNumPorts ||
			NULL==pclGetNumBytesAvail || NULL==pclGetPortInfo || NULL==pclGetSupportedBaudRates ||
			NULL==pclSerialClose || NULL==pclSerialInit || NULL==pclSerialRead || 
			NULL==pclSerialWrite || NULL==pclSetBaudRate)
		{
			bResult = FALSE;
		}
		else
		{
			bResult = TRUE;
		}
	}
	
	return bResult;
}

void CSerialCL::Deinit()
{
	if(m_hDllInstance)
	{
		pclFlushPort = NULL;
		pclGetErrorText = NULL;
		pclGetNumPorts = NULL;
		pclGetNumBytesAvail = NULL;
		pclGetPortInfo = NULL;
		pclGetSupportedBaudRates = NULL;
		pclSerialClose = NULL;
		pclSerialInit = NULL;
		pclSerialRead = NULL;
		pclSerialWrite = NULL;
		pclSetBaudRate = NULL;
	
		::FreeLibrary(m_hDllInstance);
		m_hDllInstance = NULL;
	}
}


INT32 CSerialCL::FlushPort(hSerRef serialRef)
{
	if (NULL==m_hDllInstance || NULL==pclFlushPort)
		return CL_ERR_FUNCTION_NOT_FOUND;

	return (*pclFlushPort)(serialRef);
}

INT32 CSerialCL::GetErrorText(const INT8* manuName, INT32 errorCode, INT8* errorText, UINT32* errorTextSize)
{
	if (NULL==m_hDllInstance || NULL==pclGetErrorText)
		return CL_ERR_FUNCTION_NOT_FOUND;

	return (*pclGetErrorText)(manuName, errorCode, errorText, errorTextSize);
}

INT32 CSerialCL::GetNumPorts(UINT32* Ports)
{
	if (NULL==m_hDllInstance || NULL==pclGetNumPorts)
		return CL_ERR_FUNCTION_NOT_FOUND;

	return (*pclGetNumPorts)(Ports);
}

INT32 CSerialCL::GetNumBytesAvail(hSerRef serialRef, UINT32* numBytes)
{
	if (NULL==m_hDllInstance || NULL==pclGetNumBytesAvail)
		return CL_ERR_FUNCTION_NOT_FOUND;

	return (*pclGetNumBytesAvail)(serialRef, numBytes);
}

INT32 CSerialCL::GetPortInfo(UINT32 serialIndex, INT8* manufacturerName, UINT32* nameBytes, INT8* portID, UINT32* IDBytes, UINT32* version)
{
	if (NULL==m_hDllInstance || NULL==pclGetPortInfo)
		return CL_ERR_FUNCTION_NOT_FOUND;

	return (*pclGetPortInfo)(serialIndex, manufacturerName, nameBytes, portID, IDBytes, version);
}

INT32 CSerialCL::GetSupportedBaudRates(hSerRef serialRef, UINT32* baudRates)
{
	if (NULL==m_hDllInstance || NULL==pclGetSupportedBaudRates)
		return CL_ERR_FUNCTION_NOT_FOUND;

	return (*pclGetSupportedBaudRates)(serialRef, baudRates);
}

void  CSerialCL::SerialClose(hSerRef serialRef)
{
	if (NULL==m_hDllInstance || NULL==pclSerialClose)
		return;

	(*pclSerialClose)(serialRef);
}

INT32 CSerialCL::SerialInit(UINT32 serialIndex, hSerRef* serialRefPtr)
{
	if (NULL==m_hDllInstance || NULL==pclSerialInit)
		return CL_ERR_FUNCTION_NOT_FOUND;

	return (*pclSerialInit)(serialIndex, serialRefPtr);
}

INT32 CSerialCL::SerialRead(hSerRef serialRef, INT8* buffer, UINT32* bufferSize, UINT32 serialTimeout)
{
	if (NULL==m_hDllInstance || NULL==pclSerialRead)
		return CL_ERR_FUNCTION_NOT_FOUND;

	return (*pclSerialRead)(serialRef, buffer, bufferSize, serialTimeout);
}

INT32 CSerialCL::SerialWrite(hSerRef serialRef, INT8* buffer, UINT32* bufferSize, UINT32 serialTimeout)
{
	if (NULL==m_hDllInstance || NULL==pclSerialWrite)
		return CL_ERR_FUNCTION_NOT_FOUND;

	return (*pclSerialWrite)(serialRef, buffer, bufferSize, serialTimeout);
}

INT32 CSerialCL::SetBaudRate(hSerRef serialRef, UINT32 baudRate)
{
	if (NULL==m_hDllInstance || NULL==pclSetBaudRate)
		return CL_ERR_FUNCTION_NOT_FOUND;

	return (*pclSetBaudRate)(serialRef, baudRate);
}


BOOL CSerialCL::IsOpen()
{
	BOOL bOpen = FALSE;

	if(m_hDllInstance && m_hSerialCL )
		bOpen = TRUE;

	return bOpen;
}

const int CSerialCL::GetIndex(LPCTSTR lpszDevice)
{
	int nIdx = -1;

	if(NULL==lpszDevice)
		return nIdx;

	int nPos = 0;
	BOOL bResult = CUtil::StringSearch((LPTSTR)lpszDevice, STR_CAMERALINK, &nPos);
	if(bResult)
	{
		int pos = nPos+CUtil::StringLength(STR_CAMERALINK);

		nIdx = CUtil::StringToInt( (LPTSTR)(lpszDevice+pos), 
			CUtil::StringLength((LPTSTR)lpszDevice)-pos) -1;
	}

	return nIdx;

}



BOOL CSerialCL::CheckPort(LPCTSTR pszCom)
{
	BOOL bResult = FALSE;

	return bResult;
}

int CSerialCL::SearchSerialPort(SERIALPORT_INFO* pstInfo, const int nLen)
{
	int nCount = 0;

	UINT32 nPorts = 0;

	INT32 nResult = GetNumPorts(&nPorts); 
	if(CL_ERR_NO_ERR==nResult)
	{
		nCount = nPorts;
	}

	if(pstInfo && 0<nLen)
	{
		for(int i=0; i<nCount; i++)
		{
			if(i>=nLen)
				break;

			CUtil::StringFormat(pstInfo[i].m_szPortName, MAX_SERIALNAME_LEN, _T("%s %d"), STR_CAMERALINK,  i+1);
		}
	}



	return nCount;
}


BOOL CSerialCL::Open(LPCTSTR lpszDevice, DWORD dwBaudrate)
{
	if(NULL==lpszDevice)
		return FALSE;

	UINT32 nSpeed = CL_BAUDRATE_115200;

	if(9600==dwBaudrate)			nSpeed = CL_BAUDRATE_9600;
	else if(19200==dwBaudrate)		nSpeed = CL_BAUDRATE_19200;
	else if(38400==dwBaudrate)		nSpeed = CL_BAUDRATE_38400;
	else if(57600==dwBaudrate)		nSpeed = CL_BAUDRATE_57600;
	else if(115200==dwBaudrate)		nSpeed = CL_BAUDRATE_115200;
	else if(230400==dwBaudrate)		nSpeed = CL_BAUDRATE_230400;
	else if(460800==dwBaudrate)		nSpeed = CL_BAUDRATE_460800;
	else if(921600==dwBaudrate)		nSpeed = CL_BAUDRATE_921600;
	else return FALSE;

	const int nIdx = GetIndex(lpszDevice);

	if(0<=nIdx)
	{
		this->Close();

		INT32 nResult = SerialInit(nIdx, &m_hSerialCL);
		if(CL_ERR_NO_ERR!=nResult)
			return FALSE;

		nResult = SetBaudRate(m_hSerialCL, nSpeed);
		if(CL_ERR_NO_ERR!=nResult)
		{
			this->Close();
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}


	return TRUE;
}

void CSerialCL::Close()
{
	if(m_hSerialCL)
		SerialClose(m_hSerialCL);

	m_hSerialCL = NULL;
}


BOOL CSerialCL::Write (const void* pData, DWORD dwLen, DWORD* pdwWritten, DWORD dwTimeout)
{
	if(FALSE==IsOpen())
		return FALSE;

	BOOL bResult = FALSE;

	INT32 nResult = SerialWrite(m_hSerialCL, (INT8*)pData, (UINT32*) &dwLen, dwTimeout);

	if(CL_ERR_NO_ERR==nResult)
	{
		if(pdwWritten)
			*pdwWritten = dwLen;

		bResult = TRUE;
	}

	return bResult;
}

BOOL CSerialCL::Read (void* pData, DWORD dwLen, DWORD* pdwRead, DWORD dwTimeout)
{
	if(FALSE==IsOpen())
		return FALSE;

	BOOL bResult = FALSE;

	INT32 nResult = SerialRead(m_hSerialCL, (INT8*)pData, (UINT32*) &dwLen, dwTimeout);

	if(CL_ERR_NO_ERR==nResult || -20==nResult)
	{
		if(pdwRead)
			*pdwRead = dwLen;

		bResult = TRUE;
	}

	return bResult;



}

BOOL CSerialCL::Flush ()
{
	if(FALSE==IsOpen())
		return FALSE;

	BOOL bResult = FALSE;

	INT32 nResult = FlushPort(m_hSerialCL);

	if(CL_ERR_NO_ERR==nResult)
	{
		bResult = TRUE;
	}

	return bResult;
}
