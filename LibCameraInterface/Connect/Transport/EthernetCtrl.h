#pragma once

#include "CameraInterfaceDef.h"

#include "EthernetServer.h"
#include "EthernetClient.h"
#include "../Command/CommandEthernet.h"

#include <vector>

class CEthernetCtrl
{
public:
	CEthernetCtrl();
	virtual ~CEthernetCtrl();

	BOOL Open();
	void Close();

	BOOL IsOpen();

	BOOL FindAllDevice();
	
	const int GetEnableInterfaceCount();

	const int GetEnableDeviceCount();
	const INFO_CLIENT* GetDeviceModuleInfo(const int nIdx);

	BOOL GetEnableDeviceInfo(int nIdx, INFO_CONNECT_ETHERNET* pstDevice);


	BOOL GetWidth(const int nIdx, DWORD* pdwValue);
	BOOL GetHeight(const int nIdx, DWORD* pdwValue);
	BOOL GetMaxWidth(const int nIdx, DWORD* pdwValue);
	BOOL GetMaxHeight(const int nIdx, DWORD* pdwValue);
	BOOL GetPixelFormat(const int nIdx, DWORD* pdwValue);



protected:

	CCommandEthernet m_CommandEthernet;

	// Ethernet Interface
	std::vector<INFO_ETHERNET_ADAPTOR*> m_AdapterList;

	int  SearchEthernetInterface();
	BOOL IsExistEthernetInterface(const INFO_ETHERNET_ADAPTOR* pstEthernet);
	BOOL AddEthernetInterface(const INFO_ETHERNET_ADAPTOR* pstEthernet);


	// Server
	CEthernetServer	m_Server;

	BOOL StartServer();


	// Client
	std::vector<CEthernetClient*> m_DeviceList;		// Broadcast socket device

	BOOL IsExistClient(LPCTSTR pszAddress, TYPE_PROTOCOL eProtocol);
	BOOL AddClient(LPCTSTR pszAddress, DWORD dwPort, TYPE_PROTOCOL eProtocol);

	

};