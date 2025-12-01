#include "EscudoReflectivo.h"
#include "Personaje.h"
#include <iostream>

using std::cout;
using std::endl;

EscudoReflectivo::EscudoReflectivo(const string& nombre, const string& desc, int cantref)
    : ObjetoMagico(nombre, desc), cantidadReflejo(cantref) {}

void EscudoReflectivo::usar(Personaje* personaje) {
    if (!personaje) return;
    cout << personaje->getNombre() << " activa un escudo reflectivo que devolvera " << cantidadReflejo << " puntos de dano al atacante." << endl;
}

int EscudoReflectivo::getCantidadReflejo() const { return cantidadReflejo; }
