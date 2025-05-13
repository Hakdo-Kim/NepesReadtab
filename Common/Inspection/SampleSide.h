#pragma once
#include "Proc/ProcessDef.h"
#include "NAVIApp.h"
#include <opencv2/core/core.hpp>

#include "CommonCapture.h"

using namespace std;
// 치수 측정 결과 구조체
typedef struct
{
	double m_dValue; // 측정 값
	bool m_bOK; // OK/NG
	bool m_bSpec;
} OUTPUT_DISTANCE;

// 상대 ROI 결과 구조체
typedef struct
{
	stPOINT m_pt[4];
} OUTPUT_ROI;

typedef struct
{
	//치수 측정 결과 (치수 값, OK/NG, 측정 위치 좌표)
	OUTPUT_DISTANCE m_stDistance[TYPE_GEOMETRY_DISTANCE_MAX];
	stLine m_stDistanceLine[MAX_GEOMETRY_DISTANCELINE_COUNT];
	
	// Calibration 결과 이미지
	stAPPIMAGEDATA m_stCalibratedImage;

	// FindLine 결과 Line
	stLine m_stResultLine[TYPE_FINDLINE_MAX];
	// 측정 기준 Point
	stPOINT m_stResultPoint[TYPE_GEOMETRY_POINT_MAX];

	// 상대 ROI 결과
	OUTPUT_ROI m_stROIPoint[TYPE_FINDLINE_MAX];

	// 라인찾기 결과. sizecalc때문에 맴버변수로 편입
	bool m_bFindLineResult[TYPE_FINDLINE_MAX];
} OUTPUT_SIZE;

typedef struct
{
	cv::Mat m_pInputImage;
	cv::Mat m_pProbImage;
	vector<float> m_fMaxDefectSize;
	bool m_bResult;
} OUTPUT_STAIN;

typedef struct
{
	cv::Mat m_pInputImage;
	cv::Mat m_pProbImage;
	vector<float> m_fMaxDefectSize;
	bool m_bResult;
} OUTPUT_DIFFER;

typedef struct
{
	cv::Mat m_pInputImage;
	cv::Mat m_pProbImage;
	vector<float> m_fMaxDefectSize;
	bool m_bResult;
} OUTPUT_BUBBLE;

typedef struct
{
	cv::Mat m_pInputImage;
	cv::Mat m_pProbImage;
	vector<float> m_fMaxDefectSize;
	bool m_bResult;
} OUTPUT_SCRATCH;

typedef struct
{
	cv::Mat m_pInputImage;
	cv::Mat m_pProbImage;
	vector<float> m_fMaxDefectSize;
	bool m_bResult;
} OUTPUT_STAMP;

class CSampleSide
{
public:
	CSampleSide();
	virtual ~CSampleSide();

	INFO_IMAGE* m_pRefImage;

	// Result Infomation. (Todo)
	OUTPUT_SIZE m_SizeResult;
	OUTPUT_STAIN m_StainResult;
	OUTPUT_DIFFER m_DifferResult;
	OUTPUT_BUBBLE m_BubbleResult;
	OUTPUT_SCRATCH m_ScratchResult;
	OUTPUT_STAMP m_StampResult;
	OUTPUT_SIZE m_SizeSecondResult;
	OUTPUT_SIZE m_SizeCalculationResult;
	

	// Size Option
	INFO_OPT_RANGE m_pstRefOptRangeList[MAX_SIZE_MEASURECOUNT];
	INFO_OPT_RANGE m_pstRefOptRangeSpecList[MAX_SIZE_MEASURECOUNT];
	const int m_nRangeCount = MAX_SIZE_MEASURECOUNT;
	void CopyFrom(const CSampleSide& rhs);
};