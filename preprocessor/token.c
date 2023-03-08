#include <string.h>
#include <stdio.h>

#include "token.h"
#include "../debug.h"

const Token_Literal Token_Literals_RegExp[] = {
    {.text="\\", .type=TOKEN_REGEXP_ESC},
    {.text="\\", .type=TOKEN_REGEXP_ESC},
    {.text="\\", .type=TOKEN_REGEXP_ESC},
};
#define Token_Literals_RegExp_size (sizeof(Token_Literals_RegExp)/sizeof(Token_Literals_RegExp[0]))

const Token_Literal Token_Literals[] = {
    {.text="$", .type=TOKEN_REFERENCE},
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

void Token_Type_Debug(Token t) {
    switch (t.type) {
        case TOKEN_INVALID:
            printf("[Invalid Token]: '%c'\n", *t.text);
            return;

        case TOKEN_EOF:
            printf("\x1b[31m[EOF]\x1b[0m\n");
            return;

        case TOKEN_NEWLINE:
            printf("[New Line]\n\n");
            return;

        case TOKEN_INDENT:
            printf("[Tab] x%d\n", t.size);
            return;

        case TOKEN_WHITESPACE:
            printf("[Whitespace] x%d\n", t.size);
            return;


        case TOKEN_REFERENCE:
            printf("[$Ref]\n");
            return;

        case TOKEN_FLAGS:
            printf("[:Flags] '%.*s'\n", t.size, t.text);
            return;

        case TOKEN_RETURN:
            printf("[<= Return]\n");
            return;

        case TOKEN_RETURN_SINGLE:
            printf("[<- Return]\n");
            return;

        case TOKEN_SYMBOL:
            printf("[Symbol] '%.*s'\n", t.size, t.text);
            return;

        case TOKEN_NUMBER:
            printf("[Number] '%.*s'\n", t.size, t.text);
            return;

        case TOKEN_COMMNT_INLINE:
            printf("[;Comment] '%.*s'\n", t.size, t.text);
            return;

        case TOKEN_COMMNT_MULTI_BEG:
            printf("[TOKEN_COMMENT_MULTI_BEG]\n");
            return;

        case TOKEN_COMMNT_MULTI_END:
            printf("[TOKEN_COMMENT_MULTI_END]\n");
            return;

        case TOKEN_COMMNT_DOC:
            printf("[@Comment Doc]\n");
            return;

        case TOKEN_PREPRO_SYMBOL:
            printf("[#Preproc] %.*s'\n", t.size, t.text);
            return;

        case TOKEN_REGEXP_DELIM:
            printf("[/Regexp Delim]\n");
            return;

        case TOKEN_REGEXP_FLAGS:
            printf("[/Regexp Flags]\n");
            return;

        case TOKEN_REGEXP_ESC:
            printf("[\\Regexp Escape]\n");
            return;

        default:
            printf("[UNKNOWN TOKEN]\n");
            return;
    }
}

void Token_Text_Debug(Token t) {
    switch (t.type) {

        case TOKEN_SYMBOL:
            DEBUG_ANSI_ESC(42);
            break;

        case TOKEN_STRING:
            DEBUG_ANSI_ESC(32);
            break;

        case TOKEN_REGEXP:
        case TOKEN_STREAM:
            DEBUG_ANSI_ESC(31);
            break;

        case TOKEN_INVALID:
            DEBUG_ANSI_ESC(41);
            break;

        case TOKEN_PREPRO_SYMBOL:
            DEBUG_ANSI_ESC(46);
            break;

        case TOKEN_COMMNT_INLINE:
            DEBUG_ANSI_ESC(37);
            break;

        case TOKEN_REFERENCE:
            DEBUG_ANSI_ESC(33);
            break;

        case TOKEN_PACKAGE:
        case TOKEN_REFERENCE_PIPE:
        case TOKEN_REFERENCE_PARENT:
            DEBUG_ANSI_ESC(43);
            break;

        case TOKEN_FLAGS:
            DEBUG_ANSI_ESC(95);
            break;

        default:
            break;
    }

    fprintf(stdout, "%.*s\x1b[0m", (int) t.size, t.text);

}