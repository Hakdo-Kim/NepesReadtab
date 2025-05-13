#pragma once

#include "Camera/CameraInterfaceDef.h"

#define WM_CLOSE_CHILDFRAME			(WM_USER+0x100)
#define WM_NOTIFY_FRAMERATE			(WM_USER+0x101)
#define WM_NOTIFY_SETIMAGEINFO		(WM_USER+0x102)
#define WM_NOTIFY_FOCUSCHILDFRAME	(WM_USER+0x103)

#ifndef DEF_LPAPP
#define WM_NOTIFY_SETTRIGGER		(WM_USER+0x200)
#endif

#define MAX_PROCBUFFER_COUNT		25

//#define TRIGGER_TIMEOUT
#ifdef TRIGGER_TIMEOUT
//#define TRIGGER_REFRESH_CONNECTION
#define RETRY_TRIGGERCOUNT			2
#define TIMEOUT_WAIT_TIME			100
#endif


typedef enum
{
	TYPE_FRAMESTATE_NONE,

	TYPE_FRAMESTATE_READ,
	TYPE_FRAMESTATE_DISPLAY,

} TYPE_FRAMESTATE;

typedef struct
{
	INFO_FRAME	m_stFrame;

	TYPE_FRAMESTATE		m_eFrameState;

	BYTE*	m_pBuffer;
	int		m_nBufLen;
	int		m_nLen;

	DWORD	m_dwTick;

	void* m_pReserved;


} INFO_IMAGE;

