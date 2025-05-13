#pragma once

class CRoiRectTracker : public CRectTracker
{
public:
	CRoiRectTracker(void);
	CRoiRectTracker(CWnd* pParent, const RECT* pRect);

	~CRoiRectTracker(void);

	void SetPosition(const RECT* pRect);


private:
	CWnd* m_phParent;
};

