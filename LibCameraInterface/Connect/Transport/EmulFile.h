#pragma once

#include "CameraInterfaceDef.h"
#include <vector>

#define DEF_TRIGGER_COUNT

typedef struct
{
	TCHAR m_szFilePath[MAX_FILE_PATH_LEN];

	DWORD m_dwWidth;
	DWORD m_dwHeight;
	BYTE  m_nBit;

	BYTE* m_pBuf;
	DWORD m_dwBufLen;

} INFO_EMUL_FRAME;


class CEmulFile
{
public:
	CEmulFile();
	virtual ~CEmulFile();

	BOOL IsOpen ();

	BOOL Open(const INFO_CONNECT_EMUL* pInfo);
	void Close();

	BOOL Update(const INFO_CONNECT_EMUL* pInfo);

	BOOL Start(BOOL bSingleFrame=FALSE);
	void Stop();

	const INFO_CONNECT_EMUL* GetDeviceInfo();

	BOOL SetEventFunc(FuncAcquisitionEvent pFunc, void* pUserData);

	BOOL IsCycleDirectory();

protected:
	WIN32_FIND_DATA m_stFileData;
	HANDLE m_hSearch;

	INFO_CONNECT_EMUL m_stEmul;

	HANDLE	m_hThreadEmul;
	BOOL	m_bStopEmul;
	
	HANDLE	m_hEventEmulStop;
	HANDLE	m_hEventFps;

	CRITICAL_SECTION	m_CriticalSection;

	BOOL m_bUpdated;


	FuncAcquisitionEvent m_pFunc;
	void* m_pFuncArg;

	BOOL m_bSuspend;
	BOOL m_bSingleFrame;

#ifdef DEF_TRIGGER_COUNT
	DWORD m_dwTriggerCount;
#endif

	BOOL CheckAttribute(DWORD dwFileAttr);


	static DWORD WINAPI ThreadEmulProc(LPVOID lpArg);
	DWORD ThreadEmulProc(void);

	DWORD GetAcquisitionEventTime();
	
	INFO_EMUL_FRAME* LoadFrame(const TCHAR* pszPath, const INFO_CONNECT_EMUL* pstEmul);
	INFO_EMUL_FRAME* LoadEmulFrame(const TCHAR* pszPath, const INFO_CONNECT_EMUL* pstEmul);
	INFO_EMUL_FRAME* LoadFileFrame(const TCHAR* pszPath);
	INFO_EMUL_FRAME* LoadUpdatedFileFrame();




};