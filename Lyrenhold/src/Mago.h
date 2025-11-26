//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#ifndef MAGO_H
#define MAGO_H

#include "Personaje.h"
using std::string;

class Mago : public Personaje {
private:
    double ignorarDefensa;

public:
    Mago(int id, const string& nombre, const string& desc,
         const string& tipo, const string& rol,
         int nivel, int vida, int ataque, int defensa,
         double ignore);

    double getIgnorarDefensa() const;
    void setIgnorarDefensa(double p);

    void realizarAccion(Personaje* objetivo) override;
};

#endif //MAGO_H
