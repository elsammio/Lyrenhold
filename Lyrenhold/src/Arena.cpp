//
// Created by CRASHO on 23/11/2025.
//

#include "Arena.h"
#include "Guild.h"
#include "Personaje.h"
#include "Inventario.h"

using std::cout;
using std::endl;
using std::vector;

Arena::Arena() : turnoActual(1), guild(nullptr), inventario(nullptr) {}

void Arena::iniciarCombate(Guild* guild) {
    guild = guild;
    inventario = guild->getInventario();
}

void Arena::ejecutarTurno() {
    turnoActual++;
}

void Arena::procesarAccion(Personaje* p) {
    cout << "Procesando accion de " << p->getNombre() << endl;
}

vector<Personaje*> Arena::obtenerHeroesVivos() {
    vector<Personaje*> vivos;
    for (auto p : guild->getHeroes())
        if (p->estaVivo()) vivos.push_back(p);
    return vivos;
}

vector<Personaje*> Arena::obtenerOponentesVivos() {
    vector<Personaje*> vivos;
    for (auto p : guild->getOponentes())
        if (p->estaVivo()) vivos.push_back(p);
    return vivos;
}

bool Arena::equipoDerrotado(const vector<Personaje*>& equipo) {
    for (auto p : equipo)
        if (p->estaVivo()) return false;
    return true;
}

bool Arena::verificarFinCombate() {
    return equipoDerrotado(guild->getHeroes()) ||
           equipoDerrotado(guild->getOponentes());
}

std::string Arena::verificarGanador() {
    if (equipoDerrotado(guild->getOponentes()))
        return "Heroes ganan";
    if (equipoDerrotado(guild->getHeroes()))
        return "Oponentes ganan";
    return "Nadie aún";
}
