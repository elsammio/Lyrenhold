//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <map>
#include <vector>
#include <iostream>

using std::string;
using std::map;
using std::vector;

class Personaje;
class ObjetoMagico;

class Inventario {
private:
    map<string, int> stock;
    map<Personaje*, vector<ObjetoMagico*>> asignados;

public:
    Inventario();

    void crear(ObjetoMagico* obj, int cantidad);
    void listar() const;
    void consultar(const string& nombre) const;
    void actualizarStock(const string& nombre, int cant);
    void eliminar(const string& nombre);
    void asignar(Personaje* p, ObjetoMagico* obj);

    void guardarJSON(const string& ruta) const;
    void cargarJSON(const string& ruta);

    ObjetoMagico* crearObjetoPorTipo(const string& tipo);
};

#endif //INVENTARIO_H
