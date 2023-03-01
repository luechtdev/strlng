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

Lexer   Lexer_new               (const char*, size_t);

size_t  Lexer_consume_symbol    (Lexer*);
size_t  Lexer_consume_comment   (Lexer*);
size_t  Lexer_consume_whitespace(Lexer*);
size_t  Lexer_consume_string    (Lexer*);
size_t  Lexer_consume_regexp    (Lexer*);
size_t  Lexer_consume_numeral   (Lexer*);
size_t  Lexer_consume_indent    (Lexer*);

Token   Lexer_token_consumer    (Lexer*, Token_Type, size_t (*)(Lexer*));
Token   Lexer_token_consumer_p  (Lexer*, Token_Type, size_t (*)(Lexer*));

Token   Lexer_next              (Lexer*);

#endif //STRLNG_LEXER_H
