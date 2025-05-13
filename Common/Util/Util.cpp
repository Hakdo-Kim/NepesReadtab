#include "StdAfx.h"
#include "Util.h"

#include <gdiplus.h>
using namespace Gdiplus;
#pragma comment (lib, "Gdiplus.lib")

#include "atlimage.h"
#include "Iphlpapi.h"
#pragma comment(lib, "Iphlpapi.lib")


#ifdef DEF_USE_OPENCV
	#include "opencv/highgui.h"
	#ifdef DEF_LPAPP
	#ifdef _DEBUG
		#pragma comment(lib, "opencv_ts300d.lib")
		#pragma comment(lib, "opencv_world300d.lib")
	#else
		#pragma comment(lib, "opencv_ts300.lib")
		#pragma comment(lib, "opencv_world300.lib")
	#endif

	#else
		#pragma comment(lib, "opencv_ts300.lib")
		#pragma comment(lib, "opencv_world300.lib")

	#endif
#endif

#include <string>

#define max(a, b)  (((a) > (b)) ? (a) : (b)) 

CUtil::CUtil(void)
{
	;
}

CUtil::~CUtil(void)
{
	;
}

void CUtil::PrintDebugString(const TCHAR* szFormat, ...)
{
#ifdef _DEBUG
	TCHAR szString[MAX_TEXT_LEN] = {0,};

	va_list arg;
    va_start(arg, szFormat);
    _vsntprintf(szString, MAX_TEXT_LEN, szFormat, arg);
    va_end(arg);

	::OutputDebugString(szString);
#endif

}

void CUtil::PumpMessage()
{
	MSG msg;
	if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
	{
		GetMessage(&msg, NULL, 0, 0);
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}



// String

int CUtil::StringLength(TCHAR* pszStr)
{
	if(NULL==pszStr )
		return -1;

	int len = _tcslen(pszStr);

	return len;
}

void CUtil::StringCopy(TCHAR* pszDest, const TCHAR* pszSrc)
{
	if(NULL==pszDest || NULL==pszSrc)
		return;

	_tcscpy(pszDest, pszSrc);
}

void CUtil::StringCopy(TCHAR* pszDest, const TCHAR* pszSrc, const int nLen)
{
	if (NULL == pszDest || NULL == pszSrc)
		return;

	_tcsncpy(pszDest, pszSrc, nLen);
}

void CUtil::StringCat(TCHAR* pszDest, const TCHAR* pszSrc)
{
	if (NULL == pszDest || NULL == pszSrc)
		return;

	_tcscat(pszDest, pszSrc);
}

BOOL CUtil::StringCompare(TCHAR* pszStr1, TCHAR* pszStr2)
{
	if(NULL==pszStr1 || NULL==pszStr2)
		return FALSE;
	
	int n = _tcscmp(pszStr1, pszStr2);
	if(0!=n)
		return FALSE;

	return TRUE;
}

BOOL CUtil::StringICompare(TCHAR* pszStr1, TCHAR* pszStr2)
{
	if (NULL == pszStr1 || NULL == pszStr2)
		return FALSE;

	int n = _tcsicmp(pszStr1, pszStr2);
	if (0 != n)
		return FALSE;

	return TRUE;
}

BOOL CUtil::StringSearch(TCHAR* pszStr1, TCHAR* pszStr2, int* pPos)
{
	if(NULL==pszStr1 || NULL==pszStr2)
		return FALSE;
	
	TCHAR* pChar = _tcsstr(pszStr1, pszStr2);
	if(NULL==pChar)
		return FALSE;

	if (pPos)
	{
		*pPos = pChar - pszStr1;
	}

	return TRUE;
}

BOOL CUtil::StringReverseSearchChar(TCHAR* pszStr1, TCHAR cCh, int* pPos)
{
	if (NULL == pszStr1 )
		return FALSE;

	TCHAR* pChar = _tcsrchr(pszStr1, cCh);
	if (NULL == pChar)
		return FALSE;

	if (pPos)
	{
		*pPos = pChar - pszStr1;
	}
	return TRUE;

}


void CUtil::StringToUpper(TCHAR* pszStr)
{
	if(NULL==pszStr)
		return;

	const int nLen = CUtil::StringLength(pszStr);
	for(int i=0; i<nLen; i++)
	{
		pszStr[i] = _totupper(pszStr[i]);
	}

}



void CUtil::StringFormat(TCHAR* szString, int nLen, const TCHAR* szFormat, ...)
{
	va_list arg;
    va_start(arg, szFormat);
    _vsntprintf(szString, nLen, szFormat, arg);
    va_end(arg);
}


BYTE CUtil::StringToByte(TCHAR* pszStr, int nLen)
{
	if(NULL==pszStr || 0>=nLen)
		return 0;

	TCHAR szValue[MAX_TEXT_LEN] = {0,};

	CUtil::StringCopy(szValue, pszStr, nLen);

	BYTE data = (BYTE)_tstoi( szValue);

	return data;
}

int CUtil::StringToInt(TCHAR* pszStr, int nLen)
{
	if(NULL==pszStr || 0>=nLen)
		return 0;

	TCHAR szValue[MAX_TEXT_LEN] = {0,};

	CUtil::StringCopy(szValue, pszStr, nLen);

	int data = _tstoi( szValue);

	return data;
}

int CUtil::StringToIntList(TCHAR* pszStr, int nLen, TCHAR* pszSeps, int* pnList, int nListLen)
{
	if (NULL == pszStr || NULL == pszSeps || NULL == pnList)
		return -1;

	int nCount = 0;

	TCHAR* pToken = _tcstok(pszStr, pszSeps);
	while (pToken)
	{
		pnList[nCount] = CUtil::StringToInt(pToken, CUtil::StringLength(pToken));
		nCount++;

		pToken = _tcstok(NULL, pszSeps);
	}

	return nCount;
}


DWORD CUtil::StringToDword(TCHAR* pszStr, int nLen)
{
	if (NULL == pszStr || 0 >= nLen)
		return 0;

	TCHAR szValue[MAX_TEXT_LEN] = { 0, };

	CUtil::StringCopy(szValue, pszStr, nLen);

	DWORD data = _tstol(szValue);

	return data;
}


int CUtil::ConvertCommaString(TCHAR* pszStr, int nLen, const int nValue)
{
	if(NULL==pszStr || 0>=nLen)
		return 0;

	TCHAR szValue[MAX_TEXT_LEN] = {0,};
	CUtil::StringFormat(szValue, MAX_TEXT_LEN, _T("%d"), nValue);

	const int nTxt = CUtil::StringLength(szValue);
	
	int nIdx = nTxt + nTxt/3;
	if( 0== nTxt%3 )
		nIdx -= 1;

	pszStr[nIdx] = NULL;

	for(int i=0; i<nTxt; i++)
	{
		if(0<i && 0==i%3)
		{
			pszStr[nIdx-1] = _T(',');
			nIdx--;
		}

		pszStr[nIdx-1] = szValue[nTxt-i-1];
		nIdx--;
	}

	return nTxt + nTxt/3;
}




DWORD CUtil::HexStringToDword(TCHAR* pszStr, int nLen)
{
	if(NULL==pszStr || 0>=nLen)
		return 0;

	DWORD data = _tcstoul( pszStr, NULL, 16);

	return data;
}


int CUtil::HexStringToDword(TCHAR* pszStr, int nLen, TCHAR* pszSeps, DWORD* pdwList, int nListLen)
{
	if(NULL==pszStr || NULL==pszSeps || NULL==pdwList)
		return -1;

	int nCount = 0;

	TCHAR* pToken = _tcstok(pszStr, pszSeps);
	while(pToken)
	{
		pdwList[nCount] = CUtil::HexStringToDword(pToken, CUtil::StringLength(pToken));
		nCount++;

		pToken = _tcstok(NULL, pszSeps);
	}

	return nCount;
}


double CUtil::StringToDouble(TCHAR* pszStr, int nLen)
{
	if(NULL==pszStr || 0>=nLen)
		return 0;

	double data = _ttof( pszStr);

	return data;
}

int CUtil::StringToDouble(TCHAR* pszStr, int nLen, TCHAR* pszSeps, double* pfList, int nListLen)
{
	if(NULL==pszStr || NULL==pszSeps || NULL==pfList)
		return -1;

	int nCount = 0;

	TCHAR* pToken = _tcstok(pszStr, pszSeps);
	while(pToken)
	{
		pfList[nCount] = CUtil::StringToDouble(pToken, CUtil::StringLength(pToken));
		nCount++;

		pToken = _tcstok(NULL, pszSeps);
	}

	return nCount;
}


// File
BOOL CUtil::IsExistFile(const TCHAR* pszPath)
{
	HANDLE hFile = ::CreateFile(pszPath, 
							GENERIC_READ,
							FILE_SHARE_READ | FILE_SHARE_WRITE,
							NULL,
							OPEN_EXISTING,
							0, 
							NULL);
	if(INVALID_HANDLE_VALUE==hFile)
		return FALSE;
	::CloseHandle(hFile);

	return TRUE;
}

void CUtil::DeleteFile(const TCHAR* pszPath)
{
	if (NULL == pszPath)
		return;
	::DeleteFile(pszPath);
}

BOOL CUtil::DeleteFileInDirectory(const TCHAR* szDir)
{
	if (NULL == szDir)
		return FALSE;

	CString szNextDirPath = _T("");
	CString szRoot = _T("");

	szRoot.Format(_T("%s\\*.*"), szDir);
	CFileFind find;
	BOOL bRes = find.FindFile(szRoot);
	if (bRes == FALSE)
		return bRes;

	while (bRes)
	{
		bRes = find.FindNextFile();
		if (find.IsDots() == FALSE)
		{
			if (find.IsDirectory())
			{
				DeleteFileInDirectory(find.GetFilePath());
			}
			else
			{
				bRes = ::DeleteFile(find.GetFilePath());
			}
		}
	}

	find.Close();
	bRes = ::RemoveDirectory(szDir);
	return bRes;
}

BOOL CUtil::IsDirectory(const TCHAR* pszPath)
{
	if (NULL == pszPath)
		return FALSE;
	
	DWORD dwAttribute = GetFileAttributes(pszPath);
	if (-1 != dwAttribute && FILE_ATTRIBUTE_DIRECTORY & dwAttribute)
		return TRUE;

	return FALSE;
}

BOOL CUtil::ReadTextFile(const TCHAR* pszPath, BYTE** ppBuf, DWORD* pdwBufLen)
{
	BYTE* pBuf		= NULL;
	DWORD dwBufLen	= 0;
	DWORD dwReaded = 0;

	HANDLE hFile = ::CreateFile(pszPath, 
						GENERIC_READ,
						FILE_SHARE_READ,
						NULL,
						OPEN_EXISTING,
						0, 
						NULL);
	if(INVALID_HANDLE_VALUE==hFile)
	{
		return FALSE;
	}

	dwBufLen = ::GetFileSize (hFile, NULL) +1;
	if(0<dwBufLen)
	{
		pBuf = new BYTE[dwBufLen];
		memset(pBuf, 0x00, dwBufLen);
	}
	else
	{
		::CloseHandle(hFile);
		return FALSE;
	}

	::ReadFile(hFile, pBuf, dwBufLen, &dwReaded, NULL);
	
	::CloseHandle(hFile);

	*ppBuf		= pBuf;
	*pdwBufLen	= dwBufLen;


	return TRUE;
}

void CUtil::DumpFile(const TCHAR* pszPath, BYTE* pBuf, DWORD dwBufLen)
{
	DWORD dwResult = 0;

	HANDLE hFile = ::CreateFile(pszPath,
						GENERIC_READ | GENERIC_WRITE,
						0,
						NULL,
						CREATE_ALWAYS,
						0,
						NULL);
	if(INVALID_HANDLE_VALUE==hFile)
		return;

	::WriteFile(hFile, pBuf, dwBufLen, &dwResult, NULL);
	
	::CloseHandle(hFile);

}

void CUtil::DumpBinaryToText(const TCHAR* pszPath, BYTE* pBuf, DWORD dwBufLen)
{
	DWORD dwResult = 0;

	HANDLE hFile = ::CreateFile(pszPath,
						GENERIC_READ | GENERIC_WRITE,
						0,
						NULL,
						CREATE_ALWAYS,
						0,
						NULL);
	if(INVALID_HANDLE_VALUE==hFile)
		return;

	TCHAR szText[128] = {0,};

	for (int i = 0; i<(int)dwBufLen; i++)
	{
		CUtil::StringFormat( szText, 128, _T("%d \r\n"), pBuf[i]);
		::WriteFile(hFile, szText, CUtil::StringLength(szText), &dwResult, NULL);
	}
	
	::CloseHandle(hFile);
}

void CUtil::DumpImageBinaryToText(const TCHAR* pszPath, BYTE* pBuf, DWORD dwBufLen, const int nW, const int nH, const int nBit)
{
	DWORD dwResult = 0;

	HANDLE hFile = ::CreateFile(pszPath,
						GENERIC_READ | GENERIC_WRITE,
						0,
						NULL,
						CREATE_ALWAYS,
						0,
						NULL);
	if(INVALID_HANDLE_VALUE==hFile)
		return;

	TCHAR szText[128] = {0,};
	const int nPitch = nW * nBit/8;

	if(8==nBit)
	{
		for (int i = 0; i<(int)dwBufLen; i++)
		{
			if(nPitch>i)
			{
				CUtil::StringFormat( szText, 128, _T("%d \r\n"), pBuf[i]);
				::WriteFile(hFile, szText, CUtil::StringLength(szText), &dwResult, NULL);
			}
			else
			{
				if(nPitch==i)
				{
					CUtil::StringFormat( szText, 128, _T("\r\n[Other Info] \r\n"));
					::WriteFile(hFile, szText, CUtil::StringLength(szText), &dwResult, NULL);
				}

				CUtil::StringFormat( szText, 128, _T("%x \r\n"), pBuf[i]);
				::WriteFile(hFile, szText, CUtil::StringLength(szText), &dwResult, NULL);
			}
		}
	}
	else if(12==nBit)
	{
		for (int i = 0; i<(int)dwBufLen; i++)
		{
			if(nPitch>i)
			{
				DWORD dwFirst	= pBuf[i];
				DWORD dwSecond	= pBuf[i+2];
				
				dwFirst <<= 4;
				dwFirst |= ( (pBuf[i+1]&0xF0)>>4 );
				
				dwSecond <<= 4;
				dwSecond |= (pBuf[i+1]&0x0F);


				CUtil::StringFormat( szText, 128, _T("%d \r\n"), dwFirst);
				::WriteFile(hFile, szText, CUtil::StringLength(szText), &dwResult, NULL);

				CUtil::StringFormat( szText, 128, _T("%d \r\n"), dwSecond);
				::WriteFile(hFile, szText, CUtil::StringLength(szText), &dwResult, NULL);

				i+=2;
			}
			else
			{
				if(nPitch==i)
				{
					CUtil::StringFormat( szText, 128, _T("\r\n[Other Info] \r\n"));
					::WriteFile(hFile, szText, CUtil::StringLength(szText), &dwResult, NULL);
				}

				CUtil::StringFormat( szText, 128, _T("0x%x \r\n"), pBuf[i]);
				::WriteFile(hFile, szText, CUtil::StringLength(szText), &dwResult, NULL);
			}
		}
	}

	::CloseHandle(hFile);

}

void CUtil::DumpProfileToText(const TCHAR* pszPath, BYTE* pBuf, DWORD dwBufLen, const int nW, const int nH, const int nBit)
{
	HANDLE hFile = ::CreateFile(pszPath,
						GENERIC_READ | GENERIC_WRITE,
						0,
						NULL,
						CREATE_ALWAYS,
						0,
						NULL);
	if(INVALID_HANDLE_VALUE==hFile)
		return;

	TCHAR szText[128] = {0,};
	const int nPitch = nW * nBit/8;
	float fProfile = 0.0f;

	if(8==nBit || 12==nBit)
	{
		DWORD dwResult = 0;

		for (int i = nPitch; i<(int)dwBufLen; i += nPitch)
		{
			fProfile = (float)(pBuf[i] << 8 | pBuf[i + 1]);
			fProfile += pBuf[i+2]/64.0f;

			if(0>fProfile || nW<=fProfile)
				fProfile = 0;

			CUtil::StringFormat( szText, 128, _T("%f \r\n"), fProfile);
			::WriteFile(hFile, szText, CUtil::StringLength(szText), &dwResult, NULL);

			i+=8;
		}
	}

	::CloseHandle(hFile);
}


BOOL CUtil::SelectFile(const TCHAR* pLocation, TCHAR* pFilePath, int nLen, TCHAR* pszName, TCHAR* pszFilter, int* pnFilterIdx, BOOL bOpen)
{
    CFileDialog dlgFile(bOpen,
			NULL,
			pszName,
			OFN_HIDEREADONLY | OFN_NOCHANGEDIR,
			pszFilter);

    dlgFile.m_ofn.nFilterIndex = 0;
    dlgFile.m_ofn.lpstrInitialDir = pLocation; 
  
    if(IDCANCEL == dlgFile.DoModal())
	{
		return FALSE;
    }

	_tcscpy(pFilePath, (LPTSTR)(LPCTSTR)dlgFile.GetPathName());

	if (pnFilterIdx)
	{
		*pnFilterIdx = dlgFile.m_ofn.nFilterIndex;
	}

	return TRUE;
}


static int CALLBACK BrowseCallbackProc(	HWND hwnd,UINT uMsg, LPARAM lParam, LPARAM lpData)
{
	switch (uMsg)
	{
	case BFFM_INITIALIZED:
		{
			SendMessage(hwnd, BFFM_SETSELECTION, TRUE, (LPARAM)lpData );
		}
		break;
	}

	return 0; // Always return 0.
}

BOOL CUtil::SelectDirectory(TCHAR* pszPath, int nLen)
{
	if (NULL == pszPath)
		return FALSE;

	TCHAR cpath[MAX_TEXT_LEN] = _T("");

	TCHAR szLocation[MAX_TEXT_LEN] = _T("");
	CUtil::GetCurrentDirectory(szLocation, MAX_TEXT_LEN);

	LPITEMIDLIST pDirList;
	BROWSEINFO browseInfo;
	browseInfo.hwndOwner = NULL;
	browseInfo.pidlRoot = NULL;
	browseInfo.lpszTitle = _T("Select Directory");
	browseInfo.pszDisplayName = cpath;
	browseInfo.ulFlags = BIF_RETURNONLYFSDIRS | BIF_STATUSTEXT | BIF_VALIDATE;
	browseInfo.lpfn = BrowseCallbackProc;
	browseInfo.lParam = (LPARAM)szLocation;

	pDirList = SHBrowseForFolder(&browseInfo);
	if (pDirList == NULL)
		return FALSE;

	BOOL bResult = SHGetPathFromIDList(pDirList, cpath);
	if (bResult)
	{
		CUtil::StringCopy(pszPath, cpath);
	}

	return bResult;
}





// Registry
HKEY CUtil::CreateRegKey(const TCHAR* pSubKey)
{
	HKEY hKey = NULL;
	DWORD pos; 

	LONG result = ::RegCreateKeyEx( HKEY_CURRENT_USER,
		                            pSubKey,
									0,
									NULL,
									0,
									//KEY_ALL_ACCESS,
									KEY_READ | KEY_WRITE,
									NULL,
									&hKey,
									&pos);

	return hKey;
}

void CUtil::CloseRegKey(HKEY hKey)
{
	if (hKey)
		return;
	::RegCloseKey(hKey);
}

void CUtil::DeleteRegKey(const TCHAR* pSubKey)
{
	if (NULL == pSubKey)
		return;
	::SHDeleteKey(HKEY_CURRENT_USER, pSubKey);
}



BOOL CUtil::IsExistRegKey(const TCHAR* pSubKey)
{
	BOOL bExist = FALSE;

	HKEY hKey = NULL;
	DWORD pos;

	LONG result = ::RegCreateKeyEx(HKEY_CURRENT_USER,
		pSubKey,
		0,
		NULL,
		0,
		//KEY_ALL_ACCESS,
		KEY_READ,
		NULL,
		&hKey,
		&pos);
	if (S_OK == result && hKey)
	{
		bExist = TRUE;
	}

	CloseRegKey(hKey);

	return bExist;
}


BOOL CUtil::GetRegString(const TCHAR* pSubKey, const TCHAR* pValue, TCHAR* pString, int nLen)
{
	if(NULL==pSubKey || NULL==pValue)
		return FALSE;

	HKEY hKey = CreateRegKey(pSubKey);
	if(NULL==hKey)
		return FALSE;

	DWORD dwLen = sizeof(TCHAR)*nLen;

	DWORD dwType = REG_SZ;
	LONG result = ::RegQueryValueEx(hKey,
									pValue,
									NULL,
									&dwType,
									(LPBYTE)pString,
									&dwLen);

	CloseRegKey(hKey);

	if(ERROR_SUCCESS!=result || dwLen<1)
		return FALSE;

	return TRUE;
}


BOOL CUtil::SetRegString(const TCHAR* pSubKey, const TCHAR* pValue, TCHAR* pString)
{
	if(NULL==pSubKey || NULL==pValue)
		return FALSE;

	HKEY hKey = CreateRegKey(pSubKey);

	if(NULL==hKey)
		return FALSE;

	DWORD dwType = REG_SZ;
	LONG result = ::RegSetValueEx(hKey,
								  pValue,
								  0,
								  dwType,
								  (LPBYTE)pString,
								  sizeof(TCHAR)*(CUtil::StringLength(pString)));

	CloseRegKey(hKey);

	if(ERROR_SUCCESS!=result)
		return FALSE;

	return TRUE;
}

BOOL CUtil::GetRegDword(const TCHAR* pSubKey, const TCHAR* pValue, DWORD& value)
{
	if(NULL==pSubKey || NULL==pValue)
		return FALSE;

	HKEY hKey = CreateRegKey(pSubKey);
	if(NULL==hKey)
		return FALSE;

	DWORD dwLen = sizeof(value);

	DWORD dwType = REG_DWORD;
	LONG result = ::RegQueryValueEx(hKey,
									pValue,
									NULL,
									&dwType,
									(LPBYTE)&value,
									&dwLen);

	CloseRegKey(hKey);

	if(ERROR_SUCCESS!=result || dwLen<1)
		return FALSE;

	return TRUE;
}

BOOL CUtil::SetRegDword(const TCHAR* pSubKey, const TCHAR* pValue, const DWORD value)
{
	if(NULL==pSubKey || NULL==pValue)
		return FALSE;

	HKEY hKey = CreateRegKey(pSubKey);
	if(NULL==hKey)
		return FALSE;

	DWORD dwType = REG_DWORD;
	LONG result = ::RegSetValueEx(hKey,
								  pValue,
								  0,
								  dwType,
								  (LPBYTE)&value,
								  sizeof(value));

	CloseRegKey(hKey);

	if(ERROR_SUCCESS!=result)
		return FALSE;

	return TRUE;
}




// Time
BOOL CUtil::GetCurTime(DWORD* pdwYear, DWORD* pdwMonth, DWORD* pdwDay, DWORD* pdwHour, DWORD* pdwMinute, DWORD* pdwSec)
{
	if(NULL==pdwYear || NULL==pdwMonth || NULL==pdwDay || NULL==pdwHour || NULL==pdwMinute || NULL==pdwSec)
		return FALSE;

	SYSTEMTIME st;
	::GetLocalTime(&st);

	*pdwYear	= st.wYear;
	*pdwMonth	= st.wMonth;
	*pdwDay		= st.wDay;

	*pdwHour	= st.wHour;
	*pdwMinute	= st.wMinute;
	*pdwSec		= st.wSecond;

	return TRUE;
}


BOOL CUtil::GetCurTime(DWORD* pdwHour, DWORD* pdwMinute, DWORD* pdwSec)
{
	if(NULL==pdwHour || NULL==pdwMinute || NULL==pdwSec)
		return FALSE;

	SYSTEMTIME st;
	::GetLocalTime(&st);

	*pdwHour	= st.wHour;
	*pdwMinute	= st.wMinute;
	*pdwSec		= st.wSecond;


	return TRUE;
}

BOOL CUtil::GetCurTime(DWORD* pdwSec)
{
	if(NULL==pdwSec)
		return FALSE;

	DWORD dwHour = 0;
	DWORD dwMinute = 0;
	DWORD dwSec = 0;

	BOOL bResult = GetCurTime(&dwHour, &dwMinute, &dwSec );
	if(bResult)
	{
		*pdwSec = dwHour*60*60 + dwMinute*60 + dwSec;
	}

	return bResult;
}


// Sleep
void CUtil::Sleep(DWORD dwMsec)
{
	::Sleep(dwMsec);
}

void CUtil::WaitnSleep(DWORD dwMsec)
{
	DWORD dwStart = ::GetTickCount();
	
	do
	{
		MSG msg;
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			GetMessage(&msg, NULL, 0, 0);
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		CUtil::Sleep(1);

		DWORD dwCur = ::GetTickCount();
		if (dwMsec < (dwCur - dwStart))
			break;
	} while (1);
}


// Directory
BOOL CUtil::GetCurrentDirectory(TCHAR* pszPath, DWORD dwLen)
{
	if(NULL==pszPath)
		return FALSE;

	if(SUCCEEDED(::GetModuleFileName(NULL, pszPath, dwLen)))
	{
		TCHAR* pCh = _tcsrchr(pszPath, _T('\\'));
		if (pCh) *pCh = 0;
	}
	else
	{
		return FALSE;
	}

	return TRUE;
}


int __cdecl CompareDoubleAsc (const void *first, const void *second);
int __cdecl CompareDoubleDesc (const void *first, const void *second);

BOOL CUtil::Sort(double* pList, int nLen, BOOL bAsc)
{
	if(NULL==pList)
		return FALSE;

	if(bAsc)
		qsort(pList, nLen, sizeof(double), CompareDoubleAsc);
	else
		qsort(pList, nLen, sizeof(double), CompareDoubleDesc);

	return TRUE;;
}

int __cdecl CompareDoubleAsc (const void *first, const void *second)
{
    if (*(double*)first > *(double*)second)
        return 1;
    else if (*(double*)first < *(double*)second)
        return -1;

	return 0;
}

int __cdecl CompareDoubleDesc (const void *first, const void *second)
{
    if (*(double*)first > *(double*)second)
        return -1;
    else if (*(double*)first < *(double*)second)
        return 1;

	return 0;
}

BOOL CUtil::GetEthernetAdaptorList(DWORD* pIpAddress, int* pnLen)
{
	if(NULL==pIpAddress || NULL==pnLen)
		return FALSE;

	BOOL bResult = FALSE;

	TCHAR szName[128] = {0,};
	PHOSTENT pHostInfo = NULL;

	if( 0==gethostname ( szName, sizeof(szName)))
	{
		pHostInfo = gethostbyname(szName);
		if( NULL!=pHostInfo)
		{
			int i=0;
			for(i=0; pHostInfo->h_addr_list[i] && i<*pnLen ; i++)
			{
				pIpAddress[i] = *(DWORD*)pHostInfo->h_addr_list[i];
			}

			*pnLen = i;

			bResult = TRUE;
		}
	}

	return bResult;
}

int CUtil::GetEthernetAdaptorList(INFO_ETHERNET_ADAPTOR* pstInterface, int nLen)
{
	int nCount = 0;

	DWORD dwSize = 0;
	::GetAdaptersInfo(NULL, &dwSize);

	IP_ADAPTER_INFO* pstInfo = new IP_ADAPTER_INFO[dwSize];
	memset(pstInfo, 0x00, sizeof(IP_ADAPTER_INFO)*dwSize);
	::GetAdaptersInfo(pstInfo, &dwSize);

	IP_ADAPTER_INFO* pIdx = pstInfo;
	while(pIdx)
	{
		if (pstInterface && 0<nLen)
		{
			CUtil::StringCopy(pstInterface->m_szName, pIdx->Description);
			
			CUtil::StringCopy(pstInterface->m_szIpAddress, (char*) &(pIdx->IpAddressList.IpAddress));
			pstInterface->m_dwIpAddress = inet_addr( pstInterface->m_szIpAddress );

			pstInterface++;
		}

		pIdx = pIdx->Next;
		nCount++;
	}

	delete [] pstInfo;


	return nCount;
}


#define RGB2GRAY(r,g,b) (((b)*117 + (g)*601 + (r)*306) >> 10)

BOOL CUtil::LoadImageBuffer(const TCHAR* pszPath, BYTE* pBuffer, const DWORD dwLen,
							const DWORD dwX, const DWORD dwY, const DWORD dwWidth, const DWORD dwHeight, const BYTE nBit)
{
	if(NULL==pszPath || NULL==pBuffer )
		return FALSE;

	/*// Check image
	{
		TCHAR szPath[MAX_FILE_PATH_LEN] = {0,};
		CUtil::StringCopy(szPath, pszPath);
		CUtil::StringToUpper(szPath);

		int nLen = CUtil::StringLength(szPath);

		if ( CUtil::StringCompare(szPath+nLen-4, _T(".BMP")) ||
			 CUtil::StringCompare(szPath+nLen-4, _T(".JPG")) )
		{
			// do nothing...
			// just check image...
		}
		else
		{
			return FALSE;	// Not support
		}
	}
	//*/

	CImage image;
	HRESULT hResult = image.Load(pszPath);
	if (FAILED(hResult))
		return FALSE;

	const int nPitch = (int)(dwWidth * (nBit / 8.0));

	const int dwW = image.GetWidth();
	const int dwH = image.GetHeight();

	if (8 == nBit)
	{
		HDC hDC = ::GetDC(NULL);
		HDC hBmpDC = ::CreateCompatibleDC(hDC);
		void* pRaster = NULL;

		const int nColor = 256;
		BITMAPINFO*	pstBmpInfo = (BITMAPINFO*) new BYTE[ sizeof(BITMAPINFOHEADER) + sizeof(RGBQUAD)*nColor ];
		pstBmpInfo->bmiHeader.biClrUsed	= nColor;

		for(int i=0; i<nColor; i++)
		{
			pstBmpInfo->bmiColors[i].rgbBlue = i;
			pstBmpInfo->bmiColors[i].rgbGreen = i;
			pstBmpInfo->bmiColors[i].rgbRed = i;
			pstBmpInfo->bmiColors[i].rgbReserved = i;
		}

		pstBmpInfo->bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		pstBmpInfo->bmiHeader.biWidth = dwWidth;
		pstBmpInfo->bmiHeader.biHeight = -(int)dwHeight;
		pstBmpInfo->bmiHeader.biBitCount = nBit;
		pstBmpInfo->bmiHeader.biSizeImage = dwW * dwH * nBit / 8;
		pstBmpInfo->bmiHeader.biCompression = BI_RGB;
		pstBmpInfo->bmiHeader.biXPelsPerMeter = 0;
		pstBmpInfo->bmiHeader.biYPelsPerMeter = 0;
		pstBmpInfo->bmiHeader.biClrImportant = 0;
		pstBmpInfo->bmiHeader.biPlanes = 1;

		HBITMAP hBitmap = CreateDIBSection(hBmpDC, pstBmpInfo, DIB_RGB_COLORS, &pRaster, NULL, 0x0);
		HBITMAP hOldBmp = (HBITMAP)::SelectObject(hBmpDC, hBitmap);

		CBrush brush(RGB(0,0,0));
		HBRUSH hOldBrush = (HBRUSH)::SelectObject(hBmpDC, brush);

		::Rectangle(hBmpDC, 0, 0, dwW, dwH);
		image.BitBlt(hBmpDC, 0, 0, dwWidth, dwHeight, dwX, dwY, SRCCOPY);

		memcpy(pBuffer, pRaster, dwWidth*dwHeight*nBit / 8);

		::SelectObject(hBmpDC, hOldBmp);
		::DeleteObject(hBitmap);

		delete[] pstBmpInfo;

		::SelectObject(hBmpDC, hOldBrush);

		::DeleteDC(hBmpDC);
		::ReleaseDC(NULL, hDC);
	}

	
	return TRUE;
}

#ifdef DEF_USE_OPENCV
BOOL CUtil::LoadImageBuffer(const TCHAR* pszPath, BYTE** ppBuffer, DWORD* pdwLen, DWORD* pdwWidth, DWORD* pdwHeight, BYTE* pnBit)
{
	if (NULL == pszPath || NULL == ppBuffer || NULL == pdwLen || NULL == pdwWidth || NULL == pdwHeight || NULL == pnBit)
		return FALSE;

	/// Check image
	{
		TCHAR szPath[MAX_FILE_PATH_LEN] = { 0, };
		CUtil::StringCopy(szPath, pszPath);
		CUtil::StringToUpper(szPath);

		int nLen = 0;
		if (CUtil::StringReverseSearchChar(szPath, _T('.'), &nLen))
		{
			if (CUtil::StringCompare(szPath + nLen, _T(".BMP")) ||
				CUtil::StringCompare(szPath + nLen, _T(".JPG")) ||
				CUtil::StringCompare(szPath + nLen, _T(".JPEG")) ||
				CUtil::StringCompare(szPath + nLen, _T(".PNG")))
			{
				// do nothing...
				// just check image...
			}
			else
			{
				return FALSE;	// Not support
			}
		}
	}
	//*/

#if 1

#ifdef GREYSCALE
	IplImage* pcvImage = cvLoadImage(pszPath, CV_LOAD_IMAGE_GRAYSCALE);
#else
	IplImage* pcvImage = cvLoadImage(pszPath, CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR);
#endif
	if (NULL == pcvImage)
		return FALSE;

	*pdwWidth = pcvImage->width;
	*pdwHeight = pcvImage->height;
	*pnBit = pcvImage->nChannels*pcvImage->depth;		// 1 pixel, bitcount

	*pdwLen = (*pdwWidth) * (*pdwHeight) *  (*pnBit) / 8;
	*ppBuffer = new BYTE[*pdwLen];

	BYTE* pDest = *ppBuffer;
	BYTE* pSrc = (BYTE*) pcvImage->imageData;

	const int nPitch = (*pdwWidth) * (*pnBit) / 8;
	const int nSrcPitch = pcvImage->widthStep;

	for (int y = 0; y < (int)*pdwHeight; y++)
	{
		memcpy(pDest, pSrc, nPitch);
		pDest += nPitch;
		pSrc += nSrcPitch;
	}

	cvReleaseImage(&pcvImage);


#else
	CImage image;
	HRESULT hResult = image.Load(pszPath);
	if (FAILED(hResult))
		return FALSE;

	*pdwWidth = image.GetWidth();
	*pdwHeight = image.GetHeight();
	*pnBit = image.GetBPP();

	*pdwLen = (*pdwWidth) * (*pdwHeight) *  (*pnBit) / 8;
	*ppBuffer = new BYTE[*pdwLen];

	BYTE* pDest = *ppBuffer;
	BYTE* pSrc = (BYTE*)image.GetBits();


	const int nPitch = (*pdwWidth) * (*pnBit) / 8;
	const int nSrcPitch = image.GetPitch();

	for (int y = 0; y < *pdwHeight; y++)
	{
		memcpy(pDest, pSrc, nPitch);
		pDest += nPitch;
		pSrc += nSrcPitch;
	}
#endif

	return TRUE;
}

BOOL CUtil::WriteImageFromBuffer(const TCHAR* pszPath, BYTE* pBuffer, DWORD dwLen, DWORD dwWidth, DWORD dwHeight, BYTE nBit, int nPitch)
{
	if (NULL == pszPath || NULL == pBuffer )
		return FALSE;

	IplImage* pcvImage = cvCreateImage(cvSize(dwWidth, dwHeight), IPL_DEPTH_8U, nBit / 8);
	if (pcvImage)
	{
		BYTE* pSrc = pBuffer;
		BYTE* pDest = (BYTE*)pcvImage->imageData;

		const int nDestPitch = pcvImage->widthStep;
		const int nMinPitch = nDestPitch > nPitch ? nPitch : nDestPitch;

		for (int y = 0; y < (int)dwHeight; y++)
		{
			memcpy(pDest, pSrc, nMinPitch);
			pDest += nDestPitch;
			pSrc += nPitch;
		}

		cvSaveImage(pszPath, pcvImage);
		if (pcvImage)
			cvReleaseImage(&pcvImage);
	}
	else
	{
		return FALSE;
	}

	return TRUE;
}



BOOL CUtil::GetMaxImageSizeDir(const TCHAR* pszDirPath, int& width, int& height)
{
	if (NULL == pszDirPath)
		return FALSE;

	int w = 0;
	int h = 0;

	TCHAR szFilePath[MAX_FILE_PATH_LEN] = { 0, };
	TCHAR szTemp[MAX_FILE_PATH_LEN] = { 0, };

	CUtil::StringCopy(szTemp, pszDirPath);
	DWORD dwFileAttr = ::GetFileAttributes(pszDirPath);
	if (FILE_ATTRIBUTE_DIRECTORY == dwFileAttr)
	{
		int nLen = CUtil::StringLength(szTemp);
		if (_T('\\') == *(szTemp + nLen) || _T('/') == *(szTemp + nLen))
			*(szTemp + nLen) = 0;

		CUtil::StringFormat(szFilePath, MAX_FILE_PATH_LEN, _T("%s\\*.*"), szTemp);
	}
	else
	{
		TCHAR* pCh = _tcsrchr(szTemp, _T('\\'));
		if (pCh) *pCh = 0;

		CUtil::StringFormat(szFilePath, MAX_FILE_PATH_LEN, _T("%s\\*.*"), szTemp);
	}

	WIN32_FIND_DATA szFileData;
	HANDLE hSearch = ::FindFirstFile(szFilePath, &szFileData);
	if (INVALID_HANDLE_VALUE == hSearch)
		return FALSE;

	IplImage* pcvImage = NULL;

	do
	{
		if (FILE_ATTRIBUTE_ARCHIVE & szFileData.dwFileAttributes)
		{
			if (CUtil::IsEnableImageExt(szFileData.cFileName))
			{
				// Check image
				CUtil::StringFormat(szFilePath, MAX_FILE_PATH_LEN, _T("%s\\%s"), szTemp, szFileData.cFileName);
				CUtil::StringToUpper(szFilePath);

				pcvImage = cvLoadImage(szFilePath);
				if (NULL == pcvImage)
					continue;
				w = max(w, pcvImage->width);
				h = max(h, pcvImage->height);

				cvReleaseImage(&pcvImage);
			}
		}

	} while (::FindNextFile(hSearch, &szFileData));

	width = w;
	height = h;

	::FindClose(hSearch);
	return TRUE;
}

#else
BOOL CUtil::LoadImageBuffer(const TCHAR* pszPath, BYTE** ppBuffer, DWORD* pdwLen, DWORD* pdwWidth, DWORD* pdwHeight, BYTE* pnBit)
{
	if (NULL == pszPath || NULL == ppBuffer || NULL == pdwLen || NULL == pdwWidth || NULL == pdwHeight || NULL == pnBit)
		return FALSE;

	return FALSE;
}

BOOL CUtil::WriteImageFromBuffer(const TCHAR* pszPath, BYTE* pBuffer, DWORD dwLen, DWORD dwWidth, DWORD dwHeight, BYTE nBit, int nPitch)
{
	if (NULL == pszPath || NULL == pBuffer)
		return FALSE;

	return FALSE;
}

BOOL CUtil::GetMaxImageSizeDir(const TCHAR* pszDirPath, int& width, int& height)
{
	if (NULL == pszDirPath)
		return FALSE;

	return FALSE;
}

#endif




BOOL CUtil::IsEnableImageExt(const TCHAR* pszFileName)
{
	if (NULL == pszFileName)
		return FALSE;

	const TCHAR* pCh = _tcsrchr(pszFileName, _T('.'));
	if (pCh)
	{
		CString szExt;
		szExt.Format(_T("%s"), pCh + 1);
		szExt.MakeUpper();

		if (_T("BMP") == szExt ||
			_T("JPG") == szExt ||
			_T("PNG") == szExt)
		{
			return TRUE;
		}
	}
	return FALSE;
}

BOOL CUtil::IsBase64(unsigned char c)
{
	return (isalnum(c) || (c == '+') || (c == '/'));
}


static const std::string BASE64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

DWORD CUtil::EncodeBase64(const BYTE* pInput, const DWORD dwInput, BYTE* pOutput, DWORD& dwOutput)
{
	if (NULL == pInput || NULL == pOutput)
		return 0;

	BYTE pArray3[3] = { 0, 0, 0, };
	BYTE pArray4[4] = { 0, 0, 0, 0 };

	dwOutput = 0;

	DWORD dwIn = dwInput;
	int i = 0;
	int j = 0;
	int idx = 0;

	while (dwIn--)
	{
		pArray3[i] = *(pInput + idx);	i++; idx++;
		if (3 == i)
		{
			pArray4[0] = (pArray3[0] & 0xFC) >> 2;
			pArray4[1] = ((pArray3[0] & 0x03) << 4) + ((pArray3[1] & 0xF0) >> 4);
			pArray4[2] = ((pArray3[1] & 0x0F) << 2) + ((pArray3[2] & 0xC0) >> 6);
			pArray4[3] = pArray3[2] & 0x3F;

			for (i = 0; i < 4; i++)
			{
				pOutput[dwOutput] = BASE64[pArray4[i]];
				dwOutput++;
			}
			i = 0;
		}
	}

	if (i)
	{
		for (j = i; j < 3; j++)
		{
			pArray3[j] = '\0';
		}

		pArray4[0] = (pArray3[0] & 0xFC) >> 2;
		pArray4[1] = ((pArray3[0] & 0x03) << 4) + ((pArray3[1] & 0xF0) >> 4);
		pArray4[2] = ((pArray3[1] & 0x0F) << 2) + ((pArray3[2] & 0xC0) >> 6);
		pArray4[3] = pArray3[2] & 0x3F;

		for (j = 0; j < (i + 1); j++)
		{
			pOutput[dwOutput] = BASE64[pArray4[j]];
			dwOutput++;
		}

		while (i++ < 3)
		{
			pOutput[dwOutput] = '=';
			dwOutput++;
		}
	}

	return dwOutput;
}

DWORD CUtil::DecodeBase64(const BYTE* pInput, const DWORD dwInput, BYTE* pOutput, DWORD& dwOutput)
{
	if (NULL == pInput || NULL == pOutput)
		return 0;

	BYTE pArray3[3] = { 0, 0, 0, };
	BYTE pArray4[4] = { 0, 0, 0, 0 };

	dwOutput = 0;

	DWORD dwIn = dwInput;
	
	int nIn = 0;
	int i = 0;
	int j = 0;

	while (dwIn-- && (pInput[nIn] != '=') && CUtil::IsBase64(pInput[nIn]))
	{
		pArray4[i] = pInput[nIn]; i++; nIn++;
		if (4 == i)
		{
			for (i = 0; i < 4; i++)
			{
				pArray4[i] = static_cast<BYTE>(BASE64.find(pArray4[i]));
			}

			pArray3[0] = (pArray4[0] << 2) + ((pArray4[1] & 0x30) >> 4);
			pArray3[1] = ((pArray4[1] & 0x0F) << 4) + ((pArray4[2] & 0x3C) >> 2);
			pArray3[2] = ((pArray4[2] & 0x03) << 6) + pArray4[3];

			for (i = 0; i < 3; i++)
			{
				pOutput[dwOutput] = pArray3[i];
				dwOutput++;
			}
			i = 0;
		}
	}

	if (i)
	{
		for (j = i; j < 4; j++)
		{
			pArray4[j] = 0;
		}

		for (j = 0; j < 4; j++)
		{
			pArray4[j] = static_cast<BYTE>(BASE64.find(pArray4[j]));
		}

		pArray3[0] = (pArray4[0] << 2) + ((pArray4[1] & 0x30) >> 4);
		pArray3[1] = ((pArray4[1] & 0x0F) << 4) + ((pArray4[2] & 0x3C) >> 2);
		pArray3[2] = ((pArray4[2] & 0x03) << 6) + pArray4[3];

		for (j = 0; (j < i - 1); j++)
		{
			pOutput[dwOutput] = pArray3[j];
			dwOutput++;
		}
	}

	return dwOutput;

}

int CUtil::GetRadious(POINT pt1, POINT pt2)
{
	CSize sz = CPoint(pt1) - CPoint(pt2);
	const int r = (int)sqrt(pow((double)sz.cx, 2) + pow((double)sz.cy, 2));

	return r;
}

double CUtil::GetAngle(POINT pt1, POINT pt2, BOOL bDegree)
{
	const float VALUE_PI = (4.0f * atan(1.0f));

	CSize sz = CPoint(pt1) - CPoint(pt2);

	REAL phi = 0.0f;
	if (bDegree)
	{
		phi = 180.0f * atan2((REAL)sz.cy, (REAL)sz.cx) / (REAL)VALUE_PI;
		while (-180.0f >= phi)
		{
			phi += 360.0f;	// (-180, 180)
		}
	}
	else
	{
		phi = (REAL)atan2((REAL)sz.cy, (REAL)sz.cx);
	}

	return phi;
}

void CUtil::DisplayRangeMessage(HWND hWnd, const int nMin, const int nMax, BOOL bHex)
{
	TCHAR szMessage[1024] = { 0, };

	if(bHex)
		CUtil::StringFormat(szMessage, 1024, _T("Out of range...  (0x%X ~ 0x%X) "), nMin, nMax);
	else
		CUtil::StringFormat(szMessage, 1024, _T("Out of range...  (%d ~ %d) "), nMin, nMax);
	MessageBox(hWnd, szMessage, _T(""), MB_OK | MB_ICONWARNING);
}

void CUtil::DisplayRangeMessage(HWND hWnd, const float fMin, const float fMax)
{
	TCHAR szMessage[1024] = { 0, };
	CUtil::StringFormat(szMessage, 1024, _T("Out of range...  (%.4f ~ %.4f) "), fMin, fMax);
	MessageBox(hWnd, szMessage, _T(""), MB_OK | MB_ICONWARNING);
}





// Serial Port - Uart
int SearchSerialPort(LPCTSTR lpszEnumPath, INFO_SERIALPORT* pstInfo, const int nLen);

int CUtil::SearchSerialUart(INFO_SERIALPORT* pstSerialPort, int nPortLen)
{
	OSVERSIONINFO stOsInfo;
	memset(&stOsInfo, 0x00, sizeof(OSVERSIONINFO));
	stOsInfo.dwOSVersionInfoSize = sizeof(stOsInfo);

	::GetVersionEx(&stOsInfo);

	int nCount = 0;
	if (VER_PLATFORM_WIN32_WINDOWS == stOsInfo.dwPlatformId)
	{
		nCount = SearchSerialPort(_T("ENUM"), pstSerialPort, nPortLen);
	}
	else if (VER_PLATFORM_WIN32_NT == stOsInfo.dwPlatformId)
	{
		nCount = SearchSerialPort(_T("SYSTEM\\CURRENTCONTROLSET\\ENUM"), pstSerialPort, nPortLen);
	}
	return nCount;
}


LONG OpenSubKeyByIndex(HKEY hKey, DWORD dwIndex, REGSAM samDesired, PHKEY phkResult, LPTSTR* lppSubKeyName);
LONG QueryStringValue(HKEY hKey, LPCTSTR lpValueName, LPTSTR* lppStringValue);

int SearchSerialPort(LPCTSTR lpszEnumPath, INFO_SERIALPORT* pstInfo, const int nLen)
{
	static const TCHAR lpszPortsClass[] = TEXT("PORTS");
	static const TCHAR lpszPortsClassGUID[] = TEXT("{4D36E978-E325-11CE-BFC1-08002BE10318}");

	HKEY	hkEnum = NULL;
	HKEY	hkEnumDepth1 = NULL;
	HKEY	hkEnumDepth2 = NULL;
	HKEY	hkEnumDepth3 = NULL;

	HKEY	hkDevice = NULL;

	DWORD	dwDepth1 = 0;
	DWORD	dwDepth2 = 0;
	DWORD	dwDepth3 = 0;

	LPTSTR	lpszPortName = NULL;
	LPTSTR	lpszFriendlyName = NULL;
	LPTSTR	lpszTechnology = NULL;

	BOOL	bFoundFriendlyName = FALSE;

	TCHAR  lpszClass[sizeof(lpszPortsClass) / sizeof(lpszPortsClass[0])];
	DWORD  dwClassLen = 0;
	TCHAR  lpszClassGUID[sizeof(lpszPortsClassGUID) / sizeof(lpszPortsClassGUID[0])];
	DWORD  dwClassGUIDLen = 0;

	DWORD	dwResult = ERROR_SUCCESS;

	int nCount = 0;

	if (ERROR_SUCCESS != ::RegOpenKeyEx(HKEY_LOCAL_MACHINE, lpszEnumPath, 0, KEY_ENUMERATE_SUB_KEYS, &hkEnum))
	{
		return 0;
	}

	// Loop First
	for (dwDepth1 = 0; ERROR_SUCCESS == dwResult; dwDepth1++)
	{
		if (NULL != hkEnumDepth1)
		{
			::RegCloseKey(hkEnumDepth1);
			hkEnumDepth1 = NULL;
		}

		dwResult = OpenSubKeyByIndex(hkEnum, dwDepth1, KEY_ENUMERATE_SUB_KEYS, &hkEnumDepth1, &lpszTechnology);
		if (ERROR_SUCCESS != dwResult)
		{
			if (ERROR_NO_MORE_ITEMS == dwResult)
			{
				dwResult = ERROR_SUCCESS;
				break;
			}
			else
			{
				dwResult = ERROR_INVALID_DATA;
				continue;
			}
		}

		// Loop Second
		for (dwDepth2 = 0; ERROR_SUCCESS == dwResult; dwDepth2++)
		{
			if (NULL != hkEnumDepth2)
			{
				::RegCloseKey(hkEnumDepth2);
				hkEnumDepth2 = NULL;
			}

			dwResult = OpenSubKeyByIndex(hkEnumDepth1, dwDepth2, KEY_ENUMERATE_SUB_KEYS, &hkEnumDepth2, NULL);
			if (ERROR_SUCCESS != dwResult)
			{
				if (ERROR_NO_MORE_ITEMS == dwResult)
				{
					dwResult = ERROR_SUCCESS;
					break;
				}
				else
				{
					dwResult = ERROR_INVALID_DATA;
					continue;
				}
			}

			// Loop Third
			for (dwDepth3 = 0; ERROR_SUCCESS == dwResult; dwDepth3++)
			{
				if (NULL != hkEnumDepth3)
				{
					::RegCloseKey(hkEnumDepth3);
					hkEnumDepth3 = NULL;
				}

				dwResult = OpenSubKeyByIndex(hkEnumDepth2, dwDepth3, KEY_READ, &hkEnumDepth3, NULL);
				if (ERROR_SUCCESS != dwResult)
				{
					if (ERROR_NO_MORE_ITEMS == dwResult)
					{
						dwResult = ERROR_SUCCESS;
						break;
					}
					else
					{
						dwResult = ERROR_INVALID_DATA;
						continue;
					}
				}

				dwClassLen = sizeof(lpszClass);
				if (ERROR_SUCCESS == ::RegQueryValueEx(hkEnumDepth3, TEXT("CLASS"), NULL, NULL, (LPBYTE)lpszClass, &dwClassLen)
					&& 0 == _tcsicmp(lpszPortsClass, lpszClass))
				{
					// success
				}
				else
				{
					dwClassGUIDLen = sizeof(lpszClassGUID);
					if (ERROR_SUCCESS == ::RegQueryValueEx(hkEnumDepth3, TEXT("CLASSGUID"), NULL, NULL, (LPBYTE)lpszClassGUID, &dwClassGUIDLen) &&
						0 == _tcsicmp(lpszPortsClassGUID, lpszClassGUID))
					{
					}
					else
					{
						dwResult = ERROR_SUCCESS;
						continue;
					}
				}

				// Search Port name
				dwResult = QueryStringValue(hkEnumDepth3, TEXT("PORTNAME"), &lpszPortName);
				if (ERROR_FILE_NOT_FOUND == dwResult)
				{
					if (NULL != hkDevice)
					{
						::RegCloseKey(hkDevice);
						hkDevice = NULL;
					}

					if (ERROR_SUCCESS == ::RegOpenKeyEx(hkEnumDepth3, TEXT("DEVICE PARAMETERS"), 0, KEY_READ, &hkDevice))
					{
						dwResult = QueryStringValue(hkDevice, TEXT("PORTNAME"), &lpszPortName);
					}
				}

				if (ERROR_SUCCESS != dwResult)
				{
					if (ERROR_FILE_NOT_FOUND == dwResult)
					{
						dwResult = ERROR_SUCCESS;
					}
					else
					{
						dwResult = ERROR_INVALID_DATA;
						continue;
					}
				}

				if (0 != _tcsncicmp(lpszPortName, TEXT("COM"), 3))
					continue;

				// Search Friendly name
				dwResult = QueryStringValue(hkEnumDepth3, TEXT("FRIENDLYNAME"), &lpszFriendlyName);
				if (ERROR_SUCCESS == dwResult)
				{
					bFoundFriendlyName = TRUE;
				}
				else if (ERROR_FILE_NOT_FOUND == dwResult)
				{
					bFoundFriendlyName = FALSE;
					dwResult = ERROR_SUCCESS;
				}
				else
				{
					dwResult = ERROR_INVALID_DATA;
					continue;
				}

				if (pstInfo && nLen>nCount)
				{
					_tcscpy(pstInfo[nCount].m_szPortName, lpszPortName);
					if (bFoundFriendlyName)
						_tcscpy(pstInfo[nCount].m_szFriendlyName, lpszFriendlyName);
					else
						_tcscpy(pstInfo[nCount].m_szFriendlyName, lpszPortName);

					_tcscpy(pstInfo[nCount].m_szTechnology, lpszTechnology);
				}

				// Check serial port
				HRESULT lRes = S_FALSE;
				{
					TCHAR szPort[MAX_UTIL_NAME_LEN] = { 0, };
					_stprintf(szPort, _T("\\\\.\\%s"), lpszPortName);

					HANDLE hFile = ::CreateFile(szPort, GENERIC_READ | GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
					lRes = ::GetLastError();

					::CloseHandle(hFile);
				}
				if (ERROR_SUCCESS == lRes || ERROR_ACCESS_DENIED == lRes)
					nCount++;
			}
		}
	}

	if (lpszTechnology)
		free(lpszTechnology);
	if (lpszFriendlyName)
		free(lpszFriendlyName);
	if (lpszPortName)
		free(lpszPortName);

	if (hkDevice)
		::RegCloseKey(hkDevice);
	if (hkEnumDepth3)
		::RegCloseKey(hkEnumDepth3);
	if (hkEnumDepth2)
		::RegCloseKey(hkEnumDepth2);
	if (hkEnumDepth1)
		::RegCloseKey(hkEnumDepth1);
	if (hkEnum)
		::RegCloseKey(hkEnum);

	if (ERROR_SUCCESS != dwResult)
	{
		::SetLastError(dwResult);
		nCount = -1;
	}
	return nCount;
}


LONG OpenSubKeyByIndex(HKEY hKey, DWORD dwIndex, REGSAM samDesired, PHKEY phkResult, LPTSTR* lppSubKeyName)
{
	DWORD dwError = 0;
	BOOL bLocalSubkeyName = FALSE;
	LPTSTR lpSubkeyName = NULL;
	DWORD cbSubkeyName = 128 * sizeof(TCHAR); /* an initial guess */
	FILETIME filetime;

	if (lppSubKeyName == NULL)
	{
		bLocalSubkeyName = TRUE;
		lppSubKeyName = &lpSubkeyName;
	}
	/* loop asking for the subkey name til we allocated enough memory */

	for (;;)
	{
		free(*lppSubKeyName);
		if (!(*lppSubKeyName = (LPTSTR)malloc(cbSubkeyName)))
		{
			dwError = ERROR_NOT_ENOUGH_MEMORY;
			goto end;
		}
		if (!(dwError = RegEnumKeyEx(hKey, dwIndex, *lppSubKeyName, &cbSubkeyName,
			0, NULL, NULL, &filetime)))
		{
			break; /* we did it */
		}
		else if (dwError == ERROR_MORE_DATA)
		{ /* not enough space */
			dwError = 0;
			/* no indication of space required, we try doubling */
			cbSubkeyName = (cbSubkeyName + sizeof(TCHAR)) * 2;
		}
		else goto end;
	}

	dwError = RegOpenKeyEx(hKey, *lppSubKeyName, 0, samDesired, phkResult);
end:
	if (bLocalSubkeyName)
		free(*lppSubKeyName);

	return dwError;
}

LONG QueryStringValue(HKEY hKey, LPCTSTR lpValueName, LPTSTR* lppStringValue)
{
	DWORD cbStringValue = 128 * sizeof(TCHAR); /* an initial guess */
	for (;;)
	{
		DWORD dwError = 0;

		free(*lppStringValue);
		if (!(*lppStringValue = (LPTSTR)malloc(cbStringValue)))
		{
			return ERROR_NOT_ENOUGH_MEMORY;
		}
		if (!(dwError = RegQueryValueEx(hKey, lpValueName, NULL, NULL, (LPBYTE)*lppStringValue, &cbStringValue)))
		{
			return ERROR_SUCCESS;
		}
		else if (dwError == ERROR_MORE_DATA)
		{
			/* not enough space, keep looping */
		}
		else
		{
			return dwError;
		}
	}
}
