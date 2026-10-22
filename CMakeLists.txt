cmake_minimum_required(VERSION 4.2)
project(Study_Cpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(Study_Cpp
        tasks/dynamic_stack/main.cpp
        tasks/dynamic_stack/stack.cpp
        tasks/dynamic_stack/stack.h
        tasks/throw_test/main.cpp
        tasks/polinom/main.cpp
        tasks/polinom/polinom.cpp
        tasks/polinom/polinom.h
        tasks/dynamic_dequeue/main.cpp
        tasks/dynamic_dequeue/dequeue.cpp
        tasks/dynamic_dequeue/dequeue.h
        tasks/dequeue_from_stack/main.cpp
)
