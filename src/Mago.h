//
// Created by CRASHO on 18/11/2025.
//

#ifndef LYRENHOLD_MAGO_H
#define LYRENHOLD_MAGO_H
#include "Personaje.h"

class Mago : public Rol {
public:
    void ejecutarAccion(Personaje* aliado, Personaje* objetivo) override;
    void hechizo();
};


#endif //LYRENHOLD_MAGO_H