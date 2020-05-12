#include <queue>
#include <mutex>
#include "Cola.h"
#include "ColaVaciaException.h"
#include "Lock.h"

void Cola::encolar(Recurso recurso) {
    Lock lock(mutex);
    recursos.push(std::move(recurso));
}

Recurso Cola::desencolar() {
    if (estaVacia()) throw ColaVaciaException();

    Lock lock(mutex);
    Recurso recurso = recursos.front();
    recursos.pop();
    return std::move(recurso);
}

const bool Cola::estaVacia() {
    Lock lock(mutex);
    return recursos.empty();
}

const int Cola::obtenerLargo() {
    Lock lock(mutex);
    return recursos.size();
}
