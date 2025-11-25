//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#ifndef GUILD_H
#define GUILD_H

#include <string>
#include <vector>

using std::string;
using std::vector;

class Personaje;
class Inventario;

class Guild {
private:
    string nombre;
    string tipo;
    vector<Personaje*> heroes;
    vector<Personaje*> oponentes;
    Inventario* inventario;

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
