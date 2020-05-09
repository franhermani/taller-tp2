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
    int procesarArchivoTrabajadores(const std::string& path);
    int procesarArchivoMapa(const std::string& path);
    int parsearLineaTrabajadores(const std::string& line);
    int parsearCaracterMapa(const char& c);
    void crearTrabajadores(const std::string& worker, int quant);
};

#endif // ORCHESTRATOR_H
