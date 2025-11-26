//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#include "Personaje.h"
#include <iostream>
using std::string;
using std::cout;
using std::endl;

Personaje::Personaje(int id, const string& nombre, const string& desc,
                     const string& tipo, const string& rol,
                     int nivel, int vida, int ataque, int defensa)
    : id(id), nombrePersonaje(nombre), desc(desc), tipo(tipo),
      rol(rol), nivel(nivel), vida(vida), ataque(ataque), defensa(defensa) {}

bool Personaje::estaVivo() const {
    return vida > 0;
}

void Personaje::ejecutarAccion(Personaje* usuario, Personaje* objetivo) {
    if (usuario && objetivo && usuario->estaVivo()) {
        usuario->realizarAccion(objetivo);
    }
}

void Personaje::usarObjeto(const string& nombreObjeto) {
    cout << nombrePersonaje << " uso: " << nombreObjeto << endl;
}

