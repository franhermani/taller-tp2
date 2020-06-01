#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
#include "defines.h"
#include "Orchestrator.h"
#include "Recurso.h"
#include "Recolector.h"
#include "Productor.h"

Orchestrator::Orchestrator() {}

void Orchestrator::procesarArchivoTrabajadores(const std::string& path) {
    std::map<std::string, int> trabajadores_map =
            parser.parsearArchivoTrabajadores(path);

    for (auto const& kv : trabajadores_map)
        crearTrabajadores(kv.first, kv.second);
}

void Orchestrator::procesarArchivoRecursos(const std::string& path) {
    std::vector<char> recursos_vector = parser.parsearArchivoRecursos(path);

    for (const char& c: recursos_vector)
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

void Orchestrator::encolarRecurso(const char& c) {
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
    cerrarInventario();

    for (i = 0; i < productores.size(); i ++) {
        productores[i]->join();
        delete productores[i];
    }
}

void Orchestrator::cerrarColas() {
    colaAgricultores.cerrar();
    colaLeniadores.cerrar();
    colaMineros.cerrar();
}

void Orchestrator::cerrarInventario() {
    inventario.cerrar();
}

void Orchestrator::imprimirEstadisticas() {
    std::cout << "Recursos restantes:\n"
    << "  - Trigo: " << inventario.obtenerSobrantesTrigo() << "\n"
    << "  - Madera: " << inventario.obtenerSobrantesMadera() << "\n"
    << "  - Carbon: " << inventario.obtenerSobrantesCarbon() << "\n"
    << "  - Hierro: " << inventario.obtenerSobrantesHierro() << "\n\n"
    << "Puntos de Beneficio acumulados: " << acumuladorPuntos.obtenerPuntos()
    << "\n";
}
