#ifndef LENIADOR_H
#define LENIADOR_H

#include "Recolector.h"
#include "ColaLeniadores.h"
#include "Inventario.h"

class Leniador: public Recolector {
    ColaLeniadores& cola;
    Inventario& inventario;
public:
    Leniador(ColaLeniadores& cola, Inventario& inventario) :
             cola(cola), inventario(inventario) {}
    Leniador(const Leniador& other) = delete;
    Leniador& operator=(const Leniador& other) = delete;
};

#endif // LENIADOR_H
