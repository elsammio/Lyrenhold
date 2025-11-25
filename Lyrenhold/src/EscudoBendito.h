//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#ifndef ESCUDO_BENDITO_H
#define ESCUDO_BENDITO_H
#include "ObjetoMagico.h"
#include <iostream>
using std::cout;
using std::endl;
using std::getline;
using std::string;

class EscudoBendito : public ObjetoMagico {
private:
    int minDefensa;
    int maxDefensa;

public:
    EscudoBendito();
    EscudoBendito(int minD, int maxD);

    void usar(Personaje* personaje) override;
};

#endif
