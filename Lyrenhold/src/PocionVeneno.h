//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#ifndef POCION_VENENO_H
#define POCION_VENENO_H
#include "ObjetoMagico.h"
#include <iostream>
using std::cout;
using std::endl;
using std::getline;
using std::string;

class PocionVeneno : public ObjetoMagico {
private:
    int danoPorTurno;

public:
    PocionVeneno();
    PocionVeneno(int d);

    void usar(Personaje* personaje) override;
};

#endif

