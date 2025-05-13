#include "StdAfx.h"
#include "Log.h"

#include "Util/Util.h"


CLog::CLog()
{
	::InitializeCriticalSection(&m_CriticalSection);
}

CLog::~CLog()
{
	::DeleteCriticalSection(&m_CriticalSection);
}

INFO_LOGFUNC CLog::GetLogInterface()
{
	INFO_LOGFUNC stLogFunc;
	memset(&stLogFunc, 0x00, sizeof(INFO_LOGFUNC));

	stLogFunc.m_pFuncTextLog = FuncTextLog;
	stLogFunc.m_pArg = this;

	return stLogFunc;
}

void CALLBACK CLog::FuncTextLog(void* pArg, TYPE_CAMERAPOS ePos, const char* pszTag, char* pszLog, ...)
{
	CLog* pLog = (CLog*)pArg;
	if (NULL == pLog || NULL == pszTag || NULL == pszLog || FALSE == pLog->m_stLogOption.m_bSaveTextLog)
		return;

	char szLog[MAX_TEXT_LEN] = { 0, };

	va_list arg;
	va_start(arg, pszLog);
	_vsntprintf(szLog, sizeof(szLog), pszLog, arg);
	va_end(arg);

	pLog->FuncLog(ePos, pszTag, szLog);
}

void CLog::FuncLog(TYPE_CAMERAPOS ePos, const char* pszTag, char* pszLog)
{
	::EnterCriticalSection(&m_CriticalSection);

	char szString[MAX_TEXT_LEN] = { 0, };

	if (TYPE_CAMERAPOS_FIRST == ePos)
		_snprintf(szString, MAX_TEXT_LEN, "    [FIRST %s] %s \r\n", pszTag, pszLog);
	else if (TYPE_CAMERAPOS_SECOND == ePos)
		_snprintf(szString, MAX_TEXT_LEN, "    [SECOND %s] %s \r\n", pszTag, pszLog);
	else
		_snprintf(szString, MAX_TEXT_LEN, "[%s] %s \r\n", pszTag, pszLog);

	m_LogText.Write(szString);

	::LeaveCriticalSection(&m_CriticalSection);
}


void CLog::UpdateLogInformation(const INFO_OPTIONLOG* pstLogOpt)
{
	if (NULL == pstLogOpt)
		return;

	memcpy(&m_stLogOption, pstLogOpt, sizeof(INFO_OPTIONLOG));
	m_LogText.UpdateLogDirectory(m_stLogOption.m_szLogPath);

}

const INFO_OPTIONLOG* CLog::GetLogInformation()
{
	return &m_stLogOption;
}