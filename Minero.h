#ifndef MINERO_H
#define MINERO_H

#include "Recolector.h"

class Minero: public Recolector {
public:
    Minero();
    Minero(const Minero& other) = delete;
    Minero& operator=(const Minero& other) = delete;
};

#endif // MINERO_H
