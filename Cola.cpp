#include <mutex>
#include <queue>
#include "Cola.h"
#include "ColaCerradaException.h"
#include "Lock.h"

void Cola::encolar(Recurso recurso) {
//    Lock lock(mutex);
    std::unique_lock<std::mutex> lock(mutex);

    recursos.push(std::move(recurso));
    cv.notify_all();
}

Recurso Cola::desencolar() {
//    Lock lock(mutex);
    std::unique_lock<std::mutex> lock(mutex);

    while (estaVacia()) {
        if (esta_cerrada) throw ColaCerradaException();
        cv.wait(lock);
    }
    Recurso recurso = recursos.front();
    recursos.pop();
    return std::move(recurso);
}

const bool Cola::estaVacia() {
//    Lock lock(mutex);
    std::unique_lock<std::mutex> lock(mutex);

    return recursos.empty();
}

const int Cola::obtenerLargo() {
//    Lock lock(mutex);
    std::unique_lock<std::mutex> lock(mutex);

    return recursos.size();
}

void Cola::cerrar() {
//    Lock lock(mutex);
    std::unique_lock<std::mutex> lock(mutex);

    esta_cerrada = true;
    cv.notify_all();
}
