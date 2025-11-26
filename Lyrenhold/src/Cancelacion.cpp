//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#include "Cancelacion.h"
#include "Personaje.h"
using std::cout;
using std::endl;

Cancelacion::Cancelacion()
    : ObjetoMagico("Cancelacion", "Anula acciones del oponente, durante un turno."),
      turnoCancelado(0) {}

Cancelacion::Cancelacion(const string& nombre,
                         const string& desc,
                         int turnoscancelados)
    : ObjetoMagico(nombre, desc),
      turnoCancelado(turnoscancelados) {}

void Cancelacion::usar(Personaje* personaje) {
    if (!personaje) return;

    cout << personaje->getNombre()
         << " no puede hacer nada durante "
         << turnoCancelado
         << " turno.\n";
}
