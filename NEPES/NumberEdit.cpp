// NumberEdit.cpp: 구현 파일입니다.
//

#include "stdafx.h"
#include "NEPES.h"
#include "NumberEdit.h"


// CNumberEdit

IMPLEMENT_DYNAMIC(CNumberEdit, CEdit)

CNumberEdit::CNumberEdit()
{

}

CNumberEdit::~CNumberEdit()
{
}


BEGIN_MESSAGE_MAP(CNumberEdit, CEdit)
END_MESSAGE_MAP()



// CNumberEdit 메시지 처리기입니다.
BOOL CNumberEdit::PreTranslateMessage(MSG* pMsg)
{
	if (WM_KEYDOWN == pMsg->message)
	{
		if ('0' == pMsg->wParam ||
			'1' == pMsg->wParam ||
			'2' == pMsg->wParam ||
			'3' == pMsg->wParam ||
			'4' == pMsg->wParam ||
			'5' == pMsg->wParam ||
			'6' == pMsg->wParam ||
			'7' == pMsg->wParam ||
			'8' == pMsg->wParam ||
			'9' == pMsg->wParam ||
			
			VK_NUMPAD0 == pMsg->wParam ||
			VK_NUMPAD1 == pMsg->wParam ||
			VK_NUMPAD2 == pMsg->wParam ||
			VK_NUMPAD3 == pMsg->wParam ||
			VK_NUMPAD4 == pMsg->wParam ||
			VK_NUMPAD5 == pMsg->wParam ||
			VK_NUMPAD6 == pMsg->wParam ||
			VK_NUMPAD7 == pMsg->wParam ||
			VK_NUMPAD8 == pMsg->wParam ||
			VK_NUMPAD9 == pMsg->wParam ||

			VK_TAB		== pMsg->wParam ||
			VK_RETURN	== pMsg->wParam ||
			VK_ESCAPE	== pMsg->wParam ||

			VK_SHIFT	== pMsg->wParam ||
			VK_LSHIFT	== pMsg->wParam ||
			VK_RSHIFT	== pMsg->wParam ||

			VK_HOME		== pMsg->wParam ||
			VK_END		== pMsg->wParam ||
			VK_UP		== pMsg->wParam ||
			VK_DOWN		== pMsg->wParam ||
			VK_LEFT		== pMsg->wParam ||
			VK_RIGHT	== pMsg->wParam ||

			VK_BACK		== pMsg->wParam ||
			VK_DELETE	== pMsg->wParam ||

			VK_SUBTRACT == pMsg->wParam ||
			VK_OEM_MINUS == pMsg->wParam ||		// '-'

			VK_DECIMAL	== pMsg->wParam ||			
			VK_OEM_PERIOD == pMsg->wParam		// '.'
		)
		{
			//
			if(VK_DECIMAL == pMsg->wParam || VK_OEM_PERIOD == pMsg->wParam )
			{
				CString szTemp;
				this->GetWindowText(szTemp);
				if( -1 != szTemp.Find(_T(".")) )
					return TRUE;
			}
			else if (VK_SUBTRACT == pMsg->wParam || VK_OEM_MINUS == pMsg->wParam)
			{
				CString szTemp;
				this->GetWindowText(szTemp);
				if (-1 != szTemp.Find(_T("-")))
					return TRUE;

				int nStart = 0;
				int nEnd = 0;
				this->GetSel(nStart, nEnd);

				int nLine = this->LineFromChar(nStart);
				int nCur = nStart - this->LineIndex(nLine);
				if (0 < nCur)
					return TRUE;
			}

		}
		else
		{
			return TRUE;
		}
	}

	return CEdit::PreTranslateMessage(pMsg);
}
