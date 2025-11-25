//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#ifndef AMULETO_FURIA_H
#define AMULETO_FURIA_H
#include "ObjetoMagico.h"
#include <iostream>
using std::cout;
using std::endl;
using std::getline;
using std::string;

class AmuletoFuria : public ObjetoMagico {
private:
    int minAumentoDano;
    int maxAumentoDano;

public:
    AmuletoFuria();
    AmuletoFuria(int minA, int maxA);

    void usar(Personaje* personaje) override;
};

#endif

