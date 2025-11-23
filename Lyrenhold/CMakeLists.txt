cmake_minimum_required(VERSION 3.30)
project(Lyrenhold)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lyrenhold main.cpp
        src/Personaje.cpp
        src/Personaje.h
        src/Arena.cpp
        src/Arena.h)
