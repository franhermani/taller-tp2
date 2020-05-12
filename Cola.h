#ifndef COLA_H
#define COLA_H

#include <mutex>
#include <condition_variable>
#include <queue>
#include "Recurso.h"

class Cola {
    std::mutex mutex;
    std::condition_variable cv;
    std::queue<Recurso> recursos;
    bool esta_cerrada;
public:
    Cola() : esta_cerrada(false) {}
    Cola(const Cola& other) = delete;
    Cola& operator=(const Cola& other) = delete;
    void encolar(Recurso recurso);
    Recurso desencolar();
    const int obtenerLargo();
    const bool estaVacia();
    void cerrar();
};

#endif // COLA_H
