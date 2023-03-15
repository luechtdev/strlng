#ifndef STRLNG_STRUTIL_H
#define STRLNG_STRUTIL_H

#include <stdlib.h>

inline size_t strcmp_n (const char* s1, const char* s2, const size_t n) {
    for (size_t i=0; i<n; i++)
        if (s1[n] != s2[n]) return 1;
    return 0;
}

inline size_t strcmp_d (const char* s1, const char* s2, const char delim) {
    int i = 0;
    while (s1[i] != delim) {
        if (s1[i] != s2[i]) return 1;
        i++;
    }
    return 0;
}

#endif //STRLNG_STRUTIL_H
