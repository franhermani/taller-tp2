#include <vector>
#include "Cola.h"

Cola::Cola() {
    std::vector<Recurso> recursos;
    this->recursos = recursos;
}

void Cola::encolar(Recurso recurso) {
    this->recursos.push_back(std::move(recurso));
}

Recurso Cola::desencolar() {
    Recurso recurso = this->recursos.front();
    this->recursos.erase(this->recursos.begin());
    return std::move(recurso);
}

const int Cola::obtenerLargo() {
    return this->recursos.size();
}
