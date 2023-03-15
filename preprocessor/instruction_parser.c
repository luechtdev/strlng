#include "instruction_parser.h"

#include <stdlib.h>
#include <stdio.h>

inline InstructionParser InstructionParser_new(Token** lines) {
    return (InstructionParser) {
        .lines = lines,
        .curs  = lines,
    };
}

//// CONSUMER ////

static inline size_t InstructionParser_consume_prepro(Token** line) {

}

//// PARSER ////

Instruction InstructionParser_next(InstructionParser* ip) {

    Token* curt = *ip->curs;

    if (curt->type == TOKEN_PREPRO_SYMBOL) {
        size_t count = InstructionParser_consume_prepro(&curt);
        return (Instruction) {
            .argv = curt,
            .argc = count,
            .type = PREPRO_INSTRUCTION
        };
    }

    fprintf(stderr, "[Error] #IP: Could not parse instruction in line %d\n", ip->curs - ip->lines);
    fprintf(stderr, "InstructionParser Found: ");
    Token_Type_Debug(*curt);


    ip->curs++;
    return (Instruction) {
        .type = UNKNWN_INSTRUCTION,
        .argv = curt,
        .argc = 0,
        .handler = NULL
    };
}