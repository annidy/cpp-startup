#pragma once

#if defined(ENABLE_DUMP) && defined(WIN32)
#include <Windows.h>
#include <dbghelp.h>
#include <tchar.h>
#pragma auto_inline (off)
#pragma comment( lib, "DbgHelp" )
/* cause of i can't write cpp, you must put this macro in your file */
#define DECLARE_MINIDUMP \
LONG WINAPI MyUnhandledExceptionFilter(struct _EXCEPTION_POINTERS* ExceptionInfo) {\
    HANDLE lhDumpFile = CreateFile(_T("DumpFile.dmp"), GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL, NULL);\
    MINIDUMP_EXCEPTION_INFORMATION loExceptionInfo;\
    loExceptionInfo.ExceptionPointers = ExceptionInfo;\
    loExceptionInfo.ThreadId = GetCurrentThreadId();\
    loExceptionInfo.ClientPointers = TRUE;\
    MiniDumpWriteDump(GetCurrentProcess(), GetCurrentProcessId(), lhDumpFile, MiniDumpNormal, &loExceptionInfo, NULL, NULL);\
    CloseHandle(lhDumpFile);\
    return EXCEPTION_EXECUTE_HANDLER;\
} 
#define REGIST_MINIDUMP SetUnhandledExceptionFilter(MyUnhandledExceptionFilter);
#else
#define DECLARE_MINIDUMP
#define REGIST_MINIDUMP
#endif


#if defined(DEBUG) || defined(_DEBUG)
#ifdef WIN32
#include <crtdbg.h>
#define ASSERT _ASSERTE
#else
#include <unistd.h>
#include <assert.h>
#define ASSERT(C) if (!C) { assert(C), kill(getpid(), SIGINT); }
#endif // WIN32
#else
#define ASSERT(C) 0
#endif

#ifdef ENABLE_ASSERT_LEVEL
#define ASSERT_LEVEL_CRITAL 30
#define ASSERT_LEVEL_INFO   20
#define ASSERT_LEVEL_DEBUG  10

#define ASSERTP(C, P) do {\
	if ((P) >= ASSERT_LEVEL) {\
        if (!C) fprintf(stderr, "ASSERT: %s:%d %s\n", __FILE__, __LINE__, #C);\
    }} while(0)
#else
#define ASSERTP(C, P) 0
#endif

#ifdef ENABLE_CHECK
#define CHECK(LINE, C) do {\
    int _r = LINE;\
    if (_r != C) {\
        fprintf(stderr, "%s:%d %s return %d\n", __FILE__, __LINE__, #LINE, _r);\
        fflush(stderr);\
    }} while(0)
#else
#define CHECK(LINE, C) LINE
#endif

#if defined(DEBUG) || defined(_DEBUG)
#define FOR_DEBUG(LINE) LINE
#else
#define FOR_DEBUG 0
#endif

#ifdef ENABLE_TRACE
#define CODE_TRACE log_console::instance().printf("TRACE: %s:%d\n", __FILE__, __LINE__);
#else
#define CODE_TRACE 
#endif

#define DEBUG_BREAK __asm int 3
