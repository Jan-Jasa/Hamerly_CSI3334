cmake_minimum_required(VERSION 3.26)
project(Project_3)

set(CMAKE_CXX_FLAGS "-static")

set(CMAKE_CXX_STANDARD 17)

add_executable(Project_3 main.cpp
        bst-prof-proj3.h
        bst-student-proj3.h
        notes.cpp)
