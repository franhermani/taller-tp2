#ifndef ORCHESTRATOR_H
#define ORCHESTRATOR_H

#define NUM_COLAS 3

#include "ColaBloqueante.h"
#include "InputParser.h"

class Orchestrator {
    InputParser parser;
    ColaBloqueante colas[NUM_COLAS];

public:
    Orchestrator();
    int procesarArchivoTrabajadores(const char *path);
    int procesarArchivoMapa(const char *path);
};

#endif // ORCHESTRATOR_H
