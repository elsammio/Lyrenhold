//
// Created by CRASHO on 18/11/2025.
//

#ifndef LYRENHOLD_PERSONAJE_H
#define LYRENHOLD_PERSONAJE_H
#include <iostream>
#include <string>
#include <vector>

#include "Rol.h"
using namespace std;

class Personaje {
private:
    string nombre;
    int nivel;
    int vida;
    int ataque;
    int defensa;
    Rol* rol;
public:
    Personaje() {

    }
public:
    Personaje(std::string n, int nv, int v, int atk, int def, Rol* r)
        : nombre(n), nivel(nv), vida(v), ataque(atk), defensa(def), rol(r) {}

    virtual void realizarAccion() = 0;
    bool estaVivo() { return vida > 0; }
    virtual ~Personaje() { if (rol) delete rol; }
};


#endif //LYRENHOLD_PERSONAJE_H