#include "Cancelacion.h"
#include "Personaje.h"
#include <iostream>

using std::cout;
using std::endl;

Cancelacion::Cancelacion(const string& nombre, const string& desc, int turnoscancelados)
    : ObjetoMagico(nombre, desc), turnoCancelado(turnoscancelados) {}

void Cancelacion::usar(Personaje* personaje)
{
    if (!personaje || !personaje->estaVivo()) {
        cout << "No se puede aplicar Cancelacion.\n";
        return;
    }

    personaje->aplicarCancelacion(turnoCancelado);
}
