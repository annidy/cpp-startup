#include "headers/iconfig.h"

//DECLARE_MINIDUMP
//REGIST_MINIDUMP

#ifdef _LOG
#include "headers/ilog.h"
log* log_file::_instance = 0;
log* log_console::_instance = 0;
#endif