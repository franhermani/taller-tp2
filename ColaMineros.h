#ifndef COLAMINEROS_H
#define COLAMINEROS_H

#include "Cola.h"

class ColaMineros: public Cola {
public:
    ColaMineros();
    ColaMineros(const ColaMineros& other) = delete;
};

#endif //COLAMINEROS_H
