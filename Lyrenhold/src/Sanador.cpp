//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#include "Sanador.h"
#include <iostream>
#include <cstdlib> // para rand()
using std::endl;
using std::string;
using std::cout;

Sanador::Sanador(int id, const string& nombre, const string& desc,
                 const string& tipo, const string& rol,
                 int nivel, int vida, int ataque, int defensa,
                 int minC, int maxC)
    : Personaje(id, nombre, desc, tipo, rol, nivel, vida, ataque, defensa),
      minCura(minC), maxCura(maxC) {}

int Sanador::getMinCura() const { return minCura; }
int Sanador::getMaxCura() const { return maxCura; }

void Sanador::setMinCura(int c) { minCura = c; }
void Sanador::setMaxCura(int c) { maxCura = c; }

void Sanador::realizarAccion(Personaje* objetivo) {
    if (!objetivo) return;

    int cura = minCura + (rand() % (maxCura - minCura + 1));

    objetivo->setVida(objetivo->getVida() + cura);

    cout << nombrePersonaje << " cura a " << objetivo->getRol()
         << " por " << cura << " puntos." << endl;
}
