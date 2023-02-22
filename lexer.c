#include "lexer.h"
#include <ctype.h>

Lexer Lexer_new(const char* text, const size_t size) {
    return (Lexer) {
        .text = text,
        .size = size,
        .line = 0,
        .curs = (char*) text,
        .boln = (char*) text,
        .type = LEXER_MODE_PROGRM
    };
}

size_t Lexer_getSymbolSize(char* start) {
    size_t size = 0;
    while (isalnum(*start++)) size++;
    return size;
}

Token Lexer_next(Lexer* l) {
    char* token_pos = l->curs;

    // End of File
    if (*l->curs == '\0') {
        return (Token){
            .type = TOKEN_EOF,
            .size = 0,
            .text = token_pos
        };
    }

    // Newline Token
    if (*l->curs == '\n') {
        l->curs++;
        l->line++;
        l->boln = l->curs;
        return (Token){
            .type = TOKEN_NEWLINE,
            .size = 1,
            .text = token_pos
        };
    }




//    if (l->type == LEXER_MODE_PROGRM) return Lexer_next_progrm(l);
//    if (l->type == LEXER_MODE_COMMNT) return Lexer_next_commnt(l);

    l->curs++;
    return (Token){
        .type = TOKEN_INVALID,
        .size = 1,
        .text = token_pos
    };

}
//
//Token Lexer_next_progrm(Lexer* l) {
//    char* token_pos = l->curs;
//
//    // Prepro Instruction
//    if (*l->curs == '#') {
//        l->curs++;
//        return (Token){
//            .type = TOKEN_PREPRO_HASH,
//            .text = token_pos,
//            .size = 1
//        };
//    }
//
//    if (*l->curs == ';') {
//
//    }
//
//}
//
//
//
//Token Lexer_next_commnt(Lexer* l) {
//    Token result;
//    return result;
//}
//
//Token Lexer_next_string(Lexer* l) {
//    Token result;
//    return result;
//}
//
//Token Lexer_next_regexp(Lexer* l) {
//    Token result;
//    return result;
//}