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
      rol(rol), nivel(nivel), vida(vida), ataque(ataque), defensa(defensa) {}

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
void Personaje::setVida(int v) { vida = v; if (vida < 0) vida = 0; }

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

    if (turnosCancelados > 0) {
        turnosCancelados--;
    }

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
