//
// Created by CRASHO on 23/11/2025.
//

#ifndef ARENA_H
#define ARENA_H

#include <vector>
#include <iostream>

using std::string;
using std::vector;

class Guild;
class Personaje;
class Inventario;

class Arena {
private:
    int turnoActual;
    Guild* guild;
    Inventario* inventario;

public:
    Arena();

    void iniciarCombate(Guild* g);
    void ejecutarTurno();
    void procesarAccion(Personaje* p);

    vector<Personaje*> obtenerHeroesVivos();
    vector<Personaje*> obtenerOponentesVivos();

    bool equipoDerrotado(const vector<Personaje*>& equipo);
    bool verificarFinCombate();
    string verificarGanador();
};

#endif //ARENA_H
