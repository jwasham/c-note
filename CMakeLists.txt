cmake_minimum_required(VERSION 3.3)
project(c_note)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        exercises/chapter1/degrees-cf.c
        exercises/chapter1/degrees-fc.c
        exercises/chapter1/hello.c
    README.md algorithms/bfs.c algorithms/same-sign-test.c)

add_executable(c_note ${SOURCE_FILES})