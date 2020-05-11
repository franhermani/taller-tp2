#ifndef COLAAGRICULTORES_H
#define COLAAGRICULTORES_H

#include "Cola.h"

class ColaAgricultores: public Cola {
public:
    ColaAgricultores();
    ColaAgricultores(const ColaAgricultores& other) = delete;
    ColaAgricultores& operator=(const ColaAgricultores& other) = delete;
};

#endif // COLAAGRICULTORES_H
