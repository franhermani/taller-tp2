#ifndef TRABAJADOR_H
#define TRABAJADOR_H

#include "Thread.h"

class Trabajador: public Thread {
    virtual void run() = 0;
};

#endif // TRABAJADOR_H
