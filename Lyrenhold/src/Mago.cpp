#include "Mago.h"
#include <iostream>

using std::cout;
using std::endl;

Mago::Mago(int id, const std::string& nombre,
           const std::string& tipo, const std::string& rol,
           int nivel, int vida, int ataque, int defensa,
           double ignore)
    : Personaje(id, nombre, tipo, rol, nivel, vida, ataque, defensa),
      ignorarDefensa(ignore) {}

double Mago::getIgnorarDefensa() const { return ignorarDefensa; }
void Mago::setIgnorarDefensa(double ignorardefensa) { ignorarDefensa = ignorardefensa; }

void Mago::realizarAccion(Personaje* objetivo) {
    if (!objetivo || !objetivo->estaVivo()) return;
    int defensaReducida = (int)(objetivo->getDefensa() * (1.0 - ignorarDefensa));
    int dano = getAtaque() - defensaReducida;
    if (dano < 0) dano = 0;
    objetivo->setVida(objetivo->getVida() - dano);
    cout << getNombre() << " lanza un hechizo a " << objetivo->getNombre()
         << " generando " << dano << " puntos de dano." << endl;
}
