#ifndef STRLNG_DEBUG_H
#define STRLNG_DEBUG_H

#define DEBUG_USAGE()               fprintf(stdout, "STRONG USAGE")
#define DEBUG_NOPATH()              fprintf(stdout, "NO FILE SPECIFIED")

#define DEBUG_FILE_READING(path)    fprintf(stdout, "[Debug] #IO: Reading file '%s'\n", path)
#define DEBUG_FILE_BUFFER(x,y)      fprintf(stdout, "[Debug] #IO: %d buffer filled (+%d)\n", x, y)
#define DEBUG_FILE_READ(n)          fprintf(stdout, "[Debug] #IO: Read %d lines. \n", n)
#define DEBUG_FILE_ERROR()          fprintf(stderr, "[Error] #IO: Could not read file: %s\n", strerror(errno))

#define DEBUG_ANSI_ESC(n)           fprintf(stdout, "\x1b[%dm",n)


#endif //STRLNG_DEBUG_H
