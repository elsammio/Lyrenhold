#include "EscudoBendito.h"
#include "Personaje.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::rand;
using std::endl;

EscudoBendito::EscudoBendito(const string& nombre, const string& desc, int minD, int maxD)
    : ObjetoMagico(nombre, desc), minDefensa(minD), maxDefensa(maxD) {}

void EscudoBendito::usar(Personaje* personaje) {
    if (!personaje) return;
    int aumento = minDefensa + (rand() % (maxDefensa - minDefensa + 1));
    personaje->aplicarBuffDefensa(aumento, 1);
    cout << personaje->getNombre() << " aumenta su defensa en " << aumento << " puntos." << endl;
}
