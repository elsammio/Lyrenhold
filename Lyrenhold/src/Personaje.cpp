#include "Personaje.h"
#include "Inventario.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Personaje::Personaje(int id, const string& nombre,
                     const string& tipo, const string& rol,
                     int nivel, int vida, int ataque, int defensa)
    : id(id), nombrePersonaje(nombre), tipo(tipo),
      rol(rol), nivel(nivel), vida(vida), ataque(ataque), defensa(defensa)
{
    vidaMaxima = vida;
}

void Personaje::ejecutarAccion(Personaje* usuario, Personaje* objetivo) {
    if (usuario && objetivo && usuario->estaVivo()) {
        usuario->realizarAccion(objetivo);
    }
}

void Personaje::usarObjeto(const string& nombreObjeto, Inventario* inv) {
    if (!inv) {
        cout << nombrePersonaje << " intenta usar " << nombreObjeto << " pero no hay inventario.\n";
        return;
    }
    bool ok = inv->usarAsignado(this, nombreObjeto);
    if (!ok) {
        cout << nombrePersonaje << " no tiene " << nombreObjeto << " asignado o ya fue usado.\n";
    }
}

bool Personaje::estaVivo() const {
    return vida > 0;
}

int Personaje::getVida() const { return vida; }

void Personaje::setVida(int v) {

    if (v < vida) {
        int dano = vida - v;
        if (defendiendo) {
            dano /= 2;
            cout << nombrePersonaje << " reduce el dano al defenderse!\n";
        }
        vida = vida - dano;
    } else {
        vida = v;
    }

    if (vida < 0) vida = 0;
}

int Personaje::getVidaMaxima() const { return vidaMaxima; }

string Personaje::getRol() const { return rol; }
string Personaje::getTipo() const { return tipo; }
string Personaje::getNombre() const { return nombrePersonaje; }
int Personaje::getId() const { return id; }
int Personaje::getNivel() const {return nivel;}

int Personaje::getAtaque() const { return ataque + ataqueBuff; }
void Personaje::setAtaque(int a) { ataque = a; }

int Personaje::getDefensa() const { return defensa + defensaBuff; }
void Personaje::setDefensa(int d) { defensa = d; }

void Personaje::aplicarEnvenenamiento(int dano, int turnos) {
    danoPorTurno = dano;
    turnosEnvenenado = turnos;
}

void Personaje::procesarEfectosAlInicioTurno() {

    defendiendo = false;

    if (turnosEnvenenado > 0) {
        vida -= danoPorTurno;
        if (vida < 0) vida = 0;
        cout << nombrePersonaje << " sufre " << danoPorTurno << " de dano por veneno. (vida ahora: " << vida << ")\n";
        turnosEnvenenado--;
        if (turnosEnvenenado == 0) {
            danoPorTurno = 0;
        }
    }
}

bool Personaje::estaCancelado() const {
    return turnosCancelados > 0;
}

void Personaje::aplicarCancelacion(int turnos) {
    turnosCancelados = turnos;
    cout << nombrePersonaje << " queda incapacitado por " << turnos << " turno.\n";
}

void Personaje::aplicarBuffAtaque(int val, int turnos) {
    ataqueBuff += val;
    (void)turnos;
}

void Personaje::aplicarBuffDefensa(int val, int turnos) {
    defensaBuff += val;
    (void)turnos;
}

int Personaje::getTurnosEnvenenado() const { return turnosEnvenenado; }
int Personaje::getTurnosCancelados() const { return turnosCancelados; }


void Personaje::defender() {
    defendiendo = true;
    cout << nombrePersonaje << " adopta una postura defensiva lo que reduce el dano en el siguiente ataque.\n";
}

bool Personaje::estaDefendiendo() const {
    return defendiendo;
}
