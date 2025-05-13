#include "stdafx.h"
#include "RoiTrackerDC.h"

CRoiTrackerDC::CRoiTrackerDC(CDC* pDC, DWORD dwRopCode)
	: m_pDC(pDC), m_pOldBitmap(NULL), m_RopCode(dwRopCode)
{
	if (!pDC) return;
	ASSERT_VALID(pDC);

	if (pDC->IsPrinting())
	{
		if (pDC->m_hDC != pDC->m_hAttribDC)
		{
			m_hDC = pDC->m_hDC;
			m_hAttribDC = pDC->m_hAttribDC;
		}
		else
		{
			VERIFY(Attach(pDC->Detach()));
		}
		return;
	}

	CRect rcClip;
	VERIFY(pDC->GetClipBox(rcClip) != ERROR);

	pDC->LPtoDP(rcClip);
	rcClip.NormalizeRect();

	if (m_BufferBitmap.ReserveBitmap(pDC, rcClip.Size()))
	{
		VERIFY(CreateCompatibleDC(pDC));

		ASSERT(m_pOldBitmap == 0);
		m_pOldBitmap = (CBitmap *)SelectObject(&m_BufferBitmap.m_Bitmap);

		int mapmode = pDC->GetMapMode();
		SetMapMode(mapmode);
		SetWindowOrg(pDC->GetWindowOrg());
		SetViewportOrg(pDC->GetViewportOrg());

		if (mapmode > MM_MAX_FIXEDSCALE)
		{
			SetWindowExt(pDC->GetWindowExt());
			SetViewportExt(pDC->GetViewportExt());
		}

		COLORREF col = pDC->GetBkColor();
		VERIFY(pDC->GetClipBox(rcClip) != ERROR);

		rcClip.NormalizeRect();
		if (mapmode != MM_TEXT)
		{
			CSize szPixels(2, 2);
			DPtoLP(&szPixels);
			rcClip.InflateRect(szPixels.cx, szPixels.cy);
		}

		FillSolidRect(rcClip, col);
		SetBoundsRect(NULL, DCB_ENABLE | DCB_ACCUMULATE | DCB_RESET);
	}
	else
	{
		VERIFY(Attach(pDC->Detach()));
	}
}

CRoiTrackerDC::~CRoiTrackerDC()
{
	if (!m_pDC || (m_pDC->IsPrinting() && m_pDC->m_hDC != m_pDC->m_hAttribDC))
		return;

	if (m_BufferBitmap.IsValid() && !m_pDC->IsPrinting())
	{
		CRect rcBounds;
		GetBoundsRect(rcBounds, DCB_RESET);
		rcBounds.NormalizeRect();

		CRect rcClip;
		m_pDC->GetClipBox(rcClip);
		rcClip.NormalizeRect();

		rcBounds &= rcClip;

		if (!rcBounds.IsRectEmpty())
		{
			if (GetMapMode() != MM_TEXT)
			{
				CSize szPixels(2, 2);
				DPtoLP(&szPixels);
				rcBounds.InflateRect(szPixels.cx, szPixels.cy);
			}

			VERIFY(m_pDC->BitBlt(
				rcBounds.left, rcBounds.top,
				rcBounds.Width(), rcBounds.Height(),
				this,
				rcBounds.left, rcBounds.top,
				m_RopCode));
		}

		if (m_pOldBitmap)
			SelectObject(m_pOldBitmap);
	}
	else
	{
		VERIFY(m_pDC->Attach(Detach()));
	}
}

BOOL CRoiTrackerDC::BufferBitmap::ReserveBitmap(CDC * pDC, CSize sz)
{
	if (IsValid())
	{
		BITMAP bm;
		m_Bitmap.GetBitmap(&bm);

		if (sz.cx > bm.bmWidth || sz.cy > bm.bmHeight)
		{
			m_Bitmap.DeleteObject();
		}
		else return TRUE;
	}

	BOOL bResult = m_Bitmap.CreateCompatibleBitmap(pDC, sz.cx, sz.cy);

	return bResult;
}

CRoiTrackerDC::BufferBitmap CRoiTrackerDC::m_BufferBitmap;