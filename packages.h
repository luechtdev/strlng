#ifndef STRLNG_PACKAGES_H
#define STRLNG_PACKAGES_H

#include "strlng.h"

#include "packages/fs.h"
#include "packages/jim.h"

STRLNG_PKG PACKAGES[] = {
    {.name= "fs",   .methods= STRLNG_PKG_FS},
    {.name= "jim",  .methods= STRLNG_PKG_JIM}
};
#define PACKAGES_COUNT (sizeof (PACKAGES) / sizeof (STRLNG_PKG_FS))

#endif //STRLNG_PACKAGES_H
