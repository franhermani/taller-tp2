#include <iostream>
#include <fstream>
#include <string>
#include "Recurso.h"
#include "Orchestrator.h"
#include "Agricultor.h"
#include "Leniador.h"
#include "Minero.h"
#include "Carpintero.h"
#include "Cocinero.h"
#include "Armero.h"

#define OK 0
#define ERROR 1
#define NUM_RECURSOS 4
#define NUM_TRABAJADORES 6

Orchestrator::Orchestrator() {
    this->colaAgricultores = ColaAgricultores();
    this->colaLeniadores = ColaLeniadores();
    this->colaMineros = ColaMineros();
    this->inventario = Inventario();
    this->acumuladorPuntos = AcumuladorPuntos();
}

int Orchestrator::procesarArchivoTrabajadores(const std::string& path) {
    std::ifstream trabajadores_file;
    trabajadores_file.open(path, std::ifstream::in);
    if (! trabajadores_file.good()) {
        std::cout << "Error al abrir el archivo de trabajadores\n";
        return ERROR;
    }
    std::string linea;
    while (getline(trabajadores_file, linea)) {
        if (this->parsearLineaTrabajadores(linea) == ERROR)
            return ERROR;
    }
    trabajadores_file.close();

    return OK;
}

int Orchestrator::procesarArchivoRecursos(const std::string& path) {
    std::ifstream recursos_file;
    recursos_file.open(path, std::ifstream::in);
    if (! recursos_file.good()) {
        std::cout << "Error al abrir el archivo de materias primas\n";
        return ERROR;
    }
    char c;
    while (recursos_file.get(c)) {
        if (c == '\n') continue;
        if (this->parsearCaracterRecursos(c) == ERROR) return ERROR;
    }
    recursos_file.close();

    return OK;
}

int Orchestrator::parsearLineaTrabajadores(const std::string& linea) {
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
        this->crearTrabajadores(trabajador, cant_i);
    }
    catch(std::invalid_argument) {
        std::cout << "Cantidad inválida";
        return ERROR;
    }
    return OK;
}

int Orchestrator::parsearCaracterRecursos(const char& c) {
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
    this->encolarRecurso(c);

    return OK;
}

void Orchestrator::crearTrabajadores(const std::string& trabajador, int cant) {
    int i;

    if (trabajador == "Agricultores") {
        for (i = 0; i < cant; i ++)
            this->trabajadores.push_back(
                    new Agricultor(this->colaAgricultores));
    } else if (trabajador == "Leniadores") {
        for (i = 0; i < cant; i ++)
            this->trabajadores.push_back(
                    new Leniador(this->colaLeniadores));
    } else if (trabajador == "Mineros") {
        for (i = 0; i < cant; i ++)
            this->trabajadores.push_back(
                    new Minero(this->colaMineros));
    } else if (trabajador == "Cocineros") {
        for (i = 0; i < cant; i ++)
            this->trabajadores.push_back(
                    new Cocinero());
    } else if (trabajador == "Carpinteros") {
        for (i = 0; i < cant; i ++)
            this->trabajadores.push_back(
                    new Carpintero());
    } else if (trabajador == "Armeros") {
        for (i = 0; i < cant; i ++)
            this->trabajadores.push_back(
                    new Armero());
    }
}

void Orchestrator::encolarRecurso(const char &c) {
    Recurso recurso(c);

    switch (c) {
        case 'C':
            this->colaMineros.encolar(std::move(recurso));
            break;
        case 'H':
            this->colaMineros.encolar(std::move(recurso));
            break;
        case 'M':
            this->colaLeniadores.encolar(std::move(recurso));
            break;
        case 'T':
            this->colaAgricultores.encolar(std::move(recurso));
            break;
    }
}

void Orchestrator::iniciarTrabajadores() {
    size_t i;
    for (i = 0; i < this->trabajadores.size(); i ++)
        this->trabajadores[i]->start();
}

void Orchestrator::finalizarTrabajadores() {
    size_t i;
    for (i = 0; i < this->trabajadores.size(); i ++) {
        this->trabajadores[i]->join();
        delete this->trabajadores[i];
    }
}

void Orchestrator::imprimirEstadisticas() {
    std::cout << "Recursos restantes:";
    std::cout << "\n  - Trigo: " << this->inventario.obtenerSobrantesTrigo();
    std::cout << "\n  - Madera: " << this->inventario.obtenerSobrantesMadera();
    std::cout << "\n  - Carbon: " << this->inventario.obtenerSobrantesCarbon();
    std::cout << "\n  - Hierro: " << this->inventario.obtenerSobrantesHierro();
    std::cout << "\n\nPuntos de beneficio acumulados: "
              << this->acumuladorPuntos.obtenerPuntos() << "\n";
}
