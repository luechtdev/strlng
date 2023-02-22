#include <ctype.h>

#ifndef STRLNG_H
#define STRLNG_H

typedef enum {
    STRLNG_TYPE_ANY = 0,
    STRLNG_TYPE_TXT,
    STRLNG_TYPE_LST,
    STRLNG_TYPE_NUM
} STRLNG_TYPE;

typedef void STRLNG_ANY;

typedef struct {
    char*  text;
    size_t size;
    struct STRLNG_CHUNK* next;
} STRLNG_CHUNK;

typedef struct {
    STRLNG_CHUNK*   text;
    STRLNG_CHUNK*   cursor;
} STRLNG_TEXT;

typedef struct {
    STRLNG_TEXT*    items;
    size_t          count;
} STRLNG_LIST;

typedef struct {
    STRLNG_TYPE     type;

} CONTEXT_VARIABLE;

typedef struct {
    char*           identifier;
    STRLNG_ANY*     value;
} STRLNG_ARGUMENT;

typedef struct {
    STRLNG_TEXT*    current;
//    char*           flags;
    ssize_t         exitCode;
} STRLNG_FUNCTION_SCOPE;

typedef struct {
} STRLNG_GLOBAL_SCOPE;


#endif //STRLNG_H
