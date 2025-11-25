//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#ifndef PERSONAJE_H
#define PERSONAJE_H
<<<<<<< HEAD

#include <iostream>
=======
#include <string>
>>>>>>> 48e9cccc5f36e66f969b4096d8f97f1e0b12605b

using std::string;

class Personaje {
<<<<<<< HEAD
protected:
    int id;
    string nombrePersonaje;
    string desc;
=======
private:
    int idPersonaje;
    string nombrePersonaje;
    string descripcionPersonaje;
>>>>>>> 48e9cccc5f36e66f969b4096d8f97f1e0b12605b
    string tipo;
    string rol;
    int nivel;
    int vida;
    int ataque;
    int defensa;
<<<<<<< HEAD

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
=======
>>>>>>> 48e9cccc5f36e66f969b4096d8f97f1e0b12605b
};

#endif // PERSONAJE_H
