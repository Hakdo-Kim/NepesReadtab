// DlgCamRoi.cpp : implementation file
//

#include "stdafx.h"
#include "NEPES.h"
#include "DlgCamRoi.h"
#include "afxdialogex.h"

#include "UserInterfaceDef.h"

// CDlgCamRoi dialog

IMPLEMENT_DYNAMIC(CDlgCamRoi, CDialogEx)

CDlgCamRoi::CDlgCamRoi(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlgCamRoi::IDD, pParent)
{

}

CDlgCamRoi::~CDlgCamRoi()
{
}

void CDlgCamRoi::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC_ROIVIEW, m_RoiView);
}

BOOL CDlgCamRoi::OnCommand(WPARAM wParam, LPARAM lParam)
{
	if (IDOK == wParam)
	{
		return TRUE;
	}
	return CDialogEx::OnCommand(wParam, lParam);
}

BOOL CDlgCamRoi::PreTranslateMessage(MSG* pMsg)
{
	if (WM_KEYDOWN == pMsg->message)
	{
		if (VK_ESCAPE == pMsg->wParam)
		{
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

BOOL CDlgCamRoi::OnInitDialog()
{
	CDialog::OnInitDialog();


	return TRUE;
}

BEGIN_MESSAGE_MAP(CDlgCamRoi, CDialogEx)
	ON_MESSAGE(WM_NOTIFY_TRACK_CHANGE_RECT, &CDlgCamRoi::OnNotifyChangeTrackRect)
	ON_WM_SIZE()
END_MESSAGE_MAP()


// CDlgCamRoi message handlers
LRESULT CDlgCamRoi::OnNotifyChangeTrackRect(WPARAM wParam, LPARAM lParam)
{
	this->GetParent()->SendMessage(WM_NOTIFY_TRACK_CHANGE_RECT, wParam, lParam);
	return S_OK;
}

void CDlgCamRoi::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);

	if (m_RoiView.m_hWnd)
	{
		CRect rectClient;
		this->GetClientRect(rectClient);

		int x = rectClient.left;
		int y = rectClient.top;
		int cx = rectClient.Width();
		int cy = rectClient.Height();

		m_RoiView.SetWindowPos(NULL, x, y, cx, cy, SWP_NOACTIVATE | SWP_NOZORDER);
	}
}

void CDlgCamRoi::UpdateInformation(const INFO_DEFROI* pDefROI)
{
	m_RoiView.UpdateInformation(pDefROI);
}

void CDlgCamRoi::SetRoi(const INFO_ROI_PARA* pstRoi)
{
	m_RoiView.SetRoi(pstRoi);
}

void CDlgCamRoi::SetRoiPosition(int x, int y, int w, int h)
{
	m_RoiView.SetRoiPosition(x, y, w, h);
}

void CDlgCamRoi::GetRoi(INFO_ROI_PARA* pstRoi)
{
	m_RoiView.GetRoi(pstRoi);
}

void CDlgCamRoi::CorrectRoi(INFO_ROI_PARA* pstRoi)
{
	m_RoiView.CorrectRoi(pstRoi);
}