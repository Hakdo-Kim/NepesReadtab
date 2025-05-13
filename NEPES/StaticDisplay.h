#pragma once

#include "Video/VideoDef.h"
#include "CommonCapture.h"

typedef struct
{
	HDC m_hDC;
	INFO_VIDEODC m_stFrameDC;

	int m_nWidth;
	int m_nHeight;

} INFO_VIDEO;


class CStaticDisplay : public CStatic
{
	DECLARE_DYNAMIC(CStaticDisplay)

public:
	CStaticDisplay();
	virtual ~CStaticDisplay();

	BOOL DisplayVideoDevice(const INFO_IMAGE* pstImage, const DWORD dwCurFlag, const INFO_CAPTURE_PROCESS* pstCapture);
	void ClearVideoDevice();

	BOOL IsClearVideoDevice();

	void SetBkColor(COLORREF rgb);
	void SetPostionType(TYPE_CAMERAPOS eType);

protected:
	CRITICAL_SECTION m_CriticalSection;
	CRITICAL_SECTION m_CriticalSectionPaint;

	INFO_VIDEO m_stVideo;
	float m_fZoom;
	const DWORD WAIT_DISPLAY = 75;

	COLORREF m_bkColor;
	BOOL m_bClearDevice;

	TYPE_CAMERAPOS m_ePosType;


	BOOL IsEnableVideo();

	BOOL Init(const INFO_IMAGE* pstImage);
	void Deinit();

	BOOL Init(INFO_VIDEODC& stVideoDC, HDC hDC, int nW, int nH, TYPE_VIDEOFORMAT eVideoFormat);
	void Deinit(INFO_VIDEODC& stVideoDC);
	BOOL Blt(INFO_VIDEODC& stVideoDC, const INFO_IMAGE* pstImg);

	void RedrawVideoDevice(HDC hViewDC);
	BOOL CheckVideoDevice(const INFO_IMAGE* pstImage);

	const float GetZoom();
	void SetZoom(float fZoom);
	const float CalcFitZoom();

	BOOL GetPrimaryClientRect(RECT& stPrimary, RECT& stOffscreen, const float fZoom);

	void ConvertColorBit10to8(const TYPE_NETWORK eNetwork, const INFO_IMAGE* pFrom, BYTE* pTo, int nToPitch);
	void ConvertColorBit12to8(const TYPE_NETWORK eNetwork, const INFO_IMAGE* pFrom, BYTE* pTo, int nToPitch);
	void ConvertColorBit10to8(const TYPE_NETWORK eNetwork, const int nW, const int nH, BYTE* pFrom, const int nFromPitch, BYTE* pTo, int nToPitch);
	void ConvertColorBit12to8(const TYPE_NETWORK eNetwork, const int nW, const int nH, BYTE* pFrom, const int nFromPitch, BYTE* pTo, int nToPitch);

	DECLARE_MESSAGE_MAP()
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
	
};