//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#include "Guerrero.h"
#include <iostream>
#include <cstdlib> // para rand()
using std::string;
using std::endl;
using std::cout;

Guerrero::Guerrero(int id, const string& nombre, const string& desc,
                   const string& tipo, const string& rol,
                   int nivel, int vida, int ataque, int defensa,
                   double crit)
    : Personaje(id, nombre, desc, tipo, rol, nivel, vida, ataque, defensa),
      golpeCritico(crit) {}

double Guerrero::getGolpeCritico() const {
    return golpeCritico;
}

void Guerrero::setGolpeCritico(double prob) {
    golpeCritico = prob;
}

void Guerrero::realizarAccion(Personaje* objetivo) {
    if (!objetivo || !objetivo->estaVivo()) return;

    int dano = ataque;

    double prob = (double)rand() / RAND_MAX;
    if (prob < golpeCritico) {
        dano *= 2;
        cout << nombrePersonaje << " Da un golpe critico" << endl;
    }

    objetivo->setVida(objetivo->getVida() - dano);

    cout << nombrePersonaje << " ataca a " << objetivo->getRol()
         << " generando " << dano << " puntos de daño." << endl;
}
