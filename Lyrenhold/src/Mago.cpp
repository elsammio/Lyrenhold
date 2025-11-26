//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#include "Mago.h"
using std::cout;
using std::endl;

Mago::Mago(int id, const string& nombre, const string& desc,
           const string& tipo, const string& rol,
           int nivel, int vida, int ataque, int defensa,
           double ignore)
    : Personaje(id, nombre, desc, tipo, rol, nivel, vida, ataque, defensa),
      ignorarDefensa(ignore) {}

double Mago::getIgnorarDefensa() const {
    return ignorarDefensa;
}

void Mago::setIgnorarDefensa(double p) {
    ignorarDefensa = p;
}

void Mago::realizarAccion(Personaje* objetivo) {
    if (!objetivo || !objetivo->estaVivo()) return;

    int defensaReducida = objetivo->getDefensa() * (1 - ignorarDefensa);
    int dano = ataque - defensaReducida;
    if (dano < 0) dano = 0;

    objetivo->setVida(objetivo->getVida() - dano);

    cout << nombrePersonaje << " lanza un hechizo a "
         << objetivo->getRol() << " generando "
         << dano << " puntos de dano." << endl;
}
