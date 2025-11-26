//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#include "ObjetoMagico.h"
#include "personaje.h"
ObjetoMagico::ObjetoMagico(const string& nombre, const string& desc)
    : nombreObjetoMagico(nombre), desc(desc) {}

string ObjetoMagico::getNombre() const {
    return nombreObjetoMagico;
}
