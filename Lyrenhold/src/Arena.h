#ifndef ARENA_H
#define ARENA_H

#include <vector>
#include <string>
using std::vector;
using std::string;

class Guild;
class Personaje;
class Inventario;

class Arena {
private:
    int turnoActual;
    Guild* guild;
    Inventario* inventario;
    int objetosUsadosContador = 0;

public:
    Arena();
    void iniciarCombate(Guild* g);
    void ejecutarTurnoUsuario();
    void ejecutarTurnoEnemigos();
    bool verificarFinCombate();
    string verificarGanador();
    vector<Personaje*> obtenerHeroesVivos();
    vector<Personaje*> obtenerOponentesVivos();
    void mostrarResumenFinal();
    int getObjetosUsados() const;
};

#endif
