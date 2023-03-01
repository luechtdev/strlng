#ifndef STRLNG_FS_H
#define STRLNG_FS_H

#include "../strlng.h"

void* pkg_fs_open() {

}

STRLNG_PKG_METHOD STRLNG_PKG_FS[] = {
    {
        .name = "open",
        .handler = &pkg_fs_open
    }
};

#endif //STRLNG_FS_H
