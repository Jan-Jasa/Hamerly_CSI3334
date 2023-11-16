cmake_minimum_required(VERSION 3.26)
project(Project_4)

set(CMAKE_CXX_FLAGS "-static")

set(CMAKE_CXX_STANDARD 17)

add_executable(Project_4 main.cpp
        avl-tree-prof-proj4.h
        avl-tree-student-proj4.h)
