#ifndef MAGO_H
#define MAGO_H

#include "Personaje.h"

class Mago : public Personaje {
private:
    double ignorarDefensa;

public:
    Mago(int id, const std::string& nombre, const std::string& tipo, const std::string& rol,
         int nivel, int vida, int ataque, int defensa,
         double ignore);

    double getIgnorarDefensa() const;
    void setIgnorarDefensa(double ignorardefensa);

    void realizarAccion(Personaje* objetivo) override;
};

#endif
