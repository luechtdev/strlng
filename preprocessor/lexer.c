#include "lexer.h"
#include <ctype.h>

inline Lexer Lexer_new(const char* text, const size_t size) {
    return (Lexer) {
        .text = text,
        .size = size,
        .line = 0,
        .curs = (char*) text,
        .boln = (char*) text,
        .type = LEXER_MODE_PROGRM
    };
}

inline size_t Lexer_consume_symbol(Lexer* l) {
    size_t length = 0;
    while (isalnum(*l->curs) || *l->curs == '_') {
        length++;
        *l->curs++;
    }
    return length;
}

inline size_t Lexer_consume_comment(Lexer* l) {
    size_t length = 0;
    while (*l->curs != '\n' && *l->curs != '\0') {
        length++;
        l->curs++;
    }
    return length;
}

inline size_t Lexer_consume_string(Lexer* l) {
    size_t length = 0;
    while (*l->curs != '"' && *l->curs != '\0') {
        length++;
        l->curs++;
    }
    if (*l->curs) {
        length++;
        l->curs++;
    }
    return length;
}

inline size_t Lexer_consume_regexp(Lexer* l) {
    size_t length = 0;
    while (*l->curs != '/' && *l->curs != '\0') {
        length++;
        l->curs++;
    }
    if (*l->curs) {
        length++;
        l->curs++;
    }
    return length;
}



inline size_t Lexer_consume_numeral(Lexer* l) {
    size_t length = 0;
    while (isdigit(*l->curs)) {
        l->curs++;
        length++;
    }
    return length;
}

inline size_t Lexer_consume_indent(Lexer* l) {
    size_t length = 0;
    while (*l->curs == '\t') {
        length++;
        l->curs++;
    }
    return length;
}

inline size_t Lexer_consume_whitespace(Lexer* l) {
    size_t length = 0;
    while (isspace(*l->curs)) {
        length++;
        l->curs++;
    }
    return length;
}

inline Token Lexer_token_consumer (Lexer *l, const Token_Type type, size_t (*consumer)(Lexer*)) {
    char* token_pos = l->curs;
    size_t length = (*consumer)(l);
    return (Token) {
        .type = type,
        .size = length,
        .text = token_pos
    };
}

inline Token Lexer_token_consumer_p (Lexer* l, Token_Type type, size_t (*consumer)(Lexer*)) {
    char* token_pos = l->curs;
    l->curs++;
    size_t length = (*consumer)(l);
    return (Token) {
        .type = type,
        .size = ++length,
        .text = token_pos
    };
}

Token Lexer_next(Lexer* l) {
    char* token_pos = l->curs;

    // End of File
    if (*l->curs == '\0') {
        return (Token) {
            .type = TOKEN_EOF,
            .size = 0,
            .text = token_pos
        };
    }

    // Newline Token
    if (*l->curs == '\n') {
        l->curs++; l->line++;
        l->boln = l->curs;
        return (Token) {
            .type = TOKEN_NEWLINE,
            .size = 1,
            .text = token_pos
        };
    }

    // Indentation
    if (*l->curs == '\t' && l->curs == l->boln) {
        return Lexer_token_consumer(l, TOKEN_INDENT, &Lexer_consume_indent);
    }

    // Inline Comment
    if (*l->curs == ';') {
        return Lexer_token_consumer(l, TOKEN_COMMNT_INLINE, &Lexer_consume_comment);
    }

    // String
    if (*l->curs == '"') {
        return Lexer_token_consumer_p(l, TOKEN_STRING, &Lexer_consume_string);
    }

    // Regular Expression
    if (*l->curs == '/') {
        return Lexer_token_consumer_p(l, TOKEN_REGEXP, &Lexer_consume_regexp);
    }

    // Streams
    if (*l->curs == '@') {
        return Lexer_token_consumer_p(l, TOKEN_STREAM, &Lexer_consume_symbol);
    }


    // Preproc Symbol
    if (*l->curs == '#') {
        return Lexer_token_consumer_p(l, TOKEN_PREPRO_SYMBOL, &Lexer_consume_symbol);
    }

    // Reference
    if (*l->curs == '$') {

        // Reference to pipe "$$"
        if (l->curs[1] == '$') {
            l->curs += 2;
            return (Token) {
                .text = token_pos,
                .type = TOKEN_REFERENCE_PIPE,
                .size = 2
            };
        }

        // Reference to parent
        if (l->curs[1] == '^') {
            l->curs += 2;
            return (Token) {
                .text = token_pos,
                .type = TOKEN_REFERENCE_PARENT,
                .size = 2
            };
        }

        // Reference to variable
        return Lexer_token_consumer_p(l, TOKEN_REFERENCE, &Lexer_consume_symbol);
    }

    // Whitespace
    if (isspace(*l->curs)) {
        return Lexer_token_consumer(l, TOKEN_WHITESPACE, &Lexer_consume_whitespace);
    }

    // Symbol
    if (isalpha(*l->curs)) {
        return Lexer_token_consumer(l, TOKEN_SYMBOL, &Lexer_consume_symbol);
    }

    // Number
    if (isdigit(*l->curs)) {
        return Lexer_token_consumer(l, TOKEN_NUMBER, &Lexer_consume_numeral);
    }

    // Flags
    if (*l->curs == ':' && isalpha(l->curs[1])) {
        return Lexer_token_consumer_p(l, TOKEN_FLAGS, &Lexer_consume_symbol);
    }

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