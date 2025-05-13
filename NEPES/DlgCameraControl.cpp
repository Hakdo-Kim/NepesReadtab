// DlgCameraControl.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "DlgCameraControl.h"
#include "afxdialogex.h"

#include "CaptureManager.h"
#include "Util/Util.h"

#include "stringres.h"


// CDlgCameraControl dialog

IMPLEMENT_DYNAMIC(CDlgCameraControl, CDialogEx)

CDlgCameraControl::CDlgCameraControl(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgCameraControl::IDD, pParent)
{
	m_bResearchCamera = FALSE;
}

CDlgCameraControl::~CDlgCameraControl()
{
}

void CDlgCameraControl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_CAMERALIST, m_CameraTree);
	DDX_Control(pDX, IDC_STATIC_CAMERANAME, m_ctlStaticCamera);
}

BOOL CDlgCameraControl::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (IDOK == wParam)
	{
		this->ClearInformation();
	}
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CDlgCameraControl::PreTranslateMessage(MSG* pMsg)
{
	if (WM_KEYDOWN == pMsg->message)
	{
		if (VK_ESCAPE == pMsg->wParam)
		{
			this->ClearInformation();
		}
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

BOOL CDlgCameraControl::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_bResearchCamera = FALSE;

	// Title
	m_ctlStaticCamera.SetText(STR_CAMERA_SELECTCAMERA);

	CRect rtCtrl;
	GetDlgItem(IDC_STATIC_CTRL)->GetWindowRect(&rtCtrl);
	ScreenToClient(&rtCtrl);

	CRect rtDlg;
	m_TapCameraCtrl.Create(CTapCameraCtrl::IDD, this);
	m_TapCameraCtrl.GetWindowRect(&rtDlg);
	m_TapCameraCtrl.SetMaxScrollHeight(rtDlg.Height()+20);

	m_TapCameraCtrl.MoveWindow(&rtCtrl);
	m_TapCameraCtrl.SetScrollRange(SB_VERT, 0, rtDlg.Width());
	m_TapCameraCtrl.ShowWindow(SW_SHOW);


	//
	FillCameraInterface();

	UpdateCameraTreeGigE();

	return TRUE;
}

BEGIN_MESSAGE_MAP(CDlgCameraControl, CDialogEx)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_CAMERALIST, &CDlgCameraControl::OnTvnSelchangedTreeCameralist)
	ON_BN_CLICKED(IDC_BTN_REFRESH, &CDlgCameraControl::OnBnClickedBtnRefresh)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CDlgCameraControl message handlers


void CDlgCameraControl::OnTvnSelchangedTreeCameralist(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	*pResult = 0;

	//
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	HTREEITEM hTreeItem = m_CameraTree.GetSelectedItem();
	if (NULL == hTreeItem)
		return;
	const INFO_TREELEVEL* pstTree = GetSelectedTreeItem();
	if (NULL == pstTree)
		return;

	const TYPE_TREELEVEL eTreeLevel = pstTree->m_eTreeLevel;

	BOOL bConnect = FALSE;

	if (TYPE_TREELEVEL_GIGE_IF == eTreeLevel)
	{
		bConnect = pCaptureManager->IsEnableConnection(TYPE_NETWORK_GIGE);
		m_TapCameraCtrl.UpdateInformation(NULL);

		m_ctlStaticCamera.SetText(STR_CAMERA_SELECTCAMERA);
	}
	else if (TYPE_TREELEVEL_USB_IF == eTreeLevel)
	{
		bConnect = pCaptureManager->IsEnableConnection(TYPE_NETWORK_USB);
		m_TapCameraCtrl.UpdateInformation(NULL);

		m_ctlStaticCamera.SetText(STR_CAMERA_SELECTCAMERA);
	}

	else if (TYPE_TREELEVEL_OTHER_BASLER_GIGE_IF == eTreeLevel)
	{
		bConnect = pCaptureManager->IsEnableConnection(TYPE_NETWORK_BASLER);
		m_TapCameraCtrl.UpdateInformation(NULL);

		m_ctlStaticCamera.SetText(STR_CAMERA_SELECTCAMERA);
	}

	else
	{
		if (TYPE_TREELEVEL_ROOT == eTreeLevel)
		{
			m_TapCameraCtrl.UpdateInformation(NULL);
		}
		else if (TYPE_TREELEVEL_GIGE_CAMERA == eTreeLevel || TYPE_TREELEVEL_USB_CAMERA == eTreeLevel || TYPE_TREELEVEL_OTHER_BASLER_GIGE == eTreeLevel)
		{
			const int nProcessID = pCaptureManager->GetProcessId(pstTree->m_pstDevice);
			if (0 > nProcessID)
			{
				if (m_TapCameraCtrl.m_hWnd)
					m_TapCameraCtrl.UpdateInformation(NULL, NULL);
				m_ctlStaticCamera.SetText(STR_CAMERA_SELECTCAMERA);
				return;
			}

			INFO_DEFDEV stDefDev;
			memset(&stDefDev, 0x00, sizeof(INFO_DEFDEV));

			if (TYPE_TREELEVEL_GIGE_CAMERA == eTreeLevel)
			{
				const INFO_CONNECT_GIGE* pstGigE = (INFO_CONNECT_GIGE*)pstTree->m_pstDevice;

				stDefDev.m_eNetwork = TYPE_NETWORK_GIGE;
				CUtil::StringCopy(stDefDev.m_szName, (TCHAR*)pstGigE->m_szName);
			}
			else if (TYPE_TREELEVEL_USB_CAMERA == eTreeLevel)
			{
				const INFO_CONNECT_USB* pstUsb = (INFO_CONNECT_USB*)pstTree->m_pstDevice;

				stDefDev.m_eNetwork = TYPE_NETWORK_USB;
				CUtil::StringCopy(stDefDev.m_szName, (TCHAR*)pstUsb->m_szName);
			}
			else if (TYPE_TREELEVEL_OTHER_BASLER_GIGE == eTreeLevel)
			{
				const INFO_CONNECT_OTHER_MANUFACTURER* pstBasler = (INFO_CONNECT_OTHER_MANUFACTURER*)pstTree->m_pstDevice;

				stDefDev.m_eNetwork = TYPE_NETWORK_BASLER;
				CUtil::StringCopy(stDefDev.m_szName, (TCHAR*)pstBasler->m_szName);
			}

			else
			{
				m_TapCameraCtrl.UpdateInformation(NULL);
				m_ctlStaticCamera.SetText(STR_CAMERA_SELECTCAMERA);
				return;
			}

			BOOL bResult = pCaptureManager->GetCurrentDeviceInfo(stDefDev.m_eNetwork, stDefDev.m_szName, &stDefDev, FALSE);
			if (bResult)
			{
				m_TapCameraCtrl.UpdateInformation(&stDefDev, nProcessID);
				m_ctlStaticCamera.SetText(stDefDev.m_szName);
			}
			else
			{
				m_TapCameraCtrl.UpdateInformation(NULL);
				m_ctlStaticCamera.SetText(STR_CAMERA_SELECTCAMERA);
			}
		}
		else
		{
			m_TapCameraCtrl.UpdateInformation(NULL);
			m_ctlStaticCamera.SetText(STR_CAMERA_SELECTCAMERA);
		}
	}
}

void CDlgCameraControl::OnBnClickedBtnRefresh()
{
	m_bResearchCamera = TRUE;
	this->SendMessage(WM_CLOSE);
}


void CDlgCameraControl::UpdateInformation()
{
	UpdateCameraTreeGigE();
}

void CDlgCameraControl::ClearInformation()
{
	ClearTree();
}

void CDlgCameraControl::UpdateCameraInfo()
{
	LRESULT result;
	OnTvnSelchangedTreeCameralist(NULL, &result);
}

void CDlgCameraControl::EnableCameraInfo(BOOL bEnable)
{
	if (bEnable)
		UpdateCameraInfo();
	else
		m_TapCameraCtrl.UpdateInformation(NULL);
}

const INFO_TREELEVEL* CDlgCameraControl::GetSelectedTreeItem()
{
	HTREEITEM hTreeItem = m_CameraTree.GetSelectedItem();

	CString strItemName = m_CameraTree.GetItemText(hTreeItem).GetBuffer();

	INFO_TREELEVEL* pstTreeLevel = NULL;
	if (hTreeItem)
		pstTreeLevel = (INFO_TREELEVEL*)m_CameraTree.GetItemData(hTreeItem);

	return pstTreeLevel;
}

void CDlgCameraControl::FillCameraInterface()
{
	INFO_TREELEVEL* pstTreeLevel;
	int nIdx = 0;

	HTREEITEM hRoot = m_CameraTree.InsertItem(STR_CAMERALIST, 0, 0);
	m_CameraTree.SetItemState(hRoot, TVIS_BOLD, TVIS_BOLD);
	pstTreeLevel = new INFO_TREELEVEL(TYPE_TREELEVEL_ROOT);
	m_CameraTree.SetItemData(hRoot, (DWORD_PTR)pstTreeLevel);


	HTREEITEM hGigE = m_CameraTree.InsertItem(STR_CAMERAINF_GIGE, 0, 0, hRoot);
	pstTreeLevel = new INFO_TREELEVEL(TYPE_TREELEVEL_GIGE_IF, nIdx);		nIdx++;
	m_CameraTree.SetItemData(hGigE, (DWORD_PTR)pstTreeLevel);

	m_CameraTree.Expand(hRoot, TVE_EXPAND);
	m_CameraTree.Expand(hGigE, TVE_EXPAND);
}

void CDlgCameraControl::ClearTree()
{
	ClearTreeItem(NULL);
}

HTREEITEM CDlgCameraControl::GetInterfaceTreeItem(const TYPE_TREELEVEL eTreeLevel)
{
	if (NULL == m_CameraTree.m_hWnd)
		return NULL;

	HTREEITEM hRoot = m_CameraTree.GetRootItem();

	HTREEITEM hChild = m_CameraTree.GetChildItem(hRoot);
	while (hChild)
	{
		const INFO_TREELEVEL* pstTreeLevel = (INFO_TREELEVEL*)m_CameraTree.GetItemData(hChild);

		if (!pstTreeLevel)
			return NULL;

		if (eTreeLevel == pstTreeLevel->m_eTreeLevel)
			break;

		hChild = m_CameraTree.GetNextItem(hChild, TVGN_NEXT);
	}

	return hChild;

}


void CDlgCameraControl::ClearTreeItem(HTREEITEM hTreeItem)
{
	if (NULL == hTreeItem)
	{
		hTreeItem = m_CameraTree.GetRootItem();
	}

	INFO_TREELEVEL* pstTreeLevel = (INFO_TREELEVEL*)m_CameraTree.GetItemData(hTreeItem);
	if (pstTreeLevel)
	{
		m_CameraTree.SetItemData(hTreeItem, NULL);

		if (pstTreeLevel->m_pstDevice)
			delete pstTreeLevel->m_pstDevice;
		delete pstTreeLevel;
	}

	HTREEITEM hChild = m_CameraTree.GetChildItem(hTreeItem);
	while (hChild)
	{
		ClearTreeItem(hChild);
		hChild = m_CameraTree.GetNextItem(hChild, TVGN_NEXT);
	}
}

void CDlgCameraControl::UpdateCameraTreeGigE()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	HTREEITEM hGigE = GetInterfaceTreeItem(TYPE_TREELEVEL_GIGE_IF);
	if (NULL == hGigE)
		return;
	RemoveInterfaceTree(hGigE);

	const TYPE_NETWORK eNetwork = TYPE_NETWORK_GIGE;

	const BOOL bEnable = pCaptureManager->IsEnableConnection(eNetwork);

	if (bEnable)
	{
		INFO_CONNECT_GIGE* pstGigE = NULL;
		BOOL bResult = FALSE;

		const int nCount = pCaptureManager->GetConnectedDeviceCount(eNetwork);
		for (int i = 0; i<nCount; i++)
		{
			pstGigE = new INFO_CONNECT_GIGE;
			memset(pstGigE, 0x00, sizeof(INFO_CONNECT_GIGE));
			pstGigE->m_stArg.m_eNetwork = TYPE_NETWORK_GIGE;

			bResult = pCaptureManager->GetConnectedDeviceInfo(eNetwork, i, (INFO_CONNECT_DEV*)pstGigE);
			if (bResult)
			{
				bResult = InsertGigETree(hGigE, pstGigE);
			}

			if (FALSE == bResult)
			{
				delete pstGigE;
			}
		}
	}
	//else
	//{
	//	RemoveInterfaceTree(hGigE);
	//}

	m_CameraTree.Expand(hGigE, TVE_EXPAND);
}

void CDlgCameraControl::UpdateCameraTreeUsb()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	HTREEITEM hUsb = GetInterfaceTreeItem(TYPE_TREELEVEL_USB_IF);
	if (NULL == hUsb)
		return;
	RemoveInterfaceTree(hUsb);

	const TYPE_NETWORK eNetwork = TYPE_NETWORK_USB;

	const BOOL bEnable = pCaptureManager->IsEnableConnection(eNetwork);
	if (bEnable)
	{
		INFO_CONNECT_USB* pstUsb = NULL;

		BOOL bResult = FALSE;

		const int nCount = pCaptureManager->GetConnectedDeviceCount(eNetwork);
		for (int i = 0; i<nCount; i++)
		{
			pstUsb = new INFO_CONNECT_USB;
			memset(pstUsb, 0x00, sizeof(INFO_CONNECT_USB));
			pstUsb->m_stArg.m_eNetwork = TYPE_NETWORK_USB;

			bResult = pCaptureManager->GetConnectedDeviceInfo(eNetwork, i, (INFO_CONNECT_DEV*)pstUsb);
			if (bResult)
			{
				bResult = InsertUsbTree(hUsb, pstUsb);
			}

			if (FALSE == bResult)
			{
				delete pstUsb;
			}
		}
	}
	//else
	//{
	//	RemoveInterfaceTree(hUsb);
	//}

	m_CameraTree.Expand(hUsb, TVE_EXPAND);
}

void CDlgCameraControl::UpdateCameraTreeBasler()
{
	CCaptureManager* pCaptureManager = CCaptureManager::GetInstance();

	HTREEITEM hBasler = GetInterfaceTreeItem(TYPE_TREELEVEL_OTHER_BASLER_GIGE_IF);
	if (NULL == hBasler)
		return;
	RemoveInterfaceTree(hBasler);

	const TYPE_NETWORK eNetwork = TYPE_NETWORK_BASLER;

	const BOOL bEnable = pCaptureManager->IsEnableConnection(eNetwork);

	if (bEnable)
	{
		INFO_CONNECT_OTHER_MANUFACTURER* pstBasler = NULL;
		BOOL bResult = FALSE;

		const int nCount = pCaptureManager->GetConnectedDeviceCount(eNetwork);
		for (int i = 0; i<nCount; i++)
		{
			pstBasler = new INFO_CONNECT_OTHER_MANUFACTURER;
			memset(pstBasler, 0x00, sizeof(INFO_CONNECT_OTHER_MANUFACTURER));
			pstBasler->m_stArg.m_eNetwork = TYPE_NETWORK_BASLER;

			bResult = pCaptureManager->GetConnectedDeviceInfo(eNetwork, i, (INFO_CONNECT_DEV*)pstBasler);
			if (bResult)
			{
				bResult = InsertBaslerTree(hBasler, pstBasler);
			}

			if (FALSE == bResult)
			{
				delete pstBasler;
			}
		}
	}
	//else
	//{
	//	RemoveInterfaceTree(hGigE);
	//}

	m_CameraTree.Expand(hBasler, TVE_EXPAND);
}

BOOL CDlgCameraControl::InsertGigETree(HTREEITEM hGigETree, INFO_CONNECT_GIGE* pstGigE)
{
	if (NULL == hGigETree || NULL == pstGigE)
		return FALSE;

	BOOL bFind = FindDevice(hGigETree, (INFO_CONNECT_DEV*)pstGigE);
	if (FALSE == bFind)
	{
		const int nCount = GetChildItemCount(hGigETree);

		HTREEITEM hChild = m_CameraTree.InsertItem(pstGigE->m_stArg.m_szArg, 0, 0, hGigETree);

		INFO_TREELEVEL* pTreeLevel = new INFO_TREELEVEL(TYPE_TREELEVEL_GIGE_CAMERA, nCount, (INFO_CONNECT_DEV*)pstGigE);
		m_CameraTree.SetItemData(hChild, (DWORD_PTR)pTreeLevel);

	}
	else
	{
		return FALSE;
	}

	return TRUE;

}

BOOL CDlgCameraControl::InsertUsbTree(HTREEITEM hUsbTree, INFO_CONNECT_USB* pstUsb)
{
	if (NULL == hUsbTree || NULL == pstUsb)
		return FALSE;

	BOOL bFind = FindDevice(hUsbTree, (INFO_CONNECT_DEV*)pstUsb);
	if (FALSE == bFind)
	{
		const int nCount = GetChildItemCount(hUsbTree);

		TCHAR szName[MAX_PATH] = { 0, };
		_stprintf(szName, _T("%s"), pstUsb->m_stArg.m_szArg);

		HTREEITEM hChild = m_CameraTree.InsertItem(szName, 0, 0, hUsbTree);

		INFO_TREELEVEL* pTreeLevel = new INFO_TREELEVEL(TYPE_TREELEVEL_USB_CAMERA, nCount, (INFO_CONNECT_DEV*)pstUsb);
		m_CameraTree.SetItemData(hChild, (DWORD_PTR)pTreeLevel);

	}
	else
	{
		return FALSE;
	}

	return TRUE;
}

BOOL CDlgCameraControl::InsertBaslerTree(HTREEITEM hBaslerTree, INFO_CONNECT_OTHER_MANUFACTURER* pstBasler)
{
	if (NULL == hBaslerTree || NULL == pstBasler)
		return FALSE;

	BOOL bFind = FindDevice(hBaslerTree, (INFO_CONNECT_DEV*)pstBasler);
	if (FALSE == bFind)
	{
		const int nCount = GetChildItemCount(hBaslerTree);

		HTREEITEM hChild = m_CameraTree.InsertItem(pstBasler->m_stArg.m_szArg, 0, 0, hBaslerTree);

		INFO_TREELEVEL* pTreeLevel = new INFO_TREELEVEL(TYPE_TREELEVEL_OTHER_BASLER_GIGE, nCount, (INFO_CONNECT_DEV*)pstBasler);
		m_CameraTree.SetItemData(hChild, (DWORD_PTR)pTreeLevel);

	}
	else
	{
		return FALSE;
	}

	return TRUE;

}

void CDlgCameraControl::RemoveGigETree(HTREEITEM hGigETree, INFO_CONNECT_GIGE* pstGigE)
{
	if (NULL == hGigETree || NULL == pstGigE)
		return;

	INFO_TREELEVEL* pstTreeLevel = NULL;

	HTREEITEM hChild = m_CameraTree.GetChildItem(hGigETree);
	while (hChild)
	{
		pstTreeLevel = (INFO_TREELEVEL*)m_CameraTree.GetItemData(hChild);
		if (pstTreeLevel &&
			0 == _tcscmp(pstTreeLevel->m_pstDevice->m_szArg, pstGigE->m_szName))
		{
			m_CameraTree.DeleteItem(hChild);

			if (pstTreeLevel)
			{
				if (pstTreeLevel->m_pstDevice)
					delete pstTreeLevel->m_pstDevice;

				delete pstTreeLevel;
			}

			break;
		}

		hChild = m_CameraTree.GetNextItem(hChild, TVGN_NEXT);
	}
}

void CDlgCameraControl::RemoveUsbTree(HTREEITEM hUsbTree, INFO_CONNECT_USB* pstUsb)
{
	if (NULL == hUsbTree || NULL == pstUsb)
		return;

	INFO_TREELEVEL* pstTreeLevel = NULL;

	HTREEITEM hChild = m_CameraTree.GetChildItem(hUsbTree);
	while (hChild)
	{
		pstTreeLevel = (INFO_TREELEVEL*)m_CameraTree.GetItemData(hChild);
		if (pstTreeLevel &&
			0 == _tcscmp(pstTreeLevel->m_pstDevice->m_szArg, pstUsb->m_szName))
		{
			m_CameraTree.DeleteItem(hChild);

			if (pstTreeLevel)
			{
				if (pstTreeLevel->m_pstDevice)
					delete pstTreeLevel->m_pstDevice;

				delete pstTreeLevel;
			}
			break;
		}

		hChild = m_CameraTree.GetNextItem(hChild, TVGN_NEXT);
	}

}

void CDlgCameraControl::RemoveBaslerTree(HTREEITEM hBaslerTree, INFO_CONNECT_OTHER_MANUFACTURER* pstBasler)
{
	if (NULL == hBaslerTree || NULL == pstBasler)
		return;

	INFO_TREELEVEL* pstTreeLevel = NULL;

	HTREEITEM hChild = m_CameraTree.GetChildItem(hBaslerTree);
	while (hChild)
	{
		pstTreeLevel = (INFO_TREELEVEL*)m_CameraTree.GetItemData(hChild);
		if (pstTreeLevel &&
			0 == _tcscmp(pstTreeLevel->m_pstDevice->m_szArg, pstBasler->m_szName))
		{
			m_CameraTree.DeleteItem(hChild);

			if (pstTreeLevel)
			{
				if (pstTreeLevel->m_pstDevice)
					delete pstTreeLevel->m_pstDevice;

				delete pstTreeLevel;
			}

			break;
		}

		hChild = m_CameraTree.GetNextItem(hChild, TVGN_NEXT);
	}
}

void CDlgCameraControl::RemoveInterfaceTree(HTREEITEM hInterfaceTree)
{
	if (NULL == hInterfaceTree)
		return;

	HTREEITEM hDeleteChild = NULL;

	HTREEITEM hChild = m_CameraTree.GetChildItem(hInterfaceTree);
	while (hChild)
	{
		ClearTreeItem(hChild);

		hDeleteChild = hChild;

		hChild = m_CameraTree.GetNextItem(hChild, TVGN_NEXT);


		m_CameraTree.DeleteItem(hDeleteChild);
	}


}

BOOL CDlgCameraControl::FindDevice(HTREEITEM hTree, const INFO_CONNECT_DEV* pstDevice)
{
	if (NULL == hTree || NULL == pstDevice)
		return FALSE;

	INFO_TREELEVEL* pTreeLevl = SearchChild(hTree, pstDevice);
	if (NULL == pTreeLevl)
		return FALSE;

	return TRUE;

}

INFO_TREELEVEL* CDlgCameraControl::SearchChild(HTREEITEM hTree, const INFO_CONNECT_DEV* pDev)
{
	if (NULL == hTree || NULL == pDev)
		return NULL;

	BOOL bFind = FALSE;

	HTREEITEM hChild = m_CameraTree.GetChildItem(hTree);
	while (hChild)
	{
		const INFO_TREELEVEL* pstTreeLevel = (INFO_TREELEVEL*)m_CameraTree.GetItemData(hChild);

		if (pstTreeLevel &&
			pstTreeLevel->m_pstDevice->m_eNetwork == pDev->m_eNetwork &&
			pstTreeLevel->m_pstDevice->m_dwArg == pDev->m_dwArg &&
			0 == _tcscmp((LPTSTR)pstTreeLevel->m_pstDevice->m_szArg, (LPTSTR)pDev->m_szArg))
		{
			bFind = TRUE;
			break;
		}

		hChild = m_CameraTree.GetNextItem(hChild, TVGN_NEXT);
	}

	if (!bFind || !hChild)
	{
		return NULL;
	}

	return (INFO_TREELEVEL*)m_CameraTree.GetItemData(hChild);

}

const int CDlgCameraControl::GetChildItemCount(HTREEITEM hTree)
{
	if (NULL == hTree)
		return -1;

	int nCount = 0;

	HTREEITEM hChild = m_CameraTree.GetChildItem(hTree);
	while (hChild)
	{
		nCount++;
		hChild = m_CameraTree.GetNextItem(hChild, TVGN_NEXT);
	}

	return nCount;
}

const TYPE_TREELEVEL CDlgCameraControl::GetSelectedTreeLevel()
{
	HTREEITEM hTreeItem = m_CameraTree.GetSelectedItem();
	if (NULL == hTreeItem)
		return TYPE_TREELEVEL_NONE;

	TYPE_TREELEVEL eTreeLevel = TYPE_TREELEVEL_NONE;

	INFO_TREELEVEL* pstTreeLevel = (INFO_TREELEVEL*)m_CameraTree.GetItemData(hTreeItem);
	if (pstTreeLevel)
		eTreeLevel = pstTreeLevel->m_eTreeLevel;

	return eTreeLevel;

}

void CDlgCameraControl::OnClose()
{
	this->ClearInformation();
	CDialogEx::OnClose();
}
