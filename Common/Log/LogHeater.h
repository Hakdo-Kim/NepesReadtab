#pragma once
#include "afxwin.h"
#include "CommonCapture.h"

#include "LogFileHeater.h"

class CLogHeater
{
public:
	CLogHeater();
	~CLogHeater();

	static void CALLBACK FuncTextLog(void* pArg, int* pszLog, ...);
	INFO_LOGFUNCHEATER GetLogInterface();

	// 
	void FuncLog(int* pszLog);


	void UpdateLogInformation(const INFO_OPTIONLOG* pstLogOpt);
	const INFO_OPTIONLOG* GetLogInformation();
protected:
	CRITICAL_SECTION m_CriticalSection;
	CLogFileHeater m_LogText;

	INFO_OPTIONLOG m_stLogOption;
};