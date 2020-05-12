#include <vector>
#include <mutex>
#include "Cola.h"
#include "ColaVaciaException.h"
#include "Lock.h"

Cola::Cola() {
    std::vector<Recurso> recursos;
    this->recursos = recursos;
}

void Cola::encolar(Recurso recurso) {
    this->recursos.push_back(std::move(recurso));
}

Recurso Cola::desencolar() {
    if (this->obtenerLargo() == 0) throw ColaVaciaException();

    Lock lock(this->mutex);
    Recurso recurso = this->recursos.front();
    this->recursos.erase(this->recursos.begin());
    return std::move(recurso);
}

const int Cola::obtenerLargo() {
    Lock lock(this->mutex);
    return this->recursos.size();
}
