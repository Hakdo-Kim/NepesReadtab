
#include "StdAfx.h"
#include "XmlAttribute.h"

#include "Util/Util.h"

CXmlAttribute::CXmlAttribute()
	: CXmlValue()
{
	memset(m_szTitle, 0x00, sizeof(TCHAR)*MAX_XML_NAME_LEN);
	
}

CXmlAttribute::CXmlAttribute(TCHAR* pTitle)
	: CXmlValue()
{
	memset(m_szTitle, 0x00, sizeof(TCHAR)*MAX_XML_NAME_LEN);
	if (pTitle)
		CUtil::StringCopy(m_szTitle, pTitle);

}

CXmlAttribute::CXmlAttribute(TCHAR* pTitle, TYPE_XML_VALUE eType, void* pData, int  nDataLen)
	: CXmlValue(eType, pData, nDataLen)
{
	memset(m_szTitle, 0x00, sizeof(TCHAR)*MAX_XML_NAME_LEN);
	if (pTitle)
		CUtil::StringCopy(m_szTitle, pTitle);

}

CXmlAttribute::CXmlAttribute(CXmlAttribute* pAttr)
	: CXmlValue()
{
	if (NULL==pAttr)
		return;

	const TCHAR* pTitle = pAttr->GetTitle();

	memset(m_szTitle, 0x00, sizeof(TCHAR)*MAX_XML_NAME_LEN);
	
	SetTitle(pTitle);
	SetValue(pAttr);

}


CXmlAttribute::CXmlAttribute(TCHAR* pTitle, CXmlValue* pValue)
	: CXmlValue(pValue)
{
	memset(m_szTitle, 0x00, sizeof(TCHAR)*MAX_XML_NAME_LEN);
	if (pTitle)
		CUtil::StringCopy(m_szTitle, pTitle);
}

CXmlAttribute::~CXmlAttribute()
{
	;
}

const TCHAR* CXmlAttribute::GetTitle()
{
	return m_szTitle;
}

BOOL CXmlAttribute::SetTitle(const TCHAR* pTitle)
{
	if (NULL == pTitle)
		return FALSE;

	CUtil::StringCopy(m_szTitle, pTitle);

	return TRUE;
}