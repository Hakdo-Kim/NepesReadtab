#pragma once

// CStaticText

#define MAX_BKIMAGE		9

typedef enum
{
	TYPE_BKPOS_CENTER = 0,

	TYPE_BKPOS_LT,
	TYPE_BKPOS_TOP,
	TYPE_BKPOS_RT,

	TYPE_BKPOS_RIGHT,

	TYPE_BKPOS_RB,
	TYPE_BKPOS_BOTTOM,
	TYPE_BKPOS_LB,

	TYPE_BKPOS_LEFT,

} TYPE_BKPOS;

typedef enum
{
	TYPE_BKALIGN_NONE = 0x0000,

	//
	TYPE_BKALIGN_SINGLE = 0x1000,		// 1 Bitmap

	TYPE_BKALIGN_LEFT = 0x1000,
	TYPE_BKALIGN_RIGHT = 0x1001,
	TYPE_BKALIGN_CENTER = 0x1002,

	TYPE_BKALIGN_TOP = 0x1000,
	TYPE_BKALIGN_BOTTOM = 0x1010,
	TYPE_BKALIGN_VCENTER = 0x1020,

	//
	TYPE_BKALIGN_SINGLETILE = 0x2000,	// 1 Bitmap

	//
	TYPE_BKALIGN_PIECES = 0x4000,		// 9 Bitmap

} TYPE_BKALIGN;

typedef struct
{
	COLORREF m_rgbBrush;
	CBrush* m_pBrush;

	HBITMAP m_BmpList[MAX_BKIMAGE];
	TYPE_BKALIGN m_eBmpAlign;

} INFO_BK;

typedef struct
{
	CFont* m_pFont;
	COLORREF m_rgbTxt;

} INFO_TEXT;


class CStaticText : public CStatic
{
	DECLARE_DYNAMIC(CStaticText)

public:
	CStaticText();
	virtual ~CStaticText();

	BOOL SetTextInfo(TCHAR* pszFont, int nSize, BOOL bBold, COLORREF rgb  );
	BOOL SetBkInfo(COLORREF rgb, HBITMAP* pBmpList = NULL, int nBmpLen = 0, TYPE_BKALIGN eBmpAlign = TYPE_BKALIGN_NONE);
	BOOL SetBkColor(COLORREF rgb);

	BOOL SetText(TCHAR* pszText, DWORD dwAlign);
	BOOL SetText(TCHAR* pszText);

	BOOL SetTextColor(COLORREF rgb);
	void SetBreakPoint(BOOL bBreak);

protected:
	const TCHAR* SYSTEMFONT = _T("MS Shell Dlg");

	INFO_BK m_stBk;
	INFO_TEXT m_stText;

	CString m_szTxt;
	UINT m_nFormat;

	BOOL m_bBreakPoint;

	BOOL InitTextInfo(INFO_TEXT& stText, TCHAR* pszFont, int nSize, BOOL bBold, COLORREF rgb);
	void DeinitTextInfo(INFO_TEXT& stText);

	BOOL InitBkInfo(INFO_BK& stBk, COLORREF rgb, HBITMAP* pBmpList = NULL, int nBmpLen = 0, TYPE_BKALIGN eBmpAlign = TYPE_BKALIGN_NONE);
	void DeinitBkInfo(INFO_BK& stBk);

	void DrawBackground(CDC* pDC, const INFO_BK* pstBk);


	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};



