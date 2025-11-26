//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#ifndef GUILD_H
#define GUILD_H

#include <iostream>
#include <vector>
#include "Personaje.h"
#include "Inventario.h"

using std::vector;
using std::string;

class Guild {
private:
    string nombre;
    string tipo;
    vector<Personaje*> heroes;
    vector<Personaje*> oponentes;
    Inventario* inventario;

public:
    Guild(const string& nombre, const string& tipo);

    void agregarPersonaje(Personaje* p);
    void retirarPersonaje(int id);
    void listarPersonajes() const;
    Personaje* consultarPersonaje(int id) const;

    Inventario* getInventario() const;

    vector<Personaje*> getHeroes() const;
    vector<Personaje*> getOponentes() const;
};

#endif  //GUILD_H
