#include "StdAfx.h"
#include "CameraBasler.h"

#include "inc/PixelFormat.h"
#include "Util/Util.h"


#include <pylon/PylonIncludes.h>

CCameraBasler::CCameraBasler()
{
	::InitializeCriticalSection(&m_CriticalSection);

	m_pFuncAcq = NULL;
	m_pstUserData = NULL;

	m_bStarted = FALSE;

	// Thread
	m_hThreadBasler = NULL;
	m_hEventBaslerStop = NULL;
	m_bStopBasler = FALSE;
	m_bSuspend = TRUE;


	// Basler
	m_pPylonDevice = NULL;
	m_pInstanceCamera = NULL;
	m_pRootCategory = NULL;
}

CCameraBasler::~CCameraBasler()
{
	Stop();
	::DeleteCriticalSection(&m_CriticalSection);

	Close();
}

BOOL CCameraBasler::Open(Pylon::IPylonDevice* pDevice)
{
	if (NULL == pDevice)
		return FALSE;
	//Close();

	// Get TriggerMode: On or Off
	int nMode = -1;
	{
		try
		{
			pDevice->Open();
			GenApi::CEnumerationPtr value(pDevice->GetNodeMap()->GetNode(_T("TriggerMode")));
			nMode = (int)value->GetIntValue();
			pDevice->Close();
		}
		catch (const GenericException &e)
		{
			CUtil::PrintDebugString(_T("[BASLER] %s \r\n"), e.GetDescription());
		}
	}
	
	m_pPylonDevice = pDevice;
	m_pInstanceCamera = new Pylon::CInstantCamera();
	m_pInstanceCamera->Attach(pDevice);
	//m_pInstanceCamera->RegisterConfiguration(new Pylon::CSoftwareTriggerConfiguration, Pylon::RegistrationMode_ReplaceAll, Pylon::Cleanup_Delete);
	m_pInstanceCamera->Open();


	///
	if (m_pRootCategory)
	{
		ClearCategory(m_pRootCategory);

		delete m_pRootCategory;
		m_pRootCategory = NULL;
	}
	m_pRootCategory = new INFO_OTHER_CATEGORY;
	memset(m_pRootCategory, 0x00, sizeof(INFO_OTHER_CATEGORY));

	m_pRootCategory->m_stInterface.m_eInterface = TYPE_OTHER_INTERFACE_CATEGORY;
	m_pRootCategory->m_stInterface.m_dwAccess = OTHER_OPCODE_READ | OTHER_OPCODE_WRITE;
	m_pRootCategory->m_stInterface.m_pszName = new TCHAR[16];
	m_pRootCategory->m_stInterface.m_pszDisplayName = new TCHAR[16];

	CUtil::StringFormat(m_pRootCategory->m_stInterface.m_pszName, 16, _T("Root"));
	CUtil::StringFormat(m_pRootCategory->m_stInterface.m_pszDisplayName, 16, _T("Root"));


	// Set TriggerMode: On or Off
	if (-1 < nMode)
	{
		try
		{
			GenApi::CEnumerationPtr value(m_pInstanceCamera->GetNodeMap().GetNode(_T("TriggerMode")));
			value->SetIntValue(nMode);
		}
		catch (const GenericException &e)
		{
			CUtil::PrintDebugString(_T("[BASLER] %s \r\n"), e.GetDescription());
		}
	}

	LoadCategory(m_pRootCategory);
	//*/

	return TRUE;
}

void CCameraBasler::Close()
{
	m_pPylonDevice = NULL;
	if (m_pInstanceCamera)
	{
		m_pInstanceCamera->Close();

		delete m_pInstanceCamera;
		m_pInstanceCamera = NULL;
	}

	if (m_pRootCategory)
	{
		ClearCategory(m_pRootCategory);
		
		delete m_pRootCategory;
		m_pRootCategory = NULL;

		//_CrtDumpMemoryLeaks();
	}
	
}

BOOL CCameraBasler::IsStart()
{
	return m_bStarted;
}

BOOL CCameraBasler::Start()
{
	if (TRUE == IsStart())
		return TRUE;
	if (NULL == m_pPylonDevice)
		return FALSE;

	// Basler SDK
	{
		try
		{
			m_pInstanceCamera->StartGrabbing();

			CUtil::PrintDebugString(_T("[BASLER] Start \r\n"));
		}
		catch (const GenericException &e)
		{
			CUtil::PrintDebugString(_T("[BASLER] %s \r\n"), e.GetDescription());
			return FALSE;
		}
		UpdateCategory(m_pRootCategory);
	}

	// Create Thread
	{
		m_bStopBasler = FALSE;
		m_bSuspend = FALSE;
		m_bStarted = TRUE;

		m_hEventBaslerStop = ::CreateEvent(0, TRUE, FALSE, 0);
		if (NULL == m_hEventBaslerStop)
		{
			Stop();
			return FALSE;
		}
		DWORD dwThreadId = 0;
		m_hThreadBasler = ::CreateThread(0, 0, ThreadBaslerProc, LPVOID(this), 0, &dwThreadId);
	}
	return TRUE;
}
void CCameraBasler::Stop()
{
	if (FALSE == IsStart())
		return;
	if (NULL == m_pPylonDevice)
		return;

	m_bStopBasler = TRUE;
	m_bSuspend = TRUE;
	m_bStarted = FALSE;

	// Basler SDK
	{
		try
		{
			m_pInstanceCamera->StopGrabbing();
			CUtil::PrintDebugString(_T("[BASLER] Stop\r\n"));
		}
		catch (const GenericException &e)
		{
			CUtil::PrintDebugString(_T("[BASLER] %s \r\n"), e.GetDescription());
			return;
		}
		UpdateCategory(m_pRootCategory);
	}

	if (m_hEventBaslerStop)
	{
		::ResetEvent(m_hEventBaslerStop);
		::WaitForSingleObject(m_hEventBaslerStop, 3000);

		::CloseHandle(m_hEventBaslerStop);
	}

	if (m_hThreadBasler)
	{
		::CloseHandle(m_hThreadBasler);
	}

	m_hThreadBasler = NULL;
	m_hEventBaslerStop = NULL;
}

BOOL CCameraBasler::IsGigE()
{
	BOOL bValue = FALSE;
	if (m_pInstanceCamera)
	{
		bValue = m_pInstanceCamera->IsGigE();
	}
	return bValue;
}

BOOL CCameraBasler::IsUsb()
{
	BOOL bValue = FALSE;
	if (m_pInstanceCamera)
	{
		bValue = m_pInstanceCamera->IsUsb();
	}
	return bValue;
}

const DWORD CCameraBasler::GetIpAddress()
{
	DWORD dwIpAddr = 0;
	if (m_pPylonDevice)
	{
		const Pylon::CDeviceInfo& devInfo = m_pPylonDevice->GetDeviceInfo();
		Pylon::String_t szFullName = devInfo.GetFullName();

		int nPos = 0;
		if (CUtil::StringReverseSearchChar((TCHAR*)szFullName.c_str(), _T('#'), &nPos))
		{
			TCHAR szString[128] = { 0, };
			CUtil::StringCopy(szString, ((TCHAR*)szFullName.c_str() + nPos + 1));

			BYTE addr[4] = { 0, };
			int idx = 0;
			int start = 0;

			int nLen = CUtil::StringLength(szString);
			for (int i = 0; i < nLen; i++)
			{
				if (0==isdigit(szString[i]))
				{
					if (4 <= idx)
						return 0;

					szString[i] = 0;
					addr[idx] = CUtil::StringToByte(szString + start, CUtil::StringLength(szString + start));	idx++;

					i++;
					start = i;
				}
			}
			dwIpAddr = addr[0] << 24 | addr[1] << 16 | addr[2] << 8 | addr[3];
		}
	}
	return dwIpAddr;
}


BOOL CCameraBasler::SetEventFunc(FuncAcquisitionEvent pFunc, void* pUserData)
{
	m_pFuncAcq = pFunc;
	m_pstUserData = pUserData;
	return TRUE;
}

DWORD CCameraBasler::ThreadBaslerProc(LPVOID lpArg)
{
	CCameraBasler* pBasler = (CCameraBasler*)lpArg;
	return pBasler->ThreadBaslerProc();
}
DWORD CCameraBasler::ThreadBaslerProc(void)
{
	Pylon::CGrabResultPtr ptrGrabResult;

	BOOL bAcq = FALSE;
	do
	{
		try
		{
			bAcq = FALSE;
			if (m_pInstanceCamera)
			{
				bAcq = m_pInstanceCamera->RetrieveResult(MAX_TIMEOUT_MSEC, ptrGrabResult, Pylon::TimeoutHandling_ThrowException);
			}

			// Set Acquisition...
			if (bAcq && FALSE == m_bSuspend && m_pFuncAcq)
			{
				DWORD dwPixelFormat = ptrGrabResult->GetPixelType();
				int w = ptrGrabResult->GetWidth();
				int h = ptrGrabResult->GetHeight();
				int bit = ((dwPixelFormat >> 16) & 0xFF);

				(*m_pFuncAcq)((BYTE*)ptrGrabResult->GetBuffer(), w * h * bit / 8, NULL, m_pstUserData);
				//CUtil::PrintDebugString(_T(" basler acq... \r\n"));
			}

		}
		catch (const GenericException &e)
		{
			//CUtil::PrintDebugString(_T("[BASLER] %s \r\n"), e.GetDescription());
		}
		CUtil::WaitnSleep(1);

	} while (FALSE == m_bStopBasler);

	if (m_hEventBaslerStop)
		SetEvent(m_hEventBaslerStop);

	return 0;
}


// Print
void CCameraBasler::PrintInterface(GenApi::EInterfaceType eIfType)
{
	if (GenApi::intfIValue == eIfType)					CUtil::PrintDebugString(_T(" intfIValue \r\n"));
	else if (GenApi::intfIBase == eIfType)				CUtil::PrintDebugString(_T(" intfIBase \r\n"));
	else if (GenApi::intfIInteger == eIfType)			CUtil::PrintDebugString(_T(" intfIInteger \r\n"));
	else if (GenApi::intfIBoolean == eIfType)			CUtil::PrintDebugString(_T(" intfIBoolean \r\n"));
	else if (GenApi::intfICommand == eIfType)			CUtil::PrintDebugString(_T(" intfICommand \r\n"));
	else if (GenApi::intfIFloat == eIfType)				CUtil::PrintDebugString(_T(" intfIFloat \r\n"));
	else if (GenApi::intfIString == eIfType)			CUtil::PrintDebugString(_T(" intfIString \r\n"));
	else if (GenApi::intfIRegister == eIfType)			CUtil::PrintDebugString(_T(" intfIRegister \r\n"));
	else if (GenApi::intfICategory == eIfType)			CUtil::PrintDebugString(_T(" intfICategory \r\n"));
	else if (GenApi::intfIEnumeration == eIfType)		CUtil::PrintDebugString(_T(" intfIEnumeration \r\n"));
	else if (GenApi::intfIEnumEntry == eIfType)			CUtil::PrintDebugString(_T(" intfIEnumEntry \r\n"));
	else if (GenApi::intfIPort == eIfType)				CUtil::PrintDebugString(_T(" intfIPort \r\n"));
}


// Load
void CCameraBasler::LoadCategory(INFO_OTHER_CATEGORY* pstInfo)
{
	if (NULL == m_pInstanceCamera || NULL == pstInfo)
		return;
	
	const GenApi::INodeMap& iNodeMap = m_pInstanceCamera->GetNodeMap();
	GenApi::INode* piNode = iNodeMap.GetNode(_T("Root"));

	GenApi::NodeList_t children;
	piNode->GetChildren(children);

	int nSize = (int)children.size();
	for (int i = 0; i < nSize; i++)
	{
		GenApi::INode* piChild = children.at(i);
		if (false == GenApi::IsAvailable(piChild->GetAccessMode()))
			continue;

		GenApi::EVisibility eVisible = piChild->GetVisibility();
		if (GenApi::Beginner == eVisible || GenApi::Expert == eVisible || GenApi::Guru == eVisible)
		{
			CUtil::PrintDebugString(_T("Category %d. %s (%s) "), i, children.at(i)->GetName().c_str(), children.at(i)->GetDisplayName().c_str());
			//CUtil::PrintDebugString(_T(" beginner "));

			GenApi::EInterfaceType eIfType = piChild->GetPrincipalInterfaceType();
			PrintInterface(eIfType);

			if (GenApi::intfICategory == eIfType)
			{
				INFO_OTHER_CATEGORY* pstCategory = new INFO_OTHER_CATEGORY;
				memset(pstCategory, 0x00, sizeof(INFO_OTHER_CATEGORY));

				LoadICategory(piChild, pstCategory);

				if (TYPE_OTHER_INTERFACE_CATEGORY == pstCategory->m_stInterface.m_eInterface)
				{
					pstInfo->m_pListInterface[pstInfo->m_nListLen] = (INFO_OTHER_IF*)pstCategory;
					pstInfo->m_nListLen++;
				}
				else
				{
					ClearCategory(pstCategory);
					delete pstCategory;
				}
			}
			else
			{
				continue;
			}

		}
		/*//
		else if (GenApi::Expert == eVisible)
		{
			CUtil::PrintDebugString(_T(" Expert \r\n"));
		}
		else if (GenApi::Guru == eVisible)
		{
			CUtil::PrintDebugString(_T(" Guru \r\n"));
		}
		else if (GenApi::Invisible == eVisible)
		{
			CUtil::PrintDebugString(_T(" Invisible \r\n"));
		}
		else
		{
			CUtil::PrintDebugString(_T(" undefined \r\n"));
		}
		//*/
		
	}

}

void CCameraBasler::LoadIValue(GenApi::INode* piChild)
{
	if (NULL == piChild)
		return;
}

void CCameraBasler::LoadIBase(GenApi::INode* piChild)
{
	if (NULL == piChild)
		return;
}

void CCameraBasler::LoadIInteger(GenApi::INode* piChild, INFO_OTHER_INTEGER* pstInfo)
{
	if (NULL == piChild || NULL == pstInfo)
		return;
	if (false == GenApi::IsAvailable(piChild->GetAccessMode()))
		return;

	// Load information
	LoadInterface(piChild, TYPE_OTHER_INTERFACE_INTEGER, &pstInfo->m_stInterface);


	GenApi::IInteger* pInteger = dynamic_cast<GenApi::IInteger *>(piChild);
	int nMin = 0;
	int nMax = 0;
	if (GenApi::RO != pInteger->GetAccessMode())
	{
		nMin = (int)pInteger->GetMin();
		nMax = (int)pInteger->GetMax();
	}
	
	GenApi::EIncMode eIncMode = pInteger->GetIncMode();
	int nInc = 0;
	if (GenApi::fixedIncrement == eIncMode)
	{
		nInc = (int)pInteger->GetInc();
	}
	else if (GenApi::listIncrement == eIncMode)
	{
		nInc = (int)pInteger->GetInc();
	}
	else// if (noIncrement == eIncMode)
	{
		// do nothing;
	}
	int nCur = (int)pInteger->GetValue();

	
	pstInfo->m_nMin = nMin;
	pstInfo->m_nMax = nMax;
	pstInfo->m_nInc = nInc;
	pstInfo->m_nCur = nCur;

	CUtil::PrintDebugString(_T("     Cur(%d)   min(%d) max(%d) inc(%d) \r\n"), nCur, nMin, nMax, nInc );

}

void CCameraBasler::LoadIBoolean(GenApi::INode* piChild, INFO_OTHER_BOOLEAN* pstInfo)
{
	if (NULL == piChild || NULL == pstInfo)
		return;
	if (false == GenApi::IsAvailable(piChild->GetAccessMode()))
		return;

	// Load information
	LoadInterface(piChild, TYPE_OTHER_INTERFACE_BOOLEAN, &pstInfo->m_stInterface);

	GenApi::IBoolean* pBoolean = dynamic_cast<GenApi::IBoolean *>(piChild);
	bool bCur = pBoolean->GetValue();

	pstInfo->m_bCur = bCur;

	CUtil::PrintDebugString(_T("     Cur(%d) \r\n"), bCur);

}

void CCameraBasler::LoadICommand(GenApi::INode* piChild, INFO_OTHER_COMMAND* pstInfo)
{
	if (NULL == piChild)
		return;
	if (false == GenApi::IsAvailable(piChild->GetAccessMode()))
		return;

	// Load information
	LoadInterface(piChild, TYPE_OTHER_INTERFACE_COMMAND, &pstInfo->m_stInterface);

	GenApi::ICommand* pCommand = dynamic_cast<GenApi::ICommand *>(piChild);


}

void CCameraBasler::LoadIFloat(GenApi::INode* piChild, INFO_OTHER_FLOAT* pstInfo)
{
	if (NULL == piChild || NULL == pstInfo)
		return;
	if (false == GenApi::IsAvailable(piChild->GetAccessMode()))
		return;

	// Load information
	LoadInterface(piChild, TYPE_OTHER_INTERFACE_FLOAT, &pstInfo->m_stInterface);


	GenApi::IFloat* pFloat = dynamic_cast<GenApi::IFloat *>(piChild);
	double fMin = 0;
	double fMax = 0;
	if (GenApi::RO != pFloat->GetAccessMode())
	{
		fMin = pFloat->GetMin();
		fMax = pFloat->GetMax();
	}

	GenApi::EIncMode eIncMode = pFloat->GetIncMode();
	double fInc = 0;
	if (GenApi::fixedIncrement == eIncMode)
	{
		fInc = pFloat->GetInc();
	}
	else if (GenApi::listIncrement == eIncMode)
	{
		fInc = pFloat->GetInc();
	}
	else// if (noIncrement == eIncMode)
	{
		// do nothing;
	}
	double fCur = pFloat->GetValue();


	pstInfo->m_fMin = fMin;
	pstInfo->m_fMax = fMax;
	pstInfo->m_fInc = fInc;
	pstInfo->m_fCur = fCur;

	CUtil::PrintDebugString(_T("     Cur(%lf)   min(%lf) max(%lf) inc(%lf) \r\n"), fCur, fMin, fMax, fInc);

}

void CCameraBasler::LoadIString(GenApi::INode* piChild, INFO_OTHER_STRING* pstInfo)
{
	if (NULL == piChild || NULL == pstInfo)
		return;
	if (false == GenApi::IsAvailable(piChild->GetAccessMode()))
		return;

	// Load information
	LoadInterface(piChild, TYPE_OTHER_INTERFACE_STRING, &pstInfo->m_stInterface);

	GenApi::IString* pString = dynamic_cast<GenApi::IString *>(piChild);

	int nLen = (int)pString->GetValue().length() + 1;
	pstInfo->m_pString = new TCHAR[nLen];
	CUtil::StringFormat(pstInfo->m_pString, nLen, _T("%s"), pString->GetValue().c_str());

	CUtil::PrintDebugString(_T("     %s \r\n"), pstInfo->m_pString);
}

void CCameraBasler::LoadIRegister(GenApi::INode* piChild)
{
	if (NULL == piChild)
		return;
}

void CCameraBasler::LoadICategory(GenApi::INode* piChild, INFO_OTHER_CATEGORY* pstCategoty)
{
	if (NULL == piChild || NULL == pstCategoty)
		return;
	if (false == GenApi::IsAvailable(piChild->GetAccessMode()))
		return;

	// Load information
	LoadInterface(piChild, TYPE_OTHER_INTERFACE_CATEGORY, &pstCategoty->m_stInterface);


	GenApi::NodeList_t children;
	piChild->GetChildren(children);
	int nSize = (int) children.size();

	for (int i = 0; i < nSize; i++)
	{
		GenApi::INode* piChild = children.at(i);
		if (false == GenApi::IsAvailable(piChild->GetAccessMode()))
			continue;

		GenApi::EVisibility eVisible = piChild->GetVisibility();
		if (GenApi::Beginner == eVisible || GenApi::Expert == eVisible || GenApi::Guru == eVisible)
		{
			CUtil::PrintDebugString(_T("%d. %s (%s) "), i, piChild->GetName().c_str(), piChild->GetDisplayName().c_str());
			//CUtil::PrintDebugString(_T(" beginner "));

			GenApi::EInterfaceType eIfType = piChild->GetPrincipalInterfaceType();
			PrintInterface(eIfType);


			INFO_OTHER_IF* pstInfo = NULL;
			TYPE_OTHER_INTERFACE eType = TYPE_OTHER_INTERFACE_NONE;

			if (GenApi::intfIValue == eIfType)
			{
				LoadIValue(piChild);
			}
			else if (GenApi::intfIBase == eIfType)
			{
				LoadIBase(piChild);
			}
			else if (GenApi::intfIInteger == eIfType)
			{
				eType = TYPE_OTHER_INTERFACE_INTEGER;

				pstInfo = (INFO_OTHER_IF*) new INFO_OTHER_INTEGER;
				memset(pstInfo, 0x00, sizeof(INFO_OTHER_INTEGER));

				LoadIInteger(piChild, (INFO_OTHER_INTEGER*)pstInfo);
			}
			else if (GenApi::intfIBoolean == eIfType)
			{
				eType = TYPE_OTHER_INTERFACE_BOOLEAN;

				pstInfo = (INFO_OTHER_IF*) new INFO_OTHER_BOOLEAN;
				memset(pstInfo, 0x00, sizeof(INFO_OTHER_BOOLEAN));

				LoadIBoolean(piChild, (INFO_OTHER_BOOLEAN*)pstInfo);
			}
			else if (GenApi::intfICommand == eIfType)
			{
				eType = TYPE_OTHER_INTERFACE_COMMAND;

				pstInfo = (INFO_OTHER_IF*) new INFO_OTHER_COMMAND;
				memset(pstInfo, 0x00, sizeof(INFO_OTHER_COMMAND));

				LoadICommand(piChild, (INFO_OTHER_COMMAND*)pstInfo);
			}
			else if (GenApi::intfIFloat == eIfType)
			{
				eType = TYPE_OTHER_INTERFACE_FLOAT;

				pstInfo = (INFO_OTHER_IF*) new INFO_OTHER_FLOAT;
				memset(pstInfo, 0x00, sizeof(INFO_OTHER_FLOAT));
				
				LoadIFloat(piChild, (INFO_OTHER_FLOAT*)pstInfo);
			}
			else if (GenApi::intfIString == eIfType)
			{
				eType = TYPE_OTHER_INTERFACE_STRING;

				pstInfo = (INFO_OTHER_IF*) new INFO_OTHER_STRING;
				memset(pstInfo, 0x00, sizeof(INFO_OTHER_STRING));

				LoadIString(piChild, (INFO_OTHER_STRING*)pstInfo);
			}
			else if (GenApi::intfIRegister == eIfType)
			{
				LoadIRegister(piChild);
			}
			else if (GenApi::intfICategory == eIfType)
			{
				eType = TYPE_OTHER_INTERFACE_CATEGORY;

				pstInfo = (INFO_OTHER_IF*) new INFO_OTHER_CATEGORY;
				memset(pstInfo, 0x00, sizeof(INFO_OTHER_CATEGORY));

				LoadICategory(piChild, (INFO_OTHER_CATEGORY*)pstInfo);
			}
			else if (GenApi::intfIEnumeration == eIfType)
			{
				eType = TYPE_OTHER_INTERFACE_ENUM;

				pstInfo = (INFO_OTHER_IF*) new INFO_OTHER_ENUM;
				memset(pstInfo, 0x00, sizeof(INFO_OTHER_ENUM));

				LoadIEnumeration(piChild, (INFO_OTHER_ENUM*)pstInfo);
			}
			else if (GenApi::intfIEnumEntry == eIfType)
			{
				LoadIEnumEntry(piChild);
			}
			else if (GenApi::intfIPort == eIfType)
			{
				LoadIPort(piChild);
			}

			if (pstInfo && TYPE_OTHER_INTERFACE_NONE != eType && eType == pstInfo->m_eInterface)
			{
				pstCategoty->m_pListInterface[pstCategoty->m_nListLen] = pstInfo;
				pstCategoty->m_nListLen++;
			}
			else
			{
				ClearInterface(pstInfo);
				delete pstInfo;
			}

		}
		/*//
		else if (GenApi::Expert == eVisible)
		{
		CUtil::PrintDebugString(_T(" Expert \r\n"));
		}
		else if (GenApi::Guru == eVisible)
		{
		CUtil::PrintDebugString(_T(" Guru \r\n"));
		}
		else if (GenApi::Invisible == eVisible)
		{
		CUtil::PrintDebugString(_T(" Invisible \r\n"));
		}
		else
		{
			CUtil::PrintDebugString(_T(" undefined \r\n"));
		}
		//*/
	}

	CUtil::PrintDebugString(_T("\r\n"));

}

void CCameraBasler::LoadIEnumeration(GenApi::INode* piChild, INFO_OTHER_ENUM* pstInfo)
{
	if (NULL == piChild || NULL == pstInfo)
		return;

	// Load information
	LoadInterface(piChild, TYPE_OTHER_INTERFACE_ENUM, &pstInfo->m_stInterface);


	GenApi::IEnumeration *pEnum = dynamic_cast<GenApi::IEnumeration *>(piChild);
	GenApi::IEnumEntry* pEnumEntry = pEnum->GetCurrentEntry();
	CUtil::PrintDebugString(_T("     Current: %s (%ld)\r\n"), pEnumEntry->GetSymbolic().c_str(), pEnumEntry->GetValue());

	GenApi::NodeList_t entries;
	pEnum->GetEntries(entries);
	int nSize = (int)entries.size();

	pstInfo->m_pItemList = new INFO_OTHER_ENUM_ITEM[nSize];
	memset(pstInfo->m_pItemList, 0x00, sizeof(INFO_OTHER_ENUM_ITEM) * nSize);
	pstInfo->m_nItemList = 0;

	// Current Enum...
	pstInfo->m_dwCurValue = (DWORD)pEnumEntry->GetValue();

	for (int i = 0; i < nSize; i++)
	{
		GenApi::INode* piNode = entries[i];
		if (GenApi::IsAvailable(piNode->GetAccessMode()))
		{
			GenApi::IEnumEntry* pEnumEntry = dynamic_cast<GenApi::IEnumEntry *>(piNode);
			
			int nNameLen = (int)pEnumEntry->GetSymbolic().size() + 1;
			TCHAR* pszName = new TCHAR[nNameLen];
			CUtil::StringFormat(pszName, nNameLen, _T("%s"), pEnumEntry->GetSymbolic().c_str());

			pstInfo->m_pItemList[pstInfo->m_nItemList].m_pszName = pszName;				
			pstInfo->m_pItemList[pstInfo->m_nItemList].m_dwValue = (DWORD)pEnumEntry->GetValue();
			pstInfo->m_nItemList++;

			CUtil::PrintDebugString(_T("     %s (%ld)\r\n"), pEnumEntry->GetSymbolic().c_str(), pEnumEntry->GetValue());
		}
	}
}

void CCameraBasler::LoadIEnumEntry(GenApi::INode* piChild)
{
	if (NULL == piChild)
		return;
}

void CCameraBasler::LoadIPort(GenApi::INode* piChild)
{
	if (NULL == piChild)
		return;
}

void CCameraBasler::LoadInterface(GenApi::INode* piChild, TYPE_OTHER_INTERFACE eInterface, INFO_OTHER_IF* pstInfo)
{
	if (NULL == piChild || NULL == pstInfo)
		return;
	
	int nNameLen = (int)piChild->GetName().size() + 1;
	int nDisplayLen = (int)piChild->GetDisplayName().size() + 1;

	pstInfo->m_eInterface = eInterface;
	pstInfo->m_pszName = new TCHAR[nNameLen];
	pstInfo->m_pszDisplayName = new TCHAR[nDisplayLen];

	CUtil::StringFormat(pstInfo->m_pszName, nNameLen, _T("%s"), piChild->GetName().c_str());
	CUtil::StringFormat(pstInfo->m_pszDisplayName, nDisplayLen, _T("%s"), piChild->GetDisplayName().c_str());

	GenApi::EAccessMode eAccess = piChild->GetAccessMode();
	if (GenApi::WO == eAccess)		pstInfo->m_dwAccess = OTHER_OPCODE_WRITE;
	else if (GenApi::RO == eAccess)	pstInfo->m_dwAccess = OTHER_OPCODE_READ;
	else if (GenApi::RW == eAccess)	pstInfo->m_dwAccess = OTHER_OPCODE_READ | OTHER_OPCODE_WRITE;
}



// Update
void CCameraBasler::UpdateCategory(INFO_OTHER_CATEGORY* pstInfo)
{
	if (NULL == pstInfo)
		return;

	try
	{
		const int nLen = pstInfo->m_nListLen;
		for (int i = 0; i < nLen; i++)
		{
			if (TYPE_OTHER_INTERFACE_CATEGORY == pstInfo->m_pListInterface[i]->m_eInterface)
			{
				UpdateCategory((INFO_OTHER_CATEGORY*)pstInfo->m_pListInterface[i]);
			}
			else if (TYPE_OTHER_INTERFACE_INTEGER == pstInfo->m_pListInterface[i]->m_eInterface)
			{
				GenApi::INode* piChild = m_pInstanceCamera->GetNodeMap().GetNode(pstInfo->m_stInterface.m_pszName);
				UpdateIInteger(piChild, (INFO_OTHER_INTEGER*)pstInfo->m_pListInterface[i]);
			}
			else if (TYPE_OTHER_INTERFACE_FLOAT == pstInfo->m_pListInterface[i]->m_eInterface)
			{
				GenApi::INode* piChild = m_pInstanceCamera->GetNodeMap().GetNode(pstInfo->m_stInterface.m_pszName);
				UpdateIFloat(piChild, (INFO_OTHER_FLOAT*)pstInfo->m_pListInterface[i]);
			}
			else if (TYPE_OTHER_INTERFACE_STRING == pstInfo->m_pListInterface[i]->m_eInterface)
			{
				GenApi::INode* piChild = m_pInstanceCamera->GetNodeMap().GetNode(pstInfo->m_stInterface.m_pszName);
				UpdateIString(piChild, (INFO_OTHER_STRING*)pstInfo->m_pListInterface[i]);
			}
			else if (TYPE_OTHER_INTERFACE_ENUM == pstInfo->m_pListInterface[i]->m_eInterface)
			{
				GenApi::INode* piChild = m_pInstanceCamera->GetNodeMap().GetNode(pstInfo->m_stInterface.m_pszName);
				UpdateIEnumeration(piChild, (INFO_OTHER_ENUM*)pstInfo->m_pListInterface[i]);
			}
			else if (TYPE_OTHER_INTERFACE_COMMAND == pstInfo->m_pListInterface[i]->m_eInterface)
			{
				// do nothing...
			}
			else if (TYPE_OTHER_INTERFACE_BOOLEAN == pstInfo->m_pListInterface[i]->m_eInterface)
			{
				GenApi::INode* piChild = m_pInstanceCamera->GetNodeMap().GetNode(pstInfo->m_stInterface.m_pszName);
				UpdateIBoolean(piChild, (INFO_OTHER_BOOLEAN*)pstInfo->m_pListInterface[i]);
			}
			else if (TYPE_OTHER_INTERFACE_REGISTER == pstInfo->m_pListInterface[i]->m_eInterface)
			{
				// do nothing...
			}
		}
	}
	catch (const GenericException &e)
	{
		CUtil::PrintDebugString(_T("[BASLER] %s \r\n"), e.GetDescription());
	}
}

void CCameraBasler::UpdateIValue(GenApi::INode* piChild)
{
	if (NULL == piChild)
		return;
}

void CCameraBasler::UpdateIBase(GenApi::INode* piChild)
{
	if (NULL == piChild)
		return;
}

void CCameraBasler::UpdateIInteger(GenApi::INode* piChild, INFO_OTHER_INTEGER* pstInfo)
{
	if (NULL == piChild || NULL == pstInfo)
		return;

	try
	{
		GenApi::CIntegerPtr value(m_pInstanceCamera->GetNodeMap().GetNode(pstInfo->m_stInterface.m_pszName));
		pstInfo->m_nCur = (int)value->GetValue();

		GenApi::EAccessMode eAccess = value->GetAccessMode();
		if (GenApi::WO == eAccess)		pstInfo->m_stInterface.m_dwAccess = OTHER_OPCODE_WRITE;
		else if (GenApi::RO == eAccess)	pstInfo->m_stInterface.m_dwAccess = OTHER_OPCODE_READ;
		else if (GenApi::RW == eAccess)	pstInfo->m_stInterface.m_dwAccess = OTHER_OPCODE_READ | OTHER_OPCODE_WRITE;

	}
	catch (const GenericException &e)
	{
		CUtil::PrintDebugString(_T("[BASLER] %s \r\n"), e.GetDescription());
	}
}

void CCameraBasler::UpdateIBoolean(GenApi::INode* piChild, INFO_OTHER_BOOLEAN* pstInfo)
{
	if (NULL == piChild || NULL == pstInfo)
		return;

	try
	{
		GenApi::CBooleanPtr value(m_pInstanceCamera->GetNodeMap().GetNode(pstInfo->m_stInterface.m_pszName));
		pstInfo->m_bCur = value->GetValue();

		GenApi::EAccessMode eAccess = value->GetAccessMode();
		if (GenApi::WO == eAccess)		pstInfo->m_stInterface.m_dwAccess = OTHER_OPCODE_WRITE;
		else if (GenApi::RO == eAccess)	pstInfo->m_stInterface.m_dwAccess = OTHER_OPCODE_READ;
		else if (GenApi::RW == eAccess)	pstInfo->m_stInterface.m_dwAccess = OTHER_OPCODE_READ | OTHER_OPCODE_WRITE;
	}
	catch (const GenericException &e)
	{
		CUtil::PrintDebugString(_T("[BASLER] %s \r\n"), e.GetDescription());
	}
}

void CCameraBasler::UpdateICommand(GenApi::INode* piChild, INFO_OTHER_COMMAND* pstInfo)
{
	if (NULL == piChild || NULL == pstInfo)
		return;

	try
	{
		GenApi::CCommandPtr value(m_pInstanceCamera->GetNodeMap().GetNode(pstInfo->m_stInterface.m_pszName));

		GenApi::EAccessMode eAccess = value->GetAccessMode();
		if (GenApi::WO == eAccess)		pstInfo->m_stInterface.m_dwAccess = OTHER_OPCODE_WRITE;
		else if (GenApi::RO == eAccess)	pstInfo->m_stInterface.m_dwAccess = OTHER_OPCODE_READ;
		else if (GenApi::RW == eAccess)	pstInfo->m_stInterface.m_dwAccess = OTHER_OPCODE_READ | OTHER_OPCODE_WRITE;
	}
	catch (const GenericException &e)
	{
		CUtil::PrintDebugString(_T("[BASLER] %s \r\n"), e.GetDescription());
	}

}

void CCameraBasler::UpdateIFloat(GenApi::INode* piChild, INFO_OTHER_FLOAT* pstInfo)
{
	if (NULL == piChild || NULL == pstInfo)
		return;

	try
	{
		GenApi::CFloatPtr value(m_pInstanceCamera->GetNodeMap().GetNode(pstInfo->m_stInterface.m_pszName));
		pstInfo->m_fCur = value->GetValue();

		GenApi::EAccessMode eAccess = value->GetAccessMode();
		if (GenApi::WO == eAccess)		pstInfo->m_stInterface.m_dwAccess = OTHER_OPCODE_WRITE;
		else if (GenApi::RO == eAccess)	pstInfo->m_stInterface.m_dwAccess = OTHER_OPCODE_READ;
		else if (GenApi::RW == eAccess)	pstInfo->m_stInterface.m_dwAccess = OTHER_OPCODE_READ | OTHER_OPCODE_WRITE;
	}
	catch (const GenericException &e)
	{
		CUtil::PrintDebugString(_T("[BASLER] %s \r\n"), e.GetDescription());
	}
}

void CCameraBasler::UpdateIString(GenApi::INode* piChild, INFO_OTHER_STRING* pstInfo)
{
	if (NULL == piChild || NULL == pstInfo)
		return;

	try
	{
		GenApi::CStringPtr value(m_pInstanceCamera->GetNodeMap().GetNode(pstInfo->m_stInterface.m_pszName));

		GenApi::EAccessMode eAccess = value->GetAccessMode();
		if (GenApi::WO == eAccess)		pstInfo->m_stInterface.m_dwAccess = OTHER_OPCODE_WRITE;
		else if (GenApi::RO == eAccess)	pstInfo->m_stInterface.m_dwAccess = OTHER_OPCODE_READ;
		else if (GenApi::RW == eAccess)	pstInfo->m_stInterface.m_dwAccess = OTHER_OPCODE_READ | OTHER_OPCODE_WRITE;
	}
	catch (const GenericException &e)
	{
		CUtil::PrintDebugString(_T("[BASLER] %s \r\n"), e.GetDescription());
	}
}

//void CCameraBasler::UpdateIRegister(GenApi::INode* piChild)
//{
//	if (NULL == piChild)
//		return;
//}
//
//void CCameraBasler::UpdateICategory(GenApi::INode* piChild, INFO_OTHER_CATEGORY* pstCategoty)
//{
//	if (NULL == piChild)
//		return;
//}

void CCameraBasler::UpdateIEnumeration(GenApi::INode* piChild, INFO_OTHER_ENUM* pstInfo)
{
	if (NULL == piChild || NULL == pstInfo)
		return;

	try
	{
		GenApi::CEnumerationPtr value(m_pInstanceCamera->GetNodeMap().GetNode(pstInfo->m_stInterface.m_pszName));
		pstInfo->m_dwCurValue = (DWORD)value->GetIntValue();

		GenApi::EAccessMode eAccess = value->GetAccessMode();
		if (GenApi::WO == eAccess)		pstInfo->m_stInterface.m_dwAccess = OTHER_OPCODE_WRITE;
		else if (GenApi::RO == eAccess)	pstInfo->m_stInterface.m_dwAccess = OTHER_OPCODE_READ;
		else if (GenApi::RW == eAccess)	pstInfo->m_stInterface.m_dwAccess = OTHER_OPCODE_READ | OTHER_OPCODE_WRITE;
	}
	catch (const GenericException &e)
	{
		CUtil::PrintDebugString(_T("[BASLER] %s \r\n"), e.GetDescription());
	}
}

//void CCameraBasler::UpdateIEnumEntry(GenApi::INode* piChild)
//{
//	if (NULL == piChild)
//		return;
//}
//
//void CCameraBasler::UpdateIPort(GenApi::INode* piChild)
//{
//	if (NULL == piChild)
//		return;
//}




// Clear
void CCameraBasler::ClearCategory(INFO_OTHER_CATEGORY* pstInfo)
{
	if (NULL == pstInfo || TYPE_OTHER_INTERFACE_CATEGORY != pstInfo->m_stInterface.m_eInterface)
		return;

	for (int i = 0; i < pstInfo->m_nListLen; i++)
	{
		if (NULL == pstInfo->m_pListInterface[i])
			continue;

		if (TYPE_OTHER_INTERFACE_CATEGORY == pstInfo->m_pListInterface[i]->m_eInterface)
		{
			ClearCategory((INFO_OTHER_CATEGORY*)pstInfo->m_pListInterface[i]);
		}
		else
		{
			ClearInterface((INFO_OTHER_IF*)pstInfo->m_pListInterface[i]);
		}

		if (pstInfo->m_pListInterface[i])
			delete pstInfo->m_pListInterface[i];
		pstInfo->m_pListInterface[i] = NULL;
	}


	if (pstInfo->m_stInterface.m_pszName)
		delete[] pstInfo->m_stInterface.m_pszName;
	pstInfo->m_stInterface.m_pszName = NULL;

	if (pstInfo->m_stInterface.m_pszDisplayName)
		delete[] pstInfo->m_stInterface.m_pszDisplayName;
	pstInfo->m_stInterface.m_pszDisplayName = NULL;

}

void CCameraBasler::ClearInterface(INFO_OTHER_IF* pstInfo)
{
	if (NULL == pstInfo)
		return;

	if (TYPE_OTHER_INTERFACE_CATEGORY == pstInfo->m_eInterface)
	{
		ClearCategory((INFO_OTHER_CATEGORY*)pstInfo);
	}
	else if (TYPE_OTHER_INTERFACE_ENUM == pstInfo->m_eInterface)
	{
		INFO_OTHER_ENUM* pEnum = (INFO_OTHER_ENUM*)pstInfo;
		if (pEnum->m_pItemList)
		{
			for (int i = 0; i < pEnum->m_nItemList; i++)
			{
				if (pEnum->m_pItemList[i].m_pszName)
					delete[] pEnum->m_pItemList[i].m_pszName;
			}
			delete[] pEnum->m_pItemList;
		}

		if (pstInfo->m_pszName)
			delete[] pstInfo->m_pszName;
		if (pstInfo->m_pszDisplayName)
			delete[] pstInfo->m_pszDisplayName;
	}
	else if (TYPE_OTHER_INTERFACE_STRING == pstInfo->m_eInterface)
	{
		INFO_OTHER_STRING* pString = (INFO_OTHER_STRING*)pstInfo;
		if (pString->m_pString)
			delete[] pString->m_pString;

		if (pstInfo->m_pszName)
			delete[] pstInfo->m_pszName;
		if (pstInfo->m_pszDisplayName)
			delete[] pstInfo->m_pszDisplayName;
	}
	else
	{
		if (pstInfo->m_pszName)
			delete[] pstInfo->m_pszName;
		if (pstInfo->m_pszDisplayName)
			delete[] pstInfo->m_pszDisplayName;
	}
}



BOOL CCameraBasler::GetCameraInformation(INFO_OTHER_CATEGORY* pstRootCategory)
{
	if (NULL == pstRootCategory || NULL == m_pRootCategory)
		return FALSE;
	CopyInterface(&m_pRootCategory->m_stInterface, &pstRootCategory->m_stInterface);

	const int nSize = m_pRootCategory->m_nListLen;
	for (int i = 0; i < nSize; i++)
	{
		CopyInformation(m_pRootCategory->m_pListInterface[i], &pstRootCategory->m_pListInterface[i]);
	}
	pstRootCategory->m_nListLen = nSize;

	return TRUE;
}

const INFO_OTHER_IF* CCameraBasler::GetCameraInformation(const TCHAR* szName)
{
	if (NULL == m_pRootCategory || NULL == szName)
		return NULL;

	const INFO_OTHER_IF* pOther = SearchInterface(szName);
	return pOther;
}

void CCameraBasler::CopyInformation(const INFO_OTHER_IF* pstSrc, INFO_OTHER_IF** ppstDest)
{
	if (NULL == pstSrc || NULL == ppstDest)
		return;

	if (TYPE_OTHER_INTERFACE_INTEGER == pstSrc->m_eInterface)
	{
		INFO_OTHER_INTEGER* pstInfo = new INFO_OTHER_INTEGER;
		memset(pstInfo, 0x00, sizeof(INFO_OTHER_INTEGER));
		CopyInterface(pstSrc, &pstInfo->m_stInterface);

		pstInfo->m_nMin = ((INFO_OTHER_INTEGER*)pstSrc)->m_nMin;
		pstInfo->m_nMax = ((INFO_OTHER_INTEGER*)pstSrc)->m_nMax;
		pstInfo->m_nInc = ((INFO_OTHER_INTEGER*)pstSrc)->m_nInc;
		pstInfo->m_nCur = ((INFO_OTHER_INTEGER*)pstSrc)->m_nCur;
		
		*ppstDest = (INFO_OTHER_IF*)pstInfo;
	}
	else if (TYPE_OTHER_INTERFACE_FLOAT == pstSrc->m_eInterface)
	{
		INFO_OTHER_FLOAT* pstInfo = new INFO_OTHER_FLOAT;
		memset(pstInfo, 0x00, sizeof(INFO_OTHER_FLOAT));
		CopyInterface(pstSrc, &pstInfo->m_stInterface);

		pstInfo->m_fMin = ((INFO_OTHER_FLOAT*)pstSrc)->m_fMin;
		pstInfo->m_fMax = ((INFO_OTHER_FLOAT*)pstSrc)->m_fMax;
		pstInfo->m_fInc = ((INFO_OTHER_FLOAT*)pstSrc)->m_fInc;
		pstInfo->m_fCur = ((INFO_OTHER_FLOAT*)pstSrc)->m_fCur;

		*ppstDest = (INFO_OTHER_IF*)pstInfo;
	}
	else if (TYPE_OTHER_INTERFACE_STRING == pstSrc->m_eInterface)
	{
		INFO_OTHER_STRING* pstInfo = new INFO_OTHER_STRING;
		memset(pstInfo, 0x00, sizeof(INFO_OTHER_STRING));
		CopyInterface(pstSrc, &pstInfo->m_stInterface);

		int nString = CUtil::StringLength(((INFO_OTHER_STRING*)pstSrc)->m_pString) + 1;
		pstInfo->m_pString = new TCHAR[nString];
		CUtil::StringFormat(pstInfo->m_pString, nString, _T("%s"), ((INFO_OTHER_STRING*)pstSrc)->m_pString);

		*ppstDest = (INFO_OTHER_IF*)pstInfo;
	}
	else if (TYPE_OTHER_INTERFACE_ENUM == pstSrc->m_eInterface)
	{
		INFO_OTHER_ENUM* pstInfo = new INFO_OTHER_ENUM;
		memset(pstInfo, 0x00, sizeof(INFO_OTHER_ENUM));
		CopyInterface(pstSrc, &pstInfo->m_stInterface);

		pstInfo->m_dwCurValue = ((INFO_OTHER_ENUM*)pstSrc)->m_dwCurValue;
		
		pstInfo->m_nItemList = ((INFO_OTHER_ENUM*)pstSrc)->m_nItemList;
		pstInfo->m_pItemList = new INFO_OTHER_ENUM_ITEM[pstInfo->m_nItemList];

		for (int i = 0; i < pstInfo->m_nItemList; i++)
		{
			int nName = CUtil::StringLength(((INFO_OTHER_ENUM*)pstSrc)->m_pItemList[i].m_pszName) + 1;
			pstInfo->m_pItemList[i].m_pszName = new TCHAR[nName];
			CUtil::StringFormat(pstInfo->m_pItemList[i].m_pszName, nName, _T("%s"), ((INFO_OTHER_ENUM*)pstSrc)->m_pItemList[i].m_pszName);

			pstInfo->m_pItemList[i].m_dwValue = ((INFO_OTHER_ENUM*)pstSrc)->m_pItemList[i].m_dwValue;
		}

		*ppstDest = (INFO_OTHER_IF*)pstInfo;
	}
	else if (TYPE_OTHER_INTERFACE_COMMAND == pstSrc->m_eInterface)
	{
		INFO_OTHER_COMMAND* pstInfo = new INFO_OTHER_COMMAND;
		memset(pstInfo, 0x00, sizeof(INFO_OTHER_COMMAND));
		CopyInterface(pstSrc, &pstInfo->m_stInterface);

		*ppstDest = (INFO_OTHER_IF*)pstInfo;
	}
	else if (TYPE_OTHER_INTERFACE_BOOLEAN == pstSrc->m_eInterface)
	{
		INFO_OTHER_BOOLEAN* pstInfo = new INFO_OTHER_BOOLEAN;
		memset(pstInfo, 0x00, sizeof(INFO_OTHER_BOOLEAN));
		CopyInterface(pstSrc, &pstInfo->m_stInterface);

		pstInfo->m_bCur = ((INFO_OTHER_BOOLEAN*)pstSrc)->m_bCur;

		*ppstDest = (INFO_OTHER_IF*)pstInfo;
	}
	else if (TYPE_OTHER_INTERFACE_REGISTER == pstSrc->m_eInterface)
	{
	}
	else if (TYPE_OTHER_INTERFACE_CATEGORY == pstSrc->m_eInterface)
	{
		if (1 > ((INFO_OTHER_CATEGORY*)pstSrc)->m_nListLen)
			return;

		INFO_OTHER_CATEGORY* pstInfo = new INFO_OTHER_CATEGORY;
		memset(pstInfo, 0x00, sizeof(INFO_OTHER_CATEGORY));
		CopyInterface(pstSrc, &pstInfo->m_stInterface);

		pstInfo->m_nListLen = ((INFO_OTHER_CATEGORY*)pstSrc)->m_nListLen;

		for (int i = 0; i < pstInfo->m_nListLen; i++)
		{
			CopyInformation(((INFO_OTHER_CATEGORY*)pstSrc)->m_pListInterface[i], &pstInfo->m_pListInterface[i]);
		}

		*ppstDest = (INFO_OTHER_IF*)pstInfo;
	}

	
}

void CCameraBasler::CopyInterface(const INFO_OTHER_IF* pstSrc, INFO_OTHER_IF* pstDest)
{
	if (NULL == pstSrc || NULL == pstDest)
		return;
	
	int nName = CUtil::StringLength(pstSrc->m_pszName) + 1;
	int nDisplay = CUtil::StringLength(pstSrc->m_pszDisplayName) + 1;

	pstDest->m_eInterface = pstSrc->m_eInterface;
	pstDest->m_dwAccess = pstSrc->m_dwAccess;
	pstDest->m_pszName = new TCHAR[nName];
	pstDest->m_pszDisplayName = new TCHAR[nDisplay];

	CUtil::StringFormat(pstDest->m_pszName, nName, _T("%s"), pstSrc->m_pszName);
	CUtil::StringFormat(pstDest->m_pszDisplayName, nDisplay, _T("%s"), pstSrc->m_pszDisplayName);

}


INFO_OTHER_IF* CCameraBasler::SearchInterface(const TCHAR* szName)
{
	if (NULL == m_pRootCategory || NULL == szName)
		return NULL;

	INFO_OTHER_IF* pOther = NULL;
	for (int i = 0; i < m_pRootCategory->m_nListLen; i++)
	{
		if (TYPE_OTHER_INTERFACE_CATEGORY == m_pRootCategory->m_pListInterface[i]->m_eInterface)
		{
			pOther = SearchInterfaceFromCategory((INFO_OTHER_CATEGORY*)m_pRootCategory->m_pListInterface[i], szName);
			if (pOther)
				break;
		}
		else
		{
			if (CUtil::StringICompare((TCHAR*)szName, m_pRootCategory->m_pListInterface[i]->m_pszName) ||
				CUtil::StringICompare((TCHAR*)szName, m_pRootCategory->m_pListInterface[i]->m_pszDisplayName))
			{
				pOther = m_pRootCategory->m_pListInterface[i];
				break;
			}
		}
	}
	return pOther;
}

INFO_OTHER_IF* CCameraBasler::SearchInterfaceFromCategory(INFO_OTHER_CATEGORY* pstCategory, const TCHAR* szName)
{
	if (NULL == pstCategory || NULL == szName)
		return NULL;

	INFO_OTHER_IF* pOther = NULL;
	for (int i = 0; i < pstCategory->m_nListLen; i++)
	{
		if (TYPE_OTHER_INTERFACE_CATEGORY == pstCategory->m_pListInterface[i]->m_eInterface)
		{
			pOther = SearchInterfaceFromCategory((INFO_OTHER_CATEGORY*)pstCategory->m_pListInterface[i], szName);
			if (pOther)
				break;
		}
		else
		{
			if (CUtil::StringCompare((TCHAR*)szName, pstCategory->m_pListInterface[i]->m_pszName) ||
				CUtil::StringCompare((TCHAR*)szName, pstCategory->m_pListInterface[i]->m_pszDisplayName))
			{
				pOther = pstCategory->m_pListInterface[i];
				break;
			}
		}
	}
	return pOther;
}


BOOL CCameraBasler::GetCameraValue(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	if (NULL == pstInfo || NULL == pstValue || NULL == m_pInstanceCamera)
		return FALSE;

	BOOL bResult = FALSE;

	const TYPE_OTHER_INTERFACE eType = pstInfo->m_eInterface;
	if (TYPE_OTHER_INTERFACE_INTEGER == eType)
		bResult = GetIInteger(pstInfo, pstValue);

	else if (TYPE_OTHER_INTERFACE_FLOAT == eType)
		bResult = GetIFloat(pstInfo, pstValue);

	else if (TYPE_OTHER_INTERFACE_STRING == eType)
		bResult = GetIString(pstInfo, pstValue);

	else if (TYPE_OTHER_INTERFACE_ENUM == eType)
		bResult = GetIEnumeration(pstInfo, pstValue);

	else if (TYPE_OTHER_INTERFACE_COMMAND == eType)
		bResult = GetICommand(pstInfo, pstValue);

	else if (TYPE_OTHER_INTERFACE_BOOLEAN == eType)
		bResult = GetIBoolean(pstInfo, pstValue);

	/*//
	else if (TYPE_OTHER_INTERFACE_REGISTER == eType)
	bResult = GetIInteger(pstInfo, pstValue);

	else if (TYPE_OTHER_INTERFACE_CATEGORY == eType)
	bResult = GetIInteger(pstInfo, pstValue);
	//*/

	return bResult;
}


BOOL CCameraBasler::GetIInteger(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	if (NULL == pstInfo || NULL == pstValue || NULL == m_pInstanceCamera)
		return FALSE;

	try
	{
		VALUE_OTHER_INTEGER* pstInteger = (VALUE_OTHER_INTEGER*)pstValue;

		GenApi::CIntegerPtr value(m_pInstanceCamera->GetNodeMap().GetNode(pstInfo->m_pszName));
		pstInteger->m_nValue = (int)value->GetValue();

		CUtil::PrintDebugString(_T("[BASLER] Integer \r\n"));
	}
	catch (const GenericException &e)
	{
		CUtil::PrintDebugString(_T("[BASLER] %s \r\n"), e.GetDescription());
		return FALSE;
	}
	return TRUE;
}

BOOL CCameraBasler::GetIBoolean(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	if (NULL == pstInfo || NULL == pstValue)
		return FALSE;

	try
	{
		VALUE_OTHER_BOOLEAN* pstBoolean = (VALUE_OTHER_BOOLEAN*)pstValue;

		GenApi::CBooleanPtr value(m_pInstanceCamera->GetNodeMap().GetNode(pstInfo->m_pszName));
		pstBoolean->m_bValue = value->GetValue();

		CUtil::PrintDebugString(_T("[BASLER] Boolean \r\n"));
	}
	catch (const GenericException &e)
	{
		CUtil::PrintDebugString(_T("[BASLER] %s \r\n"), e.GetDescription());
		return FALSE;
	}
	return TRUE;
}

BOOL CCameraBasler::GetICommand(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	if (NULL == pstInfo || NULL == pstValue)
		return FALSE;

	return FALSE;
}

BOOL CCameraBasler::GetIFloat(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	if (NULL == pstInfo || NULL == pstValue)
		return FALSE;

	try
	{
		VALUE_OTHER_FLOAT* pstFloat = (VALUE_OTHER_FLOAT*)pstValue;

		GenApi::CFloatPtr value(m_pInstanceCamera->GetNodeMap().GetNode(pstInfo->m_pszName));
		pstFloat->m_fValue = value->GetValue();

		CUtil::PrintDebugString(_T("[BASLER] Float \r\n"));
	}
	catch (const GenericException &e)
	{
		CUtil::PrintDebugString(_T("[BASLER] %s \r\n"), e.GetDescription());
		return FALSE;
	}
	return TRUE;
}

BOOL CCameraBasler::GetIString(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	if (NULL == pstInfo || NULL == pstValue)
		return FALSE;

	try
	{
		VALUE_OTHER_STRING* pstString = (VALUE_OTHER_STRING*)pstValue;

		GenApi::CStringPtr value(m_pInstanceCamera->GetNodeMap().GetNode(pstInfo->m_pszName));
		Pylon::String_t szValue = value->GetValue();
		
		int nLen = (int)szValue.length() + 1;
		pstString->m_pValue = new TCHAR[nLen];
		CUtil::StringFormat(pstString->m_pValue, nLen, _T("%s"), szValue.c_str());

		CUtil::PrintDebugString(_T("[BASLER] String \r\n"));
	}
	catch (const GenericException &e)
	{
		CUtil::PrintDebugString(_T("[BASLER] %s \r\n"), e.GetDescription());
		return FALSE;
	}
	return TRUE;
}

BOOL CCameraBasler::GetIEnumeration(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	if (NULL == pstInfo || NULL == pstValue)
		return FALSE;

	try
	{
		VALUE_OTHER_ENUM* pszEnum = (VALUE_OTHER_ENUM*)pstValue;

		GenApi::CEnumerationPtr value(m_pInstanceCamera->GetNodeMap().GetNode(pstInfo->m_pszName));
		pszEnum->m_dwValue = (DWORD)value->GetIntValue();

		CUtil::PrintDebugString(_T("[BASLER] Enum %d \r\n"), pszEnum->m_dwValue);
	}
	catch (const GenericException &e)
	{
		CUtil::PrintDebugString(_T("[BASLER] %s \r\n"), e.GetDescription());
		return FALSE;
	}
	return TRUE;
}



BOOL CCameraBasler::SetCameraValue(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	if (NULL == pstInfo || NULL == pstValue)
		return FALSE;

	BOOL bResult = FALSE;

	const TYPE_OTHER_INTERFACE eType = pstInfo->m_eInterface;
	if (TYPE_OTHER_INTERFACE_INTEGER == eType)
		bResult = SetIInteger(pstInfo, pstValue);

	else if (TYPE_OTHER_INTERFACE_FLOAT == eType)
		bResult = SetIFloat(pstInfo, pstValue);

	else if (TYPE_OTHER_INTERFACE_STRING == eType)
		bResult = SetIString(pstInfo, pstValue);

	else if (TYPE_OTHER_INTERFACE_ENUM == eType)
		bResult = SetIEnumeration(pstInfo, pstValue);
	
	else if (TYPE_OTHER_INTERFACE_COMMAND == eType)
		bResult = SetICommand(pstInfo, pstValue);

	else if (TYPE_OTHER_INTERFACE_BOOLEAN == eType)
		bResult = SetIBoolean(pstInfo, pstValue);
	
	/*//
	else if (TYPE_OTHER_INTERFACE_REGISTER == eType)
		bResult = SetIInteger(pstInfo, pstValue);
	else if (TYPE_OTHER_INTERFACE_CATEGORY == eType)
		bResult = SetIInteger(pstInfo, pstValue);
	//*/
	
	UpdateCategory(m_pRootCategory);

	return bResult;
}

BOOL CCameraBasler::SetIInteger(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	if (NULL == pstInfo || NULL == pstValue)
		return FALSE;

	try
	{
		VALUE_OTHER_INTEGER* pstInteger = (VALUE_OTHER_INTEGER*)pstValue;

		GenApi::CIntegerPtr value(m_pInstanceCamera->GetNodeMap().GetNode(pstInfo->m_pszName));
		value->SetValue(pstInteger->m_nValue);

		CUtil::PrintDebugString(_T("[BASLER] Integer \r\n"));
	}
	catch (const GenericException &e)
	{
		CUtil::PrintDebugString(_T("[BASLER] %s \r\n"), e.GetDescription());
		return FALSE;
	}
	return TRUE;
}

BOOL CCameraBasler::SetIBoolean(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	if (NULL == pstInfo || NULL == pstValue)
		return FALSE;

	try
	{
		VALUE_OTHER_BOOLEAN* pstBoolean = (VALUE_OTHER_BOOLEAN*)pstValue;

		GenApi::CBooleanPtr value(m_pInstanceCamera->GetNodeMap().GetNode(pstInfo->m_pszName));
		value->SetValue((bool)pstBoolean->m_bValue);

		CUtil::PrintDebugString(_T("[BASLER] Boolean \r\n"));
	}
	catch (const GenericException &e)
	{
		CUtil::PrintDebugString(_T("[BASLER] %s \r\n"), e.GetDescription());
		return FALSE;
	}
	return TRUE;
}

BOOL CCameraBasler::SetICommand(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	if (NULL == pstInfo || NULL == pstValue)
		return FALSE;

	try
	{
		GenApi::CCommandPtr value(m_pInstanceCamera->GetNodeMap().GetNode(pstInfo->m_pszName));
		value->Execute();

		CUtil::PrintDebugString(_T("[BASLER] Cmd \r\n"));
	}
	catch (const GenericException &e)
	{
		CUtil::PrintDebugString(_T("[BASLER] %s \r\n"), e.GetDescription());
		return FALSE;
	}
	return TRUE;
}

BOOL CCameraBasler::SetIFloat(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	if (NULL == pstInfo || NULL == pstValue)
		return FALSE;

	try
	{
		VALUE_OTHER_FLOAT* pstFloat = (VALUE_OTHER_FLOAT*)pstValue;

		GenApi::CFloatPtr value(m_pInstanceCamera->GetNodeMap().GetNode(pstInfo->m_pszName));
		value->SetValue(pstFloat->m_fValue);

		CUtil::PrintDebugString(_T("[BASLER] Float \r\n"));
	}
	catch (const GenericException &e)
	{
		CUtil::PrintDebugString(_T("[BASLER] %s \r\n"), e.GetDescription());
		return FALSE;
	}
	return TRUE;
}

BOOL CCameraBasler::SetIString(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	if (NULL == pstInfo || NULL == pstValue)
		return FALSE;

	BOOL bResult = FALSE;
	return bResult;
}

BOOL CCameraBasler::SetIEnumeration(const INFO_OTHER_IF* pstInfo, VALUE_OTHER* pstValue)
{
	if (NULL == pstInfo || NULL == pstValue)
		return FALSE;

	try
	{
		VALUE_OTHER_ENUM* pszEnum = (VALUE_OTHER_ENUM*)pstValue;

		GenApi::CEnumerationPtr value(m_pInstanceCamera->GetNodeMap().GetNode(pstInfo->m_pszName));
		value->SetIntValue(pszEnum->m_dwValue);

		CUtil::PrintDebugString(_T("[BASLER] Enum %d \r\n"), pszEnum->m_dwValue);
	}
	catch (const GenericException &e)
	{
		CUtil::PrintDebugString(_T("[BASLER] %s \r\n"), e.GetDescription());
		return FALSE;
	}
	return TRUE;
}

