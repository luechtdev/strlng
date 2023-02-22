#pragma once

#include <sys/types.h>

typedef enum {
    // General Tokens
        TOKEN_INVALID   = -1,
        TOKEN_EOF       =  0,
        TOKEN_NEWLINE,
        TOKEN_INDENT,
        TOKEN_REFERENCE,
        TOKEN_FLAGS,
        TOKEN_RETURN,
        TOKEN_RETURN_SINGLE,
        TOKEN_SYMBOL,
        TOKEN_NUMBER,

    // String Tokens
        TOKEN_STRING_DELIM = 10,
        TOKEN_STRING_REF,

    // Comment Tokens
        TOKEN_COMMNT_INLINE = 20,
        TOKEN_COMMNT_MULTI_BEG,
        TOKEN_COMMNT_MULTI_END,
        TOKEN_COMMNT_DOC,

    // Preprocessor Tokens
        TOKEN_PREPRO_HASH = 30,


    // RegularExpression Tokens
        TOKEN_REGEXP_DELIM = 100,
        TOKEN_REGEXP_FLAGS,
        TOKEN_REGEXP_ESC,

} Token_Type;

const char* Token_Type_Debug(Token_Type);

typedef struct {
    Token_Type  type;
    const char* text;
} Token_Literal;

const Token_Literal* Token_getLiteral(const char* text);

typedef struct {
    Token_Type type;
    char*      text;
    size_t     size;
} Token;

