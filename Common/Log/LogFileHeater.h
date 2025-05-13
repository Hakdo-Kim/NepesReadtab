#pragma once
#include "afxwin.h"

#include "Common.h"
#include <queue>

//#define DEF_THREAD_LOG

#ifdef DEF_THREAD_LOG
typedef struct
{
	char* m_pszLog;			// Log String

} INFO_LOG_BUF;

#endif

class CLogFileHeater
{
public:
	CLogFileHeater();
	~CLogFileHeater();

	void UpdateLogDirectory(TCHAR* pszDirPath);

	BOOL Open(const TCHAR* pszLocation);
	void Close();

	BOOL Write(char* pszLog);
	BOOL WriteHeader();

protected:
#ifdef DEF_THREAD_LOG
	static DWORD WINAPI ThreadProc(LPVOID lpArg);
	DWORD ThreadProc(void);
	void SetLogEvent();
#endif

protected:

	TCHAR m_szDirLocation[MAX_FILE_PATH_LEN];
	SYSTEMTIME m_stLogTime;

	CCriticalSection	m_CriticalSection;
	TCHAR m_szLogFilePath[MAX_FILE_PATH_LEN];
	HANDLE m_hFile;

#ifdef DEF_THREAD_LOG
	// Queue Buffer
	std::queue<INFO_LOG_BUF*> m_LogQueue;

	// Thread - Log
	HANDLE	m_hThread;
	HANDLE	m_hEvent;
	HANDLE	m_hStopEvent;
	BOOL	m_bStop;
#endif
};