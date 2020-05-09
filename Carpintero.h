#ifndef CARPINTERO_H
#define CARPINTERO_H

#include "Productor.h"

class Carpintero: public Productor {
public:
    Carpintero();
    Carpintero(const Carpintero& other) = delete;
    Carpintero& operator=(const Carpintero& other) = delete;
};

#endif // CARPINTERO_H
