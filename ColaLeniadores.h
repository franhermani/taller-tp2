#ifndef COLALENIADORES_H
#define COLALENIADORES_H

#include "Cola.h"

class ColaLeniadores: public Cola {
public:
    ColaLeniadores();
    ColaLeniadores(const ColaLeniadores& other) = delete;
};

#endif // COLALENIADORES_H
