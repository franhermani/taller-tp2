#include <mutex>
#include <queue>
#include "Cola.h"
#include "ColaCerradaException.h"

Cola::Cola() : estaCerrada(false) {}

void Cola::encolar(Recurso recurso) {
    std::unique_lock<std::mutex> lock(mutex);
    recursos.push(std::move(recurso));
    cv.notify_all();
}

Recurso Cola::desencolar() {
    std::unique_lock<std::mutex> lock(mutex);

    while (recursos.empty()) {
        if (estaCerrada) throw ColaCerradaException();
        cv.wait(lock);
    }
    Recurso recurso = recursos.front();
    recursos.pop();
    return std::move(recurso);
}

const int Cola::obtenerLargo() {
    std::unique_lock<std::mutex> lock(mutex);
    return recursos.size();
}

void Cola::cerrar() {
    std::unique_lock<std::mutex> lock(mutex);
    estaCerrada = true;
    cv.notify_all();
}
