#ifndef AGRICULTOR_H
#define AGRICULTOR_H

#include "Recolector.h"

class Agricultor: public Recolector {
public:
    Agricultor();
    Agricultor(const Agricultor& other) = delete;
    Agricultor& operator=(const Agricultor& other) = delete;
};

#endif // AGRICULTOR_H
