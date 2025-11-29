//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#include "PocionVeneno.h"
#include "Personaje.h"
#include <iostream>

using std::cout;
using std::endl;

PocionVeneno::PocionVeneno(const string& nombre, const string& desc, int dano)
    : ObjetoMagico(nombre, desc), danoPorTurno(dano) {}

void PocionVeneno::usar(Personaje* personaje) {
    if (!personaje) return;
    personaje->aplicarEnvenenamiento(danoPorTurno, 3);
    cout << personaje->getNombre() << " sufre envenenamiento de " << danoPorTurno << " por 3 turnos." << endl;
}
