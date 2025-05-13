#pragma once

#include "CameraInterfaceDef.h"

typedef struct
{
	BOOL m_bSupport;

	int m_nUnitX;
	int m_nUnitY;
	int m_nUnitW;
	int m_nUnitH;

	int m_nMinWidth;
	int m_nMinHeight;

} INFO_DEFROI;

typedef struct
{
	int m_nFrom;
	int m_nTo;

} INFO_DEFRANGE;

typedef struct
{
	BOOL m_bSupport;
	INFO_DEFRANGE m_stRange;

} INFO_DEFGAIN;

typedef struct
{
	BOOL m_bSupport;
	INFO_DEFRANGE m_stRange;

} INFO_DEFEXPOSURE;

typedef struct
{
	BOOL m_bSupport;
	INFO_DEFRANGE m_stRange;

} INFO_DEFFRAMERATE;

typedef struct
{
	BOOL m_bSupport;

	BOOL m_bTriggerTypeSupport[TYPE_TRIGGERTYPE_MAX];
	INFO_DEFRANGE m_stDelayRange;

} INFO_DEFTRIGGER;

typedef struct
{
	BOOL m_bSupport;

	BOOL m_bSupportSync;

	INFO_DEFRANGE m_stDelayRange;
	INFO_DEFRANGE m_stWidthRange;

} INFO_DEFSTROBE;

typedef struct
{
	BOOL m_bSupport;

	BOOL m_bSupportHorizontal;
	BOOL m_bSupportVertical;

} INFO_DEFSYMMETRY;

typedef struct
{
	BOOL m_bSupport;
	BOOL m_bSeparatedIndex;

	INFO_DEFRANGE m_stIndexRange;
	INFO_DEFRANGE m_stValueRange;

}INFO_DEFLUT;

typedef struct
{
	BOOL m_bSupport;
	BOOL m_bSupportUpload;
	
}INFO_DEFEFFECT;

typedef struct
{
	BOOL m_bSupport;
	BOOL m_bSupportStartup;

	INFO_DEFRANGE m_stRange;

} INFO_DEFUSERSET;

typedef struct
{
	BOOL m_bSupport;

	TYPE_CLIMGTAPS m_eImgTap;
	BOOL m_pDataBitList[TYPE_CLDATABIT_MAX];

} INFO_CLIMGTAP;

typedef struct
{
	BOOL m_bSupport;
	BOOL m_bSupportDataBit[TYPE_DATABIT_MAX];

} INFO_DEFDATABIT;

typedef struct
{
	BOOL m_bSupport;

} INFO_DEFCOLORFORMAT;

typedef struct
{
	BOOL m_bSupport;

	TYPE_DATABIT m_eDatabit;
	BOOL m_pColorList[TYPE_CAMCOLORFORMAT_MAX];


} INFO_DEFPIXEL;

typedef struct
{
	BOOL m_bSupport;

	INFO_DEFPIXEL m_pstPixel[TYPE_DATABIT_MAX];

} INFO_DEFPIXELFORMAT;

typedef struct
{
	BOOL m_bSupport;

	INFO_DEFGAIN m_RedGain;
	INFO_DEFGAIN m_GreenGain;
	INFO_DEFGAIN m_BlueGain;
	INFO_DEFGAIN m_GreenGain2;

} INFO_DEFCOLORGAIN;


typedef struct
{
	BOOL m_bSupport;

	INFO_DEFCOLORFORMAT m_stColorFormat;
	INFO_DEFPIXELFORMAT m_stPixelFormat;
	INFO_DEFCOLORGAIN m_stColorGain;

} INFO_DEFCOLOR;

typedef struct
{
	BOOL m_bSupport;

} INFO_DEFMTU;


typedef struct
{
	// Network Type
	TYPE_NETWORK m_eNetwork;
	TCHAR m_szName[MAX_NAME_LEN];

	INFO_DEFROI m_stDefROI;

	INFO_DEFGAIN m_stDefGain01;
	INFO_DEFGAIN m_stDefGain02;

	INFO_DEFEXPOSURE m_stDefExposure;
	INFO_DEFFRAMERATE m_stDefFrameRate;

	INFO_DEFTRIGGER m_stDefTrigger;
	INFO_DEFSTROBE m_stDefStrobe;

	INFO_DEFSYMMETRY m_stDefSymmetry;

	INFO_DEFLUT m_stDefLut;

	INFO_DEFEFFECT m_stDefEffectNR;
	INFO_DEFEFFECT m_stDefEffectGC;
	INFO_DEFEFFECT m_stDefEffectCM;
	INFO_DEFEFFECT m_stDefEffectAWB;
	INFO_DEFEFFECT m_stDefEffectFPN;
	INFO_DEFEFFECT m_stDefEffectPRNU;
	INFO_DEFEFFECT m_stDefEffectDPC;
	INFO_DEFEFFECT m_stDefEffectSmoth;
	INFO_DEFEFFECT m_stDefEffectSharpen;

	INFO_DEFUSERSET m_stDefUserset;

	INFO_DEFDATABIT	m_stDefDataBit;
	INFO_DEFCOLOR m_stDefColor;
	INFO_DEFMTU m_stDefMTU;

	DWORD m_dwReserved01;		// USB: Sensor Type.


} INFO_DEFDEV;

typedef struct
{
	INFO_DEFDEV m_stDefDev;		// Normal camera

	TYPE_CLDEVICE m_eCLDevice;
	INFO_CLIMGTAP m_pstImgTaps[TYPE_CLIMGTAPS_MAX];

} INFO_DEFDEV_CL;


typedef struct
{
	TYPE_CLGRABBER m_eGrabber;

	TYPE_CLDEVICE m_eModelType;
	TYPE_CLIMGTAPS m_eImageTap;
	TYPE_CLDATABIT m_eDataBit;
	TYPE_CAMCOLOR m_eColor;

	TCHAR m_szCamFile[CLCAMFILE_MAX][MAX_NAME_LEN];

} INFO_FRAMEGRABBER_CAMFILE;


// UserConfig
typedef struct
{
	BOOL m_bSupport;


	BOOL m_bEnable;
	INFO_DEFRANGE m_stTimeOutRange;	// Range
	int m_nCurTimeOut;				// Current Value

} INFO_TIMEOUT;

typedef struct
{
	BOOL m_bSupport;

	BOOL m_bEnable;
	DWORD m_dwMtu;

} INFO_MTU;

typedef struct
{
	INFO_MTU m_stMtu;	

} INFO_USERGIGE;

typedef struct
{
	INFO_TIMEOUT m_stTimeOut;

	INFO_USERGIGE m_stUserGigE;

} INFO_DEFDEV_USERCONFIG;
