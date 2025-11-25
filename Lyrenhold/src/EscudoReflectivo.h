//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#ifndef ESCUDO_REFLECTIVO_H
#define ESCUDO_REFLECTIVO_H
#include "ObjetoMagico.h"
#include <iostream>
using std::cout;
using std::endl;
using std::getline;
using std::string;

class EscudoReflectivo : public ObjetoMagico {
private:
    int cantidadReflejo;

public:
    EscudoReflectivo();
    EscudoReflectivo(int ref);

    void usar(Personaje* personaje) override;
};

#endif

