#pragma once

#ifndef NOTSRCINVERT
#define NOTSRCINVERT	0x00990066		// DSxn => Destination, Source, xor, not
#endif

class CRoiTrackerDC : public CDC
{
public:
	CRoiTrackerDC(CDC* pDC, DWORD dwRopCode = SRCCOPY);
	virtual ~CRoiTrackerDC();

protected:
	CDC *m_pDC;
	DWORD m_RopCode;

	CBitmap* m_pOldBitmap;

	// Helper class
	static class BufferBitmap
	{
	public:
		BOOL ReserveBitmap(CDC * pDC, CSize sz);
		BOOL IsValid() const		{ return m_Bitmap.GetSafeHandle() != NULL; }
		CBitmap m_Bitmap;
	} m_BufferBitmap;


};