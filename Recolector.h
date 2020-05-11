#ifndef RECOLECTOR_H
#define RECOLECTOR_H

#include <mutex>
#include "Trabajador.h"
#include "Cola.h"
#include "Inventario.h"

class Recolector: public Trabajador {
    std::mutex& mutex;
    Cola& cola;
    Inventario& inventario;
public:
    Recolector(std::mutex& mutex, Cola& cola, Inventario& inventario) :
    mutex(mutex), cola(cola), inventario(inventario) {}
    Recolector(const Recolector& other) = delete;
    Recolector& operator=(const Recolector& other) = delete;
    virtual void run() override;
};

#endif // RECOLECTOR_H
