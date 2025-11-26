//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#include "AmuletoFuria.h"
#include "Personaje.h"
#include <cstdlib>
using std::cout;

AmuletoFuria::AmuletoFuria(const string& nombre,
                           const string& desc,
                           int minA, int maxA)
    : ObjetoMagico(nombre, desc),
      minAumentoDano(minA), maxAumentoDano(maxA) {}

void AmuletoFuria::usar(Personaje* personaje) {
    if (!personaje) return;

    int aumento = minAumentoDano + (rand() % (maxAumentoDano - minAumentoDano + 1));

    personaje->setAtaque(personaje->getAtaque() + aumento);

    cout << personaje->getNombre()
         << " recibe un aumento de ataque de "
         << aumento << " puntos.\n";
}
