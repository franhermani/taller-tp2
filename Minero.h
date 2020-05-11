#ifndef MINERO_H
#define MINERO_H

#include "Recolector.h"
#include "Cola.h"
#include "Inventario.h"

class Minero: public Recolector {
    Cola& cola;
    Inventario& inventario;
public:
    Minero(Cola& cola, Inventario& inventario) :
           cola(cola), inventario(inventario) {}
    Minero(const Minero& other) = delete;
    Minero& operator=(const Minero& other) = delete;
};

#endif // MINERO_H
