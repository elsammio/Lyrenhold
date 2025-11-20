//
// Created by CRASHO on 18/11/2025.
//

#ifndef LYRENHOLD_GUERRERO_H
#define LYRENHOLD_GUERRERO_H
#include "Personaje.h"

class Guerrero : public Rol {
public:
    void ejecutarAccion(Personaje* aliado, Personaje* objetivo) override;
    void ataqueCritico();
};


#endif //LYRENHOLD_GUERRERO_H