//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#ifndef GUILD_H
#define GUILD_H
#include <list>

<<<<<<< HEAD
#include <string>
#include <vector>
=======
#include "Inventario.h"
>>>>>>> 48e9cccc5f36e66f969b4096d8f97f1e0b12605b

using std::string;
using std::vector;

class Personaje;
class Inventario;

class Guild {
private:
<<<<<<< HEAD
    string nombre;
    string tipo;
    vector<Personaje*> heroes;
    vector<Personaje*> oponentes;
    Inventario* inventario;
=======
    string nombreGuild;
    string tipoGuild;
    std::pmr::list<Personaje>heroe;
    std::pmr::list<Personaje>oponente;
    Inventario inventario;
>>>>>>> 48e9cccc5f36e66f969b4096d8f97f1e0b12605b

public:
    Guild(string nombre, string tipo);

    void agregarPersonaje(Personaje* p);
    void retirarPersonaje(int id);
    void listarPersonajes() const;
    Personaje* consultarPersonaje(int id) const;

    Inventario* getInventario() const;

    vector<Personaje*> getHeroes() const;
    vector<Personaje*> getOponentes() const;
};

#endif //GUILD_H
