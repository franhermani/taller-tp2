#ifndef RECOLECTOR_H
#define RECOLECTOR_H

#include "Trabajador.h"
#include "Cola.h"
#include "Inventario.h"

class Recolector: public Trabajador {
    Cola& cola;
    Inventario& inventario;
public:
    // Constructor
    // Recibe una referencia de la cola y del inventario
    Recolector(Cola& cola, Inventario& inventario) :
    cola(cola), inventario(inventario) {}

    // Constructor y asignacion por copia deshabilitados
    Recolector(const Recolector& other) = delete;
    Recolector& operator=(const Recolector& other) = delete;

    // Intenta desencolar recursos de la cola y depositarlos
    // en el inventario hasta que la cola se cierre
    virtual void run() override;
};

#endif // RECOLECTOR_H
