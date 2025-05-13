
#pragma once

#include "XmlDef.h"

class CXmlValue
{
public:
	CXmlValue();
	CXmlValue(TYPE_XML_VALUE eType, void* pData, int  nDataLen);
	CXmlValue(CXmlValue* pValue);
	virtual ~CXmlValue();

	TYPE_XML_VALUE GetValueType();
	int GetValue(void* pData, int nDataLen);

	BOOL SetValue(TYPE_XML_VALUE eType, void* pData, int nDataLen);
	BOOL SetValue(CXmlValue* pValue);


protected:
	TYPE_XML_VALUE m_eXmlValue;

	void* m_pData;
	int m_nDataLen;

	void ReleaseValue();

};