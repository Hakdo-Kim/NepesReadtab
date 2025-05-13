#include "StdAfx.h"
#include "XmlEmulDevice.h"
#include "util/util.h"

#ifdef _DEBUG
	#if defined(_WIN64)
		#pragma comment (lib, "tinyxml2d_x64.lib")
	#else
		#pragma comment (lib, "tinyxml2d.lib")
	#endif
#else
	#if defined(_WIN64)
		#pragma comment (lib, "tinyxml2_x64.lib")
	#else
		#pragma comment (lib, "tinyxml2.lib")
	#endif
#endif

#define XML_EMUL_FILENAME			"EmulDeviceList.xml"

#define XML_EMUL_NODE_ROOT			"EMULATORLIST"
#define XML_EMUL_NODE_DEVICE		"EMULATOR"
#define XML_EMUL_NODE_NAME			"NAME"
#define XML_EMUL_NODE_PATH			"PATH"
#define XML_EMUL_NODE_RESOLUTION	"RESOLUTION"
#define XML_EMUL_NODE_ROI			"ROI"
#define XML_EMUL_NODE_FPS			"FPS"

#define XML_EMUL_ATTR_X				"x"
#define XML_EMUL_ATTR_Y				"y"
#define XML_EMUL_ATTR_W				"w"
#define XML_EMUL_ATTR_H				"h"
#define XML_EMUL_ATTR_FPS			"fps"


CXmlEmulDevice::CXmlEmulDevice()
{
}

CXmlEmulDevice::~CXmlEmulDevice()
{
	ClearInformation();
}

BOOL CXmlEmulDevice::Load()
{
	TCHAR pszPath[MAX_EMUL_PATH] = {0,};
	CUtil::GetCurrentDirectory(pszPath, MAX_EMUL_PATH);
	CUtil::StringCat(pszPath, _T("\\Data\\EmulDeviceList.xml"));

	BOOL bResult = LoadInfomation(pszPath);
	return bResult;
}

BOOL CXmlEmulDevice::Save()
{
	TCHAR pszPath[MAX_EMUL_PATH] = {0,};
	CUtil::GetCurrentDirectory(pszPath, MAX_EMUL_PATH);

	{
		CUtil::StringCat(pszPath, _T("\\Data"));
		if (FALSE == CUtil::IsDirectory(pszPath))
		{
			::CreateDirectory(pszPath, NULL);
		}
	}

	CUtil::StringCat(pszPath, _T("\\EmulDeviceList.xml"));
	BOOL bResult = SaveInformation(pszPath);
	return bResult;
}

//Information.
const int CXmlEmulDevice::GetDeviceCount()
{
	int nCount = m_EmulDeviceList.size();
	return nCount;
}

const INFO_EMUL_DEVICE* CXmlEmulDevice::GetDeviceInfo(const int nIdx)
{
	const int nCount = GetDeviceCount();
	if(0>nIdx || nCount<=nIdx)
		return NULL;

	return m_EmulDeviceList[nIdx];
}

// Add
BOOL CXmlEmulDevice::AddDevice(INFO_EMUL_DEVICE& stEmul)
{
	if(FindDevice(stEmul.m_szName))
		return FALSE;

	INFO_EMUL_DEVICE* pstDevice = new INFO_EMUL_DEVICE;
	memcpy(pstDevice, &stEmul, sizeof(INFO_EMUL_DEVICE));

	//pstDevice->m_CamID = m_EmulDeviceList.size();
	pstDevice->m_bCycleDir = TRUE;

	m_EmulDeviceList.push_back(pstDevice);

	return TRUE;
}

BOOL CXmlEmulDevice::UpdateDevice(const int nIdx, INFO_EMUL_DEVICE& stEmul)
{
	const int nCount = m_EmulDeviceList.size();
	if (0>nIdx || nCount <= nIdx)
		return FALSE;

	//m_EmulDeviceList[nIdx]->m_szName;
	CUtil::StringCopy(m_EmulDeviceList[nIdx]->m_szName, stEmul.m_szName);
	CUtil::StringCopy(m_EmulDeviceList[nIdx]->m_szPath, stEmul.m_szPath);

	m_EmulDeviceList[nIdx]->m_dwFPS = stEmul.m_dwFPS;

	m_EmulDeviceList[nIdx]->m_bCameraEmulator = stEmul.m_bCameraEmulator;
	m_EmulDeviceList[nIdx]->m_stResolution = stEmul.m_stResolution;
	m_EmulDeviceList[nIdx]->m_stRoi = stEmul.m_stRoi;

	return TRUE;

}


// Delete
void CXmlEmulDevice::DeleteDevice(int nIdx)
{
	const int nCount = m_EmulDeviceList.size();
	if(0>nIdx || nCount <= nIdx)
		return;

	INFO_EMUL_DEVICE* pDevice = m_EmulDeviceList[nIdx];

	std::vector<INFO_EMUL_DEVICE*>::iterator iterBegin = m_EmulDeviceList.begin();
	iterBegin+=nIdx;

	m_EmulDeviceList.erase(iterBegin);

	delete pDevice;

	this->Save();


}

void CXmlEmulDevice::ClearDevice()
{
	//const int nCount = m_EmulDeviceList.size();

	//for (int i = 0; i < nCount; i++)
	//	DeleteDevice(i);

	std::vector<INFO_EMUL_DEVICE*>::iterator iter;
	while (m_EmulDeviceList.empty() == false)
	{
		iter = m_EmulDeviceList.begin();
		INFO_EMUL_DEVICE* pDevice = (*iter);
		if (pDevice)
			delete pDevice;
		pDevice = NULL;
		///

		m_EmulDeviceList.erase(iter);
	}
	m_EmulDeviceList.clear();

}


void CXmlEmulDevice::DeleteDevice(const TCHAR* pszName)
{
	if(NULL==pszName)
		return;

	BOOL bFind = FALSE;

	const int nCount = m_EmulDeviceList.size();
	for(int i=0; i<nCount; i++)
	{
		bFind = CUtil::StringCompare(m_EmulDeviceList[i]->m_szName, (LPTSTR) pszName);
		if(bFind)
		{
			INFO_EMUL_DEVICE* pDevice = m_EmulDeviceList[i];

			std::vector<INFO_EMUL_DEVICE*>::iterator iterBegin = m_EmulDeviceList.begin();
			iterBegin+=i;

			m_EmulDeviceList.erase(iterBegin);

			delete pDevice;

			break;
		}
	}
#ifndef DEF_LPAPP
	this->Save();
#endif
}

BOOL CXmlEmulDevice::FindDevice(const TCHAR* pszName, int* pIdx)
{
	if(NULL==pszName)
		return FALSE;
	
	BOOL bFind = FALSE;

	const int nCount = m_EmulDeviceList.size();
	for(int i=0; i<nCount; i++)
	{
		bFind = CUtil::StringCompare(m_EmulDeviceList[i]->m_szName, (LPTSTR) pszName);
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

BOOL CXmlEmulDevice::LoadInfomation(const TCHAR* pszPath)
{
	if(NULL==pszPath)
		return FALSE;

	tinyxml2::XMLDocument XmlDoc;
	if (tinyxml2::XML_SUCCESS != XmlDoc.LoadFile(pszPath))
	{
		return FALSE;
	}

	INFO_EMUL_DEVICE stEmul;

	tinyxml2::XMLHandle hDoc(XmlDoc);
	tinyxml2::XMLHandle hEmul = hDoc.FirstChildElement(XML_EMUL_NODE_ROOT).FirstChildElement(XML_EMUL_NODE_DEVICE);

	DWORD dwCam = 0;

	while(hEmul.ToNode())
	{
		memset(&stEmul, 0x00, sizeof(INFO_EMUL_DEVICE));
		if(FALSE==LoadEmulator(hEmul, stEmul))
			break;

		stEmul.m_CamID = dwCam;
		AddDevice(stEmul);
		dwCam++;

		hEmul = hEmul.NextSiblingElement(XML_EMUL_NODE_DEVICE);
	}
	
	return TRUE;
}

BOOL CXmlEmulDevice::LoadEmulator(tinyxml2::XMLHandle hEmul, INFO_EMUL_DEVICE& stEmul)
{
	tinyxml2::XMLElement* pElement = NULL;

	{
		pElement = hEmul.FirstChildElement(XML_EMUL_NODE_NAME).ToElement();
		if(NULL==pElement)
			return FALSE;
		CUtil::StringCopy(stEmul.m_szName, pElement->GetText());
	}

	{
		pElement = hEmul.FirstChildElement(XML_EMUL_NODE_PATH).ToElement();
		if(NULL==pElement)
			return FALSE;
		CUtil::StringCopy(stEmul.m_szPath, pElement->GetText());
	}

	{
		pElement = hEmul.FirstChildElement(XML_EMUL_NODE_RESOLUTION).ToElement();
		if(NULL==pElement)
			return FALSE;

		const char* pAttrX = pElement->Attribute(XML_EMUL_ATTR_X);
		const char* pAttrY = pElement->Attribute(XML_EMUL_ATTR_Y);

		stEmul.m_stResolution.cx = CUtil::StringToInt((LPTSTR)pAttrX, CUtil::StringLength((LPTSTR)pAttrX));
		stEmul.m_stResolution.cy = CUtil::StringToInt((LPTSTR)pAttrY, CUtil::StringLength((LPTSTR)pAttrY));
	}

	{
		pElement = hEmul.FirstChildElement(XML_EMUL_NODE_ROI).ToElement();
		if(NULL==pElement)
			return FALSE;

		const char* pAttrX = pElement->Attribute(XML_EMUL_ATTR_X);
		const char* pAttrY = pElement->Attribute(XML_EMUL_ATTR_Y);
		const char* pAttrW = pElement->Attribute(XML_EMUL_ATTR_W);
		const char* pAttrH = pElement->Attribute(XML_EMUL_ATTR_H);

		stEmul.m_stRoi.left		= CUtil::StringToInt((LPTSTR)pAttrX, CUtil::StringLength((LPTSTR)pAttrX));
		stEmul.m_stRoi.top		= CUtil::StringToInt((LPTSTR)pAttrY, CUtil::StringLength((LPTSTR)pAttrY));
		stEmul.m_stRoi.right	= stEmul.m_stRoi.left + CUtil::StringToInt((LPTSTR)pAttrW, CUtil::StringLength((LPTSTR)pAttrW));
		stEmul.m_stRoi.bottom	= stEmul.m_stRoi.top  + CUtil::StringToInt((LPTSTR)pAttrH, CUtil::StringLength((LPTSTR)pAttrH));
	}

	{
		pElement = hEmul.FirstChildElement(XML_EMUL_NODE_FPS).ToElement();
		if (NULL == pElement)
			return FALSE;

		const char* pAttrFps = pElement->Attribute(XML_EMUL_ATTR_FPS);
		stEmul.m_dwFPS = CUtil::StringToInt((LPTSTR)pAttrFps, CUtil::StringLength((LPTSTR)pAttrFps));
	}

	return TRUE;
}

BOOL CXmlEmulDevice::SaveInformation(const TCHAR* pszPath)
{
	if(NULL==pszPath)
		return FALSE;

	tinyxml2::XMLDocument XmlDoc;

	XmlDoc.InsertEndChild(XmlDoc.NewDeclaration());

	tinyxml2::XMLElement * pRoot = XmlDoc.NewElement(XML_EMUL_NODE_ROOT);
	XmlDoc.LinkEndChild(pRoot);

	const int nCount = m_EmulDeviceList.size();
	for(int i=0; i<nCount; i++)
	{
		tinyxml2::XMLElement* pEmul = XmlDoc.NewElement(XML_EMUL_NODE_DEVICE);

		if (FALSE == SaveEmulator(&XmlDoc, pEmul, m_EmulDeviceList[i]))
		{
			break;
		}
		pRoot->LinkEndChild(pEmul);
	}

	XmlDoc.SaveFile(pszPath);

	return TRUE;
}

BOOL CXmlEmulDevice::SaveEmulator(tinyxml2::XMLDocument* pXmlDoc, tinyxml2::XMLElement* pEmul, INFO_EMUL_DEVICE* pstEmul)
{
	if (NULL == pXmlDoc || NULL == pEmul || NULL == pstEmul)
		return FALSE;

	tinyxml2::XMLElement* pName = pXmlDoc->NewElement(XML_EMUL_NODE_NAME);
	tinyxml2::XMLText* pTxtName = pXmlDoc->NewText(pstEmul->m_szName);
	pName->LinkEndChild(pTxtName);

	tinyxml2::XMLElement* pPath = pXmlDoc->NewElement(XML_EMUL_NODE_PATH);
	tinyxml2::XMLText* pTxtPath = pXmlDoc->NewText(pstEmul->m_szPath);
	pPath->LinkEndChild(pTxtPath);


	tinyxml2::XMLElement* pResolution = pXmlDoc->NewElement(XML_EMUL_NODE_RESOLUTION);
	pResolution->SetAttribute(XML_EMUL_ATTR_X, pstEmul->m_stResolution.cx);
	pResolution->SetAttribute(XML_EMUL_ATTR_Y, pstEmul->m_stResolution.cy);


	tinyxml2::XMLElement* pRoi = pXmlDoc->NewElement(XML_EMUL_NODE_ROI);
	pRoi->SetAttribute(XML_EMUL_ATTR_X, pstEmul->m_stRoi.left);
	pRoi->SetAttribute(XML_EMUL_ATTR_Y, pstEmul->m_stRoi.top);
	pRoi->SetAttribute(XML_EMUL_ATTR_W, pstEmul->m_stRoi.right - pstEmul->m_stRoi.left);
	pRoi->SetAttribute(XML_EMUL_ATTR_H, pstEmul->m_stRoi.bottom - pstEmul->m_stRoi.top);


	tinyxml2::XMLElement* pFps = pXmlDoc->NewElement(XML_EMUL_NODE_FPS);
	pFps->SetAttribute(XML_EMUL_ATTR_FPS, (unsigned int) pstEmul->m_dwFPS);

	pEmul->LinkEndChild(pName);
	pEmul->LinkEndChild(pPath);
	pEmul->LinkEndChild(pResolution);
	pEmul->LinkEndChild(pRoi);
	pEmul->LinkEndChild(pFps);


	return TRUE;
}

void CXmlEmulDevice::ClearInformation()
{
	const int nCount = m_EmulDeviceList.size();

	for(int i=0; i<nCount; i++)
	{
		INFO_EMUL_DEVICE* pEmul = m_EmulDeviceList[i];
		delete pEmul;
	}

	std::vector<INFO_EMUL_DEVICE*> eclear;		// vector memory leak ¹æÁö.
	m_EmulDeviceList.swap(eclear);
	eclear.clear();
	m_EmulDeviceList.clear();
}