#include "Recurso.h"

Recurso::Recurso(char tipo) {
    this->tipo = tipo;
}

const char Recurso::obtenerTipo() {
    return this->tipo;
}
