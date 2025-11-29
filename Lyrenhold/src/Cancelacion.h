//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#ifndef CANCELACION_H
#define CANCELACION_H

#include "ObjetoMagico.h"

class Cancelacion : public ObjetoMagico {
private:
    int turnoCancelado;

public:
    Cancelacion(const string& nombre, const string& desc, int turnoscancelados);

    void usar(Personaje* personaje) override;
};

#endif
