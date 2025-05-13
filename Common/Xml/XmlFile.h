
#pragma once

#include "XmlDef.h"
#include "XmlNode.h"

#include "inc/tinyxml2.h"

class CXmlFile
{
public: 
	CXmlFile();
	~CXmlFile();

	CXmlNode* Load(TCHAR* pPath, TCHAR* pszRoot);
	BOOL Save(TCHAR* pPath, TCHAR* pszRoot, CXmlNode* pXmlNode);

protected:

	// Load...
	BOOL LoadNode(tinyxml2::XMLHandle& hParent, CXmlNode* pParentNode);

	TYPE_XML_VALUE GetNodeValueType(TCHAR* pTitle);
	BOOL LoadNodeValue(tinyxml2::XMLHandle& hNode, CXmlNode& xmlNode, const TYPE_XML_VALUE eType);


	TYPE_XML_VALUE GetAttributeValueType(TCHAR* pTitle);
	BOOL LoadAttribute(tinyxml2::XMLHandle& hNode, CXmlNode& xmlNode);
	BOOL LoadNextAttribute(const tinyxml2::XMLAttribute* pXmlAttr, CXmlNode& xmlNode);

	BOOL LoadAttributeValue(const tinyxml2::XMLAttribute* pXmlAttr, CXmlNode& xmlNode);

	BOOL SetValue(CXmlValue* pXmlValue, TYPE_XML_VALUE eType, TCHAR* pszText, int nTxtLen);

	
	
	// Save...
	BOOL SaveNode(tinyxml2::XMLDocument& XmlDoc, tinyxml2::XMLElement* pElement, CXmlNode* pXmlNode);

	BOOL SetNodeValue(tinyxml2::XMLDocument& XmlDoc, tinyxml2::XMLElement* pElement, CXmlNode* pXmlNode);
	BOOL SetAttributeValue(tinyxml2::XMLElement* pElement, CXmlAttribute* pXmlAttr);
	


};