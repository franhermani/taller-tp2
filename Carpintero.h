#ifndef CARPINTERO_H
#define CARPINTERO_H

#include "Productor.h"
#include "Inventario.h"
#include "AcumuladorPuntos.h"

class Carpintero: public Productor {
    Inventario& inventario;
    AcumuladorPuntos& acumulador;
public:
    Carpintero(Inventario& inventario, AcumuladorPuntos& acumulador) :
               inventario(inventario), acumulador(acumulador) {}
    Carpintero(const Carpintero& other) = delete;
    Carpintero& operator=(const Carpintero& other) = delete;
};

#endif // CARPINTERO_H
