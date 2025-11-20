//
// Created by CRASHO on 18/11/2025.
//

#ifndef LYRENHOLD_ROL_H
#define LYRENHOLD_ROL_H
#include "Personaje.h"

class Rol {
public:
    virtual void ejecutarAccion(Personaje* aliado, Personaje* objetivo) = 0;
    virtual ~Rol() {};
};


#endif //LYRENHOLD_ROL_H