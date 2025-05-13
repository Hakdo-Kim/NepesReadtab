
#pragma once

#include "XmlValue.h"

class CXmlAttribute: public CXmlValue
{
public:
	CXmlAttribute();
	CXmlAttribute(TCHAR* pTitle);
	CXmlAttribute(TCHAR* pTitle, TYPE_XML_VALUE eType, void* pData, int  nDataLen);
	CXmlAttribute(TCHAR* pTitle, CXmlValue* pValue);
	CXmlAttribute(CXmlAttribute* pAttr);
	virtual ~CXmlAttribute();

	const TCHAR* GetTitle();
	BOOL SetTitle(const TCHAR* pTitle);


protected:
	TCHAR m_szTitle[MAX_XML_NAME_LEN];
	
};