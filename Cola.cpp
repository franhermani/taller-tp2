#include "Cola.h"

void Cola::encolar(Recurso recurso) {
    this->recursos.push_back(recurso);
}

Recurso Cola::desencolar() {
    Recurso recurso = this->recursos.front();
    this->recursos.erase(this->recursos.begin());
    return std::move(recurso);
}
