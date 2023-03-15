#ifndef STRLNG_FN_PREPRO_H
#define STRLNG_FN_PREPRO_H

#include <stdlib.h>
#include <string.h>

#include "../strlng.h"
#include "../utils/strutil.h"

#define IHANDLE_COMMANDNAME(x) if (strcmp_n(argv[0].text, x, 5))
#define IHANDLE_FLAGS(x)       if (strcmp_d(flgs, x, ' '))

void FN_PREPRO_using    (STRLNG_FUNCTION_SCOPE*, STRLNG_GLOBAL_SCOPE*);

void FN_PREPRO_rtarg    (STRLNG_FUNCTION_SCOPE*, STRLNG_GLOBAL_SCOPE*);
void FN_PREPRO_rtarg_o  (STRLNG_FUNCTION_SCOPE*, STRLNG_GLOBAL_SCOPE*);
void FN_PREPRO_rtarg_l  (STRLNG_FUNCTION_SCOPE*, STRLNG_GLOBAL_SCOPE*);
void FN_PREPRO_rtarg_s  (STRLNG_FUNCTION_SCOPE*, STRLNG_GLOBAL_SCOPE*);

void FN_PREPRO_entry    (STRLNG_FUNCTION_SCOPE*, STRLNG_GLOBAL_SCOPE*);
void FN_PREPRO_entry_a  (STRLNG_FUNCTION_SCOPE*, STRLNG_GLOBAL_SCOPE*);

void FN_PREPRO_debug    (STRLNG_FUNCTION_SCOPE*, STRLNG_GLOBAL_SCOPE*);

void FN_PREPRO_const    (STRLNG_FUNCTION_SCOPE*, STRLNG_GLOBAL_SCOPE*);

void* FN_PREPRO_IHANDLER(Token* argv, size_t argc, char* flgs) {

    IHANDLE_COMMANDNAME("using") {
        return &FN_PREPRO_using;
    }

    IHANDLE_COMMANDNAME("rtarg") {
        IHANDLE_FLAGS("o") return &FN_PREPRO_rtarg_o; // Optional
        IHANDLE_FLAGS("l") return &FN_PREPRO_rtarg_l; // Long
        IHANDLE_FLAGS("s") return &FN_PREPRO_rtarg_s; // Short
        return &FN_PREPRO_rtarg;
    }

    IHANDLE_COMMANDNAME("entry") {
        return &FN_PREPRO_entry;
    }

    IHANDLE_COMMANDNAME("debug") {
        return &FN_PREPRO_debug;
    }

    IHANDLE_COMMANDNAME("const") {
        return &FN_PREPRO_const;
    }

    return NULL;
}

#endif //STRLNG_FN_PREPRO_H
