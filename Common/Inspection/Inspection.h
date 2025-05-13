#pragma once

#include "CommonCapture.h"
#include "UserInterfaceDef.h"

#include "InspectionCamera.h"
#include "Sample.h"

class CInspection
{
public:
	CInspection();
	virtual ~CInspection();

	BOOL IsInit();
	BOOL IsStart();
	BOOL IsWorkingInspection(TYPE_CAMERAPOS eCameraPos);
	BOOL IsWaitingAcquire(TYPE_CAMERAPOS eCameraPos);

	BOOL Init(HWND hWnd, const INFO_INSPECTION* pstFirstInspect, const INFO_INSPECTION* pstSecondInspect, const INFO_NOTIFY_INSPECTION* pstNotify, INFO_LOGFUNC stLogFunc);
	BOOL Update(const INFO_INSPECTION* pstFirstInspect, const INFO_INSPECTION* pstSecondInspect);
	void Deinit();

	BOOL Start();
	void Stop();

	CStep* GetInsectionStep(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep);

	std::shared_ptr<CSampleSide> GetInspectionSample(TYPE_CAMERAPOS eCameraPos);
	void SetInspectionSample(TYPE_CAMERAPOS eCameraPos, std::shared_ptr<CSampleSide> pSample);

	// Loop Inspection
	BOOL InspectCamera(TYPE_CAMERAPOS eCameraPos, std::shared_ptr<CSampleSide> pSample);
	BOOL UpdateInspectCameraSample(TYPE_CAMERAPOS eCameraPos, const INFO_IMAGE* pRefImage);
	
	// Single Inspection
	BOOL InspectCamera(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep, CSampleSide& sample);
	BOOL InspectCamera(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep, CSampleSide& sample, cv::Mat captureImg);

	void CalculationSize(TYPE_CAMERAPOS eCameraPos, CSampleSide& sample);

	void UpdateEnableInspectionStep(const INFO_OPT_INSPECTSTEP* pstFirstOpt, const INFO_OPT_INSPECTSTEP* pstSecondOpt);

	CInspectionCamera* GetInspectionCamera(TYPE_CAMERAPOS eCameraPos);
protected:
	HWND m_hNotify;
	BOOL m_bStart;

	INFO_LOGFUNC m_stLogFunc;

	CInspectionCamera m_FirstCameraInspection;
	CInspectionCamera m_SecondCameraInspection;

	void StopInspection(TYPE_CAMERAPOS eCameraPos);
};