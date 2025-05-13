#pragma once

#include "CommonCapture.h"

typedef enum
{
	TYPE_LOAD_NONE,

	TYPE_LOAD_CONNECTCAMERA,
	TYPE_LOAD_DISCONNECTCAMERA,

	TYPE_LOAD_RESEARCHCAMERA,

	TYPE_LOAD_TRIGGERMODE,

	TYPE_LOAD_INSPECTIONENV_READY,

	TYPE_LOAD_MAX,

} TYPE_LOAD;

#define FLAG_FIRST				0x01
#define FLAG_SECOND				0x02

#define FLAG_OPT_FIRST			0x01
#define FLAG_OPT_SECOND			0x02


// CDlgMessage dialog

class CDlgMessage : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgMessage)

public:
	CDlgMessage(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgMessage();

	void SetLoadType(TYPE_LOAD eType, DWORD dwPosFlag = 0, DWORD dwOptFlag = 0);


// Dialog Data
	enum { IDD = IDD_DLG_MESSAGE };
protected:
	TYPE_LOAD m_eLoadingType;
	DWORD m_dwPosFlag;
	DWORD m_dwOptFlag;

	const int TIMERID = 1;
	const int MSEC_TIMER = 200;

	HWND m_hTargetWnd;
public:
	HWND GetTargetWnd(){ return m_hTargetWnd; }
	void SetTargetWnd(HWND hTargetWnd) { m_hTargetWnd = hTargetWnd; }

	void UpdateCameraListFromReg();

	void UpdateTriggerMode();
	void UpdateTriggerMode(TYPE_CAMERAPOS ePos);
	
	BOOL GetLoadFlagTriggerMode(DWORD& dwPosFlag, DWORD& dwOptFlag);
	BOOL GetTriggerModeFromCamera(TYPE_CAMERAPOS ePos, DWORD& dwTriggerMode, DWORD& dwTriggerSrc);

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	DECLARE_MESSAGE_MAP()
	afx_msg void OnTimer(UINT_PTR nIDEvent);

};
