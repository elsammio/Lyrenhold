cmake_minimum_required(VERSION 4.0)
project(Lyrenhold)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lyrenhold main.cpp
        src/Personaje.cpp
        src/Personaje.h
        src/Guild.cpp
        src/Guild.h
        src/Arena.cpp
        src/Arena.h
        src/Heroe.cpp
        src/Heroe.h
        src/Oponente.cpp
        src/Oponente.h
        src/Inventario.cpp
        src/Inventario.h
        src/Rol.cpp
        src/Rol.h
        src/Guerrero.cpp
        src/Guerrero.h
        src/Mago.cpp
        src/Mago.h
        src/Sanador.cpp
        src/Sanador.h
        src/ObjetoMagico.cpp
        src/ObjetoMagico.h
        src/PocionVida.cpp
        src/PocionVida.h
        src/AmuletoFuria.cpp
        src/AmuletoFuria.h
        src/EscudoBendito.cpp
        src/EscudoBendito.h
        src/EscudoReflectivo.cpp
        src/EscudoReflectivo.h
        src/PocionVeneno.cpp
        src/PocionVeneno.h
        src/Cancelacion.cpp
        src/Cancelacion.h)
