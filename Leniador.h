#ifndef LENIADOR_H
#define LENIADOR_H

#include "Recolector.h"
#include "ColaLeniadores.h"

class Leniador: public Recolector {
    ColaLeniadores& cola;
public:
    Leniador(ColaLeniadores& cola) : cola(cola) {}
    Leniador(const Leniador& other) = delete;
    Leniador& operator=(const Leniador& other) = delete;
};

#endif // LENIADOR_H
