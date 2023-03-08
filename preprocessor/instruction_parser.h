#ifndef STRLNG_INSTRUCTION_PARSER_H
#define STRLNG_INSTRUCTION_PARSER_H

#include "token.h"

typedef enum {
    UNKNWN_INSTRUCTION = 0,
    PREPRO_INSTRUCTION,
    STRING_INSTRUCTION,
    NUMBER_INSTRUCTION,
    ITRABL_INSTRUCTION,
    PACKAG_INSTRUCTION
} InstructionType;

typedef struct {
    Token**     lines;
    Token**     curs;
} InstructionParser;

typedef struct {
    size_t      argc;
    Token**     argv;
    void (*handler)();
} Instruction;

inline InstructionParser InstructionParser_new(Token**);

Instruction InstructionParser_next(InstructionParser*);

#endif //STRLNG_INSTRUCTION_PARSER_H
