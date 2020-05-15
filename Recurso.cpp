#include "Recurso.h"

Recurso::Recurso(const char& tipo) : tipo(tipo) {}

const char Recurso::obtenerTipo() const {
    return tipo;
}
