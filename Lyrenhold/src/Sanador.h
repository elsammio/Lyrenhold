//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#ifndef SANADOR_H
#define SANADOR_H

#include "Personaje.h"
using std::string;

class Sanador : public Personaje {
private:
    int minCura;
    int maxCura;

public:
    Sanador(int id, string nombre, string desc, int nivel,
            int vida, int ataque, int defensa, int minC, int maxC);

    int getMinCura() const;
    int getMaxCura() const;
    void setMinCura(int c);
    void setMaxCura(int c);

    void realizarAccion(Personaje* objetivo) override;
};

#endif //SANADOR_H
