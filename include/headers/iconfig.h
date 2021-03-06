/**
* Common header
* config.h
*
* Author: fengxing(annidy@gmail.com)
* Date: 2012-05-27
* First veriosn
*/
#pragma once

////////////////////////////// Level Assert ///////////////////////////////
//#define ENABLE_ASSERT
//#define ENABLE_TRACE
//#define ENABLE_ASSERT_LEVEL
//#define ENABLE_CHECK
//#define ENABLE_DUMP

#define ASSERT_LEVEL ASSERT_LEVEL_INFO

/////////////////////////////// Level Log ////////////////////////////////
#if	defined(_LOG_DEBUG) || defined(_LOG_INFO) || defined(_LOG_ERROR)
#define _LOG
#endif

#if defined(_LOG)
#define LOG_SET(a,b) iheader::log_file::instance().reopen((a), (b))
#define LOG(...) (iheader::log_console::instance().printf(__VA_ARGS__),\
				  iheader::log_file::instance().printf(__VA_ARGS__))
#else
#define LOG_SET(a,b) 0
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