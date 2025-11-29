#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include <string>

using std::string;

class Inventario;

class Personaje {
protected:
    int id;
    string nombrePersonaje;
    string tipo;
    string rol;
    int nivel;
    int vida;
    int ataque;
    int defensa;
    int turnosEnvenenado = 0;
    int danoPorTurno = 0;
    int turnosCancelados = 0;
    int ataqueBuff = 0;
    int defensaBuff = 0;

public:
    Personaje(int id, const string& nombre, const string& tipo,
              const string& rol, int nivel, int vida, int ataque, int defensa);

    virtual ~Personaje() {}

    virtual void realizarAccion(Personaje* objetivo) = 0;

    void ejecutarAccion(Personaje* usuario, Personaje* objetivo);

    void usarObjeto(const string& nombreObjeto, class Inventario* inv);

    bool estaVivo() const;

    int getVida() const;
    void setVida(int v);

    string getRol() const;
    string getTipo() const;
    string getNombre() const;
    int getId() const;
    int getNivel () const;

    int getAtaque() const;
    void setAtaque(int a);

    int getDefensa() const;
    void setDefensa(int d);

    void aplicarEnvenenamiento(int dano, int turnos);
    void procesarEfectosAlInicioTurno();
    bool estaCancelado() const;
    void aplicarCancelacion(int turnos);

    void aplicarBuffAtaque(int val, int turnos);
    void aplicarBuffDefensa(int val, int turnos);

    int getTurnosEnvenenado() const;
    int getTurnosCancelados() const;
};

#endif

