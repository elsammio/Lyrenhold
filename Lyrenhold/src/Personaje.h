//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>

using std::string;

class Personaje {
protected:
    int id;
    string nombrePersonaje;
    string desc;
    string tipo;
    string rol;
    int nivel;
    int vida;
    int ataque;
    int defensa;

public:
    Personaje();
    Personaje(int id, string nombre, string desc, string tipo,
              string rol, int nivel, int vida, int ataque, int defensa);

    virtual ~Personaje() {}

    virtual void realizarAccion(Personaje* objetivo) = 0;
    void ejecutarAccion(Personaje* usuario, Personaje* objetivo);
    void usarObjeto(const string& nombreObjeto);

    bool estaVivo() const;

    int getVida() const;
    void setVida(int v);

    string getRol() const;
    string getTipo() const;

    int getAtaque() const;
    int getDefensa() const;
};

#endif // PERSONAJE_H
