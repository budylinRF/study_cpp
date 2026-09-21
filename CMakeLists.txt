cmake_minimum_required(VERSION 4.2)
project(Study_Cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(Study_Cpp
        tasks/count_words/words.cpp
        tasks/count_words/words.h
        tasks/count_words/main.cpp
)
