//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#include "PocionVeneno.h"
#include "Personaje.h"
using std::cout;
using std::endl;
using std::string;

PocionVeneno::PocionVeneno()
    : ObjetoMagico("Poción de Veneno", "envenena al oponente, quitandole puntos de vida."),
      danoPorTurno(0) {}

PocionVeneno::PocionVeneno(const string& nombre,
                           const string& desc,
                           int dano)
    : ObjetoMagico(nombre, desc),
      danoPorTurno(dano) {}

void PocionVeneno::usar(Personaje* personaje) {
    if (!personaje) return;

    int nuevaVida = personaje->getVida() - danoPorTurno;
    personaje->setVida(nuevaVida);

    cout << personaje->getNombre()
         << " sufre " << danoPorTurno
         << " puntos de dano por veneno.\n";
}
