//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#ifndef GUILD_H
#define GUILD_H
#include <list>
#include "Inventario.h"
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

class Guild {
private:
    string nombreGuild;
    string tipoGuild;
    std::pmr::list<Personaje>heroe;
    std::pmr::list<Personaje>oponente;
    Inventario inventario;

};



#endif //GUILD_H
