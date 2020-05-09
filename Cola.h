#ifndef COLA_H
#define COLA_H

#include <vector>
#include "MateriaPrima.h"

class Cola {
    std::vector<MateriaPrima> materias_primas;
public:
    void encolar(MateriaPrima materia_prima);
    MateriaPrima desencolar();
};

#endif // COLA_H
