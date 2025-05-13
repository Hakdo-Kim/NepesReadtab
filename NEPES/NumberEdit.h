#pragma once


// CNumberEdit

class CNumberEdit: public CEdit
{
	DECLARE_DYNAMIC(CNumberEdit)

public:
	CNumberEdit();
	virtual ~CNumberEdit();

protected:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	DECLARE_MESSAGE_MAP()
};


