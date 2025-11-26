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
    cout << nombrePersonaje << " intenta usar: " << nombreObjeto << endl;
}

int Personaje::getVida() const {
    return vida;
}

void Personaje::setVida(int v) {
    vida = v;
}

string Personaje::getRol() const {
    return rol;
}

string Personaje::getTipo() const {
    return tipo;
}

int Personaje::getAtaque() const {
    return ataque;
}

void Personaje::setAtaque(int a) {
    ataque = a;
}

int Personaje::getDefensa() const {
    return defensa;
}

void Personaje::setDefensa(int d) {
    defensa = d;
}

string Personaje::getNombre() const {
    return nombrePersonaje;
}

int Personaje::getId() const {
    return id;
}
