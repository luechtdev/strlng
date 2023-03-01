#ifndef STRLNG_DEBUG_H
#define STRLNG_DEBUG_H

#define DEBUG_USAGE()               fprintf(stdout, "STRONG USAGE")
#define DEBUG_NOPATH()              fprintf(stdout, "NO FILE SPECIFIED")

#define DEBUG_FILE_READING(path)    fprintf(stdout, "[Reading File]: %s\n", path)
#define DEBUG_FILE_ERROR()          fprintf(stderr, "[Error] Could not read file: %s", strerror(errno))

#define DEBUG_ANSI_ESC(n)           fprintf(stdout, "\x1b[%dm",n)


#endif //STRLNG_DEBUG_H
