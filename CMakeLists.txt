cmake_minimum_required(VERSION 4.0)
project(Lyrenhold)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lyrenhold main.cpp
        classes/Personaje.cpp
        classes/Personaje.h
        classes/Guild.cpp
        classes/Guild.h
        classes/Arena.cpp
        classes/Arena.h
        classes/Heroe.cpp
        classes/Heroe.h
        classes/Oponente.cpp
        classes/Oponente.h
        classes/Inventario.cpp
        classes/Inventario.h
        classes/Rol.cpp
        classes/Rol.h
        classes/Guerrero.cpp
        classes/Guerrero.h
        classes/Mago.cpp
        classes/Mago.h
        classes/Sanador.cpp
        classes/Sanador.h
        classes/ObjetoMagico.cpp
        classes/ObjetoMagico.h
        classes/PocionVida.cpp
        classes/PocionVida.h
        classes/AmuletoFuria.cpp
        classes/AmuletoFuria.h
        classes/EscudoBendito.cpp
        classes/EscudoBendito.h)
