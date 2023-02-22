#include "token.h"

typedef struct {
    Token_Type  type;
    const char* text;
} Token_Literal;

const Token_Literal Token_Literals_RegExp[] = {
    {.text="\\", .type=TOKEN_REGEXP_ESC},
    {.text="\\", .type=TOKEN_REGEXP_ESC},
    {.text="\\", .type=TOKEN_REGEXP_ESC},
};
#define Token_Literals_RegExp_size (sizeof(Token_Literals_RegExp)/sizeof(Token_Literals_RegExp[0]))

const Token_Literal Token_Literals[] = {
    {.text="$", .type=TOKEN_REFERENCE},
    {.text=":", .type=TOKEN_FLAGS},

    {.text=";", .type=TOKEN_COMMNT_INLINE},
    {.text="@", .type=TOKEN_COMMNT_INLINE},

    {.text="\"",.type=TOKEN_STRING_DELIM},

    {.text="/", .type=TOKEN_REGEXP_DELIM},
};
#define Token_Literals_size (sizeof(Token_Literals)/sizeof(Token_Literals[0]))

Token_Literal* Token_getLiteral() {
    return (void*)0;
}

const char* Token_Keywords[] = {

    // Runtime Operators
    "using", // using
    "debug", // debug
    "entry", // entrypoint
    "rtarg", // runtime argument
    "lglvl", // loglevel
    "break", // break

    // List Operators
    "merge", // merge
    "split", // split
    "dupli", // duplicate
    "count", // count

    // String Operators
    "subs", // substring
    "conc", // concat
    "loop", // repeat
    "CASE", // uppercase
    "Case", // mixed-case
    "case", // lowercase
    "pads", // pad start
    "padc", // pad center
    "pade", // pad end
    "repl", // replace
    "trim", // trim
    "trms", // trim start
    "trme", // trim end
    "prfx", // prefix
    "sufx", // suffix (append)
    "size", // length

    // Number Operator
    "mod",
    "div",
    "and",
    "orr",
    "xor",

    "\0",
};
#define Token_Keywords_size (sizeof(Token_Keywords)/sizeof(Token_Keywords[0]))