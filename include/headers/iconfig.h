/**
* Common header
* config.h
*
* Author: fengxing(annidy@gmail.com)
* Date: 2012-05-27
* First veriosn
*/
#pragma once

#define _LOG
#define FILE_LOG_NAME "log"

#define ENABLE_ASSERT
#define ENABLE_ASSERT
#define ENABLE_TRACE
#define ENABLE_ASSERT_LEVEL
#define ENABLE_CHECK
//#define ENABLE_DUMP

#define ASSERT_LEVEL ASSERT_LEVEL_INFO
#define _LOG_DEBUG

/////////////////////////////// Level Log ////////////////////////////////
#if defined(_LOG)
#define LOG(...) (iheader::log_console::instance().printf(__VA_ARGS__),\
				  iheader::log_file::instance().printf(__VA_ARGS__))
#else
#define LOG(...) (void*)0
#endif

#if	defined(_LOG_DEBUG) || defined(_LOG_INFO) || defined(_LOG_ERROR)
#define ELOG LOG
#else
#define ELOG(...) (void*)0
#endif

#if	defined(_LOG_DEBUG) || defined(_LOG_INFO)
#define ILOG LOG
#else
#define ILOG(...) (void*)0
#endif

#if	defined(_LOG_DEBUG)
#define DLOG LOG
#else
#define DLOG(...) (void*)0
#endif
//////////////////////////////////////////////////////////////////////////