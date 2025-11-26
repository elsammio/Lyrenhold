//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#include "Inventario.h"
#include "ObjetoMagico.h"
#include "Personaje.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;

Inventario::Inventario() {}

void Inventario::crear(ObjetoMagico* obj, int cantidad) {
    stock[obj->getNombre()] += cantidad;
}

void Inventario::listar() const {
    cout << " Inventario \n";
    for (const auto& p : stock) {
        cout << p.first << ": " << p.second << endl;
    }
}

void Inventario::consultar(const string& nombre) const {
    auto it = stock.find(nombre);
    if (it != stock.end()) {
        cout << nombre << " disponible: " << it->second << endl;
    } else {
        cout << nombre << " no se encuentra en el inventario.\n";
    }
}

void Inventario::actualizarStock(const string& nombre, int cant) {
    stock[nombre] = cant;
}

void Inventario::eliminar(const string& nombre) {
    stock.erase(nombre);
}

void Inventario::asignar(Personaje* p, ObjetoMagico* obj) {
    asignados[p].push_back(obj);
}
