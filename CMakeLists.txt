cmake_minimum_required(VERSION 3.3)
project(c_note)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    intro/degrees-cf.c
    intro/degrees-fc.c
    intro/hello.c
    README.md algorithms/bfs.c.c)

add_executable(c_note ${SOURCE_FILES})