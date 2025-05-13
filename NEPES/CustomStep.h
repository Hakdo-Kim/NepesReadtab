#pragma once


// CCustomStep

class CCustomStep : public CStatic
{
	DECLARE_DYNAMIC(CCustomStep)

public:
	CCustomStep();
	virtual ~CCustomStep();

	void SetTextFont(TCHAR* pszName, int nHeight, int nWeight);
	void SetTextColor(COLORREF rgb);

	void SetMessage(TCHAR* pszMsg);

protected:
	const int MARGIN = 5;
	COLORREF m_rgbBk;
	COLORREF m_rgbTxt;

	int m_nFontHeight;
	int m_nFontWeight;
	CString m_szFontName;


	CString m_szMessage;

	void DrawBackground(CDC* pMemDC);
	void DrawMessage(CDC* pMemDC);

	int GetStringLength(CString* pString);
	CString GetString(CString* pString, const int nStart, const int nEnd);

	virtual void PreSubclassWindow();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
};


