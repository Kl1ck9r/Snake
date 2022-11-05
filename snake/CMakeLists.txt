cmake_minimum_required(VERSION 3.24.2)

set(SOURCE_LIB Snake.hpp Snake.cpp)

set(SOURCE_EXE main.cpp)


add_library(snake_lib ${SOURCE_LIB})

add_executable(src ${SOURCE_EXE})

