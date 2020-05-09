#ifndef ARMERO_H
#define ARMERO_H

#include "Productor.h"

class Armero: public Productor {
public:
    Armero();
    Armero(const Armero& other) = delete;
    Armero& operator=(const Armero& other) = delete;
};

#endif // ARMERO_H
