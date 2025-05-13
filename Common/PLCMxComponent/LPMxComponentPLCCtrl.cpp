#include "stdafx.h"

#include "LPMxComponentPLCCtrl.h"

/***************************************************/
#include "ActUtlType_i.c"	
#include "ActProgType_i.c"
#include "ActMulti_i.c"
#include "ActEther_i.c"
/***************************************************/

#include "Util/Util.h" 

CLPMxComponentPLCCtrl::CLPMxComponentPLCCtrl()
{
	InitLPMxComponenetPLCCtrl();
}


CLPMxComponentPLCCtrl::~CLPMxComponentPLCCtrl()
{
	ReleaseLPMxComponenetPLCCtrl();
}


void CLPMxComponentPLCCtrl::InitLPMxComponenetPLCCtrl()
{
	m_bPLCControlOpen = FALSE;

	m_nPLCProtocolType = TYPE_PLCPROTOCOL_NONE;
	m_nPLCControlType = TYPE_PLCCONTROL_NONE;

	m_nLogicalStationNumber = PLC_DEFAULT_STATIONNUMBER;

	/// Network Option
	m_nPLCCPUType = CPU_Q26UDVCPU;
	m_strHostAddress = PLC_DEFAULT_HOSTADDRESS;

	m_bCreateIUtil = FALSE;
	m_bOpenIUtil = FALSE;
	m_pIUtlType = NULL;

	m_bCreateIProg = FALSE;
	m_bOpenIProg = FALSE;
	m_pIProgType = NULL;
	
}


BOOL CLPMxComponentPLCCtrl::CreateLPMxComponenetPLCCtrl()
{
	// ActProgType Control 
	HRESULT	hr = CoCreateInstance(CLSID_ActProgType,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IActProgType,
		(LPVOID*)&m_pIProgType);
	if (!SUCCEEDED(hr))
		m_bCreateIProg = FALSE;
	else
		m_bCreateIProg = TRUE;

	// ActUtlType Control
	hr = CoCreateInstance(CLSID_ActUtlType,
		NULL,
		CLSCTX_INPROC_SERVER,
		IID_IActUtlType,
		(LPVOID*)&m_pIUtlType);
	if (!SUCCEEDED(hr))
		m_bCreateIUtil = FALSE;
	else
		m_bCreateIUtil = TRUE;

	if (m_bCreateIProg && m_bCreateIUtil)
		return TRUE;

	return FALSE;
}

/////////////////////////////////////////////////////////////////////////////
/// Program Setting Ref Data
/////////////////////////////////////////////////////////////////////////////

/// 1. Simulation
// UnitType : UNIT_SIMULATOR2
// Protocol Type : PROTOCOL_SHAREDMEMORY

/// 2. Ethernet CPUtype( Main PLC include Ethernet)
// Unit Type : UNIT_QNETHER
// Protocol Type : PROTOCOL_TCPIP

// http://blog.naver.com/PostView.nhn?blogId=oyg049&logNo=221273182378&from=search&redirect=Log&widgetTypeCall=true&directAccess=false

/// 3. Ethernet Module(QJ71E71)
// Unit Type : UNIT_QJ71E71
// Protocol Type : PROTOCOL_TCPIP

BOOL CLPMxComponentPLCCtrl::OpenLPMxComponenetPLCCtrl(long* plReturnCode)
{
	HRESULT	hr = S_FALSE;

	switch (m_nPLCProtocolType)
	{
		case TYPE_PLCPROTOCOL_SIMULATION:
		{
			switch (m_nPLCControlType)
			{
				case TYPE_PLCCONTROL_Utility:
				{
					if (m_pIUtlType){
						hr = m_pIUtlType->put_ActLogicalStationNumber(m_nLogicalStationNumber);
						if (SUCCEEDED(hr)){
							hr = m_pIUtlType->Open(plReturnCode);
							if (SUCCEEDED(hr) && hr == S_OK)
							{
								m_bOpenIUtil = TRUE;
							}
							else
								m_bOpenIUtil = FALSE;
						}
					}
				}
				break;
				case TYPE_PLCCONTROL_Program:
				{
					if (m_pIProgType){
						hr = m_pIProgType->put_ActUnitType(UNIT_SIMULATOR2);
						if (SUCCEEDED(hr)){
							hr = m_pIProgType->put_ActProtocolType(PROTOCOL_SHAREDMEMORY);
							if (SUCCEEDED(hr)){
								hr = m_pIProgType->Open(plReturnCode);
								if (SUCCEEDED(hr) && hr == S_OK)
								{
									m_pIProgType->put_ActCpuTimeOut(PLC_SET_TIMEOUT);
									m_bOpenIProg = TRUE;
								}
								else
									m_bOpenIProg = FALSE;
							}
						}
					}
				}
				break;
			}
		}
		break;
		case TYPE_PLCPROTOCOL_TCPIP:
		{
			switch (m_nPLCControlType)
			{
				case TYPE_PLCCONTROL_Utility:
				{
					if (m_pIUtlType){
						hr = m_pIUtlType->put_ActLogicalStationNumber(m_nLogicalStationNumber);
						if (SUCCEEDED(hr)){
							hr = m_pIUtlType->Open(plReturnCode);
							if (SUCCEEDED(hr) && hr == S_OK)
							{
								m_bOpenIUtil = TRUE;
								OutputDebugString("NEPES : OpenLPMxComponenetPLCCtrl : Success \r\n");
							}
							else
							{
								m_bOpenIUtil = FALSE;
								OutputDebugString("NEPES : OpenLPMxComponenetPLCCtrl : Fail \r\n");
							}
						}
					}
				}
				break;
				case TYPE_PLCCONTROL_Program:
				{
					if (m_pIProgType){
						hr = m_pIProgType->put_ActCpuType(m_nPLCCPUType); // CPU_Q26UDVCPU
						if (SUCCEEDED(hr)){
							hr = m_pIProgType->put_ActUnitType(UNIT_QNETHER);
							if (SUCCEEDED(hr)){
								hr = m_pIProgType->put_ActProtocolType(PROTOCOL_TCPIP);
								if (SUCCEEDED(hr)){
									hr = m_pIProgType->put_ActHostAddress(m_strHostAddress.AllocSysString());
									if (SUCCEEDED(hr)){
										hr = m_pIProgType->put_ActDestinationPortNumber(5007);
										if (SUCCEEDED(hr)){
											hr = m_pIProgType->Open(plReturnCode);
											if (SUCCEEDED(hr) && hr == S_OK)
											{
												m_bOpenIProg = TRUE;
												hr = m_pIProgType->put_ActTimeOut(PLC_SET_TIMEOUT);
												if (SUCCEEDED(hr) && hr == S_OK)
												{
													long lTimeout = 0;
													hr = m_pIProgType->get_ActTimeOut(&lTimeout);
													if (SUCCEEDED(hr) && hr == S_OK)
													{
														CString strTraceMessage = _T("");
														strTraceMessage.Format(_T("NEPES : OpenLPMxComponenetPLCCtrl : TimeOut Set Success And Get Timeout : %d \r\n"), lTimeout);
														OutputDebugString(strTraceMessage);
													}
													else
													{
														OutputDebugString("NEPES : OpenLPMxComponenetPLCCtrl : TimeOut Set Success And Get Timeout Fail \r\n");
													}
												}
												else
												{
													OutputDebugString("NEPES : OpenLPMxComponenetPLCCtrl : TimeOut Set Fail \r\n");
												}
											}
											else
											{
												m_bOpenIProg = FALSE;
												OutputDebugString("NEPES : OpenLPMxComponenetPLCCtrl : Fail \r\n");
											}
										}
									}
								}
							}
						}
					}
				}
				break;
			}
		}
		break;
	}

	if (m_bOpenIProg || m_bOpenIUtil)
		m_bPLCControlOpen = TRUE;
	else
		m_bPLCControlOpen = FALSE;

	if (SUCCEEDED(hr) && hr == S_OK)
		return TRUE;
	else
		return FALSE;

	return TRUE;
}


BOOL CLPMxComponentPLCCtrl::GetLPMxComponenetPLCCtrlCPUType(CString* pstrCpuName, long* plCPUCode, long* plReturnCode)
{
	HRESULT	hr = S_FALSE;
	BSTR	szCpuName = NULL;

	switch (m_nPLCProtocolType)
	{
		case TYPE_PLCPROTOCOL_SIMULATION:
		{
			switch (m_nPLCControlType)
			{
				case TYPE_PLCCONTROL_Utility:
				{
					if (m_pIUtlType){
						hr = m_pIUtlType->GetCpuType(&szCpuName, plCPUCode, plReturnCode);
					}
				}
				break;
				case TYPE_PLCCONTROL_Program:
				{
					if (m_pIProgType){
						hr = m_pIProgType->GetCpuType(&szCpuName, plCPUCode, plReturnCode);
					}
				}
				break;
			}
		}
		break;
		case TYPE_PLCPROTOCOL_TCPIP:
		{
			switch (m_nPLCControlType)
			{
				case TYPE_PLCCONTROL_Utility:
				{
					if (m_pIUtlType){
						hr = m_pIUtlType->GetCpuType(&szCpuName, plCPUCode, plReturnCode);
					}
				}
				break;
				case TYPE_PLCCONTROL_Program:
				{
					if (m_pIProgType){
						hr = m_pIProgType->GetCpuType(&szCpuName, plCPUCode, plReturnCode);
					}
				}
				break;
			}
		}
		break;
	}

	*pstrCpuName = szCpuName;
	::SysFreeString(szCpuName);

	if (SUCCEEDED(hr) && hr == S_OK)
		return TRUE;
	else
		return FALSE;

	return TRUE;
}


BOOL CLPMxComponentPLCCtrl::GetLPMxComponenetPLCCtrlDevice(CString strDevice, long* plValue, long* plReturnCode)
{
	HRESULT	hr = S_FALSE;
	switch (m_nPLCProtocolType)
	{
		case TYPE_PLCPROTOCOL_SIMULATION:
		{
			switch (m_nPLCControlType)
			{
			case TYPE_PLCCONTROL_Utility:
			{
				if (m_pIUtlType){
					hr = m_pIUtlType->GetDevice(strDevice.AllocSysString(), plValue, plReturnCode);
				}
			}
			break;
			case TYPE_PLCCONTROL_Program:
			{
				if (m_pIProgType){
					hr = m_pIProgType->GetDevice(strDevice.AllocSysString(), plValue, plReturnCode);
				}
			}
			break;
			}
		}
		break;
		case TYPE_PLCPROTOCOL_TCPIP:
		{
			switch (m_nPLCControlType)
			{
			case TYPE_PLCCONTROL_Utility:
			{
				if (m_pIUtlType){
					hr = m_pIUtlType->GetDevice(strDevice.AllocSysString(), plValue, plReturnCode);
					if (SUCCEEDED(hr) && hr != S_OK)
					{
						CString strTraceMessage = _T("");
						strTraceMessage.Format(_T("============================== NEPES : m_pIUtlType GetLPMxComponenetPLCCtrlDevice Retry Start 1-1 : %s, 0x%08x \r\n"), strDevice, *plReturnCode);
						OutputDebugString(strTraceMessage);

						hr = m_pIUtlType->GetDevice(strDevice.AllocSysString(), plValue, plReturnCode);

						strTraceMessage.Format(_T("============================== NEPES : m_pIUtlType GetLPMxComponenetPLCCtrlDevice Retry End 1-2 : %s, 0x%08x \r\n"), strDevice, *plReturnCode);
						OutputDebugString(strTraceMessage);
					}
				}
			}
			break;
			case TYPE_PLCCONTROL_Program:
			{
				if (m_pIProgType){
					hr = m_pIProgType->GetDevice(strDevice.AllocSysString(), plValue, plReturnCode);
					if (SUCCEEDED(hr) && hr != S_OK)
					{
						CString strTraceMessage = _T("");
						strTraceMessage.Format(_T("============================== NEPES : m_pIProgType GetLPMxComponenetPLCCtrlDevice Retry Start 1-1 : %s, 0x%08x \r\n"), strDevice, *plReturnCode);
						OutputDebugString(strTraceMessage);

						hr = m_pIProgType->GetDevice(strDevice.AllocSysString(), plValue, plReturnCode);

						strTraceMessage.Format(_T("============================== NEPES : m_pIProgType GetLPMxComponenetPLCCtrlDevice Retry End 1-2 : %s, 0x%08x \r\n"), strDevice, *plReturnCode);
						OutputDebugString(strTraceMessage);
					}
				}
			}
			break;
			}
		}
		break;
	}

	CString strLogMeeage = _T("");
	strLogMeeage.Format(_T("Get Device : %s, Value : 0x%04x(%d), 0x%08x \r\n"), strDevice, *plValue, *plValue, *plReturnCode);
	CUtil::PrintDebugString(strLogMeeage);

	if (SUCCEEDED(hr) && hr == S_OK)
		return TRUE;
	else
		return FALSE;

	return TRUE;
}


BOOL CLPMxComponentPLCCtrl::SetLPMxComponenetPLCCtrlDevice(CString strDevice, long lValue, long* plReturnCode)
{
	CString strTraceMessage = _T("");
	strTraceMessage.Format(_T("NEPES : SetLPMxComponenetPLCCtrlDevice 0 : %s, %d \r\n"), strDevice, lValue);
	OutputDebugString(strTraceMessage);

	HRESULT	hr = S_FALSE;
	switch (m_nPLCProtocolType)
	{
		case TYPE_PLCPROTOCOL_SIMULATION:
		{
			switch (m_nPLCControlType)
			{
			case TYPE_PLCCONTROL_Utility:
			{
				if (m_pIUtlType){
					hr = m_pIUtlType->SetDevice(strDevice.AllocSysString(), lValue, plReturnCode);
				}
			}
			break;
			case TYPE_PLCCONTROL_Program:
			{
				if (m_pIProgType){
					hr = m_pIProgType->SetDevice(strDevice.AllocSysString(), lValue, plReturnCode);
				}
			}
			break;
			}
		}
		break;
		case TYPE_PLCPROTOCOL_TCPIP:
		{
			switch (m_nPLCControlType)
			{
			case TYPE_PLCCONTROL_Utility:
			{
				strTraceMessage.Format(_T("NEPES : m_pIUtlType SetLPMxComponenetPLCCtrlDevice 1 : %s, %d, 0x%08x \r\n"), strDevice, lValue, *plReturnCode);
				OutputDebugString(strTraceMessage);

				if (m_pIUtlType){
					hr = m_pIUtlType->SetDevice(strDevice.AllocSysString(), lValue, plReturnCode);
					if (SUCCEEDED(hr) && hr != S_OK)
					{
						strTraceMessage.Format(_T("============================== NEPES : m_pIUtlType SetLPMxComponenetPLCCtrlDevice Retry Start 1-1 : %s, %d, 0x%08x \r\n"), strDevice, lValue, *plReturnCode);
						OutputDebugString(strTraceMessage);

						hr = m_pIUtlType->SetDevice(strDevice.AllocSysString(), lValue, plReturnCode);

						strTraceMessage.Format(_T("============================== NEPES : m_pIUtlType SetLPMxComponenetPLCCtrlDevice Retry End 1-2 : %s, %d, 0x%08x \r\n"), strDevice, lValue, *plReturnCode);
						OutputDebugString(strTraceMessage);
					}

					strTraceMessage.Format(_T("NEPES : m_pIUtlType SetLPMxComponenetPLCCtrlDevice 2 : %s, %d, 0x%08x \r\n"), strDevice, lValue, *plReturnCode);
					OutputDebugString(strTraceMessage);
				}
			}
			break;
			case TYPE_PLCCONTROL_Program:
			{
				strTraceMessage.Format(_T("NEPES : m_pIProgType SetLPMxComponenetPLCCtrlDevice 1 : %s, %d, 0x%08x \r\n"), strDevice, lValue, *plReturnCode);
				OutputDebugString(strTraceMessage);

				if (m_pIProgType){
					hr = m_pIProgType->SetDevice(strDevice.AllocSysString(), lValue, plReturnCode);

					if (SUCCEEDED(hr) && hr != S_OK)
					{
						strTraceMessage.Format(_T("============================== NEPES : m_pIProgType SetLPMxComponenetPLCCtrlDevice Retry Start 1-1 : %s, %d, 0x%08x \r\n"), strDevice, lValue, *plReturnCode);
						OutputDebugString(strTraceMessage);

						hr = m_pIProgType->SetDevice(strDevice.AllocSysString(), lValue, plReturnCode);

						strTraceMessage.Format(_T("============================== NEPES : m_pIProgType SetLPMxComponenetPLCCtrlDevice Retry End 1-2 : %s, %d, 0x%08x \r\n"), strDevice, lValue, *plReturnCode);
						OutputDebugString(strTraceMessage);
					}

					strTraceMessage.Format(_T("NEPES : m_pIProgType SetLPMxComponenetPLCCtrlDevice 2 : %s, %d, 0x%08x \r\n"), strDevice, lValue, *plReturnCode);
					OutputDebugString(strTraceMessage);
				}
			}
			break;
			}
		}
		break;
	}

	strTraceMessage.Format(_T("NEPES : SetLPMxComponenetPLCCtrlDevice 3 : %s, %d, 0x%08x \r\n"), strDevice, lValue, *plReturnCode);
	OutputDebugString(strTraceMessage);

	CString strLogMeeage = _T("");
	strLogMeeage.Format(_T("Set Device : %s, Value : 0x%04x(%d), 0x%08x \r\n"), strDevice, lValue, lValue, *plReturnCode);
	CUtil::PrintDebugString(strLogMeeage);

	if (SUCCEEDED(hr) && hr == S_OK)
		return TRUE;
	else
		return FALSE;

	return TRUE;
}


BOOL CLPMxComponentPLCCtrl::CloseLPMxComponenetPLCCtrl(long* plReturnCode)
{
	HRESULT hr;

	if (m_pIUtlType)
	{
		hr = m_pIUtlType->Close(plReturnCode);
		m_bOpenIUtil = FALSE;
	}

	if (m_pIProgType)
	{
		hr = m_pIProgType->Close(plReturnCode);
		m_bOpenIProg = FALSE;
	}

	m_bPLCControlOpen = FALSE;

	return TRUE;
}


BOOL CLPMxComponentPLCCtrl::ReleaseLPMxComponenetPLCCtrl()
{
	m_nPLCProtocolType = TYPE_PLCPROTOCOL_NONE;
	m_nPLCControlType = TYPE_PLCCONTROL_NONE;

	if (m_pIUtlType)
		m_pIUtlType->Release();
	if (m_pIProgType)
		m_pIProgType->Release();

	m_bCreateIUtil = FALSE;
	m_bOpenIUtil = FALSE;
	m_pIUtlType = NULL;

	m_bCreateIProg = FALSE;
	m_bOpenIProg = FALSE;
	m_pIProgType = NULL;

	return TRUE;
}




