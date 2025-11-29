#include "Sanador.h"
#include <cstdlib>
#include <iostream>

using std::rand;
using std::cout;
using std::endl;

Sanador::Sanador(int id, const std::string& nombre, const std::string& tipo, const std::string& rol,
                 int nivel, int vida, int ataque, int defensa,
                 int minC, int maxC)
    : Personaje(id, nombre, tipo, rol, nivel, vida, ataque, defensa),
      minCura(minC), maxCura(maxC) {}

int Sanador::getMinCura() const { return minCura; }
int Sanador::getMaxCura() const { return maxCura; }
void Sanador::setMinCura(int curaminima) { minCura = curaminima; }
void Sanador::setMaxCura(int curamaxima) { maxCura = curamaxima; }

void Sanador::realizarAccion(Personaje* objetivo) {
    if (!objetivo || !objetivo->estaVivo()) return;
    int cura = minCura + (rand() % (maxCura - minCura + 1));
    objetivo->setVida(objetivo->getVida() + cura);
    cout << getNombre() << " cura a " << objetivo->getNombre()
         << " por " << cura << " puntos." << endl;
}
