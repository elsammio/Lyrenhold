//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#ifndef ESCUDO_REFLECTIVO_H
#define ESCUDO_REFLECTIVO_H

#include "ObjetoMagico.h"
using std::string;

class EscudoReflectivo : public ObjetoMagico {
private:
    int cantidadReflejo;

public:
    EscudoReflectivo();
    EscudoReflectivo(const string& nombre,
                     const string& desc,
                     int cantref);

    void usar(Personaje* personaje) override;
};

#endif

