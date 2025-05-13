#include "StdAfx.h"
#include "SdkBasler.h"

CSdkBasler::CSdkBasler()
{
	m_bOpen = FALSE;
}

CSdkBasler::~CSdkBasler()
{
}

BOOL CSdkBasler::Open()
{
	if (TRUE == IsOpen())
		return TRUE;

	Pylon::PylonInitialize();
	m_bOpen = TRUE;
	
	BOOL bResult = FindAllDevice();
	if (FALSE == bResult)
	{
		Close();
	}

	return bResult;
}

void CSdkBasler::Close()
{
	ClearDeviceList();

	m_bOpen = FALSE;
	Pylon::PylonTerminate();
}

BOOL CSdkBasler::IsOpen()
{
	return m_bOpen;
}

BOOL CSdkBasler::Start(int nIdx)
{
	if (FALSE == IsOpen() || nIdx >= GetEnableDeviceCount())
		return FALSE;

	CCameraBasler* pCamera = m_PylonDeviceList[nIdx];

	BOOL bResult = pCamera->Start();
	return bResult;
}

void CSdkBasler::Stop(int nIdx)
{
	if (FALSE == IsOpen() || nIdx >= GetEnableDeviceCount())
		return;

	CCameraBasler* pCamera = m_PylonDeviceList[nIdx];
	pCamera->Stop();

}

void CSdkBasler::ClearDeviceList()
{
	const int size = (int)m_PylonDeviceList.size();
	for (int i = 0; i < size; i++)
	{
		if (m_PylonDeviceList[i])
			delete m_PylonDeviceList[i];
		m_PylonDeviceList[i] = NULL;
	}
	m_PylonDeviceList.clear();
}

BOOL CSdkBasler::FindAllDevice()
{
	if (FALSE == IsOpen())
		return FALSE;

	ClearDeviceList();
	try
	{
		Pylon::CTlFactory& tlFactory = Pylon::CTlFactory::GetInstance();
		Pylon::DeviceInfoList_t devices;
		if (0 == tlFactory.EnumerateDevices(devices))
			return FALSE;

		CCameraBasler* pCamera = NULL;
		try
		{
			const int nCount = (int)devices.size();
			for (int i = 0; i < nCount; i++)
			{
				pCamera = new CCameraBasler;
				pCamera->Open(tlFactory.CreateDevice(devices[i]));

				m_PylonDeviceList.push_back(pCamera);
			}
		}
		catch (const GenericException &e)
		{
			if (pCamera)
			{
				delete pCamera;
			}
			pCamera = NULL;

			e.GetDescription();
			return FALSE;
		}
	}
	catch (const GenericException &e)
	{
		e.GetDescription();
		return FALSE;
	}

	return TRUE;
}

const int CSdkBasler::GetEnableDeviceCount()
{
	return (int)m_PylonDeviceList.size();
}

BOOL CSdkBasler::IsGigE(int nIdx)
{
	if (FALSE == IsOpen() || nIdx >= GetEnableDeviceCount())
		return FALSE;

	CCameraBasler* pCamera = m_PylonDeviceList[nIdx];

	BOOL bResult = pCamera->IsGigE();
	return bResult;
}

BOOL CSdkBasler::IsUsb(int nIdx)
{
	if (FALSE == IsOpen() || nIdx >= GetEnableDeviceCount())
		return FALSE;

	CCameraBasler* pCamera = m_PylonDeviceList[nIdx];

	BOOL bResult = pCamera->IsUsb();
	return bResult;
}

const DWORD CSdkBasler::GetIpAddress(int nIdx)
{
	if (FALSE == IsOpen() || nIdx >= GetEnableDeviceCount())
		return FALSE;

	CCameraBasler* pCamera = m_PylonDeviceList[nIdx];

	DWORD dwIpAddr = pCamera->GetIpAddress();
	return dwIpAddr;
}

BOOL CSdkBasler::SetEventFunc(const int nIdx, FuncAcquisitionEvent pFunc, void* pUserData)
{
	if (FALSE == IsOpen() || nIdx >= GetEnableDeviceCount())
		return FALSE;

	CCameraBasler* pCamera = m_PylonDeviceList[nIdx];

	BOOL bResult = pCamera->SetEventFunc(pFunc, pUserData);
	return bResult;
}

BOOL CSdkBasler::GetCameraInformation(const int nIdx, INFO_OTHER_CATEGORY* pstRootCategory)
{
	if (FALSE == IsOpen() || nIdx >= GetEnableDeviceCount())
		return FALSE;
	
	CCameraBasler* pCamera = m_PylonDeviceList[nIdx];
	BOOL bResult = pCamera->GetCameraInformation(pstRootCategory);
	return bResult;
}

const INFO_OTHER_IF* CSdkBasler::GetCameraInformation(const int nIdx, const TCHAR* szName)
{
	if (FALSE == IsOpen() || nIdx >= GetEnableDeviceCount())
		return NULL;

	CCameraBasler* pCamera = m_PylonDeviceList[nIdx];
	const INFO_OTHER_IF* pOther = pCamera->GetCameraInformation(szName);
	return pOther;

}

BOOL CSdkBasler::GetCameraValue(const int nIdx, const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	if (FALSE == IsOpen() || nIdx >= GetEnableDeviceCount())
		return FALSE;

	CCameraBasler* pCamera = m_PylonDeviceList[nIdx];
	BOOL bResult = pCamera->GetCameraValue(pstInfo, pstValue);
	return bResult;
}

BOOL CSdkBasler::SetCameraValue(const int nIdx, const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	if (FALSE == IsOpen() || nIdx >= GetEnableDeviceCount())
		return FALSE;

	CCameraBasler* pCamera = m_PylonDeviceList[nIdx];
	BOOL bResult = pCamera->SetCameraValue(pstInfo, pstValue);
	return bResult;
}
