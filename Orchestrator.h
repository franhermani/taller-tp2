#ifndef ORCHESTRATOR_H
#define ORCHESTRATOR_H

#include <string>
#include <vector>
#include "ColaAgricultores.h"
#include "ColaLeniadores.h"
#include "ColaMineros.h"
#include "Trabajador.h"

class Orchestrator {
    ColaAgricultores colaAgricultores;
    ColaLeniadores colaLeniadores;
    ColaMineros colaMineros;
    std::vector<Trabajador> trabajadores;
public:
    Orchestrator();
    int procesarArchivoTrabajadores(const char *path);
    int procesarArchivoMapa(const char *path);
    int parsearLineaTrabajadores(std::string line);
    int parsearCaracterMapa(char c);
    void crearTrabajadores(std::string worker, int quant);
};

#endif // ORCHESTRATOR_H
