#ifndef AGRICULTOR_H
#define AGRICULTOR_H

#include "Recolector.h"
#include "Cola.h"
#include "Inventario.h"

class Agricultor: public Recolector {
    Cola& cola;
    Inventario& inventario;
public:
    Agricultor(Cola& cola, Inventario& inventario) :
               cola(cola), inventario(inventario) {}
    Agricultor(const Agricultor& other) = delete;
    Agricultor& operator=(const Agricultor& other) = delete;
};

#endif // AGRICULTOR_H
