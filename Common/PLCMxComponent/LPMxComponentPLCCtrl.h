#pragma once

/***********************************************************/
#include "ActUtlType_i.h"		// For ActUtlType Control
#include "ActProgType_i.h"		// For ActProgType Control
#include "ActDefine.h"			// ACT Common Macro Header 

#include "ActMulti.h"			// For ActEasyIF Contorol   
#include "ActEther.h"			// For Ethernet Communication Contorol  
/***********************************************************/

typedef enum TYPE_PLCPROTOCOL
{
	TYPE_PLCPROTOCOL_NONE,
	TYPE_PLCPROTOCOL_SIMULATION,
	TYPE_PLCPROTOCOL_TCPIP,
} _TYPE_PLCPROTOCOL;

typedef enum TYPE_PLCCONTROL
{
	TYPE_PLCCONTROL_NONE,
	TYPE_PLCCONTROL_Utility,
	TYPE_PLCCONTROL_Program,
} _TYPE_PLCCONTROL;


class CLPMxComponentPLCCtrl
{
public:
	CLPMxComponentPLCCtrl();
	~CLPMxComponentPLCCtrl();

/// Get/Set
public:
	IActUtlType*		GetIUtilType() { return m_pIUtlType; }
	IActProgType*       GetIProgType() { return m_pIProgType; }

	BOOL				GetPLCControlOpen() { return m_bPLCControlOpen; }

	int					GetPLCProtocolType() { return m_nPLCProtocolType; }
	void				SetPLCProtocolType(int nPLCProtocolType) { m_nPLCProtocolType = nPLCProtocolType; }
	int					GetPLCContorlType() { return m_nPLCControlType; }
	void				SetPLCContorlType(int nPLCControlType) { m_nPLCControlType = nPLCControlType; }

/// PLC Property Set/Get
	int					GetLogicalStationNumber() { return m_nLogicalStationNumber; }
	void				SetLogicalStationNumber(int nLogicalStationNumber) { m_nLogicalStationNumber = nLogicalStationNumber; }

	int					GetPLCCPUType() { return m_nPLCCPUType; }
	void				SetPLCCPUType(int nPLCCPUType) { m_nPLCCPUType = nPLCCPUType; }

	CString				GetHostAddress() { return m_strHostAddress; }
	void				SetHostAddress(CString strHostAddress) { m_strHostAddress = strHostAddress; }

public:
	void				InitLPMxComponenetPLCCtrl();
	BOOL				CreateLPMxComponenetPLCCtrl();
	BOOL				OpenLPMxComponenetPLCCtrl(long* plReturnCode);
	BOOL				GetLPMxComponenetPLCCtrlCPUType(CString* pstrCpuName, long* plCPUCode, long* plReturnCode);

/// Device
	BOOL				GetLPMxComponenetPLCCtrlDevice(CString strDevice, long* plValue, long* plReturnCode);
	BOOL				SetLPMxComponenetPLCCtrlDevice(CString strDevice, long lValue, long* plReturnCode);

	BOOL				CloseLPMxComponenetPLCCtrl(long* plReturnCode);
	BOOL				ReleaseLPMxComponenetPLCCtrl();

protected:
	BOOL				m_bPLCControlOpen;

	int					m_nPLCProtocolType;
	int					m_nPLCControlType;

/// Utility Type Info
	int					m_nLogicalStationNumber;

/// Network Option
	int					m_nPLCCPUType;
	CString				m_strHostAddress;

protected:
	/************************************/
	BOOL				m_bCreateIUtil;
	BOOL				m_bOpenIUtil;
	IActUtlType*		m_pIUtlType;

	BOOL				m_bCreateIProg;
	BOOL				m_bOpenIProg;
	IActProgType*		m_pIProgType;

};

