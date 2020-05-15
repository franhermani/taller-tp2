#include <iostream>
#include <fstream>
#include <string>
#include "defines.h"
#include "Orchestrator.h"
#include "Recurso.h"
#include "Recolector.h"
#include "Productor.h"

#define OK 0
#define ERROR 1

Orchestrator::Orchestrator() {}

const int Orchestrator::procesarArchivoTrabajadores(const std::string& path) {
    std::ifstream trabajadores_file;
    trabajadores_file.open(path, std::ifstream::in);
    if (! trabajadores_file.good()) {
        std::cout << "Error al abrir el archivo de trabajadores\n";
        return ERROR;
    }
    std::string linea;
    while (getline(trabajadores_file, linea)) {
        if (parsearLineaTrabajadores(linea) == ERROR)
            return ERROR;
    }
    trabajadores_file.close();

    return OK;
}

const int Orchestrator::procesarArchivoRecursos(const std::string& path) {
    std::ifstream recursos_file;
    recursos_file.open(path, std::ifstream::in);
    if (! recursos_file.good()) {
        std::cout << "Error al abrir el archivo de materias primas\n";
        return ERROR;
    }
    char c;
    while (recursos_file.get(c)) {
        if (c == '\n') continue;
        if (parsearCaracterRecursos(c) == ERROR) return ERROR;
    }
    recursos_file.close();
    colaAgricultores.cerrar();
    colaMineros.cerrar();
    colaLeniadores.cerrar();

    return OK;
}

const int Orchestrator::parsearLineaTrabajadores(const std::string& linea) {
    std::string trabajadores[NUM_TRABAJADORES] =
            {"Agricultores", "Leniadores", "Mineros",
             "Cocineros", "Carpinteros", "Armeros"};

    std::string delimiter = "=",
                trabajador = linea.substr(0, linea.find(delimiter)),
                cant = linea.substr(linea.find(delimiter) + 1,
                                    std::string::npos);

    bool trabajador_ok = false;
    int i;
    for (i = 0; i < NUM_TRABAJADORES; i ++) {
        if (trabajadores[i] == trabajador) {
            trabajador_ok = true;
            break;
        }
    }
    if (! trabajador_ok) {
        std::cout << "Trabajador inválido";
        return ERROR;
    }
    try {
        int cant_i = std::stoi(cant);
        crearTrabajadores(trabajador, cant_i);
    }
    catch(std::invalid_argument) {
        std::cout << "Cantidad inválida";
        return ERROR;
    }
    return OK;
}

const int Orchestrator::parsearCaracterRecursos(const char& c) {
    char recursos[NUM_RECURSOS] = {CARBON, HIERRO, MADERA, TRIGO};

    bool recurso_ok = false;
    int i;
    for (i = 0; i < NUM_RECURSOS; i++) {
        if (recursos[i] == c) {
            recurso_ok = true;
            break;
        }
    }
    if (!recurso_ok) {
        std::cout << "Recurso inválido";
        return ERROR;
    }
    encolarRecurso(c);

    return OK;
}

void Orchestrator::crearTrabajadores(const std::string& trabajador,
                                     const int& cant) {
    if (trabajador == "Agricultores") {
        crearRecolectores(cant, colaAgricultores);
    } else if (trabajador == "Leniadores") {
        crearRecolectores(cant, colaLeniadores);
    } else if (trabajador == "Mineros") {
        crearRecolectores(cant, colaMineros);
    } else if (trabajador == "Cocineros") {
        crearProductores(cant, CANT_C_COCINERO, CANT_H_COCINERO,
                         CANT_M_COCINERO, CANT_T_COCINERO);
    } else if (trabajador == "Carpinteros") {
        crearProductores(cant, CANT_C_CARPINTERO, CANT_H_CARPINTERO,
                         CANT_M_CARPINTERO, CANT_T_CARPINTERO);
    } else if (trabajador == "Armeros") {
        crearProductores(cant, CANT_C_ARMERO, CANT_H_ARMERO,
                         CANT_M_ARMERO, CANT_T_ARMERO);
    }
}

void Orchestrator::crearRecolectores(const int& cant, Cola& cola) {
    int i;
    for (i = 0; i < cant; i ++)
        recolectores.push_back(new Recolector(cola, inventario));
}

void Orchestrator::crearProductores(const int& cant, int cant_carbon,
                                    int cant_hierro, int cant_madera,
                                    int cant_trigo) {
    int i;
    for (i = 0; i < cant; i ++)
        productores.push_back(new Productor(inventario, acumuladorPuntos,
                              cant_carbon, cant_hierro, cant_madera,
                              cant_trigo));
}

void Orchestrator::encolarRecurso(const char &c) {
    Recurso recurso(c);

    if (c == CARBON || c == HIERRO) {
        colaMineros.encolar(std::move(recurso));
    } else if (c == MADERA) {
        colaLeniadores.encolar(std::move(recurso));
    } else if (c == TRIGO) {
        colaAgricultores.encolar(std::move(recurso));
    }
}

void Orchestrator::iniciarTrabajadores() {
    size_t i;
    for (i = 0; i < recolectores.size(); i ++)
        recolectores[i]->start();

    for (i = 0; i < productores.size(); i ++)
        productores[i]->start();
}

void Orchestrator::finalizarTrabajadores() {
    size_t i;
    for (i = 0; i < recolectores.size(); i ++) {
        recolectores[i]->join();
        delete recolectores[i];
    }
    inventario.cerrar();

    for (i = 0; i < productores.size(); i ++) {
        productores[i]->join();
        delete productores[i];
    }
}

void Orchestrator::imprimirEstadisticas() {
    std::cout << "Recursos restantes:";
    std::cout << "\n  - Trigo: " << inventario.obtenerSobrantesTrigo();
    std::cout << "\n  - Madera: " << inventario.obtenerSobrantesMadera();
    std::cout << "\n  - Carbon: " << inventario.obtenerSobrantesCarbon();
    std::cout << "\n  - Hierro: " << inventario.obtenerSobrantesHierro();
    std::cout << "\n\nPuntos de beneficio acumulados: "
              << acumuladorPuntos.obtenerPuntos() << "\n";
}
