#ifndef LENIADOR_H
#define LENIADOR_H

#include "Recolector.h"
#include "Cola.h"
#include "Inventario.h"

class Leniador: public Recolector {
    Cola& cola;
    Inventario& inventario;
public:
    Leniador(Cola& cola, Inventario& inventario) :
             cola(cola), inventario(inventario) {}
    Leniador(const Leniador& other) = delete;
    Leniador& operator=(const Leniador& other) = delete;
};

#endif // LENIADOR_H
