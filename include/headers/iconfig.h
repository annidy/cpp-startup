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

#define LOG(...) (log_console::instance().printf(__VA_ARGS__),\
				  log_file::instance().printf(__VA_ARGS__))
