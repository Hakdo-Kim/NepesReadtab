#include "StdAfx.h"
#include "RoiRectTracker.h"


CRoiRectTracker::CRoiRectTracker(void) : m_phParent(NULL)
{
}

CRoiRectTracker::CRoiRectTracker(CWnd* pParent, const RECT* pRect)
{
	CRectTracker::Construct();
	CRectTracker::m_rect.CopyRect(pRect);
	CRectTracker::m_nStyle = CRectTracker::resizeInside | CRectTracker::solidLine;

	m_phParent = pParent;
}

CRoiRectTracker::~CRoiRectTracker(void)
{
}

void CRoiRectTracker::SetPosition(const RECT* pRect)
{
	CRoiRectTracker::m_rect.CopyRect(pRect);
}

