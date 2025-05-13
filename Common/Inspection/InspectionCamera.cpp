#include "StdAfx.h"
#include "InspectionCamera.h"

#include "StepBubble.h"
#include "StepScratch.h"
#include "StepSize.h"
#include "StepStain.h"
#include "StepStamp.h"
#include "StepDiffer.h"
#include "StepSizeSecond.h"
#include "StepSizeCalculation.h"

#include "Util/Util.h"

CInspectionCamera::CInspectionCamera()
{
	// Size -> Stain -> Bubble -> Scratch -> Stamp
	m_pStepList[TYPE_STEP_001] = new CStepSize();
	m_pStepList[TYPE_STEP_002] = new CStepStain();
	m_pStepList[TYPE_STEP_003] = new CStepDiffer();
	m_pStepList[TYPE_STEP_004] = new CStepBubble();
	m_pStepList[TYPE_STEP_005] = new CStepScratch();
	m_pStepList[TYPE_STEP_006] = new CStepStamp();
	m_pStepList[TYPE_STEP_007] = new CStepSizeSecond();
	m_pCalcSize = new CStepSizeCalculation();

	//
	m_eCameraPosition = TYPE_CAMERAPOS_NONE;

	m_bInit = FALSE;
	m_bWorking = FALSE;
	m_bWaitingAcq = FALSE;

	m_hNotifyWnd = NULL;


	memset(&m_stProcInspection, 0x00, sizeof(INFO_PROC_INSPECTION));
	memset(&m_stProcNotify, 0x00, sizeof(INFO_NOTIFY_INSPECTION));

	memset(&m_stLogFunc, 0x00, sizeof(INFO_LOGFUNC));
	memset(&m_stInspectStepEnable, 0x00, sizeof(INFO_OPT_INSPECTSTEP));
}

CInspectionCamera::~CInspectionCamera()
{
	for (int i = 0; i < (int)TYPE_STEP_MAX; i++)
	{
		if (m_pStepList[i])
			delete m_pStepList[i];
		m_pStepList[i] = NULL;
	}
	m_hNotifyWnd = NULL;
	m_eCameraPosition = TYPE_CAMERAPOS_NONE;
	m_bWaitingAcq = FALSE;
}

BOOL CInspectionCamera::IsInit()
{
	return m_bInit;
}

BOOL CInspectionCamera::IsWorking()
{
	return m_bWorking;
}

BOOL CInspectionCamera::IsWaitingAcquire()
{
	return m_bWaitingAcq;
}

BOOL CInspectionCamera::Init(HWND hWnd, const INFO_INSPECTION* pstInspect, TYPE_CAMERAPOS ePos, const INFO_NOTIFY_INSPECTION* pstNotify, INFO_LOGFUNC stLogFunc)
{
	BOOL bResult = TRUE;

	m_pStepList[TYPE_STEP_001]->Init(ePos, stLogFunc);
	m_pStepList[TYPE_STEP_002]->Init(ePos, stLogFunc);
	m_pStepList[TYPE_STEP_003]->Init(ePos, stLogFunc);
	m_pStepList[TYPE_STEP_004]->Init(ePos, stLogFunc);
	m_pStepList[TYPE_STEP_005]->Init(ePos, stLogFunc);
	m_pStepList[TYPE_STEP_006]->Init(ePos, stLogFunc);
	m_pStepList[TYPE_STEP_007]->Init(ePos, stLogFunc);

	m_pCalcSize->Init(ePos, stLogFunc);

	bResult = Update(pstInspect);

	m_hNotifyWnd = hWnd;
	if (FALSE == bResult)
	{
		Deinit();
	}

	if (pstNotify)
	{
		m_stProcNotify.m_pFuncNotifyInspectionResult = pstNotify->m_pFuncNotifyInspectionResult;
		m_stProcNotify.m_pArgument = pstNotify->m_pArgument;
	}

	m_eCameraPosition = ePos;
	m_stLogFunc = stLogFunc;

	if (TYPE_CAMERAPOS_FIRST == m_eCameraPosition)
	{
		m_stInspectStepEnable.m_bStep001 = TRUE;
		m_stInspectStepEnable.m_bStep002 = TRUE;
		m_stInspectStepEnable.m_bStep003 = TRUE;
		m_stInspectStepEnable.m_bStep004 = TRUE;
		m_stInspectStepEnable.m_bStep005 = TRUE;
		m_stInspectStepEnable.m_bStep006 = TRUE;
		m_stInspectStepEnable.m_bStep007 = TRUE;
	}
	else if (TYPE_CAMERAPOS_SECOND == m_eCameraPosition)
	{
		m_stInspectStepEnable.m_bStep001 = FALSE;
		m_stInspectStepEnable.m_bStep002 = TRUE;
		m_stInspectStepEnable.m_bStep003 = TRUE;
		m_stInspectStepEnable.m_bStep004 = TRUE;
		m_stInspectStepEnable.m_bStep005 = TRUE;
		m_stInspectStepEnable.m_bStep006 = TRUE;
		m_stInspectStepEnable.m_bStep007 = TRUE;
	}

	m_bInit = bResult;
	return bResult;
}

BOOL CInspectionCamera::Update(const INFO_INSPECTION* pstInspect)
{
	BOOL bResult = TRUE;

	if (pstInspect->m_bInit)
	{
		m_pStepList[TYPE_STEP_001]->Load((INFO_INSPECTION*)pstInspect);
		m_pStepList[TYPE_STEP_002]->Load((INFO_INSPECTION*)pstInspect);
		m_pStepList[TYPE_STEP_003]->Load((INFO_INSPECTION*)pstInspect);
		m_pStepList[TYPE_STEP_004]->Load((INFO_INSPECTION*)pstInspect);
		m_pStepList[TYPE_STEP_005]->Load((INFO_INSPECTION*)pstInspect);
		m_pStepList[TYPE_STEP_006]->Load((INFO_INSPECTION*)pstInspect);
		m_pStepList[TYPE_STEP_007]->Load((INFO_INSPECTION*)pstInspect);
	}
	else
	{
		m_pStepList[TYPE_STEP_001]->Load(NULL);
		m_pStepList[TYPE_STEP_002]->Load(NULL);
		m_pStepList[TYPE_STEP_003]->Load(NULL);
		m_pStepList[TYPE_STEP_004]->Load(NULL);
		m_pStepList[TYPE_STEP_005]->Load(NULL);
		m_pStepList[TYPE_STEP_006]->Load(NULL);
		m_pStepList[TYPE_STEP_007]->Load(NULL);
	}

	if (!(m_pStepList[TYPE_STEP_001] && m_pStepList[TYPE_STEP_001]->IsInit() &&
		m_pStepList[TYPE_STEP_002] && m_pStepList[TYPE_STEP_002]->IsInit() &&
		m_pStepList[TYPE_STEP_003] && m_pStepList[TYPE_STEP_003]->IsInit() &&
		m_pStepList[TYPE_STEP_004] && m_pStepList[TYPE_STEP_004]->IsInit() &&
		m_pStepList[TYPE_STEP_005] && m_pStepList[TYPE_STEP_005]->IsInit() &&
		m_pStepList[TYPE_STEP_006] && m_pStepList[TYPE_STEP_006]->IsInit() &&
		m_pStepList[TYPE_STEP_007] && m_pStepList[TYPE_STEP_007]->IsInit()))
	{
		bResult &= FALSE;
	}

	if (pstInspect->m_bInit)
	{
		m_pCalcSize->Load((INFO_INSPECTION*)pstInspect);
	}
	else
	{
		m_pCalcSize->Load(NULL);
	}

	if (!(m_pCalcSize && m_pCalcSize->IsInit()))
	{
		bResult &= FALSE;
	}
	
	m_bInit = bResult;
	return bResult;
}


void CInspectionCamera::Deinit()
{
	m_eCameraPosition = TYPE_CAMERAPOS_NONE;
	m_hNotifyWnd = NULL;

	for (int i = 0; i < (int)TYPE_STEP_MAX; i++)
	{
		if (m_pStepList[i])
			m_pStepList[i]->Deinit();
	}
	//Stop();

	m_bInit = FALSE;
}

CStep* CInspectionCamera::GetStep(TYPE_STEP eStep)
{
	CStep* pStep = NULL;
	if (TYPE_STEP_001 == eStep ||
		TYPE_STEP_002 == eStep ||
		TYPE_STEP_003 == eStep ||
		TYPE_STEP_004 == eStep ||
		TYPE_STEP_005 == eStep ||
		TYPE_STEP_006 == eStep ||
		TYPE_STEP_007 == eStep)
	{
		pStep = m_pStepList[eStep];
	}
	return pStep;
}

CStepSizeCalculation* CInspectionCamera::GetStepSizeCalc()
{
	return m_pCalcSize;
}

BOOL CInspectionCamera::Start()
{
	m_stProcInspection.m_bBreakProc = FALSE;

	m_stProcInspection.m_hEvent = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_stProcInspection.m_hEvent)
	{
		Stop();
		return FALSE;
	}
	m_stProcInspection.m_hEventForStop = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_stProcInspection.m_hEvent)
	{
		Stop();
		return FALSE;
	}

	/// Thread
	DWORD dwThreadId = 0;
	m_stProcInspection.m_hThread = ::CreateThread(0, 0, ProcInspection, LPVOID(this), 0, &dwThreadId);
	if (NULL == m_stProcInspection.m_hThread)
	{
		Stop();
		return FALSE;
	}
	
	m_stProcInspectionSub001.m_bBreakProc = FALSE;

	m_stProcInspectionSub001.m_hEvent = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_stProcInspectionSub001.m_hEvent)
	{
		Stop();
		return FALSE;
	}
	m_stProcInspectionSub001.m_hEventForStop = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_stProcInspectionSub001.m_hEvent)
	{
		Stop();
		return FALSE;
	}
	m_stProcInspectionSub001.m_hEventInspectionEnd = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_stProcInspectionSub001.m_hEvent)
	{
		Stop();
		return FALSE;
	}

	/// Thread
	DWORD dwThreadId001 = 0;
	m_stProcInspectionSub001.m_hThread = ::CreateThread(0, 0, ProcInspectionSub001, LPVOID(this), 0, &dwThreadId001);
	if (NULL == m_stProcInspectionSub001.m_hThread)
	{
		Stop();
		return FALSE;
	}

	m_stProcInspectionSub002.m_bBreakProc = FALSE;

	m_stProcInspectionSub002.m_hEvent = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_stProcInspectionSub002.m_hEvent)
	{
		Stop();
		return FALSE;
	}
	m_stProcInspectionSub002.m_hEventForStop = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_stProcInspectionSub002.m_hEvent)
	{
		Stop();
		return FALSE;
	}
	m_stProcInspectionSub002.m_hEventInspectionEnd = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_stProcInspectionSub002.m_hEvent)
	{
		Stop();
		return FALSE;
	}

	/// Thread
	DWORD dwThreadId002 = 0;
	m_stProcInspectionSub002.m_hThread = ::CreateThread(0, 0, ProcInspectionSub002, LPVOID(this), 0, &dwThreadId002);
	if (NULL == m_stProcInspectionSub002.m_hThread)
	{
		Stop();
		return FALSE;
	}

	m_stProcInspectionSub003.m_bBreakProc = FALSE;

	m_stProcInspectionSub003.m_hEvent = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_stProcInspectionSub003.m_hEvent)
	{
		Stop();
		return FALSE;
	}
	m_stProcInspectionSub003.m_hEventForStop = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_stProcInspectionSub003.m_hEvent)
	{
		Stop();
		return FALSE;
	}
	m_stProcInspectionSub003.m_hEventInspectionEnd = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_stProcInspectionSub003.m_hEvent)
	{
		Stop();
		return FALSE;
	}

	/// Thread
	DWORD dwThreadId003 = 0;
	m_stProcInspectionSub003.m_hThread = ::CreateThread(0, 0, ProcInspectionSub003, LPVOID(this), 0, &dwThreadId003);
	if (NULL == m_stProcInspectionSub003.m_hThread)
	{
		Stop();
		return FALSE;
	}

	m_stProcInspectionSub004.m_bBreakProc = FALSE;

	m_stProcInspectionSub004.m_hEvent = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_stProcInspectionSub004.m_hEvent)
	{
		Stop();
		return FALSE;
	}
	m_stProcInspectionSub004.m_hEventForStop = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_stProcInspectionSub004.m_hEvent)
	{
		Stop();
		return FALSE;
	}
	m_stProcInspectionSub004.m_hEventInspectionEnd = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_stProcInspectionSub004.m_hEvent)
	{
		Stop();
		return FALSE;
	}

	/// Thread
	DWORD dwThreadId004 = 0;
	m_stProcInspectionSub004.m_hThread = ::CreateThread(0, 0, ProcInspectionSub004, LPVOID(this), 0, &dwThreadId004);
	if (NULL == m_stProcInspectionSub004.m_hThread)
	{
		Stop();
		return FALSE;
	}
	
	m_stProcInspectionSub005.m_bBreakProc = FALSE;

	m_stProcInspectionSub005.m_hEvent = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_stProcInspectionSub005.m_hEvent)
	{
		Stop();
		return FALSE;
	}
	m_stProcInspectionSub005.m_hEventForStop = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_stProcInspectionSub005.m_hEvent)
	{
		Stop();
		return FALSE;
	}
	m_stProcInspectionSub005.m_hEventInspectionEnd = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_stProcInspectionSub005.m_hEvent)
	{
		Stop();
		return FALSE;
	}

	/// Thread
	DWORD dwThreadId005 = 0;
	m_stProcInspectionSub005.m_hThread = ::CreateThread(0, 0, ProcInspectionSub005, LPVOID(this), 0, &dwThreadId005);
	if (NULL == m_stProcInspectionSub005.m_hThread)
	{
		Stop();
		return FALSE;
	}

	m_stProcInspectionSub006.m_bBreakProc = FALSE;

	m_stProcInspectionSub006.m_hEvent = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_stProcInspectionSub006.m_hEvent)
	{
		Stop();
		return FALSE;
	}
	m_stProcInspectionSub006.m_hEventForStop = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_stProcInspectionSub006.m_hEvent)
	{
		Stop();
		return FALSE;
	}
	m_stProcInspectionSub006.m_hEventInspectionEnd = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_stProcInspectionSub006.m_hEvent)
	{
		Stop();
		return FALSE;
	}

	/// Thread
	DWORD dwThreadId006 = 0;
	m_stProcInspectionSub006.m_hThread = ::CreateThread(0, 0, ProcInspectionSub006, LPVOID(this), 0, &dwThreadId006);
	if (NULL == m_stProcInspectionSub006.m_hThread)
	{
		Stop();
		return FALSE;
	}

	m_stProcInspectionSub007.m_bBreakProc = FALSE;

	m_stProcInspectionSub007.m_hEvent = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_stProcInspectionSub007.m_hEvent)
	{
		Stop();
		return FALSE;
	}
	m_stProcInspectionSub007.m_hEventForStop = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_stProcInspectionSub007.m_hEvent)
	{
		Stop();
		return FALSE;
	}
	m_stProcInspectionSub007.m_hEventInspectionEnd = ::CreateEvent(0, TRUE, FALSE, 0);
	if (NULL == m_stProcInspectionSub007.m_hEvent)
	{
		Stop();
		return FALSE;
	}

	/// Thread
	DWORD dwThreadId007 = 0;
	m_stProcInspectionSub007.m_hThread = ::CreateThread(0, 0, ProcInspectionSub007, LPVOID(this), 0, &dwThreadId007);
	if (NULL == m_stProcInspectionSub007.m_hThread)
	{
		Stop();
		return FALSE;
	}
	//////////////////////////////

	return TRUE;
}

void CInspectionCamera::Stop()
{
	m_bWorking = FALSE;

	///////////////////////
	m_stProcInspectionSub001.m_bBreakProc = TRUE;
	CUtil::WaitnSleep(100);

	if (m_stProcInspectionSub001.m_hEvent)
	{
		::SetEvent(m_stProcInspectionSub001.m_hEvent);

		if (m_stProcInspectionSub001.m_hEventForStop)
		{
			::ResetEvent(m_stProcInspectionSub001.m_hEventForStop);
			::WaitForSingleObject(m_stProcInspectionSub001.m_hEventForStop, 5000);
			::CloseHandle(m_stProcInspectionSub001.m_hEventForStop);
			m_stProcInspectionSub001.m_hEventForStop = NULL;
		}
		if (m_stProcInspectionSub001.m_hEventInspectionEnd)
		{
			::CloseHandle(m_stProcInspectionSub001.m_hEventInspectionEnd);
			m_stProcInspectionSub001.m_hEventInspectionEnd = NULL;
		}

		::CloseHandle(m_stProcInspectionSub001.m_hEvent);
		m_stProcInspectionSub001.m_hEvent = NULL;
	}

	if (m_stProcInspectionSub001.m_hThread)
	{
		::CloseHandle(m_stProcInspectionSub001.m_hThread);
	}
	m_stProcInspectionSub001.m_hThread = NULL;

	m_stProcInspectionSub002.m_bBreakProc = TRUE;
	CUtil::WaitnSleep(100);

	if (m_stProcInspectionSub002.m_hEvent)
	{
		::SetEvent(m_stProcInspectionSub002.m_hEvent);

		if (m_stProcInspectionSub002.m_hEventForStop)
		{
			::ResetEvent(m_stProcInspectionSub002.m_hEventForStop);
			::WaitForSingleObject(m_stProcInspectionSub002.m_hEventForStop, 5000);
			::CloseHandle(m_stProcInspectionSub002.m_hEventForStop);
			m_stProcInspectionSub002.m_hEventForStop = NULL;
		}
		if (m_stProcInspectionSub002.m_hEventInspectionEnd)
		{
			::CloseHandle(m_stProcInspectionSub002.m_hEventInspectionEnd);
			m_stProcInspectionSub002.m_hEventInspectionEnd = NULL;
		}
		::CloseHandle(m_stProcInspectionSub002.m_hEvent);
		m_stProcInspectionSub002.m_hEvent = NULL;
	}

	if (m_stProcInspectionSub002.m_hThread)
	{
		::CloseHandle(m_stProcInspectionSub002.m_hThread);
	}
	m_stProcInspectionSub002.m_hThread = NULL;

	m_stProcInspectionSub003.m_bBreakProc = TRUE;
	CUtil::WaitnSleep(100);

	if (m_stProcInspectionSub003.m_hEvent)
	{
		::SetEvent(m_stProcInspectionSub003.m_hEvent);

		if (m_stProcInspectionSub003.m_hEventForStop)
		{
			::ResetEvent(m_stProcInspectionSub003.m_hEventForStop);
			::WaitForSingleObject(m_stProcInspectionSub003.m_hEventForStop, 5000);
			::CloseHandle(m_stProcInspectionSub003.m_hEventForStop);
			m_stProcInspectionSub003.m_hEventForStop = NULL;
		}
		if (m_stProcInspectionSub003.m_hEventInspectionEnd)
		{
			::CloseHandle(m_stProcInspectionSub003.m_hEventInspectionEnd);
			m_stProcInspectionSub003.m_hEventInspectionEnd = NULL;
		}
		::CloseHandle(m_stProcInspectionSub003.m_hEvent);
		m_stProcInspectionSub003.m_hEvent = NULL;
	}

	if (m_stProcInspectionSub003.m_hThread)
	{
		::CloseHandle(m_stProcInspectionSub003.m_hThread);
	}
	m_stProcInspectionSub003.m_hThread = NULL;

	m_stProcInspectionSub004.m_bBreakProc = TRUE;
	CUtil::WaitnSleep(100);

	if (m_stProcInspectionSub004.m_hEvent)
	{
		::SetEvent(m_stProcInspectionSub004.m_hEvent);

		if (m_stProcInspectionSub004.m_hEventForStop)
		{
			::ResetEvent(m_stProcInspectionSub004.m_hEventForStop);
			::WaitForSingleObject(m_stProcInspectionSub004.m_hEventForStop, 5000);
			::CloseHandle(m_stProcInspectionSub004.m_hEventForStop);
			m_stProcInspectionSub004.m_hEventForStop = NULL;
		}
		if (m_stProcInspectionSub004.m_hEventInspectionEnd)
		{
			::CloseHandle(m_stProcInspectionSub004.m_hEventInspectionEnd);
			m_stProcInspectionSub004.m_hEventInspectionEnd = NULL;
		}
		::CloseHandle(m_stProcInspectionSub004.m_hEvent);
		m_stProcInspectionSub004.m_hEvent = NULL;
	}

	if (m_stProcInspectionSub004.m_hThread)
	{
		::CloseHandle(m_stProcInspectionSub004.m_hThread);
	}
	m_stProcInspectionSub004.m_hThread = NULL;

	m_stProcInspectionSub005.m_bBreakProc = TRUE;
	CUtil::WaitnSleep(100);

	if (m_stProcInspectionSub005.m_hEvent)
	{
		::SetEvent(m_stProcInspectionSub005.m_hEvent);

		if (m_stProcInspectionSub005.m_hEventForStop)
		{
			::ResetEvent(m_stProcInspectionSub005.m_hEventForStop);
			::WaitForSingleObject(m_stProcInspectionSub005.m_hEventForStop, 5000);
			::CloseHandle(m_stProcInspectionSub005.m_hEventForStop);
			m_stProcInspectionSub005.m_hEventForStop = NULL;
		}
		if (m_stProcInspectionSub005.m_hEventInspectionEnd)
		{
			::CloseHandle(m_stProcInspectionSub005.m_hEventInspectionEnd);
			m_stProcInspectionSub005.m_hEventInspectionEnd = NULL;
		}
		::CloseHandle(m_stProcInspectionSub005.m_hEvent);
		m_stProcInspectionSub005.m_hEvent = NULL;
	}

	if (m_stProcInspectionSub005.m_hThread)
	{
		::CloseHandle(m_stProcInspectionSub005.m_hThread);
	}
	m_stProcInspectionSub005.m_hThread = NULL;

	m_stProcInspectionSub006.m_bBreakProc = TRUE;
	CUtil::WaitnSleep(100);

	if (m_stProcInspectionSub006.m_hEvent)
	{
		::SetEvent(m_stProcInspectionSub006.m_hEvent);

		if (m_stProcInspectionSub006.m_hEventForStop)
		{
			::ResetEvent(m_stProcInspectionSub006.m_hEventForStop);
			::WaitForSingleObject(m_stProcInspectionSub006.m_hEventForStop, 5000);
			::CloseHandle(m_stProcInspectionSub006.m_hEventForStop);
			m_stProcInspectionSub006.m_hEventForStop = NULL;
		}
		if (m_stProcInspectionSub006.m_hEventInspectionEnd)
		{
			::CloseHandle(m_stProcInspectionSub006.m_hEventInspectionEnd);
			m_stProcInspectionSub006.m_hEventInspectionEnd = NULL;
		}
		::CloseHandle(m_stProcInspectionSub006.m_hEvent);
		m_stProcInspectionSub006.m_hEvent = NULL;
	}

	if (m_stProcInspectionSub006.m_hThread)
	{
		::CloseHandle(m_stProcInspectionSub006.m_hThread);
	}
	m_stProcInspectionSub006.m_hThread = NULL;

	m_stProcInspectionSub007.m_bBreakProc = TRUE;
	CUtil::WaitnSleep(100);

	if (m_stProcInspectionSub007.m_hEvent)
	{
		::SetEvent(m_stProcInspectionSub007.m_hEvent);

		if (m_stProcInspectionSub007.m_hEventForStop)
		{
			::ResetEvent(m_stProcInspectionSub007.m_hEventForStop);
			::WaitForSingleObject(m_stProcInspectionSub007.m_hEventForStop, 5000);
			::CloseHandle(m_stProcInspectionSub007.m_hEventForStop);
			m_stProcInspectionSub007.m_hEventForStop = NULL;
		}
		if (m_stProcInspectionSub007.m_hEventInspectionEnd)
		{
			::CloseHandle(m_stProcInspectionSub007.m_hEventInspectionEnd);
			m_stProcInspectionSub007.m_hEventInspectionEnd = NULL;
		}
		::CloseHandle(m_stProcInspectionSub007.m_hEvent);
		m_stProcInspectionSub007.m_hEvent = NULL;
	}

	if (m_stProcInspectionSub007.m_hThread)
	{
		::CloseHandle(m_stProcInspectionSub007.m_hThread);
	}
	m_stProcInspectionSub007.m_hThread = NULL;
	///////////////////////////////

	m_stProcInspection.m_bBreakProc = TRUE;
	CUtil::WaitnSleep(100);

	if (m_stProcInspection.m_hEvent)
	{
		::SetEvent(m_stProcInspection.m_hEvent);

		if (m_stProcInspection.m_hEventForStop)
		{
			::ResetEvent(m_stProcInspection.m_hEventForStop);
			::WaitForSingleObject(m_stProcInspection.m_hEventForStop, 5000);
			::CloseHandle(m_stProcInspection.m_hEventForStop);
			m_stProcInspection.m_hEventForStop = NULL;
		}
		::CloseHandle(m_stProcInspection.m_hEvent);
		m_stProcInspection.m_hEvent = NULL;
	}

	if (m_stProcInspection.m_hThread)
	{
		::CloseHandle(m_stProcInspection.m_hThread);
	}
	m_stProcInspection.m_hThread = NULL;
}


BOOL CInspectionCamera::Process(shared_ptr<CSampleSide> pSample)
{
	if (FALSE == IsInit() || TRUE == IsWorking() || NULL == pSample)
		return FALSE;

	m_SampleSide = pSample;

	::SetEvent(m_stProcInspection.m_hEvent);
	return TRUE;
}

BOOL CInspectionCamera::ProcessUpdateImage(const INFO_IMAGE* pRefImage)
{
	if (FALSE == IsInit() || FALSE == IsWorking() || FALSE == IsWaitingAcquire())
		return FALSE;

	CSampleSide* pSample = GetSample().get();
	if (NULL == pSample || NULL)
		return FALSE;

	if (TYPE_CAMERAPOS_FIRST == m_eCameraPosition)
		pSample->m_pRefImage = (INFO_IMAGE*)pRefImage;
	else if (TYPE_CAMERAPOS_SECOND == m_eCameraPosition)
		pSample->m_pRefImage = (INFO_IMAGE*)pRefImage;
	else
		return FALSE;


	::SetEvent(m_stProcInspection.m_hEvent);
	return TRUE;
}

BOOL CInspectionCamera::Process(TYPE_STEP eStep, CSampleSide& sample)
{
	m_bWorking = TRUE;

	BOOL bResult = ProcessStep(eStep, sample);

	m_bWorking = FALSE;
	return bResult;
}

BOOL CInspectionCamera::Process(TYPE_STEP eStep, CSampleSide& sample, cv::Mat captureImg)
{
	m_bWorking = TRUE;

	BOOL bResult = ProcessStep(eStep, sample, captureImg);

	m_bWorking = FALSE;
	return bResult;
}

std::shared_ptr<CSampleSide> CInspectionCamera::GetSample()
{
	return m_SampleSide;
}
void CInspectionCamera::SetSample(shared_ptr<CSampleSide> pSample)
{
	m_SampleSide = pSample;
}

void CInspectionCamera::PushSample(CSample* pSample)
{
	if (pSample)
	{
		m_SampleQueue.push_back(pSample);
	}

	//const int size = GetCountFromSampleQueue();
}

INFO_INSPECTION* CInspectionCamera::Load(const TCHAR* pszPath)
{
	BOOL bExist = CUtil::IsExistFile(pszPath);
	if (FALSE == bExist)
		return FALSE;

	INFO_INSPECTION* pInfo = NULL;
	return pInfo;
}

BOOL CInspectionCamera::ProcessStep(TYPE_STEP eStep, CSampleSide& sample)
{
	BOOL bResult = FALSE;

	CStep* pStep = GetStep(eStep);
	if (pStep)
		bResult = pStep->Process(sample);
	return bResult;
}

BOOL CInspectionCamera::ProcessStep(TYPE_STEP eStep, CSampleSide& sample, cv::Mat captureImg)
{
	BOOL bResult = FALSE;

	CStep* pStep = GetStep(eStep);
	if (pStep)
		bResult = pStep->Process(sample, captureImg);
	return bResult;
}

DWORD WINAPI CInspectionCamera::ProcInspection(LPVOID lpArg)
{
	CInspectionCamera* pInspectionProc = (CInspectionCamera*)lpArg;
	return pInspectionProc->ProcInspection();
}

DWORD WINAPI CInspectionCamera::ProcInspectionSub001(LPVOID lpArg)
{
	CInspectionCamera* pInspectionProc001 = (CInspectionCamera*)lpArg;
	return pInspectionProc001->ProcInspectionSub001();
}

DWORD WINAPI CInspectionCamera::ProcInspectionSub002(LPVOID lpArg)
{
	CInspectionCamera* pInspectionProc002 = (CInspectionCamera*)lpArg;
	return pInspectionProc002->ProcInspectionSub002();
}

DWORD WINAPI CInspectionCamera::ProcInspectionSub003(LPVOID lpArg)
{
	CInspectionCamera* pInspectionProc003 = (CInspectionCamera*)lpArg;
	return pInspectionProc003->ProcInspectionSub003();
}

DWORD WINAPI CInspectionCamera::ProcInspectionSub004(LPVOID lpArg)
{
	CInspectionCamera* pInspectionProc004 = (CInspectionCamera*)lpArg;
	return pInspectionProc004->ProcInspectionSub004();
}

DWORD WINAPI CInspectionCamera::ProcInspectionSub005(LPVOID lpArg)
{
	CInspectionCamera* pInspectionProc005 = (CInspectionCamera*)lpArg;
	return pInspectionProc005->ProcInspectionSub005();
}

DWORD WINAPI CInspectionCamera::ProcInspectionSub006(LPVOID lpArg)
{
	CInspectionCamera* pInspectionProc006 = (CInspectionCamera*)lpArg;
	return pInspectionProc006->ProcInspectionSub006();
}

DWORD WINAPI CInspectionCamera::ProcInspectionSub007(LPVOID lpArg)
{
	CInspectionCamera* pInspectionProc007 = (CInspectionCamera*)lpArg;
	return pInspectionProc007->ProcInspectionSub007();
}

DWORD CInspectionCamera::ProcInspectionSub001()
{
	if (m_stProcInspectionSub001.m_hEvent)
		::ResetEvent(m_stProcInspectionSub001.m_hEvent);
	else
		return S_OK;

	do{
		if (WAIT_OBJECT_0 == ::WaitForSingleObject(m_stProcInspectionSub001.m_hEvent, INFINITE))
		{
			::ResetEvent(m_stProcInspectionSub001.m_hEvent);
			if (m_stProcInspectionSub001.m_bBreakProc)
				break;
			ProcInspectionStep001();
			::SetEvent(m_stProcInspectionSub001.m_hEventInspectionEnd);
		}
	} while (!m_stProcInspectionSub001.m_bBreakProc);

	if (m_stProcInspectionSub001.m_hEventForStop)
	{
		::SetEvent(m_stProcInspectionSub001.m_hEventForStop);
	}
	return S_OK;
}

DWORD CInspectionCamera::ProcInspectionSub002()
{
	if (m_stProcInspectionSub002.m_hEvent)
		::ResetEvent(m_stProcInspectionSub002.m_hEvent);
	else
		return S_OK;

	do{
		if (WAIT_OBJECT_0 == ::WaitForSingleObject(m_stProcInspectionSub002.m_hEvent, INFINITE))
		{
			::ResetEvent(m_stProcInspectionSub002.m_hEvent);
			if (m_stProcInspectionSub002.m_bBreakProc)
				break;
			ProcInspectionStep002();
			::SetEvent(m_stProcInspectionSub002.m_hEventInspectionEnd);
		}
	} while (!m_stProcInspectionSub002.m_bBreakProc);

	if (m_stProcInspectionSub002.m_hEventForStop)
	{
		::SetEvent(m_stProcInspectionSub002.m_hEventForStop);
	}
	return S_OK;
}

DWORD CInspectionCamera::ProcInspectionSub003()
{
	if (m_stProcInspectionSub003.m_hEvent)
		::ResetEvent(m_stProcInspectionSub003.m_hEvent);
	else
		return S_OK;

	do{
		if (WAIT_OBJECT_0 == ::WaitForSingleObject(m_stProcInspectionSub003.m_hEvent, INFINITE))
		{
			::ResetEvent(m_stProcInspectionSub003.m_hEvent);
			if (m_stProcInspectionSub003.m_bBreakProc)
				break;
			ProcInspectionStep003();
			::SetEvent(m_stProcInspectionSub003.m_hEventInspectionEnd);
		}
	} while (!m_stProcInspectionSub003.m_bBreakProc);

	if (m_stProcInspectionSub003.m_hEventForStop)
	{
		::SetEvent(m_stProcInspectionSub003.m_hEventForStop);
	}
	return S_OK;
}

DWORD CInspectionCamera::ProcInspectionSub004()
{
	if (m_stProcInspectionSub004.m_hEvent)
		::ResetEvent(m_stProcInspectionSub004.m_hEvent);
	else
		return S_OK;

	do{
		if (WAIT_OBJECT_0 == ::WaitForSingleObject(m_stProcInspectionSub004.m_hEvent, INFINITE))
		{
			::ResetEvent(m_stProcInspectionSub004.m_hEvent);
			if (m_stProcInspectionSub004.m_bBreakProc)
				break;
			ProcInspectionStep004();
			::SetEvent(m_stProcInspectionSub004.m_hEventInspectionEnd);
		}
	} while (!m_stProcInspectionSub004.m_bBreakProc);

	if (m_stProcInspectionSub004.m_hEventForStop)
	{
		::SetEvent(m_stProcInspectionSub004.m_hEventForStop);
	}
	return S_OK;
}

DWORD CInspectionCamera::ProcInspectionSub005()
{
	if (m_stProcInspectionSub005.m_hEvent)
		::ResetEvent(m_stProcInspectionSub005.m_hEvent);
	else
		return S_OK;

	do{
		if (WAIT_OBJECT_0 == ::WaitForSingleObject(m_stProcInspectionSub005.m_hEvent, INFINITE))
		{
			::ResetEvent(m_stProcInspectionSub005.m_hEvent);
			if (m_stProcInspectionSub005.m_bBreakProc)
				break;
			ProcInspectionStep005();
			::SetEvent(m_stProcInspectionSub005.m_hEventInspectionEnd);
		}
	} while (!m_stProcInspectionSub005.m_bBreakProc);

	if (m_stProcInspectionSub005.m_hEventForStop)
	{
		::SetEvent(m_stProcInspectionSub005.m_hEventForStop);
	}
	return S_OK;
}

DWORD CInspectionCamera::ProcInspectionSub006()
{
	if (m_stProcInspectionSub006.m_hEvent)
		::ResetEvent(m_stProcInspectionSub006.m_hEvent);
	else
		return S_OK;

	do{
		if (WAIT_OBJECT_0 == ::WaitForSingleObject(m_stProcInspectionSub006.m_hEvent, INFINITE))
		{
			::ResetEvent(m_stProcInspectionSub006.m_hEvent);
			if (m_stProcInspectionSub006.m_bBreakProc)
				break;
			ProcInspectionStep006();
			::SetEvent(m_stProcInspectionSub006.m_hEventInspectionEnd);
		}
	} while (!m_stProcInspectionSub006.m_bBreakProc);

	if (m_stProcInspectionSub006.m_hEventForStop)
	{
		::SetEvent(m_stProcInspectionSub006.m_hEventForStop);
	}
	return S_OK;
}

DWORD CInspectionCamera::ProcInspectionSub007()
{
	if (m_stProcInspectionSub007.m_hEvent)
		::ResetEvent(m_stProcInspectionSub007.m_hEvent);
	else
		return S_OK;
	do{
		if (WAIT_OBJECT_0 == ::WaitForSingleObject(m_stProcInspectionSub007.m_hEvent, INFINITE))
		{
			::ResetEvent(m_stProcInspectionSub007.m_hEvent);
			if (m_stProcInspectionSub007.m_bBreakProc)
				break;
			ProcInspectionStep007();
		}
	} while (!m_stProcInspectionSub007.m_bBreakProc);

	if (m_stProcInspectionSub007.m_hEventForStop)
	{
		::SetEvent(m_stProcInspectionSub007.m_hEventForStop);
	}
	return S_OK;
}

DWORD CInspectionCamera::ProcInspection()
{
	if (m_stProcInspection.m_hEvent)
		::ResetEvent(m_stProcInspection.m_hEvent);
	else
		return S_OK;

	const BOOL bNextGrab01 = TRUE;
	const BOOL bNextGrab02 = TRUE;
	const BOOL bNextGrab03 = TRUE;
	const BOOL bNextGrab04 = TRUE;
	const BOOL bNextGrab05 = TRUE;
	const BOOL bNextGrab06 = TRUE;

	CSampleSide* pSample = NULL;
	cv::Mat tmpImg;
	BOOL bRES = FALSE;
	CUtil::PrintDebugString(_T("CAMERAPOS[%d]   Proc : Start Thread  \r\n"), m_eCameraPosition);
	do
	{
		if (WAIT_OBJECT_0 == ::WaitForSingleObject(m_stProcInspection.m_hEvent, INFINITE))
		{
			::ResetEvent(m_stProcInspection.m_hEvent);
			if (m_stProcInspection.m_bBreakProc)
				break;
			m_bWorking = TRUE;
			{
				pSample = GetSample().get();
				tmpImg = cv::Mat(pSample->m_pRefImage->m_stFrame.m_dwHeight, pSample->m_pRefImage->m_stFrame.m_dwWidth, CV_8UC3, pSample->m_pRefImage->m_pBuffer, pSample->m_pRefImage->m_stFrame.m_dwPitch);
				m_inspectImg.img001 = tmpImg.clone();

				// TYPE_STEP_001: CStepSize
				::SetEvent(m_stProcInspectionSub001.m_hEvent);
				ProcCaptureStep001(bNextGrab01);

				if (m_stProcInspection.m_bBreakProc)
					break;
				WaitingForGrab();

				pSample = GetSample().get();
				tmpImg = cv::Mat(pSample->m_pRefImage->m_stFrame.m_dwHeight, pSample->m_pRefImage->m_stFrame.m_dwWidth, CV_8UC3, pSample->m_pRefImage->m_pBuffer, pSample->m_pRefImage->m_stFrame.m_dwPitch);
				m_inspectImg.img002 = tmpImg.clone();

				// TYPE_STEP_002: CStepStain
				::SetEvent(m_stProcInspectionSub002.m_hEvent);				
				ProcCaptureStep002(bNextGrab02);

				if (m_stProcInspection.m_bBreakProc)
					break;
				WaitingForGrab();

				pSample = GetSample().get();
				tmpImg = cv::Mat(pSample->m_pRefImage->m_stFrame.m_dwHeight, pSample->m_pRefImage->m_stFrame.m_dwWidth, CV_8UC3, pSample->m_pRefImage->m_pBuffer, pSample->m_pRefImage->m_stFrame.m_dwPitch);
				m_inspectImg.img003 = tmpImg.clone();

				// TYPE_STEP_003: CStepDiffer
				::SetEvent(m_stProcInspectionSub003.m_hEvent);				
				ProcCaptureStep003(bNextGrab03);

				if (m_stProcInspection.m_bBreakProc)
					break;
				WaitingForGrab();

				pSample = GetSample().get();
				tmpImg = cv::Mat(pSample->m_pRefImage->m_stFrame.m_dwHeight, pSample->m_pRefImage->m_stFrame.m_dwWidth, CV_8UC3, pSample->m_pRefImage->m_pBuffer, pSample->m_pRefImage->m_stFrame.m_dwPitch);
				m_inspectImg.img004 = tmpImg.clone();

				// TYPE_STEP_004: CStepBubble
				::SetEvent(m_stProcInspectionSub004.m_hEvent);				
				ProcCaptureStep004(bNextGrab04);
				if (m_stProcInspection.m_bBreakProc)
					break;
				WaitingForGrab();

				// Version 1.3.7.0
				//pSample = GetSample().get();
				//tmpImg = cv::Mat(pSample->m_pRefImage->m_stFrame.m_dwHeight, pSample->m_pRefImage->m_stFrame.m_dwWidth, CV_8UC3, pSample->m_pRefImage->m_pBuffer, pSample->m_pRefImage->m_stFrame.m_dwPitch);
				//m_inspectImg.img005 = tmpImg.clone();

				// TYPE_STEP_005: CStepScratch
				::SetEvent(m_stProcInspectionSub005.m_hEvent);				
				//ProcCaptureStep005(bNextGrab05);
				if (m_stProcInspection.m_bBreakProc)
					break;
				//WaitingForGrab();

				// Version 1.3.7.0
				//tmpImg = cv::Mat(pSample->m_pRefImage->m_stFrame.m_dwHeight, pSample->m_pRefImage->m_stFrame.m_dwWidth, CV_8UC3, pSample->m_pRefImage->m_pBuffer, pSample->m_pRefImage->m_stFrame.m_dwPitch);
				//m_inspectImg.img006 = tmpImg.clone();

				// TYPE_STEP_006: CStepStamp
				::SetEvent(m_stProcInspectionSub006.m_hEvent);				
				ProcCaptureStep006(bNextGrab06);
				if (m_stProcInspection.m_bBreakProc)
					break;
				WaitingForGrab();

				pSample = GetSample().get();
				tmpImg = cv::Mat(pSample->m_pRefImage->m_stFrame.m_dwHeight, pSample->m_pRefImage->m_stFrame.m_dwWidth, CV_8UC3, pSample->m_pRefImage->m_pBuffer, pSample->m_pRefImage->m_stFrame.m_dwPitch);
				m_inspectImg.img007 = tmpImg.clone();

				// TYPE_STEP_007: CStepSizeSecond
				::SetEvent(m_stProcInspectionSub007.m_hEvent);
			}
			m_bWorking = FALSE;
		}
	} while (!m_stProcInspection.m_bBreakProc);

	m_SampleSide.reset();
	CUtil::PrintDebugString(_T("CAMERAPOS[%d]   Proc : End Thread  \r\n"), m_eCameraPosition);
	m_bWorking = FALSE;

	if (m_stProcInspection.m_hEventForStop)
	{
		::SetEvent(m_stProcInspection.m_hEventForStop);
	}
	return S_OK;
}


BOOL CInspectionCamera::ProcInspectionStep001()
{
	BOOL bRes001 = FALSE;

	CSampleSide* pSample = GetSample().get();
	if (TYPE_CAMERAPOS_FIRST == m_eCameraPosition)
	{
		CUtil::PrintDebugString(_T("Proc: CStepSize \r\n"));
		// Print Log
		{
			if (m_stLogFunc.m_pFuncTextLog && m_stLogFunc.m_pArg)
			{
				if (m_stInspectStepEnable.m_bStep001)
					m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepSize");
				else
					m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepSize (Opt Disable)");
			}
		}

		if (m_stInspectStepEnable.m_bStep001)
		{
			bRes001 = ProcessStep(TYPE_STEP_001, *pSample, m_inspectImg.img001);
		}
	}
	else if (TYPE_CAMERAPOS_SECOND == m_eCameraPosition)
	{
#ifdef DEF_SECONDCAMERA_CHECKSIZE
		CUtil::PrintDebugString(_T("Proc: CStepSize \r\n"));
		// Print Log
		{
			if (m_stLogFunc.m_pFuncTextLog && m_stLogFunc.m_pArg)
			{
				if (m_stInspectStepEnable.m_bStep001)
					m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepSize");
				else
					m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepSize (Opt Disable)");
			}
		}

		if (m_stInspectStepEnable.m_bStep001)
		{
			bRes001 = ProcessStep(TYPE_STEP_001, *pSample, m_inspectImg.img001);
		}
#else
		CUtil::PrintDebugString(_T("Proc: CStepSize Skipped \r\n"));
		// Print Log
		{
			if (m_stLogFunc.m_pFuncTextLog && m_stLogFunc.m_pArg)
			{
				m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepSize Skipped");
			}
		}
#endif
	}

	// Print Log
	{
		if (m_stLogFunc.m_pFuncTextLog && m_stLogFunc.m_pArg)
			m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepSize Process End");
	}

	//::SetEvent(m_stProcInspectionSub001.m_hEventInspectionEnd);

	m_stProcNotify.m_pFuncNotifyInspectionResult(m_eCameraPosition, TYPE_STEP_001, bRes001, m_stProcNotify.m_pArgument, FALSE);

	return bRes001;
}

void CInspectionCamera::ProcCaptureStep001(BOOL bWaitAcq)
{
	if (bWaitAcq)
		m_bWaitingAcq = bWaitAcq;
	m_stProcNotify.m_pFuncNotifyInspectionResult(m_eCameraPosition, TYPE_STEP_001, TRUE, m_stProcNotify.m_pArgument, TRUE);
}

BOOL CInspectionCamera::ProcInspectionStep002()
{
	CUtil::PrintDebugString(_T("Proc: CStepStain \r\n"));
	// Print Log
	{
		if (m_stLogFunc.m_pFuncTextLog && m_stLogFunc.m_pArg)
		{
			if (m_stInspectStepEnable.m_bStep002)
				m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepStain");
			else
				m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepStain (Opt Disable)");
		}
	}

	BOOL bRes002 = FALSE;
	if (m_stInspectStepEnable.m_bStep002)
	{
		CSampleSide* pSample = GetSample().get();
		bRes002 = ProcessStep(TYPE_STEP_002, *pSample, m_inspectImg.img002);
	}

	// Print Log
	{
		if (m_stLogFunc.m_pFuncTextLog && m_stLogFunc.m_pArg)
			m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepStain Process End");
	}
	
	//::SetEvent(m_stProcInspectionSub002.m_hEventInspectionEnd);

	m_stProcNotify.m_pFuncNotifyInspectionResult(m_eCameraPosition, TYPE_STEP_002, bRes002, m_stProcNotify.m_pArgument, FALSE);

	return bRes002;
}

void CInspectionCamera::ProcCaptureStep002(BOOL bWaitAcq)
{
	if (bWaitAcq)
		m_bWaitingAcq = bWaitAcq;
	m_stProcNotify.m_pFuncNotifyInspectionResult(m_eCameraPosition, TYPE_STEP_002, TRUE, m_stProcNotify.m_pArgument, TRUE);
}

BOOL CInspectionCamera::ProcInspectionStep003()
{
	CUtil::PrintDebugString(_T("Proc: CStepDiffer \r\n"));
	// Print Log
	{
		if (m_stLogFunc.m_pFuncTextLog && m_stLogFunc.m_pArg)
		{
			if (m_stInspectStepEnable.m_bStep003)
				m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepDiffer");
			else
				m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepDiffer (Opt Disable)");
		}
	}

	BOOL bRes003 = FALSE;
	if (m_stInspectStepEnable.m_bStep003)
	{
		CSampleSide* pSample = GetSample().get();
		bRes003 = ProcessStep(TYPE_STEP_003, *pSample, m_inspectImg.img003);
	}

	// Print Log
	{
		if (m_stLogFunc.m_pFuncTextLog && m_stLogFunc.m_pArg)
			m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepDiffer Process End");
	}

	//::SetEvent(m_stProcInspectionSub003.m_hEventInspectionEnd);

	m_stProcNotify.m_pFuncNotifyInspectionResult(m_eCameraPosition, TYPE_STEP_003, bRes003, m_stProcNotify.m_pArgument, FALSE);

	return bRes003;
}

void CInspectionCamera::ProcCaptureStep003(BOOL bWaitAcq)
{
	if (bWaitAcq)
		m_bWaitingAcq = bWaitAcq;
	m_stProcNotify.m_pFuncNotifyInspectionResult(m_eCameraPosition, TYPE_STEP_003, TRUE, m_stProcNotify.m_pArgument, TRUE);
}

BOOL CInspectionCamera::ProcInspectionStep004()
{
	CUtil::PrintDebugString(_T("Proc: CStepBubble \r\n"));
	// Print Log
	{
		if (m_stLogFunc.m_pFuncTextLog && m_stLogFunc.m_pArg)
		{
			if (m_stInspectStepEnable.m_bStep004)
				m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepBubble");
			else
				m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepBubble (Opt Disable)");
		}
	}

	BOOL bRes004 = FALSE;
	if (m_stInspectStepEnable.m_bStep004)
	{
		CSampleSide* pSample = GetSample().get();
		bRes004 = ProcessStep(TYPE_STEP_004, *pSample, m_inspectImg.img004);
	}

	// Print Log
	{
		if (m_stLogFunc.m_pFuncTextLog && m_stLogFunc.m_pArg)
			m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepBubble Process End");
	}

	//::SetEvent(m_stProcInspectionSub004.m_hEventInspectionEnd);

	m_stProcNotify.m_pFuncNotifyInspectionResult(m_eCameraPosition, TYPE_STEP_004, bRes004, m_stProcNotify.m_pArgument, FALSE);

	return bRes004;
}

void CInspectionCamera::ProcCaptureStep004(BOOL bWaitAcq)
{
	if (bWaitAcq)
		m_bWaitingAcq = bWaitAcq;
	m_stProcNotify.m_pFuncNotifyInspectionResult(m_eCameraPosition, TYPE_STEP_004, TRUE, m_stProcNotify.m_pArgument, TRUE);
}

BOOL CInspectionCamera::ProcInspectionStep005()
{
	// Version 1.3.6.8 : /**/
	/*
	CUtil::PrintDebugString(_T("Proc: CStepScratch \r\n"));
	// Print Log
	{
		if (m_stLogFunc.m_pFuncTextLog && m_stLogFunc.m_pArg)
		{
			if (m_stInspectStepEnable.m_bStep005)
				m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepScratch");
			else
				m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepScratch (Opt Disable)");
		}
	}

	BOOL bRes005 = FALSE;
	if (m_stInspectStepEnable.m_bStep005)
	{
		CSampleSide* pSample = GetSample().get();
		bRes005 = ProcessStep(TYPE_STEP_005, *pSample, m_inspectImg.img005);
	}

	// Print Log
	{
		if (m_stLogFunc.m_pFuncTextLog && m_stLogFunc.m_pArg)
			m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepScratch Process End");
	}

	//::SetEvent(m_stProcInspectionSub005.m_hEventInspectionEnd);
	*/
	// Version 1.3.6.8
	BOOL bRes005 = TRUE;
	m_stProcNotify.m_pFuncNotifyInspectionResult(m_eCameraPosition, TYPE_STEP_005, bRes005, m_stProcNotify.m_pArgument, FALSE);

	return bRes005;
}

void CInspectionCamera::ProcCaptureStep005(BOOL bWaitAcq)
{
	if (bWaitAcq)
		m_bWaitingAcq = bWaitAcq;
	m_stProcNotify.m_pFuncNotifyInspectionResult(m_eCameraPosition, TYPE_STEP_005, TRUE, m_stProcNotify.m_pArgument, TRUE);
}

BOOL CInspectionCamera::ProcInspectionStep006()
{
	/*
	CUtil::PrintDebugString(_T("Proc: CStepStamp \r\n"));
	// Print Log
	{
		if (m_stLogFunc.m_pFuncTextLog && m_stLogFunc.m_pArg)
		{
			if (m_stInspectStepEnable.m_bStep006)
				m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepStamp");
			else
				m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepStamp (Opt Disable)");
		}
	}

	BOOL bRes006 = FALSE;
	if (m_stInspectStepEnable.m_bStep006)
	{
		CSampleSide* pSample = GetSample().get();
		bRes006 = ProcessStep(TYPE_STEP_006, *pSample, m_inspectImg.img006);
	}

	// Print Log
	{
		if (m_stLogFunc.m_pFuncTextLog && m_stLogFunc.m_pArg)
			m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepStamp Process End");
	}

	//::SetEvent(m_stProcInspectionSub005.m_hEventInspectionEnd);
	*/
	BOOL bRes006 = TRUE;
	m_stProcNotify.m_pFuncNotifyInspectionResult(m_eCameraPosition, TYPE_STEP_006, bRes006, m_stProcNotify.m_pArgument, FALSE);

	return bRes006;
}

void CInspectionCamera::ProcCaptureStep006(BOOL bWaitAcq)
{
	if (bWaitAcq)
		m_bWaitingAcq = bWaitAcq;
	m_stProcNotify.m_pFuncNotifyInspectionResult(m_eCameraPosition, TYPE_STEP_006, TRUE, m_stProcNotify.m_pArgument, TRUE);
}

BOOL CInspectionCamera::ProcInspectionStep007()
{
	BOOL bRes007 = FALSE;

	CSampleSide* pSample = GetSample().get();
	if (TYPE_CAMERAPOS_FIRST == m_eCameraPosition)
	{
		CUtil::PrintDebugString(_T("Proc: CStepSizeSecond \r\n"));
		// Print Log
		{
			if (m_stLogFunc.m_pFuncTextLog && m_stLogFunc.m_pArg)
			{
				if (m_stInspectStepEnable.m_bStep001)
					m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepSizeSecond");
				else
					m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepSizeSecond (Opt Disable)");
			}
		}

		if (m_stInspectStepEnable.m_bStep001)
		{
			bRes007 = ProcessStep(TYPE_STEP_007, *pSample, m_inspectImg.img007);
		}

		m_pCalcSize->CalcDistance(*pSample, m_inspectImg.img007);

	}
	else if (TYPE_CAMERAPOS_SECOND == m_eCameraPosition)
	{
#ifdef DEF_SECONDCAMERA_CHECKSIZE
		CUtil::PrintDebugString(_T("Proc: CStepSizeSecond \r\n"));
		// Print Log
		{
			if (m_stLogFunc.m_pFuncTextLog && m_stLogFunc.m_pArg)
			{
				if (m_stInspectStepEnable.m_bStep001)
					m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepSizeSecond");
				else
					m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepSizeSecond (Opt Disable)");
			}
		}

		if (m_stInspectStepEnable.m_bStep001)
		{
			bRes007 = ProcessStep(TYPE_STEP_007, *pSample, m_inspectImg.img007);
		}

		m_pCalcSize->CalcDistance(*pSample, m_inspectImg.img007);
#else
		CUtil::PrintDebugString(_T("Proc: CStepSizeSecond Skipped \r\n"));
		// Print Log
		{
			if (m_stLogFunc.m_pFuncTextLog && m_stLogFunc.m_pArg)
			{
				m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepSizeSecond Skipped");
			}
		}
#endif
	}

	// Print Log
	{
		if (m_stLogFunc.m_pFuncTextLog && m_stLogFunc.m_pArg)
			m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, TYPE_CAMERAPOS_NONE, "MAIN", "Proc: CStepSizeSecond Process End");
	}
	
	/////////////////////////////////////////////////////
	::SetEvent(m_stProcInspectionSub007.m_hEventInspectionEnd);
	if (WAIT_OBJECT_0 == ::WaitForSingleObject(m_stProcInspectionSub001.m_hEventInspectionEnd, INFINITE)){
		if (WAIT_OBJECT_0 == ::WaitForSingleObject(m_stProcInspectionSub002.m_hEventInspectionEnd, INFINITE)){
			if (WAIT_OBJECT_0 == ::WaitForSingleObject(m_stProcInspectionSub003.m_hEventInspectionEnd, INFINITE)){
				if (WAIT_OBJECT_0 == ::WaitForSingleObject(m_stProcInspectionSub004.m_hEventInspectionEnd, INFINITE)){
					if (WAIT_OBJECT_0 == ::WaitForSingleObject(m_stProcInspectionSub005.m_hEventInspectionEnd, INFINITE)){
						if (WAIT_OBJECT_0 == ::WaitForSingleObject(m_stProcInspectionSub006.m_hEventInspectionEnd, INFINITE)){
							if (WAIT_OBJECT_0 == ::WaitForSingleObject(m_stProcInspectionSub007.m_hEventInspectionEnd, INFINITE)){
								::ResetEvent(m_stProcInspectionSub007.m_hEventInspectionEnd);
								::ResetEvent(m_stProcInspectionSub006.m_hEventInspectionEnd);
								::ResetEvent(m_stProcInspectionSub005.m_hEventInspectionEnd);
								::ResetEvent(m_stProcInspectionSub004.m_hEventInspectionEnd);
								::ResetEvent(m_stProcInspectionSub003.m_hEventInspectionEnd);
								::ResetEvent(m_stProcInspectionSub002.m_hEventInspectionEnd);
								::ResetEvent(m_stProcInspectionSub001.m_hEventInspectionEnd);

								m_stProcNotify.m_pFuncNotifyInspectionResult(m_eCameraPosition, TYPE_STEP_007, bRes007, m_stProcNotify.m_pArgument, FALSE);
							}
						}
					}
				}
			}
		}
	}
	return bRes007;
}

void CInspectionCamera::ProcCaptureStep007()
{
	m_stProcNotify.m_pFuncNotifyInspectionResult(m_eCameraPosition, TYPE_STEP_007, TRUE, m_stProcNotify.m_pArgument, TRUE);
}

void CInspectionCamera::WaitingForGrab()
{
	// Wait For Acquisition: Strobe Change & Capure Image
	::WaitForSingleObject(m_stProcInspection.m_hEvent, INFINITE);
	::ResetEvent(m_stProcInspection.m_hEvent);
	m_bWaitingAcq = FALSE;

	Sleep(100);
}


void CInspectionCamera::UpdateEnableStep(const INFO_OPT_INSPECTSTEP* pstStepOpt)
{
	if (NULL == pstStepOpt)
		return;
	
	m_stInspectStepEnable.m_bStep001 = pstStepOpt->m_bStep001;
	m_stInspectStepEnable.m_bStep002 = pstStepOpt->m_bStep002;
	m_stInspectStepEnable.m_bStep003 = pstStepOpt->m_bStep003;
	m_stInspectStepEnable.m_bStep004 = pstStepOpt->m_bStep004;
	m_stInspectStepEnable.m_bStep005 = pstStepOpt->m_bStep005;
	m_stInspectStepEnable.m_bStep006 = pstStepOpt->m_bStep006;
	m_stInspectStepEnable.m_bStep007 = pstStepOpt->m_bStep001;
}

void CInspectionCamera::MergeSize(CSampleSide& sample)
{
	cv::Mat zeroImg = cv::Mat::zeros(cv::Size(100, 100), CV_8UC3); // 빈 이미지를 사용
	m_pCalcSize->CalcDistance(sample, zeroImg);
}
