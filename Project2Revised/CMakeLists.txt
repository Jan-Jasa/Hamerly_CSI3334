cmake_minimum_required(VERSION 3.26)
project(Project2Revised)

set(CMAKE_CXX_FLAGS "-static")

set(CMAKE_CXX_STANDARD 17)

add_executable(Project2Revised main.cpp
        arrayqueue-prof-proj2.h
        arrayqueue-student-proj2.h
        location-proj2.h
        location-proj2.cpp
        maze-proj2.h
        maze-proj2.cpp
        test.h)
