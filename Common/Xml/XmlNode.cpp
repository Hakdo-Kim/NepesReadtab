
#include "StdAfx.h"
#include "XmlNode.h"

#include "Util/Util.h"

CXmlNode::CXmlNode()
	:CXmlAttribute()
{
	m_pParentNode = NULL;

	m_ChildNodeList.clear();
	m_AttrList.clear();
}

CXmlNode::CXmlNode(TCHAR* pNodeTitle, CXmlNode* pParent)
	: CXmlAttribute(pNodeTitle)
{
	m_ChildNodeList.clear();
	m_AttrList.clear();

	m_pParentNode = pParent;
}

CXmlNode::CXmlNode(TCHAR* pNodeTitle, TYPE_XML_VALUE eType, void* pData, int  nDataLen, CXmlNode* pParent)
	: CXmlAttribute(pNodeTitle, eType, pData, nDataLen)
{
	m_ChildNodeList.clear();
	m_AttrList.clear();

	m_pParentNode = pParent;
}

CXmlNode::CXmlNode(TCHAR* pNodeTitle, CXmlValue* pValue, CXmlNode* pParent)
	: CXmlAttribute(pNodeTitle, pValue)
{
	m_ChildNodeList.clear();
	m_AttrList.clear();

	m_pParentNode = pParent;
}

CXmlNode::CXmlNode(CXmlNode* pElement)
	: CXmlAttribute()
{
	if (NULL == pElement)
		return;

	m_ChildNodeList.clear();
	m_AttrList.clear();


	const TCHAR* pTitle = pElement->GetTitle();

	SetTitle(pTitle);
	SetValue(pElement);
	SetParentNode(pElement->GetParentNode());

	// Add Attribute
	{
		const int size = pElement->GetAttributeCount();
		for (int i = 0; i < size; i++)
		{
			this->AddAttribute(pElement->GetAttribute(i));
		}
	}

	// Add Element
	{
		const int size = pElement->GetNodeCount();
		for (int i = 0; i < size; i++)
		{
			this->AddNode(pElement->GetNode(i));
		}
	}

}


CXmlNode::~CXmlNode()
{
	ReleaseValue();
	ReleaseElement();

}

void CXmlNode::ReleaseElement()
{
	// Attribute
	{
		const int size = m_AttrList.size();
		for (int i = size-1; i >= 0; i--)
		{
			CXmlAttribute* pAttr = m_AttrList[i];
			if (pAttr)
				delete pAttr;
		}
		m_AttrList.clear();
	}

	// Element
	{
		const int size = m_ChildNodeList.size();

		for (int i = size - 1; i >= 0; i--)
		{
			CXmlNode* pElement = m_ChildNodeList[i];
			if (pElement)
			{
				delete pElement;
			}
		}
		m_ChildNodeList.clear();
	}

}


// Attribute
int CXmlNode::GetAttributeCount()
{
	const int size = m_AttrList.size();
	return size;
}

CXmlAttribute* CXmlNode::GetAttribute(int nIdx)
{
	const int size = m_AttrList.size();
	if (0 > nIdx || size <= nIdx)
		return NULL;

	CXmlAttribute* pAttr = m_AttrList[nIdx];
	return pAttr;
}

CXmlAttribute* CXmlNode::GetAttribute(const TCHAR* pTitle)
{
	CXmlAttribute* pAttr = NULL;
	if (NULL == pTitle)
		return NULL;

	const int size = m_AttrList.size();
	for (int i = 0; i < size; i++)
	{
		const TCHAR* pAttrTitle = m_AttrList[i]->GetTitle();
		if (CUtil::StringCompare((TCHAR*)pTitle, (TCHAR*)pAttrTitle))
		{
			pAttr = m_AttrList[i];
			break;
		}
	}

	return pAttr;
}


BOOL CXmlNode::AddAttribute(CXmlAttribute* pAttr)
{
	if (NULL == pAttr)
		return FALSE;

	const TCHAR* pTitle = pAttr->GetTitle();

	const CXmlAttribute* pXmlAttr = GetAttribute(pTitle);
	if (pXmlAttr)
	{
		return FALSE;
	}

	m_AttrList.push_back(new CXmlAttribute(pAttr));

	return TRUE;
}

BOOL CXmlNode::AddAttribute(TCHAR* pTitle, TYPE_XML_VALUE eType, void* pData, int nDataLen)
{
	if (NULL == pTitle || 0 > nDataLen)
		return FALSE;

	CXmlAttribute xmlAttr(pTitle, eType, pData, nDataLen);

	BOOL bResult = AddAttribute(&xmlAttr);
	return bResult;
}

BOOL CXmlNode::AddAttribute(TCHAR* pTitle, CXmlValue* pValue)
{
	if (NULL == pTitle)
		return FALSE;

	CXmlAttribute xmlAttr(pTitle, pValue);

	BOOL bResult = AddAttribute(&xmlAttr);
	return bResult;
}

// Element
CXmlNode* CXmlNode::GetParentNode()
{
	return m_pParentNode;
}

BOOL CXmlNode::SetParentNode(CXmlNode* pParent)
{
	m_pParentNode = pParent;

	return TRUE;
}


int CXmlNode::GetNodeCount()
{
	const int size = m_ChildNodeList.size();

	return size;
}


CXmlNode* CXmlNode::GetNode(int nIdx)
{
	const int size = m_ChildNodeList.size();
	if (0 > nIdx || size <= nIdx)
		return NULL;

	return m_ChildNodeList[nIdx];
}

BOOL CXmlNode::AddNode(CXmlNode* pElement)
{
	if (NULL == pElement)
		return FALSE;

	CXmlNode* pChild = new CXmlNode(pElement);
	pChild->SetParentNode(this);

	m_ChildNodeList.push_back(pChild);

	return TRUE;
}

BOOL CXmlNode::AddNode(TCHAR* pNodeTitle, TYPE_XML_VALUE eType, void* pData, int nDataLen)
{
	if (NULL == pNodeTitle)
		return FALSE;

	CXmlNode* pChild = new CXmlNode(pNodeTitle, eType, pData, nDataLen, this);
	m_ChildNodeList.push_back(pChild);

	return TRUE;
}

BOOL CXmlNode::AddNode(TCHAR* pNodeTitle, CXmlValue* pValue)
{
	if (NULL == pNodeTitle)
		return FALSE;

	CXmlNode* pChild = new CXmlNode(pNodeTitle, pValue, this);
	m_ChildNodeList.push_back(pChild);

	return TRUE;
}

