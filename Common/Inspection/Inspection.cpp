#include "StdAfx.h"
#include "Inspection.h"

CInspection::CInspection()
{
	m_hNotify = NULL;
	memset(&m_stLogFunc, 0x00, sizeof(INFO_LOGFUNC));
}

CInspection::~CInspection()
{
}

BOOL CInspection::IsInit()
{
	BOOL bInit = FALSE;
	if (m_FirstCameraInspection.IsInit() && m_SecondCameraInspection.IsInit())
		bInit = TRUE;
	return bInit;
}

BOOL CInspection::IsStart()
{
	return m_bStart;
}

BOOL CInspection::IsWorkingInspection(TYPE_CAMERAPOS eCameraPos)
{
	if (FALSE == IsInit() || FALSE == IsStart())
		return FALSE;

	BOOL bWork = FALSE;

	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
		bWork = m_FirstCameraInspection.IsWorking();
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
		bWork = m_SecondCameraInspection.IsWorking();
	
	return bWork;
}

BOOL CInspection::IsWaitingAcquire(TYPE_CAMERAPOS eCameraPos)
{
	if (FALSE == IsWorkingInspection(eCameraPos))
		return FALSE;

	BOOL bWaiting = FALSE;

	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
		bWaiting = m_FirstCameraInspection.IsWaitingAcquire();
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
		bWaiting = m_SecondCameraInspection.IsWaitingAcquire();

	return bWaiting;
}


BOOL CInspection::Init(HWND hWnd, const INFO_INSPECTION* pstFirstInspect, const INFO_INSPECTION* pstSecondInspect, const INFO_NOTIFY_INSPECTION* pstNotify, INFO_LOGFUNC stLogFunc)
{
	BOOL bResult = m_FirstCameraInspection.Init(hWnd, pstFirstInspect, TYPE_CAMERAPOS_FIRST, pstNotify, stLogFunc);
	if (bResult)
		bResult = m_SecondCameraInspection.Init(hWnd, pstSecondInspect, TYPE_CAMERAPOS_SECOND, pstNotify, stLogFunc);

	m_hNotify = hWnd;
	m_stLogFunc = stLogFunc;

	if (FALSE == bResult)
		Deinit();

	return bResult;
}

BOOL CInspection::Update(const INFO_INSPECTION* pstFirstInspect, const INFO_INSPECTION* pstSecondInspect)
{
	BOOL bResult = FALSE;

	BOOL bFirstResult = m_FirstCameraInspection.Update(pstFirstInspect);
	BOOL bSecondResult = m_SecondCameraInspection.Update(pstSecondInspect);

	if (FALSE == bFirstResult || FALSE == bSecondResult)
		bResult = FALSE;
	else
		bResult = TRUE;

	return bResult;
}

void CInspection::Deinit()
{
	m_FirstCameraInspection.Deinit();
	m_SecondCameraInspection.Deinit();

	m_hNotify = NULL;
}

BOOL CInspection::Start()
{
	BOOL bFirst = m_FirstCameraInspection.Start();
	BOOL bSecond = m_SecondCameraInspection.Start();

	if (bFirst && bSecond)
		m_bStart = TRUE;
	else
		m_bStart = FALSE;

	// Print Log
	{
		if (m_stLogFunc.m_pFuncTextLog && m_stLogFunc.m_pArg)
		{
			if (m_bStart)
				m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Start: Insepction");
			else
				m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Fail to start: Insepction");
		}
	}
	return m_bStart;
}

void CInspection::Stop()
{
	m_bStart = FALSE;

	StopInspection(TYPE_CAMERAPOS_FIRST);
	StopInspection(TYPE_CAMERAPOS_SECOND);

	// Print Log
	{
		if (m_stLogFunc.m_pFuncTextLog && m_stLogFunc.m_pArg)
		{
			m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Stop: Insepction");
		}
	}
}

void CInspection::StopInspection(TYPE_CAMERAPOS eCameraPos)
{
	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
		m_FirstCameraInspection.Stop();
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
		m_SecondCameraInspection.Stop();
}

CInspectionCamera* CInspection::GetInspectionCamera(TYPE_CAMERAPOS eCameraPos)
{
	CInspectionCamera* pInspection = NULL;

	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
		pInspection = &m_FirstCameraInspection;
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
		pInspection = &m_SecondCameraInspection;

	return pInspection;
}

CStep* CInspection::GetInsectionStep(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep)
{
	CStep* pStep = NULL;

	CInspectionCamera* pInspectionCamera =  GetInspectionCamera(eCameraPos);
	if (pInspectionCamera)
	{
		pStep = pInspectionCamera->GetStep(eStep);
	}
	return pStep;
}

shared_ptr<CSampleSide> CInspection::GetInspectionSample(TYPE_CAMERAPOS eCameraPos)
{
	shared_ptr<CSampleSide> pSample = NULL;

	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
		pSample = m_FirstCameraInspection.GetSample();
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
		pSample = m_SecondCameraInspection.GetSample();

	return pSample;
}

void CInspection::SetInspectionSample(TYPE_CAMERAPOS eCameraPos, shared_ptr<CSampleSide> pSample)
{
	/*if (TYPE_CAMERAPOS_FIRST == eCameraPos)
		m_FirstCameraInspection.PushSample(pSample);
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
		m_SecondCameraInspection.PushSample(pSample);*/
}


BOOL CInspection::InspectCamera(TYPE_CAMERAPOS eCameraPos, shared_ptr<CSampleSide> pSample)
{
	BOOL bResult = FALSE;

	CInspectionCamera* pInspectionCamera = GetInspectionCamera(eCameraPos);
	if (pInspectionCamera)
	{
		pInspectionCamera->Process(pSample);
	}
	return bResult;
}

BOOL CInspection::UpdateInspectCameraSample(TYPE_CAMERAPOS eCameraPos, const INFO_IMAGE* pRefImage)
{
	BOOL bResult = FALSE;

	CInspectionCamera* pInspectionCamera = GetInspectionCamera(eCameraPos);
	if (pInspectionCamera)
	{
		pInspectionCamera->ProcessUpdateImage(pRefImage);
	}
	return bResult;
}

void CInspection::CalculationSize(TYPE_CAMERAPOS eCameraPos, CSampleSide& sample)
{
	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
		m_FirstCameraInspection.MergeSize(sample);
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
		m_SecondCameraInspection.MergeSize(sample);
}


BOOL CInspection::InspectCamera(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep, CSampleSide& sample)
{
	BOOL bResult = FALSE;

	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
		bResult = m_FirstCameraInspection.Process(eStep, sample);
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
		bResult = m_SecondCameraInspection.Process(eStep, sample);

	return bResult;
}

BOOL CInspection::InspectCamera(TYPE_CAMERAPOS eCameraPos, TYPE_STEP eStep, CSampleSide& sample, cv::Mat captureImg)
{
	BOOL bResult = FALSE;

	if (TYPE_CAMERAPOS_FIRST == eCameraPos)
		bResult = m_FirstCameraInspection.Process(eStep, sample, captureImg);
	else if (TYPE_CAMERAPOS_SECOND == eCameraPos)
		bResult = m_SecondCameraInspection.Process(eStep, sample, captureImg);

	return bResult;
}

void CInspection::UpdateEnableInspectionStep(const INFO_OPT_INSPECTSTEP* pstFirstOpt, const INFO_OPT_INSPECTSTEP* pstSecondOpt)
{
	m_FirstCameraInspection.UpdateEnableStep(pstFirstOpt);
	m_SecondCameraInspection.UpdateEnableStep(pstSecondOpt);

}
