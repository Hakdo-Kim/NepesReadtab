#ifndef __CRTDBGLEAKCHECK_H__
#define __CRTDBGLEAKCHECK_H__

#ifdef CRTDBGLEAKCHECK_EXPORTS
#define CRTDBGLEAKCHECK __declspec(dllexport)
#else
#define CRTDBGLEAKCHECK __declspec(dllimport)
#endif

CRTDBGLEAKCHECK void EnableCrtDbgLeakCheck();
CRTDBGLEAKCHECK void EnableCrtDbgDumpObject();

#endif // __CRTDBGLEAKCHECK_H__