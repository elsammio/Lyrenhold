//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#include "Guild.h"
#include <iostream>
using std::cout;
using std::endl;

Guild::Guild(const string& nombre, const string& tipo)
    : nombre(nombre), tipo(tipo), inventario(new Inventario()) {}

void Guild::agregarPersonaje(Personaje* p) {
    heroes.push_back(p);
}

void Guild::retirarPersonaje(int id) {
    for (auto it = heroes.begin(); it != heroes.end(); ++it) {
        if ((*it)->getId() == id) {
            heroes.erase(it);
            break;
        }
    }
}

void Guild::listarPersonajes() const {
    for (auto p : heroes) {
        cout << p->getNombre()
             << " (ID " << p->getId() << ")\n";
    }
}

Personaje* Guild::consultarPersonaje(int id) const {
    for (auto p : heroes)
        if (p->getId() == id) return p;
    return nullptr;
}

Inventario* Guild::getInventario() const {
    return inventario;
}

vector<Personaje*> Guild::getHeroes() const {
    return heroes;
}

vector<Personaje*> Guild::getOponentes() const {
    return oponentes;
}
