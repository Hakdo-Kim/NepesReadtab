#pragma once

#include "Common.h"

#include <math.h>
#include <gdiplus.h>
#include "TrackerLibrary.h"

#ifdef DEF_LPAPP
#include "LP_TypeDef.h"
using namespace LP_VisionApp;
#endif


using namespace Gdiplus;

class CLPTracker
{
public:
	CLPTracker();
	CLPTracker(CWnd* pWnd);
	
	virtual ~CLPTracker();

	//
	BOOL IsInit();

	BOOL Init(TYPE_TRACKER eTracker);
	BOOL Init(TYPE_TRACKER eTracker, CWnd* pWnd);
	void Deinit();
	void Clear();

	TYPE_TRACKER GetType();
	TYPE_HITTRACKER GetTrackerHitPosition(TRACKPOINT point, float fZoom);

	BOOL SetCursor(CDC* pDC, float fZoom = 1.0f);

	BOOL Track(CDC* pDC, UINT nFlags, TRACKPOINT point, float fZoom = 1.0f, BOOL bErase = TRUE);
	void Draw(CDC* pDC, float fZoom = 1.0f);
	void Draw(CDC* pDC, TYPE_TRACKER eTracker, LPTRACKPOINT pPointList, int nLen, SIZE stSize, float fZoom = 1.0f, void* pReserved = NULL);
	void DrawTracker(CDC* pDC, TRACKPOINT pt1, TRACKPOINT pt2, float fZoom, BOOL bDone);

	int GetPoint(LPTRACKPOINT pPoint, int nLen);
	int SetPoint(LPTRACKPOINT pPoint, int nLen, float fZoom, BOOL bErase = TRUE);

	BOOL GetMaskBuffer(TYPE_TRACKER eTracker, LPTRACKPOINT pPointList, int nLen, unsigned char** ppBuf, int* pBufLen, int& nW, int& nH);

	void SetOuterScrollWindow(BOOL bOuter);
	BOOL GetOuterScrollWindow();

	void SetSelectedState(BOOL bSelected);
	BOOL GetSelectedState();

	void SetBaseSelected(BOOL bBase);
	BOOL IsBaseSelected();


	void SetCurOuterScrollWindow();

#ifdef DEF_LPAPP
	BOOL GetRoi(CLP_ROI* pRoi);
#endif

	RECT GetPositionRect(LPTRACKPOINT pPointList, int nLen);
	BOOL GetPositionRectFromRing(LPTRACKPOINT pPointList, int nLen, RECT* pRect, int nRectLen);

	void SetAlign(TYPE_ALIGNTRACKER eAlign, RECT rtPos);

	BOOL SetWidth(DWORD dwWidth);
	BOOL SetHeight(DWORD dwHeight);

	BOOL MovePoint(int cx, int cy);


protected:
	HTRACKER m_hTracker;
	CWnd* m_pWnd;
	BOOL m_bOuterScroll;
	BOOL m_bSelected;
	BOOL m_bBaseSelected;

	const int MASKPAD = 5;

	double GetAngle(TRACKPOINT pt1, TRACKPOINT pt2, BOOL bDegree);
	int GetRadious(TRACKPOINT pt1, TRACKPOINT pt2);


	ColorPalette* GetPalette();
	BOOL GetBuffer(Bitmap& bmp, unsigned char** ppBuf, int* pBufLen, const int nW, const int nH);
	

	BOOL GetCircleMaskBuffer(LPTRACKPOINT pPointList, int nLen, unsigned char** ppBuf, int* pBufLen, int& nW, int& nH);
	BOOL GetLineMaskBuffer(LPTRACKPOINT pPointList, int nLen, unsigned char** ppBuf, int* pBufLen, int& nW, int& nH);
	BOOL GetPointMaskBuffer(LPTRACKPOINT pPointList, int nLen, unsigned char** ppBuf, int* pBufLen, int& nW, int& nH);
	BOOL GetPolygonMaskBuffer(LPTRACKPOINT pPointList, int nLen, unsigned char** ppBuf, int* pBufLen, int& nW, int& nH);
	BOOL GetRectMaskBuffer(LPTRACKPOINT pPointList, int nLen, unsigned char** ppBuf, int* pBufLen, int& nW, int& nH);
	BOOL GetRectRotateMaskBuffer(LPTRACKPOINT pPointList, int nLen, unsigned char** ppBuf, int* pBufLen, int& nW, int& nH);
	BOOL GetRingMaskBuffer(LPTRACKPOINT pPointList, int nLen, unsigned char** ppBuf, int* pBufLen, int& nW, int& nH);

};