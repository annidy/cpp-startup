#pragma once

#if defined(_MSC_VER)
#include <Windows.h>
#include <tchar.h>
#endif

#if defined(ENABLE_DUMP)
#include <dbghelp.h>
#pragma auto_inline (off)
#pragma comment( lib, "DbgHelp" )
/* cause of i can't write cpp, you must put this macro in your file */
LONG WINAPI MyUnhandledExceptionFilter(struct _EXCEPTION_POINTERS* ExceptionInfo);
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
#define REGIST_MINIDUMP ((void*)0)();
#endif

#if defined(ENABLE_CONSOLE)
#define REDICT_STDIO_TO_CONSOLE \
do {\
    int hConHandle;\
    long lStdHandle;\
    FILE *fp;\
    AllocConsole();\
    lStdHandle = (long)GetStdHandle(STD_OUTPUT_HANDLE);\
    hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);\
    fp = _fdopen( hConHandle, "w" );\
    *stdout = *fp;\
    setvbuf( stdout, NULL, _IONBF, 0 );\
} while(0)
#else
#define REDICT_STDIO_TO_CONSOLE 0
#endif

#ifdef ENABLE_ASSERT
#   ifdef _MSC_VER
#       include <crtdbg.h>
#       define ASSERT(expr) _ASSERT_EXPR((expr), _CRT_WIDE(#expr))
#   else
#       include <unistd.h>
#       include <stdio.h>
#       define ASSERT(C) ((!!((C))) || (LOG("ASSERT: %s:%d %s\n", \
								__FILE__, __LINE__, #C), \
								kill(getpid(), SIGINT)))
#   endif // #ifdef _MSC_VER
#else
#   define ASSERT(C) 0
#endif // #ifdef _ENABLE_ASSERT

#ifdef ENABLE_ASSERT_LEVEL
#define ASSERT_LEVEL_CRITAL 30
#define ASSERT_LEVEL_INFO   20
#define ASSERT_LEVEL_DEBUG  10

/*
#define ASSERTP(C, P) do {\
	if ((P) >= ASSERT_LEVEL) {\
        ASSERT(C);\
    }} while(0)
	*/
#define ASSERTP(C, P) ASSERT((ASSERT_LEVEL>=(P))||(C))
#else
#define ASSERTP(C, P) 0
#endif

#ifdef ENABLE_CHECK
#ifdef __cplusplus
#include <sstream>
template<typename T>
inline T _check(T t, T c, char* FILE, long LINEN, char* LINE)
{
    if (t != c)
	{
		std::ostringstream ss;
		ss << FILE << ":" << LINEN << " " << LINE << " return " << t << std::endl;
		LOG(ss.str().c_str());
	}
	return t;
}
#define CHECK(LINE, C) _check((LINE), (C), __FILE__, __LINE__, #LINE)
#else
#ifdef _MSC_VER
#pragma message ("*** CHECK Need C++ Support")
#else
#warning "*** CHECK Need C++ Support"
#endif // _MSC_VER
#define CHECK(LINE, C) LINE
#endif // __cplusplus
#else
#define CHECK(LINE, C) LINE
#endif // ENABLE_CHECK
/*
#elif __GNUC__
#define CHECK(LINE, C) \
(__extension__  \
({  \
   typeof(C) __c=(LINE);   \
   (__c==(C))?__c:(LOG("%s:%d %s return %d\n", __FILE__, __LINE__, #LINE, __c), __c));\
}) \
) 
*/

#if defined(DEBUG) || defined(_DEBUG)
#define FOR_DEBUG(LINE) LINE
#else
#define FOR_DEBUG(LINE) 0
#endif

#ifdef ENABLE_TRACE
#define CODE_TRACE LOG("TRACE: %s:%s:%d\n", __FILE__, __FUNCTION__, __LINE__);
#else
#define CODE_TRACE 
#endif

#define DEBUG_BREAK __asm int 3
