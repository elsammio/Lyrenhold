#ifndef GUERRERO_H
#define GUERRERO_H

#include "Personaje.h"

class Guerrero : public Personaje {
private:
    double golpeCritico;

public:
    Guerrero(int id, const std::string& nombre,
             const std::string& tipo, const std::string& rol,
             int nivel, int vida, int ataque, int defensa,
             double crit);

    double getGolpeCritico() const;
    void setGolpeCritico(double probabilidadgolpecritico);

    void realizarAccion(Personaje* objetivo) override;
};

#endif
