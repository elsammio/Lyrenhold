//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#ifndef SANADOR_H
#define SANADOR_H

#include "Personaje.h"

using std::string;

<<<<<<< HEAD
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
=======
class Sanador {
private:
    int minCura;
    int maxCura;
>>>>>>> 48e9cccc5f36e66f969b4096d8f97f1e0b12605b
};

#endif //SANADOR_H
