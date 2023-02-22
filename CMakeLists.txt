cmake_minimum_required(VERSION 3.22)
project(strlng C)

set(CMAKE_C_STANDARD 23)

add_executable(strlng main.c token.h lexer.h lexer.c token.c strlng.h packages/fs.h packages/jim.h packages/json.h)
