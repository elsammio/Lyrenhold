#include "ObjetoMagico.h"
#include "Personaje.h"

ObjetoMagico::ObjetoMagico(const string& nombre, const string& desc)
    : nombreObjetoMagico(nombre), desc(desc) {}

string ObjetoMagico::getNombre() const {
    return nombreObjetoMagico;
}
