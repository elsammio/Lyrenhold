//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#ifndef AMULETO_FURIA_H
#define AMULETO_FURIA_H
#include "ObjetoMagico.h"

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

