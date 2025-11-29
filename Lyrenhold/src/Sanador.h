#ifndef SANADOR_H
#define SANADOR_H

#include "Personaje.h"

class Sanador : public Personaje {
private:
    int minCura;
    int maxCura;

public:
    Sanador(int id, const std::string& nombre, const std::string& tipo, const std::string& rol,
            int nivel, int vida, int ataque, int defensa,
            int minC, int maxC);

    int getMinCura() const;
    int getMaxCura() const;
    void setMinCura(int curaminima);
    void setMaxCura(int curamaxima);

    void realizarAccion(Personaje* objetivo) override;
};

#endif
