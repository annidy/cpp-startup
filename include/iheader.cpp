#include "iheader.h"
using namespace iheader;
//DECLARE_MINIDUMP
//REGIST_MINIDUMP

#ifdef _LOG
char log_file::log_name[128] = {0};
log_file* log_file::_instance = 0;
log_console* log_console::_instance = 0;
#endif
