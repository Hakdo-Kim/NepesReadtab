#pragma once

#include "UserInterfaceDef.h"
#include "TapCameraCtrl.h"
#include "ViewTree.h"
#include "StaticText.h"

#include "afxcmn.h"
#include "afxwin.h"


// CDlgCameraControl dialog

class CDlgCameraControl : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgCameraControl)

public:
	CDlgCameraControl(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgCameraControl();

	// Dialog Data
	enum { IDD = IDD_DLG_CAMERACTRL };

	BOOL m_bResearchCamera;

	// Function
	void UpdateInformation();
	void ClearInformation();

	void UpdateCameraInfo();
	void EnableCameraInfo(BOOL bEnable);

	// Function - Tree Ctrl
	const INFO_TREELEVEL* GetSelectedTreeItem();

protected:
	// Member
	CViewTree m_CameraTree;

	CStaticText m_ctlStaticCamera;
	CTapCameraCtrl m_TapCameraCtrl;


	// Member Function
	void FillCameraInterface();
	void ClearTree();

	HTREEITEM GetInterfaceTreeItem(const TYPE_TREELEVEL eTreeLevel);
	void ClearTreeItem(HTREEITEM hTreeItem = NULL);

	void UpdateCameraTreeGigE();
	void UpdateCameraTreeUsb();
	void UpdateCameraTreeBasler();

	BOOL InsertGigETree(HTREEITEM hGigETree, INFO_CONNECT_GIGE* pstGigE);
	BOOL InsertUsbTree(HTREEITEM hUsbTree, INFO_CONNECT_USB* pstUsb);
	BOOL InsertBaslerTree(HTREEITEM hBaslerTree, INFO_CONNECT_OTHER_MANUFACTURER* pstBasler);

	void RemoveGigETree(HTREEITEM hGigETree, INFO_CONNECT_GIGE* pstGigE);
	void RemoveUsbTree(HTREEITEM hUsbTree, INFO_CONNECT_USB* pstUsb);
	void RemoveBaslerTree(HTREEITEM hBaslerTree, INFO_CONNECT_OTHER_MANUFACTURER* pstBasler);

	void RemoveInterfaceTree(HTREEITEM hInterfaceTree);


	BOOL FindDevice(HTREEITEM hTree, const INFO_CONNECT_DEV* pstDevice);

	INFO_TREELEVEL* SearchChild(HTREEITEM hTree, const INFO_CONNECT_DEV* pDev);
	const int GetChildItemCount(HTREEITEM hTree);

	const TYPE_TREELEVEL GetSelectedTreeLevel();
	

	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnInitDialog();
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	DECLARE_MESSAGE_MAP()
	afx_msg void OnTvnSelchangedTreeCameralist(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedBtnRefresh();
	afx_msg void OnClose();

};
