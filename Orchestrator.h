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
    const int parsearLineaTrabajadores(const std::string& linea);
    const int parsearCaracterRecursos(const char& c);
    void crearTrabajadores(const std::string& trabajador, const int& cant);
    void encolarRecurso(const char& c);
public:
    Orchestrator() {}
    Orchestrator(const Orchestrator& other) = delete;
    Orchestrator& operator=(const Orchestrator& other) = delete;
    const int procesarArchivoTrabajadores(const std::string& path);
    const int procesarArchivoRecursos(const std::string& path);
    void iniciarTrabajadores();
    void finalizarTrabajadores();
    void imprimirEstadisticas();
};

#endif // ORCHESTRATOR_H
