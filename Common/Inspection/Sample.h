#pragma once
#include "CommonCapture.h"
#include "SampleSide.h"


typedef struct
{
	TYPE_STEP m_eStep;

	OUTPUT_SIZE m_stOutputSize;
	OUTPUT_STAIN m_stOutputStain;
	OUTPUT_DIFFER m_stOutputDiffer;
	OUTPUT_BUBBLE m_stOutputBubble;
	OUTPUT_SCRATCH m_stOutputScratch;
	OUTPUT_STAMP m_stOutputStamp;
	OUTPUT_SIZE m_stOutputSizeSecond;
	OUTPUT_SIZE m_stOutputSizeCalc;

} INFO_DISPLAYOUTPUT;


class CSample
{
public:
	CSample();
	virtual ~CSample();

	int m_nIndex;

	CSampleSide m_FirstSample;

	// Size Option
	INFO_OPT_RANGE m_pstRefOptRangeList[MAX_CAMERA_INTERFACE][MAX_SIZE_MEASURECOUNT];
	INFO_OPT_RANGE m_pstRefOptRangeSpecList[MAX_SIZE_MEASURECOUNT];
	const int m_nRangeCount = MAX_SIZE_MEASURECOUNT;

};