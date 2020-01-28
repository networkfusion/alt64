//
// Copyright (c) 2019 The Altra64 project contributors
// See LICENSE file in the project root for full license information.
//

#include "version.h"
#include <stdio.h>
#include <stdlib.h>

const char* Altra64_GetVersionString(void)
{
    char *versionStr;
     
    int length = snprintf(0, 0, "%s.%s%s", ALTRA64_VERSION, OS_BUILD_VERSION, OS_DEBUG_VERSION);

    //assert(length >= 0); // TODO add proper error handling
    versionStr = malloc(sizeof(char) * (length + 1));
    snprintf(versionStr, length+1, "%s.%s%s", ALTRA64_VERSION, OS_BUILD_VERSION, OS_DEBUG_VERSION);
    return versionStr;

    //free(str);
}
