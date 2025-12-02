#include "Inventario.h"
#include "ObjetoMagico.h"
#include "PocionVida.h"
#include "AmuletoFuria.h"
#include "EscudoBendito.h"
#include "EscudoReflectivo.h"
#include "PocionVeneno.h"
#include "Cancelacion.h"
#include "Personaje.h"

#include <iostream>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;

Inventario::Inventario() {}

void Inventario::crear(ObjetoMagico* obj, int cantidad) {
    if (!obj) return;
    stock[obj->getNombre()] += cantidad;
}

void Inventario::listar() const {
    cout << "=== Inventario ===\n";

    for (const auto& p : stock) {
        string nombre = p.first;
        int cantidad = p.second;

        ObjetoMagico* temp = nullptr;

        if (nombre == "PocionVida")
            temp = new PocionVida("PocionVida", "Restaura entre 20 y 40 puntos de vida.", 20, 40);

        else if (nombre == "AmuletoFuria")
            temp = new AmuletoFuria("AmuletoFuria", "Aumenta el ataque entre 5 y 10 puntos.", 5, 10);

        else if (nombre == "EscudoBendito")
            temp = new EscudoBendito("EscudoBendito", "Aumenta defensa entre 10 y 20 puntos.", 10, 20);

        else if (nombre == "EscudoReflectivo")
            temp = new EscudoReflectivo("EscudoReflectivo", "Refleja el dano que le hagan al portador.", 15);

        else if (nombre == "PocionVeneno")
            temp = new PocionVeneno("PocionVeneno", "Resta vida por envenenamiento.", 12);

        else if (nombre == "Cancelacion")
            temp = new Cancelacion("Cancelacion", "Incapacita al rival por el resto de la partida.", 1);

        if (temp) {
            cout << "- " << nombre << ": " << cantidad
                 << " | " << temp->getDescripcion() << endl;
            delete temp;
        } else {
            cout << "- " << nombre << ": " << cantidad << endl;
        }
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

bool Inventario::asignar(Personaje* p, ObjetoMagico* obj) {
    if (!p || !obj) return false;
    string key = obj->getNombre();

    auto it = stock.find(key);
    if (it == stock.end() || it->second <= 0) {
        return false; // no hay stock
    }
    auto &vec = asignados[p];
    if ((int)vec.size() >= 2) {
        return false; // limite 2
    }

    it->second -= 1;
    vec.push_back(obj);
    return true;
}

bool Inventario::retirar(Personaje* p, const string& nombre) {
    if (!p) return false;
    auto it = asignados.find(p);
    if (it == asignados.end()) return false;
    auto &vec = it->second;

    for (auto vit = vec.begin(); vit != vec.end(); ++vit) {
        if ((*vit)->getNombre() == nombre) {
            stock[nombre] += 1;
            delete *vit;
            vec.erase(vit);
            return true;
        }
    }
    return false;
}

bool Inventario::usarAsignado(Personaje* p, const string& nombre) {
    if (!p) return false;
    auto it = asignados.find(p);
    if (it == asignados.end()) return false;
    auto &vec = it->second;

    for (auto vit = vec.begin(); vit != vec.end(); ++vit) {
        if ((*vit)->getNombre() == nombre) {
            (*vit)->usar(p);
            delete *vit;
            vec.erase(vit);
            return true;
        }
    }
    return false;
}

vector<string> Inventario::listarAsignados(Personaje* p) const {
    vector<string> res;
    auto it = asignados.find(p);
    if (it == asignados.end()) return res;
    for (auto o : it->second) res.push_back(o->getNombre());
    return res;
}

ObjetoMagico* Inventario::buscarAsignado(Personaje* p, const string& nombre) const {
    auto it = asignados.find(p);
    if (it == asignados.end()) return nullptr;
    for (auto o : it->second) {
        if (o->getNombre() == nombre) return o;
    }
    return nullptr;
}

bool Inventario::eliminarAsignado(Personaje* p, const string& nombre) {
    if (!p) return false;

    auto it = asignados.find(p);
    if (it == asignados.end()) return false;

    auto &vec = it->second;

    for (auto vit = vec.begin(); vit != vec.end(); ++vit) {
        if ((*vit)->getNombre() == nombre) {
            vec.erase(vit);
            return true;
        }
    }
    return false;
}
