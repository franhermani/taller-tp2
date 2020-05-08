#include <iostream>
#include <fstream>
#include <string>
#include "Orchestrator.h"

#define OK 0
#define ERROR 1

Orchestrator::Orchestrator() {
    this->parser = InputParser();

    int i;
    for (i = 0; i < NUM_COLAS; i ++) {
        this->colas[i] = ColaBloqueante();
    }
}

int Orchestrator::procesarArchivoTrabajadores(const char *path) {
    std::ifstream workers_file;
    workers_file.open(path, std::ifstream::in);
    if (! workers_file.good()) {
        std::cout << "Error al abrir el archivo de trabajadores\n";
        return ERROR;
    }
    std::string line;
    while (getline(workers_file, line)) {
        // TODO: parsear linea y crear N trabajadores-threads
    }
    workers_file.close();

    return OK;
}

int Orchestrator::procesarArchivoMapa(const char *path) {
    std::ifstream map_file;
    map_file.open(path, std::ifstream::in);
    if (! map_file.good()) {
        std::cout << "Error al abrir el archivo de materias primas\n";
        return ERROR;
    }
    char c;
    while (map_file.get(c)) {
        this->parser.parsearCaracterMapa(c);
    }
    map_file.close();

    return OK;
}
