#pragma once
#include "Step.h"
#include <opencv2/core/core.hpp>

#ifdef NAVIAI_SUPPORT
#include "NAVIAIMars.h"
#endif

// ��� �˻�

class CStepStain : public CStep
{
public:
	CStepStain();
	virtual ~CStepStain();

	virtual BOOL Init(TYPE_CAMERAPOS eCameraPos, INFO_LOGFUNC stLogFunc);
	virtual void Deinit();
	virtual BOOL Process(CSampleSide& sample);
	virtual BOOL Process(CSampleSide& sample, cv::Mat captureImg);

	virtual BOOL Load(INFO_INSPECTION* pstInspection);

	virtual BOOL Get(INFO_INSPECTION* pstInspection);
	virtual BOOL Set(const INFO_INSPECTION* pstInspection);

	const INFO_INSPECTION_STAIN* GetInformation();
	BOOL SetInformation(const INFO_INSPECTION_STAIN* pInfoSize);

	void OnePictureTest(const TCHAR* pszPath);
#if 0
	void CStepStain::setTrainFile();
#else
	void CStepStain::setTrainFile(const TCHAR* pszPath);
#endif
	std::string datName;
	BOOL m_bImgLog;
	// Version 1.3.8.1 Image Log Format (jpg)
	BOOL m_bImgCompress;

protected:
	static const int MAX_RANGE_VALUE = 256;
	BOOL TypeChange(TYPE_CAMERAPOS eCameraPos, INFO_LOGFUNC stLogFunc, char *trained_file);
	INFO_INSPECTION_STAIN m_stInfoStain;
	
#ifdef NAVIAI_SUPPORT
	COLORREF RainbowColorTable[MAX_RANGE_VALUE];	
	INAVIAIMars *gNAVIAIMars1;	
	INAVIAIMars *gNAVIAIMars2;
	NAVIAINetInfo net_info;
	NAVIAINetInfo net_info1;
	NAVIAINetInfo net_info2;
#endif

	cv::Mat		g_raw_result_img;	
	cv::Mat		g_result_img;
	cv::Mat		g_input_img;
	cv::Mat		g_view_img;
	

	inline int Normalize(float input, float range_min, float range_max, int max_value)
	{
		return (input * max_value) / (range_max - range_min);
	}
};