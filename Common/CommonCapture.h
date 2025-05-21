#pragma once

#include "Common.h"
#include "Tracker/TrackerLibrary.h"
#include "NAVIApp.h"
//#define DEF_EMUL_STROBE
//#define DEF_OLD_STROBE				//기존 조명 컨트롤러 사용할때 
#define DEF_DELAY_CAPTURE

//#define DEF_APPLY_SETTING

//#define DEF_PROTOCOL_PROGRAM

#define DEF_SKIP_SECONDCAMERA

#define DEF_ETHERNET_SERVER
#ifdef DEF_ETHERNET_SERVER
#	define DEF_TIMER_CHECK_ADAPTOR
#   define MSEC_CHECK_ADAPTOR		5000
#endif

#define DEF_STROBE_RING_4CHto1CH

#define MAX_VIEW					2
#define FIRST_VIEW					0
#define SECOND_VIEW					1

#define DEF_CMD_RESULT_OK			1
#define DEF_CMD_RESULT_NG			2

#define DEF_CMD_ALARM_OFF			1	// OK Condition
#define DEF_CMD_ALARM_ON			2	// NG Condition

#define MAX_CASSETTE_LIST			4
#define MAX_STEPNAME_LENGTH			4
#define MAX_STEPSTROBE_LIST			2


typedef enum
{
	TYPE_CAMERAPOS_NONE,

	TYPE_CAMERAPOS_FIRST,
	TYPE_CAMERAPOS_SECOND,

	TYPE_CAMERAPOS_MAX,

} TYPE_CAMERAPOS;

typedef enum
{
	TYPE_STEP_NONE,

	TYPE_STEP_001,
	TYPE_STEP_002,
	TYPE_STEP_003,
	TYPE_STEP_004,
	TYPE_STEP_005,
	TYPE_STEP_006,
	TYPE_STEP_007,

	TYPE_STEP_MAX,

} TYPE_STEP;

typedef enum
{
	TYPE_STROBE_NONE,

	TYPE_STROBE_OFF,
	TYPE_STROBE_COXIAL,
	TYPE_STROBE_RING,
	TYPE_STROBE_BAR,

	TYPE_STROBE_MAX,

} TYPE_STROBE;

typedef enum
{
	TYPE_TAPVIEW_NONE,

	TYPE_TAPVIEW_SUMMARY,
	TYPE_TAPVIEW_SIZE,
	TYPE_TAPVIEW_SCENARIO,
	TYPE_TAPVIEW_COUNT,

	TYPE_TAPVIEW_MAX,

} TYPE_TAPVIEW;


// Strobe Channel
#define FIRST_STROBE_CH_BAR					1
#define FIRST_STROBE_CH_COAX				2
#define FIRST_STROBE_CH_RING_1CH			4

#define SECOND_STROBE_CH_BAR				9
#define SECOND_STROBE_CH_COAX				10
#define SECOND_STROBE_CH_RING_1CH			12

#define MAX_STROBE_CH						16


#ifdef DEF_STROBE_RING_4CHto1CH
#define STROBE_MAX_BRIGHT_RING				160
#else
#define STROBE_MAX_BRIGHT_RING				40
#endif
#define STROBE_MAX_BRIGHT_BAR				255
#define STROBE_MAX_BRIGHT_COAX				60

#define STROBE_MIN_BRIGHT_RING				0
#define STROBE_MIN_BRIGHT_BAR				0
#define STROBE_MIN_BRIGHT_COAX				0





// Registry Path
#define REG_ROOT_PATH						_T("Software\\LAONPEOPLE\\NEPES\\ELECTRODE")

#define REG_VALUE_CAPTURE_LOCATION			_T("Location")

#define REG_VALUE_CAMERA_FIRST				_T("CameraFirst")
#define REG_VALUE_CAMERA_SECOND				_T("CameraSecond")

#define REG_VALUE_STROBECONTROLLERTYPE		_T("StrobeControllerType")

#define REG_VALUE_SERIALPORT_FIRST			_T("SerialPortFirst")
#define REG_VALUE_SERIALSPEED_FIRST			_T("SerialSpeedFirst")

#define REG_VALUE_SERIALPORT_SECOND			_T("SerialPortSecond")
#define REG_VALUE_SERIALSPEED_SECOND		_T("SerialSpeedSecond")

#define REG_VALUE_ETHERNETIP_MACHINE		_T("EthernetIpMachine")
#define REG_VALUE_ETHERNETPORT_MACHINE		_T("EthernetPortMachine")
#define REG_VALUE_ETHERNETPROTOCOL_MACHINE	_T("EthernetProtocolMachine")
#define REG_VALUE_ETHERNETTYPE_MACHINE		_T("EthernetTypeMachine")

#ifdef USE_PLC_MXCOMPONENT
#define REG_VALUE_PLC_PROTOCOLTYPE			_T("PLCProtocolType")
#define RED_VALUE_PLC_CONTROLTYPE			_T("PLCControlType")
#define RED_VALUE_PLC_STATIONNUMER			_T("PLCStationNum")
#define RED_VALUE_PLC_TCPHOSTADDRESS		_T("PLCTCPHostAddress")
#define RED_VALUE_PLC_TCPPORTUMER			_T("PLCTCPPortNum")
#define RED_VALUE_LINE_LINENUMER			_T("LineNumberNum")
#endif

#define REG_VALUE_FIRSTCAMERA_REVERSEX		_T("FirstCameraReverseX")
#define REG_VALUE_FIRSTCAMERA_REVERSEY		_T("FirstCameraReverseY")
#define REG_VALUE_SECONDCAMERA_REVERSEX		_T("SecondCameraReverseX")
#define REG_VALUE_SECONDCAMERA_REVERSEY		_T("SecondCameraReverseY")

#define REG_VALUE_OPTION_LOTIDPATH			_T("OptLotIdPath")
#define REG_VALUE_OPTION_LOGPATH			_T("OptLogPath")
#define REG_VALUE_OPTION_SAVETEXT			_T("OptSaveText")
#define REG_VALUE_OPTION_SAVEERRORIMAGE		_T("OptSaveEImage")
#define REG_VALUE_OPTION_SAVEPROBIMAGE		_T("OptSavePImage")
// Version 1.3.8.1 
#define REG_VALUE_OPTION_SAVEIMAGECOMPRESS	_T("OptSaveImageCompress")

#define REG_VALUE_OPTION_SAVEIMAGEFORMAT	_T("OptSaveImageFormat")
#define REG_VALUE_OPTION_SAVEOKIMAGE		_T("OptSaveOKImage")
#define REG_VALUE_OPTION_IMAGECOUNT			_T("OptPNGCount")
// Version 1.3.7.6 Save OK Image Period
#define REG_VALUE_OPTION_PERIOD_CHECK		_T("OptPeriodOKImage")
#define REG_VALUE_OPTION_PERIOD_TIME		_T("OptPeriodTime")

#define REG_VALUE_SECOND_ROTATE				_T("SecondCameraRotate")


// SIZE
typedef enum
{
	TYPE_FINDLINE_METAL_TOP,
	TYPE_FINDLINE_METAL_RIGHT,
	TYPE_FINDLINE_METAL_BOTTOM,
	TYPE_FINDLINE_METAL_LEFT,

	TYPE_FINDLINE_TAPE_LEFTWING_TOP,
	TYPE_FINDLINE_TAPE_LEFTWING_LEFT,
	TYPE_FINDLINE_TAPE_LEFTWING_BOTTOM,

	TYPE_FINDLINE_TAPE_CENTER_TOP,
	TYPE_FINDLINE_TAPE_CENTER_TOPLEFT,
	TYPE_FINDLINE_TAPE_CENTER_TOPRIGHT,
	TYPE_FINDLINE_TAPE_CENTER_BOTTOM,
	TYPE_FINDLINE_TAPE_CENTER_BOTTOMLEFT,
	TYPE_FINDLINE_TAPE_CENTER_BOTTOMRIGHT,

	TYPE_FINDLINE_TAPE_RIGHTWING_TOP,
	TYPE_FINDLINE_TAPE_RIGHTWING_RIGHT,
	TYPE_FINDLINE_TAPE_RIGHTWING_BOTTOM,

	TYPE_FINDLINE_MAX,
} TYPE_FINDLINE;

typedef enum
{
	TYPE_GEOMETRY_POINT_METAL_TOPRIGHT,
	TYPE_GEOMETRY_POINT_METAL_BOTTOMRIGHT,
	TYPE_GEOMETRY_POINT_METAL_BOTTOMLEFT,
	TYPE_GEOMETRY_POINT_METAL_TOPLEFT,

	TYPE_GEOMETRY_POINT_TAPE_LEFTWING_BOTTOM,		// Tape 왼쪽 끝 아래 꼭지점
	TYPE_GEOMETRY_POINT_TAPE_LEFTWING_TOP,			// Tape 왼쪽 끝 위 꼭지점

	TYPE_GEOMETRY_POINT_TAPE_CENTER_TOPLEFT,		// Tape 위 경계선과 Metal 왼쪽 경계선의 교차점
	TYPE_GEOMETRY_POINT_TAPE_CENTER_TOPRIGHT,		// Tape 위 경계선과 Metal 오른쪽 경계선의 교차점

	TYPE_GEOMETRY_POINT_TAPE_RIGHTWING_TOP,			// Tape 오른쪽 끝 위 꼭지점
	TYPE_GEOMETRY_POINT_TAPE_RIGHTWING_BOTTOM,		// Tape 오른쪽 끝 아래 꼭지점

	TYPE_GEOMETRY_POINT_TAPE_LEFTWING_TOP_CENTER,	// Tape 테이프 왼쪽 위 중간 꼭지점
	TYPE_GEOMETRY_POINT_TAPE_RIGHTWING_TOP_CENTER,	// Tape 테이프 오른쪽 위 중간 꼭지점

	TYPE_GEOMETRY_POINT_MAX,
} TYPE_GEOMETRY_POINT;

typedef enum
{
	TYPE_GEOMETRY_DISTANCE_D,		// Metal 너비
	TYPE_GEOMETRY_DISTANCE_L,		// Metal 높이
	TYPE_GEOMETRY_DISTANCE_W,		// Tape 길이

	TYPE_GEOMETRY_DISTANCE_I1,		// Tape 높이 (좌)
	TYPE_GEOMETRY_DISTANCE_I2,		// Tape 높이 (중앙)
	TYPE_GEOMETRY_DISTANCE_I3,		// Tape 높이 (우)

	TYPE_GEOMETRY_DISTANCE_M1,		// Metal 경계선부터 Tape의 길이 (좌)
	TYPE_GEOMETRY_DISTANCE_M2,		// Metal 경계선부터 Tape의 길이 (우)

	TYPE_GEOMETRY_DISTANCE_S1,		// Metal 상부와 Tape 상부 간격 (좌)
	TYPE_GEOMETRY_DISTANCE_S2,		// Metal 상부와 Tape 상부 간격 (중앙)
	TYPE_GEOMETRY_DISTANCE_S3,		// Metal 상부와 Tape 상부 간격 (우)
	TYPE_GEOMETRY_DISTANCE_S4,		// Metal 상부와 Tape 상부 간격 (Metal 밖 좌측)
	TYPE_GEOMETRY_DISTANCE_S5,		// Metal 상부와 Tape 상부 간격 (Metal 밖 우측)
	


	TYPE_GEOMETRY_DISTANCE_X1,		// Metal의 대각선 길이 (왼쪽 위 ~ 오른쪽 아래)
	TYPE_GEOMETRY_DISTANCE_X2,		// Metal의 대각선 길이 (오른쪽 위 ~ 왼쪽 아래)

	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	TYPE_GEOMETRY_DISTANCE_R1,		// Tape 상부 (좌) 1촬영 - 2촬영 
	TYPE_GEOMETRY_DISTANCE_R2,		// Tape 상부 (중) 1촬영 - 2촬영 
	TYPE_GEOMETRY_DISTANCE_R3,		// Tape 상부 (우) 1촬영 - 2촬영 
	TYPE_GEOMETRY_DISTANCE_R4,		// Tape 하부 (좌) 1촬영 - 2촬영 
	TYPE_GEOMETRY_DISTANCE_R5,		// Tape 하부 (중) 1촬영 - 2촬영 
	TYPE_GEOMETRY_DISTANCE_R6,		// Tape 하부 (우) 1촬영 - 2촬영 
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	TYPE_GEOMETRY_DISTANCE_SS1,		// Metal 하부와 Tape 하부 간격 (좌)
	TYPE_GEOMETRY_DISTANCE_SS2,		// Metal 하부와 Tape 하부 간격 (중앙)
	TYPE_GEOMETRY_DISTANCE_SS3,		// Metal 하부와 Tape 하부 간격 (우)

	TYPE_GEOMETRY_DISTANCE_X1X2,	// X1-X2
	TYPE_GEOMETRY_DISTANCE_S1S3,	// S1-S3
	TYPE_GEOMETRY_DISTANCE_M1M2,	// M1-M2
	// Version 1.3.7.6 SS1 ~ SS3
	TYPE_GEOMETRY_DISTANCE_SS1SS3,	// SS1-SS3

	TYPE_GEOMETRY_DISTANCE_MAX,
} TYPE_GEOMETRY_DISTANCE;

typedef enum
{
	TYPE_SIZE_VALID_S,
	TYPE_SIZE_VALID_D,
	// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
	TYPE_SIZE_VALID_L,
	// Version 1.3.7.2 (M1, M2)
	TYPE_SIZE_VALID_M1,
	TYPE_SIZE_VALID_M2,
	// Version 1.3.6.5 (치수 영역 추가 없이 PLC 통신 데이터 추가 (X1-X2, L))
	TYPE_SIZE_VALID_X1X2,
	// Version 1.3.7.4 (S1S3)
	TYPE_SIZE_VALID_S1S3,

	TYPE_SIZE_VALID_MAX
} TYPE_SIZE_COMM;

#define GEOMETRY_DISTANCE_DIFFERENCE_COUNT	(TYPE_GEOMETRY_DISTANCE_MAX - TYPE_GEOMETRY_DISTANCE_X1X2)
#define MAX_GEOMETRY_DISTANCELINE_COUNT 	(TYPE_GEOMETRY_DISTANCE_MAX - GEOMETRY_DISTANCE_DIFFERENCE_COUNT) // X1X2, S1S3, M1M2를 뺀 나머지 거리 측정 위치 표시 개수

#define MAX_SIZE_MEASURECOUNT				TYPE_GEOMETRY_DISTANCE_MAX


// Log
typedef void (CALLBACK* FuncTextLog) (void* pArg, TYPE_CAMERAPOS ePos, const char* pszTag, char* pszLog, ...);
typedef struct
{
	FuncTextLog m_pFuncTextLog;
	void* m_pArg;

} INFO_LOGFUNC;

// LogHeater
typedef void (CALLBACK* FuncHeaterLog) (void* pArg, int* pszLog, ...);
typedef struct
{
	FuncHeaterLog m_pFuncHeaterLog;
	void* m_pArg;

} INFO_LOGFUNCHEATER;


//
typedef BOOL (CALLBACK *FuncNotifyVideoDevice)(DWORD, DWORD, void*);
typedef BOOL (CALLBACK *FuncNotifyInspectionResult)(TYPE_CAMERAPOS, TYPE_STEP, BOOL, void*, BOOL);

#define FLAG_INPUT_NONE			0x0000
#define FLAG_INPUT_FIRST		0x0001
#define FLAG_INPUT_SECOND		0x0002

typedef struct
{
	BOOL m_bStart;

	TCHAR m_szLocation[MAX_FILE_PATH_LEN];
	TCHAR m_szCurLogLocation[MAX_FILE_PATH_LEN];

	void* m_pNotifyArg;

} INFO_CAPTURE_PROCESS;

typedef struct
{
	int m_nMinCount;
	double m_fAlarmRatio;

} INFO_OPT_ALARM;

typedef struct
{
	double m_fMin;
	double m_fMax;

} INFO_OPT_RANGE;

typedef struct
{
	BOOL m_bStep001;
	BOOL m_bStep002;
	BOOL m_bStep003;
	BOOL m_bStep004;
	BOOL m_bStep005;
	BOOL m_bStep006;
	BOOL m_bStep007;

	TCHAR m_szTitleStep01[MAX_NAME_LEN];
	TCHAR m_szTitleStep02[MAX_NAME_LEN];
	TCHAR m_szTitleStep03[MAX_NAME_LEN];
	TCHAR m_szTitleStep04[MAX_NAME_LEN];
	TCHAR m_szTitleStep05[MAX_NAME_LEN];
	TCHAR m_szTitleStep06[MAX_NAME_LEN];
	TCHAR m_szTitleStep07[MAX_NAME_LEN];

} INFO_OPT_INSPECTSTEP;

#ifdef DEF_DELAY_CAPTURE
typedef struct
{
	unsigned int m_nDelay;
} INFO_OPT_CAPTURE;
#endif

typedef struct
{
	TCHAR m_szName[MAX_GEOMETRY_DISTANCELINE_COUNT][MAX_NAME_LEN];

	CString GetNameX1X2() const
	{
		CString szName;
		szName.Format(_T("%s-%s"), m_szName[TYPE_GEOMETRY_DISTANCE_X1], m_szName[TYPE_GEOMETRY_DISTANCE_X2]); // X1-X2
		return szName;
	}

	CString GetNameS1S3() const
	{
		CString szName;
		szName.Format(_T("%s-%s"), m_szName[TYPE_GEOMETRY_DISTANCE_S1], m_szName[TYPE_GEOMETRY_DISTANCE_S3]); // S1-S3
		return szName;
	}

	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	CString GetNameSS1SS3() const
	{
		CString szName;
		szName.Format(_T("%s-%s"), m_szName[TYPE_GEOMETRY_DISTANCE_SS1], m_szName[TYPE_GEOMETRY_DISTANCE_SS3]); // SS1-SS3
		return szName;
	}

	CString GetNameM1M2() const
	{
		CString szName;
		szName.Format(_T("%s-%s"), m_szName[TYPE_GEOMETRY_DISTANCE_M1], m_szName[TYPE_GEOMETRY_DISTANCE_M2]); // M1-M2
		return szName;
	}

} INFO_OPT_SIZENAME;

typedef struct
{
	INFO_OPT_ALARM m_stSampleA;
	INFO_OPT_ALARM m_stSampleB;

	INFO_OPT_RANGE m_pstRange[MAX_CAMERA_INTERFACE][MAX_SIZE_MEASURECOUNT];
	INFO_OPT_RANGE m_pstRangeSpec[MAX_SIZE_MEASURECOUNT];

	INFO_OPT_INSPECTSTEP m_stFirstCameraStep;
	INFO_OPT_INSPECTSTEP m_stSecondCameraStep;
	// Version 1.3.6.9 Update
	INFO_OPT_INSPECTSTEP m_stShapeToSize;

#ifdef DEF_DELAY_CAPTURE
	INFO_OPT_CAPTURE m_stCapture;
#endif

	INFO_OPT_RANGE m_pstValidRange[TYPE_SIZE_VALID_MAX];

	INFO_OPT_SIZENAME m_stSizeName;

} INFO_OPTION;

typedef struct
{
	TCHAR m_szLogPath[MAX_FILE_PATH_LEN];
	BOOL m_bSaveTextLog;
	BOOL m_bSaveErrorImage;
	BOOL m_bSaveProbImage;
	int m_nSaveProbImageCount;
	TCHAR m_szSaveImageFormat[MAX_FILE_PATH_LEN];
	BOOL m_bSaveOKImage;

	// Ver 1.367
	TCHAR m_szLastFormat[MAX_FILE_PATH_LEN];
	int m_nFormatCount;
	int m_nUserSetCount;

	// Version 1.3.7.6 Save OK Image Period
	BOOL m_bSaveOKImage_Period;
	int m_nSavePeriodTime;

	// Version 1.3.8.1
	BOOL m_bSaveImageCompress;
} INFO_OPTIONLOG;


typedef struct
{
	TCHAR m_szLotIdPath[MAX_FILE_PATH_LEN];

	INFO_OPTIONLOG m_stLogInfo;

} INFO_OPTIONETC;

typedef struct
{
	BOOL m_bSizeResult;
	BOOL m_bShapeResult;

} INFO_SUMMARY_TOTAL_FLAG;

typedef struct
{
	//TCHAR m_szLotId[MAX_NAME_LEN];

	// Result, Total
	int m_nSampleCount;

	// Result, Inspection.
	int m_nSampleCountErrorSize;
	int m_nSampleCountErrorShape;

	double m_fSampleRatioErrorSize;
	double m_fSampleRatioErrorShape;

	int first_queue_size;	//디버그용
	int second_queue_size;	//디버그용

	bool ErrorSize;		//total log용
	bool ShapeSize;		//total log용

} INFO_SUMMARY_TOTAL;

typedef struct
{
	//TCHAR m_szLotId[MAX_NAME_LEN];

	// Result, Total
	int m_nSampleCount;
	int m_nSampleCountError;
	double m_fSampleRatioError;


	// Result, Inspection.
	int m_nSampleCountErrorSize;
	int m_nSampleCountErrorShape;
	// Version 1.3.8.0
	int m_nResinCountErrorSize;

	double m_fSampleRatioErrorSize;
	double m_fSampleRatioErrorShape;
	
	int m_pListErrorShape[TYPE_STEP_MAX];
	int m_pListErrorSize[MAX_SIZE_MEASURECOUNT];

	INFO_SUMMARY_TOTAL_FLAG m_stTotalFlag;

} INFO_SUMMARY_SAMPLE;


typedef struct
{
	unsigned int m_nTotalCount;
	TCHAR m_szLotId[MAX_NAME_LEN];

	INFO_SUMMARY_SAMPLE m_stSummaryA;
	INFO_SUMMARY_SAMPLE m_stSummaryB;

	INFO_SUMMARY_SAMPLE m_stSummaryFirst;
	INFO_SUMMARY_SAMPLE m_stSummarySecond;
	INFO_SUMMARY_TOTAL m_stSummaryTotal;

} INFO_SUMMARY;


typedef struct
{
	double m_fx1;
	double m_fy1;
	double m_fx2;
	double m_fy2;
	
} INFO_LINE_GDIPLUS;


#define MAX_CALIBRATE_FILECOUNT		50

typedef struct
{
	int m_iMethod; // Pixel or Chess

	int m_iImgWidth;
	int m_iImgHeight;

	double m_dWidth;
	double m_dHeight;
	int m_iPixelUnit;

	/// File Path
	TCHAR m_pszFilePathList[MAX_CALIBRATE_FILECOUNT][MAX_FILE_PATH_LEN];
	int m_nListCount;
	int m_nIdxReference;

	int m_iRow; // Grid Rows
	int m_iCol; // Grid Cols
	float m_dSpacing; // Spacing
	int m_iChessUnit; // Unit
} INFO_CALIBRATION;

typedef struct
{
	double m_dd;
	double m_dL;
	double m_dW;
	double m_dI1;
	double m_dI2;
	double m_dI3;
	double m_dM1;
	double m_dM2;
	double m_dS1;
	double m_dS2;
	double m_dS3;
	double m_dS4;
	double m_dS5;
	double m_dX1;
	double m_dX2;
	double m_dR1;
	double m_dR2;
	double m_dR3;
	double m_dR4;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	double m_dR5;
	double m_dR6;
	double m_dSS1;
	double m_dSS2;
	double m_dSS3;
} INFO_SIZE_GAIN_NAME;

typedef union
{
	INFO_SIZE_GAIN_NAME m_stGainName;
	double m_dGain[sizeof(INFO_SIZE_GAIN_NAME) / sizeof(double)];
} INFO_SIZE_GAIN;

typedef struct
{
	int m_iDirection; // search direction
	int m_iPolarity; // polarity
	int m_iLookFor; // look for
	int m_iStrengthThreshold; // strength threshold
	int m_iSampling; // sampling
	int m_iKernelSize; // kernel size
	
	bool m_bSearchAngle; // search angle
	int m_iMinAngle; // min angle
	int m_iMaxAngle; // max angle

	int m_iDistanceThreshold; // distance threshold

} INFO_FINDLINE_PARAMETER;

typedef struct
{
	// roi type & roi pos
	TYPE_TRACKER m_eTrackerType;
	stPOINT m_stCenterPt;
	float m_fWidth;
	float m_fHeight;
	double m_dAngle;

	stPOINT m_ptCriteria;
	double m_dAngleCriteria;
} INFO_FINDLINE_ROI;

typedef struct
{
	TYPE_TRACKER m_eTrackerType;
	RECT m_rtRoi;

} INFO_RECT_ROI;


typedef struct
{
	// Probability value
	float prob_thres;

	// Blob size	
	float blobSize_thres;

} INFO_MARS_PARA;


typedef struct
{
	// Calibration constant
	float const_pixel2real;
	float const_real2pixel;

} INFO_CALIB_PARA;


typedef struct
{
	// fault judgment standard
	int faultNum;
	float faultSize;

} INFO_JUDGMENT_PARA;

// Version 1.3.8.1
typedef struct
{
	BOOL imageWrite;
	BOOL imageCompress;

} INFO_IMAGE_PARA;

typedef struct
{
	TYPE_STROBE m_eStrobeType;
	int m_nStrobeBrightness;

} INFO_STEPSTROBE;

typedef struct
{
	INFO_STEPSTROBE m_pstStepStrobe[MAX_STEPSTROBE_LIST];

	INFO_CALIBRATION m_stCalibration;
	INFO_SIZE_GAIN m_stSizeGain;
	INFO_FINDLINE_ROI m_pstFindLineROI[TYPE_FINDLINE_MAX];  
	INFO_FINDLINE_PARAMETER m_pstFindLineParameter[TYPE_FINDLINE_MAX]; 
	
} INFO_INSPECTION_SIZE;

typedef struct
{
	INFO_CALIBRATION m_stCalibration;
	INFO_SIZE_GAIN m_stSizeGain;
} INFO_INSPECTION_SIZE_CALC;

typedef struct
{
	INFO_STEPSTROBE m_pstStepStrobe[MAX_STEPSTROBE_LIST];

	// Roi Type & Position
	INFO_RECT_ROI m_stRoi;

	INFO_MARS_PARA m_stParaStain;
	INFO_CALIB_PARA m_stConstStain;
	INFO_JUDGMENT_PARA m_stStainStandard;
	// Version 1.3.8.1
	INFO_IMAGE_PARA m_stParaStainImage;

} INFO_INSPECTION_STAIN;

typedef struct
{
	INFO_STEPSTROBE m_pstStepStrobe[MAX_STEPSTROBE_LIST];

	// Roi Type & Position
	INFO_RECT_ROI m_stRoi;

	INFO_MARS_PARA m_stParaDiffer;
	INFO_CALIB_PARA m_stConstDiffer;
	INFO_JUDGMENT_PARA m_stDifferStandard;
	// Version 1.3.8.1
	INFO_IMAGE_PARA m_stParaDifferImage;

} INFO_INSPECTION_DIFFER;

typedef struct
{
	INFO_STEPSTROBE m_pstStepStrobe[MAX_STEPSTROBE_LIST];

	// Roi Type & Position
	INFO_RECT_ROI m_stRoi;

	INFO_MARS_PARA m_stParaBubble;
	INFO_CALIB_PARA m_stConstBubble;
	INFO_JUDGMENT_PARA m_stBubbleStandard;
	// Version 1.3.8.1
	INFO_IMAGE_PARA m_stParaBubbleImage;

} INFO_INSPECTION_BUBBLE;

typedef struct
{
	INFO_STEPSTROBE m_pstStepStrobe[MAX_STEPSTROBE_LIST];

	// Roi Type & Position
	INFO_RECT_ROI m_stRoi;

	INFO_MARS_PARA m_stParaScratch;
	INFO_CALIB_PARA m_stConstScratch;
	INFO_JUDGMENT_PARA m_stScratchStandard;
	// Version 1.3.8.1
	INFO_IMAGE_PARA m_stParaScratchImage;

} INFO_INSPECTION_SCRATCH;

typedef struct
{
	INFO_STEPSTROBE m_pstStepStrobe[MAX_STEPSTROBE_LIST];

	// Roi Type & Position
	INFO_RECT_ROI m_stRoi;

	INFO_MARS_PARA m_stParaStamp;
	INFO_CALIB_PARA m_stConstStamp;
	INFO_JUDGMENT_PARA m_stStampStandard;
	// Version 1.3.8.1
	INFO_IMAGE_PARA m_stParaStampImage;

} INFO_INSPECTION_STAMP;

typedef struct
{
	BOOL m_bInit;

	int m_nCameraNum;	// 20211231 퍼스트 세컨드 카메라 설정 저장 파일 분리

	INFO_INSPECTION_SIZE m_stSize;
	INFO_INSPECTION_STAIN m_stStain;
	INFO_INSPECTION_DIFFER m_stDiffer;
	INFO_INSPECTION_BUBBLE m_stBubble;
	INFO_INSPECTION_SCRATCH m_stScratch;
	INFO_INSPECTION_STAMP m_stStamp;
	INFO_INSPECTION_SIZE m_stSizeSecond;
	INFO_INSPECTION_SIZE_CALC m_stSizeCalc;

} INFO_INSPECTION;

typedef struct
{
	// First Camera Inspection
	TCHAR m_szFirstFilePath[MAX_FILE_PATH_LEN];
	INFO_INSPECTION m_stFirstInspection;

	// Second Camera Inspection
	TCHAR m_szSecondFilePath[MAX_FILE_PATH_LEN];
	INFO_INSPECTION m_stSecondInspection;

} INFO_SCENARIO;

typedef struct
{
	BOOL m_bStrobeOnCoxial;
	BOOL m_bStrobeOnRing;
	BOOL m_bStrobeOnBar;

	int m_nBrightnessCoxial;
	int m_nBrightnessRing;
	int m_nBrightnessBar;

} INFO_STROBE_BRIGHTNESS;

typedef struct
{
	INFO_STROBE_BRIGHTNESS m_stFirstStrobe;
	INFO_STROBE_BRIGHTNESS m_stSecondStrobe;

} INFO_STROBE;


// Version 1.366
typedef enum
{
	Option_None,

	FirstInspection,
	SecondInspection,
	Option,
	ImageFormat,

	MAX_TYPE_MONITORING

} TYPE_MONITORING;

#define MAX_TYPE_MONITORINGOPTION MAX_TYPE_MONITORING