#ifndef ORCHESTRATOR_H
#define ORCHESTRATOR_H

#include <string>
#include <vector>
#include "Cola.h"
#include "Trabajador.h"
#include "Inventario.h"
#include "AcumuladorPuntos.h"

class Orchestrator {
    Cola colaAgricultores;
    Cola colaLeniadores;
    Cola colaMineros;
    std::vector<Trabajador*> trabajadores;
    Inventario inventario;
    AcumuladorPuntos acumuladorPuntos;
    int parsearLineaTrabajadores(const std::string& linea);
    int parsearCaracterRecursos(const char& c);
    void crearTrabajadores(const std::string& trabajador, int cant);
    void encolarRecurso(const char& c);
public:
    int procesarArchivoTrabajadores(const std::string& path);
    int procesarArchivoRecursos(const std::string& path);
    void iniciarTrabajadores();
    void finalizarTrabajadores();
    void imprimirEstadisticas();
};

#endif // ORCHESTRATOR_H
