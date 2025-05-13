#pragma once

#include "Common.h"

// CAMERA INTERFACE
typedef enum
{
	TYPE_NETWORK_NONE,

	// Giga Ethernet - Network camera
	TYPE_NETWORK_GIGE,
	// Ethernet - Network camera
	TYPE_NETWORK_ETHERNET,
	// USB - Network camera
	TYPE_NETWORK_USB,
	// Camera Link - Network camera
	TYPE_NETWORK_CAMERALINK,
	// EMUL - File camera
	TYPE_NETWORK_EMULFILE,
	// GigE 3D Camera
	TYPE_NETWORK_GIGE_3D,

	// Serial
	TYPE_NETWORK_SERIAL,
	TYPE_NETWORK_CAMERALINK_SERIAL,


	// Other Manufacturer
	TYPE_NETWORK_BAUMER,		// Baumer GigE & USB
	TYPE_NETWORK_BASLER,		// Basler GigE & USB

	TYPE_NETWORK_WEBCAM,

	TYPE_NETWORK_MAX,

} TYPE_NETWORK;

typedef enum
{
	TYPE_PROTOCOL_NONE,

	TYPE_PROTOCOL_TCP,
	TYPE_PROTOCOL_UDP,
	TYPE_PROTOCOL_UDP_BROADCAST,

	TYPE_PROTOCOL_MAX,

} TYPE_PROTOCOL;

typedef enum
{
	TYPE_CAMCOLOR_NONE,

	TYPE_CAMCOLOR_MONO,
	TYPE_CAMCOLOR_COLOR,

	TYPE_CAMCOLOR_MAX,

} TYPE_CAMCOLOR;

typedef enum
{
	TYPE_CAMCOLORFORMAT_NONE,

	TYPE_CAMCOLORFORMAT_MONO,

	TYPE_CAMCOLORFORMAT_BAYER_GR,
	TYPE_CAMCOLORFORMAT_BAYER_RG,
	TYPE_CAMCOLORFORMAT_BAYER_GB,
	TYPE_CAMCOLORFORMAT_BAYER_BG,

	TYPE_CAMCOLORFORMAT_YUV,

	TYPE_CAMCOLORFORMAT_MAX,

} TYPE_CAMCOLORFORMAT;

typedef enum
{
	TYPE_DATABIT_NONE,

	TYPE_DATABIT_08,
	TYPE_DATABIT_10,
	TYPE_DATABIT_12,
	TYPE_DATABIT_16,
	TYPE_DATABIT_24,
	TYPE_DATABIT_32,
	TYPE_DATABIT_36,
	TYPE_DATABIT_48,

	TYPE_DATABIT_MAX,

} TYPE_DATABIT;

typedef enum
{
	TYPE_TRIGGERTYPE_NONE,

	TYPE_TRIGGERTYPE_EDGE,
	TYPE_TRIGGERTYPE_LEVEL,

	TYPE_TRIGGERTYPE_MAX

} TYPE_TRIGGERTYPE;


typedef enum
{
	TYPE_CLGRABBER_NONE,

	TYPE_CLGRABBER_EURESYS,
	TYPE_CLGRABBER_SILICONSOFTWARE,
	TYPE_CLGRABBER_MATROX,
	TYPE_CLGRABBER_DALSA,

	TYPE_CLGRABBER_MAX,

} TYPE_CLGRABBER;


typedef enum
{
	TYPE_CLDEVICE_NONE,
	TYPE_CLDEVICE_UNKNOWN,

	TYPE_CLDEVICE_2M,
	TYPE_CLDEVICE_4M,
	TYPE_CLDEVICE_25M,
	TYPE_CLDEVICE_N25M,

	TYPE_CLDEVICE_MAX,

} TYPE_CLDEVICE;

typedef enum
{
	TYPE_CLIMGTAPS_NONE,

	TYPE_CLIMGTAPS_02,
	TYPE_CLIMGTAPS_04,
	TYPE_CLIMGTAPS_08,
	TYPE_CLIMGTAPS_10,

	TYPE_CLIMGTAPS_MAX,

} TYPE_CLIMGTAPS;

typedef enum
{
	TYPE_CLDATABIT_NONE,

	TYPE_CLDATABIT_08,
	TYPE_CLDATABIT_10,

	TYPE_CLDATABIT_MAX,

} TYPE_CLDATABIT;


//
typedef struct
{
	DWORD m_dwWidth;
	DWORD m_dwHeight;
	DWORD m_dwPitch;

	BYTE m_nBit;

} INFO_IMAGEBUF;

typedef struct
{
	BOOL	m_bVariable;

	DWORD	m_dwMaxWidth;
	DWORD	m_dwMaxHeight;
	DWORD	m_dwMaxPitch;

	DWORD	m_dwX;
	DWORD	m_dwY;
	DWORD	m_dwWidth;
	DWORD	m_dwHeight;

	DWORD	m_dwPitch;

	TYPE_CAMCOLOR		m_eColor;
	TYPE_DATABIT		m_eDataBit;
	TYPE_CAMCOLORFORMAT	m_eColorFormat;
	TYPE_DATABIT		m_eColorBit;

	TYPE_NETWORK		m_eNetwork;

} INFO_FRAME;

typedef struct
{
	TCHAR	m_szName[MAX_NAME_LEN];
	TCHAR	m_szPath[MAX_FILE_PATH_LEN];

	DWORD	m_dwFps;
	BOOL	m_bCycleDir;


	BOOL	m_bCameraEmul;

	SIZE	m_stResolution;
	RECT	m_stRoi;

} INFO_EMUL;

typedef struct
{
	TCHAR	m_szName[MAX_NAME_LEN];

	// Grabber & Camera Information
	TYPE_CLGRABBER	m_eClFrameGrabber;
	TYPE_CLDEVICE	m_eClDevice;
	TYPE_CLIMGTAPS	m_eClImageTaps;
	TYPE_CLDATABIT	m_eClDataBit;
	TYPE_CAMCOLOR	m_eClColor;

#ifdef ENABLE_FRAMEGRABBER_DALSA_CL
	// Dalsa Framegrabber Only
	TCHAR	m_szServerName[MAX_NAME_LEN];
	TCHAR	m_szDeviceName[MAX_NAME_LEN];
	BYTE	m_nDeviceIndex;
#endif

	// Serial Information
	TCHAR	m_szSerial[MAX_NAME_LEN];
	DWORD	m_dwSpeed;

} INFO_CAMERALINK;

typedef struct
{
	TCHAR m_szFileName[MAX_NAME_LEN];
	TCHAR m_szPathName[MAX_FILE_PATH_LEN];

	INFO_IMAGEBUF m_stImgBuf;

} INFO_FILE;

typedef struct
{
	TCHAR	m_szPortName[MAX_NAME_LEN];
	TCHAR	m_szFriendlyName[MAX_NAME_LEN];
	TCHAR	m_szTechnology[MAX_NAME_LEN];

} INFO_SERIAL;


typedef struct
{
	TYPE_NETWORK	m_eNetwork;

	TCHAR	m_szArg[MAX_NAME_LEN];
	DWORD	m_dwArg;

} INFO_CONNECT_DEV;

typedef struct
{
	INFO_CONNECT_DEV	m_stArg;

	// ETC
	INFO_SERIAL m_stSerial;

} INFO_CONNECT_SERIAL;

typedef struct
{
	INFO_CONNECT_DEV	m_stArg;

	TYPE_PROTOCOL	m_eProtocol;

	// ETC
	TCHAR	m_szName[MAX_NAME_LEN];
	TCHAR	m_szIpAddress[MAX_NAME_LEN];
	TCHAR	m_szSerialNumber[MAX_NAME_LEN];

	//
	DWORD	m_dwIpAddress;
	DWORD	m_dwSubnetMask;
	DWORD	m_dwGateWay;

} INFO_CONNECT_ETHERNET;

typedef struct
{
	INFO_CONNECT_DEV	m_stArg;

	// ETC
	TCHAR	m_szName[MAX_NAME_LEN];
	TCHAR	m_szIpAddress[MAX_NAME_LEN];
	TCHAR	m_szSerialNumber[MAX_NAME_LEN];

	//
	DWORD	m_dwIpAddress;
	DWORD	m_dwSubnetMask;
	DWORD	m_dwGateWay;

} INFO_CONNECT_GIGE;

typedef struct
{
	INFO_CONNECT_DEV	m_stArg;

	//
	DWORD	m_CamID;
	TCHAR	m_szName[MAX_NAME_LEN];

	TYPE_CLGRABBER	m_eClFrameGrabber;
	TYPE_CLDEVICE	m_eClDevice;
	TYPE_CLIMGTAPS	m_eClImageTaps;
	TYPE_CLDATABIT	m_eClDataBit;
	TYPE_CAMCOLOR	m_eClColor;
	TCHAR			m_szCamFile[CLCAMFILE_MAX][MAX_FILE_PATH_LEN];

#ifdef ENABLE_FRAMEGRABBER_DALSA_CL
	// Dalsa Only
	TCHAR	m_szServerName[MAX_NAME_LEN];
	TCHAR	m_szDeviceName[MAX_NAME_LEN];
	BYTE	m_nDeviceIndex;
#endif

	//
	TCHAR	m_szSerial[MAX_NAME_LEN];
	DWORD	m_dwSpeed;


} INFO_CONNECT_CAMERALINK;

typedef struct
{
	INFO_CONNECT_DEV	m_stArg;

	// ETC
	DWORD	m_CamID;
	TCHAR	m_szName[MAX_NAME_LEN];

	TCHAR	m_szFilePath[MAX_FILE_PATH_LEN];
	TCHAR	m_szDirPath[MAX_FILE_PATH_LEN];

	DWORD	m_dwFps;
	BOOL	m_bCycleDir;


	BOOL	m_bCameraEmulator;
	INFO_FRAME	m_stFrame;


} INFO_CONNECT_EMUL;


typedef struct
{
	BOOL m_bEnable;

	int m_nWidth;
	int m_nHeight;
	int m_nBitCount;
	DWORD m_dwBiCompress;

} INFO_VINFO_WEBCAM;

typedef struct
{
	INFO_CONNECT_DEV	m_stArg;

	// ETC
	DWORD	m_CamID;
	TCHAR	m_szName[MAX_NAME_LEN];

	INFO_VINFO_WEBCAM m_stCurVINFO;
	INFO_VINFO_WEBCAM m_pstVInfoList[MAX_NAME_LEN];


} INFO_CONNECT_WEBCAM;


typedef struct
{
	INFO_CONNECT_DEV	m_stArg;

	// ETC
	TCHAR	m_szName[MAX_NAME_LEN];
	int  	m_szIndex;
	TCHAR	m_szSerialNumber[MAX_NAME_LEN];

	DWORD	m_dwSensorType;

} INFO_CONNECT_USB;

typedef struct
{
	INFO_CONNECT_DEV	m_stArg;

	// Manufacturer
	TCHAR	m_szManufacturer[MAX_NAME_LEN];

	// Other Camera Information
	TYPE_NETWORK m_eCameraType;
	TCHAR	m_szName[MAX_NAME_LEN];

} INFO_CONNECT_OTHER_MANUFACTURER;



#ifdef ENABLE_FRAMEGRABBER_DALSA_CL
// Only Dalsa Framegrabber 
typedef struct
{
	TCHAR* m_pListAcqServer;

	TCHAR** m_ppListAcqDevice;
	int m_nDeviceCount;

} INFO_DALSA_LOCATION;
#endif


////
#define TRIGGER_ON						1
#define TRIGGER_OFF						0

#define TRIGGER_SRC_SW					1
#define TRIGGER_SRC_LINE				0

#define TRIGGER_EDGE_NEGATIVE			0
#define TRIGGER_EDGE_POSITIVE			1
#define TRIGGER_LEVEL_NEGATIVE			2
#define TRIGGER_LEVEL_POSITIVE			3

#define STROBE_ON						1
#define STROBE_OFF						0

#define STROBE_SYNC_EXPOSURE			0
#define STROBE_SYNC_BYPASS				1

#define STROBE_POLA_NEGATIVE			0
#define STROBE_POLA_POSITIVE			1

#define GAIN_DIGITAL_ADC				1	// ADC
#define GAIN_ANALOG_PGA					2	// PGA

// USB SENSOR TYPE
#define USBSENSOR_UNKNOWN				0
#define USBSENSOR_VGA_MONO_CMOSIS		1
#define USBSENSOR_4M_MONO				2
#define USBSENSOR_2M_MONO				3
#define USBSENSOR_4M_COLOR				4
#define USBSENSOR_VGA_MONO_PYTHON		5
#define USBSENSOR_VGA_COLOR_PYTHON		6
#define USBSENSOR_1_2M_MONO				7
#define USBSENSOR_1_2M_COLOR			8
#define USBSENSOR_5M_MONO				9
#define USBSENSOR_10M_MONO				10


typedef struct
{
	unsigned int		m_nImageCount;
	float				m_fFrameRate;
	float				m_fBitRate;
	unsigned int		m_nSkipCnt;

} INFO_DIAGONOSTICS_USB;

typedef struct
{
	unsigned long               nDisplaySkipCount; // skipped displaying images 
	unsigned long               nFrameSkipCount;   // skipped frames
	unsigned long               nImageFrameCount;  // # of frames
	unsigned long				nRecvResend;

	unsigned long				nRequestResend;    // sdk or from camera reg
	float						fFrameRate;
	int							Mbps;              // del

} INFO_DIAGONOSTICS_GIGE;


typedef struct
{
	UINT              nTriggerMode;           // trigger on off 
	UINT              nTriggerSource;         // sw trigger or line trigger
	UINT              nTriggerTypePolarity;   // edge or level,  active low or high
	UINT			  nTriggerDelay;          // trigger exposure delay

} INFO_TRIGGER_PARA;

typedef struct
{
	UINT              nStrobeMode;
	UINT              nStrobeSync;
	UINT              nStrobePolarity;
	UINT              nStrobeWidth;
	UINT			  nStrobeDelay;

} INFO_STROBE_PARA;

typedef struct
{
	UINT              nXstart;
	UINT              nYstart;
	UINT              nWidth;
	UINT			  nHeight;
	UINT              nMaxWidth;
	UINT			  nMaxHeight;

} INFO_ROI_PARA;

typedef struct
{
	POINT* m_PointList;
	int m_nPointLen;

	int m_nIndex;

} INFO_LUT_PARA;


typedef void (CALLBACK *FuncAcquisitionEvent)(unsigned char*, unsigned int, void*, void*);



// 
#define MAX_CATEGORY_LIST					64

#define OTHER_OPCODE_READ					0x001
#define OTHER_OPCODE_WRITE					0x002
#define OTHER_OPCODE_COMMAND				0x004

typedef enum
{
	TYPE_OTHER_INTERFACE_NONE,

	TYPE_OTHER_INTERFACE_INTEGER,
	TYPE_OTHER_INTERFACE_FLOAT,
	TYPE_OTHER_INTERFACE_STRING,
	TYPE_OTHER_INTERFACE_ENUM,
	TYPE_OTHER_INTERFACE_COMMAND,
	TYPE_OTHER_INTERFACE_BOOLEAN,
	TYPE_OTHER_INTERFACE_REGISTER,
	TYPE_OTHER_INTERFACE_CATEGORY,

	TYPE_OTHER_INTERFACE_MAX,

} TYPE_OTHER_INTERFACE;



// Interface Information
typedef struct
{
	TYPE_OTHER_INTERFACE m_eInterface;
	DWORD m_dwAccess;

	TCHAR* m_pszName;				// For XML Node 
	TCHAR* m_pszDisplayName;		// For UI Display

} INFO_OTHER_IF;


typedef struct
{
	INFO_OTHER_IF m_stInterface;

	INFO_OTHER_IF* m_pListInterface[MAX_CATEGORY_LIST];
	int m_nListLen;

} INFO_OTHER_CATEGORY;

typedef struct
{
	INFO_OTHER_IF m_stInterface;

	int m_nMin;
	int m_nMax;
	int m_nInc;

	int m_nCur;

} INFO_OTHER_INTEGER;

typedef struct
{
	INFO_OTHER_IF m_stInterface;

	double m_fMin;
	double m_fMax;
	double m_fInc;

	double m_fCur;

} INFO_OTHER_FLOAT;

typedef struct
{
	INFO_OTHER_IF m_stInterface;

	TCHAR* m_pString;

} INFO_OTHER_STRING;


typedef struct
{
	TCHAR* m_pszName;
	DWORD  m_dwValue;

} INFO_OTHER_ENUM_ITEM;

typedef struct
{
	INFO_OTHER_IF m_stInterface;

	INFO_OTHER_ENUM_ITEM* m_pItemList;
	int m_nItemList;

	DWORD m_dwCurValue;

} INFO_OTHER_ENUM;

typedef struct
{
	INFO_OTHER_IF m_stInterface;

} INFO_OTHER_COMMAND;

typedef struct
{
	INFO_OTHER_IF m_stInterface;
	BOOL m_bCur;

} INFO_OTHER_BOOLEAN;



// Interface Value...
typedef struct
{
	TYPE_OTHER_INTERFACE m_eInterface;
} VALUE_OTHER;

typedef struct
{
	VALUE_OTHER m_stInterfae;
	int m_nValue;

} VALUE_OTHER_INTEGER;

typedef struct
{
	VALUE_OTHER m_stInterfae;
	double m_fValue;

} VALUE_OTHER_FLOAT;

typedef struct
{
	VALUE_OTHER m_stInterfae;
	TCHAR* m_pValue;

} VALUE_OTHER_STRING;

typedef struct
{
	VALUE_OTHER m_stInterfae;
	DWORD m_dwValue;

} VALUE_OTHER_ENUM;

typedef struct
{
	VALUE_OTHER m_stInterfae;
	BOOL m_bValue;

} VALUE_OTHER_BOOLEAN;

