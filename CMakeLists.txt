cmake_minimum_required(VERSION 3.22)
project(strlng C)

set(CMAKE_C_STANDARD 23)

add_executable(strlng main.c preprocessor/token.h preprocessor/lexer.h preprocessor/lexer.c preprocessor/token.c strlng.h packages/fs.h packages/jim.h packages/json.h functions/fn_string.h functions/fn_list.h functions/fn_number.h functions/fn.h functions/fn_prepro.h packages.h preprocessor/package_loader.h debug.h preprocessor/instruction_parser.h preprocessor/instruction_parser.c utils/strutil.h)
