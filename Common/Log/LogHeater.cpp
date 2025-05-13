#include "StdAfx.h"
#include "LogHeater.h"

#include "Util/Util.h"


CLogHeater::CLogHeater()
{
	::InitializeCriticalSection(&m_CriticalSection);
}

CLogHeater::~CLogHeater()
{
	::DeleteCriticalSection(&m_CriticalSection);
}

INFO_LOGFUNCHEATER CLogHeater::GetLogInterface()
{
	INFO_LOGFUNCHEATER stLogFunc;
	memset(&stLogFunc, 0x00, sizeof(INFO_LOGFUNC));

	stLogFunc.m_pFuncHeaterLog = FuncTextLog;
	stLogFunc.m_pArg = this;

	return stLogFunc;
}

//TODO 매개변수 정리
void CALLBACK CLogHeater::FuncTextLog(void* pArg, int* pszLog, ...)
{
	CLogHeater* pLog = (CLogHeater*)pArg;
	if (NULL == pLog || NULL == pszLog || FALSE == pLog->m_stLogOption.m_bSaveTextLog)
		return;

	/*char szLog[MAX_TEXT_LEN] = { 0, };

	va_list arg;
	va_start(arg, pszLog);
	_vsntprintf(szLog, sizeof(szLog), pszLog, arg);
	va_end(arg);

	pLog->FuncLog(szLog);*/
	pLog->FuncLog(pszLog);
}

void CLogHeater::FuncLog(int* pszLog)
{
	::EnterCriticalSection(&m_CriticalSection);

	char szString[MAX_TEXT_LEN] = { 0, };

	std::string strTemperature = "";
	for (int i = 0; i < PLC_HEATER_MAX; i++){
		sprintf(szString, "%d,", pszLog[i]);
		strTemperature += szString;
	}
	strTemperature += "\r\n";

	strcpy(szString, strTemperature.c_str());
	//_snprintf(szString, MAX_TEXT_LEN, "%s \r\n", temp);

	m_LogText.Write(szString);

	::LeaveCriticalSection(&m_CriticalSection);
}


void CLogHeater::UpdateLogInformation(const INFO_OPTIONLOG* pstLogOpt)
{
	if (NULL == pstLogOpt)
		return;

	memcpy(&m_stLogOption, pstLogOpt, sizeof(INFO_OPTIONLOG));
	m_LogText.UpdateLogDirectory(m_stLogOption.m_szLogPath);

}

const INFO_OPTIONLOG* CLogHeater::GetLogInformation()
{
	return &m_stLogOption;
}