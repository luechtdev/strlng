#include "token.h"
#include <sys/types.h>

#ifndef STRLNG_LEXER_H
#define STRLNG_LEXER_H

typedef enum {
    LEXER_MODE_PROGRM, // While tokenizing the program
    LEXER_MODE_STRING, // While reading a string
    LEXER_MODE_REGEXP, // While reading a RegExp
    LEXER_MODE_COMMNT, // While reading a string
} LexerMode;

typedef struct {
    const char*  text;
    const size_t size;
    size_t       line;
    char*        boln;
    char*        curs;
    LexerMode    type;
} Lexer;

Lexer Lexer_new(const char*, size_t);

Token Lexer_next(Lexer*);
Token Lexer_next_progrm(Lexer*);
Token Lexer_next_commnt(Lexer*);
Token Lexer_next_string(Lexer*);
Token Lexer_next_regexp(Lexer*);

#endif //STRLNG_LEXER_H
