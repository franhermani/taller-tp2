#ifndef PRODUCTOR_H
#define PRODUCTOR_H

#include "Trabajador.h"

class Productor: public Trabajador {
    virtual void run() override;
};

#endif // PRODUCTOR_H
