#include "Guild.h"
#include "Personaje.h"
#include <iostream>

using std::cout;
using std::endl;

Guild::Guild(const string& nombre, const string& tipo)
    : nombre(nombre), tipo(tipo), inventario(new Inventario()) {}

Guild::~Guild() {

    for (auto p : heroes) delete p;
    for (auto p : oponentes) delete p;
    delete inventario;
}

void Guild::agregarHeroe(Personaje* p) {
    heroes.push_back(p);
}

void Guild::retirarHeroe(int id) {
    for (auto it = heroes.begin(); it != heroes.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            heroes.erase(it);
            break;
        }
    }
}

void Guild::listarHeroes() const {
    cout << "=== HEROES ===\n";
    for (auto p : heroes) {
        cout << "- ID " << p->getId() << " | " << p->getNombre()
             << " | Nivel: " << p->getNivel()
             << " | Vida: " << p->getVida()
             << " | Ataque: " << p->getAtaque()
             << " | Defensa: " << p->getDefensa()
             << " | Rol: " << p->getRol() << "\n";

    }
}

Personaje* Guild::consultarHeroe(int id) const {
    for (auto p : heroes) if (p->getId() == id) return p;
    return nullptr;
}

vector<Personaje*> Guild::getHeroes() const { return heroes; }

// Oponentes
void Guild::agregarOponente(Personaje* p) {
    oponentes.push_back(p);
}

void Guild::retirarOponente(int id) {
    for (auto it = oponentes.begin(); it != oponentes.end(); ++it) {
        if ((*it)->getId() == id) {
            delete *it;
            oponentes.erase(it);
            break;
        }
    }
}

void Guild::listarOponentes() const {
    cout << "=== OPONENTES ===\n";
    for (auto p : oponentes) {
        cout << "- ID " << p->getId() << " | " << p->getNombre()
             << " | Nivel: " << p->getNivel()
             << " | Vida: " << p->getVida()
             << " | Ataque: " << p->getAtaque()
             << " | Defensa: " << p->getDefensa()
             << " | Rol: " << p->getRol() << "\n";
    }
}

Personaje* Guild::consultarOponente(int id) const {
    for (auto p : oponentes) if (p->getId() == id) return p;
    return nullptr;
}

vector<Personaje*> Guild::getOponentes() const { return oponentes; }

Inventario* Guild::getInventario() const { return inventario; }
