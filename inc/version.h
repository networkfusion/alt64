//
// Copyright (c) 2017 The Altra64 project contributors
// See LICENSE file in the project root for full license information.
//

#ifndef _VERSION_H
#define _VERSION_H

#define ALTRA64_VERSION "0.1.8.6.1.4"

#ifndef OS_BUILD_VERSION
  #define OS_BUILD_VERSION "0"  //populate from CI-CD pipeline Version
#endif
#ifndef DEBUG //populate from makefile
  #define OS_DEBUG_VERSION ""  
#else
  #define OS_DEBUG_VERSION "-DBG"
#endif

const char* Altra64_GetVersionString(void);

#endif
