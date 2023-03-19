#ifndef STRLNG_DEBUG_H
#define STRLNG_DEBUG_H

//typedef enum {
//    DEBUG_ANSI_DISABLE  = 0,
//    DEBUG_ANSI_ENABLE   = 1,
//} DEBUG_ANSI_MODE_T;

int DEBUG_ANSI_MODE = 1;

#define DEBUG_ANSI_ESC(n)           fprintf(stdout, "\x1b[%dm",n)

#define DEBUG_MSG(type, tag, msg)   fprintf(stdout, "%s %s: %s", type, tag, msg)
#define DEBUG_TYPE(type, c)         (DEBUG_ANSI_MODE) ? ("\x1b["c"m["type"]\x1b[0m") : ("["type"]")
#define DEBUG_TAG(tag, c)           (DEBUG_ANSI_MODE) ? ("\x1b["c"m#"tag"\x1b[0m")   : ("#"tag)

#define DEBUG_USAGE()               fprintf(stdout, "STRONG USAGE")
#define DEBUG_NOPATH()              fprintf(stdout, "NO FILE SPECIFIED")

#define DEBUG_FILE_READING(path)    fprintf(stdout, "[Debug] #IO: Reading file '%s'\n", path)
#define DEBUG_FILE_BUFFER(x,y)      fprintf(stdout, "[Debug] #IO: %zu buffer filled (+%zu)\n", x, y)
#define DEBUG_FILE_READ(n)          fprintf(stdout, "[Debug] #IO: Read %zu lines. \n", n)
#define DEBUG_FILE_ERROR()          fprintf(stderr, "[Error] #IO: Could not read file: %s\n", strerror(errno))


#endif //STRLNG_DEBUG_H
