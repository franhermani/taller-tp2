#ifndef RECOLECTOR_H
#define RECOLECTOR_H

#include "Trabajador.h"

class Recolector: public Trabajador {
    virtual void run() override;
};

#endif // RECOLECTOR_H
