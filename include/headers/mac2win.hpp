/**
 * Common header
 * mac2win.h
 *
 * Author: fengxing(annidy@gmail.com)
 * Date: 2012-05-27
 * First veriosn
 */
#pragma once

#ifdef WIN32
#include <windows.h>
#else
#import <CoreFoundation/CoreFoundation.h>
#include <unistd.h>
#endif

#include <string>
#ifndef MAX_PATH
#define MAX_PATH 260
#endif

namespace iheader {
    

    /**
     *  Get the library abs path (include last '/' or '\')
     *
     *	@ret path
     */
    inline std::string get_module_path()
    {
        char module_path[MAX_PATH] = {0};
#ifdef WIN32
        if( GetModuleFileNameA( NULL, module_path, MAX_PATH ) )
        {
            for (int i = strlen(module_path); i > 0; i--)
            {
                if (module_path[i] == '\\')
                {
                    module_path[i+1] = '\0';
                    break;
                }
            }
        }
#else
        CFBundleRef bd = CFBundleGetMainBundle();
        CFURLRef url = CFBundleCopyBundleURL(bd);
        CFStringRef srf = CFURLCopyFileSystemPath(url, kCFURLPOSIXPathStyle);
        CFStringGetCString(srf, module_path, sizeof(module_path),kCFStringEncodingUTF8);
        strcat(module_path, "/");
#endif
        return module_path;
    }
    
    inline std::string get_user_name()
    {
        return getlogin();
    }

}