#ifndef STRLNG_JIM_H
#define STRLNG_JIM_H

#include <stdlib.h>

#include "../strlng.h"

void* PKG_JIM_create        ();
void* PKG_JIM_objectBegin   ();
void* PKG_JIM_objectEnd     ();
void* PKG_JIM_arrayBegin    ();
void* PKG_JIM_arrayEnd      ();
void* PKG_JIM_memberKey     ();
void* PKG_JIM_float         ();
void* PKG_JIM_integer       ();
void* PKG_JIM_string        ();
void* PKG_JIM_write         ();

STRLNG_PKG_METHOD STRLNG_PKG_JIM[] = {
    {.name= "create",       .handler= &PKG_JIM_create},
    {.name= "objectBegin",  .handler= &PKG_JIM_objectBegin},
    {.name= "objectEnd",    .handler= &PKG_JIM_objectEnd},
    {.name= "arrayBegin",   .handler= &PKG_JIM_arrayBegin},
    {.name= "arrayEnd",     .handler= &PKG_JIM_arrayEnd},
    {.name= "memberKey",    .handler= &PKG_JIM_memberKey},
    {.name= "float",        .handler= &PKG_JIM_float},
    {.name= "integer",      .handler= &PKG_JIM_integer},
    {.name= "string",       .handler= &PKG_JIM_string},
    {.name= "write",        .handler= &PKG_JIM_write},
    STRLNG_PKG_END
};

#endif //STRLNG_JIM_H
