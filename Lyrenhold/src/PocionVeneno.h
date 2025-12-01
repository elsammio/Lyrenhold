#ifndef POCION_VENENO_H
#define POCION_VENENO_H

#include "ObjetoMagico.h"

class PocionVeneno : public ObjetoMagico {
private:
    int danoPorTurno;

public:
    PocionVeneno(const string& nombre, const string& desc, int dano);

    void usar(Personaje* personaje) override;
};

#endif
