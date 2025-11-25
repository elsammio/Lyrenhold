//
// Created by CRASHO on 23/11/2025.
//

<<<<<<< HEAD
#ifndef ARENA_H
#define ARENA_H
=======
#ifndef LYRENHOLD_ARENA_H
#define LYRENHOLD_ARENA_H
#include "Guild.h"
>>>>>>> 48e9cccc5f36e66f969b4096d8f97f1e0b12605b

#include <vector>
#include <string>

using std::vector;
using std::string;

class Guild;
class Personaje;
class Inventario;

class Arena {
<<<<<<< HEAD
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
=======
    private:
    int turnoActual;
    Guild guild;
    Inventario inventario;
>>>>>>> 48e9cccc5f36e66f969b4096d8f97f1e0b12605b
};

#endif //ARENA_H
