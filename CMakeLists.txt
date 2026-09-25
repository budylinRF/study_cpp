cmake_minimum_required(VERSION 4.2)
project(Study_Cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(Study_Cpp
        tasks/dynamic_stack/main.cpp
        tasks/dynamic_stack/stack.cpp
        tasks/dynamic_stack/stack.h
        tasks/throw_test/main.cpp
)
