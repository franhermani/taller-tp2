#ifndef MINERO_H
#define MINERO_H

#include "Recolector.h"
#include "ColaMineros.h"

class Minero: public Recolector {
    ColaMineros& cola;
public:
    Minero(ColaMineros& cola) : cola(cola) {}
    Minero(const Minero& other) = delete;
    Minero& operator=(const Minero& other) = delete;
};

#endif // MINERO_H
