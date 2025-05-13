#include "stdafx.h"

#include "XmlClDevice.h"
#include "util/util.h"

#define XML_CL_FILENAME				"CLDeviceList.xml"

#define XML_CL_NODE_ROOT			"CAMERALINKLIST"
#define XML_CL_NODE_DEVICE			"CAMERALINK"
#define XML_CL_NODE_CAMERA	        "CAMERA"
#define XML_CL_NODE_NAME			"NAME"
#define XML_CL_NODE_FRAMEGRABBER	"FRAMEGRABBER"
#define XML_CL_NODE_CAMFILE			"FILE"

#define XML_CL_ATTR_MODEL			"model"
#define XML_CL_ATTR_IMAGETAP		"imagetap"
#define XML_CL_ATTR_DATABIT			"databit"
#define XML_CL_ATTR_COLOR			"color"
#define XML_CL_ATTR_TRIGGER			"trigger"
#define XML_CL_ATTR_CAMFILE			"camfile"


#define XML_CL_ATTR_TYPE			"type"
#define XML_CL_ATTR_PORT			"port"
#define XML_CL_ATTR_SPEED			"speed"


//
#define XML_VALUE_MODEL_CL2M		_T("LPMVC-CL2M")
#define XML_VALUE_MODEL_CL4M		_T("LPMVC-CL4M")
#define XML_VALUE_MODEL_CL25M		_T("LPMVC-CL25M")
#define XML_VALUE_MODEL_CL025M		_T("LPMVC-CL025M")

#define XML_VALUE_CLR_MONO			_T("mono")
#define XML_VALUE_CLR_COLOR			_T("color")

#define XML_VALUE_GRABBER_EURESYS	_T("EURESYS")
#define XML_VALUE_GRABBER_SILICON	_T("SILICON")
#define XML_VALUE_GRABBER_MATROX	_T("MATROX")



CXmlCLDevice::CXmlCLDevice()
{
}

CXmlCLDevice::~CXmlCLDevice()
{
	ClearInformation();
}

BOOL CXmlCLDevice::Load()
{
	TCHAR pszPath[MAX_CL_PATH] = { 0, };
	CUtil::GetCurrentDirectory(pszPath, MAX_CL_PATH);
	CUtil::StringCat(pszPath, _T("\\Data\\CLDeviceList.xml"));

	BOOL bResult = LoadInfomation(pszPath);
	return bResult;
}

BOOL CXmlCLDevice::Save()
{
	TCHAR pszPath[MAX_CL_PATH] = { 0, };
	CUtil::GetCurrentDirectory(pszPath, MAX_CL_PATH);
	CUtil::StringCat(pszPath, _T("\\Data\\CLDeviceList.xml"));

	BOOL bResult = SaveInformation(pszPath);
	return bResult;
}

//Information.
const int CXmlCLDevice::GetDeviceCount()
{
	int nCount = m_CLDeviceList.size();
	return nCount;
}

const INFO_CL_DEVICE* CXmlCLDevice::GetDeviceInfo(const int nIdx)
{
	const int nCount = GetDeviceCount();
	if (0>nIdx || nCount <= nIdx)
		return NULL;

	return m_CLDeviceList[nIdx];
}

const TCHAR* CXmlCLDevice::GetModelName(TYPE_CLDEVICE eDevice)
{
	TCHAR* pszName = NULL;

	if (TYPE_CLDEVICE_2M == eDevice)
		pszName = XML_VALUE_MODEL_CL2M;
	else if (TYPE_CLDEVICE_4M == eDevice)
		pszName = XML_VALUE_MODEL_CL4M;
	else if (TYPE_CLDEVICE_25M == eDevice)
		pszName = XML_VALUE_MODEL_CL25M;
	else if (TYPE_CLDEVICE_N25M == eDevice)
		pszName = XML_VALUE_MODEL_CL025M;

	return pszName;
}

// Add
BOOL CXmlCLDevice::AddDevice(INFO_CL_DEVICE& stCL)
{
	if (FindDevice(stCL.m_stCameraLink.m_szName))
		return FALSE;

	INFO_CL_DEVICE* pstDevice = new INFO_CL_DEVICE;
	memcpy(pstDevice, &stCL, sizeof(INFO_CL_DEVICE));

	//pstDevice->m_CamID = m_CLDeviceList.size();

	m_CLDeviceList.push_back(pstDevice);

	return TRUE;
}

BOOL CXmlCLDevice::UpdateDevice(const int nIdx, INFO_CL_DEVICE& stCL)
{
	const int nCount = m_CLDeviceList.size();
	if (0>nIdx || nCount <= nIdx)
		return FALSE;

	DWORD dwCamID = m_CLDeviceList[nIdx]->m_CamID;

	INFO_CL_DEVICE* pstDevice = m_CLDeviceList[nIdx];
	memcpy(pstDevice, &stCL, sizeof(INFO_CL_DEVICE));

	pstDevice->m_CamID = dwCamID;

	return TRUE;
}

// Delete
void CXmlCLDevice::DeleteDevice(int nIdx)
{
	const int nCount = m_CLDeviceList.size();
	if (0>nIdx || nCount <= nIdx)
		return;

	INFO_CL_DEVICE* pDevice = m_CLDeviceList[nIdx];

	std::vector<INFO_CL_DEVICE*>::iterator iterBegin = m_CLDeviceList.begin();
	iterBegin += nIdx;

	m_CLDeviceList.erase(iterBegin);

	delete pDevice;

	this->Save();
}

void CXmlCLDevice::ClearDevice()
{
	std::vector<INFO_CL_DEVICE*>::iterator iter;
	while (m_CLDeviceList.empty() == false)
	{
		iter = m_CLDeviceList.begin();
		INFO_CL_DEVICE* pDevice = (*iter);
		if (pDevice)
			delete pDevice;
		pDevice = NULL;

		m_CLDeviceList.erase(iter);
	}
	m_CLDeviceList.clear();

}


void CXmlCLDevice::DeleteDevice(const TCHAR* pszName)
{
	if (NULL == pszName)
		return;

	BOOL bFind = FALSE;

	const int nCount = m_CLDeviceList.size();
	for (int i = 0; i<nCount; i++)
	{
		bFind = CUtil::StringCompare(m_CLDeviceList[i]->m_stCameraLink.m_szName, (LPTSTR)pszName);
		if (bFind)
		{
			INFO_CL_DEVICE* pDevice = m_CLDeviceList[i];

			std::vector<INFO_CL_DEVICE*>::iterator iterBegin = m_CLDeviceList.begin();
			iterBegin += i;

			m_CLDeviceList.erase(iterBegin);

			delete pDevice;

			break;
		}
	}
#ifndef DEF_LPAPP
	this->Save();
#endif
}

BOOL CXmlCLDevice::FindDevice(const TCHAR* pszName, int* pIdx)
{
	if (NULL == pszName)
		return FALSE;

	BOOL bFind = FALSE;

	const int nCount = m_CLDeviceList.size();
	for (int i = 0; i<nCount; i++)
	{
		bFind = CUtil::StringCompare(m_CLDeviceList[i]->m_stCameraLink.m_szName, (LPTSTR)pszName);
		if (bFind)
		{
			if (pIdx)
			{
				*pIdx = i;
			}
			break;
		}
	}
	return bFind;
}

BOOL CXmlCLDevice::LoadInfomation(const TCHAR* pszPath)
{
	if (NULL == pszPath)
		return FALSE;

	tinyxml2::XMLDocument XmlDoc;
	if (tinyxml2::XML_SUCCESS != XmlDoc.LoadFile(pszPath))
	{
		return FALSE;
	}

	INFO_CL_DEVICE stCL;

	tinyxml2::XMLHandle hDoc(XmlDoc);
	tinyxml2::XMLHandle hCL = hDoc.FirstChildElement(XML_CL_NODE_ROOT).FirstChildElement(XML_CL_NODE_DEVICE);

	DWORD dwCam = 0;

	while (hCL.ToNode())
	{
		memset(&stCL, 0x00, sizeof(INFO_CL_DEVICE));
		if (FALSE == LoadCameraLink(hCL, stCL))
			break;

		stCL.m_CamID = dwCam;
		AddDevice(stCL);
		dwCam++;

		hCL = hCL.NextSiblingElement(XML_CL_NODE_DEVICE);
	}

	return TRUE;
}

BOOL CXmlCLDevice::LoadCameraLink(tinyxml2::XMLHandle hCL, INFO_CL_DEVICE& stCL)
{
	tinyxml2::XMLElement* pElement = NULL;

	// CameraLink Name
	{
		pElement = hCL.FirstChildElement(XML_CL_NODE_NAME).ToElement();
		if (NULL == pElement)
			return FALSE;
		CUtil::StringCopy(stCL.m_stCameraLink.m_szName, pElement->GetText());
	}

	// Camera
	{
		pElement = hCL.FirstChildElement(XML_CL_NODE_CAMERA).ToElement();
		if (NULL == pElement)
			return FALSE;

		const char* pModel = pElement->Attribute(XML_CL_ATTR_MODEL);
		const char* pImageTap = pElement->Attribute(XML_CL_ATTR_IMAGETAP);
		const char* pDataBit = pElement->Attribute(XML_CL_ATTR_DATABIT);
		const char* pColor = pElement->Attribute(XML_CL_ATTR_COLOR);

		if (CUtil::StringCompare(XML_VALUE_MODEL_CL025M, (LPTSTR)(LPCTSTR)pModel))
			stCL.m_stCameraLink.m_eClDevice = TYPE_CLDEVICE_N25M;
		else if (CUtil::StringCompare(XML_VALUE_MODEL_CL25M, (LPTSTR)(LPCTSTR)pModel))
			stCL.m_stCameraLink.m_eClDevice = TYPE_CLDEVICE_25M;
		else if (CUtil::StringCompare(XML_VALUE_MODEL_CL4M, (LPTSTR)(LPCTSTR)pModel))
			stCL.m_stCameraLink.m_eClDevice = TYPE_CLDEVICE_4M;
		else if (CUtil::StringCompare(XML_VALUE_MODEL_CL2M, (LPTSTR)(LPCTSTR)pModel))
			stCL.m_stCameraLink.m_eClDevice = TYPE_CLDEVICE_2M;
		else
			return FALSE;

		const DWORD dwImageTap = CUtil::StringToDword((LPTSTR)(LPCTSTR)pImageTap, CUtil::StringLength((LPTSTR)(LPCTSTR)pImageTap));
		if (10 == dwImageTap)
			stCL.m_stCameraLink.m_eClImageTaps = TYPE_CLIMGTAPS_10;
		else if (8 == dwImageTap)
			stCL.m_stCameraLink.m_eClImageTaps = TYPE_CLIMGTAPS_08;
		else if (4 == dwImageTap)
			stCL.m_stCameraLink.m_eClImageTaps = TYPE_CLIMGTAPS_04;
		else if (2 == dwImageTap)
			stCL.m_stCameraLink.m_eClImageTaps = TYPE_CLIMGTAPS_02;
		else
			return FALSE;

		const DWORD dwDataBit = CUtil::StringToDword((LPTSTR)(LPCTSTR)pDataBit, CUtil::StringLength((LPTSTR)(LPCTSTR)pDataBit));
		if (10 == dwDataBit)
			stCL.m_stCameraLink.m_eClDataBit = TYPE_CLDATABIT_10;
		else if (8 == dwDataBit)
			stCL.m_stCameraLink.m_eClDataBit = TYPE_CLDATABIT_08;
		else
			return FALSE;

		if (CUtil::StringCompare(XML_VALUE_CLR_MONO, (LPTSTR)(LPCTSTR)pColor))
			stCL.m_stCameraLink.m_eClColor = TYPE_CAMCOLOR_MONO;
		else if (CUtil::StringCompare(XML_VALUE_CLR_COLOR, (LPTSTR)(LPCTSTR)pColor))
			stCL.m_stCameraLink.m_eClColor = TYPE_CAMCOLOR_COLOR;
		else
			return FALSE;
	}

	// FrameGrabber
	{
		pElement = hCL.FirstChildElement(XML_CL_NODE_FRAMEGRABBER).ToElement();
		if (NULL == pElement)
			return FALSE;

		const char* pType = pElement->Attribute(XML_CL_ATTR_TYPE);
		const char* pPort = pElement->Attribute(XML_CL_ATTR_PORT);
		const char* pSpeed = pElement->Attribute(XML_CL_ATTR_SPEED);

		if (CUtil::StringCompare(XML_VALUE_GRABBER_EURESYS, (LPTSTR)(LPCTSTR)pType))
			stCL.m_stCameraLink.m_eClFrameGrabber = TYPE_CLGRABBER_EURESYS;
		else if (CUtil::StringCompare(XML_VALUE_GRABBER_SILICON, (LPTSTR)(LPCTSTR)pType))
			stCL.m_stCameraLink.m_eClFrameGrabber = TYPE_CLGRABBER_SILICONSOFTWARE;
		else if (CUtil::StringCompare(XML_VALUE_GRABBER_MATROX, (LPTSTR)(LPCTSTR)pType))
			stCL.m_stCameraLink.m_eClFrameGrabber = TYPE_CLGRABBER_MATROX;
		else
			return FALSE;

		CUtil::StringCopy(stCL.m_stCameraLink.m_szSerial, pPort);
		stCL.m_stCameraLink.m_dwSpeed = CUtil::StringToDword((LPTSTR)(LPCTSTR)pSpeed, CUtil::StringLength((LPTSTR)(LPCTSTR)pSpeed));
		

		LoadCameraLinkCamFile(hCL.FirstChildElement(XML_CL_NODE_FRAMEGRABBER), stCL);
	}

	return TRUE;
}

BOOL CXmlCLDevice::LoadCameraLinkCamFile(tinyxml2::XMLHandle hCL, INFO_CL_DEVICE& stCL)
{

	tinyxml2::XMLElement* pElement = NULL;

	tinyxml2::XMLHandle hCamFile = hCL.FirstChildElement(XML_CL_NODE_CAMFILE);
	while (hCamFile.ToNode())
	{
		pElement = hCamFile.ToElement();

		const char* pTrigger = pElement->Attribute(XML_CL_ATTR_TRIGGER);
		const char* pCamFile = pElement->Attribute(XML_CL_ATTR_CAMFILE);

		if (CUtil::StringICompare((char*)pTrigger, _T("true")))
			CUtil::StringCopy(stCL.m_szCamFile[CLCAMFILE_TRIGGER], pCamFile);
		else
			CUtil::StringCopy(stCL.m_szCamFile[CLCAMFILE_NORMAL], pCamFile);
	

		hCamFile = hCamFile.NextSiblingElement(XML_CL_NODE_CAMFILE);
	}
	
	return TRUE;
}


BOOL CXmlCLDevice::SaveInformation(const TCHAR* pszPath)
{
	if (NULL == pszPath)
		return FALSE;

	tinyxml2::XMLDocument XmlDoc;
	XmlDoc.InsertEndChild(XmlDoc.NewDeclaration());

	tinyxml2::XMLElement * pRoot = XmlDoc.NewElement(XML_CL_NODE_ROOT);
	XmlDoc.LinkEndChild(pRoot);

	const int nCount = m_CLDeviceList.size();
	for (int i = 0; i<nCount; i++)
	{
		tinyxml2::XMLElement* pEmul = XmlDoc.NewElement(XML_CL_NODE_DEVICE);

		if (FALSE == SaveCameraLink(&XmlDoc, pEmul, m_CLDeviceList[i]))
		{
			break;
		}
		pRoot->LinkEndChild(pEmul);
	}

	XmlDoc.SaveFile(pszPath);

	return TRUE;
}

BOOL CXmlCLDevice::SaveCameraLink(tinyxml2::XMLDocument* pXmlDoc, tinyxml2::XMLElement* pCL, INFO_CL_DEVICE* pstCL)
{
	if (NULL == pXmlDoc || NULL == pCL || NULL == pstCL)
		return FALSE;

	TCHAR* pTxt = NULL;
	LONG dwValue = 0;

	// CameraLink Name
	tinyxml2::XMLElement* pName = pXmlDoc->NewElement(XML_CL_NODE_NAME);
	tinyxml2::XMLText* pTxtName = pXmlDoc->NewText(pstCL->m_stCameraLink.m_szName);
	pName->LinkEndChild(pTxtName);


	// Camera
	tinyxml2::XMLElement* pCamera = pXmlDoc->NewElement(XML_CL_NODE_CAMERA);

	if (TYPE_CLDEVICE_N25M == pstCL->m_stCameraLink.m_eClDevice)
		pTxt = XML_VALUE_MODEL_CL025M;
	else if (TYPE_CLDEVICE_25M == pstCL->m_stCameraLink.m_eClDevice)
		pTxt = XML_VALUE_MODEL_CL25M;
	else if (TYPE_CLDEVICE_4M == pstCL->m_stCameraLink.m_eClDevice)
		pTxt = XML_VALUE_MODEL_CL4M;
	else if (TYPE_CLDEVICE_2M == pstCL->m_stCameraLink.m_eClDevice)
		pTxt = XML_VALUE_MODEL_CL2M;
	else
		return FALSE;
	pCamera->SetAttribute(XML_CL_ATTR_MODEL, pTxt);


	if (TYPE_CLIMGTAPS_10 == pstCL->m_stCameraLink.m_eClImageTaps)			dwValue = 10;
	else if (TYPE_CLIMGTAPS_08 == pstCL->m_stCameraLink.m_eClImageTaps)		dwValue = 8;
	else if (TYPE_CLIMGTAPS_04 == pstCL->m_stCameraLink.m_eClImageTaps)		dwValue = 4;
	else if (TYPE_CLIMGTAPS_02 == pstCL->m_stCameraLink.m_eClImageTaps)		dwValue = 2;
	else
		return FALSE;
	pCamera->SetAttribute(XML_CL_ATTR_IMAGETAP, dwValue);


	if (TYPE_CLDATABIT_10 == pstCL->m_stCameraLink.m_eClDataBit)			dwValue = 10;
	else if (TYPE_CLDATABIT_08 == pstCL->m_stCameraLink.m_eClDataBit)		dwValue = 8;
	else
		return FALSE;
	pCamera->SetAttribute(XML_CL_ATTR_DATABIT, dwValue);


	if (TYPE_CAMCOLOR_MONO == pstCL->m_stCameraLink.m_eClColor)
		pTxt = XML_VALUE_CLR_MONO;
	else if (TYPE_CAMCOLOR_COLOR == pstCL->m_stCameraLink.m_eClColor)
		pTxt = XML_VALUE_CLR_COLOR;
	else
		return FALSE;		
	pCamera->SetAttribute(XML_CL_ATTR_COLOR, pTxt);


	// FrameGrabber
	tinyxml2::XMLElement* pFrameGrabber = pXmlDoc->NewElement(XML_CL_NODE_FRAMEGRABBER);

	
	{
		// Trigger Off
		tinyxml2::XMLElement* pCamFile = pXmlDoc->NewElement(XML_CL_NODE_CAMFILE);
		pCamFile->SetAttribute(XML_CL_ATTR_TRIGGER, "false");
		pCamFile->SetAttribute(XML_CL_ATTR_CAMFILE, pstCL->m_szCamFile[CLCAMFILE_NORMAL]);

		// Trigger On
		tinyxml2::XMLElement* pCamFileTr = pXmlDoc->NewElement(XML_CL_NODE_CAMFILE);
		pCamFileTr->SetAttribute(XML_CL_ATTR_TRIGGER, "true");
		pCamFileTr->SetAttribute(XML_CL_ATTR_CAMFILE, pstCL->m_szCamFile[CLCAMFILE_TRIGGER]);

		pFrameGrabber->LinkEndChild(pCamFile);
		pFrameGrabber->LinkEndChild(pCamFileTr);
	}

	if (TYPE_CLGRABBER_EURESYS == pstCL->m_stCameraLink.m_eClFrameGrabber)
		pTxt = XML_VALUE_GRABBER_EURESYS;
	else if (TYPE_CLGRABBER_SILICONSOFTWARE == pstCL->m_stCameraLink.m_eClFrameGrabber)
		pTxt = XML_VALUE_GRABBER_SILICON;
	else if (TYPE_CLGRABBER_MATROX == pstCL->m_stCameraLink.m_eClFrameGrabber)
		pTxt = XML_VALUE_GRABBER_MATROX;
	else
		return FALSE;
	pFrameGrabber->SetAttribute(XML_CL_ATTR_TYPE, pTxt);
	pFrameGrabber->SetAttribute(XML_CL_ATTR_PORT, pstCL->m_stCameraLink.m_szSerial);
	pFrameGrabber->SetAttribute(XML_CL_ATTR_SPEED, (LONG)pstCL->m_stCameraLink.m_dwSpeed);



	pCL->LinkEndChild(pName);
	pCL->LinkEndChild(pCamera);
	pCL->LinkEndChild(pFrameGrabber);

	return TRUE;
}

void CXmlCLDevice::ClearInformation()
{
	const int nCount = m_CLDeviceList.size();

	for (int i = 0; i<nCount; i++)
	{
		INFO_CL_DEVICE* pCL = m_CLDeviceList[i];
		delete pCL;
	}

	std::vector<INFO_CL_DEVICE*> eclear;		// vector memory leak ¹æÁö.
	m_CLDeviceList.swap(eclear);
	eclear.clear();
	m_CLDeviceList.clear();
}