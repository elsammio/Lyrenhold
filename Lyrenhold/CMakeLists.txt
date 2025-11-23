cmake_minimum_required(VERSION 3.30)
project(Lyrenhold)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lyrenhold main.cpp
        src/Personaje.cpp
        src/Personaje.h
        src/Arena.cpp
        src/Arena.h
        src/Guild.cpp
        src/Guild.h
        src/Inventario.cpp
        src/Inventario.h
        src/ObjetoMagico.cpp
        src/ObjetoMagico.h
        src/Sanador.cpp
        src/Sanador.h
        src/Mago.cpp
        src/Mago.h
        src/Guerrero.cpp
        src/Guerrero.h)
