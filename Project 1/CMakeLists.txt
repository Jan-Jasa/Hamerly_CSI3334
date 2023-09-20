cmake_minimum_required(VERSION 3.26)
project(Project_1)

set(CMAKE_CXX_FLAGS "-static")

set(CMAKE_CXX_STANDARD 17)

add_executable(Project_1 main.cpp
        location-proj1.h
        maze-proj1.h
        stack-proj1.h
        location-proj1.cpp
        driver-proj1.cpp
        maze-proj1.cpp
        stack-proj1.cpp
)
