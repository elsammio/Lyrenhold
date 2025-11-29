#include "Guerrero.h"
#include <cstdlib>
#include <iostream>

using std::rand;
using std::cout;
using std::endl;

Guerrero::Guerrero(int id, const std::string& nombre,
                   const std::string& tipo, const std::string& rol,
                   int nivel, int vida, int ataque, int defensa,
                   double crit)
    : Personaje(id, nombre, tipo, rol, nivel, vida, ataque, defensa),
      golpeCritico(crit) {}

double Guerrero::getGolpeCritico() const { return golpeCritico; }
void Guerrero::setGolpeCritico(double probabilidadgolpecritico) { golpeCritico = probabilidadgolpecritico; }

void Guerrero::realizarAccion(Personaje* objetivo) {
    if (!objetivo || !objetivo->estaVivo()) return;
    int dano = getAtaque();
    double prob = (double)rand() / RAND_MAX;
    if (prob < golpeCritico) {
        dano *= 2;
        cout << getNombre() << "Da un golpe critico." << endl;
    }
    objetivo->setVida(objetivo->getVida() - dano);
    cout << getNombre() << " ataca a " << objetivo->getNombre()
         << " generando " << dano << " puntos de dano." << endl;
}
