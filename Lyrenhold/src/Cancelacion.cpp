//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#include "Cancelacion.h"
#include "Personaje.h"
#include <iostream>

using std::cout;
using std::endl;
Cancelacion::Cancelacion(const string& nombre, const string& desc, int turnoscancelados)
    : ObjetoMagico(nombre, desc), turnoCancelado(turnoscancelados) {}

void Cancelacion::usar(Personaje* personaje) {
    if (!personaje) return;
    personaje->aplicarCancelacion(turnoCancelado);
    cout << personaje->getNombre() << " queda incapacitado por " << turnoCancelado << " turno." << endl;
}
