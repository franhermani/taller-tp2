#include <iostream>
#include <fstream>
#include <string>
#include "Carbon.h"
#include "Hierro.h"
#include "Madera.h"
#include "Trigo.h"
#include "Orchestrator.h"
#include "Agricultor.h"
#include "Leniador.h"
#include "Minero.h"
#include "Carpintero.h"
#include "Cocinero.h"
#include "Armero.h"

#define OK 0
#define ERROR 1
#define NUM_WORK 6

Orchestrator::Orchestrator() {
    this->colaAgricultores = ColaAgricultores();
    this->colaLeniadores = ColaLeniadores();
    this->colaMineros = ColaMineros();
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
        if (this->parsearLineaTrabajadores(line) == ERROR)
            return ERROR;
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
        if (this->parsearCaracterMapa(c) == ERROR) return ERROR;
    }
    map_file.close();

    return OK;
}

int Orchestrator::parsearLineaTrabajadores(std::string line) {
    std::string workers[NUM_WORK] = {"Agricultores", "Leniadores", "Mineros",
                                     "Cocineros", "Carpinteros", "Armeros"};

    std::string delimiter = "=";
    std::string worker = line.substr(0, line.find(delimiter));
    std::string quant = line.substr(line.find(delimiter)+1, std::string::npos);

    bool worker_ok = false;
    int i;
    for (i = 0; i < NUM_WORK; i ++) {
        if (workers[i] == worker) {
            worker_ok = true;
            break;
        }
    }
    if (! worker_ok) {
        std::cout << "Trabajador inválido";
        return ERROR;
    }
    try {
        int quant_i = std::stoi(quant);
        this->crearTrabajadores(worker, quant_i);
    }
    catch(std::invalid_argument) {
        std::cout << "Cantidad inválida";
        return ERROR;
    }
    return OK;
}

int Orchestrator::parsearCaracterMapa(char c) {
    switch (c) {
        case 'C':
            Carbon carbon;
            this->colaMineros.encolar(carbon);
            break;
        case 'H':
            Hierro hierro;
            this->colaMineros.encolar(hierro);
            break;
        case 'M':
            Madera madera;
            this->colaLeniadores.encolar(madera);
            break;
        case 'T':
            Trigo trigo;
            this->colaAgricultores.encolar(trigo);
            break;
        case '\n':
            break;
        default:
            std::cout << "Materia prima inválida\n";
            return ERROR;
    }
    return OK;
}

void Orchestrator::crearTrabajadores(std::string worker, int quant) {
    int i;

    if (worker == "Agricultores") {
        for (i = 0; i < quant; i ++) {
            Agricultor agricultor;
            this->trabajadores.push_back(agricultor);
        }
    } else if (worker == "Leniadores") {
        for (i = 0; i < quant; i ++) {
            Leniador leniador;
            this->trabajadores.push_back(leniador);
        }
    } else if (worker == "Mineros") {
        for (i = 0; i < quant; i ++) {
            Minero minero;
            this->trabajadores.push_back(minero);
        }
    } else if (worker == "Cocineros") {
        for (i = 0; i < quant; i ++) {
            Cocinero cocinero;
            this->trabajadores.push_back(cocinero);
        }
    } else if (worker == "Carpinteros") {
        for (i = 0; i < quant; i ++) {
            Carpintero carpintero;
            this->trabajadores.push_back(carpintero);
        }
    } else if (worker == "Armeros") {
        for (i = 0; i < quant; i ++) {
            Armero armero;
            this->trabajadores.push_back(armero);
        }
    }
}
