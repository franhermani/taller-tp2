#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
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
    while (getline(trabajadores_file, linea))
        if (parsearLineaTrabajadores(linea) == ERROR) return ERROR;

    trabajadores_file.close();

    return OK;
}

const int Orchestrator::procesarArchivoRecursos(const std::string& path) {
    std::ifstream recursos_file;
    recursos_file.open(path, std::ifstream::in);
    if (! recursos_file.good()) {
        std::cout << "Error al abrir el archivo de recursos\n";
        return ERROR;
    }
    std::string linea;
    while (getline(recursos_file, linea))
        for (char& c : linea) parsearCaracterRecursos(c);

    recursos_file.close();
    colaAgricultores.cerrar();
    colaMineros.cerrar();
    colaLeniadores.cerrar();

    return OK;
}

const int Orchestrator::parsearLineaTrabajadores(const std::string& linea) {
    std::vector<std::string> t = {AGRICULTORES, LENIADORES, MINEROS,
                                  COCINEROS, CARPINTEROS, ARMEROS};

    std::string trabajador = linea.substr(0, linea.find(DELIM)),
                cant = linea.substr(linea.find(DELIM) + 1, std::string::npos);

    if (std::count(t.begin(), t.end(), trabajador) == 0) {
        std::cout << "Trabajador inválido en el archivo de trabajadores\n";
        return ERROR;
    }
    try {
        int cant_i = std::stoi(cant);
        crearTrabajadores(trabajador, cant_i);
    }
    catch(std::invalid_argument) {
        std::cout << "Cantidad inválida en el archivo de trabajadores\n";
        return ERROR;
    }
    return OK;
}

void Orchestrator::parsearCaracterRecursos(const char& c) {
    std::vector<char> recursos = {CARBON, HIERRO, MADERA, TRIGO};

    if (std::count(recursos.begin(), recursos.end(), c) > 0)
        encolarRecurso(c);
}

void Orchestrator::crearTrabajadores(const std::string& trabajador,
                                     const int& cant) {
    if (trabajador == AGRICULTORES) {
        crearRecolectores(cant, colaAgricultores);
    } else if (trabajador == LENIADORES) {
        crearRecolectores(cant, colaLeniadores);
    } else if (trabajador == MINEROS) {
        crearRecolectores(cant, colaMineros);
    } else if (trabajador == COCINEROS) {
        crearProductores(cant, CANT_C_COCINERO, CANT_H_COCINERO,
                         CANT_M_COCINERO, CANT_T_COCINERO);
    } else if (trabajador == CARPINTEROS) {
        crearProductores(cant, CANT_C_CARPINTERO, CANT_H_CARPINTERO,
                         CANT_M_CARPINTERO, CANT_T_CARPINTERO);
    } else if (trabajador == ARMEROS) {
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
    std::cout << "Recursos restantes:\n"
    << "  - Trigo: " << inventario.obtenerSobrantesTrigo() << "\n"
    << "  - Madera: " << inventario.obtenerSobrantesMadera() << "\n"
    << "  - Carbon: " << inventario.obtenerSobrantesCarbon() << "\n"
    << "  - Hierro: " << inventario.obtenerSobrantesHierro() << "\n\n"
    << "Puntos de beneficio acumulados: " << acumuladorPuntos.obtenerPuntos()
    << "\n";
}
