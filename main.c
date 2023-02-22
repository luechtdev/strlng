#include <stdio.h>
#include <string.h>

#include "lexer.h"

#include "include/pcre2/pcre2.h.in"

int main() {

    const char *text = "#entry main; comment";
    const size_t len = strlen(text);

    Lexer l = Lexer_new(text, len);

    Token t;
    while ((t = Lexer_next(&l)).type) {

    }


    return 0;
}
