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

static inline size_t  Lexer_consume_symbol    (Lexer*);
static inline size_t  Lexer_consume_comment   (Lexer*);
static inline size_t  Lexer_consume_whitespace(Lexer*);
static inline size_t  Lexer_consume_string    (Lexer*);
static inline size_t  Lexer_consume_regexp    (Lexer*);
static inline size_t  Lexer_consume_numeral   (Lexer*);
static inline size_t  Lexer_consume_indent    (Lexer*);

static inline Token   Lexer_token_consumer    (Lexer*, Token_Type, size_t (*)(Lexer*));
static inline Token   Lexer_token_consumer_p  (Lexer*, Token_Type, size_t (*)(Lexer*));
static inline Token   Lexer_token_consumer_ps (Lexer*, Token_Type, size_t (*)(Lexer*));

Token   Lexer_next              (Lexer*);

#endif //STRLNG_LEXER_H
