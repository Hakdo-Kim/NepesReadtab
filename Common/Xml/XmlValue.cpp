
#include "StdAfx.h"
#include "XmlValue.h"

CXmlValue::CXmlValue()
{
	m_eXmlValue = TYPE_XML_VALUE_NONE;
	m_pData = NULL;
	m_nDataLen = 0;
}

CXmlValue::CXmlValue(TYPE_XML_VALUE eType, void* pData, int  nDataLen)
{
	m_eXmlValue = TYPE_XML_VALUE_NONE;
	m_pData = NULL;
	m_nDataLen = 0;

	if (TYPE_XML_VALUE_NONE == eType || NULL == pData || 0 >= nDataLen)
	{
		return;
	}

	SetValue(eType, pData, nDataLen);
}

CXmlValue::CXmlValue(CXmlValue* pValue)
{
	m_eXmlValue = TYPE_XML_VALUE_NONE;
	m_pData = NULL;
	m_nDataLen = 0;

	if (NULL == pValue)
	{
		return;
	}

	SetValue(pValue);
}



CXmlValue::~CXmlValue()
{
	ReleaseValue();
}

TYPE_XML_VALUE CXmlValue::GetValueType()
{
	return m_eXmlValue;
}

int CXmlValue::GetValue(void* pData, int nDataLen)
{
	if (NULL == pData || 1 > nDataLen)
	{
		return m_nDataLen;
	}

	const int len = min(nDataLen, m_nDataLen);
	memcpy(pData, m_pData, len);

	return len;
}

BOOL CXmlValue::SetValue(TYPE_XML_VALUE eType, void* pData, int nDataLen)
{
	if (TYPE_XML_VALUE_NONE == eType || NULL == pData || 0 >= nDataLen)
	{
		return FALSE;
	}

	if (nDataLen != m_nDataLen)
		ReleaseValue();

	m_eXmlValue = eType;

	m_nDataLen = nDataLen;
	if (NULL == m_pData)
		m_pData = new BYTE[m_nDataLen];

	memcpy(m_pData, pData, nDataLen);

	return TRUE;
}

BOOL CXmlValue::SetValue(CXmlValue* pValue)
{
	if (NULL == pValue)
		return FALSE;
	
	m_eXmlValue = pValue->GetValueType();

	m_nDataLen = pValue->GetValue(NULL, 0);
	if (m_nDataLen > 0)
	{
		m_pData = new BYTE[m_nDataLen];
		pValue->GetValue(m_pData, m_nDataLen);
	}
	else
	{
		ReleaseValue();

		return FALSE;
	}


	return TRUE;
}

void CXmlValue::ReleaseValue()
{
	m_eXmlValue = TYPE_XML_VALUE_NONE;
	if (m_pData)
	{
		delete[] m_pData;
	}

	m_pData = NULL;
	m_nDataLen = 0;

}