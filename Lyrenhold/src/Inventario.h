//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#ifndef INVENTARIO_H
#define INVENTARIO_H
<<<<<<< HEAD

#include <iostream>
#include <map>
#include <vector>
=======
#include <map>
>>>>>>> 48e9cccc5f36e66f969b4096d8f97f1e0b12605b

using std::string;
using std::map;
using std::vector;

class Personaje;
class ObjetoMagico;

class Inventario {
private:
<<<<<<< HEAD
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
=======
    std::map<string, int> stock;
    std::map<>asisgnados;
>>>>>>> 48e9cccc5f36e66f969b4096d8f97f1e0b12605b
};

#endif //INVENTARIO_H
