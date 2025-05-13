#pragma once
#include "afxwin.h"
#include "CommonCapture.h"
#include "NumberEdit.h"
#include "Proc\ProcessDef.h"
#include "Inspection/Sample.h"
// Version 1.3.7.8
#include <memory> 

// CDlgSizeGain dialog

class CDlgSizeGain : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgSizeGain)

public:
	CDlgSizeGain(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgSizeGain();

// Dialog Data
	enum { IDD = IDD_DLG_SIZEGAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	double m_dd;
	double m_dL;
	double m_dW;
	double m_dI1;
	double m_dI2;
	double m_dI3;
	double m_dM1;
	double m_dM2;
	double m_dS1;
	double m_dS2;
	double m_dS3;
	double m_dS4;
	double m_dS5;
	double m_dX1;
	double m_dX2;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	double m_dR1;
	double m_dR2;
	double m_dR3;
	double m_dR4;
	double m_dR5;
	double m_dR6;
	double m_dSS1;
	double m_dSS2;
	double m_dSS3;


	CNumberEdit m_Editd;
	CNumberEdit m_EditL;
	CNumberEdit m_EditW;
	CNumberEdit m_EditI1;
	CNumberEdit m_EditI2;
	CNumberEdit m_EditI3;
	CNumberEdit m_EditM1;
	CNumberEdit m_EditM2;
	CNumberEdit m_EditS1;
	CNumberEdit m_EditS2;
	CNumberEdit m_EditS3;
	CNumberEdit m_EditS4;
	CNumberEdit m_EditS5;
	CNumberEdit m_EditX1;
	CNumberEdit m_EditX2;
	// Version 1.3.7.5 R1 ~ R6, SS1 ~ SS3
	CNumberEdit m_EditR1;
	CNumberEdit m_EditR2;
	CNumberEdit m_EditR3;
	CNumberEdit m_EditR4;
	CNumberEdit m_EditR5;
	CNumberEdit m_EditR6;
	CNumberEdit m_EditSS1;
	CNumberEdit m_EditSS2;
	CNumberEdit m_EditSS3;


	INFO_SIZE_GAIN m_stInfoSizeGain;

	// Version 1.3.7.1
	INFO_IMAGE* m_tempImage;
	// Version 1.3.7.8
	INFO_IMAGE* m_tempImageFirst;
	INFO_IMAGE* m_tempImageSecond;
	cv::Mat m_CaptureImage[2];
	std::unique_ptr<CSampleSide> m_Sample;
	//
	//void UpdateImage(INFO_IMAGE* Image, cv::Mat captureimage[2]);
	//void UpdateImage(INFO_IMAGE* image, INFO_IMAGE* image1, INFO_IMAGE* image2);
	void UpdateResult(const CSampleSide* sample);

	void CDlgSizeGain::MinMaxCheck(double min, double max, double value, BOOL errorCheck);

	afx_msg void OnBnClickedOk();

	void SetInfoSizeGain(const INFO_SIZE_GAIN *stInfoSizeGain);

	TYPE_CAMERAPOS m_eCameraPos;
	void UpdateCameraPos(TYPE_CAMERAPOS ePos);
	void Log(char* pszLog, ...);
	virtual BOOL OnInitDialog();
	afx_msg void OnBnApplyClick();
};
