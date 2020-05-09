#ifndef COLA_H
#define COLA_H

#include <vector>
#include "Recurso.h"

class Cola {
    std::vector<Recurso> recursos;
public:
    void encolar(Recurso recurso);
    Recurso desencolar();
};

#endif // COLA_H
