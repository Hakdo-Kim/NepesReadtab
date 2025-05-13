#pragma once
#include "afxwin.h"
#include "CommonCapture.h"
#include "UserInterfaceDef.h"

#include "StepSize.h"
#include "StepStain.h"
#include "StepDiffer.h"
#include "StepBubble.h"
#include "StepScratch.h"
#include "StepStamp.h"
#include "StepSizeSecond.h"
#include "StepSizeCalculation.h"

#include "Sample.h"

#include <memory>
#include <queue>
#include <deque>

typedef struct
{
	HANDLE	m_hThread;
	HANDLE	m_hEvent;
	HANDLE	m_hEventForStop;

	BOOL m_bBreakProc;

} INFO_PROC_INSPECTION;

typedef struct : INFO_PROC_INSPECTION
{
	HANDLE	m_hEventInspectionEnd;

} INFO_PROC_INSPECTION_STEP;

typedef struct
{
	FuncNotifyInspectionResult m_pFuncNotifyInspectionResult;
	void* m_pArgument;

} INFO_NOTIFY_INSPECTION;

typedef struct
{
	cv::Mat img001;
	cv::Mat img002;
	cv::Mat img003;
	cv::Mat img004;
	cv::Mat img005;
	cv::Mat img006;
	cv::Mat img007;

} INSPECTION_CAMERA_IMG;

class CInspectionCamera
{
public:
	CInspectionCamera();
	virtual ~CInspectionCamera();

	BOOL IsInit();
	BOOL IsWorking(); 
	BOOL IsWaitingAcquire();

	BOOL Init(HWND hWnd, const INFO_INSPECTION* pstInspect, TYPE_CAMERAPOS ePos, const INFO_NOTIFY_INSPECTION* pstNotify, INFO_LOGFUNC stLogFunc);
	BOOL Update(const INFO_INSPECTION* pstInspect);
	void Deinit();

	CStep* GetStep(TYPE_STEP eStep);
	CStepSizeCalculation* GetStepSizeCalc();

	///////
	INSPECTION_CAMERA_IMG m_inspectImg;

	// Loop Inspection
	BOOL Start();		// Create thread & Wait Acq. Image
	void Stop();		// Destroy thread
	
	BOOL Process(std::shared_ptr<CSampleSide> pSample);							// Start Thread
	BOOL ProcessUpdateImage(const INFO_IMAGE* pRefImage);	// Update Image & Resume Thread

	// Single Inspection
	BOOL Process(TYPE_STEP eStep, CSampleSide& sample);
	BOOL Process(TYPE_STEP eStep, CSampleSide& sample, cv::Mat captureImg);

	std::shared_ptr<CSampleSide> GetSample();
	void SetSample(std::shared_ptr<CSampleSide> pSample);
	void PushSample(CSample* pSample);

	void UpdateEnableStep(const INFO_OPT_INSPECTSTEP* pstStepOpt);

	void MergeSize(CSampleSide& sample);

protected:
	TYPE_CAMERAPOS m_eCameraPosition;
	INFO_OPT_INSPECTSTEP m_stInspectStepEnable;

	BOOL m_bInit;
	BOOL m_bWorking;
	BOOL m_bWaitingAcq;

	HWND m_hNotifyWnd;

	INFO_LOGFUNC m_stLogFunc;

	CStep* m_pStepList[TYPE_STEP_MAX];
	CStepSizeCalculation* m_pCalcSize;

	INFO_INSPECTION* Load(const TCHAR* pszPath);
	BOOL ProcessStep(TYPE_STEP eStep, CSampleSide& sample);
	BOOL ProcessStep(TYPE_STEP eStep, CSampleSide& sample, cv::Mat captureImg);
		
protected:	// Thread
	INFO_PROC_INSPECTION m_stProcInspection;
	INFO_NOTIFY_INSPECTION m_stProcNotify;

	std::deque<CSample*> m_SampleQueue;

	INFO_PROC_INSPECTION_STEP m_stProcInspectionSub001;
	INFO_PROC_INSPECTION_STEP m_stProcInspectionSub002;
	INFO_PROC_INSPECTION_STEP m_stProcInspectionSub003;
	INFO_PROC_INSPECTION_STEP m_stProcInspectionSub004;
	INFO_PROC_INSPECTION_STEP m_stProcInspectionSub005;
	INFO_PROC_INSPECTION_STEP m_stProcInspectionSub006;
	INFO_PROC_INSPECTION_STEP m_stProcInspectionSub007;

	std::shared_ptr<CSampleSide> m_SampleSide;

	static DWORD WINAPI ProcInspection(LPVOID lpArg);
	DWORD ProcInspection();

	static DWORD WINAPI ProcInspectionSub001(LPVOID lpArg);
	DWORD ProcInspectionSub001();
	static DWORD WINAPI ProcInspectionSub002(LPVOID lpArg);
	DWORD ProcInspectionSub002();
	static DWORD WINAPI ProcInspectionSub003(LPVOID lpArg);
	DWORD ProcInspectionSub003();
	static DWORD WINAPI ProcInspectionSub004(LPVOID lpArg);
	DWORD ProcInspectionSub004();
	static DWORD WINAPI ProcInspectionSub005(LPVOID lpArg);
	DWORD ProcInspectionSub005();
	static DWORD WINAPI ProcInspectionSub006(LPVOID lpArg);
	DWORD ProcInspectionSub006();
	static DWORD WINAPI ProcInspectionSub007(LPVOID lpArg);
	DWORD ProcInspectionSub007();
	
	BOOL ProcInspectionStep001();
	BOOL ProcInspectionStep002();
	BOOL ProcInspectionStep003();
	BOOL ProcInspectionStep004();
	BOOL ProcInspectionStep005();
	BOOL ProcInspectionStep006();
	BOOL ProcInspectionStep007();

	void ProcCaptureStep001(BOOL bWaitAcq);
	void ProcCaptureStep002(BOOL bWaitAcq);
	void ProcCaptureStep003(BOOL bWaitAcq);
	void ProcCaptureStep004(BOOL bWaitAcq);
	void ProcCaptureStep005(BOOL bWaitAcq);
	void ProcCaptureStep006(BOOL bWaitAcq);
	void ProcCaptureStep007();

	void WaitingForGrab();
};