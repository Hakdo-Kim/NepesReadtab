
#pragma once

#include "XmlAttribute.h"

#include <vector>

class CXmlNode : public CXmlAttribute
{
public:
	CXmlNode();
	CXmlNode(TCHAR* pNodeTitle, CXmlNode* pParent);
	CXmlNode(TCHAR* pNodeTitle, TYPE_XML_VALUE eType, void* pData, int  nDataLen, CXmlNode* pParent);
	CXmlNode(TCHAR* pNodeTitle, CXmlValue* pValue, CXmlNode* pParent);
	CXmlNode(CXmlNode* pNode);

	virtual ~CXmlNode();

	// Attribute
	int GetAttributeCount();

	CXmlAttribute* GetAttribute(int nIdx);
	CXmlAttribute* GetAttribute(const TCHAR* pTitle);

	BOOL AddAttribute(CXmlAttribute* pAttr);
	BOOL AddAttribute(TCHAR* pTitle, TYPE_XML_VALUE eType, void* pData, int nDataLen);
	BOOL AddAttribute(TCHAR* pTitle, CXmlValue* pValue);

	
	// Element
	CXmlNode* GetParentNode();
	BOOL SetParentNode(CXmlNode* pParent);

	int GetNodeCount();
	CXmlNode* GetNode(int nIdx);

	BOOL AddNode(CXmlNode* pNode);
	BOOL AddNode(TCHAR* pNodeTitle, TYPE_XML_VALUE eType, void* pData, int nDataLen);
	BOOL AddNode(TCHAR* pNodeTitle, CXmlValue* pValue);



	

protected:

	CXmlNode* m_pParentNode;

	std::vector<CXmlNode*>  m_ChildNodeList;
	std::vector<CXmlAttribute*>  m_AttrList;

	void ReleaseElement();

	
};