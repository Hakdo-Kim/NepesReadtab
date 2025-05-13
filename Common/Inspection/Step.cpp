#include "StdAfx.h"
#include "Step.h"

#include <tchar.h> // _vsntprintf

#include "Util/Util.h"

CStep::CStep(std::string strStepName)
	: m_strStepName(strStepName)
{
	m_bInit = FALSE;

	m_eCameraPos = TYPE_CAMERAPOS_NONE;
	memset(&m_stLogFunc, 0x00, sizeof(INFO_LOGFUNC));

}

CStep::~CStep()
{
	;
}

BOOL CStep::IsInit()
{
	return m_bInit;
}

void CStep::Log(char* pszLog, ...)
{
	if (m_stLogFunc.m_pFuncTextLog && m_stLogFunc.m_pArg)
	{
		char szLog[MAX_TEXT_LEN] = { 0, };

		va_list arg;
		va_start(arg, pszLog);
		_vsntprintf(szLog, sizeof(szLog), pszLog, arg);
		va_end(arg);

		CUtil::PrintDebugString(_T("%s\r\n"), szLog);
		m_stLogFunc.m_pFuncTextLog(m_stLogFunc.m_pArg, this->m_eCameraPos, m_strStepName.c_str(), szLog);
	}
}
