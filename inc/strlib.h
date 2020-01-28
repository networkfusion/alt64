//
// Copyright (c) 2017 The Altra64 project contributors
// Portions (c) 2013 saturnu (Alt64) based on libdragon, Neo64Menu, ED64IO, libn64-hkz, libmikmod
// See LICENSE file in the project root for full license information.
//

#ifndef _STRLIB_H
#define	_STRLIB_H

#include "types.h"
#include <stddef.h>
#include <ctype.h> // for `tolower()`
#include <limits.h> // for `INT_MIN`

enum strtrim_mode_t {
    STRLIB_MODE_ALL       = 0, 
    STRLIB_MODE_RIGHT     = 0x01, 
    STRLIB_MODE_LEFT      = 0x02, 
    STRLIB_MODE_BOTH      = 0x03
};

char *strcpytrim(char *d, // destination
                 char *s, // source
                 int mode,
                 const char *delim
                 );

char *strtriml(char *d, char *s);
char *strtrimr(char *d, char *s);
char *strtrim(char *d, char *s); 
char *strstrlibkill(char *d, char *s);

char *triml(char *s);
char *trimr(char *s);
char *trim(char *s);
char *strlibkill(char *s);

void strhicase(u8 *str, u8 len);
u16 strcon(u8 *str1, u8 *str2, u8 *dst, u16 max_len);
u8 slen(u8 *str);
u8 scopy(u8 *src, u8 *dst);

u8 streq(u8 *str1, u8 *str2);
u8 streql(u8 *str1, u8 *str2, u8 len);

u16 strContain(u8 *target, u8 *str);

static inline int strncmpci(const char * str1, const char * str2, size_t num);

/*

    Case-insensitive string compare (strncmp case-insensitive)
    - Identical to strncmp except case-insensitive. See: http://www.cplusplus.com/reference/cstring/strncmp/
    - Aided/inspired, in part, by: https://stackoverflow.com/a/5820991/4561887

    str1    C string 1 to be compared
    str2    C string 2 to be compared
    num     max number of chars to compare

    return:
    (essentially identical to strncmp)
    INT_MIN  invalid arguments (one or both of the input strings is a NULL pointer)
    <0       the first character that does not match has a lower value in str1 than in str2
    0       the contents of both strings are equal
    >0       the first character that does not match has a greater value in str1 than in str2

    */
    static inline int strncmpci(const char * str1, const char * str2, size_t num)
    {
        int ret_code = INT_MIN;

        size_t chars_compared = 0;

        // Check for NULL pointers
        if (!str1 || !str2)
        {
            goto done;
        }

        // Continue doing case-insensitive comparisons, one-character-at-a-time, of str1 to str2, 
        // as long as at least one of the strings still has more characters in it, and we have
        // not yet compared num chars.
        while ((*str1 || *str2) && (chars_compared < num))
        {
            ret_code = tolower((int)(*str1)) - tolower((int)(*str2));
            if (ret_code != 0)
            {
                // The 2 chars just compared don't match
                break;
            }
            chars_compared++;
            str1++;
            str2++;
        }

    done:
        return ret_code;
    }

#endif
