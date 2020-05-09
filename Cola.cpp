#include <iostream>
#include "Cola.h"

void Cola::encolar(MateriaPrima materia_prima) {
    this->materias_primas.push_back(materia_prima);
    std::cout << this->materias_primas.size() << std::endl;
}

MateriaPrima Cola::desencolar() {
    MateriaPrima materia_prima = this->materias_primas.front();
    this->materias_primas.erase(this->materias_primas.begin());
    return materia_prima;
}
