#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <string>
#include <map>
#include <vector>

class ObjetoMagico;
class Personaje;

class Inventario {
private:
    std::map<std::string, int> stock;
    std::map<Personaje*, std::vector<ObjetoMagico*>> asignados;
    std::map<std::string, ObjetoMagico*> catalogo;
public:
    Inventario();

    void crear(ObjetoMagico* obj, int cantidad);
    void listar() const;
    void consultar(const std::string& nombre) const;
    void actualizarStock(const std::string& nombre, int cant);
    void eliminar(const std::string& nombre);

    bool asignar(Personaje* p, ObjetoMagico* obj);
    bool retirar(Personaje* p, const std::string& nombre);

    bool usarAsignado(Personaje* p, const std::string& nombre);

    bool eliminarAsignado(Personaje* p, const std::string& nombre);


    std::vector<std::string> listarAsignados(Personaje* p) const;
    ObjetoMagico* buscarAsignado(Personaje* p, const std::string& nombre) const;

    const std::map<std::string,int>& getStock() const { return stock; }
};

#endif
