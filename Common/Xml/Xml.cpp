#include "StdAfx.h"
#include "Xml.h"

#include "Xml/XmlFile.h"
#include "Util/Util.h"

CXml::CXml()
{
	/*//
	stSequenceManager* pSeqManager = CXml::Load(_T("E:/Work/Machine Vision/NAVI/Navi.xml"));
	CXml::Save(_T("E:/Work/Machine Vision/NAVI/Navi_save.xml"), pSeqManager);

	std::list<stSequence*>::iterator itor;
	for (itor = pSeqManager->m_listSequence.begin(); itor != pSeqManager->m_listSequence.end(); itor++)
	{
		stSequence* pSeq = *itor;
		std::list<stApplication*>::iterator itorApp;
		for (itorApp = pSeq->m_listImageBuffer.begin(); itorApp != pSeq->m_listImageBuffer.end(); itorApp++)
		{
			stApplication* pApp = *itorApp;
			delete pApp;
		}

		delete pSeq;
	}
	pSeqManager->m_listSequence.clear();
	delete pSeqManager;
	//*/

	/*//
	stProgramSetting* pSetting = CXml::LoadSetting(_T("E:/Work/Machine Vision/NAVI/navi_setting.xml"));
	CXml::SaveSetting(_T("E:/Work/Machine Vision/NAVI/navi_setting_save.xml"), pSetting);

	pSetting->m_vtConfigRecentsProjectFilesList.clear();
	pSetting->m_vtInspectRecentsProjectFilesList.clear();

	delete pSetting;
	//*/

	//CXmlFile xmlFile;
}

CXml::~CXml()
{
}


#ifdef DEF_LPAPP
///////////////////////////////////////////////
// User Config.
BOOL CXml::LoadUserConfig(TCHAR* pszPath, CUserConfig& UserConfig)
{
	if (NULL == pszPath)
		return FALSE;

	BOOL bResult = FALSE;

	CXmlFile xmlFile;
	CXmlNode* pXmlNode = xmlFile.Load(pszPath, XML_USERNODE_ROOT);

	if (pXmlNode)
	{
		bResult = LoadXml(UserConfig, pXmlNode);
		delete pXmlNode;
	}

	return bResult;
}

BOOL CXml::SaveUserConfig(TCHAR* pszPath, CUserConfig& UserConfig)
{
	if (NULL == pszPath)
		return FALSE;

	CXmlNode* pXmlNode = SaveXml(UserConfig);

	BOOL bResult = FALSE;
	if (pXmlNode)
	{
		CXmlFile xmlFile;
		bResult = xmlFile.Save(pszPath, XML_USERNODE_ROOT, pXmlNode);

		if (pXmlNode)
			delete pXmlNode;
	}
	else
	{
		return FALSE;
	}

	return TRUE;
}

BOOL CXml::LoadXml(CUserConfig& UserConfig, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		const int nValueLen = pChildNode->GetValue(0, NULL);

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_USERNODE_OUTPUTCONFIGLIST))
		{
			LoadOutputConfigList(UserConfig, pChildNode);
		}
	}

	return TRUE;
}


BOOL CXml::LoadOutputConfigList(CUserConfig& UserConfig, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		const int nValueLen = pChildNode->GetValue(0, NULL);

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_USERNODE_OUTPUTCONFIG))
		{
			TYPE_OUTPUT eOutput = TYPE_OUTPUT_NONE;

			TCHAR szName[MAX_NAME_LEN] = { 0, };

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_NAME);
			if (pXmlAttr)
				pXmlAttr->GetValue(szName, MAX_NAME_LEN);

			if (CUtil::StringCompare(XML_OUTPUTCONFIG_APPNAME, szName))				eOutput = TYPE_OUTPUT_APPNAME;
			else if (CUtil::StringCompare(XML_OUTPUTCONFIG_LABEL, szName))			eOutput = TYPE_OUTPUT_LABEL;
			else if (CUtil::StringCompare(XML_OUTPUTCONFIG_TEXT, szName))			eOutput = TYPE_OUTPUT_TEXT;
			else if (CUtil::StringCompare(XML_OUTPUTCONFIG_RECT, szName))			eOutput = TYPE_OUTPUT_RECT;
			else if (CUtil::StringCompare(XML_OUTPUTCONFIG_CIRCLE, szName))			eOutput = TYPE_OUTPUT_CIRCLE;
			else if (CUtil::StringCompare(XML_OUTPUTCONFIG_LINE, szName))			eOutput = TYPE_OUTPUT_LINE;
			else if (CUtil::StringCompare(XML_OUTPUTCONFIG_ARROW, szName))			eOutput = TYPE_OUTPUT_ARROW;
			else if (CUtil::StringCompare(XML_OUTPUTCONFIG_POINT, szName))			eOutput = TYPE_OUTPUT_POINT;
			else if (CUtil::StringCompare(XML_OUTPUTCONFIG_IMAGE, szName))			eOutput = TYPE_OUTPUT_IMAGE;
			else if (CUtil::StringCompare(XML_OUTPUTCONFIG_MASKIMG, szName))		eOutput = TYPE_OUTPUT_MASKIMG;
			else if (CUtil::StringCompare(XML_OUTPUTCONFIG_ROI, szName))			eOutput = TYPE_OUTPUT_ROI;
			else if (CUtil::StringCompare(XML_OUTPUTCONFIG_ROIEDGGE, szName))		eOutput = TYPE_OUTPUT_ROIEDGE;
			else if (CUtil::StringCompare(XML_OUTPUTCONFIG_RESULT, szName))			eOutput = TYPE_OUTPUT_RESULT;
			else if (CUtil::StringCompare(XML_OUTPUTCONFIG_FILTERFEATURE, szName))	eOutput = TYPE_OUTPUT_FILTER_FEATURE;
			else if (CUtil::StringCompare(XML_OUTPUTCONFIG_FILTERRESULT, szName))	eOutput = TYPE_OUTPUT_FILTER_RESULT;

			// Name...
			INFO_OUTPUTCONFIG* pstConfig = UserConfig.GetVideoOutputConfig(eOutput);
			if (pstConfig)
				LoadOutputConfig(*pstConfig, pChildNode);
		}
	}

	return TRUE;
}

BOOL CXml::LoadOutputConfig(INFO_OUTPUTCONFIG& stConfig, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		const int nValueLen = pChildNode->GetValue(0, NULL);

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_USERNODE_OUTPUTTEXT))
			LoadOutputText(stConfig.m_stTextConfig, pChildNode);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_USERNODE_OUTPUTPEN))
			LoadOutputPen(stConfig.m_stPenConfig, pChildNode);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_USERNODE_OUTPUTBRUSH))
			LoadOutputBrush(stConfig.m_stBrushConfig, pChildNode);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_USERNODE_OUTPUTOPTION))
			LoadOutputOption(stConfig, pChildNode);

	}

	return TRUE;
}


BOOL CXml::LoadOutputText(INFO_OUTPUTTEXT& stText, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	TCHAR szTxt[MAX_NAME_LEN] = { 0, };
	DWORD dwValue = 0;

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_NAME);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(szTxt, MAX_NAME_LEN);
		CUtil::StringCopy(stText.m_stLogFont.lfFaceName, szTxt);
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SIZE);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
		stText.m_stLogFont.lfHeight = dwValue;
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_RGB);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
		stText.m_rgbText = dwValue;
	}
	return TRUE;
}

BOOL CXml::LoadOutputPen(INFO_OUTPUTPEN& stPen, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;
	DWORD dwValue = 0;

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_PENSTYLE);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
		stPen.m_nStyle = dwValue;
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_RGB);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
		stPen.m_rgbPen = dwValue;
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SIZE);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
		stPen.m_nWeight = dwValue;
	}


	return TRUE;
}

BOOL CXml::LoadOutputBrush(INFO_OUTPUTBRUSH& stBrush, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;
	DWORD dwValue = 0;

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_RGB);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
		stBrush.m_rgbBrush = dwValue;
	}

	return TRUE;
}

BOOL CXml::LoadOutputOption(INFO_OUTPUTCONFIG& stConfig, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;
	DWORD dwValue = 0;

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_OPACITY);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
		stConfig.m_nOpacity = dwValue;
	}


	// Align
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_HALIGN);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
		stConfig.m_eHAlign = (TYPE_OUTPUT_HALIGN)dwValue;
	}
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_VALIGN);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
		stConfig.m_eVAlign = (TYPE_OUTPUT_VALIGN)dwValue;
	}

	return TRUE;
}




CXmlNode* CXml::SaveXml(CUserConfig& UserConfig)
{
	CXmlNode* pXmlNode = new CXmlNode(XML_USERNODE_ROOT, NULL);

	CXmlNode* pNode = SaveOutputConfigList(pXmlNode, UserConfig);
	pXmlNode->AddNode(pNode);	delete pNode;

	return pXmlNode;
}

CXmlNode* CXml::SaveOutputConfigList(CXmlNode* pParentNode, CUserConfig& UserConfig)
{
	if (NULL == pParentNode)
		return NULL;

	CXmlNode* pConfigListNode = CreateNode(pParentNode, XML_USERNODE_OUTPUTCONFIGLIST, TYPE_XML_VALUE_NONE, NULL, 0);

	CXmlNode* pNode = NULL;


	INFO_OUTPUTCONFIG* pstConfig = NULL;
	pstConfig = UserConfig.GetVideoOutputConfig(TYPE_OUTPUT_APPNAME);
	if (pstConfig)
	{
		pNode = SaveOutputConfig(pConfigListNode, TYPE_OUTPUT_APPNAME, *pstConfig);
		pConfigListNode->AddNode(pNode);	delete pNode;
	}

	pstConfig = UserConfig.GetVideoOutputConfig(TYPE_OUTPUT_LABEL);
	if (pstConfig)
	{
		pNode = SaveOutputConfig(pConfigListNode, TYPE_OUTPUT_LABEL, *pstConfig);
		pConfigListNode->AddNode(pNode);	delete pNode;
	}

	pstConfig = UserConfig.GetVideoOutputConfig(TYPE_OUTPUT_TEXT);
	if (pstConfig)
	{
		pNode = SaveOutputConfig(pConfigListNode, TYPE_OUTPUT_TEXT, *pstConfig);
		pConfigListNode->AddNode(pNode);	delete pNode;
	}

	pstConfig = UserConfig.GetVideoOutputConfig(TYPE_OUTPUT_RECT);
	if (pstConfig)
	{
		pNode = SaveOutputConfig(pConfigListNode, TYPE_OUTPUT_RECT, *pstConfig);
		pConfigListNode->AddNode(pNode);	delete pNode;
	}

	pstConfig = UserConfig.GetVideoOutputConfig(TYPE_OUTPUT_CIRCLE);
	if (pstConfig)
	{
		pNode = SaveOutputConfig(pConfigListNode, TYPE_OUTPUT_CIRCLE, *pstConfig);
		pConfigListNode->AddNode(pNode);	delete pNode;
	}

	pstConfig = UserConfig.GetVideoOutputConfig(TYPE_OUTPUT_LINE);
	if (pstConfig)
	{
		pNode = SaveOutputConfig(pConfigListNode, TYPE_OUTPUT_LINE, *pstConfig);
		pConfigListNode->AddNode(pNode);	delete pNode;
	}

	pstConfig = UserConfig.GetVideoOutputConfig(TYPE_OUTPUT_ARROW);
	if (pstConfig)
	{
		pNode = SaveOutputConfig(pConfigListNode, TYPE_OUTPUT_ARROW, *pstConfig);
		pConfigListNode->AddNode(pNode);	delete pNode;
	}

	pstConfig = UserConfig.GetVideoOutputConfig(TYPE_OUTPUT_POINT);
	if (pstConfig)
	{
		pNode = SaveOutputConfig(pConfigListNode, TYPE_OUTPUT_POINT, *pstConfig);
		pConfigListNode->AddNode(pNode);	delete pNode;
	}

	pstConfig = UserConfig.GetVideoOutputConfig(TYPE_OUTPUT_IMAGE);
	if (pstConfig)
	{
		pNode = SaveOutputConfig(pConfigListNode, TYPE_OUTPUT_IMAGE, *pstConfig);
		pConfigListNode->AddNode(pNode);	delete pNode;
	}

	pstConfig = UserConfig.GetVideoOutputConfig(TYPE_OUTPUT_MASKIMG);
	if (pstConfig)
	{
		pNode = SaveOutputConfig(pConfigListNode, TYPE_OUTPUT_MASKIMG, *pstConfig);
		pConfigListNode->AddNode(pNode);	delete pNode;
	}

	pstConfig = UserConfig.GetVideoOutputConfig(TYPE_OUTPUT_ROI);
	if (pstConfig)
	{
		pNode = SaveOutputConfig(pConfigListNode, TYPE_OUTPUT_ROI, *pstConfig);
		pConfigListNode->AddNode(pNode);	delete pNode;
	}

	pstConfig = UserConfig.GetVideoOutputConfig(TYPE_OUTPUT_ROIEDGE);
	if (pstConfig)
	{
		pNode = SaveOutputConfig(pConfigListNode, TYPE_OUTPUT_ROIEDGE, *pstConfig);
		pConfigListNode->AddNode(pNode);	delete pNode;
	}

	pstConfig = UserConfig.GetVideoOutputConfig(TYPE_OUTPUT_RESULT);
	if (pstConfig)
	{
		pNode = SaveOutputConfig(pConfigListNode, TYPE_OUTPUT_RESULT, *pstConfig);
		pConfigListNode->AddNode(pNode);	delete pNode;
	}

	pstConfig = UserConfig.GetVideoOutputConfig(TYPE_OUTPUT_FILTER_FEATURE);
	if (pstConfig)
	{
		pNode = SaveOutputConfig(pConfigListNode, TYPE_OUTPUT_FILTER_FEATURE, *pstConfig);
		pConfigListNode->AddNode(pNode);	delete pNode;
	}

	pstConfig = UserConfig.GetVideoOutputConfig(TYPE_OUTPUT_FILTER_RESULT);
	if (pstConfig)
	{
		pNode = SaveOutputConfig(pConfigListNode, TYPE_OUTPUT_FILTER_RESULT, *pstConfig);
		pConfigListNode->AddNode(pNode);	delete pNode;
	}

	return pConfigListNode;

}


CXmlNode* CXml::SaveOutputConfig(CXmlNode* pParentNode, TYPE_OUTPUT eType, INFO_OUTPUTCONFIG& stConfig)
{
	if (NULL == pParentNode)
		return NULL;

	CXmlNode* pConfigNode = CreateNode(pParentNode, XML_USERNODE_OUTPUTCONFIG, TYPE_XML_VALUE_NONE, NULL, 0);

	CXmlNode* pNode = NULL;

	pNode = SaveOutputText(pConfigNode, stConfig.m_stTextConfig);
	pConfigNode->AddNode(pNode);	delete pNode;

	pNode = SaveOutputPen(pConfigNode, stConfig.m_stPenConfig);
	pConfigNode->AddNode(pNode);	delete pNode;

	pNode = SaveOutputBrush(pConfigNode, stConfig.m_stBrushConfig);
	pConfigNode->AddNode(pNode);	delete pNode;

	pNode = SaveOutputOption(pConfigNode, stConfig);
	pConfigNode->AddNode(pNode);	delete pNode;

	if (TYPE_OUTPUT_APPNAME == eType)				AddAttributeString(pConfigNode, XML_NAVI_ATTR_NAME, XML_OUTPUTCONFIG_APPNAME);
	else if (TYPE_OUTPUT_LABEL == eType)			AddAttributeString(pConfigNode, XML_NAVI_ATTR_NAME, XML_OUTPUTCONFIG_LABEL);
	else if (TYPE_OUTPUT_TEXT == eType)				AddAttributeString(pConfigNode, XML_NAVI_ATTR_NAME, XML_OUTPUTCONFIG_TEXT);
	else if (TYPE_OUTPUT_RECT == eType)				AddAttributeString(pConfigNode, XML_NAVI_ATTR_NAME, XML_OUTPUTCONFIG_RECT);
	else if (TYPE_OUTPUT_CIRCLE == eType)			AddAttributeString(pConfigNode, XML_NAVI_ATTR_NAME, XML_OUTPUTCONFIG_CIRCLE);
	else if (TYPE_OUTPUT_LINE == eType)				AddAttributeString(pConfigNode, XML_NAVI_ATTR_NAME, XML_OUTPUTCONFIG_LINE);
	else if (TYPE_OUTPUT_ARROW == eType)			AddAttributeString(pConfigNode, XML_NAVI_ATTR_NAME, XML_OUTPUTCONFIG_ARROW);
	else if (TYPE_OUTPUT_POINT == eType)			AddAttributeString(pConfigNode, XML_NAVI_ATTR_NAME, XML_OUTPUTCONFIG_POINT);
	else if (TYPE_OUTPUT_IMAGE == eType)			AddAttributeString(pConfigNode, XML_NAVI_ATTR_NAME, XML_OUTPUTCONFIG_IMAGE);
	else if (TYPE_OUTPUT_MASKIMG == eType)			AddAttributeString(pConfigNode, XML_NAVI_ATTR_NAME, XML_OUTPUTCONFIG_MASKIMG);
	else if (TYPE_OUTPUT_ROI == eType)				AddAttributeString(pConfigNode, XML_NAVI_ATTR_NAME, XML_OUTPUTCONFIG_ROI);
	else if (TYPE_OUTPUT_ROIEDGE == eType)			AddAttributeString(pConfigNode, XML_NAVI_ATTR_NAME, XML_OUTPUTCONFIG_ROIEDGGE);
	else if (TYPE_OUTPUT_RESULT == eType)			AddAttributeString(pConfigNode, XML_NAVI_ATTR_NAME, XML_OUTPUTCONFIG_RESULT);
	else if (TYPE_OUTPUT_FILTER_FEATURE == eType)	AddAttributeString(pConfigNode, XML_NAVI_ATTR_NAME, XML_OUTPUTCONFIG_FILTERFEATURE);
	else if (TYPE_OUTPUT_FILTER_RESULT == eType)	AddAttributeString(pConfigNode, XML_NAVI_ATTR_NAME, XML_OUTPUTCONFIG_FILTERRESULT);


	return pConfigNode;
}


CXmlNode* CXml::SaveOutputText(CXmlNode* pParentNode, INFO_OUTPUTTEXT& stText)
{
	if (NULL == pParentNode)
		return NULL;

	CXmlNode* pTextNode = CreateNode(pParentNode, XML_USERNODE_OUTPUTTEXT, TYPE_XML_VALUE_NONE, NULL, 0);

	AddAttributeString(pTextNode, XML_NAVI_ATTR_NAME, stText.m_stLogFont.lfFaceName);
	AddAttributeUnsignedInt(pTextNode, XML_NAVI_ATTR_SIZE, stText.m_stLogFont.lfHeight);
	AddAttributeUnsignedInt(pTextNode, XML_NAVI_ATTR_RGB, stText.m_rgbText);


	return pTextNode;
}

CXmlNode* CXml::SaveOutputPen(CXmlNode* pParentNode, INFO_OUTPUTPEN& stPen)
{
	if (NULL == pParentNode)
		return NULL;

	CXmlNode* pPenNode = CreateNode(pParentNode, XML_USERNODE_OUTPUTPEN, TYPE_XML_VALUE_NONE, NULL, 0);

	AddAttributeUnsignedInt(pPenNode, XML_NAVI_ATTR_RGB, stPen.m_rgbPen);
	AddAttributeUnsignedInt(pPenNode, XML_NAVI_ATTR_PENSTYLE, stPen.m_nStyle);
	AddAttributeUnsignedInt(pPenNode, XML_NAVI_ATTR_SIZE, stPen.m_nWeight);

	return pPenNode;
}

CXmlNode* CXml::SaveOutputBrush(CXmlNode* pParentNode, INFO_OUTPUTBRUSH& stBrush)
{
	if (NULL == pParentNode)
		return NULL;

	CXmlNode* pBrushNode = CreateNode(pParentNode, XML_USERNODE_OUTPUTBRUSH, TYPE_XML_VALUE_NONE, NULL, 0);

	AddAttributeUnsignedInt(pBrushNode, XML_NAVI_ATTR_RGB, stBrush.m_rgbBrush);

	return pBrushNode;
}

CXmlNode* CXml::SaveOutputOption(CXmlNode* pParentNode, INFO_OUTPUTCONFIG& stConfig)
{
	if (NULL == pParentNode)
		return NULL;

	CXmlNode* pOptionNode = CreateNode(pParentNode, XML_USERNODE_OUTPUTOPTION, TYPE_XML_VALUE_NONE, NULL, 0);

	AddAttributeUnsignedInt(pOptionNode, XML_NAVI_ATTR_OPACITY, stConfig.m_nOpacity);
	AddAttributeUnsignedInt(pOptionNode, XML_NAVI_ATTR_HALIGN, stConfig.m_eHAlign);
	AddAttributeUnsignedInt(pOptionNode, XML_NAVI_ATTR_VALIGN, stConfig.m_eVAlign);


	return pOptionNode;
}




////////////////////////////////////////////////////////////////////
// Stat SequenceManager
stStat_SequenceManager* CXml::LoadStat(TCHAR* pszPath)
{
	if (NULL == pszPath)
		return NULL;

	stStat_SequenceManager* pstStat = NULL;

	CXmlFile xmlFile;
	CXmlNode* pXmlNode = xmlFile.Load(pszPath, XML_NAVINDE_STAT_ROOT);

	if (pXmlNode)
	{
		pstStat = new stStat_SequenceManager;
		LoadXml(pstStat, pXmlNode);

		delete pXmlNode;
	}
	return pstStat;
}

BOOL CXml::LoadXml(stStat_SequenceManager* pstStat, CXmlNode* pXmlNode)
{
	if (NULL == pstStat || NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		const int nValueLen = pChildNode->GetValue(0, NULL);

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINDE_STAT_SEQUENCE))
		{
			stStat_Sequence* pSeqStat = new stStat_Sequence;

			BOOL bResult = LoadStatSequence(pChildNode, *pSeqStat);
			if (bResult)
				pstStat->listSequence.push_back(pSeqStat);
			else
				delete pSeqStat;
		}
	}

	return TRUE;
}


BOOL CXml::LoadStatSequence(CXmlNode* pXmlNode, stStat_Sequence& stStatSeq)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		const int nValueLen = pChildNode->GetValue(0, NULL);

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINDE_STAT_APPLICATION))
		{
			stStat_Application* pAppStat = new stStat_Application;
			BOOL bResult = LoadStatApplication(pChildNode, *pAppStat);
			if (bResult)
				stStatSeq.listApplication.push_back(pAppStat);
			else
				delete pAppStat;

		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINDE_STAT_SEQSTAT))
		{
			LoadStatSeqStat(pChildNode, stStatSeq);
		}
	}

	TCHAR szTxt[MAX_NAME_LEN] = { 0, };

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_ID);
	if (pXmlAttr)
		pXmlAttr->GetValue(szTxt, MAX_NAME_LEN);
	stStatSeq.strSeqID = szTxt;

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_NAME);
	if (pXmlAttr)
		pXmlAttr->GetValue(szTxt, MAX_NAME_LEN);
	stStatSeq.strSeqName = szTxt;

	return TRUE;
}

BOOL CXml::LoadStatSeqStat(CXmlNode* pXmlNode, stStat_Sequence& stStatSeq)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;
	DWORD dwValue = 0;

	//
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_TOTAL);
	if (pXmlAttr)
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
	else
		dwValue = 0;
	stStatSeq.nSeqTotalCount = dwValue;

	//
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_PASS);
	if (pXmlAttr)
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
	else
		dwValue = 0;
	stStatSeq.nSeqPassCount = dwValue;

	//
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_FAIL);
	if (pXmlAttr)
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
	else
		dwValue = 0;
	stStatSeq.nSeqFailCount = dwValue;

	return TRUE;
}

BOOL CXml::LoadStatApplication(CXmlNode* pXmlNode, stStat_Application& stStatApp)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;
	DWORD dwValue = 0;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		const int nValueLen = pChildNode->GetValue(0, NULL);

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINDE_STAT_APPSTAT))
		{
			LoadStatAppStat(pChildNode, stStatApp);
		}
	}



	TCHAR szTxt[MAX_NAME_LEN] = { 0, };

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_NAME);
	if (pXmlAttr)
		pXmlAttr->GetValue(szTxt, MAX_NAME_LEN);
	stStatApp.strAppName = szTxt;


	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_INDEX);
	if (pXmlAttr)
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
	else
		dwValue = 0;
	stStatApp.nSequenceindex = dwValue;

	return TRUE;
}

BOOL CXml::LoadStatAppStat(CXmlNode* pXmlNode, stStat_Application& stStatApp)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;
	DWORD dwValue = 0;

	//
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_TOTAL);
	if (pXmlAttr)
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
	else
		dwValue = 0;
	stStatApp.nTotalCount = dwValue;

	//
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_PASS);
	if (pXmlAttr)
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
	else
		dwValue = 0;
	stStatApp.nPassCount = dwValue;

	//
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_FAIL);
	if (pXmlAttr)
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
	else
		dwValue = 0;
	stStatApp.nFailCount = dwValue;

	return TRUE;
}



BOOL CXml::SaveStat(TCHAR* pszPath, stStat_SequenceManager* pstStat)
{
	if (NULL == pszPath || NULL == pstStat)
		return FALSE;

	CXmlNode* pXmlNode = SaveXml(pstStat);

	if (pXmlNode)
	{
		CXmlFile xmlFile;
		xmlFile.Save(pszPath, XML_NAVINDE_STAT_ROOT, pXmlNode);

		if (pXmlNode)
			delete pXmlNode;
	}
	else
	{
		return FALSE;
	}

	return TRUE;
}

CXmlNode* CXml::SaveXml(stStat_SequenceManager* pstStat)
{
	if (NULL == pstStat)
		return NULL;

	CXmlNode* pXmlNode = new CXmlNode(XML_NAVINDE_STAT_ROOT, NULL);

	CXmlNode* pNode = NULL;

	std::list<stStat_Sequence*>::iterator iter;
	for (iter = pstStat->listSequence.begin(); iter != pstStat->listSequence.end(); ++iter)
	{
		stStat_Sequence* pStat = *iter;

		pNode = SaveStatSequence(pXmlNode, *pStat);
		pXmlNode->AddNode(pNode);	delete pNode;
	}


	return pXmlNode;
}


CXmlNode* CXml::SaveStatSequence(CXmlNode* pParentNode, stStat_Sequence& stStatSeq)
{
	if (NULL == pParentNode)
		return NULL;

	CXmlNode* pSeqNode = CreateNode(pParentNode, XML_NAVINDE_STAT_SEQUENCE, TYPE_XML_VALUE_NONE, NULL, 0);

	CXmlNode* pNode = NULL;

	pNode = SaveStatSeqStat(pSeqNode, stStatSeq);
	pSeqNode->AddNode(pNode);	delete pNode;

	AddAttributeString(pSeqNode, XML_NAVI_ATTR_ID, stStatSeq.strSeqID);
	AddAttributeString(pSeqNode, XML_NAVI_ATTR_NAME, stStatSeq.strSeqName);


	// Application...
	std::list<stStat_Application*>::iterator iter;
	for (iter = stStatSeq.listApplication.begin(); iter != stStatSeq.listApplication.end(); ++iter)
	{
		stStat_Application* pStat = *iter;

		pNode = SaveStatAppliction(pSeqNode, *pStat);
		pSeqNode->AddNode(pNode);	delete pNode;
	}

	return pSeqNode;
}

CXmlNode* CXml::SaveStatSeqStat(CXmlNode* pParentNode, stStat_Sequence& stStatSeq)
{
	if (NULL == pParentNode)
		return NULL;

	CXmlNode* pStatNode = CreateNode(pParentNode, XML_NAVINDE_STAT_SEQSTAT, TYPE_XML_VALUE_NONE, NULL, 0);
	
	AddAttributeUnsignedInt(pStatNode, XML_NAVI_ATTR_TOTAL, stStatSeq.nSeqTotalCount);
	AddAttributeUnsignedInt(pStatNode, XML_NAVI_ATTR_PASS, stStatSeq.nSeqPassCount);
	AddAttributeUnsignedInt(pStatNode, XML_NAVI_ATTR_FAIL, stStatSeq.nSeqFailCount);

	return pStatNode;
}

CXmlNode* CXml::SaveStatAppliction(CXmlNode* pParentNode, stStat_Application& stAppStat)
{
	if (NULL == pParentNode)
		return NULL;

	CXmlNode* pAppNode = CreateNode(pParentNode, XML_NAVINDE_STAT_APPLICATION, TYPE_XML_VALUE_NONE, NULL, 0);

	CXmlNode* pNode = NULL;

	pNode = SaveStatAppStat(pAppNode, stAppStat);
	pAppNode->AddNode(pNode);	delete pNode;

	AddAttributeUnsignedInt(pAppNode, XML_NAVI_ATTR_INDEX, stAppStat.nSequenceindex);
	AddAttributeString(pAppNode, XML_NAVI_ATTR_NAME, stAppStat.strAppName);

	return pAppNode;
}

CXmlNode* CXml::SaveStatAppStat(CXmlNode* pParentNode, stStat_Application& stAppStat)
{
	if (NULL == pParentNode)
		return NULL;

	CXmlNode* pStatNode = CreateNode(pParentNode, XML_NAVINDE_STAT_APPSTAT, TYPE_XML_VALUE_NONE, NULL, 0);

	AddAttributeUnsignedInt(pStatNode, XML_NAVI_ATTR_TOTAL, stAppStat.nTotalCount);
	AddAttributeUnsignedInt(pStatNode, XML_NAVI_ATTR_PASS, stAppStat.nPassCount);
	AddAttributeUnsignedInt(pStatNode, XML_NAVI_ATTR_FAIL, stAppStat.nFailCount);

	return pStatNode;
}


////////////////////////////////////////////////////////////////////
// ProgramSetting
stProgramSetting* CXml::LoadSetting(TCHAR* pszPath)
{
	if (NULL == pszPath)
		return NULL;

	stProgramSetting* pstSetting = NULL;

	CXmlFile xmlFile;
	CXmlNode* pXmlNode = xmlFile.Load(pszPath, XML_NAVINODE_SET_ROOT);

	if (pXmlNode)
	{
		pstSetting = new stProgramSetting;
		LoadXml(pstSetting, pXmlNode);

		delete pXmlNode;
	}
	return pstSetting;
}

BOOL CXml::SaveSetting(TCHAR* pszPath, stProgramSetting* pstSetting)
{
	if (NULL == pszPath || NULL == pstSetting)
		return NULL;

	CXmlNode* pXmlNode = SaveXml(pstSetting);

	if (pXmlNode)
	{
		CXmlFile xmlFile;
		xmlFile.Save(pszPath, XML_NAVINODE_SET_ROOT, pXmlNode);

		if (pXmlNode)
			delete pXmlNode;
	}
	else
	{
		return FALSE;
	}

	return TRUE;
}



//
BOOL CXml::LoadXml(stProgramSetting* pstSetting, CXmlNode* pXmlNode)
{
	if (NULL == pstSetting || NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		const int nValueLen = pChildNode->GetValue(0, NULL);

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_AUTH))
		{
			LoadSettingAuth(pChildNode, *pstSetting);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_LICENSEINFO))
		{
			LoadSettingLicense(pChildNode, *pstSetting);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_SETINFO))
		{
			LoadSettingPath(pChildNode, *pstSetting);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_CONFIGPROJECT))
		{
			LoadSettingConfigProject(pChildNode, *pstSetting);;
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_INSPECTPROJECT))
		{
			LoadSettingInspectProject(pChildNode, *pstSetting);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_LASTPROJECT))
		{
			DWORD dwOption = 0;

			TCHAR* pszValue = new TCHAR[nValueLen + 1];
			pChildNode->GetValue(pszValue, nValueLen + 1);

			pstSetting->m_strLastCloseProjectFileFullPath = pszValue;

			CXmlAttribute* pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_OPTION);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&dwOption, sizeof(DWORD));
				pstSetting->m_bLastCloseFileAutoOpen = dwOption;
			}

			delete[] pszValue;
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_TRANSFERDATA))
		{
			LoadSettingTransferData(pChildNode, *pstSetting);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_LOGGING))
		{
			LoadSettingLogging(pChildNode, *pstSetting);
		}


	}

	return TRUE;
}


BOOL CXml::LoadSettingAuth(CXmlNode* pXmlNode, stProgramSetting& stSetting)
{
	if (NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		const int nValueLen = pChildNode->GetValue(0, NULL);

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_USERID))
		{
			TCHAR* pszValue = new TCHAR[nValueLen + 1];
			pChildNode->GetValue(pszValue, nValueLen + 1);

			stSetting.m_strUserID = pszValue;

			delete[] pszValue;
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_PASSWORD))
		{
			TCHAR* pszValue = new TCHAR[nValueLen + 1];
			pChildNode->GetValue(pszValue, nValueLen + 1);

			stSetting.m_strPassword = pszValue;

			delete[] pszValue;
		}
	}

	return TRUE;
}

BOOL CXml::LoadSettingLicense(CXmlNode* pXmlNode, stProgramSetting& stSetting)
{
	if (NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		const int nValueLen = pChildNode->GetValue(0, NULL);

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_LICENSETYPE))
		{
			int nValue = 0;
			pChildNode->GetValue(&nValue, sizeof(int));

			stSetting.m_nLicenseType = nValue;
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_EXPIRATIONDATE))
		{
			TCHAR* pszValue = new TCHAR[nValueLen + 1];
			pChildNode->GetValue(pszValue, nValueLen + 1);

			stSetting.m_strExpirationData = pszValue;

			delete[] pszValue;
		}
	}

	return TRUE;
}

BOOL CXml::LoadSettingPath(CXmlNode* pXmlNode, stProgramSetting& stSetting)
{
	if (NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		const int nValueLen = pChildNode->GetValue(0, NULL);

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_INSTALLPATH))
		{
			TCHAR* pszValue = new TCHAR[nValueLen + 1];
			pChildNode->GetValue(pszValue, nValueLen + 1);

			stSetting.m_strProgramFullPath = pszValue;

			delete[] pszValue;
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_LASTIMAGEPATH))
		{
			TCHAR* pszValue = new TCHAR[nValueLen + 1];
			pChildNode->GetValue(pszValue, nValueLen + 1);

			stSetting.m_strLastImageFullPath = pszValue;

			delete[] pszValue;
		}
	}

	return TRUE;
}

BOOL CXml::LoadSettingConfigProject(CXmlNode* pXmlNode, stProgramSetting& stSetting)
{
	if (NULL == pXmlNode)
		return FALSE;

	stSetting.m_vtConfigRecentsProjectFilesList.clear();

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		const int nValueLen = pChildNode->GetValue(0, NULL);
		if (1 >= nValueLen)
			continue;

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_PROJECTPATH))
		{
			TCHAR* pszValue = new TCHAR[nValueLen + 1];
			pChildNode->GetValue(pszValue, nValueLen + 1);

			CString szPath = pszValue;
			stSetting.m_vtConfigRecentsProjectFilesList.push_back(szPath);

			delete[] pszValue;
		}
		
	}

	return TRUE;
}

BOOL CXml::LoadSettingInspectProject(CXmlNode* pXmlNode, stProgramSetting& stSetting)
{
	if (NULL == pXmlNode)
		return FALSE;

	stSetting.m_vtInspectRecentsProjectFilesList.clear();

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		const int nValueLen = pChildNode->GetValue(0, NULL);
		if (1 >= nValueLen)
			continue;

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_PROJECTPATH))
		{
			TCHAR* pszValue = new TCHAR[nValueLen + 1];
			pChildNode->GetValue(pszValue, nValueLen + 1);

			CString szPath = pszValue;
			stSetting.m_vtInspectRecentsProjectFilesList.push_back(szPath);

			delete[] pszValue;
		}

	}

	return TRUE;
}

BOOL CXml::LoadSettingTransferData(CXmlNode* pXmlNode, stProgramSetting& stSetting)
{
	if (NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_SERIAL))
		{
			LoadSettingTransferDataSerial(pChildNode, stSetting);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_ETHERNET))
		{
			LoadSettingTransferDataEthernet(pChildNode, stSetting);
		}
	}
	
	return TRUE;
}

BOOL CXml::LoadSettingTransferDataSerial(CXmlNode* pXmlNode, stProgramSetting& stSetting)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_CONFIG))
		{
			stSerialConfig stConfig;
			memset(&stConfig, 0x00, sizeof(stSerialConfig));

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_SERIALPORT);
			if (pXmlAttr)
				pXmlAttr->GetValue(&stConfig.m_nPort, sizeof(int));

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_BAUDRATE);
			if (pXmlAttr)
				pXmlAttr->GetValue(&stConfig.m_nBaudrate, sizeof(int));

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_DATABIT);
			if (pXmlAttr)
				pXmlAttr->GetValue(&stConfig.m_nDatabits, sizeof(int));

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_PARITY);
			if (pXmlAttr)
				pXmlAttr->GetValue(&stConfig.m_nParity, sizeof(int));

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_STOPBIT);
			if (pXmlAttr)
				pXmlAttr->GetValue(&stConfig.m_nStopbits, sizeof(int));


			stSetting.m_stActiveTransferDataInfo.m_stOpenSerialMan.m_vtOpenSerialList.push_back(stConfig);

		}
	}

	return TRUE;
}

BOOL CXml::LoadSettingTransferDataEthernet(CXmlNode* pXmlNode, stProgramSetting& stSetting)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_SERVER))
		{
			//
			LoadSettingTransferDataEthernetServerConnected(pChildNode, stSetting);

			//
			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_IP);
			if (pXmlAttr)
			{
				const int nTxtLen = pXmlAttr->GetValue(0, NULL);
				TCHAR* pTxt = new TCHAR[nTxtLen + 1];
				pXmlAttr->GetValue(pTxt, nTxtLen + 1);

				stSetting.m_stActiveTransferDataInfo.m_stServerConfig.m_strIPAddress = pTxt;

				if (pTxt) delete[] pTxt;
			}

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_IPPORT);
			if (pXmlAttr)
				pXmlAttr->GetValue(&(stSetting.m_stActiveTransferDataInfo.m_stServerConfig.m_nPort), sizeof(int));

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_START);
			if (pXmlAttr)
			{
				const int nTxtLen = pXmlAttr->GetValue(0, NULL);
				TCHAR* pTxt = new TCHAR[nTxtLen + 1];
				pXmlAttr->GetValue(pTxt, nTxtLen + 1);

				BOOL bStart = FALSE;
				GetBoolean(bStart, pTxt);
				stSetting.m_stActiveTransferDataInfo.m_stServerConfig.m_bStartServer = bStart;

				if (pTxt) delete[] pTxt;
			}

		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_CLIENTLIST))
		{
			//
			LoadSettingTransferDataEthernetClientItems(pChildNode, stSetting);
		}
	}

	return TRUE;
}

BOOL CXml::LoadSettingTransferDataEthernetServerConnected(CXmlNode* pXmlNode, stProgramSetting& stSetting)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_CLIENTLIST))
		{
			LoadSettingTransferDataEthernetServerItems(pChildNode, stSetting);
		}
	}

	return TRUE;
}


BOOL CXml::LoadSettingTransferDataEthernetServerItems(CXmlNode* pXmlNode, stProgramSetting& stSetting)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_CLIENT))
		{
			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_IP);
			if (pXmlAttr)
			{
				const int nTxtLen = pXmlAttr->GetValue(0, NULL);
				TCHAR* pTxt = new TCHAR[nTxtLen + 1];
				pXmlAttr->GetValue(pTxt, nTxtLen + 1);

				CString szIp = pTxt;
				stSetting.m_stActiveTransferDataInfo.m_stServerConfig.m_vtConncetClientList.push_back(szIp);

				if (pTxt) delete[] pTxt;
			}

		}
	}

	return TRUE;
}

BOOL CXml::LoadSettingTransferDataEthernetClientItems(CXmlNode* pXmlNode, stProgramSetting& stSetting)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_CLIENT))
		{
			stClientConfig stClinet;


			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_NAME);
			if (pXmlAttr)
			{
				const int nTxtLen = pXmlAttr->GetValue(0, NULL);
				TCHAR* pTxt = new TCHAR[nTxtLen + 1];
				pXmlAttr->GetValue(pTxt, nTxtLen + 1);

				stClinet.m_strDeviceName = pTxt;

				if (pTxt) delete[] pTxt;
			}

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_LOCALIP);
			if (pXmlAttr)
			{
				const int nTxtLen = pXmlAttr->GetValue(0, NULL);
				TCHAR* pTxt = new TCHAR[nTxtLen + 1];
				pXmlAttr->GetValue(pTxt, nTxtLen + 1);

				stClinet.m_strLocalIPAddress = pTxt;

				if (pTxt) delete[] pTxt;
			}

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_TARGETIP);
			if (pXmlAttr)
			{
				const int nTxtLen = pXmlAttr->GetValue(0, NULL);
				TCHAR* pTxt = new TCHAR[nTxtLen + 1];
				pXmlAttr->GetValue(pTxt, nTxtLen + 1);

				stClinet.m_strTargetIPAddress = pTxt;

				if (pTxt) delete[] pTxt;
			}

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_IPPORT);
			if (pXmlAttr)
				pXmlAttr->GetValue(&stClinet.m_nPort, sizeof(int));

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_TIMEOUT);
			if (pXmlAttr)
				pXmlAttr->GetValue(&stClinet.m_nTimeout, sizeof(int));

			stSetting.m_stActiveTransferDataInfo.m_stActiveClientMan.m_vtActiveClientList.push_back(stClinet);
		}
	}

	return TRUE;
}

BOOL CXml::LoadSettingLogging(CXmlNode* pXmlNode, stProgramSetting& stSetting)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_LOGFILE))
		{
			LoadSettingLoggingFile(pChildNode, stSetting);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_IMAGEFILE))
		{
			LoadSettingLoggingImage(pChildNode, stSetting);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_AUTODELETE))
		{
			LoadSettingLoggingFileAutoDelete(pChildNode, stSetting);
		}
	}

	return TRUE;
}

BOOL CXml::LoadSettingLoggingFile(CXmlNode* pXmlNode, stProgramSetting& stSetting)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;
	DWORD dwValue = 0;

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_LOGGING_ENABLE);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
		stSetting.m_stLogSetting.m_stFileSetting.m_bEnable = dwValue;
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_LOGGING_SINGLE);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
		stSetting.m_stLogSetting.m_stFileSetting.m_bSingle = dwValue;
	}


	return TRUE;
}

BOOL CXml::LoadSettingLoggingFileAutoDelete(CXmlNode* pXmlNode, stProgramSetting& stSetting)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_LOGGING_ENABLE);
	if (pXmlAttr)
	{
		DWORD dwValue = 0;

		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
		stSetting.m_stLogSetting.m_bAutoDelete = dwValue;
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_LOGGING_FLAG);
	if (pXmlAttr)
	{
		TCHAR szTxt[MAX_NAME_LEN] = { 0, };
		pXmlAttr->GetValue(&szTxt, MAX_NAME_LEN);
		stSetting.m_stLogSetting.m_eAutoDeleteFlag = LOG_AUTODELETE_NONE;

		if (CUtil::StringCompare(XML_AUTODELETE_DAILY, szTxt))
			stSetting.m_stLogSetting.m_eAutoDeleteFlag = LOG_AUTODELETE_DAILY;
		else if (CUtil::StringCompare(XML_AUTODELETE_WEEKLY, szTxt))
			stSetting.m_stLogSetting.m_eAutoDeleteFlag = LOG_AUTODELETE_WEEKLY;
		else if (CUtil::StringCompare(XML_AUTODELETE_MONTHLY, szTxt))
			stSetting.m_stLogSetting.m_eAutoDeleteFlag = LOG_AUTODELETE_MONTHLY;
	}

	return TRUE;
}

BOOL CXml::LoadSettingLoggingImage(CXmlNode* pXmlNode, stProgramSetting& stSetting)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_ORIGINALIMG))
		{
			LoadSettingLoggingImageOriginal(pChildNode, stSetting);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_RESULTIMG))
		{
			LoadSettingLoggingImageResult(pChildNode, stSetting);
		}
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_LOGGING_ENABLE);
	if (pXmlAttr)
	{
		DWORD dwValue = 0;
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
		stSetting.m_stLogSetting.m_stImageSetting.m_bEnable = dwValue;
	}

	return TRUE;
}

BOOL CXml::LoadSettingLoggingImageOriginal(CXmlNode* pXmlNode, stProgramSetting& stSetting)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_PASS))
		{
			LoadSettingLoggingImageOriginalPass(pChildNode, stSetting);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_FAIL))
		{
			LoadSettingLoggingImageOriginalFail(pChildNode, stSetting);
		}
	}


	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_LOGGING_ENABLE);
	if (pXmlAttr)
	{
		DWORD dwValue = 0;
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
		stSetting.m_stLogSetting.m_stImageSetting.m_bOriginal = dwValue;
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_LOGGING_FORMAT);
	if (pXmlAttr)
	{
		TCHAR szTxt[MAX_NAME_LEN] = { 0, };
		pXmlAttr->GetValue(&szTxt, MAX_NAME_LEN);
		stSetting.m_stLogSetting.m_stImageSetting.m_eOriginalFormat = LOG_IMAGEFORMAT_BMP;

		if (CUtil::StringCompare(XML_LOGCONFIG_BMP, szTxt))
			stSetting.m_stLogSetting.m_stImageSetting.m_eOriginalFormat = LOG_IMAGEFORMAT_BMP;
		else if (CUtil::StringCompare(XML_LOGCONFIG_PNG, szTxt))
			stSetting.m_stLogSetting.m_stImageSetting.m_eOriginalFormat = LOG_IMAGEFORMAT_PNG;
		else if (CUtil::StringCompare(XML_LOGCONFIG_JPG, szTxt))
			stSetting.m_stLogSetting.m_stImageSetting.m_eOriginalFormat = LOG_IMAGEFORMAT_JPG;
	}


	return TRUE;
}

BOOL CXml::LoadSettingLoggingImageOriginalPass(CXmlNode* pXmlNode, stProgramSetting& stSetting)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_LOGGING_ENABLE);
	if (pXmlAttr)
	{
		DWORD dwValue = 0;
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
		stSetting.m_stLogSetting.m_stImageSetting.m_bOriginalPass = dwValue;
	}

	return TRUE;
}
BOOL CXml::LoadSettingLoggingImageOriginalFail(CXmlNode* pXmlNode, stProgramSetting& stSetting)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_LOGGING_ENABLE);
	if (pXmlAttr)
	{
		DWORD dwValue = 0;
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
		stSetting.m_stLogSetting.m_stImageSetting.m_bOriginalFail = dwValue;
	}

	return TRUE;
}



BOOL CXml::LoadSettingLoggingImageResult(CXmlNode* pXmlNode, stProgramSetting& stSetting)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_PASS))
		{
			LoadSettingLoggingImageResultPass(pChildNode, stSetting);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SET_FAIL))
		{
			LoadSettingLoggingImageResultFail(pChildNode, stSetting);
		}
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_LOGGING_ENABLE);
	if (pXmlAttr)
	{
		DWORD dwValue = 0;
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
		stSetting.m_stLogSetting.m_stImageSetting.m_bResult = dwValue;
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_LOGGING_FORMAT);
	if (pXmlAttr)
	{
		TCHAR szTxt[MAX_NAME_LEN] = { 0, };
		pXmlAttr->GetValue(&szTxt, MAX_NAME_LEN);
		stSetting.m_stLogSetting.m_stImageSetting.m_eResultFormat = LOG_IMAGEFORMAT_BMP;

		if (CUtil::StringCompare(XML_LOGCONFIG_BMP, szTxt))
			stSetting.m_stLogSetting.m_stImageSetting.m_eResultFormat = LOG_IMAGEFORMAT_BMP;
		else if (CUtil::StringCompare(XML_LOGCONFIG_PNG, szTxt))
			stSetting.m_stLogSetting.m_stImageSetting.m_eResultFormat = LOG_IMAGEFORMAT_PNG;
		else if (CUtil::StringCompare(XML_LOGCONFIG_JPG, szTxt))
			stSetting.m_stLogSetting.m_stImageSetting.m_eResultFormat = LOG_IMAGEFORMAT_JPG;
	}

	return TRUE;
}


BOOL CXml::LoadSettingLoggingImageResultPass(CXmlNode* pXmlNode, stProgramSetting& stSetting)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_LOGGING_ENABLE);
	if (pXmlAttr)
	{
		DWORD dwValue = 0;
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
		stSetting.m_stLogSetting.m_stImageSetting.m_bResultPass = dwValue;
	}

	return TRUE;
}
BOOL CXml::LoadSettingLoggingImageResultFail(CXmlNode* pXmlNode, stProgramSetting& stSetting)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_LOGGING_ENABLE);
	if (pXmlAttr)
	{
		DWORD dwValue = 0;
		pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
		stSetting.m_stLogSetting.m_stImageSetting.m_bResultFail = dwValue;
	}

	return TRUE;
}




CXmlNode* CXml::SaveXml(stProgramSetting* pstSetting)
{
	if (NULL == pstSetting)
		return NULL;

	CXmlNode* pXmlNode = new CXmlNode(XML_NAVINODE_ROOT, NULL);

	CXmlNode* pNode = NULL;
	
	pNode = SaveSettingAuth(pXmlNode, *pstSetting);
	pXmlNode->AddNode(pNode);	delete pNode;
	
	pNode = SaveSettingLicense(pXmlNode, *pstSetting);
	pXmlNode->AddNode(pNode);	delete pNode;

	pNode = SaveSettingPath(pXmlNode, *pstSetting);
	pXmlNode->AddNode(pNode);	delete pNode;

	pNode = SaveSettingConfigProject(pXmlNode, *pstSetting);
	pXmlNode->AddNode(pNode);	delete pNode;

	pNode = SaveSettingInspectProject(pXmlNode, *pstSetting);
	pXmlNode->AddNode(pNode);	delete pNode;

	pNode = CreateNodeString(pXmlNode, XML_NAVINODE_SET_LASTPROJECT, pstSetting->m_strLastCloseProjectFileFullPath);
	AddAttributeUnsignedInt(pNode, XML_NAVI_ATTR_OPTION, pstSetting->m_bLastCloseFileAutoOpen);
	pXmlNode->AddNode(pNode);	delete pNode;

	pNode = SaveSettingTransferData(pXmlNode, *pstSetting);
	pXmlNode->AddNode(pNode);	delete pNode;

	pNode = SaveSettingLogging(pXmlNode, *pstSetting);
	pXmlNode->AddNode(pNode);	delete pNode;

	return pXmlNode;
}

CXmlNode* CXml::SaveSettingAuth(CXmlNode* pParentNode, stProgramSetting& stSetting)
{
	if (NULL == pParentNode)
		return NULL;

	CXmlNode* pAuthNode = CreateNode(pParentNode, XML_NAVINODE_SET_AUTH, TYPE_XML_VALUE_NONE, NULL, 0);

	CXmlNode* pNode = NULL;
	
	pNode = CreateNodeString(pAuthNode, XML_NAVINODE_SET_USERID, stSetting.m_strUserID);
	pAuthNode->AddNode(pNode); delete pNode;

	pNode = CreateNodeString(pAuthNode, XML_NAVINODE_SET_PASSWORD, stSetting.m_strPassword);
	pAuthNode->AddNode(pNode); delete pNode;

	
	
	return pAuthNode;
}

CXmlNode* CXml::SaveSettingLicense(CXmlNode* pParentNode, stProgramSetting& stSetting)
{
	if (NULL == pParentNode)
		return NULL;

	CXmlNode* pLicenseNode = CreateNode(pParentNode, XML_NAVINODE_SET_LICENSEINFO, TYPE_XML_VALUE_NONE, NULL, 0);

	CXmlNode* pNode = NULL;

	pNode = CreateNodeInt(pLicenseNode, XML_NAVINODE_SET_LICENSETYPE, stSetting.m_nLicenseType);
	pLicenseNode->AddNode(pNode); delete pNode;

	pNode = CreateNodeString(pLicenseNode, XML_NAVINODE_SET_EXPIRATIONDATE, stSetting.m_strExpirationData);
	pLicenseNode->AddNode(pNode); delete pNode;

	return pLicenseNode;
}

CXmlNode* CXml::SaveSettingPath(CXmlNode* pParentNode, stProgramSetting& stSetting)
{
	if (NULL == pParentNode)
		return NULL;

	CXmlNode* pSettingPath = CreateNode(pParentNode, XML_NAVINODE_SET_SETINFO, TYPE_XML_VALUE_NONE, NULL, 0);

	CXmlNode* pNode = NULL;

	pNode = CreateNodeString(pSettingPath, XML_NAVINODE_SET_INSTALLPATH, stSetting.m_strProgramFullPath);
	pSettingPath->AddNode(pNode); delete pNode;

	pNode = CreateNodeString(pSettingPath, XML_NAVINODE_SET_LASTIMAGEPATH, stSetting.m_strLastImageFullPath);
	pSettingPath->AddNode(pNode); delete pNode;


	return pSettingPath;;
}

CXmlNode* CXml::SaveSettingConfigProject(CXmlNode* pParentNode, stProgramSetting& stSetting)
{
	if (NULL == pParentNode)
		return NULL;

	CXmlNode* pConfigProject = CreateNode(pParentNode, XML_NAVINODE_SET_CONFIGPROJECT, TYPE_XML_VALUE_NONE, NULL, 0);

	CXmlNode* pNode = NULL;

	const int nSize = stSetting.m_vtConfigRecentsProjectFilesList.size();
	for (int i = 0; i < nSize; i++)
	{
		pNode = CreateNodeString(pConfigProject, XML_NAVINODE_SET_PROJECTPATH, stSetting.m_vtConfigRecentsProjectFilesList[i]);
		pConfigProject->AddNode(pNode); delete pNode;
	}

	return pConfigProject;
}

CXmlNode* CXml::SaveSettingInspectProject(CXmlNode* pParentNode, stProgramSetting& stSetting)
{
	if (NULL == pParentNode)
		return NULL;

	CXmlNode* pInspectProject = CreateNode(pParentNode, XML_NAVINODE_SET_INSPECTPROJECT, TYPE_XML_VALUE_NONE, NULL, 0);

	CXmlNode* pNode = NULL;

	const int nSize = stSetting.m_vtInspectRecentsProjectFilesList.size();
	for (int i = 0; i < nSize; i++)
	{
		pNode = CreateNodeString(pInspectProject, XML_NAVINODE_SET_PROJECTPATH, stSetting.m_vtInspectRecentsProjectFilesList[i]);
		pInspectProject->AddNode(pNode); delete pNode;
	}

	return pInspectProject;
}

CXmlNode* CXml::SaveSettingTransferData(CXmlNode* pParentNode, stProgramSetting& stSetting)
{
	if (NULL == pParentNode)
		return NULL;

	CXmlNode* pTransferData = CreateNode(pParentNode, XML_NAVINODE_SET_TRANSFERDATA, TYPE_XML_VALUE_NONE, NULL, 0);

	CXmlNode* pNode = NULL;

	// Serial
	pNode = SaveSettingTransferDataSerial(pTransferData, stSetting);
	pTransferData->AddNode(pNode); delete pNode;
	
	// Ethernet
	pNode = SaveSettingTransferDataEthernet(pTransferData, stSetting);
	pTransferData->AddNode(pNode); delete pNode;


	return pTransferData;
}

CXmlNode* CXml::SaveSettingTransferDataSerial(CXmlNode* pParentNode, stProgramSetting& stSetting)
{
	if (NULL == pParentNode)
		return NULL;

	CXmlNode* pSerialNode = CreateNode(pParentNode, XML_NAVINODE_SET_SERIAL, TYPE_XML_VALUE_NONE, NULL, 0);

	CXmlNode* pNode = NULL;
	
	const int nCount = stSetting.m_stActiveTransferDataInfo.m_stOpenSerialMan.m_vtOpenSerialList.size();
	for (int i = 0; i < nCount; i++)
	{
		pNode = CreateNode(pSerialNode, XML_NAVINODE_SET_CONFIG, TYPE_XML_VALUE_NONE, NULL, 0);

		const stSerialConfig* pSerialConfig = &(stSetting.m_stActiveTransferDataInfo.m_stOpenSerialMan.m_vtOpenSerialList[i]);

		AddAttributeInt(pNode, XML_NAVI_ATTR_SERIALPORT, pSerialConfig->m_nPort);
		AddAttributeInt(pNode, XML_NAVI_ATTR_BAUDRATE, pSerialConfig->m_nBaudrate);
		AddAttributeInt(pNode, XML_NAVI_ATTR_DATABIT, pSerialConfig->m_nDatabits);
		AddAttributeInt(pNode, XML_NAVI_ATTR_PARITY, pSerialConfig->m_nParity);
		AddAttributeInt(pNode, XML_NAVI_ATTR_STOPBIT, pSerialConfig->m_nStopbits);

		pSerialNode->AddNode(pNode); delete pNode;
	}

	return pSerialNode;
}

CXmlNode* CXml::SaveSettingTransferDataEthernet(CXmlNode* pParentNode, stProgramSetting& stSetting)
{
	if (NULL == pParentNode)
		return NULL;

	CXmlNode* pEthernetNode = CreateNode(pParentNode, XML_NAVINODE_SET_ETHERNET, TYPE_XML_VALUE_NONE, NULL, 0);

	CXmlNode* pNode = NULL;

	// Server
	CXmlNode* pServerNode = CreateNode(pEthernetNode, XML_NAVINODE_SET_SERVER, TYPE_XML_VALUE_NONE, NULL, 0);
	{
		AddAttributeString(pServerNode, XML_NAVI_ATTR_IP, stSetting.m_stActiveTransferDataInfo.m_stServerConfig.m_strIPAddress);
		AddAttributeInt(pServerNode, XML_NAVI_ATTR_IPPORT, stSetting.m_stActiveTransferDataInfo.m_stServerConfig.m_nPort);
		if (stSetting.m_stActiveTransferDataInfo.m_stServerConfig.m_bStartServer)
			AddAttributeString(pServerNode, XML_NAVI_ATTR_START, _T("TRUE"));
		else
			AddAttributeString(pServerNode, XML_NAVI_ATTR_START, _T("FALSE"));


		CXmlNode* pClientListNode = CreateNode(pServerNode, XML_NAVINODE_SET_CLIENTLIST, TYPE_XML_VALUE_NONE, NULL, 0);

		const int nCount = stSetting.m_stActiveTransferDataInfo.m_stServerConfig.m_vtConncetClientList.size();
		for (int i = 0; i < nCount; i++)
		{
			pNode = CreateNode(pClientListNode, XML_NAVINODE_SET_CLIENT, TYPE_XML_VALUE_NONE, NULL, 0);
			AddAttributeString(pNode, XML_NAVI_ATTR_IP, stSetting.m_stActiveTransferDataInfo.m_stServerConfig.m_vtConncetClientList[i]);;
			pClientListNode->AddNode(pNode); delete pNode;
		}
		pServerNode->AddNode(pClientListNode); delete pClientListNode;

	}
	pEthernetNode->AddNode(pServerNode); delete pServerNode;


	// Clinet
	CXmlNode* pClientListNode = CreateNode(pParentNode, XML_NAVINODE_SET_CLIENTLIST, TYPE_XML_VALUE_NONE, NULL, 0);
	{
		const int nCount = stSetting.m_stActiveTransferDataInfo.m_stActiveClientMan.m_vtActiveClientList.size();
		for (int i = 0; i < nCount; i++)
		{
			stClientConfig* pstClient = &(stSetting.m_stActiveTransferDataInfo.m_stActiveClientMan.m_vtActiveClientList[i]);

			pNode = CreateNode(pClientListNode, XML_NAVINODE_SET_CLIENT, TYPE_XML_VALUE_NONE, NULL, 0);

			AddAttributeString(pNode, XML_NAVI_ATTR_NAME, pstClient->m_strDeviceName);
			AddAttributeString(pNode, XML_NAVI_ATTR_TARGETIP, pstClient->m_strTargetIPAddress);
			AddAttributeString(pNode, XML_NAVI_ATTR_LOCALIP, pstClient->m_strLocalIPAddress);
			AddAttributeInt(pNode, XML_NAVI_ATTR_IPPORT, pstClient->m_nPort);
			AddAttributeInt(pNode, XML_NAVI_ATTR_TIMEOUT, pstClient->m_nTimeout);
			
			pClientListNode->AddNode(pNode); delete pNode;
		}

	}
	pEthernetNode->AddNode(pClientListNode); delete pClientListNode;

	return pEthernetNode;
}



CXmlNode* CXml::SaveSettingLogging(CXmlNode* pParentNode, stProgramSetting& stSetting)
{
	if (NULL == pParentNode)
		return NULL;

	CXmlNode* pLogNode = CreateNode(pParentNode, XML_NAVINODE_SET_LOGGING, TYPE_XML_VALUE_NONE, NULL, 0);
	CXmlNode* pNode = NULL;

	// File
	pNode = SaveSettingLoggingFile(pLogNode, stSetting);
	pLogNode->AddNode(pNode); delete pNode;

	// Image
	pNode = SaveSettingLoggingImage(pLogNode, stSetting);
	pLogNode->AddNode(pNode); delete pNode;

	// Auto Delete
	pNode = SaveSettingLoggingFileAutoDelete(pLogNode, stSetting);
	pLogNode->AddNode(pNode); delete pNode;


	return pLogNode;
}


CXmlNode* CXml::SaveSettingLoggingFile(CXmlNode* pParentNode, stProgramSetting& stSetting)
{
	CXmlNode* pLogFileNode = CreateNode(pParentNode, XML_NAVINODE_SET_LOGFILE, TYPE_XML_VALUE_NONE, NULL, 0);
	CXmlNode* pNode = NULL;

	AddAttributeUnsignedInt(pLogFileNode, XML_NAVI_ATTR_LOGGING_ENABLE, stSetting.m_stLogSetting.m_stFileSetting.m_bEnable);
	AddAttributeUnsignedInt(pLogFileNode, XML_NAVI_ATTR_LOGGING_SINGLE, stSetting.m_stLogSetting.m_stFileSetting.m_bSingle);

	return pLogFileNode;
}

CXmlNode* CXml::SaveSettingLoggingImage(CXmlNode* pParentNode, stProgramSetting& stSetting)
{
	CXmlNode* pLogImgNode = CreateNode(pParentNode, XML_NAVINODE_SET_IMAGEFILE, TYPE_XML_VALUE_NONE, NULL, 0);
	CXmlNode* pNode = NULL;

	// Original Image
	pNode = SaveSettingLoggingImageOriginal(pLogImgNode, stSetting);
	pLogImgNode->AddNode(pNode); delete pNode;

	// Result Image
	pNode = SaveSettingLoggingImageResult(pLogImgNode, stSetting);
	pLogImgNode->AddNode(pNode); delete pNode;


	AddAttributeUnsignedInt(pLogImgNode, XML_NAVI_ATTR_LOGGING_ENABLE, stSetting.m_stLogSetting.m_stImageSetting.m_bEnable);

	return pLogImgNode;
}

CXmlNode* CXml::SaveSettingLoggingFileAutoDelete(CXmlNode* pParentNode, stProgramSetting& stSetting)
{
	CXmlNode* pAutoDeleteNode = CreateNode(pParentNode, XML_NAVINODE_SET_AUTODELETE, TYPE_XML_VALUE_NONE, NULL, 0);
	
	AddAttributeUnsignedInt(pAutoDeleteNode, XML_NAVI_ATTR_LOGGING_ENABLE, stSetting.m_stLogSetting.m_bAutoDelete);

	if(LOG_AUTODELETE_DAILY == stSetting.m_stLogSetting.m_eAutoDeleteFlag)
		AddAttributeString(pAutoDeleteNode, XML_NAVI_ATTR_LOGGING_FLAG, XML_AUTODELETE_DAILY );
	else if (LOG_AUTODELETE_WEEKLY == stSetting.m_stLogSetting.m_eAutoDeleteFlag)
		AddAttributeString(pAutoDeleteNode, XML_NAVI_ATTR_LOGGING_FLAG, XML_AUTODELETE_WEEKLY );
	else if (LOG_AUTODELETE_MONTHLY == stSetting.m_stLogSetting.m_eAutoDeleteFlag)
		AddAttributeString(pAutoDeleteNode, XML_NAVI_ATTR_LOGGING_FLAG, XML_AUTODELETE_MONTHLY );
	else
		AddAttributeString(pAutoDeleteNode, XML_NAVI_ATTR_LOGGING_FLAG, XML_AUTODELETE_NONE );

	return pAutoDeleteNode;
}

CXmlNode* CXml::SaveSettingLoggingImageOriginal(CXmlNode* pParentNode, stProgramSetting& stSetting)
{
	CXmlNode* pOriginalNode = CreateNode(pParentNode, XML_NAVINODE_SET_ORIGINALIMG, TYPE_XML_VALUE_NONE, NULL, 0);
	CXmlNode* pNode = NULL;

	// Pass
	pNode = SaveSettingLoggingImageOriginalPass(pOriginalNode, stSetting);
	pOriginalNode->AddNode(pNode); delete pNode;

	// Fail
	pNode = SaveSettingLoggingImageOriginalFail(pOriginalNode, stSetting);
	pOriginalNode->AddNode(pNode); delete pNode;


	AddAttributeUnsignedInt(pOriginalNode, XML_NAVI_ATTR_LOGGING_ENABLE, stSetting.m_stLogSetting.m_stImageSetting.m_bOriginal);

	if (LOG_IMAGEFORMAT_PNG == stSetting.m_stLogSetting.m_stImageSetting.m_eOriginalFormat)
		AddAttributeString(pOriginalNode, XML_NAVI_ATTR_LOGGING_FORMAT, XML_LOGCONFIG_PNG);
	else if (LOG_IMAGEFORMAT_JPG == stSetting.m_stLogSetting.m_stImageSetting.m_eOriginalFormat)
		AddAttributeString(pOriginalNode, XML_NAVI_ATTR_LOGGING_FORMAT, XML_LOGCONFIG_JPG);
	else //if (LOG_IMAGEFORMAT_BMP == stSetting.m_stLogSetting.m_stImageSetting.m_eOriginalFormat)
		AddAttributeString(pOriginalNode, XML_NAVI_ATTR_LOGGING_FORMAT, XML_LOGCONFIG_BMP);

	return pOriginalNode;
}

CXmlNode* CXml::SaveSettingLoggingImageOriginalPass(CXmlNode* pParentNode, stProgramSetting& stSetting)
{
	CXmlNode* pPassNode = CreateNode(pParentNode, XML_NAVINODE_SET_PASS, TYPE_XML_VALUE_NONE, NULL, 0);

	AddAttributeUnsignedInt(pPassNode, XML_NAVI_ATTR_LOGGING_ENABLE, stSetting.m_stLogSetting.m_stImageSetting.m_bOriginalPass);
	return pPassNode;
}

CXmlNode* CXml::SaveSettingLoggingImageOriginalFail(CXmlNode* pParentNode, stProgramSetting& stSetting)
{
	CXmlNode* pFailNode = CreateNode(pParentNode, XML_NAVINODE_SET_FAIL, TYPE_XML_VALUE_NONE, NULL, 0);

	AddAttributeUnsignedInt(pFailNode, XML_NAVI_ATTR_LOGGING_ENABLE, stSetting.m_stLogSetting.m_stImageSetting.m_bOriginalFail);
	return pFailNode;
}


CXmlNode* CXml::SaveSettingLoggingImageResult(CXmlNode* pParentNode, stProgramSetting& stSetting)
{
	CXmlNode* pResultNode = CreateNode(pParentNode, XML_NAVINODE_SET_RESULTIMG, TYPE_XML_VALUE_NONE, NULL, 0);
	CXmlNode* pNode = NULL;

	// Pass
	pNode = SaveSettingLoggingImageResultPass(pResultNode, stSetting);
	pResultNode->AddNode(pNode); delete pNode;

	// Fail
	pNode = SaveSettingLoggingImageResultFail(pResultNode, stSetting);
	pResultNode->AddNode(pNode); delete pNode;

	AddAttributeUnsignedInt(pResultNode, XML_NAVI_ATTR_LOGGING_ENABLE, stSetting.m_stLogSetting.m_stImageSetting.m_bResult);

	if (LOG_IMAGEFORMAT_PNG == stSetting.m_stLogSetting.m_stImageSetting.m_eResultFormat)
		AddAttributeString(pResultNode, XML_NAVI_ATTR_LOGGING_FORMAT, XML_LOGCONFIG_PNG);
	else if (LOG_IMAGEFORMAT_JPG == stSetting.m_stLogSetting.m_stImageSetting.m_eResultFormat)
		AddAttributeString(pResultNode, XML_NAVI_ATTR_LOGGING_FORMAT, XML_LOGCONFIG_JPG);
	else //if (LOG_IMAGEFORMAT_BMP == stSetting.m_stLogSetting.m_stImageSetting.m_eResultFormat)
		AddAttributeString(pResultNode, XML_NAVI_ATTR_LOGGING_FORMAT, XML_LOGCONFIG_BMP);


	return pResultNode;
}

CXmlNode* CXml::SaveSettingLoggingImageResultPass(CXmlNode* pParentNode, stProgramSetting& stSetting)
{
	CXmlNode* pPassNode = CreateNode(pParentNode, XML_NAVINODE_SET_PASS, TYPE_XML_VALUE_NONE, NULL, 0);

	AddAttributeUnsignedInt(pPassNode, XML_NAVI_ATTR_LOGGING_ENABLE, stSetting.m_stLogSetting.m_stImageSetting.m_bResultPass);
	return pPassNode;
}

CXmlNode* CXml::SaveSettingLoggingImageResultFail(CXmlNode* pParentNode, stProgramSetting& stSetting)
{
	CXmlNode* pFailNode = CreateNode(pParentNode, XML_NAVINODE_SET_FAIL, TYPE_XML_VALUE_NONE, NULL, 0);

	AddAttributeUnsignedInt(pFailNode, XML_NAVI_ATTR_LOGGING_ENABLE, stSetting.m_stLogSetting.m_stImageSetting.m_bResultFail);
	return pFailNode;
}




////////////////////////////////////////////////////////////////////
// Sequence Manager
stSequenceManager* CXml::Load(TCHAR* pszPath)
{
	if (NULL == pszPath)
		return NULL;

	stSequenceManager* pstSequence = NULL;


	CXmlFile xmlFile;
	CXmlNode* pXmlNode = xmlFile.Load(pszPath, XML_NAVINODE_ROOT);

	if (pXmlNode)
	{
		pstSequence = new stSequenceManager;
		LoadXml(pstSequence, pXmlNode);

		delete pXmlNode;
	}

	return pstSequence;
}


BOOL CXml::LoadXml(stSequenceManager* pstSequence, CXmlNode* pXmlNode)
{
	if (NULL == pstSequence || NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);

		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		const int nValueLen = pChildNode->GetValue(0, NULL);

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_MODE))
		{
			int nValue = 0;
			pChildNode->GetValue(&nValue, sizeof(int));

			pstSequence->m_nTemplateMode = nValue;
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_NAME))
		{
			TCHAR* pszValue = new TCHAR[nValueLen + 1];
			pChildNode->GetValue(pszValue, nValueLen + 1);

			pstSequence->m_strTemplatename = pszValue;

			delete[] pszValue;
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_CREATEDATE))
		{
			TCHAR* pszValue = new TCHAR[nValueLen + 1];
			pChildNode->GetValue(pszValue, nValueLen + 1);

			pstSequence->m_strTemplateCreateDate = pszValue;

			delete[] pszValue;
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_LASTDATE))
		{
			TCHAR* pszValue = new TCHAR[nValueLen + 1];
			pChildNode->GetValue(pszValue, nValueLen + 1);

			pstSequence->m_strTemplateModifyDate = pszValue;

			delete[] pszValue;

		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_DESC))
		{
			// nothing...
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_PROTECT))
		{
			const int nChild = pChildNode->GetNodeCount();
			for (int j = 0; j < nChild; j++)
			{
				CXmlNode* pChild = pChildNode->GetNode(j);
				if (NULL == pChild)
					continue;

				const TCHAR* pChildTitle = pChild->GetTitle();
				const int nValueLen = pChild->GetValue(0, NULL);

				if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pChildTitle, XML_NAVINODE_PASSWD))
				{
					TCHAR* pszValue = new TCHAR[nValueLen + 1];
					pChild->GetValue(pszValue, nValueLen + 1);

					pstSequence->m_strTemplatePassword = pszValue;

					delete[] pszValue;
				}
			}
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_SEQMANAGER))
		{
			const int nChild = pChildNode->GetNodeCount();
			for (int j = 0; j < nChild; j++)
			{
				CXmlNode* pChild = pChildNode->GetNode(j);
				if (NULL == pChild)
					continue;

				stSequence*pstSeq = LoadSequence(pChild);
				if (pstSeq)
				{
					pstSequence->m_listSequence.push_back(pstSeq);
				}
			}
		}

	}

	return TRUE;
}

stSequence* CXml::LoadSequence(CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return NULL;

	stSequence* pstSequence = new stSequence;

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		stApplication* pstApp = LoadApplication(pChildNode);
		pstSequence->m_listImageBuffer.push_back(pstApp);

	}

	return pstSequence;
}

stApplication* CXml::LoadApplication(CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return NULL;

	stApplication* pstApp = new stApplication;
	pstApp->m_iSequenceindex = -1;
	pstApp->m_eAppType = eAppType_None;

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		const int nValueLen = pChildNode->GetValue(0, NULL);

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_APP_SEQINDEX))
		{
			int nValue = 0;
			pChildNode->GetValue(&nValue, sizeof(int));

			pstApp->m_iSequenceindex = nValue;
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_APP_TYPE))
		{
			eAPPLICATION_TYPE eType = eAppType_None;

			TCHAR* pTxt = new TCHAR[nValueLen + 1];
			pChildNode->GetValue(pTxt, nValueLen + 1);
			GetApplicationType(eType, pTxt);

			pstApp->m_eAppType = eType;

			if (pTxt)
				delete[] pTxt;
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_APP_INFO))
		{
			LoadApplicationInfo(pChildNode, pstApp->m_stAppInfo);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_APP_FILTER))
		{
			LoadApplicationFilter(pChildNode, pstApp->m_stAppFilter);
		}
	}

	return pstApp;
}

BOOL CXml::LoadApplicationFilter(CXmlNode* pXmlNode, stAPPFILTER& stAppFilter)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;
	int nValue = 0;

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_APPFILTER_NAME);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&nValue, sizeof(int));
		stAppFilter.m_nAppName = nValue;
	}
	else
	{
		stAppFilter.m_nAppName = 1;
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_APPFILTER_ROI);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&nValue, sizeof(int));
		stAppFilter.m_nRoi = nValue;
	}
	else
	{
		stAppFilter.m_nRoi = 1;
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_APPFILTER_ROIEDGE);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&nValue, sizeof(int));
		stAppFilter.m_nRoiEdge = nValue;
	}
	else
	{
		stAppFilter.m_nRoiEdge = 1;
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_APPFILTER_FEATURE);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&nValue, sizeof(int));
		stAppFilter.m_nFeature = nValue;
	}
	else
	{
		stAppFilter.m_nFeature = 1;
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_APPFILTER_RESULT);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&nValue, sizeof(int));
		stAppFilter.m_nResult = nValue;
	}
	else
	{
		stAppFilter.m_nResult = 1;
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_APPFILTER_IMAGE);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&nValue, sizeof(int));
		stAppFilter.m_nImage = nValue;
	}
	else
	{
		stAppFilter.m_nImage = 2;
	}

	return TRUE;

}


BOOL CXml::LoadApplicationInfo(CXmlNode* pXmlNode, stAPPINFO& stAppInfo)
{
	if (NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		const int nValueLen = pChildNode->GetValue(0, NULL);

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_APP_PATH))
		{
			TCHAR* pTxt = new TCHAR[nValueLen + 1];
			pChildNode->GetValue(pTxt, nValueLen + 1);

			stAppInfo.m_strPath = pTxt;

			if (pTxt)
				delete[] pTxt;
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_APP_NAME))
		{
			TCHAR* pTxt = new TCHAR[nValueLen + 1];
			pChildNode->GetValue(pTxt, nValueLen + 1);

			stAppInfo.m_strAppName = pTxt;

			if (pTxt)
				delete[] pTxt;

		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_APP_ROIREF))
		{
			TCHAR* pTxt = new TCHAR[nValueLen + 1];
			pChildNode->GetValue(pTxt, nValueLen + 1);

			stAppInfo.m_strIndexROIReference = pTxt;

			if (pTxt)
				delete[] pTxt;
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_APP_ROICOPY))
		{
			TCHAR* pTxt = new TCHAR[nValueLen + 1];
			pChildNode->GetValue(pTxt, nValueLen + 1);

			stAppInfo.m_strIndexCalibrate = pTxt;

			if (pTxt)
				delete[] pTxt;
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_APP_SRCIMG))
		{
			TCHAR* pTxt = new TCHAR[nValueLen + 1];
			pChildNode->GetValue(pTxt, nValueLen + 1);

			stAppInfo.m_strIndexSrcImage = pTxt;

			if (pTxt)
				delete[] pTxt;
		}

		//
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_APP_IMAGELIST))
		{
			CXmlAttribute* pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_COUNT);
			if (pXmlAttr)
			{
				DWORD dwValue = 0;
				pXmlAttr->GetValue(&dwValue, sizeof(DWORD));

				stAppInfo.m_iImageNum = dwValue;
				LoadApplicationImageList(pChildNode, stAppInfo);
			}
			else
			{
				stAppInfo.m_iImageNum = 0;
			}

		}

		//
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_APP_CONFIGLIST))
		{
			LoadApplicationConfigList(pChildNode, stAppInfo);
		}

		//
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_ROI_INFO))
		{
			LoadApplicationRoiInfo(pChildNode, stAppInfo.m_CROI);
		}
		// MULTI ROI
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_ROI_LIST))
		{
			LoadApplicationRoiList(pChildNode, stAppInfo);
		}
	}

	return TRUE;
}

BOOL CXml::LoadApplicationRoiList(CXmlNode* pXmlNode, stAPPINFO& stAppInfo)
{
	if (NULL == pXmlNode)
		return FALSE;
	stAppInfo.m_CMultiROI.clear();


	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		const int nValueLen = pChildNode->GetValue(0, NULL);

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_ROI_INFO))
		{
			CLP_ROI cRoi;

			BOOL bResult = LoadApplicationRoiInfo(pChildNode, cRoi);
			if (bResult)
			{
				stAppInfo.m_CMultiROI.push_back(cRoi);
			}
		}
	}

	return TRUE;
}


BOOL CXml::LoadApplicationRoiInfo(CXmlNode* pXmlNode, CLP_ROI& stCLRoi)
{
	if (NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		const int nValueLen = pChildNode->GetValue(0, NULL);

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_ROI_TYPE))
		{
			TCHAR* pTxt = new TCHAR[nValueLen + 1];
			pChildNode->GetValue(pTxt, nValueLen + 1);

			GetRoiType(stCLRoi.m_eROIType, pTxt);

			if (pTxt)
				delete[] pTxt;

		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_ROI_FACE))
		{
			TCHAR* pTxt = new TCHAR[nValueLen + 1];
			pChildNode->GetValue(pTxt, nValueLen + 1);

			GetRoiFaceType(stCLRoi.m_eROIFace, pTxt);

			if (pTxt)
				delete[] pTxt;

		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_ROI_POSITION))
		{
			CXmlAttribute* pXmlAttr = NULL;

			DWORD dwW = 0;
			DWORD dwH = 0;
			double fAngle = 0.0f;
			TCHAR* pTxt = NULL;

			// Attribute width
			{
				pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_W);
				if (pXmlAttr)
					pXmlAttr->GetValue(&dwW, sizeof(DWORD));

				stCLRoi.m_iROIWidth = dwW;
			}

			// Attribute height
			{
				pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_H);
				if (pXmlAttr)
					pXmlAttr->GetValue(&dwH, sizeof(DWORD));

				stCLRoi.m_iROIHeight = dwH;
			}

			// Attribute angle
			{
				pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_ANGLE);
				if (pXmlAttr)
					pXmlAttr->GetValue(&fAngle, sizeof(double));

				stCLRoi.m_dROIAngle = fAngle;
			}

			// Attribute direction
			{
				pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_DIRECTION);
				if (pXmlAttr)
				{
					const int nValueLen = pXmlAttr->GetValue(0, NULL);
					pTxt = new TCHAR[nValueLen + 1];
					pXmlAttr->GetValue(pTxt, nValueLen + 1);

					if (eROIFace_Edge == stCLRoi.m_eROIFace)
					{
						if (eROIType_Circle == stCLRoi.m_eROIType || eROIType_Circle == stCLRoi.m_eROIType)
						{
							eROI2DIR eType = eRoi2Dir_In2Out;
							GetRoi2DirType(eType, pTxt);

							stCLRoi.m_eROIDirection.eROI2Direction = eType;
						}
						else if (eROIType_Rectangular == stCLRoi.m_eROIType || eROIType_RectangularRotate == stCLRoi.m_eROIType)
						{
							eROI4DIR eType = eRoi4Dir_Left2Right;
							GetRoi4DirType(eType, pTxt);

							stCLRoi.m_eROIDirection.eROI4Direction = eType;
						}
					}
				}

				if (pTxt)
					delete[] pTxt;
			}

			LoadApplicationRoiPos(pChildNode, stCLRoi);

		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_ROI_STEP))
		{
			DWORD dwValue = 0;
			pChildNode->GetValue(&dwValue, sizeof(DWORD));

			stCLRoi.m_iStep = dwValue;

		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_ROI_OPTION))
		{
			LoadApplicationRoiOption(pChildNode, stCLRoi);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_ROI_MASK))
		{
			// image
		}
	}


	return TRUE;
}


BOOL CXml::LoadApplicationRoiOption(CXmlNode* pXmlNode, CLP_ROI& stCLRoi)
{
	if (NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_ROI_RING))
		{
			LoadApplicationRoiRingOption(pChildNode, stCLRoi);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_ROI_CRITERIA))
		{
			LoadApplicationRoiCriteriaOption(pChildNode, stCLRoi);
		}
	}

	return TRUE;
}

BOOL CXml::LoadApplicationRoiCriteriaOption(CXmlNode* pXmlNode, CLP_ROI& stCLRoi)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	{
		int nMode = 0;
		double fAngle = 0;

		pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_MODE);
		if (pXmlAttr)
			pXmlAttr->GetValue(&nMode, sizeof(int));
		stCLRoi.m_iModeCriteria = nMode;

		pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_ANGLE);
		if (pXmlAttr)
			pXmlAttr->GetValue(&fAngle, sizeof(double));
		stCLRoi.m_dAngleCriteria = fAngle;
	}


	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_ROI_POINT))
		{
			double fX = 0.0f;
			double fY = 0.0f;

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_X);
			if (pXmlAttr)
				pXmlAttr->GetValue(&fX, sizeof(double));

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_Y);
			if (pXmlAttr)
				pXmlAttr->GetValue(&fY, sizeof(double));

			stCLRoi.m_stPosCriteria.m_fX = fX;
			stCLRoi.m_stPosCriteria.m_fY = fY;
		}

	}
	return TRUE;
}


BOOL CXml::LoadApplicationRoiRingOption(CXmlNode* pXmlNode, CLP_ROI& stCLRoi)
{
	if (NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_ROI_RANGE))
		{
			CXmlAttribute* pXmlAttr = NULL;
			TCHAR* pName = NULL;

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_NAME);
			if (pXmlAttr)
			{
				const int nNameLen = pXmlAttr->GetValue(0, NULL);
				pName = new TCHAR[nNameLen + 1];
				pXmlAttr->GetValue(pName, nNameLen + 1);
			}

			double fFrom = 0.0f;
			double fTo = 0.0f;

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_FROM);
			if (pXmlAttr)
				pXmlAttr->GetValue(&fFrom, sizeof(double));

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_TO);
			if (pXmlAttr)
				pXmlAttr->GetValue(&fTo, sizeof(double));

			if (CUtil::StringCompare(pName, XML_RINGROIRANGE_RADIOUS))
			{
				stCLRoi.m_dRadiusSmall = fFrom;
				stCLRoi.m_dRadiusLarge = fTo;
			}
			else if (CUtil::StringCompare(pName, XML_RINGROIRANGE_ANGLE))
			{
				stCLRoi.m_dAngleStart = fFrom;
				stCLRoi.m_dAngleEnd = fTo;
			}

			if (pName)
				delete[] pName;
		}
	}

	return TRUE;
}


BOOL CXml::LoadApplicationRoiPos(CXmlNode* pXmlNode, CLP_ROI& stCLRoi)
{
	if (NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_ROI_POINT))
		{
			CXmlAttribute* pXmlAttr = NULL;
			TCHAR* pName = NULL;

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_NAME);
			if (pXmlAttr)
			{
				const int nNameLen = pXmlAttr->GetValue(0, NULL);
				pName = new TCHAR[nNameLen + 1];
				pXmlAttr->GetValue(pName, nNameLen + 1);
			}

			double fX = 0.0f;
			double fY = 0.0f;

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_X);
			if (pXmlAttr)
				pXmlAttr->GetValue(&fX, sizeof(double));

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_Y);
			if (pXmlAttr)
				pXmlAttr->GetValue(&fY, sizeof(double));

			if (CUtil::StringCompare(XML_ROIPOINTTYPE_START, pName))
			{
				stCLRoi.m_stPosROIStart.m_fX = fX;
				stCLRoi.m_stPosROIStart.m_fY = fY;
			}
			else if (CUtil::StringCompare(XML_ROIPOINTTYPE_END, pName))
			{
				stCLRoi.m_stPosROIEnd.m_fX = fX;
				stCLRoi.m_stPosROIEnd.m_fY = fY;
			}
			else if (CUtil::StringCompare(XML_ROIPOINTTYPE_CENTER, pName))
			{
				stCLRoi.m_stPosROICenter.m_fX = fX;
				stCLRoi.m_stPosROICenter.m_fY = fY;
			}

			if (pName)
				delete[] pName;

		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_ROI_POINTLIST))
		{
			const int nChildCount = pChildNode->GetNodeCount();
			stCLRoi.m_iCountPts = nChildCount;
			for (int j = 0; j < nChildCount; j++)
			{
				CXmlNode* pPointNode = pChildNode->GetNode(j);
				if (NULL == pPointNode)
					continue;

				const TCHAR* pPointTitle = pPointNode->GetTitle();
				if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pPointTitle, XML_NAVINODE_ROI_POINT))
				{
					CXmlAttribute* pXmlAttr = NULL;

					double fX = 0.0f;
					double fY = 0.0f;

					pXmlAttr = pPointNode->GetAttribute(XML_NAVI_ATTR_X);
					if (pXmlAttr)
						pXmlAttr->GetValue(&fX, sizeof(double));

					pXmlAttr = pPointNode->GetAttribute(XML_NAVI_ATTR_Y);
					if (pXmlAttr)
						pXmlAttr->GetValue(&fY, sizeof(double));

					stPOINT point;
					point.m_fX = fX;
					point.m_fY = fY;
					stCLRoi.m_pstPosArray.push_back(point);
				}
			}
		}
	}

	return TRUE;
}


BOOL CXml::LoadApplicationImageList(CXmlNode* pXmlNode, stAPPINFO& stAppInfo)
{
	if (NULL == pXmlNode)
		return FALSE;

	stAppInfo.m_iImageSize.clear();
	stAppInfo.m_strImageBuffer.clear();

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		const int nValueLen = pChildNode->GetValue(0, NULL);

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_APP_BUFFER))
		{
			BYTE* pValue = new BYTE[nValueLen + 1];
			pChildNode->GetValue(pValue, nValueLen + 1);

			DWORD dwOutput = nValueLen + 1;
			BYTE* pOutput = new BYTE[dwOutput];
			memset(pOutput, 0x00, sizeof(dwOutput));
			CUtil::DecodeBase64(pValue, nValueLen, pOutput, dwOutput);

			/*//
			{
				CUtil::DumpFile(_T("E:/Work/dump_read"), pOutput, dwOutput);
			}
			//*/

			stAppInfo.m_iImageSize.push_back(dwOutput);
			stAppInfo.m_strImageBuffer.push_back(pOutput);

			delete[] pValue;
		
		}
	}

	return TRUE;
}


BOOL CXml::LoadApplicationConfigList(CXmlNode* pXmlNode, stAPPINFO& stAppInfo)
{
	if (NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		const int nValueLen = pChildNode->GetValue(0, NULL);

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_NAVINODE_APP_CONFIG))
		{
			CXmlAttribute* pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_NAME);
			TCHAR* pName = NULL;

			if (pXmlAttr)
			{
				const int nNameLen = pXmlAttr->GetValue(0, NULL);
				pName = new TCHAR[nNameLen + 1];
				pXmlAttr->GetValue(pName, nNameLen + 1);
			}

			TCHAR* pValue = new TCHAR[nValueLen + 1];
			pChildNode->GetValue(pValue, nValueLen + 1);

			string name = pName;
			string value = pValue;

			stAppInfo.m_AppconfName.push_back(name);
			stAppInfo.m_AppconfValue.push_back(value);

			if (pName)
				delete[] pName;

			if (pValue)
				delete[] pValue;
		}
	}

	return TRUE;
}

//
BOOL CXml::Save(TCHAR* pszPath, stSequenceManager* pstSequence)
{
	if (NULL == pszPath || NULL == pstSequence)
		return FALSE;

	CXmlNode* pXmlNode = SaveXml(pstSequence);

	BOOL bResult = FALSE;
	if (pXmlNode)
	{
		CXmlFile xmlFile;
		bResult = xmlFile.Save(pszPath, XML_NAVINODE_ROOT, pXmlNode);

		if (pXmlNode)
			delete pXmlNode;
	}
	else
	{
		return FALSE;
	}

	return TRUE;
}

CXmlNode* CXml::SaveXml(stSequenceManager* pstSequence)
{
	if (NULL == pstSequence)
		return NULL;

	CXmlNode* pXmlNode = new CXmlNode(XML_NAVINODE_ROOT, NULL);

	CXmlNode* pNode = NULL;

	pNode = CreateNode(pXmlNode, XML_NAVINODE_MODE, TYPE_XML_VALUE_SIGNED, &pstSequence->m_nTemplateMode, sizeof(int));
	pXmlNode->AddNode(pNode); delete pNode;

	pNode = CreateNodeString(pXmlNode, XML_NAVINODE_NAME, pstSequence->m_strTemplatename);
	pXmlNode->AddNode(pNode); delete pNode;

	pNode = CreateNodeString(pXmlNode, XML_NAVINODE_CREATEDATE, pstSequence->m_strTemplateCreateDate);
	pXmlNode->AddNode(pNode); delete pNode;

	pNode = CreateNodeString(pXmlNode, XML_NAVINODE_LASTDATE, pstSequence->m_strTemplateModifyDate);
	pXmlNode->AddNode(pNode); delete pNode;

	pNode = CreateNode(pXmlNode, XML_NAVINODE_PROTECT, TYPE_XML_VALUE_NONE, NULL, 0);
	CXmlNode* pChildNode = CreateNodeString(pNode, XML_NAVINODE_PASSWD, pstSequence->m_strTemplatePassword);
	pNode->AddNode(pChildNode); delete pChildNode;
	pXmlNode->AddNode(pNode); delete pNode;

	const int nCount = pstSequence->m_listSequence.size();

	pNode = CreateNode(pXmlNode, XML_NAVINODE_SEQMANAGER, TYPE_XML_VALUE_NONE, NULL, 0);
	AddAttributeInt(pNode, XML_NAVI_ATTR_COUNT, nCount);

	list<stSequence*>::iterator li;
	for (li = pstSequence->m_listSequence.begin(); li != pstSequence->m_listSequence.end(); li++)
	{
		CXmlNode* pSeqNode = SaveSequence(pNode, (stSequence*)*li);
		pNode->AddNode(pSeqNode); delete pSeqNode;
	}
	pXmlNode->AddNode(pNode); delete pNode;
	

	return pXmlNode;
}

CXmlNode* CXml::SaveSequence(CXmlNode* pParentNode, stSequence* pstSequence)
{
	if (NULL == pParentNode || NULL == pstSequence)
		return NULL;

	const int nCount = pstSequence->m_listImageBuffer.size();

	CXmlNode* pSeqNode = CreateNode(pParentNode, XML_NAVINODE_SEQUENCE, TYPE_XML_VALUE_NONE, NULL, 0);
	AddAttributeInt(pSeqNode, XML_NAVI_ATTR_COUNT, nCount); 

	list<stApplication*>::iterator li;
	for (li = pstSequence->m_listImageBuffer.begin(); li != pstSequence->m_listImageBuffer.end(); li++)
	{
		stApplication* pstApp = (stApplication*)*li;

		CXmlNode* pAppNode = SaveApplication(pSeqNode, pstApp);
		pSeqNode->AddNode(pAppNode); delete pAppNode;
	}
	return pSeqNode;
}

CXmlNode* CXml::SaveApplication(CXmlNode* pParentNode, stApplication* pstApp)
{
	if (NULL == pParentNode || NULL == pstApp)
		return NULL;

	CXmlNode* pAppNode = CreateNode(pParentNode, XML_NAVINODE_APPLICATION, TYPE_XML_VALUE_NONE, NULL, 0);
	CXmlNode* pNode = NULL;

	pNode = CreateNodeInt(pAppNode, XML_NAVINODE_APP_SEQINDEX, pstApp->m_iSequenceindex);
	pAppNode->AddNode(pNode); delete pNode;


	TCHAR szText[128] = { 0, };
	SetApplicationType(pstApp->m_eAppType, szText, 128);
	pNode = CreateNodeString(pAppNode, XML_NAVINODE_APP_TYPE, szText);
	pAppNode->AddNode(pNode); delete pNode;


	pNode = SaveApplicationInfo(pAppNode, &pstApp->m_stAppInfo);
	pAppNode->AddNode(pNode); delete pNode;

	pNode = SaveApplicationFilter(pAppNode, &pstApp->m_stAppFilter);
	pAppNode->AddNode(pNode); delete pNode;

	return pAppNode;
}

CXmlNode* CXml::SaveApplicationFilter(CXmlNode* pParentNode, stAPPFILTER* pstAppFilter)
{
	if (NULL == pParentNode || NULL == pstAppFilter)
		return NULL;

	CXmlNode* pAppFilter = CreateNode(pParentNode, XML_NAVINODE_APP_FILTER, TYPE_XML_VALUE_NONE, NULL, 0);

	AddAttributeInt(pAppFilter, XML_NAVI_ATTR_APPFILTER_NAME, pstAppFilter->m_nAppName);
	AddAttributeInt(pAppFilter, XML_NAVI_ATTR_APPFILTER_ROI, pstAppFilter->m_nRoi);
	AddAttributeInt(pAppFilter, XML_NAVI_ATTR_APPFILTER_ROIEDGE, pstAppFilter->m_nRoiEdge);
	AddAttributeInt(pAppFilter, XML_NAVI_ATTR_APPFILTER_FEATURE, pstAppFilter->m_nFeature);
	AddAttributeInt(pAppFilter, XML_NAVI_ATTR_APPFILTER_RESULT, pstAppFilter->m_nResult);
	AddAttributeInt(pAppFilter, XML_NAVI_ATTR_APPFILTER_IMAGE, pstAppFilter->m_nImage);

	return pAppFilter;
}


CXmlNode* CXml::SaveApplicationInfo(CXmlNode* pParentNode, stAPPINFO* pstAppInfo)
{
	if (NULL == pParentNode || NULL == pstAppInfo)
		return NULL;

	CXmlNode* pAppInfo = CreateNode(pParentNode, XML_NAVINODE_APP_INFO, TYPE_XML_VALUE_NONE, NULL, 0);
	CXmlNode* pNode = NULL;

	CString szText;

	szText = pstAppInfo->m_strPath.c_str();
	pNode = CreateNodeString(pAppInfo, XML_NAVINODE_APP_PATH, szText);
	pAppInfo->AddNode(pNode); delete pNode;

	szText = pstAppInfo->m_strAppName.c_str();
	pNode = CreateNodeString(pAppInfo, XML_NAVINODE_APP_NAME, szText);
	pAppInfo->AddNode(pNode); delete pNode;

	szText = pstAppInfo->m_strIndexROIReference.c_str();
	pNode = CreateNodeString(pAppInfo, XML_NAVINODE_APP_ROIREF, szText);
	pAppInfo->AddNode(pNode); delete pNode;

	szText = pstAppInfo->m_strIndexCalibrate.c_str();
	pNode = CreateNodeString(pAppInfo, XML_NAVINODE_APP_ROICOPY, szText);
	pAppInfo->AddNode(pNode); delete pNode;

	szText = pstAppInfo->m_strIndexSrcImage.c_str();
	pNode = CreateNodeString(pAppInfo, XML_NAVINODE_APP_SRCIMG, szText);
	pAppInfo->AddNode(pNode); delete pNode;


	// Image Buffer List...
	{
		const int nCount = pstAppInfo->m_iImageNum;
		pNode = CreateNode(pAppInfo, XML_NAVINODE_APP_IMAGELIST, TYPE_XML_VALUE_NONE, NULL, 0);
		AddAttributeInt(pNode, XML_NAVI_ATTR_COUNT, nCount);

		CXmlNode* pChildNode = NULL;

		for (int i = 0; i < nCount; i++)
		{
			pChildNode = CreateNode(pNode, XML_NAVINODE_APP_BUFFER, TYPE_XML_VALUE_BINARY, pstAppInfo->m_strImageBuffer[i], pstAppInfo->m_iImageSize[i]);

			AddAttributeInt(pChildNode, XML_NAVI_ATTR_SIZE, pstAppInfo->m_iImageSize[i]);
			pNode->AddNode(pChildNode); delete pChildNode;
		}
		pAppInfo->AddNode(pNode); delete pNode;
	}


	// Config List...
	{
		const int nCount = pstAppInfo->m_AppconfName.size();
		pNode = CreateNode(pAppInfo, XML_NAVINODE_APP_CONFIGLIST, TYPE_XML_VALUE_NONE, NULL, 0);
		AddAttributeInt(pNode, XML_NAVI_ATTR_COUNT, nCount);

		CXmlNode* pChildNode = NULL;
		CString szName;
		CString szText;

		for (int i = 0; i < nCount; i++)
		{
			szName = pstAppInfo->m_AppconfName[i].c_str();
			szText = pstAppInfo->m_AppconfValue[i].c_str();

			pChildNode = CreateNodeString(pNode, XML_NAVINODE_APP_CONFIG, szText);

			AddAttributeString(pChildNode, XML_NAVI_ATTR_NAME, szName);
			pNode->AddNode(pChildNode); delete pChildNode;
		}
		pAppInfo->AddNode(pNode); delete pNode;
	}


	pNode = SaveRoiInfo(pAppInfo, &pstAppInfo->m_CROI);
	pAppInfo->AddNode(pNode); delete pNode;

	// MULTI ROI
	{
		pNode = CreateNode(pAppInfo, XML_NAVINODE_ROI_LIST, TYPE_XML_VALUE_NONE, NULL, 0);
		
		const int nRoiCount = pstAppInfo->m_CMultiROI.size();
		for (int i = 0; i < nRoiCount; i++)
		{
			CXmlNode* pRoiNode = SaveRoiInfo(pNode, &(pstAppInfo->m_CMultiROI[i]));
			pNode->AddNode(pRoiNode); delete pRoiNode;
		}
		pAppInfo->AddNode(pNode); delete pNode;
	}


	return pAppInfo;
}

CXmlNode* CXml::SaveRoiInfo(CXmlNode* pParentNode, CLP_ROI* pRoi)
{
	if (NULL == pParentNode || NULL == pRoi)
		return NULL;

	CXmlNode* pRoiInfo = CreateNode(pParentNode, XML_NAVINODE_ROI_INFO, TYPE_XML_VALUE_NONE, NULL, 0);

	CXmlNode* pNode = NULL;
	TCHAR pText[128] = { 0, };

	SetRoiType(pRoi->m_eROIType, pText, 128);
	pNode = CreateNodeString(pRoiInfo, XML_NAVINODE_ROI_TYPE, pText);
	pRoiInfo->AddNode(pNode); delete pNode;


	SetRoiFaceType(pRoi->m_eROIFace, pText, 128);
	pNode = CreateNodeString(pRoiInfo, XML_NAVINODE_ROI_FACE, pText);
	pRoiInfo->AddNode(pNode); delete pNode;

	{
		pNode = CreateNode(pParentNode, XML_NAVINODE_ROI_POSITION, TYPE_XML_VALUE_NONE, NULL, 0);

		AddAttributeUnsignedInt(pNode, XML_NAVI_ATTR_W, pRoi->m_iROIWidth);
		AddAttributeUnsignedInt(pNode, XML_NAVI_ATTR_H, pRoi->m_iROIHeight);
		AddAttributeDouble(pNode, XML_NAVI_ATTR_ANGLE, pRoi->m_dROIAngle);

		if (eROIFace_Edge == pRoi->m_eROIFace)
		{
			if (eROIType_Rectangular == pRoi->m_eROIType || eROIType_RectangularRotate == pRoi->m_eROIType)
			{
				SetRoi4DirType(pRoi->m_eROIDirection.eROI4Direction, pText, 128);
				AddAttributeString(pNode, XML_NAVI_ATTR_DIRECTION, pText);
			}
			else if (eROIType_Circle == pRoi->m_eROIType || eROIType_Ring == pRoi->m_eROIType)
			{
				SetRoi2DirType(pRoi->m_eROIDirection.eROI2Direction, pText, 128);
				AddAttributeString(pNode, XML_NAVI_ATTR_DIRECTION, pText);
			}
			else
			{
				AddAttributeString(pNode, XML_NAVI_ATTR_DIRECTION, _T(""));
			}
		}
		else
		{
			AddAttributeString(pNode, XML_NAVI_ATTR_DIRECTION, _T(""));
		}

		CXmlNode* pChildNode = NULL;

		pChildNode = CreateNode(pNode, XML_NAVINODE_ROI_POINT, TYPE_XML_VALUE_NONE, NULL, 0);
		AddAttributeString(pChildNode, XML_NAVI_ATTR_NAME, XML_ROIPOINTTYPE_START);
		AddAttributeDouble(pChildNode, XML_NAVI_ATTR_X, pRoi->m_stPosROIStart.m_fX);
		AddAttributeDouble(pChildNode, XML_NAVI_ATTR_Y, pRoi->m_stPosROIStart.m_fY);
		pNode->AddNode(pChildNode); delete pChildNode;

		pChildNode = CreateNode(pNode, XML_NAVINODE_ROI_POINT, TYPE_XML_VALUE_NONE, NULL, 0);
		AddAttributeString(pChildNode, XML_NAVI_ATTR_NAME, XML_ROIPOINTTYPE_END);
		AddAttributeDouble(pChildNode, XML_NAVI_ATTR_X, pRoi->m_stPosROIEnd.m_fX);
		AddAttributeDouble(pChildNode, XML_NAVI_ATTR_Y, pRoi->m_stPosROIEnd.m_fY);
		pNode->AddNode(pChildNode); delete pChildNode;

		pChildNode = CreateNode(pNode, XML_NAVINODE_ROI_POINT, TYPE_XML_VALUE_NONE, NULL, 0);
		AddAttributeString(pChildNode, XML_NAVI_ATTR_NAME, XML_ROIPOINTTYPE_CENTER);
		AddAttributeDouble(pChildNode, XML_NAVI_ATTR_X, pRoi->m_stPosROICenter.m_fX);
		AddAttributeDouble(pChildNode, XML_NAVI_ATTR_Y, pRoi->m_stPosROICenter.m_fY);
		pNode->AddNode(pChildNode); delete pChildNode;


		pChildNode = CreateNode(pNode, XML_NAVINODE_ROI_POINTLIST, TYPE_XML_VALUE_NONE, NULL, 0);
		AddAttributeInt(pChildNode, XML_NAVI_ATTR_COUNT, pRoi->m_iCountPts);

		for (int i = 0; i < pRoi->m_iCountPts; i++)
		{
			if (pRoi->m_pstPosArray.size() < 1)
				continue;

			CXmlNode* pPointNode = CreateNode(pChildNode, XML_NAVINODE_ROI_POINT, TYPE_XML_VALUE_NONE, NULL, 0);
			AddAttributeDouble(pPointNode, XML_NAVI_ATTR_X, pRoi->m_pstPosArray[i].m_fX);
			AddAttributeDouble(pPointNode, XML_NAVI_ATTR_Y, pRoi->m_pstPosArray[i].m_fY);

			pChildNode->AddNode(pPointNode); delete pPointNode;
		}

		pNode->AddNode(pChildNode); delete pChildNode;
		pRoiInfo->AddNode(pNode); delete pNode;
	}

	pNode = CreateNodeUnsignedInt(pRoiInfo, XML_NAVINODE_ROI_STEP, pRoi->m_iStep);
	pRoiInfo->AddNode(pNode); delete pNode;

	{
		pNode = CreateNode(pRoiInfo, XML_NAVINODE_ROI_OPTION, TYPE_XML_VALUE_NONE, NULL, 0);

		{
			CXmlNode* pRingNode = CreateNode(pNode, XML_NAVINODE_ROI_RING, TYPE_XML_VALUE_NONE, NULL, 0);
			CXmlNode* pRingRangeNode = NULL;

			pRingRangeNode = CreateNode(pRingNode, XML_NAVINODE_ROI_RANGE, TYPE_XML_VALUE_NONE, NULL, 0);
			AddAttributeString(pRingRangeNode, XML_NAVI_ATTR_NAME, XML_RINGROIRANGE_RADIOUS);
			AddAttributeDouble(pRingRangeNode, XML_NAVI_ATTR_FROM, pRoi->m_dRadiusSmall);
			AddAttributeDouble(pRingRangeNode, XML_NAVI_ATTR_TO, pRoi->m_dRadiusLarge);
			pRingNode->AddNode(pRingRangeNode); delete pRingRangeNode;

			pRingRangeNode = CreateNode(pRingNode, XML_NAVINODE_ROI_RANGE, TYPE_XML_VALUE_NONE, NULL, 0);
			AddAttributeString(pRingRangeNode, XML_NAVI_ATTR_NAME, XML_RINGROIRANGE_ANGLE);
			AddAttributeDouble(pRingRangeNode, XML_NAVI_ATTR_FROM, pRoi->m_dAngleStart);
			AddAttributeDouble(pRingRangeNode, XML_NAVI_ATTR_TO, pRoi->m_dAngleEnd);
			pRingNode->AddNode(pRingRangeNode); delete pRingRangeNode;

			pNode->AddNode(pRingNode); delete pRingNode;
		}

		{
			CXmlNode* pCriteriaNode = CreateNode(pNode, XML_NAVINODE_ROI_CRITERIA, TYPE_XML_VALUE_NONE, NULL, 0);
			CXmlNode* pCriteriaPointNode = NULL;

			pCriteriaPointNode = CreateNode(pCriteriaNode, XML_NAVINODE_ROI_POINT, TYPE_XML_VALUE_NONE, NULL, 0);
			AddAttributeString(pCriteriaPointNode, XML_NAVI_ATTR_NAME, XML_ROIPOINTTYPE_CRITERIA);
			AddAttributeDouble(pCriteriaPointNode, XML_NAVI_ATTR_X, pRoi->m_stPosCriteria.m_fX);
			AddAttributeDouble(pCriteriaPointNode, XML_NAVI_ATTR_Y, pRoi->m_stPosCriteria.m_fY);
			pCriteriaNode->AddNode(pCriteriaPointNode); delete pCriteriaPointNode;


			AddAttributeDouble(pCriteriaNode, XML_NAVI_ATTR_MODE, pRoi->m_iModeCriteria);
			AddAttributeDouble(pCriteriaNode, XML_NAVI_ATTR_ANGLE, pRoi->m_dAngleCriteria);

			pNode->AddNode(pCriteriaNode); delete pCriteriaNode;
		}

		pRoiInfo->AddNode(pNode); delete pNode;
	}


	{
		pNode = CreateNode(pRoiInfo, XML_NAVINODE_ROI_MASK, TYPE_XML_VALUE_NONE, NULL, 0);

		CXmlNode* pChildNode = CreateNode(pNode, XML_NAVINODE_APP_BUFFER, TYPE_XML_VALUE_NONE, NULL, 0);
		AddAttributeInt(pChildNode, XML_NAVI_ATTR_SIZE, 0);

		pNode->AddNode(pChildNode); delete pChildNode;
		pRoiInfo->AddNode(pNode); delete pNode;
	}


	return pRoiInfo;
}
#endif


////////////////////////////////////////////////////////////////////
// Default Camera information
BOOL CXml::LoadDefCamera(TCHAR* pszPath, CCameraDevice& DefDevice)
{
	if (NULL == pszPath)
		return FALSE;
	DefDevice.ClearAll();

	CXmlFile xmlFile;
	CXmlNode* pXmlNode = xmlFile.Load(pszPath, XML_CAMERANODE_ROOT);

	BOOL bResult = LoadXml(DefDevice, pXmlNode);
	if (pXmlNode)
	{
		delete pXmlNode;
	}

	return bResult;
}

//
BOOL CXml::LoadXml(CCameraDevice& DefDevice, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_GIGE))
			LoadCamera(pChildNode, TYPE_NETWORK_GIGE, DefDevice);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_ETHERNET))
			LoadCamera(pChildNode, TYPE_NETWORK_ETHERNET, DefDevice);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_USB))
			LoadCamera(pChildNode, TYPE_NETWORK_USB, DefDevice);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAMERALINK))
			LoadCameraCL(pChildNode, TYPE_NETWORK_CAMERALINK, DefDevice);

	}

	return TRUE;
}

BOOL CXml::LoadCamera(CXmlNode* pXmlNode, TYPE_NETWORK eNetwork, CCameraDevice& DefDevice)
{
	if (NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();

	INFO_DEFDEV stDefDev;

	CXmlAttribute* pXmlAttr = NULL;
	TCHAR* pName = NULL;

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAMERA))
		{
			memset(&stDefDev, 0x00, sizeof(INFO_DEFDEV));
			stDefDev.m_eNetwork = eNetwork;

			if (LoadCamera(pChildNode, &stDefDev))
			{
				pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_NAME);
				if (pXmlAttr)
					pXmlAttr->GetValue(stDefDev.m_szName, MAX_NAME_LEN);

				DefDevice.AddDefaultDevice(&stDefDev);
			}
		}
	}

	return TRUE;
}

BOOL CXml::LoadCamera(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev)
{
	if (NULL == pXmlNode || NULL == pstDefDev)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_DATABITS))
			LoadCameraDataBits(pChildNode, pstDefDev);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_COLOR))
			LoadCameraColor(pChildNode, pstDefDev);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_MTU))
			LoadCameraMTU(pChildNode, pstDefDev);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_ROI))
			LoadCameraRoi(pChildNode, pstDefDev);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_GAIN))
			LoadCameraGain(pChildNode, pstDefDev);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_EXPOSURE))
			LoadCameraExposure(pChildNode, pstDefDev);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_FRAMERATE))
			LoadCameraFramerate(pChildNode, pstDefDev);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_TRIGGER))
			LoadCameraTrigger(pChildNode, pstDefDev);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_STROBE))
			LoadCameraStrobe(pChildNode, pstDefDev);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_SYMMETRY))
			LoadCameraSymmetry(pChildNode, pstDefDev);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_LUT))
			LoadCameraLut(pChildNode, pstDefDev);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_EFFECT))
			LoadCameraEffect(pChildNode, pstDefDev);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_USERSET))
			LoadCameraUserset(pChildNode, pstDefDev);

	}

	return TRUE;
}


BOOL CXml::LoadCameraCL(CXmlNode* pXmlNode, TYPE_NETWORK eNetwork, CCameraDevice& DefDevice)
{
	if (NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();

	INFO_DEFDEV_CL stDefDevCL;

	CXmlAttribute* pXmlAttr = NULL;
	TCHAR* pName = NULL;

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_FRAMEGRABBER))
		{
			LoadFramegrabber(pChildNode, DefDevice);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAMERA))
		{
			memset(&stDefDevCL, 0x00, sizeof(INFO_DEFDEV_CL));
			stDefDevCL.m_stDefDev.m_eNetwork = eNetwork;

			if (LoadCameraCL(pChildNode, &stDefDevCL))
			{
				pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_NAME);
				if (pXmlAttr)
				{
					pXmlAttr->GetValue(stDefDevCL.m_stDefDev.m_szName, MAX_NAME_LEN);

					if (CUtil::StringCompare(stDefDevCL.m_stDefDev.m_szName, XML_CLMODEL_CLN25M))
						stDefDevCL.m_eCLDevice = TYPE_CLDEVICE_N25M;
					else if (CUtil::StringCompare(stDefDevCL.m_stDefDev.m_szName, XML_CLMODEL_CL25M))
						stDefDevCL.m_eCLDevice = TYPE_CLDEVICE_25M;
					else if (CUtil::StringCompare(stDefDevCL.m_stDefDev.m_szName, XML_CLMODEL_CL4M))
						stDefDevCL.m_eCLDevice = TYPE_CLDEVICE_4M;
					else if (CUtil::StringCompare(stDefDevCL.m_stDefDev.m_szName, XML_CLMODEL_CL2M))
						stDefDevCL.m_eCLDevice = TYPE_CLDEVICE_2M;
					else
						continue;
				}

				DefDevice.AddDefaultDevice((INFO_DEFDEV*)&stDefDevCL);
			}
		}
	}

	return TRUE;
}


BOOL CXml::LoadCameraCL(CXmlNode* pXmlNode, INFO_DEFDEV_CL* pstDefDev)
{
	if (NULL == pXmlNode || NULL == pstDefDev)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_ROI))
			LoadCameraRoi(pChildNode, &pstDefDev->m_stDefDev);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_GAIN))
			LoadCameraGain(pChildNode, &pstDefDev->m_stDefDev);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_EXPOSURE))
			LoadCameraExposure(pChildNode, &pstDefDev->m_stDefDev);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_FRAMERATE))
			LoadCameraFramerate(pChildNode, &pstDefDev->m_stDefDev);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_TRIGGER))
			LoadCameraTrigger(pChildNode, &pstDefDev->m_stDefDev);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_STROBE))
			LoadCameraStrobe(pChildNode, &pstDefDev->m_stDefDev);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_SYMMETRY))
			LoadCameraSymmetry(pChildNode, &pstDefDev->m_stDefDev);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_LUT))
			LoadCameraLut(pChildNode, &pstDefDev->m_stDefDev);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_EFFECT))
			LoadCameraEffect(pChildNode, &pstDefDev->m_stDefDev);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_USERSET))
			LoadCameraUserset(pChildNode, &pstDefDev->m_stDefDev);

		// Camera Link
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CLCAM_IMAGETAPS))
			LoadCameraImageTaps(pChildNode, pstDefDev);
	}

	return TRUE;
}

BOOL CXml::LoadFramegrabber(CXmlNode* pXmlNode, CCameraDevice& DefDevice)
{
	if (NULL == pXmlNode)
		return FALSE;

	// Node
	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_GRABBER))
		{
			LoadGrabber(pChildNode, DefDevice);
		}
	}

	return TRUE;
}

BOOL CXml::LoadGrabber(CXmlNode* pXmlNode, CCameraDevice& DefDevice)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;
	TYPE_CLGRABBER eFrameGrabber = TYPE_CLGRABBER_NONE;

	BOOL bSupport = FALSE;
	// Support
	{
		pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
		if (pXmlAttr)
		{
			const int nTxtLen = pXmlAttr->GetValue(0, NULL);
			TCHAR* pTxt = new TCHAR[nTxtLen + 1];
			pXmlAttr->GetValue(pTxt, nTxtLen + 1);

			GetBoolean(bSupport, pTxt);

			if (pTxt) delete[] pTxt;
		}
	}
	if (FALSE == bSupport)
		return FALSE;


	// Frame Grabber
	{
		TCHAR szName[MAX_NAME_LEN] = { 0, };

		pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_NAME);
		if (pXmlAttr)
			pXmlAttr->GetValue(szName, MAX_NAME_LEN);

		if (CUtil::StringCompare(XML_CLGRABBER_EURESYS, szName))
			eFrameGrabber = TYPE_CLGRABBER_EURESYS;
		else if (CUtil::StringCompare(XML_CLGRABBER_SILICON, szName))
			eFrameGrabber = TYPE_CLGRABBER_SILICONSOFTWARE;
		else if (CUtil::StringCompare(XML_CLGRABBER_MATROX, szName))
			eFrameGrabber = TYPE_CLGRABBER_MATROX;
		else
			return FALSE;
	}


	INFO_FRAMEGRABBER_CAMFILE stCamfile;
	// Node
	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		memset(&stCamfile, 0x00, sizeof(INFO_FRAMEGRABBER_CAMFILE));

		const TCHAR* pTitle = pChildNode->GetTitle();
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAMFILE))
		{
			if (LoadCamfile(pChildNode, &stCamfile))
			{
				stCamfile.m_eGrabber = eFrameGrabber;
				DefDevice.AddCamfile(&stCamfile);
			}
		}
	}

	return TRUE;
}


BOOL CXml::LoadCamfile(CXmlNode* pXmlNode, INFO_FRAMEGRABBER_CAMFILE* pstGrabber)
{
	if (NULL == pXmlNode || NULL == pstGrabber)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	TCHAR szTxt[MAX_TEXT_LEN] = { 0, };

	// CLCamera Name
	{
		pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_CLMODEL);
		if (pXmlAttr)
			pXmlAttr->GetValue(szTxt, MAX_TEXT_LEN);

		if (CUtil::StringICompare(XML_CLMODEL_CLN25M, szTxt))
			pstGrabber->m_eModelType = TYPE_CLDEVICE_N25M;
		else if (CUtil::StringICompare(XML_CLMODEL_CL25M, szTxt))
			pstGrabber->m_eModelType = TYPE_CLDEVICE_25M;
		else if (CUtil::StringICompare(XML_CLMODEL_CL4M, szTxt))
			pstGrabber->m_eModelType = TYPE_CLDEVICE_4M;
		else if (CUtil::StringICompare(XML_CLMODEL_CL2M, szTxt))
			pstGrabber->m_eModelType = TYPE_CLDEVICE_2M;
		else
			return FALSE;
	}

	// Image Tap
	{
		DWORD tap = 0;
		pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_CLIMAGETAP);
		if (pXmlAttr)
			pXmlAttr->GetValue(&tap, sizeof(DWORD));

		if (10 == tap)
			pstGrabber->m_eImageTap = TYPE_CLIMGTAPS_10;
		else if (8 == tap)
			pstGrabber->m_eImageTap = TYPE_CLIMGTAPS_08;
		else if (4 == tap)
			pstGrabber->m_eImageTap = TYPE_CLIMGTAPS_04;
		else if (2 == tap)
			pstGrabber->m_eImageTap = TYPE_CLIMGTAPS_02;
		else
			return FALSE;
	}

	// Data Bit
	{
		int databit = 0;
		pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_CLDATABIT);
		if (pXmlAttr)
			pXmlAttr->GetValue(&databit, sizeof(int));
		if (10 == databit)
			pstGrabber->m_eDataBit = TYPE_CLDATABIT_10;
		else if (8 == databit)
			pstGrabber->m_eDataBit = TYPE_CLDATABIT_08;
		else
			return FALSE;
	}

	// Color Type
	{
		pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_CLCOLORTYPE);
		if (pXmlAttr)
			pXmlAttr->GetValue(szTxt, MAX_TEXT_LEN);

		if (CUtil::StringICompare(XML_COLOR_MONO, szTxt))
			pstGrabber->m_eColor = TYPE_CAMCOLOR_MONO;
		else if (CUtil::StringICompare(XML_COLOR_MONO, szTxt))
			pstGrabber->m_eColor = TYPE_CAMCOLOR_COLOR;
		else
			return FALSE;
	}

	// CAM File
	{
		// Node
		const int nCount = pXmlNode->GetNodeCount();

		for (int i = 0; i < nCount; i++)
		{
			CXmlNode* pChildNode = pXmlNode->GetNode(i);
			if (NULL == pChildNode)
				continue;

			const TCHAR* pTitle = pChildNode->GetTitle();

			if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAMFILE_ITEM))
			{
				LoadCamfileFromTrigger(pChildNode, pstGrabber);
			}
		}
	}
	

	return TRUE;
}

BOOL CXml::LoadCamfileFromTrigger(CXmlNode* pXmlNode, INFO_FRAMEGRABBER_CAMFILE* pstGrabber)
{
	if (NULL == pXmlNode || NULL == pstGrabber)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	TCHAR szTxt[MAX_TEXT_LEN] = { 0, };
	BOOL bTrigger = FALSE;

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_CLTRIGGERMODE);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(szTxt, MAX_TEXT_LEN);
		GetBoolean(bTrigger, szTxt);
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_CLCAMFILE);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(szTxt, MAX_TEXT_LEN);
		if (bTrigger)
			CUtil::StringCopy(pstGrabber->m_szCamFile[CLCAMFILE_TRIGGER], szTxt);
		else
			CUtil::StringCopy(pstGrabber->m_szCamFile[CLCAMFILE_NORMAL], szTxt);
	}


	return TRUE;
}


BOOL CXml::LoadCameraDataBits(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev)
{
	if (NULL == pXmlNode || NULL == pstDefDev)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Node
	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_BIT))
		{
			LoadCameraBit(pChildNode, &pstDefDev->m_stDefDataBit);
		}
	}

	// Attribute
	BOOL bEnable = FALSE;

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(bEnable, pTxt);

		if (pTxt) delete[] pTxt;
	}

	pstDefDev->m_stDefDataBit.m_bSupport = bEnable;


	return TRUE;
}

BOOL CXml::LoadCameraBit(CXmlNode* pXmlNode, INFO_DEFDATABIT* pstDefDataBit)
{
	if (NULL == pXmlNode || NULL == pstDefDataBit)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;
	BOOL bEnable = FALSE;
	
	TYPE_DATABIT eDataBit = TYPE_DATABIT_NONE;
	int nDataBit = 0;

	//
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_DATABIT);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&nDataBit, sizeof(int));
	}

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(bEnable, pTxt);

		if (pTxt) delete[] pTxt;
	}

	BOOL bResult = GetDataBit(eDataBit, nDataBit);
	if (bResult)
		pstDefDataBit->m_bSupportDataBit[eDataBit] = bEnable;
	
	return bResult;
}

BOOL CXml::LoadCameraColor(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev)
{
	if (NULL == pXmlNode || NULL == pstDefDev)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_COLORFORMAT))
			LoadCameraColorFormat(pChildNode, &(pstDefDev->m_stDefColor.m_stColorFormat));

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_PIXELFORMAT))
			LoadCameraPixelFormat(pChildNode, &(pstDefDev->m_stDefColor.m_stPixelFormat));

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_RGBGAIN))
			LoadCameraPixelRgbGain(pChildNode, &(pstDefDev->m_stDefColor.m_stColorGain));
	}

	// Attribute
	CXmlAttribute* pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefDev->m_stDefColor.m_bSupport, pTxt);

		if (pTxt) delete[] pTxt;
	}

	return TRUE;
}

BOOL CXml::LoadCameraColorFormat(CXmlNode* pXmlNode, INFO_DEFCOLORFORMAT* pstDefColorFormat)
{
	if (NULL == pXmlNode || NULL == pstDefColorFormat)
		return FALSE;

	// Attribute
	CXmlAttribute* pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefColorFormat->m_bSupport, pTxt);

		if (pTxt) delete[] pTxt;
	}

	return TRUE;
}

BOOL CXml::LoadCameraPixelFormat(CXmlNode* pXmlNode, INFO_DEFPIXELFORMAT* pstDefPixelFormat)
{
	if (NULL == pXmlNode || NULL == pstDefPixelFormat)
		return FALSE;

	// Attribute
	CXmlAttribute* pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefPixelFormat->m_bSupport, pTxt);

		if (pTxt) delete[] pTxt;
	}

	if (pstDefPixelFormat->m_bSupport)
	{
		const int nCount = pXmlNode->GetNodeCount();

		for (int i = 0; i < nCount; i++)
		{
			CXmlNode* pChildNode = pXmlNode->GetNode(i);
			if (NULL == pChildNode)
				continue;

			const TCHAR* pTitle = pChildNode->GetTitle();

			if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_PIXEL))
				LoadCameraPixel(pChildNode, pstDefPixelFormat);
		}
	}

	return TRUE;
}

BOOL CXml::LoadCameraPixel(CXmlNode* pXmlNode, INFO_DEFPIXELFORMAT* pstDefPixelFormat)
{
	if (NULL == pXmlNode || NULL == pstDefPixelFormat)
		return FALSE;

	BOOL bSupport = FALSE;
	TYPE_DATABIT eDataBit = TYPE_DATABIT_NONE;

	// Attribute
	{
		CXmlAttribute* pXmlAttr = NULL;

		pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
		if (pXmlAttr)
		{
			const int nTxtLen = pXmlAttr->GetValue(0, NULL);
			TCHAR* pTxt = new TCHAR[nTxtLen + 1];
			pXmlAttr->GetValue(pTxt, nTxtLen + 1);

			GetBoolean(bSupport, pTxt);

			if (pTxt) delete[] pTxt;
		}

		// Data Bit
		int databit = 0;
		pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_CLDATABIT);
		if (pXmlAttr)
			pXmlAttr->GetValue(&databit, sizeof(int));
		if (12 == databit)
			eDataBit = TYPE_DATABIT_12;
		else if (10 == databit)
			eDataBit = TYPE_DATABIT_10;
		else if (8 == databit)
			eDataBit = TYPE_DATABIT_08;
		else
			return FALSE;
	}


	pstDefPixelFormat->m_pstPixel[eDataBit].m_bSupport = bSupport;
	pstDefPixelFormat->m_pstPixel[eDataBit].m_eDatabit = eDataBit;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_ITEM))
			LoadCameraPixelItem(pChildNode, &(pstDefPixelFormat->m_pstPixel[eDataBit]));
	}

	return TRUE;
}


BOOL CXml::LoadCameraPixelItem(CXmlNode* pXmlNode, INFO_DEFPIXEL* pstDefPixel)
{
	if (NULL == pXmlNode || NULL == pstDefPixel)
		return FALSE;

	TCHAR szTxt[MAX_NAME_LEN] = { 0, };
	
	BOOL bSupport = FALSE;
	TYPE_CAMCOLORFORMAT eColorFormat = TYPE_CAMCOLORFORMAT_NONE;

	// Attribute
	CXmlAttribute* pXmlAttr = NULL;

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(bSupport, pTxt);

		if (pTxt) delete[] pTxt;
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_NAME);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(szTxt, MAX_NAME_LEN);

		if (CUtil::StringCompare(XML_COLOR_PIXELFORMAT_MONO, szTxt))
			eColorFormat = TYPE_CAMCOLORFORMAT_MONO;
		else if (CUtil::StringCompare(XML_COLOR_PIXELFORMAT_BAYERGR, szTxt))
			eColorFormat = TYPE_CAMCOLORFORMAT_BAYER_GR;
		else if (CUtil::StringCompare(XML_COLOR_PIXELFORMAT_BAYERRG, szTxt))
			eColorFormat = TYPE_CAMCOLORFORMAT_BAYER_RG;
		else if (CUtil::StringCompare(XML_COLOR_PIXELFORMAT_BAYERGB, szTxt))
			eColorFormat = TYPE_CAMCOLORFORMAT_BAYER_GB;
		else if (CUtil::StringCompare(XML_COLOR_PIXELFORMAT_BAYERBG, szTxt))
			eColorFormat = TYPE_CAMCOLORFORMAT_BAYER_BG;
		else
			return FALSE;
	}

	pstDefPixel->m_pColorList[eColorFormat] = bSupport;

	return TRUE;
}

BOOL CXml::LoadCameraPixelRgbGain(CXmlNode* pXmlNode, INFO_DEFCOLORGAIN* pstDefColorGain)
{
	if (NULL == pXmlNode || NULL == pstDefColorGain)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefColorGain->m_bSupport, pTxt);

		if (pTxt) delete[] pTxt;
	}

	if (pstDefColorGain->m_bSupport)
	{
		DWORD dwType = 0;

		// Node
		const int nCount = pXmlNode->GetNodeCount();

		for (int i = 0; i < nCount; i++)
		{
			CXmlNode* pChildNode = pXmlNode->GetNode(i);
			if (NULL == pChildNode)
				continue;


			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_TYPE);
			if (pXmlAttr)
				pXmlAttr->GetValue(&dwType, sizeof(DWORD));

			INFO_DEFGAIN* pstGain = NULL;
			if (1 == dwType)		pstGain = &pstDefColorGain->m_RedGain;
			else if (2 == dwType)	pstGain = &pstDefColorGain->m_GreenGain;
			else if (3 == dwType)	pstGain = &pstDefColorGain->m_BlueGain;
			else if (4 == dwType)	pstGain = &pstDefColorGain->m_GreenGain2;
			else return FALSE;


			const TCHAR* pTitle = pChildNode->GetTitle();

			if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_GAIN))
			{
				LoadCameraPixelGain(pChildNode, pstGain);
			}
		}
	}

	return TRUE;

}

BOOL CXml::LoadCameraPixelGain(CXmlNode* pXmlNode, INFO_DEFGAIN* pstDefGain)
{
	if (NULL == pXmlNode || NULL == pstDefGain)
		return FALSE;

	// Node
	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_RANGE))
		{
			LoadCameraRange(pChildNode, &(pstDefGain->m_stRange));
		}
	}

	return TRUE;
}

BOOL CXml::LoadCameraMTU(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev)
{
	if (NULL == pXmlNode || NULL == pstDefDev)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefDev->m_stDefMTU.m_bSupport, pTxt);

		if (pTxt) delete[] pTxt;
	}

	return TRUE;
}


BOOL CXml::LoadCameraRoi(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev)
{
	if (NULL == pXmlNode || NULL == pstDefDev)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Node
	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_ROI_UNIT))
		{
			double fX = 0.0f;
			double fY = 0.0f;

			DWORD dwW = 0;
			DWORD dwH = 0;

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_X);
			if (pXmlAttr)
				pXmlAttr->GetValue(&fX, sizeof(double));
			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_Y);
			if (pXmlAttr)
				pXmlAttr->GetValue(&fY, sizeof(double));

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_W);
			if (pXmlAttr)
				pXmlAttr->GetValue(&dwW, sizeof(DWORD));
			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_H);
			if (pXmlAttr)
				pXmlAttr->GetValue(&dwH, sizeof(DWORD));


			pstDefDev->m_stDefROI.m_nUnitX = (int)fX;
			pstDefDev->m_stDefROI.m_nUnitY = (int)fY;

			pstDefDev->m_stDefROI.m_nUnitW = (int)dwW;
			pstDefDev->m_stDefROI.m_nUnitH = (int)dwH;

		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_ROI_MIN))
		{
			DWORD dwW = 0;
			DWORD dwH = 0;

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_W);
			if (pXmlAttr)
				pXmlAttr->GetValue(&dwW, sizeof(DWORD));

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_H);
			if (pXmlAttr)
				pXmlAttr->GetValue(&dwH, sizeof(DWORD));

			pstDefDev->m_stDefROI.m_nMinWidth = dwW;
			pstDefDev->m_stDefROI.m_nMinHeight = dwH;
		}
	}


	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefDev->m_stDefROI.m_bSupport, pTxt);

		if (pTxt) delete[] pTxt;
	}

	return TRUE;
}

BOOL CXml::LoadCameraGain(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev)
{
	if (NULL == pXmlNode || NULL == pstDefDev)
		return FALSE;

	DWORD dwType = 0;

	CXmlAttribute* pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_TYPE);
	if (pXmlAttr)
		pXmlAttr->GetValue(&dwType, sizeof(DWORD));

	INFO_DEFGAIN* pstGain = NULL;
	if (1 == dwType)		pstGain = &pstDefDev->m_stDefGain01;
	else if (2 == dwType)	pstGain = &pstDefDev->m_stDefGain02;
	else return FALSE;

	// Node
	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_RANGE))
		{
			LoadCameraRange(pChildNode, &(pstGain->m_stRange));
		}
	}


	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstGain->m_bSupport, pTxt);

		if (pTxt) delete[] pTxt;
	}

	return TRUE;
}

BOOL CXml::LoadCameraExposure(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev)
{
	if (NULL == pXmlNode || NULL == pstDefDev)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Node
	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_RANGE))
		{
			LoadCameraRange(pChildNode, &(pstDefDev->m_stDefExposure.m_stRange));
		}
	}


	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefDev->m_stDefExposure.m_bSupport, pTxt);

		if (pTxt) delete[] pTxt;
	}

	return TRUE;
}

BOOL CXml::LoadCameraFramerate(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev)
{
	if (NULL == pXmlNode || NULL == pstDefDev)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Node
	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_RANGE))
		{
			LoadCameraRange(pChildNode, &(pstDefDev->m_stDefFrameRate.m_stRange));
		}
	}


	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefDev->m_stDefFrameRate.m_bSupport, pTxt);

		if (pTxt) delete[] pTxt;
	}


	return TRUE;
}

BOOL CXml::LoadCameraTrigger(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev)
{
	if (NULL == pXmlNode || NULL == pstDefDev)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Node
	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_TRIGGER_DELAY))
		{
			LoadCameraTriggerDelay(pChildNode, pstDefDev);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_TRIGGER_TYPE))
		{
			LoadCameraTriggerType(pChildNode, pstDefDev);
		}
	}

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefDev->m_stDefTrigger.m_bSupport, pTxt);

		if (pTxt) delete[] pTxt;
	}


	return TRUE;
}

BOOL CXml::LoadCameraTriggerDelay(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev)
{
	if (NULL == pXmlNode || NULL == pstDefDev)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Node
	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_RANGE))
		{
			LoadCameraRange(pChildNode, &(pstDefDev->m_stDefTrigger.m_stDelayRange));
		}
	}

	return TRUE;
}

BOOL CXml::LoadCameraTriggerType(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev)
{
	if (NULL == pXmlNode || NULL == pstDefDev)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Node
	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_ITEM))
		{
			TYPE_TRIGGERTYPE eTriggerType = TYPE_TRIGGERTYPE_NONE;
			BOOL bSupport = FALSE;

			// Attribute
			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_NAME);
			if (pXmlAttr)
			{
				const int nTxtLen = pXmlAttr->GetValue(0, NULL);
				TCHAR* pTxt = new TCHAR[nTxtLen + 1];
				pXmlAttr->GetValue(pTxt, nTxtLen + 1);

				if (CUtil::StringICompare((LPTSTR)pTxt, _T("EDGE")))
					eTriggerType = TYPE_TRIGGERTYPE_EDGE;
				else if (CUtil::StringICompare((LPTSTR)pTxt, _T("LEVEL")))
					eTriggerType = TYPE_TRIGGERTYPE_LEVEL;

				if (pTxt) delete[] pTxt;
			}

			pXmlAttr = pChildNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
			if (pXmlAttr)
			{
				const int nTxtLen = pXmlAttr->GetValue(0, NULL);
				TCHAR* pTxt = new TCHAR[nTxtLen + 1];
				pXmlAttr->GetValue(pTxt, nTxtLen + 1);

				GetBoolean(bSupport, pTxt);

				if (pTxt) delete[] pTxt;
			}

			pstDefDev->m_stDefTrigger.m_bTriggerTypeSupport[eTriggerType] = bSupport;

		}
	}

	return TRUE;
}


BOOL CXml::LoadCameraStrobe(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev)
{
	if (NULL == pXmlNode || NULL == pstDefDev)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Node
	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_STROBE_SYNC))
			LoadCameraStrobeSync(pChildNode, pstDefDev);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_STROBE_DELAY))
			LoadCameraStrobeDelay(pChildNode, pstDefDev);

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_STROBE_WIDTH))
			LoadCameraStrobeWidth(pChildNode, pstDefDev);
	}

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefDev->m_stDefStrobe.m_bSupport, pTxt);

		if (pTxt) delete[] pTxt;
	}

	return TRUE;
}

BOOL CXml::LoadCameraStrobeSync(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev)
{
	if (NULL == pXmlNode || NULL == pstDefDev)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefDev->m_stDefStrobe.m_bSupportSync, pTxt);

		if (pTxt) delete[] pTxt;
	}
	return TRUE;
}

BOOL CXml::LoadCameraStrobeDelay(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev)
{
	if (NULL == pXmlNode || NULL == pstDefDev)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Node
	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_RANGE))
		{
			LoadCameraRange(pChildNode, &(pstDefDev->m_stDefStrobe.m_stDelayRange));
		}
	}

	return TRUE;
}

BOOL CXml::LoadCameraStrobeWidth(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev)
{
	if (NULL == pXmlNode || NULL == pstDefDev)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Node
	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_RANGE))
		{
			LoadCameraRange(pChildNode, &(pstDefDev->m_stDefStrobe.m_stWidthRange));
		}
	}

	return TRUE;
}

BOOL CXml::LoadCameraSymmetry(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev)
{
	if (NULL == pXmlNode || NULL == pstDefDev)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefDev->m_stDefSymmetry.m_bSupport, pTxt);

		if (pTxt) delete[] pTxt;
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORTH);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefDev->m_stDefSymmetry.m_bSupportHorizontal, pTxt);

		if (pTxt) delete[] pTxt;
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORTV);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefDev->m_stDefSymmetry.m_bSupportVertical, pTxt);

		if (pTxt) delete[] pTxt;
	}


	return TRUE;
}

BOOL CXml::LoadCameraLut(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev)
{
	if (NULL == pXmlNode || NULL == pstDefDev)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_INDEX))
			LoadCameraRange(pChildNode, &(pstDefDev->m_stDefLut.m_stIndexRange));

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_RANGE))
			LoadCameraRange(pChildNode, &(pstDefDev->m_stDefLut.m_stValueRange));
	}

	// Attribute
	BOOL bEnable = FALSE;

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(bEnable, pTxt);

		if (pTxt) delete[] pTxt;
	}
	pstDefDev->m_stDefLut.m_bSupport = bEnable;


	bEnable = FALSE;
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SEPARATE);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(bEnable, pTxt);

		if (pTxt) delete[] pTxt;
	}
	pstDefDev->m_stDefLut.m_bSeparatedIndex = bEnable;


	return TRUE;
}

BOOL CXml::LoadCameraEffect(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev)
{
	if (NULL == pXmlNode || NULL == pstDefDev)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_EFFECT_NR))
			LoadCameraEffectNR(pChildNode, &(pstDefDev->m_stDefEffectNR));

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_EFFECT_GC))
			LoadCameraEffectGC(pChildNode, &(pstDefDev->m_stDefEffectGC));

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_EFFECT_CM))
			LoadCameraEffectCM(pChildNode, &(pstDefDev->m_stDefEffectCM));

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_EFFECT_AWB))
			LoadCameraEffectAWB(pChildNode, &(pstDefDev->m_stDefEffectAWB));

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_EFFECT_FPN))
			LoadCameraEffectFPN(pChildNode, &(pstDefDev->m_stDefEffectFPN));

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_EFFECT_PRNU))
			LoadCameraEffectPRNU(pChildNode, &(pstDefDev->m_stDefEffectPRNU));

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_EFFECT_DPC))
			LoadCameraEffectDPC(pChildNode, &(pstDefDev->m_stDefEffectDPC));

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_EFFECT_SMOTH))
			LoadCameraEffectSmoth(pChildNode, &(pstDefDev->m_stDefEffectSmoth));

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_EFFECT_SHARPEN))
			LoadCameraEffectSharpen(pChildNode, &(pstDefDev->m_stDefEffectSharpen));

	}

	return TRUE;
}

BOOL CXml::LoadCameraEffectNR(CXmlNode* pXmlNode, INFO_DEFEFFECT* pstDefEffect)
{
	if (NULL == pXmlNode || NULL == pstDefEffect)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefEffect->m_bSupport, pTxt);

		if (pTxt) delete[] pTxt;
	}

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_UPLOAD);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefEffect->m_bSupportUpload, pTxt);

		if (pTxt) delete[] pTxt;
	}


	return TRUE;
}

BOOL CXml::LoadCameraEffectGC(CXmlNode* pXmlNode, INFO_DEFEFFECT* pstDefEffect)
{
	if (NULL == pXmlNode || NULL == pstDefEffect)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefEffect->m_bSupport, pTxt);

		if (pTxt) delete[] pTxt;
	}

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_UPLOAD);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefEffect->m_bSupportUpload, pTxt);

		if (pTxt) delete[] pTxt;
	}


	return TRUE;
}

BOOL CXml::LoadCameraEffectCM(CXmlNode* pXmlNode, INFO_DEFEFFECT* pstDefEffect)
{
	if (NULL == pXmlNode || NULL == pstDefEffect)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefEffect->m_bSupport, pTxt);

		if (pTxt) delete[] pTxt;
	}

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_UPLOAD);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefEffect->m_bSupportUpload, pTxt);

		if (pTxt) delete[] pTxt;
	}

	return TRUE;
}

BOOL CXml::LoadCameraEffectAWB(CXmlNode* pXmlNode, INFO_DEFEFFECT* pstDefEffect)
{
	if (NULL == pXmlNode || NULL == pstDefEffect)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefEffect->m_bSupport, pTxt);

		if (pTxt) delete[] pTxt;
	}

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_UPLOAD);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefEffect->m_bSupportUpload, pTxt);

		if (pTxt) delete[] pTxt;
	}

	return TRUE;
}

BOOL CXml::LoadCameraEffectFPN(CXmlNode* pXmlNode, INFO_DEFEFFECT* pstDefEffect)
{
	if (NULL == pXmlNode || NULL == pstDefEffect)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefEffect->m_bSupport, pTxt);

		if (pTxt) delete[] pTxt;
	}

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_UPLOAD);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefEffect->m_bSupportUpload, pTxt);

		if (pTxt) delete[] pTxt;
	}

	return TRUE;
}

BOOL CXml::LoadCameraEffectPRNU(CXmlNode* pXmlNode, INFO_DEFEFFECT* pstDefEffect)
{
	if (NULL == pXmlNode || NULL == pstDefEffect)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefEffect->m_bSupport, pTxt);

		if (pTxt) delete[] pTxt;
	}

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_UPLOAD);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefEffect->m_bSupportUpload, pTxt);

		if (pTxt) delete[] pTxt;
	}

	return TRUE;
}

BOOL CXml::LoadCameraEffectDPC(CXmlNode* pXmlNode, INFO_DEFEFFECT* pstDefEffect)
{
	if (NULL == pXmlNode || NULL == pstDefEffect)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefEffect->m_bSupport, pTxt);

		if (pTxt) delete[] pTxt;
	}

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_UPLOAD);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefEffect->m_bSupportUpload, pTxt);

		if (pTxt) delete[] pTxt;
	}

	return TRUE;
}

BOOL CXml::LoadCameraEffectSmoth(CXmlNode* pXmlNode, INFO_DEFEFFECT* pstDefEffect)
{
	if (NULL == pXmlNode || NULL == pstDefEffect)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefEffect->m_bSupport, pTxt);

		if (pTxt) delete[] pTxt;
	}

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_UPLOAD);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefEffect->m_bSupportUpload, pTxt);

		if (pTxt) delete[] pTxt;
	}

	return TRUE;
}

BOOL CXml::LoadCameraEffectSharpen(CXmlNode* pXmlNode, INFO_DEFEFFECT* pstDefEffect)
{
	if (NULL == pXmlNode || NULL == pstDefEffect)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefEffect->m_bSupport, pTxt);

		if (pTxt) delete[] pTxt;
	}

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_UPLOAD);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefEffect->m_bSupportUpload, pTxt);

		if (pTxt) delete[] pTxt;
	}

	return TRUE;
}


BOOL CXml::LoadCameraUserset(CXmlNode* pXmlNode, INFO_DEFDEV* pstDefDev)
{
	if (NULL == pXmlNode || NULL == pstDefDev)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Node
	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_STARTUP))
		{
			LoadCameraUsersetStartup(pChildNode, &(pstDefDev->m_stDefUserset));
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CAM_RANGE))
		{
			LoadCameraRange(pChildNode, &(pstDefDev->m_stDefUserset.m_stRange));
		}
	}

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefDev->m_stDefUserset.m_bSupport, pTxt);

		if (pTxt) delete[] pTxt;
	}

	return TRUE;
}

BOOL CXml::LoadCameraUsersetStartup(CXmlNode* pXmlNode, INFO_DEFUSERSET* pstDefUserset)
{
	if (NULL == pXmlNode || NULL == pstDefUserset)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;

	// Attribute
	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(pstDefUserset->m_bSupportStartup, pTxt);

		if (pTxt) delete[] pTxt;
	}

	return TRUE;
}


BOOL CXml::LoadCameraImageTaps(CXmlNode* pXmlNode, INFO_DEFDEV_CL* pstDefDev)
{
	if (NULL == pXmlNode || NULL == pstDefDev)
		return FALSE;
	CXmlAttribute* pXmlAttr = NULL;

	// Node
	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CLCAM_TAP))
		{
			LoadCameraCLTap(pChildNode, pstDefDev);
		}
	}

	return TRUE;
}

BOOL CXml::LoadCameraCLTap(CXmlNode* pXmlNode, INFO_DEFDEV_CL* pstDefDev)
{
	if (NULL == pXmlNode || NULL == pstDefDev)
		return FALSE;
	CXmlAttribute* pXmlAttr = NULL;
	
	INFO_CLIMGTAP* pstImgTap = NULL;
	TYPE_CLIMGTAPS	eImageTap = TYPE_CLIMGTAPS_NONE;

	// Support
	{
		BOOL bSupport = FALSE;
		pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
		if (pXmlAttr)
		{
			const int nTxtLen = pXmlAttr->GetValue(0, NULL);
			TCHAR* pTxt = new TCHAR[nTxtLen + 1];
			pXmlAttr->GetValue(pTxt, nTxtLen + 1);

			GetBoolean(bSupport, pTxt);

			if (pTxt) delete[] pTxt;
		}

		if (FALSE == bSupport)
			return FALSE;
	}


	// Image Tap
	{
		DWORD tap = 0;
		pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_CLIMAGETAP);
		if (pXmlAttr)
			pXmlAttr->GetValue(&tap, sizeof(DWORD));

		if (10 == tap)			eImageTap = TYPE_CLIMGTAPS_10;
		else if (8 == tap)		eImageTap = TYPE_CLIMGTAPS_08;
		else if (4 == tap)		eImageTap = TYPE_CLIMGTAPS_04;
		else if (2 == tap)		eImageTap = TYPE_CLIMGTAPS_02;
		else
			return FALSE;
	}


	// Node
	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CLCAM_DATABITS))
		{
			pstImgTap = &(pstDefDev->m_pstImgTaps[eImageTap]);
			pstImgTap->m_eImgTap = eImageTap;

			LoadCameraDataBits(pChildNode, pstImgTap);
		}
	}

	return TRUE;
}

BOOL CXml::LoadCameraDataBits(CXmlNode* pXmlNode, INFO_CLIMGTAP* pstImgTap)
{
	if (NULL == pXmlNode || NULL == pstImgTap)
		return FALSE;
	CXmlAttribute* pXmlAttr = NULL;

	// Node
	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_CLCAM_BIT))
		{
			LoadCameraCLBit(pChildNode, pstImgTap);
		}
	}

	return TRUE;
}

BOOL CXml::LoadCameraCLBit(CXmlNode* pXmlNode, INFO_CLIMGTAP* pstImgTap)
{
	if (NULL == pXmlNode || NULL == pstImgTap)
		return FALSE;
	CXmlAttribute* pXmlAttr = NULL;

	TYPE_CLDATABIT eDataBit = TYPE_CLDATABIT_NONE;
	BOOL bSupport = FALSE;

	// Support
	{
		pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
		if (pXmlAttr)
		{
			const int nTxtLen = pXmlAttr->GetValue(0, NULL);
			TCHAR* pTxt = new TCHAR[nTxtLen + 1];
			pXmlAttr->GetValue(pTxt, nTxtLen + 1);

			GetBoolean(bSupport, pTxt);

			if (pTxt) delete[] pTxt;
		}

		pstImgTap->m_bSupport = bSupport;
		if (FALSE == bSupport)
			return FALSE;

	}

	// Data Bit
	{
		int databit = 0;
		pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_CLDATABIT);
		if (pXmlAttr)
			pXmlAttr->GetValue(&databit, sizeof(int));
		if (10 == databit)
			eDataBit = TYPE_CLDATABIT_10;
		else if (8 == databit)
			eDataBit = TYPE_CLDATABIT_08;
		else
			return FALSE;
	}

	pstImgTap->m_pDataBitList[eDataBit] = TRUE;

	return TRUE;
}

BOOL CXml::LoadCameraRange(CXmlNode* pXmlNode, INFO_DEFRANGE* pstRange)
{
	if (NULL == pXmlNode || NULL == pstRange)
		return FALSE;
	CXmlAttribute* pXmlAttr = NULL;

	double fFrom = 0.0f;
	double fTo = 0.0f;

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_FROM);
	if (pXmlAttr)
		pXmlAttr->GetValue(&fFrom, sizeof(double));

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_TO);
	if (pXmlAttr)
		pXmlAttr->GetValue(&fTo, sizeof(double));

	pstRange->m_nFrom = (int)fFrom;
	pstRange->m_nTo = (int)fTo;

	return TRUE;
}



//
CXmlNode* CXml::CreateNode(CXmlNode* pParentNode, TCHAR* pTitle, TYPE_XML_VALUE eType, void* pData, int nDataLen)
{
	CXmlNode* pNode = NULL;

	if (TYPE_XML_VALUE_NONE == eType)
	{
		pNode = new CXmlNode(pTitle, pParentNode);
	}
	else if (TYPE_XML_VALUE_STRING == eType)
	{
		pNode = new CXmlNode(pTitle, eType, pData, nDataLen, pParentNode);
	}
	else if (TYPE_XML_VALUE_SIGNED == eType)
	{
		pNode = new CXmlNode(pTitle, eType, pData, nDataLen, pParentNode);
	}
	else if (TYPE_XML_VALUE_UNSIGNED == eType)
	{
		pNode = new CXmlNode(pTitle, eType, pData, nDataLen, pParentNode);
	}
	else if (TYPE_XML_VALUE_DOUBLE == eType)
	{
		pNode = new CXmlNode(pTitle, eType, pData, nDataLen, pParentNode);
	}
	else if (TYPE_XML_VALUE_HEX == eType)
	{
	}
	else if (TYPE_XML_VALUE_BINARY == eType)
	{
		DWORD dwBase64 = nDataLen * 2;
		BYTE* pBase64 = new BYTE[dwBase64];
		memset(pBase64, 0x00, sizeof(BYTE) * dwBase64);

		CUtil::EncodeBase64((BYTE*)pData, nDataLen, pBase64, dwBase64);

		/*//
		{
			CUtil::DumpFile(_T("E:/Work/dump"), (BYTE*)pData, nDataLen);
			CUtil::DumpFile(_T("E:/Work/dump_base64"), pBase64, dwBase64);

			DWORD dwDecodeBase64 = nDataLen * 2;
			BYTE* pDecodeBase64 = new BYTE[dwDecodeBase64];

			CUtil::DecodeBase64(pBase64, dwBase64, pDecodeBase64, dwDecodeBase64);
			CUtil::DumpFile(_T("E:/Work/dump_decode_base64"), pDecodeBase64, dwDecodeBase64);
		}
		//*/

		pNode = new CXmlNode(pTitle, eType, pBase64, dwBase64, pParentNode);

		delete[] pBase64;
	}

	return pNode;
}

CXmlNode* CXml::CreateNodeString(CXmlNode* pParentNode, TCHAR* pTitle, CString szValue)
{
	const int nLen = szValue.GetLength() + 1;
	TCHAR* pTxt = new TCHAR[nLen];
	CUtil::StringCopy(pTxt, (LPCTSTR)szValue);

	CXmlNode* pNode = new CXmlNode(pTitle, TYPE_XML_VALUE_STRING, pTxt, nLen, pParentNode);
	delete[] pTxt;

	return pNode;
}

CXmlNode* CXml::CreateNodeInt(CXmlNode* pParentNode, TCHAR* pTitle, int nValue)
{
	const int nLen = sizeof(int);
	CXmlNode* pNode = new CXmlNode(pTitle, TYPE_XML_VALUE_SIGNED, &nValue, nLen, pParentNode);
	return pNode;
}

CXmlNode* CXml::CreateNodeUnsignedInt(CXmlNode* pParentNode, TCHAR* pTitle, DWORD dwValue)
{
	const int nLen = sizeof(DWORD);
	CXmlNode* pNode = new CXmlNode(pTitle, TYPE_XML_VALUE_UNSIGNED, &dwValue, nLen, pParentNode);
	return pNode;
}

CXmlNode* CXml::CreateNodeDouble(CXmlNode* pParentNode, TCHAR* pTitle, double fValue)
{
	const int nLen = sizeof(double);
	CXmlNode* pNode = new CXmlNode(pTitle, TYPE_XML_VALUE_DOUBLE, &fValue, nLen, pParentNode);
	return pNode;
}


BOOL CXml::AddAttributeString(CXmlNode* pNode, TCHAR* pTitle, CString szValue)
{
	if (NULL == pNode || NULL == pTitle)
		return FALSE;

	const int nLen = szValue.GetLength() + 1;
	TCHAR* pTxt = new TCHAR[nLen];
	CUtil::StringCopy(pTxt, (LPCTSTR)szValue);

	pNode->AddAttribute(pTitle, TYPE_XML_VALUE_STRING, pTxt, nLen);
	delete[] pTxt;

	return TRUE;
}

BOOL CXml::AddAttributeInt(CXmlNode* pNode, TCHAR* pTitle, int nValue)
{
	if (NULL == pNode || NULL == pTitle)
		return FALSE;

	const int nLen = sizeof(int);
	pNode->AddAttribute(pTitle, TYPE_XML_VALUE_SIGNED, &nValue, nLen);

	return TRUE;
}

BOOL CXml::AddAttributeUnsignedInt(CXmlNode* pNode, TCHAR* pTitle, DWORD dwValue)
{
	if (NULL == pNode || NULL == pTitle)
		return FALSE;

	const int nLen = sizeof(DWORD);
	pNode->AddAttribute(pTitle, TYPE_XML_VALUE_UNSIGNED, &dwValue, nLen);

	return TRUE;
}

BOOL CXml::AddAttributeDouble(CXmlNode* pNode, TCHAR* pTitle, double fValue)
{
	if (NULL == pNode || NULL == pTitle)
		return FALSE;

	const int nLen = sizeof(double);
	pNode->AddAttribute(pTitle, TYPE_XML_VALUE_DOUBLE, &fValue, nLen);

	return TRUE;
}


#ifdef DEF_LPAPP
//
BOOL CXml::GetApplicationType(eAPPLICATION_TYPE& eType, const TCHAR* pTxt)
{
	if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_NONE))		eType = eAppType_None;

	//Enhance
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_ENHANCE_FILTER))		eType = eAppType_Filter;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_ENHANCE_THRESHOLD))	eType = eAppType_Threshold;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_ENHANCE_SEGMENTCOLOR))	eType = eAppType_SegmentColor;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_ENHANCE_CALIBRATE))	eType = eAppType_Calibrate;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_ENHANCE_BRIGHTNESS))	eType = eAppType_Brightness;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_ENHANCE_MTIG))			eType = eAppType_MTiG;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_ENHANCE_SPLITPLANE))	eType = eAppType_SplitPlane;

	//Measure
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_MEASURE_INTENSITY))	eType = eAppType_Intensity;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_MEASURE_COUNTPIXELS))	eType = eAppType_CountPixels;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_MEASURE_MEASURECOLOR))	eType = eAppType_MeasureColor;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_MEASURE_MATCHCOLOR))	eType = eAppType_MatchColor;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_MEASURE_CALIPER))		eType = eAppType_Caliper;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_MEASURE_GEOMETRY))		eType = eAppType_Geometry;

	//Locate
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_LOCATE_FINDEDGE))		eType = eAppType_FindEdge;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_LOCATE_LINEFITTING))	eType = eAppType_LineFitting;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_LOCATE_CIRCLEFITTING))	eType = eAppType_CircleFitting;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_LOCATE_PATTERNMATCH))	eType = eAppType_PatternMatch;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_LOCATE_SETCOORDINATE))	eType = eAppType_SetCoordinate;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_LOCATE_DETECTOBJECT))	eType = eAppType_DetectObject;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_LOCATE_MATCHEDGE))	    eType = eAppType_MatchEdge;

	//Identify
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_IDENTIFY_BARCODE))		eType = eAppType_Barcode;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_IDENTIFY_BARCODEVER))	eType = eAppType_BarcodeVerification;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_IDENTIFY_OCR))			eType = eAppType_OCR;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_IDENTIFY_OCV))			eType = eAppType_OCV;

	//test
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_TEST))					eType = eAppType_test;

	//camera
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_CAMERA_LOCALFILE))		eType = eAppType_Local_File;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_CAMERA_GIGE))			eType = eAppType_GigE_Camera;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_CAMERA_CAMERALINK))	eType = eAppType_CameraLink_Camera;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_CAMERA_USB))			eType = eAppType_USB_Camera;


	//output
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_IO_SERIAL))			eType = eAppType_Serial_IO;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_IO_TCPIP))				eType = eAppType_TCPIP_IO;

	//assistant
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_ASSISTANT_HISTOGRAM))		eType = eAppType_Histogram;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_ASSISTANT_LINEPROFILE))	eType = eAppType_LineProfile;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_ASSISTANT_MEASURE))		eType = eAppType_Measure;

	//Result Logic
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_LOGIC_RESULTLOGIC))		eType = eAppType_ResultLogic;

	//IO
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_DIO_DEVICE))			eType = eAppType_Device_DIO;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_APPTYPE_DIO_RESULT))			eType = eAppType_Result_DIO;

	else return FALSE;

	return TRUE;
}

BOOL CXml::SetApplicationType(eAPPLICATION_TYPE eType, TCHAR* pTxt, int nLen)
{
	if (eAppType_None == eType)					CUtil::StringCopy(pTxt, XML_APPTYPE_NONE);

	//Enhance
	else if (eAppType_Filter == eType)			CUtil::StringCopy(pTxt, XML_APPTYPE_ENHANCE_FILTER);
	else if (eAppType_Threshold == eType)		CUtil::StringCopy(pTxt, XML_APPTYPE_ENHANCE_THRESHOLD);
	else if (eAppType_SegmentColor == eType)	CUtil::StringCopy(pTxt, XML_APPTYPE_ENHANCE_SEGMENTCOLOR);
	else if (eAppType_Calibrate == eType)		CUtil::StringCopy(pTxt, XML_APPTYPE_ENHANCE_CALIBRATE);
	else if (eAppType_Brightness == eType)		CUtil::StringCopy(pTxt, XML_APPTYPE_ENHANCE_BRIGHTNESS);
	else if (eAppType_MTiG == eType)			CUtil::StringCopy(pTxt, XML_APPTYPE_ENHANCE_MTIG);
	else if (eAppType_SplitPlane == eType)		CUtil::StringCopy(pTxt, XML_APPTYPE_ENHANCE_SPLITPLANE);

	//Measure
	else if (eAppType_Intensity == eType)		CUtil::StringCopy(pTxt, XML_APPTYPE_MEASURE_INTENSITY);
	else if (eAppType_CountPixels == eType)		CUtil::StringCopy(pTxt, XML_APPTYPE_MEASURE_COUNTPIXELS);
	else if (eAppType_MeasureColor == eType)	CUtil::StringCopy(pTxt, XML_APPTYPE_MEASURE_MEASURECOLOR);
	else if (eAppType_MatchColor == eType)		CUtil::StringCopy(pTxt, XML_APPTYPE_MEASURE_MATCHCOLOR);
	else if (eAppType_Caliper == eType)			CUtil::StringCopy(pTxt, XML_APPTYPE_MEASURE_CALIPER);
	else if (eAppType_Geometry == eType)		CUtil::StringCopy(pTxt, XML_APPTYPE_MEASURE_GEOMETRY);

	//Locate
	else if (eAppType_FindEdge == eType)		CUtil::StringCopy(pTxt, XML_APPTYPE_LOCATE_FINDEDGE);
	else if (eAppType_LineFitting == eType)		CUtil::StringCopy(pTxt, XML_APPTYPE_LOCATE_LINEFITTING);
	else if (eAppType_CircleFitting == eType)	CUtil::StringCopy(pTxt, XML_APPTYPE_LOCATE_CIRCLEFITTING);
	else if (eAppType_PatternMatch == eType)	CUtil::StringCopy(pTxt, XML_APPTYPE_LOCATE_PATTERNMATCH);
	else if (eAppType_SetCoordinate == eType)	CUtil::StringCopy(pTxt, XML_APPTYPE_LOCATE_SETCOORDINATE);
	else if (eAppType_DetectObject == eType)	CUtil::StringCopy(pTxt, XML_APPTYPE_LOCATE_DETECTOBJECT);
	else if (eAppType_MatchEdge == eType)		CUtil::StringCopy(pTxt, XML_APPTYPE_LOCATE_MATCHEDGE);

	//Identify
	else if (eAppType_Barcode == eType)					CUtil::StringCopy(pTxt, XML_APPTYPE_IDENTIFY_BARCODE);
	else if (eAppType_BarcodeVerification == eType)		CUtil::StringCopy(pTxt, XML_APPTYPE_IDENTIFY_BARCODEVER);
	else if (eAppType_OCR == eType)						CUtil::StringCopy(pTxt, XML_APPTYPE_IDENTIFY_OCR);
	else if (eAppType_OCV == eType)						CUtil::StringCopy(pTxt, XML_APPTYPE_IDENTIFY_OCV);

	//test
	else if (eAppType_test == eType)					CUtil::StringCopy(pTxt, XML_APPTYPE_TEST);

	//camera
	else if (eAppType_Local_File == eType)				CUtil::StringCopy(pTxt, XML_APPTYPE_CAMERA_LOCALFILE);
	else if (eAppType_GigE_Camera == eType)				CUtil::StringCopy(pTxt, XML_APPTYPE_CAMERA_GIGE);
	else if (eAppType_CameraLink_Camera == eType)		CUtil::StringCopy(pTxt, XML_APPTYPE_CAMERA_CAMERALINK);
	else if (eAppType_USB_Camera == eType)				CUtil::StringCopy(pTxt, XML_APPTYPE_CAMERA_USB);

	//output
	else if (eAppType_Serial_IO == eType)				CUtil::StringCopy(pTxt, XML_APPTYPE_IO_SERIAL);
	else if (eAppType_TCPIP_IO == eType)				CUtil::StringCopy(pTxt, XML_APPTYPE_IO_TCPIP);

	//output
	else if (eAppType_Histogram == eType)				CUtil::StringCopy(pTxt, XML_APPTYPE_ASSISTANT_HISTOGRAM);
	else if (eAppType_LineProfile == eType)				CUtil::StringCopy(pTxt, XML_APPTYPE_ASSISTANT_LINEPROFILE);
	else if (eAppType_Measure == eType)					CUtil::StringCopy(pTxt, XML_APPTYPE_ASSISTANT_MEASURE);

	//result logic
	else if (eAppType_ResultLogic == eType)				CUtil::StringCopy(pTxt, XML_APPTYPE_LOGIC_RESULTLOGIC);

	//IO
	else if (eAppType_Device_DIO == eType)				CUtil::StringCopy(pTxt, XML_APPTYPE_DIO_DEVICE);
	else if (eAppType_Result_DIO == eType)				CUtil::StringCopy(pTxt, XML_APPTYPE_DIO_RESULT);

	else return FALSE;

	return TRUE;

}


BOOL CXml::GetRoiType(eROITYPE& eType, const TCHAR* pTxt)
{
	if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_ROITYPE_NONE))						eType = eROIType_None;

	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_ROITYPE_RECTANGULAR))			eType = eROIType_Rectangular;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_ROITYPE_RECTANGULARROTATE))	eType = eROIType_RectangularRotate;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_ROITYPE_POLYGON))				eType = eROIType_Polygon;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_ROITYPE_CIRCLE))				eType = eROIType_Circle;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_ROITYPE_RING))					eType = eROIType_Ring;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_ROITYPE_LINE))					eType = eROIType_Line;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_ROITYPE_POINT))				eType = eROIType_Point;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_ROITYPE_CURVE))				eType = eROIType_Curve;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_ROITYPE_SUFFACE))				eType = eROIType_Sufface;
	else return FALSE;

	return TRUE;
}

BOOL CXml::SetRoiType(eROITYPE eType, TCHAR* pTxt, int nLen)
{
	if (eROIType_None == eType)				CUtil::StringCopy(pTxt, XML_ROITYPE_NONE);

	else if (eROIType_Rectangular == eType)			CUtil::StringCopy(pTxt, XML_ROITYPE_RECTANGULAR);
	else if (eROIType_RectangularRotate == eType)	CUtil::StringCopy(pTxt, XML_ROITYPE_RECTANGULARROTATE);
	else if (eROIType_Polygon == eType)		CUtil::StringCopy(pTxt, XML_ROITYPE_POLYGON);
	else if (eROIType_Circle == eType)		CUtil::StringCopy(pTxt, XML_ROITYPE_CIRCLE);
	else if (eROIType_Ring == eType)		CUtil::StringCopy(pTxt, XML_ROITYPE_RING);
	else if (eROIType_Line == eType)		CUtil::StringCopy(pTxt, XML_ROITYPE_LINE);
	else if (eROIType_Point == eType)		CUtil::StringCopy(pTxt, XML_ROITYPE_POINT);
	else if (eROIType_Curve == eType)		CUtil::StringCopy(pTxt, XML_ROITYPE_CURVE);
	else if (eROIType_Sufface == eType)		CUtil::StringCopy(pTxt, XML_ROITYPE_SUFFACE);
	else return FALSE;

	return TRUE;
}


BOOL CXml::GetRoiFaceType(eROIFACE& eType, const TCHAR* pTxt)
{
	if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_ROIFACETYPE_NORMAL))		eType = eROIFace_Normal;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_ROIFACETYPE_EDGE))		eType = eROIFace_Edge;
	else return FALSE;

	return TRUE;
}

BOOL CXml::SetRoiFaceType(eROIFACE eType, TCHAR* pTxt, int nLen)
{
	if (eROIFace_Normal == eType)		CUtil::StringCopy(pTxt, XML_ROIFACETYPE_NORMAL);
	else if (eROIFace_Edge == eType)	CUtil::StringCopy(pTxt, XML_ROIFACETYPE_EDGE);
	else return FALSE;

	return TRUE;
}


BOOL CXml::GetRoi4DirType(eROI4DIR& eType, const TCHAR* pTxt)
{
	if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_ROI4DIR_LEFT2RIGHT))		eType = eRoi4Dir_Left2Right;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_ROI4DIR_RIGHT2LEFT))	eType = eRoi4Dir_Right2Left;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_ROI4DIR_TOP2BOTTOM))	eType = eRoi4Dir_Top2Bottom;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_ROI4DIR_BOTTOM2TOP))	eType = eRoi4Dir_Bottom2Top;
	else return FALSE;

	return TRUE;
}

BOOL CXml::SetRoi4DirType(eROI4DIR eType, TCHAR* pTxt, int nLen)
{
	if (eRoi4Dir_Left2Right == eType)		CUtil::StringCopy(pTxt, XML_ROI4DIR_LEFT2RIGHT);
	else if (eRoi4Dir_Right2Left == eType)	CUtil::StringCopy(pTxt, XML_ROI4DIR_RIGHT2LEFT);
	else if (eRoi4Dir_Top2Bottom == eType)	CUtil::StringCopy(pTxt, XML_ROI4DIR_TOP2BOTTOM);
	else if (eRoi4Dir_Bottom2Top == eType)	CUtil::StringCopy(pTxt, XML_ROI4DIR_BOTTOM2TOP);
	else return FALSE;

	return TRUE;
}


BOOL CXml::GetRoi2DirType(eROI2DIR& eType, const TCHAR* pTxt)
{
	if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_ROI2DIR_IN2OUT))		eType = eRoi2Dir_In2Out;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_ROI2DIR_OUT2IN))	eType = eRoi2Dir_Out2In;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_ROI2DIR_CCW))		eType = eRoi2Dir_CounterClockWise;
	else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTxt, XML_ROI2DIR_CW))		eType = eRoi2Dir_ClockWise;
	else return FALSE;

	return TRUE;
}

BOOL CXml::SetRoi2DirType(eROI2DIR eType, TCHAR* pTxt, int nLen)
{
	if (eRoi2Dir_In2Out == eType)					CUtil::StringCopy(pTxt, XML_ROI2DIR_IN2OUT);
	else if (eRoi2Dir_Out2In == eType)				CUtil::StringCopy(pTxt, XML_ROI2DIR_OUT2IN);
	else if (eRoi2Dir_CounterClockWise == eType)	CUtil::StringCopy(pTxt, XML_ROI2DIR_CCW);
	else if (eRoi2Dir_ClockWise == eType)			CUtil::StringCopy(pTxt, XML_ROI2DIR_CW);
	else return FALSE;

	return TRUE;
}
#endif

BOOL CXml::GetBoolean(BOOL& bBool, const TCHAR* pTxt)
{
	if (CUtil::StringICompare((TCHAR*)pTxt, _T("true")))
		bBool = TRUE;
	else
		bBool = FALSE;

	return TRUE;
}

BOOL CXml::SetBoolean(BOOL bBool, TCHAR* pTxt, int nLen)
{
	if (bBool)	CUtil::StringCopy(pTxt, _T("true"));
	else		CUtil::StringCopy(pTxt, _T("false"));

	return TRUE;
}

BOOL CXml::GetDataBit(TYPE_DATABIT& eDataBit, int nBit)
{
	if (8 == nBit)
		eDataBit = TYPE_DATABIT_08;
	else if (10 == nBit)
		eDataBit = TYPE_DATABIT_10;
	else if (12 == nBit)
		eDataBit = TYPE_DATABIT_12;
	else if (16 == nBit)
		eDataBit = TYPE_DATABIT_16;
	else if (24 == nBit)
		eDataBit = TYPE_DATABIT_24;
	else if (32 == nBit)
		eDataBit = TYPE_DATABIT_32;
	else if (36 == nBit)
		eDataBit = TYPE_DATABIT_36;
	else if (48 == nBit)
		eDataBit = TYPE_DATABIT_48;
	else
		return FALSE;

	return TRUE;	
}



// 
BOOL CXml::LoadCameraUserConfig(TCHAR* pszPath, CCameraDevice& DefDevice)
{
	if (NULL == pszPath)
		return FALSE;

	BOOL bResult = FALSE;

	CXmlFile xmlFile;
	CXmlNode* pXmlNode = xmlFile.Load(pszPath, XML_CAMERAUSER_NODE_ROOT);
	if (pXmlNode)
	{
		INFO_DEFDEV_USERCONFIG stUserConfig;
		memset(&stUserConfig, 0x00, sizeof(INFO_DEFDEV_USERCONFIG));

		bResult = LoadXml(stUserConfig, pXmlNode);
		delete pXmlNode;

		if (bResult)
			DefDevice.UpdateUserConfig(&stUserConfig);
	}
	return bResult;
}

BOOL CXml::SaveCameraUserConfig(TCHAR* pszPath, CCameraDevice& DefDevice)
{
	if (NULL == pszPath)
		return FALSE;

	const INFO_DEFDEV_USERCONFIG* pstUserConfig = DefDevice.GetUserConfig();

	BOOL bResult = FALSE;
	CXmlNode* pXmlNode = SaveXml(*pstUserConfig);
	if (pXmlNode)
	{
		CXmlFile xmlFile;
		bResult = xmlFile.Save(pszPath, XML_CAMERAUSER_NODE_ROOT, pXmlNode);

		if (pXmlNode)
			delete pXmlNode;
	}
	else
	{
		return FALSE;
	}
	return bResult;
}


BOOL CXml::LoadXml(INFO_DEFDEV_USERCONFIG& stUserConfig, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		const int nValueLen = pChildNode->GetValue(0, NULL);

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERAUSER_NODE_COMMON))
		{
			LoadCameraUserCommon(pChildNode, stUserConfig);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERANODE_GIGE))
		{
			LoadCameraUserGigE(pChildNode, stUserConfig.m_stUserGigE);
		}
	}

	return TRUE;
}

BOOL CXml::LoadCameraUserCommon(CXmlNode* pXmlNode, INFO_DEFDEV_USERCONFIG& stUserConfig)
{
	if (NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		const int nValueLen = pChildNode->GetValue(0, NULL);

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERAUSER_NODE_TIMEOUT))
		{
			LoadCameraUserCommonTimeOut(pChildNode, stUserConfig.m_stTimeOut);
		}
	}

	return TRUE;
}

BOOL CXml::LoadCameraUserCommonTimeOut(CXmlNode* pXmlNode, INFO_TIMEOUT& stTimeOut)
{
	if (NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		const int nValueLen = pChildNode->GetValue(0, NULL);

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERAUSER_NODE_RANGE))
		{
			LoadCameraUserCommonTimeOutRange(pChildNode, stTimeOut);
			{
				BOOL bBool = FALSE;

				CXmlAttribute* pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
				if (pXmlAttr)
				{
					const int nTxtLen = pXmlAttr->GetValue(0, NULL);
					TCHAR* pTxt = new TCHAR[nTxtLen + 1];
					pXmlAttr->GetValue(pTxt, nTxtLen + 1);

					GetBoolean(bBool, pTxt);

					if (pTxt) delete[] pTxt;
				}
				stTimeOut.m_bSupport = bBool;

				pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_ENABLE);
				if (pXmlAttr)
				{
					const int nTxtLen = pXmlAttr->GetValue(0, NULL);
					TCHAR* pTxt = new TCHAR[nTxtLen + 1];
					pXmlAttr->GetValue(pTxt, nTxtLen + 1);

					GetBoolean(bBool, pTxt);

					if (pTxt) delete[] pTxt;
				}
				stTimeOut.m_bEnable = bBool;				

			}
		}
	}

	return TRUE;
}

BOOL CXml::LoadCameraUserCommonTimeOutRange(CXmlNode* pXmlNode, INFO_TIMEOUT& stTimeOut)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;
	
	double fFrom = 0.0f;
	double fTo = 0.0f;

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_FROM);
	if (pXmlAttr)
		pXmlAttr->GetValue(&fFrom, sizeof(double));

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_TO);
	if (pXmlAttr)
		pXmlAttr->GetValue(&fTo, sizeof(double));

	stTimeOut.m_stTimeOutRange.m_nFrom = (int)fFrom;
	stTimeOut.m_stTimeOutRange.m_nTo = (int)fTo;

	{
		DWORD dwValue = 0;
		pXmlNode->GetValue(&dwValue, sizeof(DWORD));
		stTimeOut.m_nCurTimeOut = dwValue;
	}

	return TRUE;
}

BOOL CXml::LoadCameraUserGigE(CXmlNode* pXmlNode, INFO_USERGIGE& stUserGigE)
{
	if (NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();

	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		const int nValueLen = pChildNode->GetValue(0, NULL);

		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_CAMERAUSER_NODE_MTU))
		{
			LoadCameraUserGigEMtu(pChildNode, stUserGigE.m_stMtu);
		}
	}

	return TRUE;
}

BOOL CXml::LoadCameraUserGigEMtu(CXmlNode* pXmlNode, INFO_MTU& stMtu)
{
	if (NULL == pXmlNode)
		return FALSE;

	BOOL bBool = FALSE;

	CXmlAttribute* pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_SUPPORT);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(bBool, pTxt);

		if (pTxt) delete[] pTxt;
	}
	stMtu.m_bSupport = bBool;

	pXmlAttr = pXmlNode->GetAttribute(XML_NAVI_ATTR_ENABLE);
	if (pXmlAttr)
	{
		const int nTxtLen = pXmlAttr->GetValue(0, NULL);
		TCHAR* pTxt = new TCHAR[nTxtLen + 1];
		pXmlAttr->GetValue(pTxt, nTxtLen + 1);

		GetBoolean(bBool, pTxt);

		if (pTxt) delete[] pTxt;
	}
	stMtu.m_bEnable = bBool;

	//
	{
		DWORD dwValue = 0;
		pXmlNode->GetValue(&dwValue, sizeof(DWORD));
		stMtu.m_dwMtu = dwValue;
	}

	return TRUE;
}



CXmlNode* CXml::SaveXml(const INFO_DEFDEV_USERCONFIG& stUserConfig)
{
	CXmlNode* pXmlNode = new CXmlNode(XML_CAMERAUSER_NODE_ROOT, NULL);

	CXmlNode* pNode = SaveCameraUserCommon(pXmlNode, stUserConfig);
	pXmlNode->AddNode(pNode);	delete pNode;

	pNode = SaveCameraUserGigE(pXmlNode, stUserConfig.m_stUserGigE);
	pXmlNode->AddNode(pNode);	delete pNode;

	return pXmlNode;
}

CXmlNode* CXml::SaveCameraUserCommon(CXmlNode* pParentNode, const INFO_DEFDEV_USERCONFIG& stUserConfig)
{
	if (NULL == pParentNode)
		return NULL;

	CXmlNode* pCommonNode = CreateNode(pParentNode, XML_CAMERAUSER_NODE_COMMON, TYPE_XML_VALUE_NONE, NULL, 0);
	if (pCommonNode)
	{
		CXmlNode* pNode = SaveCameraUserCommonTimeOut(pCommonNode, stUserConfig.m_stTimeOut);
		pCommonNode->AddNode(pNode);	delete pNode;
	}

	return pCommonNode;

}

CXmlNode* CXml::SaveCameraUserCommonTimeOut(CXmlNode* pParentNode, const INFO_TIMEOUT& stTimeOut)
{
	if (NULL == pParentNode)
		return NULL;

	CXmlNode* pTimeOutNode = CreateNode(pParentNode, XML_CAMERAUSER_NODE_TIMEOUT, TYPE_XML_VALUE_NONE, NULL, 0);
	if (pTimeOutNode)
	{
		if (stTimeOut.m_bSupport)
			pTimeOutNode->AddAttribute(XML_NAVI_ATTR_SUPPORT, TYPE_XML_VALUE_STRING, _T("true"), CUtil::StringLength(_T("true"))+1 );
		else
			pTimeOutNode->AddAttribute(XML_NAVI_ATTR_SUPPORT, TYPE_XML_VALUE_STRING, _T("false"), CUtil::StringLength(_T("false"))+1 );

		if (stTimeOut.m_bEnable)
			pTimeOutNode->AddAttribute(XML_NAVI_ATTR_ENABLE, TYPE_XML_VALUE_STRING, _T("true"), CUtil::StringLength(_T("true")) + 1);
		else
			pTimeOutNode->AddAttribute(XML_NAVI_ATTR_ENABLE, TYPE_XML_VALUE_STRING, _T("false"), CUtil::StringLength(_T("false")) + 1);

		CXmlNode* pNode = SaveCameraUserCommonTimeOutRange(pTimeOutNode, stTimeOut);
		pTimeOutNode->AddNode(pNode);	delete pNode;
	}

	return pTimeOutNode;
}

CXmlNode* CXml::SaveCameraUserCommonTimeOutRange(CXmlNode* pParentNode, const INFO_TIMEOUT& stTimeOut)
{
	if (NULL == pParentNode)
		return NULL;

	CXmlNode* pTimeOutRangeNode = CreateNodeUnsignedInt(pParentNode, XML_CAMERAUSER_NODE_RANGE, stTimeOut.m_nCurTimeOut);
	if (pTimeOutRangeNode)
	{
		AddAttributeDouble(pTimeOutRangeNode, XML_NAVI_ATTR_FROM, stTimeOut.m_stTimeOutRange.m_nFrom);
		AddAttributeDouble(pTimeOutRangeNode, XML_NAVI_ATTR_TO, stTimeOut.m_stTimeOutRange.m_nTo);
	}

	return pTimeOutRangeNode;
}

CXmlNode* CXml::SaveCameraUserGigE(CXmlNode* pParentNode, const INFO_USERGIGE& stUserGigE)
{
	if (NULL == pParentNode)
		return NULL;

	CXmlNode* pGigENode = CreateNode(pParentNode, XML_CAMERANODE_GIGE, TYPE_XML_VALUE_NONE, NULL, 0);

	CXmlNode* pNode = SaveCameraUserGigEMtu(pGigENode, stUserGigE.m_stMtu);
	pGigENode->AddNode(pNode);	delete pNode;

	return pGigENode;
}

CXmlNode* CXml::SaveCameraUserGigEMtu(CXmlNode* pParentNode, const INFO_MTU& stMtu)
{
	if (NULL == pParentNode)
		return NULL;

	CXmlNode* pMtuNode = CreateNodeUnsignedInt(pParentNode, XML_CAMERAUSER_NODE_MTU, stMtu.m_dwMtu);
	if (pMtuNode)
	{
		if (stMtu.m_bSupport)
			pMtuNode->AddAttribute(XML_NAVI_ATTR_SUPPORT, TYPE_XML_VALUE_STRING, _T("true"), CUtil::StringLength(_T("true")) + 1);
		else
			pMtuNode->AddAttribute(XML_NAVI_ATTR_SUPPORT, TYPE_XML_VALUE_STRING, _T("false"), CUtil::StringLength(_T("false")) + 1);

		if (stMtu.m_bEnable)
			pMtuNode->AddAttribute(XML_NAVI_ATTR_ENABLE, TYPE_XML_VALUE_STRING, _T("true"), CUtil::StringLength(_T("true")) + 1);
		else
			pMtuNode->AddAttribute(XML_NAVI_ATTR_ENABLE, TYPE_XML_VALUE_STRING, _T("false"), CUtil::StringLength(_T("false")) + 1);
	}

	return pMtuNode;
}





BOOL CXml::LoadOption(TCHAR* pszPath, INFO_OPTION& stOpt)
{
	if (NULL == pszPath)
		return FALSE;

	BOOL bResult = FALSE;

	CXmlFile xmlFile;
	CXmlNode* pXmlNode = xmlFile.Load(pszPath, XML_OPTION_ROOT);
	if (pXmlNode)
	{
		INFO_OPTION stUseopt;
		memset(&stUseopt, 0x00, sizeof(INFO_OPTION));

		bResult = LoadOption(stUseopt, pXmlNode);
		delete pXmlNode;

		if (bResult)
		{
			stOpt = stUseopt;
		}
	}
	return bResult;
}

BOOL CXml::SaveOption(TCHAR* pszPath, INFO_OPTION& stOpt)
{
	if (NULL == pszPath)
		return FALSE;

	CXmlNode* pXmlNode = SaveOption(stOpt);
	BOOL bResult = FALSE;
	if (pXmlNode)
	{
		CXmlFile xmlFile;
		bResult = xmlFile.Save(pszPath, XML_OPTION_ROOT, pXmlNode);

		if (pXmlNode)
			delete pXmlNode;
	}
	else
	{
		return FALSE;
	}
	return bResult;
}



//
BOOL CXml::LoadOption(INFO_OPTION& stOpt, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();

		/*if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_ALARAM))
		{
			const int nCount = pChildNode->GetNodeCount();
			for (int i = 0; i < nCount; i++)
			{
				CXmlNode* pTempNode = pChildNode->GetNode(i);
				if (NULL == pTempNode)
					continue;

				const TCHAR* pTitle = pTempNode->GetTitle();

				if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_ASAMPLE))
				{
					CXmlAttribute* pXmlAttr = NULL;

					// Attribute
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_COUNT);
					if (pXmlAttr)
					{
						DWORD dwValue = 0;
						pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
						stOpt.m_stSampleA.m_nMinCount = dwValue;
					}

					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_ERATIO);
					if (pXmlAttr)
					{
						double fValue = 0;
						pXmlAttr->GetValue(&fValue, sizeof(double));
						stOpt.m_stSampleA.m_fAlarmRatio = fValue;
					}

				}
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_BSAMPLE))
				{
					CXmlAttribute* pXmlAttr = NULL;

					// Attribute
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_COUNT);
					if (pXmlAttr)
					{
						DWORD dwValue = 0;
						pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
						stOpt.m_stSampleB.m_nMinCount = dwValue;
					}

					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_ERATIO);
					if (pXmlAttr)
					{
						double fValue = 0;
						pXmlAttr->GetValue(&fValue, sizeof(double));
						stOpt.m_stSampleB.m_fAlarmRatio = fValue;
					}
				}
			}

		}
		else */
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_SIZERANGE))
		{
			int cameraIdx = -1;

			{
				CXmlAttribute* pXmlAttr = NULL;
				pXmlAttr = pChildNode->GetAttribute(XML_OPTIONATTR_CAMERA);
				if (pXmlAttr)
				{
					DWORD dwValue = -1;
					pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
					cameraIdx = dwValue;
				}
				else
				{
					cameraIdx = 0;
				}
			}

			if (cameraIdx >= 0 && cameraIdx < MAX_CAMERA_INTERFACE)
			{
				const int nCount = pChildNode->GetNodeCount();
				for (int i = 0; i < nCount; i++)
				{
					CXmlNode* pTempNode = pChildNode->GetNode(i);
					if (NULL == pTempNode)
						continue;

					const TCHAR* pTitle = pTempNode->GetTitle();

					int idx = -1;

					if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle,	   XML_OPTION_MEASURE01))	idx = 0;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE02))	idx = 1;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE03))	idx = 2;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE04))	idx = 3;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE05))	idx = 4;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE06))	idx = 5;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE07))	idx = 6;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE08))	idx = 7;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE09))	idx = 8;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE10))	idx = 9;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE11))	idx = 10;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE12))	idx = 11;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE13))	idx = 12;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE14))	idx = 13;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE15))	idx = 14;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE16))	idx = 15;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE17))	idx = 16;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE18))	idx = 17;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE19))	idx = 18;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE20))	idx = 19;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE21))	idx = 20;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE22))	idx = 21;

					// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE23))	idx = 22;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE24))	idx = 23;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE25))	idx = 24;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE26))	idx = 25;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE27))	idx = 26;
					else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE28))	idx = 27;


					if (0 <= idx)
					{
						CXmlAttribute* pXmlAttr = NULL;

						// Attribute
						pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_MIN);
						if (pXmlAttr)
						{
							double fValue = 0;
							pXmlAttr->GetValue(&fValue, sizeof(double));
							stOpt.m_pstRange[cameraIdx][idx].m_fMin = fValue;
						}

						pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_MAX);
						if (pXmlAttr)
						{
							double fValue = 0;
							pXmlAttr->GetValue(&fValue, sizeof(double));
							stOpt.m_pstRange[cameraIdx][idx].m_fMax = fValue;
						}
					}
				}
			}
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_SIZESPEC))
		{
			const int nCount = pChildNode->GetNodeCount();
			for (int i = 0; i < nCount; i++)
			{
				CXmlNode* pTempNode = pChildNode->GetNode(i);
				if (NULL == pTempNode)
					continue;

				const TCHAR* pTitle = pTempNode->GetTitle();

				int idx = -1;

				if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle,	   XML_OPTION_MEASURE01))	idx = 0;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE02))	idx = 1;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE03))	idx = 2;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE04))	idx = 3;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE05))	idx = 4;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE06))	idx = 5;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE07))	idx = 6;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE08))	idx = 7;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE09))	idx = 8;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE10))	idx = 9;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE11))	idx = 10;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE12))	idx = 11;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE13))	idx = 12;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE14))	idx = 13;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE15))	idx = 14;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE16))	idx = 15;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE17))	idx = 16;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE18))	idx = 17;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE19))	idx = 18;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE20))	idx = 19;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE21))	idx = 20;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE22))	idx = 21;

				// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE23))	idx = 22;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE24))	idx = 23;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE25))	idx = 24;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE26))	idx = 25;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE27))	idx = 26;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE28))	idx = 27;

				if (0 <= idx)
				{
					CXmlAttribute* pXmlAttr = NULL;

					// Attribute
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_MIN);
					if (pXmlAttr)
					{
						double fValue = 0;
						pXmlAttr->GetValue(&fValue, sizeof(double));
						stOpt.m_pstRangeSpec[idx].m_fMin = fValue;
					}

					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_MAX);
					if (pXmlAttr)
					{
						double fValue = 0;
						pXmlAttr->GetValue(&fValue, sizeof(double));
						stOpt.m_pstRangeSpec[idx].m_fMax = fValue;
					}
				}
			}
		}
#ifdef USE_VALID_RANGE
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_SIZEVALID))
		{

			const int nCount = pChildNode->GetNodeCount();
			for (int i = 0; i < nCount; i++)
			{
				CXmlNode* pTempNode = pChildNode->GetNode(i);
				if (NULL == pTempNode)
					continue;

				const TCHAR* pTitle = pTempNode->GetTitle();

				int idx = -1;

				if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle,	   XML_OPTION_MEASURE01))	idx = 0;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE02))	idx = 1;
				// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE03))	idx = 2;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE04))	idx = 3;
				// Ver1.3.7.2 (치수 영역 추가 없이 PLC 통신 데이터 추가 (M1, M2)) 
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE05))	idx = 4;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE06))	idx = 5;
				// Ver1.3.7.4 (치수 영역 추가 없이 PLC 통신 데이터 추가 (S1-S3)) 
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE07))	idx = 6;

				if (0 <= idx)
				{
					CXmlAttribute* pXmlAttr = NULL;

					// Attribute
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_MIN);
					if (pXmlAttr)
					{
						double fValue = 0;
						pXmlAttr->GetValue(&fValue, sizeof(double));
						stOpt.m_pstValidRange[idx].m_fMin = fValue;
					}

					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_MAX);
					if (pXmlAttr)
					{
						double fValue = 0;
						pXmlAttr->GetValue(&fValue, sizeof(double));
						stOpt.m_pstValidRange[idx].m_fMax = fValue;
					}
				}

			}
		}
#endif
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_INSPECTSTEP))
		{
			const int nCount = pChildNode->GetNodeCount();
			for (int i = 0; i < nCount; i++)
			{
				CXmlNode* pTempNode = pChildNode->GetNode(i);
				if (NULL == pTempNode)
					continue;

				const TCHAR* pTitle = pTempNode->GetTitle();
				if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_INSPECTSTEP_FIRST))
				{
					CXmlAttribute* pXmlAttr = NULL;
					DWORD dwValue = 0;

					stOpt.m_stFirstCameraStep.m_bStep001 = TRUE;
					stOpt.m_stFirstCameraStep.m_bStep002 = TRUE;
					stOpt.m_stFirstCameraStep.m_bStep003 = TRUE;
					stOpt.m_stFirstCameraStep.m_bStep004 = TRUE;
					stOpt.m_stFirstCameraStep.m_bStep005 = TRUE;
					stOpt.m_stFirstCameraStep.m_bStep006 = TRUE;


					// Attribute
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP01);
					if (pXmlAttr)
					{
						pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
						stOpt.m_stFirstCameraStep.m_bStep001 = (BOOL)dwValue;
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP02);
					if (pXmlAttr)
					{
						pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
						stOpt.m_stFirstCameraStep.m_bStep002 = (BOOL)dwValue;
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP03);
					if (pXmlAttr)
					{
						pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
						stOpt.m_stFirstCameraStep.m_bStep003 = (BOOL)dwValue;
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP04);
					if (pXmlAttr)
					{
						pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
						stOpt.m_stFirstCameraStep.m_bStep004 = (BOOL)dwValue;
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP05);
					if (pXmlAttr)
					{
						pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
						stOpt.m_stFirstCameraStep.m_bStep005 = (BOOL)dwValue;
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP06);
					if (pXmlAttr)
					{
						pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
						stOpt.m_stFirstCameraStep.m_bStep006 = (BOOL)dwValue;
					}
				}
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_INSPECTSTEP_SECOND))
				{
					CXmlAttribute* pXmlAttr = NULL;
					DWORD dwValue = 0;

					stOpt.m_stSecondCameraStep.m_bStep001 = FALSE;
					stOpt.m_stSecondCameraStep.m_bStep002 = TRUE;
					stOpt.m_stSecondCameraStep.m_bStep003 = TRUE;
					stOpt.m_stSecondCameraStep.m_bStep004 = TRUE;
					stOpt.m_stSecondCameraStep.m_bStep005 = TRUE;
					stOpt.m_stSecondCameraStep.m_bStep006 = TRUE;

					// Attribute
#ifdef DEF_SECONDCAMERA_CHECKSIZE
					stOpt.m_stSecondCameraStep.m_bStep001 = TRUE;

					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP01);
					if (pXmlAttr)
					{
						pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
						stOpt.m_stSecondCameraStep.m_bStep001 = (BOOL)dwValue;
					}
					else
					{
						stOpt.m_stSecondCameraStep.m_bStep001 = FALSE;
					}
#endif
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP02);
					if (pXmlAttr)
					{
						pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
						stOpt.m_stSecondCameraStep.m_bStep002 = (BOOL)dwValue;
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP03);
					if (pXmlAttr)
					{
						pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
						stOpt.m_stSecondCameraStep.m_bStep003 = (BOOL)dwValue;
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP04);
					if (pXmlAttr)
					{
						pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
						stOpt.m_stSecondCameraStep.m_bStep004 = (BOOL)dwValue;
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP05);
					if (pXmlAttr)
					{
						pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
						stOpt.m_stSecondCameraStep.m_bStep005 = (BOOL)dwValue;
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP06);
					if (pXmlAttr)
					{
						pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
						stOpt.m_stSecondCameraStep.m_bStep006 = (BOOL)dwValue;
					}
				}
			}
		}
		// Version 1.3.6.9 Update
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_INSPECTTOSIZE))
		{
			const int nCount = pChildNode->GetNodeCount();
			for (int i = 0; i < nCount; i++)
			{
				CXmlNode* pTempNode = pChildNode->GetNode(i);
				if (NULL == pTempNode)
					continue;

				const TCHAR* pTitle = pTempNode->GetTitle();
				if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_INSPECTTOSIZE_ALL))
				{
					CXmlAttribute* pXmlAttr = NULL;
					DWORD dwValue = 0;

					stOpt.m_stShapeToSize.m_bStep001 = FALSE;
					stOpt.m_stShapeToSize.m_bStep002 = FALSE;
					stOpt.m_stShapeToSize.m_bStep003 = FALSE;
					stOpt.m_stShapeToSize.m_bStep004 = FALSE;
					stOpt.m_stShapeToSize.m_bStep005 = FALSE;
					stOpt.m_stShapeToSize.m_bStep006 = FALSE;


					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP01);
					if (pXmlAttr)
					{
						pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
						stOpt.m_stShapeToSize.m_bStep001 = (BOOL)dwValue;
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP02);
					if (pXmlAttr)
					{
						pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
						stOpt.m_stShapeToSize.m_bStep002 = (BOOL)dwValue;
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP03);
					if (pXmlAttr)
					{
						pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
						stOpt.m_stShapeToSize.m_bStep003 = (BOOL)dwValue;
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP04);
					if (pXmlAttr)
					{
						pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
						stOpt.m_stShapeToSize.m_bStep004 = (BOOL)dwValue;
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP05);
					if (pXmlAttr)
					{
						pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
						stOpt.m_stShapeToSize.m_bStep005 = (BOOL)dwValue;
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP06);
					if (pXmlAttr)
					{
						pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
						stOpt.m_stShapeToSize.m_bStep006 = (BOOL)dwValue;
					}
				}
			}
		}

		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_INSPECTSTEPNAME))
		{
			const int nCount = pChildNode->GetNodeCount();
			for (int i = 0; i < nCount; i++)
			{
				CXmlNode* pTempNode = pChildNode->GetNode(i);
				if (NULL == pTempNode)
					continue;

				const TCHAR* pTitle = pTempNode->GetTitle();
				if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_INSPECTSTEP_FIRST))
				{
					CXmlAttribute* pXmlAttr = NULL;

					// Attribute
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP01_TITLE);
					if (pXmlAttr)
					{
						const int nTxtLen = pXmlAttr->GetValue(0, NULL);
						pXmlAttr->GetValue(stOpt.m_stFirstCameraStep.m_szTitleStep01, nTxtLen + 1);
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP02_TITLE);
					if (pXmlAttr)
					{
						const int nTxtLen = pXmlAttr->GetValue(0, NULL);
						pXmlAttr->GetValue(stOpt.m_stFirstCameraStep.m_szTitleStep02, nTxtLen + 1);
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP03_TITLE);
					if (pXmlAttr)
					{
						const int nTxtLen = pXmlAttr->GetValue(0, NULL);
						pXmlAttr->GetValue(stOpt.m_stFirstCameraStep.m_szTitleStep03, nTxtLen + 1);
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP04_TITLE);
					if (pXmlAttr)
					{
						const int nTxtLen = pXmlAttr->GetValue(0, NULL);
						pXmlAttr->GetValue(stOpt.m_stFirstCameraStep.m_szTitleStep04, nTxtLen + 1);
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP05_TITLE);
					if (pXmlAttr)
					{
						const int nTxtLen = pXmlAttr->GetValue(0, NULL);
						pXmlAttr->GetValue(stOpt.m_stFirstCameraStep.m_szTitleStep05, nTxtLen + 1);
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP06_TITLE);
					if (pXmlAttr)
					{
						const int nTxtLen = pXmlAttr->GetValue(0, NULL);
						pXmlAttr->GetValue(stOpt.m_stFirstCameraStep.m_szTitleStep06, nTxtLen + 1);
					}
				}
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_INSPECTSTEP_SECOND))
				{
					CXmlAttribute* pXmlAttr = NULL;
					// Attribute
#ifdef DEF_SECONDCAMERA_CHECKSIZE
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP01_TITLE);
					if (pXmlAttr)
					{
						const int nTxtLen = pXmlAttr->GetValue(0, NULL);
						pXmlAttr->GetValue(stOpt.m_stSecondCameraStep.m_szTitleStep01, nTxtLen + 1);
					}
#endif
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP02_TITLE);
					if (pXmlAttr)
					{
						const int nTxtLen = pXmlAttr->GetValue(0, NULL);
						pXmlAttr->GetValue(stOpt.m_stSecondCameraStep.m_szTitleStep02, nTxtLen + 1);
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP03_TITLE);
					if (pXmlAttr)
					{
						const int nTxtLen = pXmlAttr->GetValue(0, NULL);
						pXmlAttr->GetValue(stOpt.m_stSecondCameraStep.m_szTitleStep03, nTxtLen + 1);
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP04_TITLE);
					if (pXmlAttr)
					{
						const int nTxtLen = pXmlAttr->GetValue(0, NULL);
						pXmlAttr->GetValue(stOpt.m_stSecondCameraStep.m_szTitleStep04, nTxtLen + 1);
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP05_TITLE);
					if (pXmlAttr)
					{
						const int nTxtLen = pXmlAttr->GetValue(0, NULL);
						pXmlAttr->GetValue(stOpt.m_stSecondCameraStep.m_szTitleStep05, nTxtLen + 1);
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP06_TITLE);
					if (pXmlAttr)
					{
						const int nTxtLen = pXmlAttr->GetValue(0, NULL);
						pXmlAttr->GetValue(stOpt.m_stSecondCameraStep.m_szTitleStep06, nTxtLen + 1);
					}
				}
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_INSPECTTOSIZE_ALL))
				{
					CXmlAttribute* pXmlAttr = NULL;

					// Attribute
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP01_TITLE);
					if (pXmlAttr)
					{
						const int nTxtLen = pXmlAttr->GetValue(0, NULL);
						pXmlAttr->GetValue(stOpt.m_stShapeToSize.m_szTitleStep01, nTxtLen + 1);
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP02_TITLE);
					if (pXmlAttr)
					{
						const int nTxtLen = pXmlAttr->GetValue(0, NULL);
						pXmlAttr->GetValue(stOpt.m_stShapeToSize.m_szTitleStep02, nTxtLen + 1);
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP03_TITLE);
					if (pXmlAttr)
					{
						const int nTxtLen = pXmlAttr->GetValue(0, NULL);
						pXmlAttr->GetValue(stOpt.m_stShapeToSize.m_szTitleStep03, nTxtLen + 1);
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP04_TITLE);
					if (pXmlAttr)
					{
						const int nTxtLen = pXmlAttr->GetValue(0, NULL);
						pXmlAttr->GetValue(stOpt.m_stShapeToSize.m_szTitleStep04, nTxtLen + 1);
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP05_TITLE);
					if (pXmlAttr)
					{
						const int nTxtLen = pXmlAttr->GetValue(0, NULL);
						pXmlAttr->GetValue(stOpt.m_stShapeToSize.m_szTitleStep05, nTxtLen + 1);
					}
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_STEP06_TITLE);
					if (pXmlAttr)
					{
						const int nTxtLen = pXmlAttr->GetValue(0, NULL);
						pXmlAttr->GetValue(stOpt.m_stShapeToSize.m_szTitleStep06, nTxtLen + 1);
					}
				}
			}
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_SIZENAME))
		{
			const int nCount = pChildNode->GetNodeCount();
			for (int i = 0; i < nCount; i++)
			{
				CXmlNode* pTempNode = pChildNode->GetNode(i);
				if (NULL == pTempNode)
					continue;

				const TCHAR* pTitle = pTempNode->GetTitle();

				int idx = -1;

				if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE01))		idx = 0;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE02))	idx = 1;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE03))	idx = 2;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE04))	idx = 3;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE05))	idx = 4;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE06))	idx = 5;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE07))	idx = 6;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE08))	idx = 7;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE09))	idx = 8;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE10))	idx = 9;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE11))	idx = 10;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE12))	idx = 11;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE13))	idx = 12;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE14))	idx = 13;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE15))	idx = 14;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE16))	idx = 15;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE17))	idx = 16;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE18))	idx = 17;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE19))	idx = 18;

				// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE20))	idx = 19;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE21))	idx = 20;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE22))	idx = 21;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE23))	idx = 22;
				else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_MEASURE24))	idx = 23;
				
				// SIZE NAME은 X1-X2 등은 포함하지 않음

				if (0 <= idx)
				{
					CXmlAttribute* pXmlAttr = NULL;

					// Attribute
					pXmlAttr = pTempNode->GetAttribute(XML_OPTIONATTR_SIZENAME);
					if (pXmlAttr)
					{
						const int nTxtLen = pXmlAttr->GetValue(0, NULL);
						pXmlAttr->GetValue(stOpt.m_stSizeName.m_szName[idx], nTxtLen + 1);
					}
				}
			}
		}
#ifdef DEF_DELAY_CAPTURE
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_OPTION_CAPTURE))
		{
			CXmlAttribute* pXmlAttr = NULL;

			pXmlAttr = pChildNode->GetAttribute(XML_OPTIONATTR_DELAY);
			if (pXmlAttr)
			{
				DWORD dwValue = 0;
				pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
				stOpt.m_stCapture.m_nDelay = dwValue;
			}
		}
#endif
	}

	return TRUE;
}

CXmlNode* CXml::SaveOption(const  INFO_OPTION& stOpt)
{
	CXmlNode* pXmlNode = new CXmlNode(XML_OPTION_ROOT, NULL);

	CXmlNode* pNode = NULL;

#ifdef DEF_DELAY_CAPTURE
	pNode = new CXmlNode(XML_OPTION_CAPTURE, NULL);
	{
		AddAttributeUnsignedInt(pNode, XML_OPTIONATTR_DELAY, stOpt.m_stCapture.m_nDelay);
	}
	pXmlNode->AddNode(pNode);	delete pNode;
#endif
	
	pNode = new CXmlNode(XML_OPTION_ALARAM, NULL);
	{
		// Sample A
		CXmlNode* pChildNode = new CXmlNode(XML_OPTION_ASAMPLE, NULL);
		AddAttributeUnsignedInt(pChildNode, XML_OPTIONATTR_COUNT, stOpt.m_stSampleA.m_nMinCount);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_ERATIO, stOpt.m_stSampleA.m_fAlarmRatio);
		pNode->AddNode(pChildNode);	delete pChildNode;

		// Sample B
		pChildNode = new CXmlNode(XML_OPTION_BSAMPLE, NULL);
		AddAttributeUnsignedInt(pChildNode, XML_OPTIONATTR_COUNT, stOpt.m_stSampleB.m_nMinCount);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_ERATIO, stOpt.m_stSampleB.m_fAlarmRatio);
		pNode->AddNode(pChildNode);	delete pChildNode;

	}
	pXmlNode->AddNode(pNode);	delete pNode;

	for (int i = 0; i < MAX_CAMERA_INTERFACE; i++)
	{
		pNode = new CXmlNode(XML_OPTION_SIZERANGE, NULL);
		{
			AddAttributeUnsignedInt(pNode, XML_OPTIONATTR_CAMERA, i);
			int idx = 0;

			CXmlNode* pChildNode = new CXmlNode(XML_OPTION_MEASURE01, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE02, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE03, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE04, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE05, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE06, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE07, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE08, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE09, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE10, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE11, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE12, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE13, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE14, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE15, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE16, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE17, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE18, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE19, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE20, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE21, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE22, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
			pChildNode = new CXmlNode(XML_OPTION_MEASURE23, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE24, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE25, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE26, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE27, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

			pChildNode = new CXmlNode(XML_OPTION_MEASURE28, NULL);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRange[i][idx].m_fMin);
			AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRange[i][idx].m_fMax);
			pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		}
		pXmlNode->AddNode(pNode);	delete pNode;
	}

#ifdef USE_VALID_RANGE
	pNode = new CXmlNode(XML_OPTION_SIZEVALID, NULL);
	{
		int idx = 0;

		CXmlNode* pChildNode = new CXmlNode(XML_OPTION_MEASURE01, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstValidRange[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstValidRange[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE02, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstValidRange[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstValidRange[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
		pChildNode = new CXmlNode(XML_OPTION_MEASURE03, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstValidRange[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstValidRange[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE04, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstValidRange[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstValidRange[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		// Ver1.3.7.2 (치수 영역 추가 없이 PLC 통신 데이터 추가 (M1, M2)) 
		pChildNode = new CXmlNode(XML_OPTION_MEASURE05, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstValidRange[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstValidRange[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE06, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstValidRange[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstValidRange[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;
		
		// Ver1.3.7.4 (치수 영역 추가 없이 PLC 통신 데이터 추가 (S1-S3)) 
		pChildNode = new CXmlNode(XML_OPTION_MEASURE07, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstValidRange[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstValidRange[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;
	}
	pXmlNode->AddNode(pNode);	delete pNode;
#endif
	pNode = new CXmlNode(XML_OPTION_SIZESPEC, NULL);
	{
		int idx = 0;

		CXmlNode* pChildNode = new CXmlNode(XML_OPTION_MEASURE01, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE02, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE03, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE04, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE05, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE06, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE07, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE08, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE09, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE10, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE11, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE12, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE13, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE14, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE15, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE16, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE17, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE18, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE19, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE20, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE21, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE22, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
		pChildNode = new CXmlNode(XML_OPTION_MEASURE23, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE24, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE25, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE26, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE27, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE28, NULL);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MIN, stOpt.m_pstRangeSpec[idx].m_fMin);
		AddAttributeDouble(pChildNode, XML_OPTIONATTR_MAX, stOpt.m_pstRangeSpec[idx].m_fMax);
		pNode->AddNode(pChildNode);	delete pChildNode;		idx++;

	}
	pXmlNode->AddNode(pNode);	delete pNode;

	// Step Selection
	pNode = new CXmlNode(XML_OPTION_INSPECTSTEP, NULL);
	{
		// Step Selection: First
		CXmlNode* pChildNode = new CXmlNode(XML_OPTION_INSPECTSTEP_FIRST, NULL);
		{
			AddAttributeUnsignedInt(pChildNode, XML_OPTIONATTR_STEP01, stOpt.m_stFirstCameraStep.m_bStep001);
			AddAttributeUnsignedInt(pChildNode, XML_OPTIONATTR_STEP02, stOpt.m_stFirstCameraStep.m_bStep002);
			AddAttributeUnsignedInt(pChildNode, XML_OPTIONATTR_STEP03, stOpt.m_stFirstCameraStep.m_bStep003);
			AddAttributeUnsignedInt(pChildNode, XML_OPTIONATTR_STEP04, stOpt.m_stFirstCameraStep.m_bStep004);
			AddAttributeUnsignedInt(pChildNode, XML_OPTIONATTR_STEP05, stOpt.m_stFirstCameraStep.m_bStep005);
			AddAttributeUnsignedInt(pChildNode, XML_OPTIONATTR_STEP06, stOpt.m_stFirstCameraStep.m_bStep006);
		}
		pNode->AddNode(pChildNode);	delete pChildNode;

		// Step Selection: Second
		pChildNode = new CXmlNode(XML_OPTION_INSPECTSTEP_SECOND, NULL);
		{
#ifdef DEF_SECONDCAMERA_CHECKSIZE
			AddAttributeUnsignedInt(pChildNode, XML_OPTIONATTR_STEP01, stOpt.m_stSecondCameraStep.m_bStep001);
#endif
			AddAttributeUnsignedInt(pChildNode, XML_OPTIONATTR_STEP02, stOpt.m_stSecondCameraStep.m_bStep002);
			AddAttributeUnsignedInt(pChildNode, XML_OPTIONATTR_STEP03, stOpt.m_stSecondCameraStep.m_bStep003);
			AddAttributeUnsignedInt(pChildNode, XML_OPTIONATTR_STEP04, stOpt.m_stSecondCameraStep.m_bStep004);
			AddAttributeUnsignedInt(pChildNode, XML_OPTIONATTR_STEP05, stOpt.m_stSecondCameraStep.m_bStep005);
			AddAttributeUnsignedInt(pChildNode, XML_OPTIONATTR_STEP06, stOpt.m_stSecondCameraStep.m_bStep006);
		}
		pNode->AddNode(pChildNode);	delete pChildNode;
	}
	pXmlNode->AddNode(pNode);	delete pNode;

	// Version 1.3.6.9 Update
	pNode = new CXmlNode(XML_OPTION_INSPECTTOSIZE, NULL);
	{
		// Step Selection
		CXmlNode* pChildNode = new CXmlNode(XML_OPTION_INSPECTTOSIZE_ALL, NULL);
		{
			AddAttributeUnsignedInt(pChildNode, XML_OPTIONATTR_STEP01, stOpt.m_stShapeToSize.m_bStep001);
			AddAttributeUnsignedInt(pChildNode, XML_OPTIONATTR_STEP02, stOpt.m_stShapeToSize.m_bStep002);
			AddAttributeUnsignedInt(pChildNode, XML_OPTIONATTR_STEP03, stOpt.m_stShapeToSize.m_bStep003);
			AddAttributeUnsignedInt(pChildNode, XML_OPTIONATTR_STEP04, stOpt.m_stShapeToSize.m_bStep004);
			AddAttributeUnsignedInt(pChildNode, XML_OPTIONATTR_STEP05, stOpt.m_stShapeToSize.m_bStep005);
			AddAttributeUnsignedInt(pChildNode, XML_OPTIONATTR_STEP06, stOpt.m_stShapeToSize.m_bStep006);
		}
		pNode->AddNode(pChildNode);	delete pChildNode;
	}
	pXmlNode->AddNode(pNode);	delete pNode;

	// Step Title
	pNode = new CXmlNode(XML_OPTION_INSPECTSTEPNAME, NULL);
	{
		// Step Selection: First
		CXmlNode* pChildNode = new CXmlNode(XML_OPTION_INSPECTSTEP_FIRST, NULL);
		{
			AddAttributeString(pChildNode, XML_OPTIONATTR_STEP01_TITLE, stOpt.m_stFirstCameraStep.m_szTitleStep01);
			AddAttributeString(pChildNode, XML_OPTIONATTR_STEP02_TITLE, stOpt.m_stFirstCameraStep.m_szTitleStep02);
			AddAttributeString(pChildNode, XML_OPTIONATTR_STEP03_TITLE, stOpt.m_stFirstCameraStep.m_szTitleStep03);
			AddAttributeString(pChildNode, XML_OPTIONATTR_STEP04_TITLE, stOpt.m_stFirstCameraStep.m_szTitleStep04);
			AddAttributeString(pChildNode, XML_OPTIONATTR_STEP05_TITLE, stOpt.m_stFirstCameraStep.m_szTitleStep05);
			AddAttributeString(pChildNode, XML_OPTIONATTR_STEP06_TITLE, stOpt.m_stFirstCameraStep.m_szTitleStep06);
		}
		pNode->AddNode(pChildNode);	delete pChildNode;

		// Step Selection: Second
		pChildNode = new CXmlNode(XML_OPTION_INSPECTSTEP_SECOND, NULL);
		{
			AddAttributeString(pChildNode, XML_OPTIONATTR_STEP02_TITLE, stOpt.m_stSecondCameraStep.m_szTitleStep02);
			AddAttributeString(pChildNode, XML_OPTIONATTR_STEP03_TITLE, stOpt.m_stSecondCameraStep.m_szTitleStep03);
			AddAttributeString(pChildNode, XML_OPTIONATTR_STEP04_TITLE, stOpt.m_stSecondCameraStep.m_szTitleStep04);
			AddAttributeString(pChildNode, XML_OPTIONATTR_STEP05_TITLE, stOpt.m_stSecondCameraStep.m_szTitleStep05);
			AddAttributeString(pChildNode, XML_OPTIONATTR_STEP06_TITLE, stOpt.m_stSecondCameraStep.m_szTitleStep06);
		}
		pNode->AddNode(pChildNode);	delete pChildNode;

		// Version 1.3.6.9 Update
		// Step Selection: Shape To Size
		pChildNode = new CXmlNode(XML_OPTION_INSPECTTOSIZE_ALL, NULL);
		{
			AddAttributeString(pChildNode, XML_OPTIONATTR_STEP01_TITLE, stOpt.m_stShapeToSize.m_szTitleStep01);
			AddAttributeString(pChildNode, XML_OPTIONATTR_STEP02_TITLE, stOpt.m_stShapeToSize.m_szTitleStep02);
			AddAttributeString(pChildNode, XML_OPTIONATTR_STEP03_TITLE, stOpt.m_stShapeToSize.m_szTitleStep03);
			AddAttributeString(pChildNode, XML_OPTIONATTR_STEP04_TITLE, stOpt.m_stShapeToSize.m_szTitleStep04);
			AddAttributeString(pChildNode, XML_OPTIONATTR_STEP05_TITLE, stOpt.m_stShapeToSize.m_szTitleStep05);
			AddAttributeString(pChildNode, XML_OPTIONATTR_STEP06_TITLE, stOpt.m_stShapeToSize.m_szTitleStep06);
		}
		pNode->AddNode(pChildNode);	delete pChildNode;
	}
	pXmlNode->AddNode(pNode);	delete pNode;

	// Size Name
	pNode = new CXmlNode(XML_OPTION_SIZENAME, NULL);
	{
		int idx = 0;
		CXmlNode* pChildNode = new CXmlNode(XML_OPTION_MEASURE01, NULL);
		AddAttributeString(pChildNode, XML_OPTIONATTR_SIZENAME, stOpt.m_stSizeName.m_szName[idx]);
		pNode->AddNode(pChildNode);	delete pChildNode; idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE02, NULL);
		AddAttributeString(pChildNode, XML_OPTIONATTR_SIZENAME, stOpt.m_stSizeName.m_szName[idx]);
		pNode->AddNode(pChildNode);	delete pChildNode; idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE03, NULL);
		AddAttributeString(pChildNode, XML_OPTIONATTR_SIZENAME, stOpt.m_stSizeName.m_szName[idx]);
		pNode->AddNode(pChildNode);	delete pChildNode; idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE04, NULL);
		AddAttributeString(pChildNode, XML_OPTIONATTR_SIZENAME, stOpt.m_stSizeName.m_szName[idx]);
		pNode->AddNode(pChildNode);	delete pChildNode; idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE05, NULL);
		AddAttributeString(pChildNode, XML_OPTIONATTR_SIZENAME, stOpt.m_stSizeName.m_szName[idx]);
		pNode->AddNode(pChildNode);	delete pChildNode; idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE06, NULL);
		AddAttributeString(pChildNode, XML_OPTIONATTR_SIZENAME, stOpt.m_stSizeName.m_szName[idx]);
		pNode->AddNode(pChildNode);	delete pChildNode; idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE07, NULL);
		AddAttributeString(pChildNode, XML_OPTIONATTR_SIZENAME, stOpt.m_stSizeName.m_szName[idx]);
		pNode->AddNode(pChildNode);	delete pChildNode; idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE08, NULL);
		AddAttributeString(pChildNode, XML_OPTIONATTR_SIZENAME, stOpt.m_stSizeName.m_szName[idx]);
		pNode->AddNode(pChildNode);	delete pChildNode; idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE09, NULL);
		AddAttributeString(pChildNode, XML_OPTIONATTR_SIZENAME, stOpt.m_stSizeName.m_szName[idx]);
		pNode->AddNode(pChildNode);	delete pChildNode; idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE10, NULL);
		AddAttributeString(pChildNode, XML_OPTIONATTR_SIZENAME, stOpt.m_stSizeName.m_szName[idx]);
		pNode->AddNode(pChildNode);	delete pChildNode; idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE11, NULL);
		AddAttributeString(pChildNode, XML_OPTIONATTR_SIZENAME, stOpt.m_stSizeName.m_szName[idx]);
		pNode->AddNode(pChildNode);	delete pChildNode; idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE12, NULL);
		AddAttributeString(pChildNode, XML_OPTIONATTR_SIZENAME, stOpt.m_stSizeName.m_szName[idx]);
		pNode->AddNode(pChildNode);	delete pChildNode; idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE13, NULL);
		AddAttributeString(pChildNode, XML_OPTIONATTR_SIZENAME, stOpt.m_stSizeName.m_szName[idx]);
		pNode->AddNode(pChildNode);	delete pChildNode; idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE14, NULL);
		AddAttributeString(pChildNode, XML_OPTIONATTR_SIZENAME, stOpt.m_stSizeName.m_szName[idx]);
		pNode->AddNode(pChildNode);	delete pChildNode; idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE15, NULL);
		AddAttributeString(pChildNode, XML_OPTIONATTR_SIZENAME, stOpt.m_stSizeName.m_szName[idx]);
		pNode->AddNode(pChildNode);	delete pChildNode; idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE16, NULL);
		AddAttributeString(pChildNode, XML_OPTIONATTR_SIZENAME, stOpt.m_stSizeName.m_szName[idx]);
		pNode->AddNode(pChildNode);	delete pChildNode; idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE17, NULL);
		AddAttributeString(pChildNode, XML_OPTIONATTR_SIZENAME, stOpt.m_stSizeName.m_szName[idx]);
		pNode->AddNode(pChildNode);	delete pChildNode; idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE18, NULL);
		AddAttributeString(pChildNode, XML_OPTIONATTR_SIZENAME, stOpt.m_stSizeName.m_szName[idx]);
		pNode->AddNode(pChildNode);	delete pChildNode; idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE19, NULL);
		AddAttributeString(pChildNode, XML_OPTIONATTR_SIZENAME, stOpt.m_stSizeName.m_szName[idx]);
		pNode->AddNode(pChildNode);	delete pChildNode; idx++;

		// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
		pChildNode = new CXmlNode(XML_OPTION_MEASURE20, NULL);
		AddAttributeString(pChildNode, XML_OPTIONATTR_SIZENAME, stOpt.m_stSizeName.m_szName[idx]);
		pNode->AddNode(pChildNode);	delete pChildNode; idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE21, NULL);
		AddAttributeString(pChildNode, XML_OPTIONATTR_SIZENAME, stOpt.m_stSizeName.m_szName[idx]);
		pNode->AddNode(pChildNode);	delete pChildNode; idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE22, NULL);
		AddAttributeString(pChildNode, XML_OPTIONATTR_SIZENAME, stOpt.m_stSizeName.m_szName[idx]);
		pNode->AddNode(pChildNode);	delete pChildNode; idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE23, NULL);
		AddAttributeString(pChildNode, XML_OPTIONATTR_SIZENAME, stOpt.m_stSizeName.m_szName[idx]);
		pNode->AddNode(pChildNode);	delete pChildNode; idx++;

		pChildNode = new CXmlNode(XML_OPTION_MEASURE24, NULL);
		AddAttributeString(pChildNode, XML_OPTIONATTR_SIZENAME, stOpt.m_stSizeName.m_szName[idx]);
		pNode->AddNode(pChildNode);	delete pChildNode; idx++;

		// SIZE NAME은 X1-X2 등은 포함하지 않음
	}
	pXmlNode->AddNode(pNode);	delete pNode;

	return pXmlNode;
}



BOOL CXml::LoadInspection(TCHAR* pszPath, INFO_INSPECTION& stInspection)
{
	if (NULL == pszPath)
		return FALSE;

	BOOL bResult = FALSE;

	CXmlFile xmlFile;
	CXmlNode* pXmlNode = xmlFile.Load(pszPath, XML_INSPECT_ROOT);
	if (pXmlNode)
	{
		INFO_INSPECTION stInspect;
		memset(&stInspect, 0x00, sizeof(INFO_INSPECTION));

		bResult = LoadInspection(stInspect, pXmlNode);
		delete pXmlNode;

		if (bResult)
		{
			stInspection = stInspect;
		}
	}
	return bResult;
}

BOOL CXml::SaveInspection(TCHAR* pszPath, INFO_INSPECTION& stInspection, TYPE_CAMERAPOS ePos)
{
	if (NULL == pszPath)
		return FALSE;

	CXmlNode* pXmlNode = SaveInspection(stInspection, ePos);
	BOOL bResult = FALSE;
	if (pXmlNode)
	{
		CXmlFile xmlFile;
		bResult = xmlFile.Save(pszPath, XML_INSPECT_ROOT, pXmlNode);

		if (pXmlNode)
			delete pXmlNode;
	}
	else
	{
		return FALSE;
	}
	return bResult;
}


//20211231 함수 원형
//BOOL CXml::LoadInspection(INFO_INSPECTION& stInspection, CXmlNode* pXmlNode)
//{
//	if (NULL == pXmlNode)
//		return FALSE;
//
//	const int nCount = pXmlNode->GetNodeCount();
//	for (int i = 0; i < nCount; i++)
//	{
//		CXmlNode* pChildNode = pXmlNode->GetNode(i);
//		if (NULL == pChildNode)
//			continue;
//
//		const TCHAR* pTitle = pChildNode->GetTitle();
//		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_STEPSIZE))
//		{
//			LoadInspectionStepSize(stInspection.m_stSize, pChildNode);
//		}
//		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_STEPSTAIN))
//		{
//			LoadInspectionStepStain(stInspection.m_stStain, pChildNode);
//		}
//		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_STEPDIFFER))
//		{
//			LoadInspectionStepDiffer(stInspection.m_stDiffer, pChildNode);
//		}
//		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_STEPBUBBLE))
//		{
//			LoadInspectionStepBubble(stInspection.m_stBubble, pChildNode);
//		}
//		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_STEPSCRATCH))
//		{
//			LoadInspectionStepScratch(stInspection.m_stScratch, pChildNode);
//		}
//		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_STEPSTAMP))
//		{
//			LoadInspectionStepStamp(stInspection.m_stStamp, pChildNode);
//		}
//		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_STEPSIZESECOND))
//		{
//			LoadInspectionStepSize(stInspection.m_stSizeSecond, pChildNode);
//		}
//		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_CALC))
//		{
//			LoadInspectionCalc(stInspection.m_stSizeCalc, pChildNode);
//		}
//	}
//
//	stInspection.m_bInit = TRUE;
//	return TRUE;
//}

BOOL CXml::LoadInspection(INFO_INSPECTION& stInspection, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_CAMERACHECK))
		{
			int nValue = 0;
			CXmlAttribute* pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_CAMERANUM);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&nValue, sizeof(int));
				stInspection.m_nCameraNum = nValue;
			}
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_STEPSIZE))
		{
			LoadInspectionStepSize(stInspection.m_stSize, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_STEPSTAIN))
		{
			LoadInspectionStepStain(stInspection.m_stStain, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_STEPDIFFER))
		{
			LoadInspectionStepDiffer(stInspection.m_stDiffer, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_STEPBUBBLE))
		{
			LoadInspectionStepBubble(stInspection.m_stBubble, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_STEPSCRATCH))
		{
			LoadInspectionStepScratch(stInspection.m_stScratch, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_STEPSTAMP))
		{
			LoadInspectionStepStamp(stInspection.m_stStamp, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_STEPSIZESECOND))
		{
			LoadInspectionStepSize(stInspection.m_stSizeSecond, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_CALC))
		{
			LoadInspectionCalc(stInspection.m_stSizeCalc, pChildNode);
		}
	}

	stInspection.m_bInit = TRUE;
	return TRUE;
}

BOOL CXml::LoadInspectionStepSize(INFO_INSPECTION_SIZE& stSize, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	TCHAR szTxt[MAX_NAME_LEN] = { 0, };

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_SIZECALIBRATE))
		{
			LoadInspectionStepSizeCalibrate(stSize.m_stCalibration, pChildNode);
		}
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_SIZEGAIN))
		{
			LoadInspectionStepSizeGain(stSize.m_stSizeGain, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_SIZEROILIST))
		{
			LoadInspectionStepSizeRoi(stSize, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_SIZESAMPLE))
		{
			LoadInspectionStepSizeSample(stSize, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_STEPSTROBELIST))
		{
			int idxStrobe = 0;
			
			const int nStrobeCount = pChildNode->GetNodeCount();
			for (int s = 0; s < nStrobeCount; s++)
			{
				CXmlNode* pStrobeNode = pChildNode->GetNode(s);
				if (NULL == pStrobeNode || idxStrobe >= MAX_STEPSTROBE_LIST)
					continue;

				stSize.m_pstStepStrobe[idxStrobe].m_eStrobeType = TYPE_STROBE_OFF;
				stSize.m_pstStepStrobe[idxStrobe].m_nStrobeBrightness = 0;

				// Strobe Type
				CXmlAttribute* pXmlAttr = pStrobeNode->GetAttribute(XML_INSPECTATTR_STROBETYPE);
				if (pXmlAttr)
				{
					pXmlAttr->GetValue(szTxt, MAX_NAME_LEN);

					if (CUtil::StringICompare(szTxt, XML_INSPECTATTR_VALUE_STORBE_COXIAL))
						stSize.m_pstStepStrobe[idxStrobe].m_eStrobeType = TYPE_STROBE_COXIAL;
					else if (CUtil::StringICompare(szTxt, XML_INSPECTATTR_VALUE_STORBE_RING))
						stSize.m_pstStepStrobe[idxStrobe].m_eStrobeType = TYPE_STROBE_RING;
					else if (CUtil::StringICompare(szTxt, XML_INSPECTATTR_VALUE_STORBE_BAR))
						stSize.m_pstStepStrobe[idxStrobe].m_eStrobeType = TYPE_STROBE_BAR;
				}

				// Strobe Brightness
				pXmlAttr = pStrobeNode->GetAttribute(XML_INSPECTATTR_STROBEBRIGHT);
				if (pXmlAttr)
				{
					int nValue = 0;
					pXmlAttr->GetValue(&nValue, sizeof(int));
					stSize.m_pstStepStrobe[idxStrobe].m_nStrobeBrightness = nValue;
				}
				idxStrobe++;
			}
		}
	}

	return TRUE;
}

BOOL CXml::LoadInspectionStepSizeCalibrate(INFO_CALIBRATION& stCalib, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_CALIBRATEPATHLIST))
		{
			const int nPathCount = pChildNode->GetNodeCount();
			for (int j = 0; j < nPathCount; j++)
			{
				CXmlNode* pPathNode = pChildNode->GetNode(j);
				const TCHAR* pPathTitle = pPathNode->GetTitle();
				if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pPathTitle, XML_INSPECT_CALIBRATEPATH))
				{
					CXmlAttribute* pXmlAttr = pPathNode->GetAttribute(XML_INSPECTATTR_IMAGEPATH);
					if (pXmlAttr)
					{
						TCHAR szTxt[MAX_FILE_PATH_LEN] = { 0, };
						pXmlAttr->GetValue(szTxt, MAX_FILE_PATH_LEN);
						CUtil::StringCopy(stCalib.m_pszFilePathList[j], szTxt);
					}
				}
			}
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_CALIBRATEPARAM))
		{
			CXmlAttribute* pXmlAttr = NULL;

			DWORD dwValue = 0;
			double fValue = 0;

			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_LISTCOUNT);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
				stCalib.m_nListCount = dwValue;
			}
			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_REFIDX);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
				stCalib.m_nIdxReference = dwValue;
			}
			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_ROW);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
				stCalib.m_iRow = dwValue;
			}
			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_COL);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
				stCalib.m_iCol = dwValue;
			}
			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_SPACING);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&fValue, sizeof(double));
				stCalib.m_dSpacing = (float)fValue;
				
			}
			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_UNI);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
				stCalib.m_iChessUnit = dwValue;
			}

			//
			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_CALIBRATE_METHOD);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
				stCalib.m_iMethod = dwValue;
			}
			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_CALIBRATE_IMAGEWIDTH);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
				stCalib.m_iImgWidth = dwValue;
			}
			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_CALIBRATE_IMAGEHEIGHT);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
				stCalib.m_iImgHeight = dwValue;
			}
			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_CALIBRATE_WIDTH);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&fValue, sizeof(double));
				stCalib.m_dWidth = fValue;
			}
			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_CALIBRATE_HEIGHT);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&fValue, sizeof(double));
				stCalib.m_dHeight = fValue;
			}
			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_CALIBRATE_PIXELUNIT);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
				stCalib.m_iPixelUnit = dwValue;
			}
		}
	}
	return TRUE;
}

BOOL CXml::LoadInspectionStepSizeGain(INFO_SIZE_GAIN& stGain, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	const TCHAR* pTitle = pXmlNode->GetTitle();
	if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_SIZEGAIN))
	{
		CXmlAttribute* pXmlAttr = NULL;

		DWORD dwValue = 0;
		double fValue = 0;

		pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_SIZEGAIN_D);
		if (pXmlAttr)
		{
			pXmlAttr->GetValue(&fValue, sizeof(double));
			stGain.m_stGainName.m_dd = fValue;
		}
		pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_SIZEGAIN_L);
		if (pXmlAttr)
		{
			pXmlAttr->GetValue(&fValue, sizeof(double));
			stGain.m_stGainName.m_dL = fValue;
		}
		pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_SIZEGAIN_W);
		if (pXmlAttr)
		{
			pXmlAttr->GetValue(&fValue, sizeof(double));
			stGain.m_stGainName.m_dW = fValue;
		}
		pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_SIZEGAIN_I1);
		if (pXmlAttr)
		{
			pXmlAttr->GetValue(&fValue, sizeof(double));
			stGain.m_stGainName.m_dI1 = fValue;
		}
		pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_SIZEGAIN_I2);
		if (pXmlAttr)
		{
			pXmlAttr->GetValue(&fValue, sizeof(double));
			stGain.m_stGainName.m_dI2 = fValue;
		}
		pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_SIZEGAIN_I3);
		if (pXmlAttr)
		{
			pXmlAttr->GetValue(&fValue, sizeof(double));
			stGain.m_stGainName.m_dI3 = fValue;
		}
		pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_SIZEGAIN_M1);
		if (pXmlAttr)
		{
			pXmlAttr->GetValue(&fValue, sizeof(double));
			stGain.m_stGainName.m_dM1 = fValue;
		}
		pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_SIZEGAIN_M2);
		if (pXmlAttr)
		{
			pXmlAttr->GetValue(&fValue, sizeof(double));
			stGain.m_stGainName.m_dM2 = fValue;
		}
		pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_SIZEGAIN_S1);
		if (pXmlAttr)
		{
			pXmlAttr->GetValue(&fValue, sizeof(double));
			stGain.m_stGainName.m_dS1 = fValue;
		}
		pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_SIZEGAIN_S2);
		if (pXmlAttr)
		{
			pXmlAttr->GetValue(&fValue, sizeof(double));
			stGain.m_stGainName.m_dS2 = fValue;
		}
		pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_SIZEGAIN_S3);
		if (pXmlAttr)
		{
			pXmlAttr->GetValue(&fValue, sizeof(double));
			stGain.m_stGainName.m_dS3 = fValue;
		}
		pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_SIZEGAIN_S4);
		if (pXmlAttr)
		{
			pXmlAttr->GetValue(&fValue, sizeof(double));
			stGain.m_stGainName.m_dS4 = fValue;
		}
		pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_SIZEGAIN_S5);
		if (pXmlAttr)
		{
			pXmlAttr->GetValue(&fValue, sizeof(double));
			stGain.m_stGainName.m_dS5 = fValue;
		}
		pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_SIZEGAIN_X1);
		if (pXmlAttr)
		{
			pXmlAttr->GetValue(&fValue, sizeof(double));
			stGain.m_stGainName.m_dX1 = fValue;
		}
		pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_SIZEGAIN_X2);
		if (pXmlAttr)
		{
			pXmlAttr->GetValue(&fValue, sizeof(double));
			stGain.m_stGainName.m_dX2 = fValue;
		}
		pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_SIZEGAIN_R1);
		if (pXmlAttr)
		{
			pXmlAttr->GetValue(&fValue, sizeof(double));
			stGain.m_stGainName.m_dR1 = fValue;
		}
		pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_SIZEGAIN_R2);
		if (pXmlAttr)
		{
			pXmlAttr->GetValue(&fValue, sizeof(double));
			stGain.m_stGainName.m_dR2 = fValue;
		}
		pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_SIZEGAIN_R3);
		if (pXmlAttr)
		{
			pXmlAttr->GetValue(&fValue, sizeof(double));
			stGain.m_stGainName.m_dR3 = fValue;
		}
		pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_SIZEGAIN_R4);
		if (pXmlAttr)
		{
			pXmlAttr->GetValue(&fValue, sizeof(double));
			stGain.m_stGainName.m_dR4 = fValue;
		}

		// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
		pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_SIZEGAIN_R5);
		if (pXmlAttr)
		{
			pXmlAttr->GetValue(&fValue, sizeof(double));
			stGain.m_stGainName.m_dR5 = fValue;
		}
		pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_SIZEGAIN_R6);
		if (pXmlAttr)
		{
			pXmlAttr->GetValue(&fValue, sizeof(double));
			stGain.m_stGainName.m_dR6 = fValue;
		}

		pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_SIZEGAIN_SS1);
		if (pXmlAttr)
		{
			pXmlAttr->GetValue(&fValue, sizeof(double));
			stGain.m_stGainName.m_dSS1 = fValue;
		}
		pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_SIZEGAIN_SS2);
		if (pXmlAttr)
		{
			pXmlAttr->GetValue(&fValue, sizeof(double));
			stGain.m_stGainName.m_dSS2 = fValue;
		}
		pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_SIZEGAIN_SS3);
		if (pXmlAttr)
		{
			pXmlAttr->GetValue(&fValue, sizeof(double));
			stGain.m_stGainName.m_dSS3 = fValue;
		}
	}
	return TRUE;
}

BOOL CXml::LoadInspectionStepSizeRoi(INFO_INSPECTION_SIZE& stSize, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;
	TCHAR szTxt[MAX_NAME_LEN] = { 0, };
	double fValue = 0;

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_SIZEROI))
		{
			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_WIDTH);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&fValue, sizeof(double));
				stSize.m_pstFindLineROI[i].m_fWidth = (float)fValue;
			}
			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_HEIGHT);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&fValue, sizeof(double));
				stSize.m_pstFindLineROI[i].m_fHeight = (float)fValue;
			}
			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_ANGLE);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&fValue, sizeof(double));
				stSize.m_pstFindLineROI[i].m_dAngle = fValue;
			}
			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_ANGLE_CRITERIA);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&fValue, sizeof(double));
				stSize.m_pstFindLineROI[i].m_dAngleCriteria = fValue;
			}

			const int nPtCount = pChildNode->GetNodeCount();
			for (int j = 0; j < nPtCount; j++)
			{
				CXmlNode* pPtNode = pChildNode->GetNode(j);
				const TCHAR* pPtTitle = pPtNode->GetTitle();
				if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pPtTitle, XML_INSPECT_SIZEPOINT))
				{
					double fx = 0;
					double fy = 0;

					pXmlAttr = pPtNode->GetAttribute(XML_INSPECTATTR_POINTTYPE);
					if (pXmlAttr)
						pXmlAttr->GetValue(szTxt, MAX_NAME_LEN);
					pXmlAttr = pPtNode->GetAttribute(XML_INSPECTATTR_POINTX);
					if (pXmlAttr)
						pXmlAttr->GetValue(&fx, sizeof(double));
					pXmlAttr = pPtNode->GetAttribute(XML_INSPECTATTR_POINTY);
					if (pXmlAttr)
						pXmlAttr->GetValue(&fy, sizeof(double));

					stSize.m_pstFindLineROI[i].m_eTrackerType = TYPE_TRACKER_RECT_ROTATE;

					if (CUtil::StringICompare(szTxt, XML_INSPECTATTR_VALUE_POINT_CRITERIA))
					{
						stSize.m_pstFindLineROI[i].m_ptCriteria.m_fX = (float)fx;
						stSize.m_pstFindLineROI[i].m_ptCriteria.m_fY = (float)fy;
					}
					else if (CUtil::StringICompare(szTxt, XML_INSPECTATTR_VALUE_POINT_CENTER))
					{
						stSize.m_pstFindLineROI[i].m_stCenterPt.m_fX = (float)fx;
						stSize.m_pstFindLineROI[i].m_stCenterPt.m_fY = (float)fy;
					}
				}
			}
		}
	}

	return TRUE;
}

BOOL CXml::LoadInspectionStepSizeSample(INFO_INSPECTION_SIZE& stSize, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;
	TCHAR szTxt[MAX_NAME_LEN] = { 0, };

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_SIZEPARAM))
		{
			DWORD dwValue = 0;

			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_SAMPLEDIRECTION);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
				stSize.m_pstFindLineParameter[i].m_iDirection = (int)dwValue;
			}
			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_SAMPLEPOLAR);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
				stSize.m_pstFindLineParameter[i].m_iPolarity = (int)dwValue;
			}
			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_SAMPLELOOKFOR);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
				stSize.m_pstFindLineParameter[i].m_iLookFor = (int)dwValue;
			}
			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_SAMPLESTRTHRESHOLD);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
				stSize.m_pstFindLineParameter[i].m_iStrengthThreshold = (int)dwValue;
			}
			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_SAMPLESAMPLING);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
				stSize.m_pstFindLineParameter[i].m_iSampling = (int)dwValue;
			}
			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_SAMPLEKERNELSIZE);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
				stSize.m_pstFindLineParameter[i].m_iKernelSize = (int)dwValue;
			}
			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_SAMPLESEARCHANGLE);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
				stSize.m_pstFindLineParameter[i].m_bSearchAngle = (bool)dwValue;
			}
			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_SAMPLEMINANGLE);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
				stSize.m_pstFindLineParameter[i].m_iMinAngle = (int)dwValue;
			}

			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_SAMPLEMAXANGLE);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
				stSize.m_pstFindLineParameter[i].m_iMaxAngle = (int)dwValue;
			}
			pXmlAttr = pChildNode->GetAttribute(XML_INSPECTATTR_SAMPLEDISTTHRESHOLD);
			if (pXmlAttr)
			{
				pXmlAttr->GetValue(&dwValue, sizeof(DWORD));
				stSize.m_pstFindLineParameter[i].m_iDistanceThreshold = (int)dwValue;
			}
		}
	}

	return TRUE;
}


BOOL CXml::LoadInspectionStepStain(INFO_INSPECTION_STAIN& stStain, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	TCHAR szTxt[MAX_NAME_LEN] = { 0, };

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_RECTROI))
		{
			stStain.m_stRoi.m_eTrackerType = TYPE_TRACKER_RECT;
			LoadStepRectRoi(stStain.m_stRoi, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_PARAM_MARS))
		{
			LoadStepMarsParam(stStain.m_stParaStain, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_PARAM_CALIB))
		{
			LoadStepCalibParam(stStain.m_stConstStain, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_PARAM_JUDGMENT))
		{
			LoadStepJudgmentsParam(stStain.m_stStainStandard, pChildNode);
		}
		// Version 1.3.8.1 Image Save & Compress
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_PARAM_IMAGE))
		{
			LoadStepImageParam(stStain.m_stParaStainImage, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_STEPSTROBELIST))
		{
			int idxStrobe = 0;

			const int nStrobeCount = pChildNode->GetNodeCount();
			for (int s = 0; s < nStrobeCount; s++)
			{
				CXmlNode* pStrobeNode = pChildNode->GetNode(s);
				if (NULL == pStrobeNode || idxStrobe >= MAX_STEPSTROBE_LIST)
					continue;

				stStain.m_pstStepStrobe[idxStrobe].m_eStrobeType = TYPE_STROBE_OFF;
				stStain.m_pstStepStrobe[idxStrobe].m_nStrobeBrightness = 0;

				// Strobe Type
				CXmlAttribute* pXmlAttr = pStrobeNode->GetAttribute(XML_INSPECTATTR_STROBETYPE);
				if (pXmlAttr)
				{
					pXmlAttr->GetValue(szTxt, MAX_NAME_LEN);

					if (CUtil::StringICompare(szTxt, XML_INSPECTATTR_VALUE_STORBE_COXIAL))
						stStain.m_pstStepStrobe[idxStrobe].m_eStrobeType = TYPE_STROBE_COXIAL;
					else if (CUtil::StringICompare(szTxt, XML_INSPECTATTR_VALUE_STORBE_RING))
						stStain.m_pstStepStrobe[idxStrobe].m_eStrobeType = TYPE_STROBE_RING;
					else if (CUtil::StringICompare(szTxt, XML_INSPECTATTR_VALUE_STORBE_BAR))
						stStain.m_pstStepStrobe[idxStrobe].m_eStrobeType = TYPE_STROBE_BAR;
				}

				// Strobe Brightness
				pXmlAttr = pStrobeNode->GetAttribute(XML_INSPECTATTR_STROBEBRIGHT);
				if (pXmlAttr)
				{
					int nValue = 0;
					pXmlAttr->GetValue(&nValue, sizeof(int));
					stStain.m_pstStepStrobe[idxStrobe].m_nStrobeBrightness = nValue;
				}
				idxStrobe++;
			}
		}
	}

	return TRUE;
}

BOOL CXml::LoadInspectionStepDiffer(INFO_INSPECTION_DIFFER& stDiffeer, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	TCHAR szTxt[MAX_NAME_LEN] = { 0, };

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_RECTROI))
		{
			stDiffeer.m_stRoi.m_eTrackerType = TYPE_TRACKER_RECT;
			LoadStepRectRoi(stDiffeer.m_stRoi, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_PARAM_MARS))
		{
			LoadStepMarsParam(stDiffeer.m_stParaDiffer, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_PARAM_CALIB))
		{
			LoadStepCalibParam(stDiffeer.m_stConstDiffer, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_PARAM_JUDGMENT))
		{
			LoadStepJudgmentsParam(stDiffeer.m_stDifferStandard, pChildNode);
		}
		// Version 1.3.8.1 Image Save & Compress
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_PARAM_IMAGE))
		{
			LoadStepImageParam(stDiffeer.m_stParaDifferImage, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_STEPSTROBELIST))
		{
			int idxStrobe = 0;

			const int nStrobeCount = pChildNode->GetNodeCount();
			for (int s = 0; s < nStrobeCount; s++)
			{
				CXmlNode* pStrobeNode = pChildNode->GetNode(s);
				if (NULL == pStrobeNode || idxStrobe >= MAX_STEPSTROBE_LIST)
					continue;

				stDiffeer.m_pstStepStrobe[idxStrobe].m_eStrobeType = TYPE_STROBE_OFF;
				stDiffeer.m_pstStepStrobe[idxStrobe].m_nStrobeBrightness = 0;

				// Strobe Type
				CXmlAttribute* pXmlAttr = pStrobeNode->GetAttribute(XML_INSPECTATTR_STROBETYPE);
				if (pXmlAttr)
				{
					pXmlAttr->GetValue(szTxt, MAX_NAME_LEN);

					if (CUtil::StringICompare(szTxt, XML_INSPECTATTR_VALUE_STORBE_COXIAL))
						stDiffeer.m_pstStepStrobe[idxStrobe].m_eStrobeType = TYPE_STROBE_COXIAL;
					else if (CUtil::StringICompare(szTxt, XML_INSPECTATTR_VALUE_STORBE_RING))
						stDiffeer.m_pstStepStrobe[idxStrobe].m_eStrobeType = TYPE_STROBE_RING;
					else if (CUtil::StringICompare(szTxt, XML_INSPECTATTR_VALUE_STORBE_BAR))
						stDiffeer.m_pstStepStrobe[idxStrobe].m_eStrobeType = TYPE_STROBE_BAR;
				}

				// Strobe Brightness
				pXmlAttr = pStrobeNode->GetAttribute(XML_INSPECTATTR_STROBEBRIGHT);
				if (pXmlAttr)
				{
					int nValue = 0;
					pXmlAttr->GetValue(&nValue, sizeof(int));
					stDiffeer.m_pstStepStrobe[idxStrobe].m_nStrobeBrightness = nValue;
				}
				idxStrobe++;
			}
		}
	}

	return TRUE;
}

BOOL CXml::LoadInspectionStepBubble(INFO_INSPECTION_BUBBLE& stBubble, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	TCHAR szTxt[MAX_NAME_LEN] = { 0, };

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_RECTROI))
		{
			stBubble.m_stRoi.m_eTrackerType = TYPE_TRACKER_RECT;
			LoadStepRectRoi(stBubble.m_stRoi, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_PARAM_MARS))
		{
			LoadStepMarsParam(stBubble.m_stParaBubble, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_PARAM_CALIB))
		{
			LoadStepCalibParam(stBubble.m_stConstBubble, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_PARAM_JUDGMENT))
		{
			LoadStepJudgmentsParam(stBubble.m_stBubbleStandard, pChildNode);
		}
		// Version 1.3.8.1 Image Save & Compress
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_PARAM_IMAGE))
		{
			LoadStepImageParam(stBubble.m_stParaBubbleImage, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_STEPSTROBELIST))
		{
			int idxStrobe = 0;

			const int nStrobeCount = pChildNode->GetNodeCount();
			for (int s = 0; s < nStrobeCount; s++)
			{
				CXmlNode* pStrobeNode = pChildNode->GetNode(s);
				if (NULL == pStrobeNode || idxStrobe >= MAX_STEPSTROBE_LIST)
					continue;

				stBubble.m_pstStepStrobe[idxStrobe].m_eStrobeType = TYPE_STROBE_OFF;
				stBubble.m_pstStepStrobe[idxStrobe].m_nStrobeBrightness = 0;

				// Strobe Type
				CXmlAttribute* pXmlAttr = pStrobeNode->GetAttribute(XML_INSPECTATTR_STROBETYPE);
				if (pXmlAttr)
				{
					pXmlAttr->GetValue(szTxt, MAX_NAME_LEN);

					if (CUtil::StringICompare(szTxt, XML_INSPECTATTR_VALUE_STORBE_COXIAL))
						stBubble.m_pstStepStrobe[idxStrobe].m_eStrobeType = TYPE_STROBE_COXIAL;
					else if (CUtil::StringICompare(szTxt, XML_INSPECTATTR_VALUE_STORBE_RING))
						stBubble.m_pstStepStrobe[idxStrobe].m_eStrobeType = TYPE_STROBE_RING;
					else if (CUtil::StringICompare(szTxt, XML_INSPECTATTR_VALUE_STORBE_BAR))
						stBubble.m_pstStepStrobe[idxStrobe].m_eStrobeType = TYPE_STROBE_BAR;
				}

				// Strobe Brightness
				pXmlAttr = pStrobeNode->GetAttribute(XML_INSPECTATTR_STROBEBRIGHT);
				if (pXmlAttr)
				{
					int nValue = 0;
					pXmlAttr->GetValue(&nValue, sizeof(int));
					stBubble.m_pstStepStrobe[idxStrobe].m_nStrobeBrightness = nValue;
				}
				idxStrobe++;
			}
		}
	}

	return TRUE;
}

BOOL CXml::LoadInspectionStepScratch(INFO_INSPECTION_SCRATCH& stScratch, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	TCHAR szTxt[MAX_NAME_LEN] = { 0, };

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_RECTROI))
		{
			stScratch.m_stRoi.m_eTrackerType = TYPE_TRACKER_RECT;
			LoadStepRectRoi(stScratch.m_stRoi, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_PARAM_MARS))
		{
			LoadStepMarsParam(stScratch.m_stParaScratch, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_PARAM_CALIB))
		{
			LoadStepCalibParam(stScratch.m_stConstScratch, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_PARAM_JUDGMENT))
		{
			LoadStepJudgmentsParam(stScratch.m_stScratchStandard, pChildNode);
		}
		// Version 1.3.8.1 Image Save & Compress
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_PARAM_IMAGE))
		{
			LoadStepImageParam(stScratch.m_stParaScratchImage, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_STEPSTROBELIST))
		{
			int idxStrobe = 0;

			const int nStrobeCount = pChildNode->GetNodeCount();
			for (int s = 0; s < nStrobeCount; s++)
			{
				CXmlNode* pStrobeNode = pChildNode->GetNode(s);
				if (NULL == pStrobeNode || idxStrobe >= MAX_STEPSTROBE_LIST)
					continue;

				stScratch.m_pstStepStrobe[idxStrobe].m_eStrobeType = TYPE_STROBE_OFF;
				stScratch.m_pstStepStrobe[idxStrobe].m_nStrobeBrightness = 0;

				// Strobe Type
				CXmlAttribute* pXmlAttr = pStrobeNode->GetAttribute(XML_INSPECTATTR_STROBETYPE);
				if (pXmlAttr)
				{
					pXmlAttr->GetValue(szTxt, MAX_NAME_LEN);

					if (CUtil::StringICompare(szTxt, XML_INSPECTATTR_VALUE_STORBE_COXIAL))
						stScratch.m_pstStepStrobe[idxStrobe].m_eStrobeType = TYPE_STROBE_COXIAL;
					else if (CUtil::StringICompare(szTxt, XML_INSPECTATTR_VALUE_STORBE_RING))
						stScratch.m_pstStepStrobe[idxStrobe].m_eStrobeType = TYPE_STROBE_RING;
					else if (CUtil::StringICompare(szTxt, XML_INSPECTATTR_VALUE_STORBE_BAR))
						stScratch.m_pstStepStrobe[idxStrobe].m_eStrobeType = TYPE_STROBE_BAR;
				}

				// Strobe Brightness
				pXmlAttr = pStrobeNode->GetAttribute(XML_INSPECTATTR_STROBEBRIGHT);
				if (pXmlAttr)
				{
					int nValue = 0;
					pXmlAttr->GetValue(&nValue, sizeof(int));
					stScratch.m_pstStepStrobe[idxStrobe].m_nStrobeBrightness = nValue;
				}
				idxStrobe++;
			}
		}
	}

	return TRUE;
}

BOOL CXml::LoadInspectionStepStamp(INFO_INSPECTION_STAMP& stStamp, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	TCHAR szTxt[MAX_NAME_LEN] = { 0, };

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_RECTROI))
		{
			stStamp.m_stRoi.m_eTrackerType = TYPE_TRACKER_RECT;
			LoadStepRectRoi(stStamp.m_stRoi, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_PARAM_MARS))
		{
			LoadStepMarsParam(stStamp.m_stParaStamp, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_PARAM_CALIB))
		{
			LoadStepCalibParam(stStamp.m_stConstStamp, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_PARAM_JUDGMENT))
		{
			LoadStepJudgmentsParam(stStamp.m_stStampStandard, pChildNode);
		}
		// Version 1.3.8.1 Image Save & Compress
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_PARAM_IMAGE))
		{
			LoadStepImageParam(stStamp.m_stParaStampImage, pChildNode);
		}
		else if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_STEPSTROBELIST))
		{
			int idxStrobe = 0;

			const int nStrobeCount = pChildNode->GetNodeCount();
			for (int s = 0; s < nStrobeCount; s++)
			{
				CXmlNode* pStrobeNode = pChildNode->GetNode(s);
				if (NULL == pStrobeNode || idxStrobe >= MAX_STEPSTROBE_LIST)
					continue;

				stStamp.m_pstStepStrobe[idxStrobe].m_eStrobeType = TYPE_STROBE_OFF;
				stStamp.m_pstStepStrobe[idxStrobe].m_nStrobeBrightness = 0;

				// Strobe Type
				CXmlAttribute* pXmlAttr = pStrobeNode->GetAttribute(XML_INSPECTATTR_STROBETYPE);
				if (pXmlAttr)
				{
					pXmlAttr->GetValue(szTxt, MAX_NAME_LEN);

					if (CUtil::StringICompare(szTxt, XML_INSPECTATTR_VALUE_STORBE_COXIAL))
						stStamp.m_pstStepStrobe[idxStrobe].m_eStrobeType = TYPE_STROBE_COXIAL;
					else if (CUtil::StringICompare(szTxt, XML_INSPECTATTR_VALUE_STORBE_RING))
						stStamp.m_pstStepStrobe[idxStrobe].m_eStrobeType = TYPE_STROBE_RING;
					else if (CUtil::StringICompare(szTxt, XML_INSPECTATTR_VALUE_STORBE_BAR))
						stStamp.m_pstStepStrobe[idxStrobe].m_eStrobeType = TYPE_STROBE_BAR;
				}

				// Strobe Brightness
				pXmlAttr = pStrobeNode->GetAttribute(XML_INSPECTATTR_STROBEBRIGHT);
				if (pXmlAttr)
				{
					int nValue = 0;
					pXmlAttr->GetValue(&nValue, sizeof(int));
					stStamp.m_pstStepStrobe[idxStrobe].m_nStrobeBrightness = nValue;
				}
				idxStrobe++;
			}
		}
	}

	return TRUE;
}


BOOL CXml::LoadInspectionCalc(INFO_INSPECTION_SIZE_CALC& stCalc, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	TCHAR szTxt[MAX_NAME_LEN] = { 0, };

	const int nCount = pXmlNode->GetNodeCount();
	for (int i = 0; i < nCount; i++)
	{
		CXmlNode* pChildNode = pXmlNode->GetNode(i);
		if (NULL == pChildNode)
			continue;

		const TCHAR* pTitle = pChildNode->GetTitle();
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_SIZECALIBRATE))
		{
			LoadInspectionStepSizeCalibrate(stCalc.m_stCalibration, pChildNode);
		}
		if (CUtil::StringCompare((LPTSTR)(LPCTSTR)pTitle, XML_INSPECT_SIZEGAIN))
		{
			LoadInspectionStepSizeGain(stCalc.m_stSizeGain, pChildNode);
		}
	}

	return TRUE;
}

BOOL CXml::LoadStepRectRoi(INFO_RECT_ROI& stRectRoi, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;
	int nValue = 0;

	pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_RECT_LEFT);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&nValue, sizeof(int));
		stRectRoi.m_rtRoi.left = nValue;
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_RECT_TOP);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&nValue, sizeof(int));
		stRectRoi.m_rtRoi.top = nValue;
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_RECT_RIGHT);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&nValue, sizeof(int));
		stRectRoi.m_rtRoi.right = nValue;
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_RECT_BOTTOM);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&nValue, sizeof(int));
		stRectRoi.m_rtRoi.bottom = nValue;
	}

	return TRUE;
}


BOOL CXml::LoadStepMarsParam(INFO_MARS_PARA& stMarsParam, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;
	double fValue = 0.0f;

	pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_MARSPARAM_PROBTHRES);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&fValue, sizeof(double));
		stMarsParam.prob_thres = (float)fValue;
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_MARSPARAM_BLOBSIZETHRES);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&fValue, sizeof(double));
		stMarsParam.blobSize_thres = (float)fValue;
	}

	return TRUE;
}

BOOL CXml::LoadStepCalibParam(INFO_CALIB_PARA& stCalibParam, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;
	double fValue = 0.0f;

	pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_CALIBPARAM_PIXEL2REAL);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&fValue, sizeof(double));
		stCalibParam.const_pixel2real = (float)fValue;
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_CALIBPARAM_REAL2PIXEL);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&fValue, sizeof(double));
		stCalibParam.const_real2pixel = (float)fValue;
	}

	return TRUE;
}

BOOL CXml::LoadStepJudgmentsParam(INFO_JUDGMENT_PARA& stJudgParam, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;
	int nValue = 0;
	double fValue = 0.0f;

	pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_JUDGPARAM_FAULTNUM);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&nValue, sizeof(int));
		stJudgParam.faultNum = nValue;
	}

	pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_JUDGBPARAM_FAULTSIZE);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&fValue, sizeof(double));
		stJudgParam.faultSize = (float)fValue;
	}

	return TRUE;
}

// Version 1.3.8.1
BOOL CXml::LoadStepImageParam(INFO_IMAGE_PARA& stImageParam, CXmlNode* pXmlNode)
{
	if (NULL == pXmlNode)
		return FALSE;

	CXmlAttribute* pXmlAttr = NULL;
	int nValue = 0;
	double fValue = 0.0f;

	pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_IMAGEPARAM_WRITE);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&nValue, sizeof(int));
		if (nValue == 0)	stImageParam.imageWrite = FALSE;
		else				stImageParam.imageWrite = TRUE;
	}

	nValue = 0;
	pXmlAttr = pXmlNode->GetAttribute(XML_INSPECTATTR_IMAGEPARAM_COMPRESS);
	if (pXmlAttr)
	{
		pXmlAttr->GetValue(&nValue, sizeof(int));
		if (nValue == 0)	stImageParam.imageCompress = FALSE;
		else				stImageParam.imageCompress = TRUE;
	}

	return TRUE;
}



CXmlNode* CXml::SaveInspection(const INFO_INSPECTION& stInspection, TYPE_CAMERAPOS ePos)
{
	CXmlNode* pXmlNode = new CXmlNode(XML_OPTION_ROOT, NULL);

	CXmlNode* pNodeCam = SaveInspectionCam(stInspection.m_nCameraNum, ePos);
	if (pNodeCam)
	{
		pXmlNode->AddNode(pNodeCam);
		delete pNodeCam;		pNodeCam = NULL;
	}

	CXmlNode* pNodeSize = SaveInspectionSize(stInspection.m_stSize);
	if (pNodeSize)
	{
		pXmlNode->AddNode(pNodeSize);
		delete pNodeSize;		pNodeSize = NULL;
	}

	CXmlNode* pNodeStain = SaveInspectionStain(stInspection.m_stStain);
	if (pNodeStain)
	{
		pXmlNode->AddNode(pNodeStain);
		delete pNodeStain;		pNodeStain = NULL;
	}

	CXmlNode* pNodeDiffer = SaveInspectionDiffer(stInspection.m_stDiffer);
	if (pNodeDiffer)
	{
		pXmlNode->AddNode(pNodeDiffer);
		delete pNodeDiffer;		pNodeDiffer = NULL;
	}

	CXmlNode* pNodeBubble = SaveInspectionBubble(stInspection.m_stBubble);
	if (pNodeBubble)
	{
		pXmlNode->AddNode(pNodeBubble);
		delete pNodeBubble;		pNodeBubble = NULL;
	}

	CXmlNode* pNodeScratch = SaveInspectionScratch(stInspection.m_stScratch);
	if (pNodeScratch)
	{
		pXmlNode->AddNode(pNodeScratch);
		delete pNodeScratch;	pNodeScratch = NULL;
	}

	CXmlNode* pNodeStamp = SaveInspectionStamp(stInspection.m_stStamp);
	if (pNodeStamp)
	{
		pXmlNode->AddNode(pNodeStamp);
		delete pNodeStamp;		pNodeStamp = NULL;
	}

	CXmlNode* pNodeSizeSecond = SaveInspectionSizeSecond(stInspection.m_stSizeSecond);
	if (pNodeSizeSecond)
	{
		pXmlNode->AddNode(pNodeSizeSecond);
		delete pNodeSizeSecond;		pNodeSizeSecond = NULL;
	}

	CXmlNode* pNodeCalc = SaveInspectionCalc(stInspection.m_stSizeCalc);
	if (pNodeCalc)
	{
		pXmlNode->AddNode(pNodeCalc);
		delete pNodeCalc;		pNodeCalc = NULL;
	}

	return pXmlNode;
}


CXmlNode* CXml::SaveInspectionCam(const int& nCameranum, TYPE_CAMERAPOS ePos)
{
	CXmlNode* pXmlNode = new CXmlNode(XML_INSPECT_CAMERACHECK, NULL);

	if (TYPE_CAMERAPOS_FIRST == ePos)
		AddAttributeInt(pXmlNode, XML_INSPECTATTR_CAMERANUM, TYPE_CAMERAPOS_FIRST);
	else if (TYPE_CAMERAPOS_SECOND == ePos)
		AddAttributeInt(pXmlNode, XML_INSPECTATTR_CAMERANUM, TYPE_CAMERAPOS_SECOND);
	else
		AddAttributeInt(pXmlNode, XML_INSPECTATTR_CAMERANUM, TYPE_CAMERAPOS_NONE);

	return pXmlNode;
}

CXmlNode* CXml::SaveInspectionSize(const INFO_INSPECTION_SIZE& stSize)
{
	

	CXmlNode* pXmlNode = new CXmlNode(XML_INSPECT_STEPSIZE, NULL);

	// Strobe List
	CXmlNode* pStrobeListNode = new CXmlNode(XML_INSPECT_STEPSTROBELIST, NULL);
	{
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			CXmlNode* pNode = new CXmlNode(XML_INSPECT_STEPSTROBE, NULL);

			// Strobe Type
			if (TYPE_STROBE_COXIAL == stSize.m_pstStepStrobe[i].m_eStrobeType)
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_COXIAL);
			else if (TYPE_STROBE_RING == stSize.m_pstStepStrobe[i].m_eStrobeType)
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_RING);
			else if (TYPE_STROBE_BAR == stSize.m_pstStepStrobe[i].m_eStrobeType)
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_BAR);
			else
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_OFF);

			// Strobe Brightness
			AddAttributeInt(pNode, XML_INSPECTATTR_STROBEBRIGHT, stSize.m_pstStepStrobe[i].m_nStrobeBrightness);

			pStrobeListNode->AddNode(pNode);	delete pNode;
		}
	}
	pXmlNode->AddNode(pStrobeListNode);	delete pStrobeListNode;

	// Calibrate
	{
		CXmlNode* pNode = new CXmlNode(XML_INSPECT_SIZECALIBRATE, NULL);
		{
			// param
			CXmlNode* pNodeParam = new CXmlNode(XML_INSPECT_CALIBRATEPARAM, NULL);
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_LISTCOUNT, stSize.m_stCalibration.m_nListCount);
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_REFIDX, stSize.m_stCalibration.m_nIdxReference);
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_ROW, stSize.m_stCalibration.m_iRow);
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_COL, stSize.m_stCalibration.m_iCol);
			AddAttributeDouble(pNodeParam, XML_INSPECTATTR_SPACING, stSize.m_stCalibration.m_dSpacing);
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_UNI, stSize.m_stCalibration.m_iChessUnit);
			//
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_CALIBRATE_METHOD, stSize.m_stCalibration.m_iMethod);
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_CALIBRATE_IMAGEWIDTH, stSize.m_stCalibration.m_iImgWidth);
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_CALIBRATE_IMAGEHEIGHT, stSize.m_stCalibration.m_iImgHeight);
			AddAttributeDouble(pNodeParam, XML_INSPECTATTR_CALIBRATE_WIDTH, stSize.m_stCalibration.m_dWidth);
			AddAttributeDouble(pNodeParam, XML_INSPECTATTR_CALIBRATE_HEIGHT, stSize.m_stCalibration.m_dHeight);
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_CALIBRATE_PIXELUNIT, stSize.m_stCalibration.m_iPixelUnit);

			pNode->AddNode(pNodeParam);	delete pNodeParam;

			// path
			CXmlNode* pNodeList = new CXmlNode(XML_INSPECT_CALIBRATEPATHLIST, NULL);
			for (int i = 0; i < stSize.m_stCalibration.m_nListCount; i++)
			{
				CXmlNode* pNodePath = new CXmlNode(XML_INSPECT_CALIBRATEPATH, NULL);
				AddAttributeString(pNodePath, XML_INSPECTATTR_IMAGEPATH, stSize.m_stCalibration.m_pszFilePathList[i]);
				pNodeList->AddNode(pNodePath);	delete pNodePath;
			}
			pNode->AddNode(pNodeList);	delete pNodeList;
		}
		pXmlNode->AddNode(pNode);	delete pNode;
	}

	// Gain
	{
		CXmlNode* pNode = new CXmlNode(XML_INSPECT_SIZEGAIN, NULL);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_D, stSize.m_stSizeGain.m_stGainName.m_dd);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_L, stSize.m_stSizeGain.m_stGainName.m_dL);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_W, stSize.m_stSizeGain.m_stGainName.m_dW);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_I1, stSize.m_stSizeGain.m_stGainName.m_dI1);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_I2, stSize.m_stSizeGain.m_stGainName.m_dI2);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_I3, stSize.m_stSizeGain.m_stGainName.m_dI3);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_M1, stSize.m_stSizeGain.m_stGainName.m_dM1);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_M2, stSize.m_stSizeGain.m_stGainName.m_dM2);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_S1, stSize.m_stSizeGain.m_stGainName.m_dS1);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_S2, stSize.m_stSizeGain.m_stGainName.m_dS2);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_S3, stSize.m_stSizeGain.m_stGainName.m_dS3);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_S4, stSize.m_stSizeGain.m_stGainName.m_dS4);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_S5, stSize.m_stSizeGain.m_stGainName.m_dS5);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_X1, stSize.m_stSizeGain.m_stGainName.m_dX1);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_X2, stSize.m_stSizeGain.m_stGainName.m_dX2);
		// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R1, stSize.m_stSizeGain.m_stGainName.m_dR1);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R2, stSize.m_stSizeGain.m_stGainName.m_dR2);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R3, stSize.m_stSizeGain.m_stGainName.m_dR3);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R4, stSize.m_stSizeGain.m_stGainName.m_dR4);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R5, stSize.m_stSizeGain.m_stGainName.m_dR5);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R6, stSize.m_stSizeGain.m_stGainName.m_dR6);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_SS1, stSize.m_stSizeGain.m_stGainName.m_dSS1);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_SS2, stSize.m_stSizeGain.m_stGainName.m_dSS2);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_SS3, stSize.m_stSizeGain.m_stGainName.m_dSS3);

		pXmlNode->AddNode(pNode);	delete pNode;
	}

	// Roi
	{
		CXmlNode* pNode = new CXmlNode(XML_INSPECT_SIZEROILIST, NULL);
		{
			for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
			{
				CXmlNode* pNodeRoi = new CXmlNode(XML_INSPECT_SIZEROI, NULL);
				AddAttributeDouble(pNodeRoi, XML_INSPECTATTR_WIDTH, stSize.m_pstFindLineROI[i].m_fWidth);
				AddAttributeDouble(pNodeRoi, XML_INSPECTATTR_HEIGHT, stSize.m_pstFindLineROI[i].m_fHeight);
				AddAttributeDouble(pNodeRoi, XML_INSPECTATTR_ANGLE, stSize.m_pstFindLineROI[i].m_dAngle);
				AddAttributeDouble(pNodeRoi, XML_INSPECTATTR_ANGLE_CRITERIA, stSize.m_pstFindLineROI[i].m_dAngleCriteria);


				CXmlNode* pNodePoint = new CXmlNode(XML_INSPECT_SIZEPOINT, NULL);
				AddAttributeString(pNodePoint, XML_INSPECTATTR_POINTTYPE, XML_INSPECTATTR_VALUE_POINT_CENTER);
				AddAttributeDouble(pNodePoint, XML_INSPECTATTR_POINTX, stSize.m_pstFindLineROI[i].m_stCenterPt.m_fX);
				AddAttributeDouble(pNodePoint, XML_INSPECTATTR_POINTY, stSize.m_pstFindLineROI[i].m_stCenterPt.m_fY);
				pNodeRoi->AddNode(pNodePoint);	delete pNodePoint;

				pNodePoint = new CXmlNode(XML_INSPECT_SIZEPOINT, NULL);
				AddAttributeString(pNodePoint, XML_INSPECTATTR_POINTTYPE, XML_INSPECTATTR_VALUE_POINT_CRITERIA);
				AddAttributeDouble(pNodePoint, XML_INSPECTATTR_POINTX, stSize.m_pstFindLineROI[i].m_ptCriteria.m_fX);
				AddAttributeDouble(pNodePoint, XML_INSPECTATTR_POINTY, stSize.m_pstFindLineROI[i].m_ptCriteria.m_fY);
				pNodeRoi->AddNode(pNodePoint);	delete pNodePoint;

				pNode->AddNode(pNodeRoi);	delete pNodeRoi;
			}
		}
		pXmlNode->AddNode(pNode);	delete pNode;
	}

	// A
	{
		CXmlNode* pNode = new CXmlNode(XML_INSPECT_SIZESAMPLE, NULL);
		{
			AddAttributeString(pNode, XML_INSPECTATTR_SAMPLETYPE, XML_INSPECTATTR_VALUE_SAMPLE_A);

			for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
			{
				CXmlNode* pNodeParam = new CXmlNode(XML_INSPECT_SIZEPARAM, NULL);

				AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_SAMPLEDIRECTION, stSize.m_pstFindLineParameter[i].m_iDirection);
				AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_SAMPLEPOLAR, stSize.m_pstFindLineParameter[i].m_iPolarity);
				AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_SAMPLELOOKFOR, stSize.m_pstFindLineParameter[i].m_iLookFor);
				AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_SAMPLESTRTHRESHOLD, stSize.m_pstFindLineParameter[i].m_iStrengthThreshold);
				AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_SAMPLESAMPLING, stSize.m_pstFindLineParameter[i].m_iSampling);
				AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_SAMPLEKERNELSIZE, stSize.m_pstFindLineParameter[i].m_iKernelSize);
				AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_SAMPLESEARCHANGLE, stSize.m_pstFindLineParameter[i].m_bSearchAngle);
				AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_SAMPLEMINANGLE, stSize.m_pstFindLineParameter[i].m_iMinAngle);
				AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_SAMPLEMAXANGLE, stSize.m_pstFindLineParameter[i].m_iMaxAngle);
				AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_SAMPLEDISTTHRESHOLD, stSize.m_pstFindLineParameter[i].m_iDistanceThreshold);
				
				pNode->AddNode(pNodeParam);	delete pNodeParam;
			}
		}
		pXmlNode->AddNode(pNode);	delete pNode;
	}

	return pXmlNode;
}

CXmlNode* CXml::SaveInspectionStain(const INFO_INSPECTION_STAIN& stStain)
{
	CXmlNode* pXmlNode = new CXmlNode(XML_INSPECT_STEPSTAIN, NULL);

	// Strobe List
	CXmlNode* pStrobeListNode = new CXmlNode(XML_INSPECT_STEPSTROBELIST, NULL);
	{
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			CXmlNode* pNode = new CXmlNode(XML_INSPECT_STEPSTROBE, NULL);

			// Strobe Type
			if (TYPE_STROBE_COXIAL == stStain.m_pstStepStrobe[i].m_eStrobeType)
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_COXIAL);
			else if (TYPE_STROBE_RING == stStain.m_pstStepStrobe[i].m_eStrobeType)
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_RING);
			else if (TYPE_STROBE_BAR == stStain.m_pstStepStrobe[i].m_eStrobeType)
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_BAR);
			else
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_OFF);

			// Strobe Brightness
			AddAttributeInt(pNode, XML_INSPECTATTR_STROBEBRIGHT, stStain.m_pstStepStrobe[i].m_nStrobeBrightness);

			pStrobeListNode->AddNode(pNode);	delete pNode;
		}
	}
	pXmlNode->AddNode(pStrobeListNode);	delete pStrobeListNode;

	// Roi
	CXmlNode* pRectNode = SaveStepRectRoi(stStain.m_stRoi);
	pXmlNode->AddNode(pRectNode);	delete pRectNode;

	// Mars Param 2
	CXmlNode* pMarsNode = SaveStepMarsParam(stStain.m_stParaStain);
	pXmlNode->AddNode(pMarsNode);	delete pMarsNode;

	// Calb Param
	CXmlNode* pCalibNode = SaveStepCalibParam(stStain.m_stConstStain);
	pXmlNode->AddNode(pCalibNode);	delete pCalibNode;

	// Judgment Param
	CXmlNode* pJudgNode = SaveStepJudgmentsParam(stStain.m_stStainStandard);
	pXmlNode->AddNode(pJudgNode);	delete pJudgNode;
	
	// Version 1.3.8.1 Image Save & Compress
	CXmlNode* pImageNode = SaveStepImageParam(stStain.m_stParaStainImage);
	pXmlNode->AddNode(pImageNode);	delete pImageNode;

	return pXmlNode;
}

CXmlNode* CXml::SaveInspectionDiffer(const INFO_INSPECTION_DIFFER& stDiffer)
{
	CXmlNode* pXmlNode = new CXmlNode(XML_INSPECT_STEPDIFFER, NULL);

	// Strobe List
	CXmlNode* pStrobeListNode = new CXmlNode(XML_INSPECT_STEPSTROBELIST, NULL);
	{
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			CXmlNode* pNode = new CXmlNode(XML_INSPECT_STEPSTROBE, NULL);

			// Strobe Type
			if (TYPE_STROBE_COXIAL == stDiffer.m_pstStepStrobe[i].m_eStrobeType)
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_COXIAL);
			else if (TYPE_STROBE_RING == stDiffer.m_pstStepStrobe[i].m_eStrobeType)
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_RING);
			else if (TYPE_STROBE_BAR == stDiffer.m_pstStepStrobe[i].m_eStrobeType)
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_BAR);
			else
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_OFF);

			// Strobe Brightness
			AddAttributeInt(pNode, XML_INSPECTATTR_STROBEBRIGHT, stDiffer.m_pstStepStrobe[i].m_nStrobeBrightness);

			pStrobeListNode->AddNode(pNode);	delete pNode;
		}
	}
	pXmlNode->AddNode(pStrobeListNode);	delete pStrobeListNode;

	// Roi
	CXmlNode* pRectNode = SaveStepRectRoi(stDiffer.m_stRoi);
	pXmlNode->AddNode(pRectNode);	delete pRectNode;

	// Mars Param 2
	CXmlNode* pMarsNode = SaveStepMarsParam(stDiffer.m_stParaDiffer);
	pXmlNode->AddNode(pMarsNode);	delete pMarsNode;

	// Calb Param
	CXmlNode* pCalibNode = SaveStepCalibParam(stDiffer.m_stConstDiffer);
	pXmlNode->AddNode(pCalibNode);	delete pCalibNode;

	// Judgment Param
	CXmlNode* pJudgNode = SaveStepJudgmentsParam(stDiffer.m_stDifferStandard);
	pXmlNode->AddNode(pJudgNode);	delete pJudgNode;

	// Version 1.3.8.1 Image Save & Compress
	CXmlNode* pImageNode = SaveStepImageParam(stDiffer.m_stParaDifferImage);
	pXmlNode->AddNode(pImageNode);	delete pImageNode;

	return pXmlNode;
}

CXmlNode* CXml::SaveInspectionBubble(const INFO_INSPECTION_BUBBLE& stBubble)
{
	CXmlNode* pXmlNode = new CXmlNode(XML_INSPECT_STEPBUBBLE, NULL);

	// Strobe List
	CXmlNode* pStrobeListNode = new CXmlNode(XML_INSPECT_STEPSTROBELIST, NULL);
	{
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			CXmlNode* pNode = new CXmlNode(XML_INSPECT_STEPSTROBE, NULL);

			// Strobe Type
			if (TYPE_STROBE_COXIAL == stBubble.m_pstStepStrobe[i].m_eStrobeType)
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_COXIAL);
			else if (TYPE_STROBE_RING == stBubble.m_pstStepStrobe[i].m_eStrobeType)
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_RING);
			else if (TYPE_STROBE_BAR == stBubble.m_pstStepStrobe[i].m_eStrobeType)
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_BAR);
			else
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_OFF);

			// Strobe Brightness
			AddAttributeInt(pNode, XML_INSPECTATTR_STROBEBRIGHT, stBubble.m_pstStepStrobe[i].m_nStrobeBrightness);

			pStrobeListNode->AddNode(pNode);	delete pNode;
		}
	}
	pXmlNode->AddNode(pStrobeListNode);	delete pStrobeListNode;

	// Roi
	CXmlNode* pRectNode = SaveStepRectRoi(stBubble.m_stRoi);
	pXmlNode->AddNode(pRectNode);	delete pRectNode;

	// Mars Param 2
	CXmlNode* pMarsNode = SaveStepMarsParam(stBubble.m_stParaBubble);
	pXmlNode->AddNode(pMarsNode);	delete pMarsNode;

	// Calb Param
	CXmlNode* pCalibNode = SaveStepCalibParam(stBubble.m_stConstBubble);
	pXmlNode->AddNode(pCalibNode);	delete pCalibNode;

	// Judgment Param
	CXmlNode* pJudgNode = SaveStepJudgmentsParam(stBubble.m_stBubbleStandard);
	pXmlNode->AddNode(pJudgNode);	delete pJudgNode;

	// Version 1.3.8.1 Image Save & Compress
	CXmlNode* pImageNode = SaveStepImageParam(stBubble.m_stParaBubbleImage);
	pXmlNode->AddNode(pImageNode);	delete pImageNode;

	return pXmlNode;
}

CXmlNode* CXml::SaveInspectionScratch(const INFO_INSPECTION_SCRATCH& stScratch)
{
	CXmlNode* pXmlNode = new CXmlNode(XML_INSPECT_STEPSCRATCH, NULL);

	// Strobe List
	CXmlNode* pStrobeListNode = new CXmlNode(XML_INSPECT_STEPSTROBELIST, NULL);
	{
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			CXmlNode* pNode = new CXmlNode(XML_INSPECT_STEPSTROBE, NULL);

			// Strobe Type
			if (TYPE_STROBE_COXIAL == stScratch.m_pstStepStrobe[i].m_eStrobeType)
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_COXIAL);
			else if (TYPE_STROBE_RING == stScratch.m_pstStepStrobe[i].m_eStrobeType)
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_RING);
			else if (TYPE_STROBE_BAR == stScratch.m_pstStepStrobe[i].m_eStrobeType)
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_BAR);
			else
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_OFF);

			// Strobe Brightness
			AddAttributeInt(pNode, XML_INSPECTATTR_STROBEBRIGHT, stScratch.m_pstStepStrobe[i].m_nStrobeBrightness);

			pStrobeListNode->AddNode(pNode);	delete pNode;
		}
	}
	pXmlNode->AddNode(pStrobeListNode);	delete pStrobeListNode;

	// Roi
	CXmlNode* pRectNode = SaveStepRectRoi(stScratch.m_stRoi);
	pXmlNode->AddNode(pRectNode);	delete pRectNode;

	// Mars Param 2
	CXmlNode* pMarsNode = SaveStepMarsParam(stScratch.m_stParaScratch);
	pXmlNode->AddNode(pMarsNode);	delete pMarsNode;

	// Calb Param
	CXmlNode* pCalibNode = SaveStepCalibParam(stScratch.m_stConstScratch);
	pXmlNode->AddNode(pCalibNode);	delete pCalibNode;

	// Judgment Param
	CXmlNode* pJudgNode = SaveStepJudgmentsParam(stScratch.m_stScratchStandard);
	pXmlNode->AddNode(pJudgNode);	delete pJudgNode;

	// Version 1.3.8.1 Image Save & Compress
	CXmlNode* pImageNode = SaveStepImageParam(stScratch.m_stParaScratchImage);
	pXmlNode->AddNode(pImageNode);	delete pImageNode;

	return pXmlNode;
}

CXmlNode* CXml::SaveInspectionStamp(const INFO_INSPECTION_STAMP& stStamp)
{
	CXmlNode* pXmlNode = new CXmlNode(XML_INSPECT_STEPSTAMP, NULL);

	// Strobe List
	CXmlNode* pStrobeListNode = new CXmlNode(XML_INSPECT_STEPSTROBELIST, NULL);
	{
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			CXmlNode* pNode = new CXmlNode(XML_INSPECT_STEPSTROBE, NULL);

			// Strobe Type
			if (TYPE_STROBE_COXIAL == stStamp.m_pstStepStrobe[i].m_eStrobeType)
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_COXIAL);
			else if (TYPE_STROBE_RING == stStamp.m_pstStepStrobe[i].m_eStrobeType)
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_RING);
			else if (TYPE_STROBE_BAR == stStamp.m_pstStepStrobe[i].m_eStrobeType)
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_BAR);
			else
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_OFF);

			// Strobe Brightness
			AddAttributeInt(pNode, XML_INSPECTATTR_STROBEBRIGHT, stStamp.m_pstStepStrobe[i].m_nStrobeBrightness);

			pStrobeListNode->AddNode(pNode);	delete pNode;
		}
	}
	pXmlNode->AddNode(pStrobeListNode);	delete pStrobeListNode;

	// Roi
	CXmlNode* pRectNode = SaveStepRectRoi(stStamp.m_stRoi);
	pXmlNode->AddNode(pRectNode);	delete pRectNode;

	// Mars Param 2
	CXmlNode* pMarsNode = SaveStepMarsParam(stStamp.m_stParaStamp);
	pXmlNode->AddNode(pMarsNode);	delete pMarsNode;

	// Calb Param
	CXmlNode* pCalibNode = SaveStepCalibParam(stStamp.m_stConstStamp);
	pXmlNode->AddNode(pCalibNode);	delete pCalibNode;

	// Judgment Param
	CXmlNode* pJudgNode = SaveStepJudgmentsParam(stStamp.m_stStampStandard);
	pXmlNode->AddNode(pJudgNode);	delete pJudgNode;

	// Version 1.3.8.1 Image Save & Compress
	CXmlNode* pImageNode = SaveStepImageParam(stStamp.m_stParaStampImage);
	pXmlNode->AddNode(pImageNode);	delete pImageNode;

	return pXmlNode;
}

CXmlNode* CXml::SaveInspectionSizeSecond(const INFO_INSPECTION_SIZE& stSize)
{
	CXmlNode* pXmlNode = new CXmlNode(XML_INSPECT_STEPSIZESECOND, NULL);

	// Strobe List
	CXmlNode* pStrobeListNode = new CXmlNode(XML_INSPECT_STEPSTROBELIST, NULL);
	{
		for (int i = 0; i < MAX_STEPSTROBE_LIST; i++)
		{
			CXmlNode* pNode = new CXmlNode(XML_INSPECT_STEPSTROBE, NULL);

			// Strobe Type
			if (TYPE_STROBE_COXIAL == stSize.m_pstStepStrobe[i].m_eStrobeType)
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_COXIAL);
			else if (TYPE_STROBE_RING == stSize.m_pstStepStrobe[i].m_eStrobeType)
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_RING);
			else if (TYPE_STROBE_BAR == stSize.m_pstStepStrobe[i].m_eStrobeType)
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_BAR);
			else
				AddAttributeString(pNode, XML_INSPECTATTR_STROBETYPE, XML_INSPECTATTR_VALUE_STORBE_OFF);

			// Strobe Brightness
			AddAttributeInt(pNode, XML_INSPECTATTR_STROBEBRIGHT, stSize.m_pstStepStrobe[i].m_nStrobeBrightness);

			pStrobeListNode->AddNode(pNode);	delete pNode;
		}
	}
	pXmlNode->AddNode(pStrobeListNode);	delete pStrobeListNode;

	// Calibrate
	{
		CXmlNode* pNode = new CXmlNode(XML_INSPECT_SIZECALIBRATE, NULL);
		{
			// param
			CXmlNode* pNodeParam = new CXmlNode(XML_INSPECT_CALIBRATEPARAM, NULL);
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_LISTCOUNT, stSize.m_stCalibration.m_nListCount);
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_REFIDX, stSize.m_stCalibration.m_nIdxReference);
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_ROW, stSize.m_stCalibration.m_iRow);
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_COL, stSize.m_stCalibration.m_iCol);
			AddAttributeDouble(pNodeParam, XML_INSPECTATTR_SPACING, stSize.m_stCalibration.m_dSpacing);
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_UNI, stSize.m_stCalibration.m_iChessUnit);
			//
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_CALIBRATE_METHOD, stSize.m_stCalibration.m_iMethod);
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_CALIBRATE_IMAGEWIDTH, stSize.m_stCalibration.m_iImgWidth);
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_CALIBRATE_IMAGEHEIGHT, stSize.m_stCalibration.m_iImgHeight);
			AddAttributeDouble(pNodeParam, XML_INSPECTATTR_CALIBRATE_WIDTH, stSize.m_stCalibration.m_dWidth);
			AddAttributeDouble(pNodeParam, XML_INSPECTATTR_CALIBRATE_HEIGHT, stSize.m_stCalibration.m_dHeight);
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_CALIBRATE_PIXELUNIT, stSize.m_stCalibration.m_iPixelUnit);

			pNode->AddNode(pNodeParam);	delete pNodeParam;

			// path
			CXmlNode* pNodeList = new CXmlNode(XML_INSPECT_CALIBRATEPATHLIST, NULL);
			for (int i = 0; i < stSize.m_stCalibration.m_nListCount; i++)
			{
				CXmlNode* pNodePath = new CXmlNode(XML_INSPECT_CALIBRATEPATH, NULL);
				AddAttributeString(pNodePath, XML_INSPECTATTR_IMAGEPATH, stSize.m_stCalibration.m_pszFilePathList[i]);
				pNodeList->AddNode(pNodePath);	delete pNodePath;
			}
			pNode->AddNode(pNodeList);	delete pNodeList;
		}
		pXmlNode->AddNode(pNode);	delete pNode;
	}

	// Gain
	{
		CXmlNode* pNode = new CXmlNode(XML_INSPECT_SIZEGAIN, NULL);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_D, stSize.m_stSizeGain.m_stGainName.m_dd);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_L, stSize.m_stSizeGain.m_stGainName.m_dL);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_W, stSize.m_stSizeGain.m_stGainName.m_dW);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_I1, stSize.m_stSizeGain.m_stGainName.m_dI1);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_I2, stSize.m_stSizeGain.m_stGainName.m_dI2);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_I3, stSize.m_stSizeGain.m_stGainName.m_dI3);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_M1, stSize.m_stSizeGain.m_stGainName.m_dM1);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_M2, stSize.m_stSizeGain.m_stGainName.m_dM2);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_S1, stSize.m_stSizeGain.m_stGainName.m_dS1);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_S2, stSize.m_stSizeGain.m_stGainName.m_dS2);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_S3, stSize.m_stSizeGain.m_stGainName.m_dS3);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_S4, stSize.m_stSizeGain.m_stGainName.m_dS4);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_S5, stSize.m_stSizeGain.m_stGainName.m_dS5);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_X1, stSize.m_stSizeGain.m_stGainName.m_dX1);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_X2, stSize.m_stSizeGain.m_stGainName.m_dX2);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R1, stSize.m_stSizeGain.m_stGainName.m_dR1);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R2, stSize.m_stSizeGain.m_stGainName.m_dR2);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R3, stSize.m_stSizeGain.m_stGainName.m_dR3);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R4, stSize.m_stSizeGain.m_stGainName.m_dR4);

		// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R1, stSize.m_stSizeGain.m_stGainName.m_dR1);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R2, stSize.m_stSizeGain.m_stGainName.m_dR2);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R3, stSize.m_stSizeGain.m_stGainName.m_dR3);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R4, stSize.m_stSizeGain.m_stGainName.m_dR4);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R5, stSize.m_stSizeGain.m_stGainName.m_dR5);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R6, stSize.m_stSizeGain.m_stGainName.m_dR6);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_SS1, stSize.m_stSizeGain.m_stGainName.m_dSS1);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_SS2, stSize.m_stSizeGain.m_stGainName.m_dSS2);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_SS3, stSize.m_stSizeGain.m_stGainName.m_dSS3);


		pXmlNode->AddNode(pNode);	delete pNode;
	}

	// Roi
	{
		CXmlNode* pNode = new CXmlNode(XML_INSPECT_SIZEROILIST, NULL);
		{
			for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
			{
				CXmlNode* pNodeRoi = new CXmlNode(XML_INSPECT_SIZEROI, NULL);
				AddAttributeDouble(pNodeRoi, XML_INSPECTATTR_WIDTH, stSize.m_pstFindLineROI[i].m_fWidth);
				AddAttributeDouble(pNodeRoi, XML_INSPECTATTR_HEIGHT, stSize.m_pstFindLineROI[i].m_fHeight);
				AddAttributeDouble(pNodeRoi, XML_INSPECTATTR_ANGLE, stSize.m_pstFindLineROI[i].m_dAngle);
				AddAttributeDouble(pNodeRoi, XML_INSPECTATTR_ANGLE_CRITERIA, stSize.m_pstFindLineROI[i].m_dAngleCriteria);


				CXmlNode* pNodePoint = new CXmlNode(XML_INSPECT_SIZEPOINT, NULL);
				AddAttributeString(pNodePoint, XML_INSPECTATTR_POINTTYPE, XML_INSPECTATTR_VALUE_POINT_CENTER);
				AddAttributeDouble(pNodePoint, XML_INSPECTATTR_POINTX, stSize.m_pstFindLineROI[i].m_stCenterPt.m_fX);
				AddAttributeDouble(pNodePoint, XML_INSPECTATTR_POINTY, stSize.m_pstFindLineROI[i].m_stCenterPt.m_fY);
				pNodeRoi->AddNode(pNodePoint);	delete pNodePoint;

				pNodePoint = new CXmlNode(XML_INSPECT_SIZEPOINT, NULL);
				AddAttributeString(pNodePoint, XML_INSPECTATTR_POINTTYPE, XML_INSPECTATTR_VALUE_POINT_CRITERIA);
				AddAttributeDouble(pNodePoint, XML_INSPECTATTR_POINTX, stSize.m_pstFindLineROI[i].m_ptCriteria.m_fX);
				AddAttributeDouble(pNodePoint, XML_INSPECTATTR_POINTY, stSize.m_pstFindLineROI[i].m_ptCriteria.m_fY);
				pNodeRoi->AddNode(pNodePoint);	delete pNodePoint;

				pNode->AddNode(pNodeRoi);	delete pNodeRoi;
			}
		}
		pXmlNode->AddNode(pNode);	delete pNode;
	}

	// A
	{
		CXmlNode* pNode = new CXmlNode(XML_INSPECT_SIZESAMPLE, NULL);
		{
			AddAttributeString(pNode, XML_INSPECTATTR_SAMPLETYPE, XML_INSPECTATTR_VALUE_SAMPLE_A);

			for (int i = 0; i < TYPE_FINDLINE_MAX; i++)
			{
				CXmlNode* pNodeParam = new CXmlNode(XML_INSPECT_SIZEPARAM, NULL);

				AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_SAMPLEDIRECTION, stSize.m_pstFindLineParameter[i].m_iDirection);
				AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_SAMPLEPOLAR, stSize.m_pstFindLineParameter[i].m_iPolarity);
				AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_SAMPLELOOKFOR, stSize.m_pstFindLineParameter[i].m_iLookFor);
				AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_SAMPLESTRTHRESHOLD, stSize.m_pstFindLineParameter[i].m_iStrengthThreshold);
				AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_SAMPLESAMPLING, stSize.m_pstFindLineParameter[i].m_iSampling);
				AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_SAMPLEKERNELSIZE, stSize.m_pstFindLineParameter[i].m_iKernelSize);
				AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_SAMPLESEARCHANGLE, stSize.m_pstFindLineParameter[i].m_bSearchAngle);
				AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_SAMPLEMINANGLE, stSize.m_pstFindLineParameter[i].m_iMinAngle);
				AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_SAMPLEMAXANGLE, stSize.m_pstFindLineParameter[i].m_iMaxAngle);
				AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_SAMPLEDISTTHRESHOLD, stSize.m_pstFindLineParameter[i].m_iDistanceThreshold);

				pNode->AddNode(pNodeParam);	delete pNodeParam;
			}
		}
		pXmlNode->AddNode(pNode);	delete pNode;
	}

	return pXmlNode;
}

CXmlNode* CXml::SaveInspectionCalc(const INFO_INSPECTION_SIZE_CALC& stCalc)
{
	CXmlNode* pXmlNode = new CXmlNode(XML_INSPECT_CALC, NULL);

	// Calibrate
	{
		CXmlNode* pNode = new CXmlNode(XML_INSPECT_SIZECALIBRATE, NULL);
		{
			// param
			CXmlNode* pNodeParam = new CXmlNode(XML_INSPECT_CALIBRATEPARAM, NULL);
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_LISTCOUNT, stCalc.m_stCalibration.m_nListCount);
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_REFIDX, stCalc.m_stCalibration.m_nIdxReference);
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_ROW, stCalc.m_stCalibration.m_iRow);
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_COL, stCalc.m_stCalibration.m_iCol);
			AddAttributeDouble(pNodeParam, XML_INSPECTATTR_SPACING, stCalc.m_stCalibration.m_dSpacing);
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_UNI, stCalc.m_stCalibration.m_iChessUnit);
			//
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_CALIBRATE_METHOD, stCalc.m_stCalibration.m_iMethod);
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_CALIBRATE_IMAGEWIDTH, stCalc.m_stCalibration.m_iImgWidth);
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_CALIBRATE_IMAGEHEIGHT, stCalc.m_stCalibration.m_iImgHeight);
			AddAttributeDouble(pNodeParam, XML_INSPECTATTR_CALIBRATE_WIDTH, stCalc.m_stCalibration.m_dWidth);
			AddAttributeDouble(pNodeParam, XML_INSPECTATTR_CALIBRATE_HEIGHT, stCalc.m_stCalibration.m_dHeight);
			AddAttributeUnsignedInt(pNodeParam, XML_INSPECTATTR_CALIBRATE_PIXELUNIT, stCalc.m_stCalibration.m_iPixelUnit);

			pNode->AddNode(pNodeParam);	delete pNodeParam;

			// path
			CXmlNode* pNodeList = new CXmlNode(XML_INSPECT_CALIBRATEPATHLIST, NULL);
			for (int i = 0; i < stCalc.m_stCalibration.m_nListCount; i++)
			{
				CXmlNode* pNodePath = new CXmlNode(XML_INSPECT_CALIBRATEPATH, NULL);
				AddAttributeString(pNodePath, XML_INSPECTATTR_IMAGEPATH, stCalc.m_stCalibration.m_pszFilePathList[i]);
				pNodeList->AddNode(pNodePath);	delete pNodePath;
			}
			pNode->AddNode(pNodeList);	delete pNodeList;
		}
		pXmlNode->AddNode(pNode);	delete pNode;
	}

	// Gain
	{
		CXmlNode* pNode = new CXmlNode(XML_INSPECT_SIZEGAIN, NULL);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_D, stCalc.m_stSizeGain.m_stGainName.m_dd);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_L, stCalc.m_stSizeGain.m_stGainName.m_dL);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_W, stCalc.m_stSizeGain.m_stGainName.m_dW);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_I1, stCalc.m_stSizeGain.m_stGainName.m_dI1);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_I2, stCalc.m_stSizeGain.m_stGainName.m_dI2);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_I3, stCalc.m_stSizeGain.m_stGainName.m_dI3);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_M1, stCalc.m_stSizeGain.m_stGainName.m_dM1);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_M2, stCalc.m_stSizeGain.m_stGainName.m_dM2);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_S1, stCalc.m_stSizeGain.m_stGainName.m_dS1);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_S2, stCalc.m_stSizeGain.m_stGainName.m_dS2);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_S3, stCalc.m_stSizeGain.m_stGainName.m_dS3);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_S4, stCalc.m_stSizeGain.m_stGainName.m_dS4);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_S5, stCalc.m_stSizeGain.m_stGainName.m_dS5);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_X1, stCalc.m_stSizeGain.m_stGainName.m_dX1);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_X2, stCalc.m_stSizeGain.m_stGainName.m_dX2);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R1, stCalc.m_stSizeGain.m_stGainName.m_dR1);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R2, stCalc.m_stSizeGain.m_stGainName.m_dR2);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R3, stCalc.m_stSizeGain.m_stGainName.m_dR3);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R4, stCalc.m_stSizeGain.m_stGainName.m_dR4);

		// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R1,  stCalc.m_stSizeGain.m_stGainName.m_dR1);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R2,  stCalc.m_stSizeGain.m_stGainName.m_dR2);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R3,  stCalc.m_stSizeGain.m_stGainName.m_dR3);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R4,  stCalc.m_stSizeGain.m_stGainName.m_dR4);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R5,  stCalc.m_stSizeGain.m_stGainName.m_dR5);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_R6,  stCalc.m_stSizeGain.m_stGainName.m_dR6);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_SS1, stCalc.m_stSizeGain.m_stGainName.m_dSS1);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_SS2, stCalc.m_stSizeGain.m_stGainName.m_dSS2);
		AddAttributeDouble(pNode, XML_INSPECTATTR_SIZEGAIN_SS3, stCalc.m_stSizeGain.m_stGainName.m_dSS3);


		pXmlNode->AddNode(pNode);	delete pNode;
	}

	return pXmlNode;
}

CXmlNode* CXml::SaveStepRectRoi(const INFO_RECT_ROI& stRectRoi)
{
	CXmlNode* pXmlNode = new CXmlNode(XML_INSPECT_RECTROI, NULL);

	AddAttributeInt(pXmlNode, XML_INSPECTATTR_RECT_LEFT, stRectRoi.m_rtRoi.left);
	AddAttributeInt(pXmlNode, XML_INSPECTATTR_RECT_TOP, stRectRoi.m_rtRoi.top);
	AddAttributeInt(pXmlNode, XML_INSPECTATTR_RECT_RIGHT, stRectRoi.m_rtRoi.right);
	AddAttributeInt(pXmlNode, XML_INSPECTATTR_RECT_BOTTOM, stRectRoi.m_rtRoi.bottom);

	return pXmlNode;
}

CXmlNode* CXml::SaveStepMarsParam(const INFO_MARS_PARA& stMarsParam)
{
	CXmlNode* pXmlNode = new CXmlNode(XML_INSPECT_PARAM_MARS, NULL);

	AddAttributeDouble(pXmlNode, XML_INSPECTATTR_MARSPARAM_PROBTHRES, stMarsParam.prob_thres);
	AddAttributeDouble(pXmlNode, XML_INSPECTATTR_MARSPARAM_BLOBSIZETHRES, stMarsParam.blobSize_thres);

	return pXmlNode;
}

CXmlNode* CXml::SaveStepCalibParam(const INFO_CALIB_PARA& stCalibParam)
{
	CXmlNode* pXmlNode = new CXmlNode(XML_INSPECT_PARAM_CALIB, NULL);

	AddAttributeDouble(pXmlNode, XML_INSPECTATTR_CALIBPARAM_PIXEL2REAL, stCalibParam.const_pixel2real);
	AddAttributeDouble(pXmlNode, XML_INSPECTATTR_CALIBPARAM_REAL2PIXEL, stCalibParam.const_real2pixel);

	return pXmlNode;
}

CXmlNode* CXml::SaveStepJudgmentsParam(const INFO_JUDGMENT_PARA& stJudgParam)
{
	CXmlNode* pXmlNode = new CXmlNode(XML_INSPECT_PARAM_JUDGMENT, NULL);

	AddAttributeInt(pXmlNode, XML_INSPECTATTR_JUDGPARAM_FAULTNUM, stJudgParam.faultNum);
	AddAttributeDouble(pXmlNode, XML_INSPECTATTR_JUDGBPARAM_FAULTSIZE, stJudgParam.faultSize);

	return pXmlNode;

}

// Version 1.3.8.1 Image Save & Compress
CXmlNode* CXml::SaveStepImageParam(const INFO_IMAGE_PARA& stImageParam)
{
	CXmlNode* pXmlNode = new CXmlNode(XML_INSPECT_PARAM_IMAGE, NULL);
	int nValue;

	if (stImageParam.imageWrite)	nValue = 1;
	else							nValue = 0;
	AddAttributeInt(pXmlNode, XML_INSPECTATTR_IMAGEPARAM_WRITE, nValue);
	if (stImageParam.imageCompress)	nValue = 1;
	else							nValue = 0;
	AddAttributeInt(pXmlNode, XML_INSPECTATTR_IMAGEPARAM_COMPRESS, nValue);

	return pXmlNode;

}