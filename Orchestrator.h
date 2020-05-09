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
    int procesarArchivoRecursos(const std::string& path);
    int parsearLineaTrabajadores(const std::string& linea);
    int parsearCaracterRecursos(const char& c);
    void crearTrabajadores(const std::string& trabajador, int cant);
    void crearRecurso(const char& c);
};

#endif // ORCHESTRATOR_H
