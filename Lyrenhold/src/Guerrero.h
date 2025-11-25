//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#ifndef GUERRERO_H
#define GUERRERO_H

#include "Personaje.h"

using std::string;

<<<<<<< HEAD
class Guerrero : public Personaje {
=======
class Guerrero {
>>>>>>> 48e9cccc5f36e66f969b4096d8f97f1e0b12605b
private:
    double golpeCritico;

public:
    Guerrero(int id, string nombre, string desc, int nivel,
             int vida, int ataque, int defensa, double crit);

    double getGolpeCritico() const;
    void setGolpeCritico(double prob);

    void realizarAccion(Personaje* objetivo) override;
};

#endif //GUERRERO_H
