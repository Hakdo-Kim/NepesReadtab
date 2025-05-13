/**
* @file StepSize.cpp
* @brief StepSizeCalculation 클래스 선언 파일
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

class CStepSizeCalculation
{
public:
	CStepSizeCalculation();
	virtual ~CStepSizeCalculation();

	virtual BOOL Init(TYPE_CAMERAPOS eCameraPos, INFO_LOGFUNC stLogFunc);
	virtual void Deinit();

	virtual BOOL Load(INFO_INSPECTION* pstInspection);

	virtual BOOL Get(INFO_INSPECTION* pstInspection);
	virtual BOOL Set(const INFO_INSPECTION* pstInspection);


	const INFO_INSPECTION_SIZE_CALC* GetInformation();
	BOOL SetInformation(const INFO_INSPECTION_SIZE_CALC* pInfoSize);
	BOOL SetCalibration(const INFO_CALIBRATION* pstInfoCalibration = NULL);
	BOOL SetSizeGain(const INFO_SIZE_GAIN* pstInfoSizeGain);

	int GetCalibrationResult() { return m_iCalInit; }

	//사이즈 계산
	void CalcDistance(CSampleSide& sample, cv::Mat captureImg);
	void CalcDistanceCompareValues(cv::Mat captureImg, CSampleSide& sample);
	void CalcDistanceCompareValues(CSampleSide& sample);
	void CalcDistanceSPoint(CSampleSide& sample);
	void CalcDistanceRpoint(CSampleSide& sample);
	void MultiplyGain(CSampleSide& sample);
	void DecideResult(CSampleSide& sample);

	virtual void Log(char* pszLog, ...);

	BOOL IsInit();
	OUTPUT_DISTANCE *stDistance;
protected:
	BOOL m_bInit;

	TYPE_CAMERAPOS m_eCameraPos;
	INFO_LOGFUNC m_stLogFunc;

	std::string m_strStepName;

	const float S1_MARGIN = 5.0f;
	const float S3_MARGIN = S1_MARGIN;

	INFO_INSPECTION_SIZE_CALC m_stInfoCalc;
	int m_iCalInit;

	OUTPUT_ROI m_stCurruntROIPoint[TYPE_FINDLINE_MAX]; // 마지막 Process의 상대 ROI 위치

	// Calibration App
	CLPApp *m_pCalibrationApp;

#ifdef USE_BASLER_CAMERA
	cv::Mat m_GrayMat;
#endif

	// FindLine App (2 Samples)
	CLPApp *m_pFindLineApp[TYPE_FINDLINE_MAX];

	// Geometry App
	CLPApp *m_pGeometryApp;

	void PreProcess(cv::Mat captureImg);

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
	BOOL S4Distance(LP_VisionApp::stAPPIMAGEDATA *img, const stLine &metalLine, const stPOINT &tapePt1, const stPOINT &tapePt2,
		double &s4Distance, stLine &s4DistanceLine);
	BOOL S5Distance(LP_VisionApp::stAPPIMAGEDATA *img, const stLine &metalLine, const stPOINT &tapePt1, const stPOINT &tapePt2,
		double &s5Distance, stLine &s5DistanceLine);

	void GetDefaultCalcSetting(INFO_INSPECTION_SIZE_CALC *info);
};