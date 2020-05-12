#ifndef COLA_H
#define COLA_H

#include <vector>
#include <mutex>
#include "Recurso.h"

class Cola {
    std::mutex mutex;
    std::vector<Recurso> recursos;
public:
    Cola();
    void encolar(Recurso recurso);
    Recurso desencolar();
    const int obtenerLargo();
};

#endif // COLA_H
