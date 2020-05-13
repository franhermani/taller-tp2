#include <iostream>
#include <fstream>
#include <string>
#include "Orchestrator.h"
#include "Recurso.h"
#include "Recolector.h"
#include "Productor.h"

#define OK 0
#define ERROR 1
#define NUM_RECURSOS 4
#define NUM_TRABAJADORES 6

#define CANT_C_COCINERO 1
#define CANT_H_COCINERO 0
#define CANT_M_COCINERO 0
#define CANT_T_COCINERO 2

#define CANT_C_CARPINTERO 0
#define CANT_H_CARPINTERO 1
#define CANT_M_CARPINTERO 3
#define CANT_T_CARPINTERO 0

#define CANT_C_ARMERO 2
#define CANT_H_ARMERO 2
#define CANT_M_ARMERO 0
#define CANT_T_ARMERO 0

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
    char recursos[NUM_RECURSOS] = {'C', 'H', 'M', 'T'};

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
    int i;

    if (trabajador == "Agricultores") {
        for (i = 0; i < cant; i ++)
            trabajadores.push_back(
                    new Recolector(colaAgricultores, inventario));

    } else if (trabajador == "Leniadores") {
        for (i = 0; i < cant; i ++)
            trabajadores.push_back(
                    new Recolector(colaLeniadores, inventario));

    } else if (trabajador == "Mineros") {
        for (i = 0; i < cant; i ++)
            trabajadores.push_back(
                    new Recolector(colaMineros, inventario));

    } else if (trabajador == "Cocineros") {
        for (i = 0; i < cant; i ++)
            trabajadores.push_back(
                    new Productor(inventario, acumuladorPuntos,
                                  CANT_C_COCINERO, CANT_H_COCINERO,
                                  CANT_M_COCINERO, CANT_T_COCINERO));

    } else if (trabajador == "Carpinteros") {
        for (i = 0; i < cant; i ++)
            trabajadores.push_back(
                    new Productor(inventario, acumuladorPuntos,
                                  CANT_C_CARPINTERO, CANT_H_CARPINTERO,
                                  CANT_M_CARPINTERO, CANT_T_CARPINTERO));

    } else if (trabajador == "Armeros") {
        for (i = 0; i < cant; i ++)
            trabajadores.push_back(
                    new Productor(inventario, acumuladorPuntos,
                                  CANT_C_ARMERO, CANT_H_ARMERO,
                                  CANT_M_ARMERO, CANT_T_ARMERO));
    }
}

void Orchestrator::encolarRecurso(const char &c) {
    Recurso recurso(c);

    switch (c) {
        case 'C':
            colaMineros.encolar(std::move(recurso));
            break;
        case 'H':
            colaMineros.encolar(std::move(recurso));
            break;
        case 'M':
            colaLeniadores.encolar(std::move(recurso));
            break;
        case 'T':
            colaAgricultores.encolar(std::move(recurso));
            break;
    }
}

void Orchestrator::iniciarTrabajadores() {
    size_t i;
    for (i = 0; i < trabajadores.size(); i ++)
        trabajadores[i]->start();
}

void Orchestrator::finalizarTrabajadores() {
    size_t i;
    for (i = 0; i < trabajadores.size(); i ++) {
        trabajadores[i]->join();
        delete trabajadores[i];
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
