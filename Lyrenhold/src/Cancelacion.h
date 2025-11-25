//
// Created by Luis Alejandro Peña on 23/11/2025.
//
#ifndef CANCELACION_H
#define CANCELACION_H
#include "ObjetoMagico.h"
#include <iostream>
using std::cout;
using std::endl;
using std::getline;
using std::string;

class Cancelacion : public ObjetoMagico {
private:
    int turnoCancelado;

public:
    Cancelacion();
    Cancelacion(int t);

    void usar(Personaje* personaje) override;
};

#endif


