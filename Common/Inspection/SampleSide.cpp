#include "StdAfx.h"
#include "SampleSide.h"


CSampleSide::CSampleSide()
{
	m_pRefImage = NULL;

	m_StainResult.m_pProbImage = cv::Mat();
	m_StainResult.m_fMaxDefectSize.clear();
	m_StainResult.m_bResult = false;
	m_BubbleResult.m_pProbImage = cv::Mat();
	m_BubbleResult.m_fMaxDefectSize.clear();
	m_BubbleResult.m_bResult = false;
	m_DifferResult.m_pProbImage = cv::Mat();
	m_DifferResult.m_fMaxDefectSize.clear();
	m_DifferResult.m_bResult = false;
	m_ScratchResult.m_pProbImage = cv::Mat();
	m_ScratchResult.m_fMaxDefectSize.clear();
	m_ScratchResult.m_bResult = true;
	m_StampResult.m_pProbImage = cv::Mat();
	m_StampResult.m_fMaxDefectSize.clear();
	m_StampResult.m_bResult = true;

	memset(&m_SizeResult, 0, sizeof(OUTPUT_SIZE));
	memset(m_pstRefOptRangeList, 0x00, sizeof(INFO_OPT_RANGE) * MAX_SIZE_MEASURECOUNT);
	
	memset(&m_SizeSecondResult, 0, sizeof(OUTPUT_SIZE));
	memset(m_pstRefOptRangeList, 0x00, sizeof(INFO_OPT_RANGE) * MAX_SIZE_MEASURECOUNT);

	memset(&m_SizeCalculationResult, 0, sizeof(OUTPUT_SIZE));
	memset(m_pstRefOptRangeList, 0x00, sizeof(INFO_OPT_RANGE) * MAX_SIZE_MEASURECOUNT);
}

CSampleSide::~CSampleSide()
{	
	m_StainResult.m_pProbImage.release();
	m_BubbleResult.m_pProbImage.release();
	m_DifferResult.m_pProbImage.release();
	m_ScratchResult.m_pProbImage.release();
	m_StampResult.m_pProbImage.release();
}

void CSampleSide::CopyFrom(const CSampleSide& rhs)
{
	this->m_SizeCalculationResult = rhs.m_SizeCalculationResult;
}