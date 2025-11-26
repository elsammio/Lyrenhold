//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#ifndef POCION_VIDA_H
#define POCION_VIDA_H
#include "ObjetoMagico.h"

class PocionVida : public ObjetoMagico {
private:
    int minCuracion;
    int maxCuracion;

public:
    PocionVida();
    PocionVida(int minC, int maxC);

    void usar(Personaje* personaje) override;
};

#endif
