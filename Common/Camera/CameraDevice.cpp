#include "StdAfx.h"
#include "CameraDevice.h"
#include "Util/Util.h"

CCameraDevice::CCameraDevice()
{
	memset(&m_stDefUserConfig, 0x00, sizeof(INFO_DEFDEV_USERCONFIG));
}

CCameraDevice::~CCameraDevice()
{
}

const int CCameraDevice::GetDefaultListCount(TYPE_NETWORK eNetwork)
{
	int nCount = -1;

	if (TYPE_NETWORK_GIGE == eNetwork)
		nCount = m_DefGigEList.size();
	else if (TYPE_NETWORK_USB == eNetwork)
		nCount = m_DefUSBList.size();
	else if (TYPE_NETWORK_CAMERALINK == eNetwork)
		nCount = m_DefCLList.size();
	else if (TYPE_NETWORK_BASLER == eNetwork)
		nCount = m_DefBaslerList.size();

	return nCount;
}

const INFO_DEFDEV* CCameraDevice::GetDefaultDevice(TYPE_NETWORK eNetwork, const TCHAR* pszName)
{
	if (NULL == pszName)
		return NULL;

	INFO_DEFDEV* pDefDev = NULL;

	const int nCount = GetDefaultListCount(eNetwork);
	for (int i = 0; i < nCount; i++)
	{
		if (TYPE_NETWORK_GIGE == eNetwork)
			pDefDev = &m_DefGigEList[i];
		else if (TYPE_NETWORK_USB == eNetwork)
			pDefDev = &m_DefUSBList[i];
		else if (TYPE_NETWORK_CAMERALINK == eNetwork)
			pDefDev = (INFO_DEFDEV*)&m_DefCLList[i];
		else if (TYPE_NETWORK_BASLER == eNetwork)
			pDefDev = &m_DefBaslerList[i];
		else
			pDefDev = NULL;

		if (CUtil::StringCompare(pDefDev->m_szName, (TCHAR*) pszName))
			return pDefDev;
	}

	return NULL;
}

const INFO_DEFDEV* CCameraDevice::GetDefaultDevice(const INFO_CONNECT_DEV* pDev)
{
	if (NULL == pDev)
		return NULL;

	INFO_DEFDEV* pDefDev = NULL;
	TCHAR* pszName = NULL;

	if (TYPE_NETWORK_GIGE == pDev->m_eNetwork)
		pszName = ((INFO_CONNECT_GIGE*)pDev)->m_szName;
	else if (TYPE_NETWORK_USB == pDev->m_eNetwork)
		pszName = ((INFO_CONNECT_USB*)pDev)->m_szName;
	else if (TYPE_NETWORK_CAMERALINK == pDev->m_eNetwork)
		pszName = ((INFO_CONNECT_CAMERALINK*)pDev)->m_szName;
	else if (TYPE_NETWORK_BASLER == pDev->m_eNetwork)
		pszName = ((INFO_CONNECT_OTHER_MANUFACTURER*)pDev)->m_szName;
	
	const int nCount = GetDefaultListCount(pDev->m_eNetwork);
	for (int i = 0; i < nCount; i++)
	{
		if (TYPE_NETWORK_GIGE == pDev->m_eNetwork)
			pDefDev = &m_DefGigEList[i];
		else if (TYPE_NETWORK_USB == pDev->m_eNetwork)
			pDefDev = &m_DefUSBList[i];
		else if (TYPE_NETWORK_CAMERALINK == pDev->m_eNetwork)
			pDefDev = (INFO_DEFDEV*)&m_DefCLList[i];
		else if (TYPE_NETWORK_BASLER == pDev->m_eNetwork)
			pDefDev = &m_DefBaslerList[i];
		else
			pDefDev = NULL;

		if (CUtil::StringCompare(pDefDev->m_szName, (TCHAR*)pszName))
			return pDefDev;
	}

	return NULL;
}

const INFO_DEFDEV_CL* CCameraDevice::GetCameraLinkDevice(const TYPE_CLDEVICE eDevice)
{
	INFO_DEFDEV_CL* pDefDev = NULL;

	const int nCount = m_DefCLList.size();
	for (int i = 0; i < nCount; i++)
	{
		if (eDevice == m_DefCLList[i].m_eCLDevice)
		{
			pDefDev = &m_DefCLList[i];
			break;
		}
	}

	return pDefDev;
}


int CCameraDevice::AddDefaultDevice(INFO_DEFDEV* pstDefDev)
{
	if (NULL == pstDefDev)
		return -1;

	TYPE_NETWORK eNetwork = pstDefDev->m_eNetwork;
	int nCount = -1;

	if (TYPE_NETWORK_GIGE == eNetwork)
		m_DefGigEList.push_back(*pstDefDev);
	else if (TYPE_NETWORK_USB == eNetwork)
		m_DefUSBList.push_back(*pstDefDev);
	else if (TYPE_NETWORK_CAMERALINK == eNetwork)
		m_DefCLList.push_back(*((INFO_DEFDEV_CL*)pstDefDev));
	else if (TYPE_NETWORK_BASLER == eNetwork)
		m_DefBaslerList.push_back(*pstDefDev);

	nCount = GetDefaultListCount(eNetwork);
	return nCount;
}

int CCameraDevice::AddCamfile(INFO_FRAMEGRABBER_CAMFILE* pstCamfile)
{
	if (NULL == pstCamfile)
		return -1;

	m_CLCamFileList.push_back(*pstCamfile);

	int nCount = m_CLCamFileList.size();
	return nCount;
}


void CCameraDevice::ClearDefaultDevice(TYPE_NETWORK eNetwork)
{
	if (TYPE_NETWORK_GIGE == eNetwork)
		m_DefGigEList.clear();
	else if (TYPE_NETWORK_USB == eNetwork)
		m_DefUSBList.clear();
	else if (TYPE_NETWORK_CAMERALINK == eNetwork)
		m_DefCLList.clear();
	else if (TYPE_NETWORK_BASLER == eNetwork)
		m_DefBaslerList.clear();
}

void CCameraDevice::ClearCamfile()
{
	m_CLCamFileList.clear();;
}

void CCameraDevice::ClearAll()
{
	ClearDefaultDevice(TYPE_NETWORK_GIGE);
	ClearDefaultDevice(TYPE_NETWORK_USB);
	ClearDefaultDevice(TYPE_NETWORK_CAMERALINK);
	ClearDefaultDevice(TYPE_NETWORK_BASLER);

	ClearCamfile();
}

const INFO_FRAMEGRABBER_CAMFILE* CCameraDevice::GetCamFile(const INFO_CAMERALINK* pstCL)
{
	if (NULL == pstCL)
		return NULL;
	INFO_FRAMEGRABBER_CAMFILE* pszCamFile = NULL;

	const int size = m_CLCamFileList.size();
	for (int i = 0; i < size; i++)
	{
		if (m_CLCamFileList[i].m_eGrabber == pstCL->m_eClFrameGrabber &&
			m_CLCamFileList[i].m_eModelType == pstCL->m_eClDevice  &&
			m_CLCamFileList[i].m_eImageTap == pstCL->m_eClImageTaps &&
			m_CLCamFileList[i].m_eDataBit == pstCL->m_eClDataBit &&
			m_CLCamFileList[i].m_eColor == pstCL->m_eClColor)
		{
			pszCamFile = &m_CLCamFileList[i];
			break;
		}
	}
	return pszCamFile;
}

BOOL CCameraDevice::IsEnableFramegrabber(TYPE_CLGRABBER eGrabber)
{
	BOOL bEnable = FALSE;

	const int size = m_CLCamFileList.size();
	for (int i = 0; i < size; i++)
	{
		if (eGrabber == m_CLCamFileList[i].m_eGrabber)
		{
			bEnable = TRUE;
			break;
		}
	}
	return bEnable;
}

int CCameraDevice::GetEnableModelList(TYPE_CLGRABBER eGrabber, BOOL* pbModelList, int nLen)
{
	if (NULL == pbModelList)
		return 0;

	int nCount = 0;

	const int size = m_CLCamFileList.size();
	for (int i = 0; i < size; i++)
	{
		if (eGrabber == m_CLCamFileList[i].m_eGrabber)
		{
			if (nLen > m_CLCamFileList[i].m_eModelType)
			{
				if (FALSE == pbModelList[m_CLCamFileList[i].m_eModelType])
					nCount++;

				pbModelList[m_CLCamFileList[i].m_eModelType] = TRUE;
			}
		}
	}

	return nCount;
}

int CCameraDevice::GetEnableImageTapList(TYPE_CLGRABBER eGrabber, TYPE_CLDEVICE eModel, BOOL* pbTapList, int nLen)
{
	if (NULL == pbTapList)
		return 0;

	int nCount = 0;

	const int size = m_CLCamFileList.size();
	for (int i = 0; i < size; i++)
	{
		if (eGrabber == m_CLCamFileList[i].m_eGrabber && eModel == m_CLCamFileList[i].m_eModelType)
		{
			if (nLen > m_CLCamFileList[i].m_eImageTap)
			{
				if (FALSE == pbTapList[m_CLCamFileList[i].m_eImageTap])
					nCount++;

				pbTapList[m_CLCamFileList[i].m_eImageTap] = TRUE;
			}
		}
	}

	return nCount;
}

int CCameraDevice::GetEnableDataBitList(TYPE_CLGRABBER eGrabber, TYPE_CLDEVICE eModel, BOOL* pbDataBitList, int nLen)
{
	if (NULL == pbDataBitList)
		return 0;

	int nCount = 0;

	const int size = m_CLCamFileList.size();
	for (int i = 0; i < size; i++)
	{
		if (eGrabber == m_CLCamFileList[i].m_eGrabber && eModel == m_CLCamFileList[i].m_eModelType)
		{
			if (nLen > m_CLCamFileList[i].m_eDataBit)
			{
				if (FALSE == pbDataBitList[m_CLCamFileList[i].m_eDataBit])
					nCount++;

				pbDataBitList[m_CLCamFileList[i].m_eDataBit] = TRUE;
			}
		}
	}

	return nCount;
}

int CCameraDevice::GetEnableColorList(TYPE_CLGRABBER eGrabber, TYPE_CLDEVICE eModel, BOOL* pbColorList, int nLen)
{
	if (NULL == pbColorList)
		return 0;

	int nCount = 0;

	const int size = m_CLCamFileList.size();
	for (int i = 0; i < size; i++)
	{
		if (eGrabber == m_CLCamFileList[i].m_eGrabber && eModel == m_CLCamFileList[i].m_eModelType)
		{
			if (nLen > m_CLCamFileList[i].m_eColor)
			{
				if (FALSE == pbColorList[m_CLCamFileList[i].m_eColor])
					nCount++;

				pbColorList[m_CLCamFileList[i].m_eColor] = TRUE;
			}
		}
	}

	return nCount;
}



// UserConfig
const INFO_DEFDEV_USERCONFIG* CCameraDevice::GetUserConfig()
{
	return &m_stDefUserConfig;
}

void CCameraDevice::UpdateUserConfig(const INFO_DEFDEV_USERCONFIG* pstUserConfig)
{
	memcpy(&m_stDefUserConfig, pstUserConfig, sizeof(INFO_DEFDEV_USERCONFIG));

}