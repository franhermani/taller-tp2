#ifndef ARMERO_H
#define ARMERO_H

#include "Productor.h"
#include "Inventario.h"
#include "AcumuladorPuntos.h"

class Armero: public Productor {
    Inventario& inventario;
    AcumuladorPuntos& acumulador;
public:
    Armero(Inventario& inventario, AcumuladorPuntos& acumulador) :
           inventario(inventario), acumulador(acumulador) {}
    Armero(const Armero& other) = delete;
    Armero& operator=(const Armero& other) = delete;
};

#endif // ARMERO_H
