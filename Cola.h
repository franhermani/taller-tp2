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
public:
    void encolar(Recurso recurso);
    Recurso desencolar();
    const bool estaVacia();
    const int obtenerLargo();
};

#endif // COLA_H
