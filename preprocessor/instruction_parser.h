#ifndef STRLNG_INSTRUCTION_PARSER_H
#define STRLNG_INSTRUCTION_PARSER_H

#include "token.h"

typedef struct {

} InstructionParser;

typedef struct {
    size_t      argc;

} Instruction;

inline InstructionParser InstructionParser_new(Token**);


#endif //STRLNG_INSTRUCTION_PARSER_H
