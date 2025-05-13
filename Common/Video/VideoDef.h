#pragma once

#include "Camera/CameraInterfaceDef.h"
#include "Proc/ProcessDef.h"

typedef enum
{
	TYPE_VIDEODEV_NONE,

	TYPE_VIDEODEV_GDI,
	//TYPE_VIDEODEV_OPENCV,
	//TYPE_VIDEODEV_DDRAW,
	TYPE_VIDEODEV_D2D,				// Direct2D

	TYPE_VIDEODEV_CALLBACK,

	TYPE_VIDEODEV_MAX,

} TYPE_VIDEODEV;

typedef enum 
{
	TYPE_VIDEOFORMAT_NONE,

	TYPE_VIDEOFORMAT_RGB08,
	TYPE_VIDEOFORMAT_RGB12,
	TYPE_VIDEOFORMAT_RGB16,
	TYPE_VIDEOFORMAT_RGB24,
	TYPE_VIDEOFORMAT_RGB32,

	TYPE_VIDEOFORMAT_MAX,

} TYPE_VIDEOFORMAT;


typedef struct
{
	TYPE_VIDEODEV m_VideoDev;

	BOOL m_bEnable;
	HWND m_hWnd;

	INFO_FRAME m_stFrame;

	TYPE_VIDEOFORMAT m_eVideoFormat;
	float m_fCurZoom;


} INFO_VIDEODEV;

typedef struct
{
	BITMAPINFO* m_pstBmpInfo;

	HDC		m_hDC;

	HBITMAP	m_hBmp;
	PVOID	m_pRaster;

} INFO_VIDEODC;


typedef BOOL(CALLBACK *FuncOpenVideoDevice)(HWND, const INFO_FRAME*, void*);
typedef void(CALLBACK *FuncCloseVideoDevice)(void*);
typedef BOOL(CALLBACK *FuncDisplayVideoDevice)(const INFO_IMAGE*, void*, int);
typedef BOOL(CALLBACK *FuncRedrawVideoDevice)(void*);
typedef BOOL(CALLBACK *FuncDrawOutputVideoDevice)(void*, int, void*);
typedef BOOL(CALLBACK *FuncRemoveOutputVideoDevice)(const int, void*);
typedef BOOL(CALLBACK *FuncSetTrackerVideoDevice)(BOOL, const int, void*);

typedef BOOL(CALLBACK *FuncGetZoom)(float&, void*);
typedef BOOL(CALLBACK *FuncSetZoom)(const float, void*);

typedef BOOL(CALLBACK *FuncGetImageSize)(int&, int&, void*);


typedef struct
{
	TYPE_VIDEODEV	m_eVideoDev;

	// Enable Only Callback...
	FuncOpenVideoDevice m_FuncOpenDev;
	FuncCloseVideoDevice m_FuncCloseDev;
	FuncDisplayVideoDevice m_FuncDisplayDev;
	FuncRedrawVideoDevice m_FuncRedrawDev;
	FuncDrawOutputVideoDevice m_FuncDrawOutputDev;
	FuncRemoveOutputVideoDevice m_FuncRemoveOutputDev;
	FuncSetTrackerVideoDevice m_FuncSetTracker;

	FuncGetZoom m_FuncGetZoom;
	FuncSetZoom m_FuncSetZoom;

	FuncGetImageSize m_FuncGetFrameSize;
	FuncGetImageSize m_FuncGetDisplaySize;

	void* m_pArgument;

} INFO_VIDEODEV_ARG;


