//#pragma pack(1)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <getopt.h>

#include "preprocessor/lexer.h"
#include "preprocessor/instruction_parser.h"

#include "strlng.h"
#include "debug.h"

#define SCRIPT_BUFFER_SIZE 32
#define SCRIPT_BUFFER_BLOCK_SIZE (SCRIPT_BUFFER_SIZE * sizeof (char))

#define RT_VERBOSEONLY if (RT_mode_verbs)

int main(const int argc, const char** argv) {

    // If no args are supplied, show usage
    if (argc <= 1) {
        DEBUG_USAGE();
        return EXIT_SUCCESS;
    }

    // Check for special mode

    const int RT_mode_debug = strcmp(argv[1], "debug") == 0;
    const int RT_mode_token = strcmp(argv[1], "token") == 0;
    const int RT_mode_verbs = strcmp(argv[1], "verbose") == 0;

    const int RT_modeSelector = RT_mode_debug
            + RT_mode_token
            + RT_mode_verbs;

    // Return if only a mode is selected
    if (argc <= RT_modeSelector + 1) {
        DEBUG_NOPATH();
        return EXIT_FAILURE;
    }

    // Trimming of the mode selector
    // and parsing the other args to the runtime
    const int    RT_argc     = argc - 1 - RT_modeSelector;
    const char** RT_argv     = &argv [1 + RT_modeSelector];
    const char*  filePath = *RT_argv;

    //// Open file stream ////

    FILE* script;

    if ((script = fopen(filePath,"r")) == NULL) {
        DEBUG_FILE_ERROR();
        return errno;
    }

    RT_VERBOSEONLY DEBUG_FILE_READING(filePath);

    //// Read file to Buffer ////

    char*  script_buffer         = NULL;
    size_t script_buffer_block   = 0;
    size_t script_buffer_written;

    do {
        script_buffer = realloc(script_buffer, SCRIPT_BUFFER_BLOCK_SIZE * ++script_buffer_block);
        char* offset = &script_buffer[SCRIPT_BUFFER_SIZE * (script_buffer_block - 1)];
        memset(offset, 0, SCRIPT_BUFFER_BLOCK_SIZE);
        script_buffer_written = fread(offset, sizeof (char), SCRIPT_BUFFER_SIZE, script);
    } while(script_buffer_written == SCRIPT_BUFFER_SIZE);

    fclose(script);
    RT_VERBOSEONLY DEBUG_FILE_BUFFER(script_buffer_block, script_buffer_written);

    //// Lexing / Tokenizing ////

    const size_t len = strlen(script_buffer);

    Lexer l = Lexer_new(script_buffer, len);

    Token   t;
    Token*  token_buffer        = NULL;
    size_t  token_buffer_size   = 0;
    size_t  token_line_counter  = 0;
    Token** lines               = NULL;
    size_t  lines_count         = 0;

    do {
        t = Lexer_next(&l);
        if (RT_mode_token) Token_Text_Debug(t);

        token_buffer = realloc(token_buffer, (token_buffer_size + 1) * sizeof (Token));
        token_buffer[token_buffer_size++] = t;
        token_line_counter++;

        if (t.type == TOKEN_NEWLINE || t.type == TOKEN_EOF) {
            // Save line pointer to heap
            lines = realloc(lines, sizeof (Token*) * (lines_count + 1));
            lines[lines_count] = &token_buffer[token_buffer_size - token_line_counter];
            lines_count++;
            token_line_counter = 0;
        }

    } while (t.type);

    if (RT_mode_token) goto free_memory;

    RT_VERBOSEONLY DEBUG_FILE_READ(lines_count);

    //// Line instruction parsing ////

    Token** line = lines;

    do {
       Token_Type_Debug(**line);
    } while ((*line++)->type);

    //// Preprocessor execution ////

    const STRLNG_GLOBAL_SCOPE RT_globalScope = {
        .argc = RT_argc,
        .argv = RT_argv
    };

    //// Free memory ////
free_memory:

    free(lines);
    free(script_buffer);
    free(token_buffer);

    return 0;
}
