#ifndef __SERIAL_CAMERALINK_H__
#define __SERIAL_CAMERALINK_H__

#include "SerialDef.h"
#include "inc/clallserial.h"

class CSerialCL
{
public:
	CSerialCL();
	virtual ~CSerialCL();

	BOOL Init();
	void Deinit();

	
	BOOL CheckPort(LPCTSTR pszCom);
	int SearchSerialPort(SERIALPORT_INFO* pstInfo, const int nLen);

	

	BOOL IsOpen();

	BOOL Open(LPCTSTR lpszDevice, DWORD dwBaudrate);
	void Close();

	BOOL Write (const void* pData, DWORD dwLen, DWORD* pdwWritten = 0, DWORD dwTimeout = DEFAULT_TIMEOUT_CAMERALINK);
	BOOL Read (void* pData, DWORD dwLen, DWORD* pdwRead = 0, DWORD dwTimeout = DEFAULT_TIMEOUT_CAMERALINK);

	BOOL Flush ();


protected:

	HINSTANCE	m_hDllInstance;
	hSerRef		m_hSerialCL;

	INT32 FlushPort(hSerRef serialRef);
	INT32 GetErrorText(const INT8* manuName, INT32 errorCode, INT8* errorText, UINT32* errorTextSize);
	INT32 GetNumPorts(UINT32* Ports); 
	INT32 GetNumBytesAvail(hSerRef serialRef, UINT32* numBytes);
	INT32 GetPortInfo(UINT32 serialIndex, INT8* manufacturerName, UINT32* nameBytes, INT8* portID, UINT32* IDBytes, UINT32* version);
	INT32 GetSupportedBaudRates(hSerRef serialRef, UINT32* baudRates);
	
	void  SerialClose(hSerRef serialRef);

	INT32 SerialInit(UINT32 serialIndex, hSerRef* serialRefPtr);
	INT32 SerialRead(hSerRef serialRef, INT8* buffer, UINT32* bufferSize, UINT32 serialTimeout);
	INT32 SerialWrite(hSerRef serialRef, INT8* buffer, UINT32* bufferSize, UINT32 serialTimeout);
	INT32 SetBaudRate(hSerRef serialRef, UINT32 baudRate);


	INT32 (*pclFlushPort)(hSerRef serialRef);
	INT32 (*pclGetErrorText)(const INT8* manuName, INT32 errorCode, INT8* errorText, UINT32* errorTextSize);
	INT32 (*pclGetNumPorts)(UINT32* Ports); 
	INT32 (*pclGetNumBytesAvail)(hSerRef serialRef, UINT32* numBytes);
	INT32 (*pclGetPortInfo)(UINT32 serialIndex, INT8* manufacturerName, UINT32* nameBytes, INT8* portID, UINT32* IDBytes, UINT32* version);
	INT32 (*pclGetSupportedBaudRates)(hSerRef serialRef, UINT32* baudRates);
	void  (*pclSerialClose)(hSerRef serialRef);
	INT32 (*pclSerialInit)(UINT32 serialIndex, hSerRef* serialRefPtr);
	INT32 (*pclSerialRead)(hSerRef serialRef, INT8* buffer, UINT32* bufferSize, UINT32 serialTimeout);
	INT32 (*pclSerialWrite)(hSerRef serialRef, INT8* buffer, UINT32* bufferSize, UINT32 serialTimeout);
	INT32 (*pclSetBaudRate)(hSerRef serialRef, UINT32 baudRate);

	
	const int GetIndex(LPCTSTR lpszDevice);

	

};




#endif