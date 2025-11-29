#ifndef GUILD_H
#define GUILD_H

#include <vector>
#include <string>
#include "Inventario.h"
using std::vector;
using std::string;

class Personaje;

class Guild {
private:
    string nombre;
    string tipo;
    vector<Personaje*> heroes;
    vector<Personaje*> oponentes;
    Inventario* inventario;

public:
    Guild(const string& nombre, const string& tipo);
    ~Guild();


    void agregarHeroe(Personaje* p);
    void retirarHeroe(int id);
    void listarHeroes() const;
    Personaje* consultarHeroe(int id) const;
    vector<Personaje*> getHeroes() const;


    void agregarOponente(Personaje* p);
    void retirarOponente(int id);
    void listarOponentes() const;
    Personaje* consultarOponente(int id) const;
    vector<Personaje*> getOponentes() const;

    Inventario* getInventario() const;
};

#endif
