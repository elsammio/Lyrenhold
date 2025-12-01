#include "PocionVida.h"
#include "Personaje.h"
#include <cstdlib>
#include <iostream>

using std::cout;
using std::endl;
using std::rand;

PocionVida::PocionVida(const string& nombre, const string& desc, int minC, int maxC)
    : ObjetoMagico(nombre, desc), minCuracion(minC), maxCuracion(maxC) {}

void PocionVida::usar(Personaje* personaje) {
    if (!personaje) return;
    int cura = minCuracion + (rand() % (maxCuracion - minCuracion + 1));
    personaje->setVida(personaje->getVida() + cura);
    cout << personaje->getNombre() << " recupera " << cura << " puntos de vida." << endl;
}
