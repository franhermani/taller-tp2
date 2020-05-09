#include "Cola.h"

void Cola::encolar(MateriaPrima materia_prima) {
    this->materias_primas.push_back(materia_prima);
}

MateriaPrima Cola::desencolar() {
    MateriaPrima materia_prima = this->materias_primas.front();
    this->materias_primas.erase(this->materias_primas.begin());
    return std::move(materia_prima);
}
