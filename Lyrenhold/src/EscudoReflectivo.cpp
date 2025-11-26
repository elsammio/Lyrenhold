//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#include "EscudoReflectivo.h"
#include "Personaje.h"
using std::cout;
using std::endl;

EscudoReflectivo::EscudoReflectivo()
    : ObjetoMagico("Escudo Reflectivo", "Escudo que refleja dano del oponente, es como si le rebotara"),
      cantidadReflejo(0) {}

EscudoReflectivo::EscudoReflectivo(const string& nombre,
                                   const string& desc,
                                   int ref)
    : ObjetoMagico(nombre, desc),
      cantidadReflejo(ref) {}

void EscudoReflectivo::usar(Personaje* personaje) {
    if (!personaje) return;

    cout << personaje->getNombre()
         << " activa un escudo reflectivo que devolvera "
         << cantidadReflejo
         << " puntos de dano al atacante.\n";
}
