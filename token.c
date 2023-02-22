#include <string.h>

#include "token.h"

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

const Token_Literal* Token_getLiteral(const char* text) {
    for (size_t i = 0; i < Token_Literals_size; ++i)
        if (*Token_Literals[i].text == *text)
            return &Token_Literals[i];
    return NULL;
}

const char* Token_Keywords[] = {

    // Runtime Operators
    "using", // using
    "debug", // debug
    "entry", // entrypoint
    "rtarg", // runtime argument
    "break", // break

    //
    // List Operators
    "split", // split
    "lines", // seperate all the lines  (equivalent to: split "\n")
    "words", // seperate all words      (equivalent to: split " ")
    "dupli", // duplicate

    //
    // String Operators
    "join", // Merge
    "subs", // substring
    "conc", // concat
    "CASE", // uppercase
    "Case", // mixed-case
    "case", // lowercase
    "loop", // Loop
    "pads", // pad start
    "padc", // pad center
    "pade", // pad end
    "part", // split
    "repl", // replace
    "trim", // trim
    "trms", // trim start
    "trme", // trim end
    "prfx", // prefix
    "sufx", // suffix (append)
    "base", // to String (base)

    // Number Operator
    "int",  // Parse int
    "flt",  // Parse float
    "len",  // Count
    "mod",  // Modulo
    "div",  // Division
    "add",  // Reduce List with addition
    "avg",  // Reduce List with average
    "and",  // Bitwise And
    "orr",  // Bitwise Or
    "xor",  // Bitwise XOr

    "\0",
};
#define Token_Keywords_size (sizeof(Token_Keywords)/sizeof(Token_Keywords[0]))

const char* Token_Type_Debug(Token_Type tt) {
    switch (tt) {
        case TOKEN_INVALID:
            return "[Invalid Token]";
        case TOKEN_EOF:
            return "[EOF]";
        case TOKEN_NEWLINE:
            return "[New Line]";
        case TOKEN_INDENT:
            return "[Tab]";
        case TOKEN_REFERENCE:
            return "[$Ref]";
        case TOKEN_FLAGS:
            return "[:Flags]";
        case TOKEN_RETURN:
            return "[<= Return]";
        case TOKEN_RETURN_SINGLE:
            return "[<- Return]";
        case TOKEN_SYMBOL:
            return "[Symbol]";
        case TOKEN_NUMBER:
            return "[Number]";
        case TOKEN_STRING_DELIM:
            return "[\"String delim]";
        case TOKEN_STRING_REF:
            return "[$ String ref]";
        case TOKEN_COMMNT_INLINE:
            return "[;Comment]";
        case TOKEN_COMMNT_MULTI_BEG:
            return "[TOKEN_COMMENT_MULTI_BEG]";
        case TOKEN_COMMNT_MULTI_END:
            return "[TOKEN_COMMENT_MULTI_END]";
        case TOKEN_COMMNT_DOC:
            return "[@Comment Doc]";
        case TOKEN_PREPRO_HASH:
            return "[#Preproc]";
        case TOKEN_REGEXP_DELIM:
            return "[/Regexp Delim]";
        case TOKEN_REGEXP_FLAGS:
            return "[/Regexp Flags]";
        case TOKEN_REGEXP_ESC:
            return "[\\Regexp Escape]";
    }
}