//
// Created by CRASHO on 18/11/2025.
//

#ifndef LYRENHOLD_SANADOR_H
#define LYRENHOLD_SANADOR_H
#include "Personaje.h"

class Sanador : public Rol {
public:
    void ejecutarAccion(Personaje* aliado, Personaje* objetivo) override;
    void curarAliado();
};

#endif //LYRENHOLD_SANADOR_H