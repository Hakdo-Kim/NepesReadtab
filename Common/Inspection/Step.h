#pragma once
#include "CommonCapture.h"
#include "Sample.h"

#ifdef _WIN64
#define NAVIAI_SUPPORT
#endif

class CStep
{
public:
	CStep(std::string strStepName);
	virtual ~CStep();

	virtual BOOL Init(TYPE_CAMERAPOS eCameraPos, INFO_LOGFUNC stLogFunc) = 0;
	virtual void Deinit() = 0;
	virtual BOOL Process(CSampleSide& sample) = 0;
	virtual BOOL Process(CSampleSide& sample, cv::Mat inputImg) = 0;
	
	virtual BOOL Load(INFO_INSPECTION* pstInspection) = 0;

	virtual BOOL Get(INFO_INSPECTION* pstInspection) = 0;
	virtual BOOL Set(const INFO_INSPECTION* pstInspection) = 0;

	virtual void Log(char* pszLog, ...);

	BOOL IsInit();

protected:
	BOOL m_bInit;

	TYPE_CAMERAPOS m_eCameraPos;
	INFO_LOGFUNC m_stLogFunc;

	std::string m_strStepName;
};