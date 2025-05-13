#pragma once
#include "VideoDef.h"

class CVideoCaptureCallback
{
public:
	CVideoCaptureCallback();
	~CVideoCaptureCallback();

	FuncDisplayVideoDevice m_FuncDisplayDev;
	void* m_pArgument;


};