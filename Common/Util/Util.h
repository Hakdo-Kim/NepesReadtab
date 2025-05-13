#pragma once
#pragma warning(disable:4996)

#include "Common.h"

#define MAX_UTIL_NAME_LEN				128

typedef struct
{
	TCHAR	m_szPortName[MAX_UTIL_NAME_LEN];
	TCHAR	m_szFriendlyName[MAX_UTIL_NAME_LEN];
	TCHAR	m_szTechnology[MAX_UTIL_NAME_LEN];

} INFO_SERIALPORT;


class CUtil
{
public:
	CUtil(void);
	~CUtil(void);


	// Print debug string
	static void PrintDebugString(const TCHAR* szFormat, ...);
	static void PumpMessage();


	// String
	static void StringFormat(TCHAR* szString, int nLen, const TCHAR* szFormat, ...);
	
	static int StringLength(TCHAR* pszStr);
	
	static void StringCopy(TCHAR* pszDest, const TCHAR* pszSrc);
	static void StringCopy(TCHAR* pszDest, const TCHAR* pszSrc, const int nLen);
	static void StringCat(TCHAR* pszDest, const TCHAR* pszSrc);
	static BOOL StringCompare(TCHAR* pszStr1, TCHAR* pszStr2);
	static BOOL StringICompare(TCHAR* pszStr1, TCHAR* pszStr2);
	
	static BOOL StringSearch(TCHAR* pszStr1, TCHAR* pszStr2, int* pPos=NULL);
	static BOOL StringReverseSearchChar(TCHAR* pszStr1, TCHAR cCh, int* pPos = NULL);
	
	static void StringToUpper(TCHAR* pszStr);


	static BYTE StringToByte(TCHAR* pszStr, int nLen);
	static int StringToInt(TCHAR* pszStr, int nLen);
	static DWORD StringToDword(TCHAR* pszStr, int nLen);
	
	static double StringToDouble(TCHAR* pszStr, int nLen);
	static int StringToDouble(TCHAR* pszStr, int nLen, TCHAR* pszSeps, double* pfList, int nListLen);

	static DWORD HexStringToDword(TCHAR* pszStr, int nLen);
	static int HexStringToDword(TCHAR* pszStr, int nLen, TCHAR* pszSeps, DWORD* pdwList, int nListLen);

	static int ConvertCommaString(TCHAR* pszStr, int nLen, const int nValue);

	static int StringToIntList(TCHAR* pszStr, int nLen, TCHAR* pszSeps, int* pnList, int nListLen);

	

	
	// File
	static BOOL IsExistFile(const TCHAR* pszPath);
	static BOOL IsDirectory(const TCHAR* pszPath);

	static void DeleteFile(const TCHAR* pszPath);
	static BOOL DeleteFileInDirectory(const TCHAR* pszPath);

	static BOOL ReadTextFile(const TCHAR* pszPath, BYTE** ppBuf, DWORD* pdwBufLen);

	static void DumpFile(const TCHAR* pszPath, BYTE* pBuf, DWORD dwBufLen);
	static void DumpBinaryToText(const TCHAR* pszPath, BYTE* pBuf, DWORD dwBufLen);
	static void DumpImageBinaryToText(const TCHAR* pszPath, BYTE* pBuf, DWORD dwBufLen, const int nW, const int nH, const int nBit);
	static void DumpProfileToText(const TCHAR* pszPath, BYTE* pBuf, DWORD dwBufLen, const int nW, const int nH, const int nBit);
	

	// Select - File or Directory
	static BOOL GetCurrentDirectory(TCHAR* pszPath, DWORD dwLen);

	static BOOL SelectFile(const TCHAR* pLocation, TCHAR* pFilePath, int nLen, TCHAR* pszName, TCHAR* pszFilter, int* pnFilterIdx, BOOL bOpen);
	static BOOL SelectDirectory(TCHAR* pszPath, int nLen);
	


	// Registry
protected:
	static HKEY CreateRegKey(const TCHAR* pSubKey);
	static void CloseRegKey(HKEY hKey);
public:
	static void DeleteRegKey(const TCHAR* pSubKey);

	static BOOL IsExistRegKey(const TCHAR* pSubKey);

	static BOOL GetRegString(const TCHAR* pSubKey, const TCHAR* pValue, TCHAR* pString, int nLen);
	static BOOL SetRegString(const TCHAR* pSubKey, const TCHAR* pValue, TCHAR* pString);

	static BOOL GetRegDword(const TCHAR* pSubKey, const TCHAR* pValue, DWORD& value);
	static BOOL SetRegDword(const TCHAR* pSubKey, const TCHAR* pValue, const DWORD value);


	// Time
	static BOOL GetCurTime(DWORD* pdwYear, DWORD* pdwMonth, DWORD* pdwDay, DWORD* pdwHour, DWORD* pdwMinute, DWORD* pdwSec);
	static BOOL GetCurTime(DWORD* pdwHour, DWORD* pdwMinute, DWORD* pdwSec);
	static BOOL GetCurTime(DWORD* pdwSec);


	// Sleep
	static void Sleep(DWORD dwMsec);
	static void WaitnSleep(DWORD dwMsec);


	// Sort 
	static BOOL Sort(double* pList, int nLen, BOOL bAsc = TRUE);	// Quick sort


	// Image
protected:
	static BOOL IsEnableImageExt(const TCHAR* pszFileName);
public:
	static BOOL LoadImageBuffer(const TCHAR* pszPath, BYTE* pBuffer, const DWORD dwLen, 
								const DWORD dwX, const DWORD dwY, const DWORD dwWidth, const DWORD dwHeight, const BYTE nBit);
	static BOOL LoadImageBuffer(const TCHAR* pszPath, BYTE** ppBuffer, DWORD* pdwLen, DWORD* pdwWidth, DWORD* pdwHeight, BYTE* pnBit);
	static BOOL WriteImageFromBuffer(const TCHAR* pszPath, BYTE* pBuffer, DWORD dwLen, DWORD dwWidth, DWORD dwHeight, BYTE nBit, int nPitch);

	static BOOL GetMaxImageSizeDir(const TCHAR* pszPath, int& width, int& height);


	// Calculate
	static int GetRadious(POINT pt1, POINT pt2);
	static double GetAngle(POINT pt1, POINT pt2, BOOL bDegree);


	// Base 64 - Encode & Decode
protected:
	static inline BOOL IsBase64(unsigned char c);
public:
	static DWORD EncodeBase64(const BYTE* pInput, const DWORD dwInput, BYTE* pOutput, DWORD& dwOutput);
	static DWORD DecodeBase64(const BYTE* pInput, const DWORD dwInput, BYTE* pOutput, DWORD& dwOutput);


	// System - Ethernet Adaptor
	static BOOL GetEthernetAdaptorList(DWORD* pIpAddress, int* pnLen);
	static int GetEthernetAdaptorList(INFO_ETHERNET_ADAPTOR* pstInterface, int nLen);


	// Message...
	static void DisplayRangeMessage(HWND hWnd, const int nMin, const int nMax, BOOL bHex = FALSE);
	static void DisplayRangeMessage(HWND hWnd, const float fMin, const float fMax);
	

	// Serial Port
	static int SearchSerialUart(INFO_SERIALPORT* pstSerialPort, int nPortLen);

};
