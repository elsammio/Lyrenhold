#ifndef AMULETO_FURIA_H
#define AMULETO_FURIA_H

#include "ObjetoMagico.h"

class AmuletoFuria : public ObjetoMagico {
private:
    int minAumentoDano;
    int maxAumentoDano;

public:
    AmuletoFuria(const string& nombre, const string& desc, int minA, int maxA);

    void usar(Personaje* personaje) override;
};

#endif

