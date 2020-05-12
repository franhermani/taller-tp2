#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include "Cola.h"
#include "Inventario.h"
#include "AcumuladorPuntos.h"
#include "Trabajador.h"
#include "Recolector.h"
#include "Armero.h"
#include "Cocinero.h"
#include "Carpintero.h"

#define OK 0
#define ERROR 1
#define NUM_RECURSOS 4
#define NUM_TRABAJADORES 6

std::map<std::string, int> procesarArchivoTrabajadores(const std::string& path);

int parsearLineaTrabajadores(const std::string& linea,
                             std::map<std::string, int> &trabajadores_map);

void imprimirEstadisticas();


int main(int argc, char *argv[]) {
    const std::string trabajadores_path = argv[1], recursos_path = argv[2];

    // Creo los recursos compartidos
    Cola colaLeniadores, colaMineros, colaAgricultores;
    Inventario inventario;
    AcumuladorPuntos acumuladorPuntos;

    // Vector de threads
    std::vector<Trabajador*> trabajadores;

    // Creo el diccionario de trabajadores
    std::map<std::string, int> trabajadores_map =
            procesarArchivoTrabajadores(trabajadores_path);

    // Creo los trabajadores
    int i;
    for (const auto& kv : trabajadores_map) {
        std::string trabajador = kv.first;
        int cant = kv.second;

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
                        new Cocinero(inventario, acumuladorPuntos));
        } else if (trabajador == "Carpinteros") {
            for (i = 0; i < cant; i ++)
                trabajadores.push_back(
                        new Carpintero(inventario, acumuladorPuntos));
        } else if (trabajador == "Armeros") {
            for (i = 0; i < cant; i ++)
                trabajadores.push_back(
                        new Armero(inventario, acumuladorPuntos));
        }
    }

    // Inicializo los trabajadores (threads)
    for (i = 0; i < (int) trabajadores.size(); i ++)
        trabajadores[i]->start();

    // Abro el archivo de recursos
    std::ifstream recursos_file;
    recursos_file.open(recursos_path, std::ifstream::in);
    if (! recursos_file.good()) {
        std::cout << "Error al abrir el archivo de materias primas\n";
        return ERROR;
    }
    char c;

    // Encolo los recursos
    while (recursos_file.get(c)) {
        if (c == '\n') continue;
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
    recursos_file.close();

    // Finalizo los trabajadores (threads)
    for (i = 0; i < (int) trabajadores.size(); i ++) {
        trabajadores[i]->join();
        delete trabajadores[i];
    }

    // Imprimo resultados
    std::cout << "Recursos restantes:";
    std::cout << "\n  - Trigo: " << inventario.obtenerSobrantesTrigo();
    std::cout << "\n  - Madera: " << inventario.obtenerSobrantesMadera();
    std::cout << "\n  - Carbon: " << inventario.obtenerSobrantesCarbon();
    std::cout << "\n  - Hierro: " << inventario.obtenerSobrantesHierro();
    std::cout << "\n\nPuntos de beneficio acumulados: "
              << acumuladorPuntos.obtenerPuntos() << "\n";


    return OK;
}

std::map<std::string, int> procesarArchivoTrabajadores(
        const std::string& path) {
    std::ifstream trabajadores_file;
    trabajadores_file.open(path, std::ifstream::in);
    if (! trabajadores_file.good()) {
        std::cout << "Error al abrir el archivo de trabajadores\n";
//        return ERROR;
    }
    std::string linea;
    std::map<std::string, int> trabajadores_map;

    while (getline(trabajadores_file, linea))
        parsearLineaTrabajadores(linea, trabajadores_map);

    trabajadores_file.close();

    return trabajadores_map;
}

int parsearLineaTrabajadores(const std::string& linea,
                             std::map<std::string, int> &trabajadores_map) {
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
        trabajadores_map[trabajador] = cant_i;
    }
    catch(std::invalid_argument) {
        std::cout << "Cantidad inválida";
        return ERROR;
    }
    return OK;
}

void imprimirEstadisticas() {
}
