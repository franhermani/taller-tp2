#ifndef TRABAJADOR_H
#define TRABAJADOR_H

#include "Thread.h"

class Trabajador: public Thread {
    virtual void run() override;
};

#endif // TRABAJADOR_H
