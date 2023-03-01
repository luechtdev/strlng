#pragma once

#include <sys/types.h>

typedef enum {
    // General Tokens
        TOKEN_INVALID   = -1,
        TOKEN_EOF       =  0,
        TOKEN_NEWLINE,
        TOKEN_INDENT,
        TOKEN_WHITESPACE,

        TOKEN_REFERENCE,
        TOKEN_REFERENCE_PIPE,
        TOKEN_REFERENCE_PARENT,

        TOKEN_STREAM,

        TOKEN_FLAGS,
        TOKEN_RETURN,
        TOKEN_RETURN_SINGLE,
        TOKEN_SYMBOL,
        TOKEN_NUMBER,

    // String Tokens
        TOKEN_STRING = 100,
        TOKEN_STRING_DELIM,

    // Comment Tokens
        TOKEN_COMMNT_INLINE = 200,
        TOKEN_COMMNT_MULTI_BEG,
        TOKEN_COMMNT_MULTI_END,
        TOKEN_COMMNT_DOC,

    // Preprocessor Tokens
        TOKEN_PREPRO_SYMBOL = 300,

    // RegularExpression Tokens
        TOKEN_REGEXP = 1000,
        TOKEN_REGEXP_DELIM,
        TOKEN_REGEXP_FLAGS,
        TOKEN_REGEXP_ESC,

} Token_Type;

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

void Token_Type_Debug(Token);
void Token_Text_Debug(Token);
