#pragma once
#include "afxwin.h"
#include "CommonCapture.h"

#include "LogFile.h"

class CLog
{
public:
	CLog();
	~CLog();

	static void CALLBACK FuncTextLog(void* pArg, TYPE_CAMERAPOS ePos, const char* pszTag, char* pszLog, ...);
	INFO_LOGFUNC GetLogInterface();

	// 
	void FuncLog(TYPE_CAMERAPOS ePos, const char* pszTag, char* pszLog);


	void UpdateLogInformation(const INFO_OPTIONLOG* pstLogOpt);
	const INFO_OPTIONLOG* GetLogInformation();
protected:
	CRITICAL_SECTION m_CriticalSection;
	CLogFile m_LogText;

	INFO_OPTIONLOG m_stLogOption;
};