//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#ifndef ESCUDO_REFLECTIVO_H
#define ESCUDO_REFLECTIVO_H
#include "ObjetoMagico.h"

class EscudoReflectivo : public ObjetoMagico {
private:
    int cantidadReflejo;

public:
    EscudoReflectivo();
    EscudoReflectivo(int danoreflejado);

    void usar(Personaje* personaje) override;
};

#endif
