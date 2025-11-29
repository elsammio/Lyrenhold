//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#ifndef ESCUDO_BENDITO_H
#define ESCUDO_BENDITO_H

#include "ObjetoMagico.h"

class EscudoBendito : public ObjetoMagico {
private:
    int minDefensa;
    int maxDefensa;

public:
    EscudoBendito(const string& nombre, const string& desc, int minD, int maxD);

    void usar(Personaje* personaje) override;
};

#endif
