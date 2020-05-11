#ifndef AGRICULTOR_H
#define AGRICULTOR_H

#include "Recolector.h"
#include "ColaAgricultores.h"

class Agricultor: public Recolector {
    ColaAgricultores *cola;
public:
    explicit Agricultor(ColaAgricultores *cola);
    Agricultor(const Agricultor& other) = delete;
    Agricultor& operator=(const Agricultor& other) = delete;
};

#endif // AGRICULTOR_H
