#include "StdAfx.h"
#include "EthernetCtrl.h"

#include "Connect/Command/DefineEthernet.h"
#include "Util/Util.h"

CEthernetCtrl::CEthernetCtrl()
{
	WSADATA stWsaData;
	int nRes = WSAStartup(MAKEWORD(2, 2), &stWsaData);
	if (0 == nRes)
	{
		if (2 != LOBYTE(stWsaData.wVersion) || 2 != HIBYTE(stWsaData.wVersion))
		{
			WSACleanup();
		}
	}
}

CEthernetCtrl::~CEthernetCtrl()
{
	WSACleanup();
}

BOOL CEthernetCtrl::Open()
{
	if(this->IsOpen())
		Close();

	// Open Server
	if(FALSE==StartServer())
	{
		Close();
		return FALSE;
	}

	return TRUE;
}

void CEthernetCtrl::Close()
{
	m_Server.Close();

	int nCount = m_AdapterList.size();

	for(int i=0; i<nCount; i++)
	{
		INFO_ETHERNET_ADAPTOR* pstInfo = m_AdapterList[i];
		if(pstInfo)
			delete pstInfo;
	}

	nCount = m_DeviceList.size();
	for(int i=0; i<nCount; i++)
	{
		CEthernetClient* pstInfo = m_DeviceList[i];
		if(pstInfo)
			delete pstInfo;
	}

	std::vector<INFO_ETHERNET_ADAPTOR*> aclear;		// vector memory leak 방지.
	m_AdapterList.swap(aclear);
	aclear.clear();
	m_AdapterList.clear();


	std::vector<CEthernetClient*> dclear;		// vector memory leak 방지.
	m_DeviceList.swap(dclear);
	dclear.clear();
	m_DeviceList.clear();
}

BOOL CEthernetCtrl::IsOpen()
{
	BOOL bResult = m_Server.IsOpen();
	return bResult;
}

BOOL CEthernetCtrl::FindAllDevice()
{
	if(FALSE == IsOpen())
		return FALSE;

	// Open Client
	const int nCount = SearchEthernetInterface();
	if(1>nCount)
		return FALSE;

	BOOL bResult = FALSE;

	for(int i=0; i<nCount; i++)
	{
		bResult=IsExistClient(m_AdapterList[i]->m_szIpAddress, TYPE_PROTOCOL_UDP);
		if(bResult)
			continue;
		
		bResult=AddClient(m_AdapterList[i]->m_szIpAddress, ETHERNET_PORT_CONTROL_BASE+i, TYPE_PROTOCOL_UDP);
		if(FALSE==bResult)
		{
			// Check error...
		}
	}

	// Send Broadcast message...
	INFO_ARGUMENT stArg;
	INFO_COMMAND  stCmd;

	m_CommandEthernet.MakeArgument(stArg, TYPE_ARGUMENT_BROADCAST, TYPE_OPCODE_COMMAND, NULL, 0, NULL, 0);
	bResult = m_CommandEthernet.MuxCommand(stArg, stCmd);
	if(bResult)
	{
		const int nClient = m_DeviceList.size();
		for(int i=0; i<nClient; i++)
		{
			m_DeviceList[i]->SendBroadcastPacket(&stCmd);
		}
	}
	else
	{
		return FALSE;
	}

	Sleep(5000);		// Wait for connect device...


	return TRUE;
}

BOOL CEthernetCtrl::GetEnableDeviceInfo(int nIdx, INFO_CONNECT_ETHERNET* pstDevice)
{
	if( NULL==pstDevice)
		return FALSE;

	const INFO_CLIENT* pClient = m_Server.GetConnectedClientInfo(nIdx);
	if(NULL==pClient)
		return FALSE;


	pstDevice->m_eProtocol= TYPE_PROTOCOL_TCP;
	
	CUtil::StringCopy(pstDevice->m_szName, _T("SMART CAMERA"));
	CUtil::StringFormat(pstDevice->m_szIpAddress, MAX_NAME_LEN, _T("%d.%d.%d.%d"), 
							pClient->m_dwIpAddress & 0xFF,
							(pClient->m_dwIpAddress >> 8) & 0xFF,
							(pClient->m_dwIpAddress >> 16) & 0xFF,
							(pClient->m_dwIpAddress >> 24) & 0xFF );
	//pstDevice->m_szSerialNumber[MAX_NAME_LEN];

	pstDevice->m_stArg.m_eNetwork	= TYPE_NETWORK_ETHERNET;
	pstDevice->m_stArg.m_dwArg		= pClient->m_dwIpAddress;
	CUtil::StringFormat(pstDevice->m_stArg.m_szArg, MAX_NAME_LEN, _T("%s (%s)"), pstDevice->m_szName, pstDevice->m_szIpAddress);

	return TRUE;
}



const int CEthernetCtrl::GetEnableInterfaceCount()
{
	return m_AdapterList.size();;
}


const int CEthernetCtrl::GetEnableDeviceCount()
{
	if(FALSE == IsOpen())
		return -1;

	const int nCount = m_Server.GetConnectedClientCount();
	return nCount;
}

const INFO_CLIENT* CEthernetCtrl::GetDeviceModuleInfo(const int nIdx)
{
	const int nCount = GetEnableDeviceCount();

	if(FALSE == IsOpen() || nCount<=nIdx )
		return NULL;

	return m_Server.GetConnectedClientInfo(nIdx);
}


BOOL CEthernetCtrl::IsExistEthernetInterface(const INFO_ETHERNET_ADAPTOR* pstEthernet)
{
	if(NULL==pstEthernet)
		return FALSE;

	const int nCount = m_AdapterList.size();
	for(int i=0; i<nCount; i++)
	{
		const INFO_ETHERNET_ADAPTOR* pInfo = m_AdapterList[i];
		if( pInfo->m_dwIpAddress == pstEthernet->m_dwIpAddress &&
			CUtil::StringCompare((TCHAR*)pInfo->m_szIpAddress, (TCHAR*)pstEthernet->m_szIpAddress) )
		{
			return TRUE;
		}
	}


	return FALSE;
}

BOOL CEthernetCtrl::AddEthernetInterface(const INFO_ETHERNET_ADAPTOR* pstEthernet)
{
	if(NULL==pstEthernet)
		return FALSE;

	INFO_ETHERNET_ADAPTOR* pInfo = new INFO_ETHERNET_ADAPTOR;
	memcpy(pInfo, pstEthernet, sizeof(INFO_ETHERNET_ADAPTOR));

	m_AdapterList.push_back( pInfo );

	return TRUE;
}

int CEthernetCtrl::SearchEthernetInterface()
{
	const int nCount = CUtil::GetEthernetAdaptorList(NULL, 0);
	if(1>nCount)
		return -1;

	INFO_ETHERNET_ADAPTOR* pstEthernet = new INFO_ETHERNET_ADAPTOR[nCount];
	CUtil::GetEthernetAdaptorList(pstEthernet, nCount);

	INFO_ETHERNET_ADAPTOR* pInfo = NULL;
	for(int i=0; i<nCount; i++)
	{
		if (0x00 != pstEthernet[i].m_dwIpAddress && FALSE==IsExistEthernetInterface( &pstEthernet[i] ) )
		{
			AddEthernetInterface( &pstEthernet[i] );
		}
	}
	delete [] pstEthernet;

	return GetEnableInterfaceCount();
}


// Server
BOOL CEthernetCtrl::StartServer()
{
	BOOL bResult = m_Server.Open(ETHERNET_IP_SERVER, ETHERNET_PORT_SERVER, TYPE_PROTOCOL_TCP);
	return bResult;

}


// Client
BOOL CEthernetCtrl::IsExistClient(LPCTSTR pszAddress, TYPE_PROTOCOL eProtocol)
{
	if(NULL==pszAddress)
		return FALSE;

	BOOL bResult = FALSE;

	TCHAR szIpAddr[MAX_NAME_LEN] = {0,};
	DWORD dwPort = 0;
	TYPE_PROTOCOL ePrtcl = TYPE_PROTOCOL_NONE;

	const int nCount = m_DeviceList.size();
	for(int i=0; i<nCount; i++)
	{
		bResult = m_DeviceList[i]->GetClientInfo(szIpAddr, &dwPort, &ePrtcl);
		if(FALSE==bResult)
			continue;

		if( CUtil::StringCompare((LPTSTR)pszAddress, szIpAddr) && eProtocol==ePrtcl )
		{
			return TRUE;
		}
	}

	return FALSE;
}

BOOL CEthernetCtrl::AddClient(LPCTSTR pszAddress, DWORD dwPort, TYPE_PROTOCOL eProtocol)
{
	if(NULL==pszAddress)
		return FALSE;

	CEthernetClient* pClient = new CEthernetClient;

	BOOL bResult = pClient->OpenBroadCastClient(pszAddress, dwPort);
	if(bResult)
	{
		m_DeviceList.push_back(pClient);
	}	
	return bResult;
}

BOOL CEthernetCtrl::GetWidth(const int nIdx, DWORD* pdwValue)
{
	BOOL bResult = m_Server.GetWidth(nIdx, pdwValue);
	return bResult;
}

BOOL CEthernetCtrl::GetHeight(const int nIdx, DWORD* pdwValue)
{
	BOOL bResult = m_Server.GetHeight(nIdx, pdwValue);
	return bResult;
}

BOOL CEthernetCtrl::GetMaxWidth(const int nIdx, DWORD* pdwValue)
{
	BOOL bResult = m_Server.GetMaxWidth(nIdx, pdwValue);
	return bResult;
}

BOOL CEthernetCtrl::GetMaxHeight(const int nIdx, DWORD* pdwValue)
{
	BOOL bResult = m_Server.GetMaxHeight(nIdx, pdwValue);
	return bResult;
}

BOOL CEthernetCtrl::GetPixelFormat(const int nIdx, DWORD* pdwValue)
{
	BOOL bResult = m_Server.GetPixelFormat(nIdx, pdwValue);
	return bResult;
}



