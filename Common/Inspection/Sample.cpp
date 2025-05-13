#include "StdAfx.h"
#include "Sample.h"

CSample::CSample()
{
	m_nIndex = -1;

	memset(m_pstRefOptRangeList, 0x00, sizeof(INFO_OPT_RANGE)* MAX_CAMERA_INTERFACE * MAX_SIZE_MEASURECOUNT);
}

CSample::~CSample()
{
}
