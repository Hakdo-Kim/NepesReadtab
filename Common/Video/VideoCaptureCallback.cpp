#include "StdAfx.h"
#include "VideoCaptureCallback.h"

CVideoCaptureCallback::CVideoCaptureCallback()
{
	m_FuncDisplayDev = NULL;
	m_pArgument = NULL;
}

CVideoCaptureCallback::~CVideoCaptureCallback()
{
	if (m_pArgument)
		delete m_pArgument;
	m_pArgument = NULL;
}
