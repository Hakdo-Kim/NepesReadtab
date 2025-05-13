
#include "StdAfx.h"
#include "XmlFile.h"

#include "Util/Util.h"

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

CXmlFile::CXmlFile()
{
	{
		/*//
		CXmlNode* pXmlNode = CXmlFile::Load(_T("E:/Work/Machine Vision/NAVI/Navi.xml"), XML_NAVINODE_ROOT);
		CXmlFile::Save(_T("E:/Work/Machine Vision/NAVI/navi_save.xml"), XML_NAVINODE_ROOT, pXmlNode);
		if (pXmlNode)
			delete pXmlNode;
		//*/
	}


	{
		/*//
		CXmlNode* pXmlNode = CXmlFile::Load(_T("E:/Work/Machine Vision/NAVI/navi_setting.xml"), XML_NAVINODE_SET_ROOT);
		CXmlFile::Save(_T("E:/Work/Machine Vision/NAVI/navi_setting_save.xml"), XML_NAVINODE_SET_ROOT,  pXmlNode);
		if (pXmlNode)
			delete pXmlNode;
		//*/
	}

}

CXmlFile::~CXmlFile()
{
	;
}

///////////////////////////////////////
/// Load
CXmlNode* CXmlFile::Load(TCHAR* pPath, TCHAR* pszRoot)
{
	tinyxml2::XMLDocument XmlDoc;
	if (NULL == pPath || NULL == pszRoot || tinyxml2::XML_SUCCESS != XmlDoc.LoadFile(pPath))
	{
		return NULL;
	}

	tinyxml2::XMLHandle hDoc(XmlDoc);
	tinyxml2::XMLHandle hRoot = hDoc.FirstChildElement(pszRoot);
	if (FALSE == hRoot.ToNode())
	{
		return NULL;
	}

	CXmlNode* pRoot = new CXmlNode(pszRoot, NULL);

	BOOL bResult = LoadNode(hRoot, pRoot);
	if (FALSE == bResult)
	{
		delete pRoot;
		pRoot = NULL;
	}

	return pRoot;
}

BOOL CXmlFile::LoadNode(tinyxml2::XMLHandle& hParent, CXmlNode* pParentNode)
{
	if (NULL == pParentNode)
		return FALSE;

	tinyxml2::XMLHandle hNode = hParent.FirstChildElement();

	while (hNode.ToNode())
	{
		const char* pTitle = hNode.ToElement()->Name();

		CXmlNode xmlNode((LPTSTR)(LPCTSTR)pTitle, pParentNode);

		// Load Value
		const TYPE_XML_VALUE eType = CXmlFile::GetNodeValueType((LPTSTR)(LPCTSTR)pTitle);
		LoadNodeValue(hNode, xmlNode, eType);
		// Load Attribute
		LoadAttribute(hNode, xmlNode);


		// Load Child Element
		LoadNode(hNode, &xmlNode);
		pParentNode->AddNode(&xmlNode);

		hNode = hNode.NextSiblingElement();
	}

	return TRUE;
}

BOOL CXmlFile::LoadNodeValue(tinyxml2::XMLHandle& hNode, CXmlNode& xmlNode, const TYPE_XML_VALUE eType)
{
	if (TYPE_XML_VALUE_NONE == eType)
		return TRUE;

	tinyxml2::XMLElement* pXmlElement = hNode.ToElement();

	const char* pTxt = pXmlElement->GetText();
	int nTxtLen = 0;
	TCHAR* pszText = NULL;
	if (pTxt)
	{
		nTxtLen = strlen(pTxt) + 1;

		pszText = new TCHAR[nTxtLen];
		_tcscpy(pszText, pTxt);
	}
	else
	{
		nTxtLen = 1;
		pszText = new TCHAR[nTxtLen];
		_tcscpy(pszText, _T(""));
	}

	SetValue(&xmlNode, eType, pszText, nTxtLen);

	if (pszText)
	{
		delete[] pszText;
	}

	return TRUE;
}


TYPE_XML_VALUE CXmlFile::GetNodeValueType(TCHAR* pTitle)
{
	TYPE_XML_VALUE eType = TYPE_XML_VALUE_NONE;
	if (NULL == pTitle)
		return TYPE_XML_VALUE_NONE;

	// Sequence
	if (CUtil::StringCompare(pTitle, XML_NAVINODE_ROOT))				eType = TYPE_XML_VALUE_NONE;

	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_MODE))			eType = TYPE_XML_VALUE_SIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_NAME))			eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_CREATEDATE))		eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_LASTDATE))		eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_DESC))			eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_PROTECT))		eType = TYPE_XML_VALUE_NONE;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_PASSWD) || CUtil::StringCompare(pTitle, XML_NAVINODE_SET_PASSWORD) )			eType = TYPE_XML_VALUE_STRING;

	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_SEQMANAGER))		eType = TYPE_XML_VALUE_NONE;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_SEQUENCE))		eType = TYPE_XML_VALUE_NONE;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_APPLICATION))	eType = TYPE_XML_VALUE_NONE;

	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_APP_SEQINDEX))	eType = TYPE_XML_VALUE_SIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_APP_TYPE))		eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_APP_INFO))		eType = TYPE_XML_VALUE_NONE;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_APP_FILTER))		eType = TYPE_XML_VALUE_NONE;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_APP_PATH))		eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_APP_NAME))		eType = TYPE_XML_VALUE_STRING;

	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_APP_ROIREF))		eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_APP_ROICOPY))	eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_APP_SRCIMG))		eType = TYPE_XML_VALUE_STRING;

	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_APP_IMAGELIST))	eType = TYPE_XML_VALUE_NONE;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_APP_BUFFER))		eType = TYPE_XML_VALUE_BINARY;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_APP_CONFIGLIST))	eType = TYPE_XML_VALUE_NONE;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_APP_CONFIG) || CUtil::StringCompare(pTitle, XML_NAVINODE_SET_CONFIG))		eType = TYPE_XML_VALUE_STRING;
	
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_ROI_LIST))		eType = TYPE_XML_VALUE_NONE;

	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_ROI_INFO))		eType = TYPE_XML_VALUE_NONE;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_ROI_TYPE))		eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_ROI_FACE))		eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_ROI_POSITION))	eType = TYPE_XML_VALUE_NONE;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_ROI_POINTLIST))	eType = TYPE_XML_VALUE_NONE;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_ROI_POINT))		eType = TYPE_XML_VALUE_NONE;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_ROI_STEP))		eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_ROI_OPTION))		eType = TYPE_XML_VALUE_NONE;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_ROI_RING))		eType = TYPE_XML_VALUE_NONE;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_ROI_RANGE))		eType = TYPE_XML_VALUE_NONE;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_ROI_MASK))		eType = TYPE_XML_VALUE_NONE;

	// Setting
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_SET_AUTH))				eType = TYPE_XML_VALUE_NONE;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_SET_USERID))				eType = TYPE_XML_VALUE_STRING;
	

	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_SET_LICENSEINFO))		eType = TYPE_XML_VALUE_NONE;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_SET_LICENSETYPE))		eType = TYPE_XML_VALUE_SIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_SET_EXPIRATIONDATE))		eType = TYPE_XML_VALUE_STRING;

	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_SET_SETINFO))			eType = TYPE_XML_VALUE_NONE;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_SET_INSTALLPATH))		eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_SET_LASTIMAGEPATH))		eType = TYPE_XML_VALUE_STRING;

	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_SET_CONFIGPROJECT))		eType = TYPE_XML_VALUE_NONE;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_SET_INSPECTPROJECT))		eType = TYPE_XML_VALUE_NONE;
	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_SET_PROJECTPATH))		eType = TYPE_XML_VALUE_STRING;

	else if (CUtil::StringCompare(pTitle, XML_NAVINODE_SET_LASTPROJECT))		eType = TYPE_XML_VALUE_STRING;


	else if (CUtil::StringCompare(pTitle, XML_CAMERANODE_CAM_RANGE) || CUtil::StringCompare(pTitle, XML_CAMERAUSER_NODE_RANGE))			eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_CAMERANODE_CAM_MTU) || CUtil::StringCompare(pTitle, XML_CAMERAUSER_NODE_MTU))				eType = TYPE_XML_VALUE_UNSIGNED;


	
	return eType;
}

//
BOOL CXmlFile::LoadAttribute(tinyxml2::XMLHandle& hNode, CXmlNode& xmlNode)
{
	tinyxml2::XMLElement* pXmlElement = hNode.ToElement();

	const tinyxml2::XMLAttribute* pXmlAttr = pXmlElement->FirstAttribute();
	LoadNextAttribute(pXmlAttr, xmlNode);

	return TRUE;
}

BOOL CXmlFile::LoadNextAttribute(const tinyxml2::XMLAttribute* pXmlAttr, CXmlNode& xmlNode)
{
	if (NULL == pXmlAttr)
		return FALSE;

	LoadAttributeValue(pXmlAttr, xmlNode);

	const tinyxml2::XMLAttribute* pXmlAttrNext = pXmlAttr ->Next();
	LoadNextAttribute(pXmlAttrNext, xmlNode);

	return TRUE;
}

BOOL CXmlFile::LoadAttributeValue(const tinyxml2::XMLAttribute* pXmlAttr, CXmlNode& xmlNode)
{
	if (NULL == pXmlAttr)
		return FALSE;

	// Attribute Name & Value
	const char* pTitle = pXmlAttr->Name();
	const int nTxtLen = strlen(pTitle) + 1;

	const char* pValue = pXmlAttr->Value();
	const int nValueLen = strlen(pValue) + 1;

	TCHAR* pszText = new TCHAR[nTxtLen];
	_tcscpy(pszText, pTitle);

	TCHAR* pszValue = new TCHAR[nValueLen];
	_tcscpy(pszValue, pValue);

	// Parse & Add Value...
	CXmlValue xmlValue;

	const TYPE_XML_VALUE eType = GetAttributeValueType(pszText);
	BOOL bResult = SetValue(&xmlValue, eType, pszValue, nValueLen);
	if (bResult)
	{
		xmlNode.AddAttribute(pszText, &xmlValue);
	}

	if (pszText)
		delete[] pszText;

	if (pszValue)
		delete[] pszValue;

	return TRUE;
}



TYPE_XML_VALUE CXmlFile::GetAttributeValueType(TCHAR* pTitle)
{
	if (NULL == pTitle)
		return TYPE_XML_VALUE_NONE;

	TYPE_XML_VALUE eType = TYPE_XML_VALUE_NONE;

	if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_X))					eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_Y))				eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_W))				eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_H))				eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_ANGLE))			eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_MODE))			eType = TYPE_XML_VALUE_SIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_DIRECTION))		eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_SIZE))			eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_NAME))			eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_FROM))			eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_TO))			eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_COUNT))			eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_OPTION))		eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_SUPPORT))		eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_SUPPORTH))		eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_SUPPORTV))		eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_SEPARATE))		eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_UPLOAD))		eType = TYPE_XML_VALUE_STRING;	
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_TYPE))			eType = TYPE_XML_VALUE_UNSIGNED;

	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_RGB))			eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_PENSTYLE))		eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_OPACITY))		eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_HALIGN))		eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_VALIGN))		eType = TYPE_XML_VALUE_UNSIGNED;


	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_SERIALPORT) ||	CUtil::StringCompare(pTitle, XML_NAVI_ATTR_IPPORT) )	eType = TYPE_XML_VALUE_SIGNED;

	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_BAUDRATE))		eType = TYPE_XML_VALUE_SIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_DATABIT) || CUtil::StringCompare(pTitle, XML_NAVI_ATTR_CLDATABIT))		eType = TYPE_XML_VALUE_SIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_PARITY))		eType = TYPE_XML_VALUE_SIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_STOPBIT))		eType = TYPE_XML_VALUE_SIGNED;

	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_START))			eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_IP))			eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_LOCALIP))		eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_TARGETIP))		eType = TYPE_XML_VALUE_STRING;

	
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_TIMEOUT))		eType = TYPE_XML_VALUE_SIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_ENABLE))		eType = TYPE_XML_VALUE_STRING;

	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_ID))			eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_INDEX))			eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_TOTAL))			eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_PASS))			eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_FAIL))			eType = TYPE_XML_VALUE_UNSIGNED;

	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_APPFILTER_NAME))	eType = TYPE_XML_VALUE_SIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_APPFILTER_ROI))		eType = TYPE_XML_VALUE_SIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_APPFILTER_ROIEDGE))	eType = TYPE_XML_VALUE_SIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_APPFILTER_FEATURE))	eType = TYPE_XML_VALUE_SIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_APPFILTER_RESULT))	eType = TYPE_XML_VALUE_SIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_APPFILTER_IMAGE))	eType = TYPE_XML_VALUE_SIGNED;

	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_LOGGING_ENABLE))	eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_LOGGING_LIMIT))		eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_LOGGING_SINGLE))	eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_LOGGING_FLAG))		eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_LOGGING_FORMAT))	eType = TYPE_XML_VALUE_STRING;

	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_CLIMAGETAP))		eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_CLDATABIT))			eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_CLCOLORTYPE))		eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_CLCAMFILE))			eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_CLMODEL))			eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_NAVI_ATTR_CLTRIGGERMODE))		eType = TYPE_XML_VALUE_STRING;

	
	// Option...
	else if (CUtil::StringCompare(pTitle, XML_OPTIONATTR_DELAY))		eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_OPTIONATTR_COUNT))		eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_OPTIONATTR_ERATIO))		eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_OPTIONATTR_CAMERA))		eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_OPTIONATTR_MIN))			eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_OPTIONATTR_MAX))			eType = TYPE_XML_VALUE_DOUBLE;

	else if (CUtil::StringCompare(pTitle, XML_OPTIONATTR_ODD) || CUtil::StringCompare(pTitle, XML_OPTIONATTR_EVEN))		eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_OPTIONATTR_CASSETTE_COUNT))		eType = TYPE_XML_VALUE_UNSIGNED;

	else if (CUtil::StringCompare(pTitle, XML_OPTIONATTR_STEP01))			eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_OPTIONATTR_STEP02))			eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_OPTIONATTR_STEP03))			eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_OPTIONATTR_STEP04))			eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_OPTIONATTR_STEP05))			eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_OPTIONATTR_STEP06))			eType = TYPE_XML_VALUE_UNSIGNED;

	else if (CUtil::StringCompare(pTitle, XML_OPTIONATTR_STEP01_TITLE))			eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_OPTIONATTR_STEP02_TITLE))			eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_OPTIONATTR_STEP03_TITLE))			eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_OPTIONATTR_STEP04_TITLE))			eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_OPTIONATTR_STEP05_TITLE))			eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_OPTIONATTR_STEP06_TITLE))			eType = TYPE_XML_VALUE_STRING;
	

	// Sequence
	if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_STEPENABLE))				eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_STROBETYPE))				eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_STROBEBRIGHT))			eType = TYPE_XML_VALUE_SIGNED;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_IMAGEPATH))				eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_LISTCOUNT))				eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_REFIDX))					eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_ROW))						eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_COL))						eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SPACING))					eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_UNI))						eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_CALIBRATE_METHOD))		eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_CALIBRATE_IMAGEWIDTH))	eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_CALIBRATE_IMAGEHEIGHT))	eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_CALIBRATE_WIDTH))			eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_CALIBRATE_HEIGHT))		eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_CALIBRATE_PIXELUNIT))		eType = TYPE_XML_VALUE_UNSIGNED;

	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SIZEGAIN_D))				eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SIZEGAIN_L))				eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SIZEGAIN_W))				eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SIZEGAIN_I1))				eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SIZEGAIN_I2))				eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SIZEGAIN_I3))				eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SIZEGAIN_M1))				eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SIZEGAIN_M2))				eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SIZEGAIN_S1))				eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SIZEGAIN_S2))				eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SIZEGAIN_S3))				eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SIZEGAIN_S4))				eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SIZEGAIN_S5))				eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SIZEGAIN_X1))				eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SIZEGAIN_X2))				eType = TYPE_XML_VALUE_DOUBLE;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SIZEGAIN_R1))				eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SIZEGAIN_R2))				eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SIZEGAIN_R3))				eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SIZEGAIN_R4))				eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SIZEGAIN_R5))				eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SIZEGAIN_R6))				eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SIZEGAIN_SS1))			eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SIZEGAIN_SS2))			eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SIZEGAIN_SS3))			eType = TYPE_XML_VALUE_DOUBLE;


	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_WIDTH))					eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_HEIGHT))					eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_ANGLE))					eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_ANGLE_CRITERIA))			eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_POINTTYPE))				eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_POINTX))					eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_POINTY))					eType = TYPE_XML_VALUE_DOUBLE;

	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SAMPLETYPE))				eType = TYPE_XML_VALUE_STRING;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SAMPLEDIRECTION))			eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SAMPLEPOLAR))				eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SAMPLELOOKFOR))			eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SAMPLESTRTHRESHOLD))		eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SAMPLESAMPLING))			eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SAMPLEKERNELSIZE))		eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SAMPLESEARCHANGLE))		eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SAMPLEMINANGLE))			eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SAMPLEMAXANGLE))			eType = TYPE_XML_VALUE_UNSIGNED;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_SAMPLEDISTTHRESHOLD))		eType = TYPE_XML_VALUE_UNSIGNED;

	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_CAMERANUM))				eType = TYPE_XML_VALUE_SIGNED;

	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_RECT_LEFT))			eType = TYPE_XML_VALUE_SIGNED;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_RECT_TOP))			eType = TYPE_XML_VALUE_SIGNED;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_RECT_RIGHT))			eType = TYPE_XML_VALUE_SIGNED;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_RECT_BOTTOM))			eType = TYPE_XML_VALUE_SIGNED;


	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_MARSPARAM_PROBTHRES))			eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_MARSPARAM_BLOBSIZETHRES))		eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_CALIBPARAM_PIXEL2REAL))		eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_CALIBPARAM_REAL2PIXEL))		eType = TYPE_XML_VALUE_DOUBLE;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_JUDGPARAM_FAULTNUM))			eType = TYPE_XML_VALUE_SIGNED;
	else if (CUtil::StringCompare(pTitle, XML_INSPECTATTR_JUDGBPARAM_FAULTSIZE))		eType = TYPE_XML_VALUE_DOUBLE;


	return eType;
}

BOOL CXmlFile::SetValue(CXmlValue* pXmlValue, TYPE_XML_VALUE eType, TCHAR* pszText, int nTxtLen)
{
	if (NULL == pXmlValue || NULL == pszText || 1 > nTxtLen)
		return FALSE;

	if (TYPE_XML_VALUE_STRING == eType)
	{
		pXmlValue->SetValue(eType, pszText, nTxtLen * sizeof(TCHAR));
	}
	else if (TYPE_XML_VALUE_SIGNED == eType)
	{
		int nValue = CUtil::StringToInt(pszText, nTxtLen);
		pXmlValue->SetValue(eType, &nValue, sizeof(int));

	}
	else if (TYPE_XML_VALUE_UNSIGNED == eType)
	{
		DWORD dwValue = CUtil::StringToDword(pszText, nTxtLen);
		pXmlValue->SetValue(eType, &dwValue, sizeof(DWORD));

	}
	else if (TYPE_XML_VALUE_DOUBLE == eType)
	{
		double fValue = CUtil::StringToDouble(pszText, nTxtLen);
		pXmlValue->SetValue(eType, &fValue, sizeof(double));

	}
	else if (TYPE_XML_VALUE_HEX == eType)		// Hex string
	{

	}
	else if (TYPE_XML_VALUE_BINARY == eType)
	{
		pXmlValue->SetValue(eType, pszText, nTxtLen);
	}
	else
	{
		return FALSE;
	}

	return TRUE;

}



///////////////////////////////////////
/// Save
BOOL CXmlFile::Save(TCHAR* pPath, TCHAR* pszRoot, CXmlNode* pXmlNode)
{
	if (NULL == pPath || NULL == pszRoot || NULL == pXmlNode)
		return FALSE;

	tinyxml2::XMLDocument XmlDoc;
	XmlDoc.InsertEndChild(XmlDoc.NewDeclaration());

	tinyxml2::XMLElement* pRootElement = XmlDoc.NewElement(pszRoot);
	XmlDoc.LinkEndChild(pRootElement);
		
	BOOL bResult = SaveNode(XmlDoc, pRootElement, pXmlNode);
	if (bResult)
	{
		tinyxml2::XMLError error = XmlDoc.SaveFile(pPath);
		if (tinyxml2::XML_SUCCESS == error)
			bResult = TRUE;
		else
			bResult = FALSE;
	}

	return bResult;
}

BOOL CXmlFile::SaveNode(tinyxml2::XMLDocument& XmlDoc, tinyxml2::XMLElement* pElement, CXmlNode* pXmlNode)
{
	if (NULL == pElement || NULL == pXmlNode)
		return FALSE;

	// Attribute
	const int nAttrCount = pXmlNode->GetAttributeCount();
	for (int i = 0; i < nAttrCount; i++)
	{
		CXmlAttribute* pXmlAttr = pXmlNode->GetAttribute(i);
		SetAttributeValue(pElement, pXmlAttr);
	}

	// Value
	SetNodeValue(XmlDoc, pElement, pXmlNode);


	// Element
	const int nNodeCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nNodeCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);

		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		const int nTitleLen = CUtil::StringLength((LPTSTR)(LPCTSTR)pTitle) + 1;

		if (pTitle && 1 < nTitleLen)
		{
			char* pszNew = new char[nTitleLen];
			strcpy(pszNew, pTitle);

			tinyxml2::XMLElement* pChildElement = XmlDoc.NewElement(pszNew);

			SaveNode(XmlDoc, pChildElement, pChildNode);
			pElement->LinkEndChild(pChildElement);

			delete[] pszNew;
		}
	}

	return TRUE;
}


BOOL CXmlFile::SetNodeValue(tinyxml2::XMLDocument& XmlDoc, tinyxml2::XMLElement* pElement, CXmlNode* pXmlNode)
{
	if (NULL == pElement || NULL == pXmlNode)
		return FALSE;

	const TYPE_XML_VALUE eType = pXmlNode->GetValueType();

	const int nValueLen = pXmlNode->GetValue(NULL, 0);

	if (TYPE_XML_VALUE_STRING == eType)
	{
		TCHAR* pString = new TCHAR[nValueLen + 1];
		pXmlNode->GetValue(pString, nValueLen + 1);

		char* pValue = new char[nValueLen + 1];
		strcpy(pValue, pString);
	
		tinyxml2::XMLText* pTxtName = XmlDoc.NewText(pValue);

		if (pString)
			delete[] pString;
		if (pValue)
			delete[] pValue;

		pElement->LinkEndChild(pTxtName);

	}
	else if (TYPE_XML_VALUE_SIGNED == eType)
	{
		int nValue = 0;
		pXmlNode->GetValue(&nValue, sizeof(int));

		pElement->SetText(nValue);
	}
	else if (TYPE_XML_VALUE_UNSIGNED == eType)
	{
		DWORD dwValue = 0;
		pXmlNode->GetValue(&dwValue, sizeof(DWORD));

		unsigned int nValue = dwValue;
		pElement->SetText(nValue);
	}
	else if (TYPE_XML_VALUE_DOUBLE == eType)
	{
		double fValue = 0;
		pXmlNode->GetValue(&fValue, sizeof(double));

		pElement->SetText(fValue);

	}
	else if (TYPE_XML_VALUE_HEX == eType)
	{
	}
	else if (TYPE_XML_VALUE_BINARY == eType)
	{
		char* pValue = new char[nValueLen + 1];
		memset(pValue, 0x00, nValueLen + 1);

		pXmlNode->GetValue(pValue, nValueLen + 1);
		tinyxml2::XMLText* pTxtName = XmlDoc.NewText(pValue);

		if (pValue)
			delete[] pValue;

		pElement->LinkEndChild(pTxtName);
	}
	else
	{
		return FALSE;
	}
	return TRUE;

}


BOOL CXmlFile::SetAttributeValue(tinyxml2::XMLElement* pElement, CXmlAttribute* pXmlAttr)
{
	if (NULL == pElement || NULL == pXmlAttr)
		return FALSE;

	const TCHAR* pTitle = pXmlAttr->GetTitle();
	if (NULL == pTitle)
		return FALSE;
	
	const int nTitleLen = CUtil::StringLength((LPTSTR)(LPCTSTR)pTitle) + 1;
	const int nValueLen = pXmlAttr->GetValue(NULL, 0);

	if (1 > nTitleLen || 1 > nValueLen)
		return FALSE;

	char* pName = new char[nTitleLen];
	strcpy(pName, pTitle);

	const TYPE_XML_VALUE eType = pXmlAttr->GetValueType();
	if (TYPE_XML_VALUE_STRING == eType)
	{
		TCHAR* pString = new TCHAR[nValueLen+1];
		pXmlAttr->GetValue(pString, nValueLen + 1);

		char* pValue = new char[nValueLen + 1];
		strcpy(pValue, pString);		

		pElement->SetAttribute(pName, pValue);

		if (pString)
			delete[] pString;
		if (pValue)
			delete[] pValue;
	}
	else if (TYPE_XML_VALUE_SIGNED == eType)
	{
		int nValue = 0;
		pXmlAttr->GetValue(&nValue, sizeof(int));

		pElement->SetAttribute(pName, nValue);

	}
	else if (TYPE_XML_VALUE_UNSIGNED == eType)
	{
		DWORD dwValue = 0;
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));

		unsigned int nValue = dwValue;
		pElement->SetAttribute(pName, nValue);

	}
	else if (TYPE_XML_VALUE_DOUBLE == eType)
	{
		double fValue = 0;
		pXmlAttr->GetValue(&fValue, sizeof(double));

		pElement->SetAttribute(pName, fValue);

	}
	else if (TYPE_XML_VALUE_HEX == eType)		// Hex string
	{

	}
	else if (TYPE_XML_VALUE_BINARY == eType)
	{

	}

	if (pName)
		delete[] pName;

	return TRUE;
	
}