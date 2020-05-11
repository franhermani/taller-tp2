#ifndef COCINERO_H
#define COCINERO_H

#include "Productor.h"
#include "Inventario.h"
#include "AcumuladorPuntos.h"

class Cocinero: public Productor {
    Inventario& inventario;
    AcumuladorPuntos& acumulador;
public:
    Cocinero(Inventario& inventario, AcumuladorPuntos& acumulador) :
             inventario(inventario), acumulador(acumulador) {}
    Cocinero(const Cocinero& other) = delete;
    Cocinero& operator=(const Cocinero& other) = delete;
};

#endif // COCINERO_H
