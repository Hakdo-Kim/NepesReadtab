#pragma once
//#define DEF_USE_OPENCV
#define DEF_FREERUN_CAPTURE
//#define DEF_DUMP_ETHERNET_PACKET
//#define DEF_DUMP_SERIAL_MESSAGE
#define DEF_DISABLE_DISPLAY_SKIP

//Select Camera
#define USE_BASLER_CAMERA
//#define USE_GIGE_CAMERA
#define USE_VALID_RANGE

#define DEF_SECONDCAMERA_CHECKSIZE		// Second Camera - Activate Size
#define ENABLE_CAMERA_LIBRARY_BASLER

// String
#define MAX_NAME_LEN						128
#define MAX_FILE_PATH_LEN					1024
#define MAX_TEXT_LEN						1024

// CAMERA
#define MAX_CAMERA_INTERFACE				2

// ZOOM
#define DEFAULT_ZOOM_FACTOR					(1.0f)
#define MAX_ZOOM_FACTOR						(2.0f)
#define MIN_ZOOM_FACTOR						(0.1f)
#define INC_ZOOM_FACTOR						(0.01f)


#define CLCAMFILE_MAX						2
#define CLCAMFILE_NORMAL					0
#define CLCAMFILE_TRIGGER					1

// AI
#define AI_ROI_WIDTH						1200
#define AI_ROI_HEIGHT						AI_ROI_WIDTH // 정사각형으로 고정

#define ROI_S								424
#define ROI_E								1624
// Ethernet Adaptor
typedef struct
{
	TCHAR	m_szName[MAX_NAME_LEN];

	TCHAR	m_szIpAddress[MAX_NAME_LEN];
	DWORD	m_dwIpAddress;

} INFO_ETHERNET_ADAPTOR;


#define USE_PLC_MXCOMPONENT

#ifdef USE_PLC_MXCOMPONENT
#include <windows.h>
#include <shellapi.h>

#define STRING_LEN 100
#define TIMEOUT_MS 2000
#define PLC_CHECKTIME_MS 500

#define PLC_CHECKCOUNT_RESULTDELAY 3

#define LPMXCOMPONENT_EXE	_T("LPMXComponentNetPass.exe")
#define TARGETWINDOWTITLE	_T("LPMXComponentDlg")
#define NETPASSWINDOWTITLE  _T("NEPES - ELECTRODE - LDK 2line")

#define PLC_MEMORY_PREFIX _T("W")

#define PLC_DEFAULT_PROTOCOLTYPE	TYPE_PLCPROTOCOL_TCPIP
#define PLC_DEFAULT_CONTROLTYPE		TYPE_PLCCONTROL_Program			// Real PLC mode
//#define PLC_DEFAULT_CONTROLTYPE		TYPE_PLCCONTROL_Utility				// Virtual PLC mode
#define PLC_DEFAULT_STATIONNUMBER	1
#define PLC_DEFAULT_HOSTADDRESS		_T("1.123.10.90")
#define PLC_SET_TIMEOUT				500
#define PLC_SET_RETRYTIME			1

/// LINE1_FIRST
#define MEMORY0 0x00
#define MEMORY1 0x20
#define MEMORY2 0x02
#define MEMORY3 0x03
#define MEMORY4 0x04
#define MEMORY5 0x05
#define MEMORY6 0x06
#define MEMORY7 0x0A
#define MEMORY8 0x2A
#define MEMORY9 0x40
// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
#define MEMORY10 0x0C
#define MEMORY11 0x0E
// Version 1.3.7.2
#define MEMORY12 0x80
#define MEMORY13 0x82
// Version 1.3.7.4
#define MEMORY14 0x84
// Version 1.3.7.7 (PC - PLC 시간 동기화)
#define MEMORY15 0x3A
#define MEMORY16 0x3B
#define MEMORY17 0x3C
#define MEMORY18 0x3D
#define MEMORY19 0x3E
#define MEMORY20 0x3F


#define PLC_HEATER_MAX 26

typedef enum TYPE_LINE
{
	TYPE_LINE_1 = 0,
	TYPE_LINE_2,
} _TYPE_LINE;

typedef enum TYPE_POS
{
	TYPE_POS_FIRST = 0,
	TYPE_POS_SECOND,
	TYPE_POS_MAX,
} _TYPE_POS;

typedef enum TYPE_STATE
{
	TYPE_STATE_VISION_SENDINSPECTION = 0,	// W0
	TYPE_STATE_PLC_SENDINSPECTION,			// W20
	TYPE_STATE_ALL_RESULTSIZE,				// W2
	TYPE_STATE_ALL_RESULTSHAPE,				// W3
	TYPE_STATE_ALL_AVERAGESIZE,				// W4
	TYPE_STATE_ALL_VALUESIZE,				// W5
	TPYE_STATE_VISION_LIVEBIT,				// W6
	TPYE_STATE_TEMPERATURE,					// WA
	TPYE_STATE_TEMPERATURE_REQUEST,			// W2A
	TPYE_STATE_TEMPERATURE_SUB,				// W40
	// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
	TYPE_STATE_ALL_LVALUESIZE,				// W0C
	TYPE_STATE_ALL_X1X2VALUESIZE,			// W0E
	// Version 1.3.7.2 (M1, M2)
	TYPE_STATE_ALL_M1VALUESIZE,				// 80
	TYPE_STATE_ALL_M2VALUESIZE,				// 82
	// Version 1.3.7.4 (S1S3)
	TYPE_STATE_ALL_S1S3VALUESIZE,			// 84
	// Version 1.3.7.7
	TYPE_STATE_PLCSYNC_YEAR,				// 3A
	TYPE_STATE_PLCSYNC_MONTH,				// 3B
	TYPE_STATE_PLCSYNC_DATE,				// 3C
	TYPE_STATE_PLCSYNC_HOUR,				// 3D
	TYPE_STATE_PLCSYNC_MINUTE,				// 3E
	TYPE_STATE_PLCSYNC_SECOND				// 3F

} _TYPE_STATE;

typedef enum TYPE_Command
{
	TYPE_COMMAND_SETTING = 0,
	TYPE_COMMAND_OPENCOM,
	TYPE_COMMAND_GETCPUTYPE,
	TYPE_COMMAND_GETDEVICE,
	TYPE_COMMAND_SETDEVICE,
	TYPE_COMMAND_CLOSECOM,
	TYPE_COMMAND_CLOSEPROGRAM,
	TYPE_COMMAND_WINDOWSHOWHIDE
} _TYPE_Command;

typedef struct INFO_PLCMEMORYMAP
{
	long lVISION_SENDINSPECTION;
	long lPLC_SENDINSPECTION;
	long lALL_RESULTSIZE;
	long lALL_RESULTSHAPE;
	long lALL_AVERAGESIZE;
	long lALL_VALUESIZE;
	long lPLC_CURCASSETTE;
	long lPLC_SETCASSETTE;
	INFO_PLCMEMORYMAP()
	{
		lVISION_SENDINSPECTION = 0;
		lPLC_SENDINSPECTION = 0;
		lALL_RESULTSIZE = 0;
		lALL_RESULTSHAPE = 0;
		lALL_AVERAGESIZE = 0;
		lALL_VALUESIZE = 0;
		lPLC_CURCASSETTE = 0;
		lPLC_SETCASSETTE = 0;
	}
} _INFO_PLCMEMORYMAP;

typedef struct INFO_PLCMEMORYMAPDATA
{
	INFO_PLCMEMORYMAP m_stCurMemoryMap;
	INFO_PLCMEMORYMAP m_stOldMemoryMap;
	INFO_PLCMEMORYMAPDATA()
	{
	}
} INFO_PLCMEMORYMAPDATA;

typedef struct stLPMXComponentCommnd
{
	int 		bControlOpened;
	int			nCommandType;
	int			nPLCProtocolType;
	int			nPLCControlType;
	int			nPLCStationNumber;
	int			nPortNum;
	long		lCpuCode;
	long		lGetValue;
	long		lSetValue;
	long		lRet;
	int			nCameraPos;
	int			bWindowShow;
	char		szHostAddress[STRING_LEN];
	char		szCpuName[STRING_LEN];
	char		szDeviceName[STRING_LEN];

	stLPMXComponentCommnd()
	{
		bControlOpened = FALSE;
		nCommandType = 0;
		nPLCProtocolType = 0;
		nPLCControlType = 0;
		nPLCStationNumber = 1;
		nPortNum = 0;
		lCpuCode = 0;
		lGetValue = 0;
		lSetValue = 0;
		lRet = 0;
		nCameraPos = 0;
		bWindowShow = FALSE;
		memset(szHostAddress, 0x00, STRING_LEN);
		memset(szCpuName, 0x00, STRING_LEN);
		memset(szDeviceName, 0x00, STRING_LEN);
	}
} _stLPMXComponentCommnd;

#endif   
