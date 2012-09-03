/**
 * Common header
 * log.h
 *
 * Author: fengxing(annidy@gmail.com)
 * Date: 2012-05-27
 * First veriosn
 */
#pragma once
#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include "iconfig.h"

#ifdef _LOG
#define LOG_INTERfACE virtual
#else
#define LOG_INTERfACE
#endif

#ifdef FILE_LOG_TRUNC
#define FILE_LOG_MODE "w+"
#else
#define FILE_LOG_MODE "a+"
#endif

// -------------------------------------------------------------------------------------------
#ifdef __cplusplus

namespace iheader
{
    
class log
{
public:
    static log& instance();
    LOG_INTERfACE void printf(const char *format, ...) {}
    LOG_INTERfACE void dump(const char *buffer, size_t size) {}

private:
    static log *_instance;

protected:
	log() {};
    LOG_INTERfACE ~log() {};
};

#ifndef _LOG
inline log& log::instance()
{
    return *(static_cast<log*>(0));
}
#endif // _LOG


// -------------------------------------------------------------------------------------------
class log_file : log 
{
public:
    void printf(const char *format, ...);
    void dump(const char *buffer, size_t size);
    static log& instance();

private:
    FILE *_file;
    static log_file *_instance;

protected:
    log_file();
    LOG_INTERfACE ~log_file();
};

inline log& log_file::instance()
{
    if (!_instance)
    {
        static log_file obj;
        _instance = &obj;
    }	// FIXME: The dead reference problem, Modern C++ Design, P118
    return *_instance;
}

inline log_file::log_file()
{
    _file = fopen(FILE_LOG_NAME, "w+");
    if (!_file)
    {
        char fn[30];
        time_t rawtime;
        struct tm * timeinfo;

        time ( &rawtime );
        timeinfo = localtime ( &rawtime );
        sprintf(fn, "%04d%02d%02d%02d%02d%02d.log", timeinfo->tm_year, \
                timeinfo->tm_mon, timeinfo->tm_mday, timeinfo->tm_hour, \
                timeinfo->tm_min, timeinfo->tm_sec);
        _file = fopen(fn, FILE_LOG_MODE);
    }
}

inline log_file::~log_file()
{
    fclose(_file);
}

inline void log_file::printf(const char* format, ...)
{
    va_list argptr;
    va_start(argptr, format);
    vfprintf(_file, format, argptr);
    fflush(_file);
    va_end(argptr);
}

inline void log_file::dump(const char *buffer, size_t size)
{
    fwrite(buffer, 1, size, _file);
    fflush(_file);
}


// -------------------------------------------------------------------------------------------
class log_console : public log 
{
public:
    void printf(const char *format, ...);
    void dump(const char *buffer, size_t size);
    static log& instance();

private:
    static log_console *_instance;

protected:
	log_console() {}
	LOG_INTERfACE ~log_console() {}
};

inline log& log_console::instance()
{
    if (!_instance)
    {
        static log_console obj;
        _instance = &obj;
    }
    return *_instance;
}

inline void log_console::printf(const char* format, ...)
{
    va_list argptr;
    va_start(argptr, format);
    vfprintf(stderr, format, argptr);
    fflush(stderr);
    va_end(argptr);
}

inline void log_console::dump(const char *buffer, size_t size)
{
    fwrite(buffer, 1, size, stderr);
    fflush(stderr);
}
    
}      // namespace iheader
#else

#if defined(_LOG) && defined(LOG)
#ifdef _MSC_VER
#pragma message ("*** LOG Need C++ Support")
#else
#warning "*** LOG Need C++ Support"
#endif // _MSC_VER
#undef LOG
#define LOG(...) (void*)0
#endif // defined(_LOG) && defined(LOG)
#endif // #ifdef __cplusplus
