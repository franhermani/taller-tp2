#include <mutex>
#include <queue>
#include "Cola.h"
#include "ColaCerradaException.h"

void Cola::encolar(Recurso recurso) {
    std::unique_lock<std::mutex> lock(mutex);

    recursos.push(std::move(recurso));
    cv.notify_all();
}

Recurso Cola::desencolar() {
    std::unique_lock<std::mutex> lock(mutex);

    while (estaVacia()) {
        if (esta_cerrada) throw ColaCerradaException();
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

const bool Cola::estaVacia() {
    std::unique_lock<std::mutex> lock(mutex);
    return recursos.empty();
}

void Cola::cerrar() {
    std::unique_lock<std::mutex> lock(mutex);
    esta_cerrada = true;
    cv.notify_all();
}
