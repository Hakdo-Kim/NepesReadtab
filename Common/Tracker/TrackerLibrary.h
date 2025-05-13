#pragma once

#if defined(_USRDLL) | defined(_AFXDLL)
#define TRACKERDLL extern "C"  __declspec(dllexport)
#else
#define TRACKERDLL extern "C"  __declspec(dllimport)
#endif

typedef enum
{
	TYPE_TRACKER_NONE,
	
	TYPE_TRACKER_CIRCLE,
	TYPE_TRACKER_LINE,
	TYPE_TRACKER_POINT,
	TYPE_TRACKER_POLYGON,
	TYPE_TRACKER_RECT,
	TYPE_TRACKER_RECT_ROTATE,
	TYPE_TRACKER_RING,
	
	TYPE_TRACKER_MAX,
	
} TYPE_TRACKER;

typedef enum
{
	TYPE_HITTRACKER_NONE,

	TYPE_HITTRACKER_TOPLEFT,
	TYPE_HITTRACKER_TOP,
	TYPE_HITTRACKER_TOPRIGHT,

	TYPE_HITTRACKER_RIGHT,

	TYPE_HITTRACKER_BOTTOMRIGHT,
	TYPE_HITTRACKER_BOTTOM,
	TYPE_HITTRACKER_BOTTOMLEFT,

	TYPE_HITTRACKER_LEFT,

	TYPE_HITTRACKER_CENTER,

	TYPE_HITTRACKER_BODY,

	TYPE_HITTRACKER_MAX,

} TYPE_HITTRACKER;

typedef enum
{
	TYPE_ALIGNTRACKER_NONE,

	TYPE_ALIGNTRACKER_LEFT,
	TYPE_ALIGNTRACKER_CENTER,
	TYPE_ALIGNTRACKER_RIGHT,

	TYPE_ALIGNTRACKER_TOP,
	TYPE_ALIGNTRACKER_MIDDLE,
	TYPE_ALIGNTRACKER_BOTTOM,

	TYPE_ALIGNTRACKER_MAX,

} TYPE_ALIGNTRACKER;

typedef struct
{
	double m_fx;
	double m_fy;

} TRACKPOINT, FAR *LPTRACKPOINT;

typedef struct
{
	double m_fcx;
	double m_fcy;

} TRACKSIZE, FAR *LPTRACKSIZE;

typedef struct
{
	double m_fleft;
	double m_ftop;
	double m_fright;
	double m_fbottom;

} TRACKRECT;

typedef struct
{
	DWORD	m_dwDirection;
	DWORD	m_dwStep;
	DWORD	m_dwOpacity;

	COLORREF m_rgbOutLine;
	COLORREF m_rgbInLine;
	COLORREF m_rgbInBrush;

	DWORD	m_dwOutLine;
	DWORD	m_dwInLine;

	HPEN	m_hOutLine;
	HPEN	m_hInLine;
	HBRUSH	m_hInBrush;

	BOOL m_bDrawForFile;

} INFO_RESERVEDROI;

typedef void* HTRACKER;

TRACKERDLL	BOOL IsInitTracker(HTRACKER hTracker);


TRACKERDLL	HTRACKER InitTracker(TYPE_TRACKER eTracker, CWnd* pWnd);
TRACKERDLL	void DeinitTracker(HTRACKER hTracker);
TRACKERDLL	void ClearTracker(HTRACKER hTracker);

TRACKERDLL	TYPE_TRACKER GetTrackerType(HTRACKER hTracker);
TRACKERDLL	BOOL SetTrackerCursor(HTRACKER hTracker, CDC* pDC, float fZoom);

TRACKERDLL	BOOL RunTracker(HTRACKER hTracker, CDC* pDC, UINT nFlags, TRACKPOINT point, float fZoom, BOOL bErase);
TRACKERDLL	void DrawTracker(HTRACKER hTracker, CDC* pDC, float fZoom);
TRACKERDLL	void DrawRoi(HTRACKER hTracker, CDC* pDC, TRACKSIZE size, float fZoom, void* pReserved = NULL);
TRACKERDLL	void DrawMoveTracker(HTRACKER hTracker, CDC* pDC, TRACKPOINT pt1, TRACKPOINT pt2, float fZoom, BOOL bDone);

TRACKERDLL	int	GetTrackerPoint(HTRACKER hTracker, LPTRACKPOINT pPoint, int nLen);
TRACKERDLL	int	SetTrackerPoint(HTRACKER hTracker, const LPTRACKPOINT pPoint, const int nLen, float fZoom, BOOL bErase);

TRACKERDLL	void SetTrackerAlign(HTRACKER hTracker, TYPE_ALIGNTRACKER eAlign, TRACKRECT rtPos);
TRACKERDLL	void SetOuterScroll(HTRACKER hTracker, BOOL bOuter);
TRACKERDLL	void SetBaseSelection(HTRACKER hTracker, BOOL bBase);

TRACKERDLL	BOOL SetWidth(HTRACKER hTracker, DWORD dwWidth);
TRACKERDLL	BOOL SetHeight(HTRACKER hTracker, DWORD dwHeight);

TRACKERDLL	BOOL MoveRoi(HTRACKER hTracker, int cx, int cy);



TRACKERDLL	TRACKRECT GetPositionRect(HTRACKER hTracker, LPTRACKPOINT pPointList, int nLen);

TRACKERDLL	TYPE_HITTRACKER GetTrackerHitPosition(HTRACKER hTracker, TRACKPOINT point, float fZoom);



