/**
* @file StepSize.cpp
* @brief StepSizeSecond 클래스 선언 파일
* @author Junmock Lee  * @Modified Jongik
* @date 2017-07-25     * @date 2020-07-13
*/

#pragma once
#include "Step.h"
#include "NAVIApp.h"
#include "hasp_api_cpp.h"
#include "opencv2/core/core.hpp"

#define MAX_FINDLINE_STRING_SIZE 64
#define FINDLINE_METAL_COUNT (TYPE_FINDLINE_METAL_LEFT - TYPE_FINDLINE_METAL_TOP + 1)

// 치수 검사

class CStepSizeSecond : public CStep
{
public:
	CStepSizeSecond();
	virtual ~CStepSizeSecond();

	virtual BOOL Init(TYPE_CAMERAPOS eCameraPos, INFO_LOGFUNC stLogFunc);
	virtual void Deinit();
	virtual BOOL Process(CSampleSide& sample);
	virtual BOOL Process(CSampleSide& sample, cv::Mat captureImg);

	virtual BOOL Load(INFO_INSPECTION* pstInspection);

	virtual BOOL Get(INFO_INSPECTION* pstInspection);
	virtual BOOL Set(const INFO_INSPECTION* pstInspection);


	const INFO_INSPECTION_SIZE* GetInformation();
	BOOL SetInformation(const INFO_INSPECTION_SIZE* pInfoSize);
	BOOL SetInfoFindLineROI(const INFO_FINDLINE_ROI* pInfoLine, const INFO_IMAGE* pRefImage, const int iIndex);
	BOOL SetInfoFindLineParameter(const INFO_FINDLINE_PARAMETER* pInfoLine, const int iIndex);
	BOOL SetCalibration(const INFO_CALIBRATION* pstInfoCalibration = NULL);
	BOOL SetSizeGain(const INFO_SIZE_GAIN* pstInfoSizeGain);

	int GetCalibrationResult() { return m_iCalInit; }
	OUTPUT_ROI *GetCurruntROIPoint() { return m_stCurruntROIPoint; }

protected:
	static const int m_iDefaultDirection[TYPE_FINDLINE_MAX];
	static const int m_iDefaultPolarity[TYPE_FINDLINE_MAX];
	static const int m_iDefaultLookFor[TYPE_FINDLINE_MAX];
	static const int m_iDefaultStrengthThreshold[TYPE_FINDLINE_MAX];
	static const int m_iDefaultSampling[TYPE_FINDLINE_MAX];
	static const int m_iDefaultKernelSize[TYPE_FINDLINE_MAX];

	const float S1_MARGIN = 5.0f;
	const float S3_MARGIN = S1_MARGIN;

	INFO_INSPECTION_SIZE m_stInfoSize;

	int m_iCalInit;
	OUTPUT_ROI m_stCurruntROIPoint[TYPE_FINDLINE_MAX]; // 마지막 Process의 상대 ROI 위치

	// Calibration App
	CLPApp *m_pCalibrationApp;

#ifdef USE_BASLER_CAMERA
	cv::Mat m_OutputImage;
	cv::Mat m_GrayMat;
#endif

	// FindLine App (2 Samples)
	CLPApp *m_pFindLineApp[TYPE_FINDLINE_MAX];

	// Geometry App
	CLPApp *m_pGeometryApp;

	BOOL SetFindLineAppParameter(CLPApp *app, const INFO_FINDLINE_PARAMETER info);
	BOOL SetFindLineAppROI(CLPApp *app, const INFO_FINDLINE_ROI *info, const bool enableRefROI = false, const stPOINT refPt = { 0, 0 }, const double refAngle = 0);

	BOOL LineIntersection(LP_VisionApp::stAPPIMAGEDATA *img, const stLine &line1, const stLine &line2, stPOINT &ptOut);
	BOOL MidPoint(LP_VisionApp::stAPPIMAGEDATA *img, const stPOINT &pt1, const stPOINT &pt2, stPOINT &ptOut);
	BOOL LinetoLineDistance(LP_VisionApp::stAPPIMAGEDATA *img, const stLine &line1, const stLine &line2, double &distance, stLine &distanceLine);
	BOOL PointtoPointDistance(LP_VisionApp::stAPPIMAGEDATA *img, const stPOINT &pt1, const stPOINT &pt2, double &distance, stLine &distanceLine);
	BOOL PointtoLineDistance(LP_VisionApp::stAPPIMAGEDATA *img, const stLine &line, const stPOINT &pt, double &distance, stLine &distanceLine);

	BOOL S1Distance(LP_VisionApp::stAPPIMAGEDATA *img, const stLine &metalLine, const stLine &tapeLineS1, const double metalLineDistance,
		double &s1Distance, stLine &s1DistanceLine);
	BOOL S2Distance(LP_VisionApp::stAPPIMAGEDATA *img, const stLine &metalLine, const stLine &tapeLineS2, const double metalLineDistance,
		double &s2Distance, stLine &s2DistanceLine);
	BOOL S3Distance(LP_VisionApp::stAPPIMAGEDATA *img, const stLine &metalLine, const stLine &tapeLineS3, const double metalLineDistance,
		double &s3Distance, stLine &s3DistanceLine);

	void GetDefaultSizeSetting(INFO_INSPECTION_SIZE *info);

	Chasp hasp;
	bool DongleLogin();
	bool DongleCheck();
	void DongleLogout();
};