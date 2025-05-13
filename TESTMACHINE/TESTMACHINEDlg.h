
// TESTMACHINEDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include <queue>

#define DEF_RUN2STEP

#include "Ethernet/EthernetClient.h"
#include "Ethernet/EthernetServer.h"

typedef enum
{
	TYPE_POS_NONE,

	TYPE_POS_FIRST,
	TYPE_POS_SECOND,

	TYPE_POS_MAX,

} TYPE_POS;


typedef enum
{
	TYPE_SHAPE_NONE,

	TYPE_SHAPE_A,
	TYPE_SHAPE_B,

	TYPE_SHAPE_MAX,

} TYPE_SHAPE;

typedef struct
{
	BOOL m_bDoneInspect;
	BOOL m_bInspecting;

	BOOL m_bSize;
	BOOL m_bShape;

} INFO_SIDE;

typedef struct
{
	INFO_SIDE m_stFirst;
	INFO_SIDE m_stSecond;

	int m_nIndex;

	TYPE_SHAPE m_eShape;

} INFO_SAMPLE;


// CTESTMACHINEDlg dialog
class CTESTMACHINEDlg : public CDialogEx
{
// Construction
public:
	CTESTMACHINEDlg(CWnd* pParent = NULL);	// standard constructor
	static BOOL CALLBACK FuncNotifyEthernetListener(DWORD dwListener, void* pArg);

// Dialog Data
	enum { IDD = IDD_TESTMACHINE_DIALOG };
protected:
	TYPE_POS m_eCurPos;
	TYPE_SHAPE m_eCurShape;

	HICON m_hIcon;
	const int TIMERID_FIRST = 1;
	const int TIMERID_SECOND = 2;
#if 1
	const int MSEC_TIMER = 2000;
#else
	const int MSEC_TIMER = 20000;
#endif


	const int FIRSTCAMERA = 1;
	const int SECONDCAMERA = 2;


	int m_nCassetteCount;
	int m_nSampleACount;
	int m_nSampleBCount;

	/// Inspection Argument 
	BOOL m_bStart;
	int m_nInspectionCount;
	
	

	std::queue<INFO_SAMPLE*> m_FirstCameraQueue;
	std::queue<INFO_SAMPLE*> m_SecondCameraQueue;
	///
	
	CEthernet* m_pCommunicate;


	CIPAddressCtrl m_ctlIpAddress;
	CEdit m_ctlPort;
	CComboBox m_ctlProtocol;
	CComboBox m_ctlType;

	const BOOL IsStarted();
	void UpdateConnectState(BOOL bConnect);
	void UpdateStartState(BOOL bStart);

	void ClearQueue();

	BOOL InspectFirstCamera();
	void InspectSecondCamera();

	BOOL RunInspect(int nIdx);	// 0: First Camera, 1: Second Camera
	int ParseResultInspect(TCHAR* pszResponse);
	void ParseResultInspect(TCHAR* pszResponse, int& nIdxCamera, BOOL& bSize, BOOL& bShape, BOOL& bAlarm);

	void UpdateMessage(TCHAR* pszMessage);

	BOOL IsSkipSecondCamera();
	

	// Generated message map functions
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	virtual BOOL OnInitDialog();
	
	DECLARE_MESSAGE_MAP()
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnClose();
	
	afx_msg void OnBnClickedBtnConnect();
	afx_msg void OnBnClickedBtnDisconnect();
	afx_msg void OnBnClickedBtnStart();
	afx_msg void OnBnClickedBtnStop();


};
