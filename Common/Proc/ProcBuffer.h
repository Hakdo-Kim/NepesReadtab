#pragma once

#include "ProcessDef.h"
#include <vector>


class CProcBuffer
{
public:
	CProcBuffer();
	virtual ~CProcBuffer();

	BOOL CreateBuffer(const INFO_FRAME* pstFrame, const int nMaxCount);
	BOOL CreateBuffer(const int nMaxCount);
	void DestoryBuffer();

	void ResetBuffer();

	INFO_IMAGE* AllocBuffer(const int nMininum = -1);
	void ReleaseBuffer(INFO_IMAGE* pstBuf);

	BOOL IsEnable();


protected:
	CRITICAL_SECTION	m_CriticalSection;

	std::vector<INFO_IMAGE*> m_BufferList;
	int m_nIndex;

	BOOL m_bEnable;
	
};
