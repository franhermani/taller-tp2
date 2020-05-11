#ifndef RECOLECTOR_H
#define RECOLECTOR_H

#include "Trabajador.h"
#include "Cola.h"
#include "Inventario.h"

class Recolector: public Trabajador {
    Cola& cola;
    Inventario& inventario;
public:
    Recolector(Cola& cola, Inventario& inventario) :
    cola(cola), inventario(inventario) {}
    Recolector(const Recolector& other) = delete;
    Recolector& operator=(const Recolector& other) = delete;
    virtual void run() override;
};

#endif // RECOLECTOR_H
