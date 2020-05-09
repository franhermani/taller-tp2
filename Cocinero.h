#ifndef COCINERO_H
#define COCINERO_H

#include "Productor.h"

class Cocinero: public Productor {
public:
    Cocinero();
    Cocinero(const Cocinero& other) = delete;
    Cocinero& operator=(const Cocinero& other) = delete;
};

#endif // COCINERO_H
