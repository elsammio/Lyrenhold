//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#include "EscudoBendito.h"
#include "Personaje.h"
#include <cstdlib>

using std::cout;

EscudoBendito::EscudoBendito(const string& nombre,
                             const string& desc,
                             int minD, int maxD)
    : ObjetoMagico(nombre, desc),
      minDefensa(minD), maxDefensa(maxD) {}

void EscudoBendito::usar(Personaje* personaje) {
    if (!personaje) return;

    int aumento = minDefensa + (rand() % (maxDefensa - minDefensa + 1));

    personaje->setDefensa(personaje->getDefensa() + aumento);

    cout << personaje->getNombre()
         << " aumenta su defensa en "
         << aumento << " puntos.\n";
}
