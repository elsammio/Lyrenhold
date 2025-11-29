//
// Created by Luis Alejandro Peña on 23/11/2025.
//

#ifndef OBJETO_MAGICO_H
#define OBJETO_MAGICO_H

#include <iostream>
using std::string;

class Personaje;

class ObjetoMagico {
protected:
    string nombreObjetoMagico;
    string desc;

public:
    ObjetoMagico(const string& nombre, const string& desc);
    virtual ~ObjetoMagico() {}

    virtual void usar(Personaje* personaje) = 0;

    string getNombre() const;

    // NUEVO: para mostrar descripción en el inventario
    string getDescripcion() const { return desc; }
};

#endif
