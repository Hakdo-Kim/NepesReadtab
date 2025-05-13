#pragma once
#include <gdiplus.h>

using namespace Gdiplus;
#pragma comment (lib, "Gdiplus.lib")

#define VALUE_INFLATE			5
#define VALUE_INFLATE_POINT		5

#define VALUE_PI				(4.0f * atan(1.0f))

#define ROTATE_POINT_DISTANCE	10

#define FLAG_LBUTTONDOWN		0x80000

typedef enum
{
	TYPE_RESULTROI_FAILED	= -2,
	TYPE_RESULTROI_CANCELLED= -1,
	TYPE_RESULTROI_CONTINUE	= 0,
	TYPE_RESULTROI_SUCCEEDED= 1,
	TYPE_RESULTROI_COPY		= 2,
	TYPE_RESULTROI_NOMOVE	= 3,

} TYPE_RESULTROI;

typedef enum
{
	TYPE_FLAGROI_MOUSE		= 0x007F,
	TYPE_FLAGROI_REMOVE		= 0x0000,
	TYPE_FLAGROI_DRAW		= 0x0400,
	TYPE_FLAGROI_FIRST		= 0x0800,
	TYPE_FLAGROI_ENTER		= 0x1000,
	TYPE_FLAGROI_LEAVE		= 0x2000,
	TYPE_FLAGROI_LAST		= 0x4000,

} TYPE_FLAGROI;

typedef enum
{
	TYPE_OPTIONROI_NONE			= 0x0000,

	TYPE_OPTIONROI_ROTATE		= 0x0001,
	TYPE_OPTIONROI_SHEAR		= 0x0002,
	TYPE_OPTIONROI_ALLOWMIRROR	= 0x0004,
	TYPE_OPTIONROI_CENTER		= 0x0008,
	TYPE_OPTIONROI_CENTERMOVE	= 0x0010,
	TYPE_OPTIONROI_ROTATEREVERSE= 0x0020,
	TYPE_OPTIONROI_MARKDOTTED	= 0x0040,
	TYPE_OPTIONROI_TRACKDOTTED	= 0x0080,
	TYPE_OPTIONROI_PATHDOTTED	= 0x0100,

} TYPE_OPTIONROI;

typedef enum
{
	TYPE_TRANSFORMROI_NONE,

	TYPE_TRANSFORMROI_CREATE,
	TYPE_TRANSFORMROI_MOVE,
	TYPE_TRANSFORMROI_SCALE,
	TYPE_TRANSFORMROI_ROTATE,

} TYPE_TRANSFORMROI;

typedef enum
{
	TYPE_HITROI_NONE		= -1,

	// For point
	TYPE_HITROI_TOPLEFT		= 0,
	TYPE_HITROI_TOP			= 1,
	TYPE_HITROI_TOPRIGHT	= 2,

	TYPE_HITROI_RIGHT		= 3,

	TYPE_HITROI_BOTTOMRIGHT	= 4,
	TYPE_HITROI_BOTTOM		= 5,
	TYPE_HITROI_BOTTOMLEFT	= 6,

	TYPE_HITROI_LEFT		= 7,

	TYPE_HITROI_CENTER		= 8,

	TYPE_HITROI_BODY		= 9,	// Not Used

	// For Line (Rectangle
	TYPE_HITROI_LINE_TOP	= 10,
	TYPE_HITROI_LINE_RIGHT	= 11,
	TYPE_HITROI_LINE_BOTTOM	= 12,
	TYPE_HITROI_LINE_LEFT	= 13,

	// For Ring
	TYPE_HITROI_LINE_INNER		= 14,
	TYPE_HITROI_LINE_OUTER		= 15,
	TYPE_HITROI_LINE_TOPANGLE	= 16,
	TYPE_HITROI_LINE_BOTTOMANGLE= 17,


	TYPE_HITROI_MAX,

} TYPE_HITROI;

typedef enum
{
	TYPE_ALIGN_NONE,

	TYPE_ALIGN_LEFT,
	TYPE_ALIGN_CENTER,
	TYPE_ALIGN_RIGHT,

	TYPE_ALIGN_TOP,
	TYPE_ALIGN_MIDDLE,
	TYPE_ALIGN_BOTTOM,

	TYPE_ALIGN_MAX,

} TYPE_ALIGN;



typedef enum
{
	TYPE_CURSOR_NONE,

	TYPE_CURSOR_NWSE,
	TYPE_CURSOR_NESW,
	TYPE_CURSOR_NS,
	TYPE_CURSOR_WE,
	TYPE_CURSOR_CENTOR,
	TYPE_CURSOR_MOVE,
	TYPE_CURSOR_ROTATE,

} TYPE_CURSOR;

typedef struct
{
	double m_fx;
	double m_fy;

} INFO_POINT, FAR *LPINFO_POINT;


typedef struct
{
	INFO_POINT m_ptStart;
	INFO_POINT m_ptEnd;

} INFO_LINE;

typedef struct
{
	double m_fcx;
	double m_fcy;

} INFO_SIZE, FAR *LPINFO_SIZE;

typedef struct
{
	double m_fleft;
	double m_ftop;
	double m_fright;
	double m_fbottom;

} INFO_RECT;

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

} INFO_RESERVED;


class CRoiTracker
{
public:
	CRoiTracker(CWnd* pWnd);
	virtual ~CRoiTracker();

	virtual BOOL IsInit();
	virtual BOOL IsEnableRotate();
	virtual BOOL SetCursor(CDC* pDC, float fZoom);
	virtual void Clear();

	TYPE_RESULTROI Track(CDC* pDC, UINT nFlags, INFO_POINT point, float fZoom, BOOL bErase);
	BOOL IsTracking();

	virtual TYPE_HITROI HitTest(INFO_POINT point, float fZoom);
	virtual void Draw(CDC* pDC, float fZoom);
	virtual void DrawRoi(CDC* pDC, INFO_SIZE stSize, float fZoom, void* pReserved = NULL);
	virtual void DrawTracker(CDC* pDC, INFO_POINT pt1, INFO_POINT pt2, float fZoom, BOOL bDone = FALSE);

	virtual int GetPoint(LPINFO_POINT pPoint, int nLen);
	virtual int SetPoint(const LPINFO_POINT pPoint, const int nLen, float fZoom, BOOL bErase = TRUE);

	virtual INFO_RECT GetPositionRect(LPINFO_POINT pPointList, int nLen);

	virtual void SetAlign(TYPE_ALIGN eAlign, INFO_RECT rtPos);

	virtual BOOL SetWidth(DWORD dwWidth);
	virtual BOOL SetHeight(DWORD dwHeight);

	virtual BOOL MovePoint(int cx, int cy);

	void SetOuterScroll(BOOL bOuter);
	BOOL IsOuterScroll();

	void SetBaseSelection(BOOL bBase);
	BOOL IsBaseSelection();

protected:
	const float DEFAULT_ZOOM = 1.0f;
	const int ARROWWIDTH = 3;

	ULONG_PTR m_GdiPlusToken;

	CWnd* m_pWnd;

	BOOL m_bTracking;
	BOOL m_bDirty;
	BOOL m_bOuterScroll;
	BOOL m_bBaseSelection;

	INFO_POINT m_stPoint;
	INFO_POINT m_stPreviousPoint;
	INFO_POINT m_stStartPoint;

	virtual TYPE_RESULTROI OnBeginTrack(UINT nFlags, INFO_POINT point, float fZoom);
	virtual TYPE_RESULTROI OnEndTrack(TYPE_RESULTROI eResult, float fZoom, BOOL bErase=TRUE);
	virtual TYPE_RESULTROI OnMouseMessage(UINT msg, UINT nFlags, INFO_POINT point, float fZoom);
	virtual TYPE_RESULTROI OnMessage(MSG& msg);
	virtual TYPE_RESULTROI OnKeyMessage(UINT msg, UINT nChar, UINT nRepCnt, UINT nFlags);
	virtual void OnUpdate(CDC* pDC, UINT nMode, float fZoom);
	virtual void Invalidate(BOOL bErase = TRUE);

	INFO_RECT GetPointRect(INFO_POINT point);

	double GetRadious(INFO_POINT pt1, INFO_POINT pt2);
	double GetAngle(INFO_POINT pt1, INFO_POINT pt2, BOOL bDegree = FALSE);

	void ConvertPointPixelToDraw(const LPINFO_POINT pSrcPoint, LPINFO_POINT pDestPoint, const int nLen, const float fZoom);
	void ConvertPointDrawToPixel(const LPINFO_POINT pSrcPoint, LPINFO_POINT pDestPoint, const int nLen, const float fZoom);
	void ConvertPointPixelToDrawForRoi(const LPINFO_POINT pSrcPoint, LPINFO_POINT pDestPoint, const int nLen, const INFO_SIZE stSize, const float fZoom, BOOL bDrawForFile = FALSE);

	int GetHScrollPos();
	int GetVScrollPos();

	HBITMAP CreateEdgeBitmap(HDC hDC, const int nW, const int nH, void** ppBits);

	BOOL CheckPointInRect(INFO_RECT rect, INFO_POINT point, float fZoom);

	INFO_POINT GetTrackerPointFromSrc(INFO_POINT point, float fZoom);
	INFO_POINT GetTrackerPointFromSrc(INFO_POINT point, INFO_POINT ptStart, INFO_POINT ptEnd, float fZoom);
	INFO_POINT GetSrcPointFromTracker(INFO_POINT point, float fZoom);
	INFO_POINT GetPointFromPointF(PointF point);

	INFO_RECT SetRectangle(double left, double top, double right, double bottom);
	BOOL IsPointInRectangle(const INFO_RECT& rect, const INFO_POINT& point);

	INFO_SIZE GetSize(const INFO_POINT& point1, const INFO_POINT& point2);
	INFO_RECT GetInflateRect(const INFO_POINT& point, double fx, double fy);

	RECT GetRectangle(const INFO_RECT& rect);
	POINT GetPoint(const INFO_POINT& point);

	// Draw 
	void DrawLine(CDC* pDC, const INFO_POINT& point1, const INFO_POINT& point2);
	void DrawPolygon(CDC* pDC, INFO_POINT* pPointList, int nLen);
	void DrawArc(CDC* pDC, const INFO_RECT& rect, const INFO_POINT& ptStart, const INFO_POINT& ptEnd);

	DWORD GetRemainder(DWORD dwValue, DWORD dwDiv);
	double GetRemainder(double fValue, double fDiv);

	int GetZoomWeight(int nWeight, float fZoom);

};