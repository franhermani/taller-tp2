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

    // Parsea una linea del archivo de trabajadores obteniendo
    // el trabajador y la cantidad correspondientes
    const int parsearLineaTrabajadores(const std::string& linea);

    // Parsea un caracter del archivo de recursos obteniendo
    // el recurso correspondiente
    const int parsearCaracterRecursos(const char& c);

    // Crea 'cant' instancias de 'trabajador' y las agrega
    // al vector de trabajadores
    void crearTrabajadores(const std::string& trabajador, const int& cant);

    // Crea un recurso del tipo 'c' y lo agrega a la cola correspondiente
    void encolarRecurso(const char& c);

public:
    // Constructor
    Orchestrator() {}

    // Constructor y asignacion por copia deshabilitados
    Orchestrator(const Orchestrator& other) = delete;
    Orchestrator& operator=(const Orchestrator& other) = delete;

    // Procesa el archivo de trabajadores y crea
    // las instancias correspondientes
    const int procesarArchivoTrabajadores(const std::string& path);

    // Procesa el archivo de recursos y crea
    // las instancias correspondientes
    const int procesarArchivoRecursos(const std::string& path);

    // Inicializa los trabajadores (threads) mediante el comando start()
    void iniciarTrabajadores();

    // Finaliza los trabajadores (threads) mediante el comando join()
    void finalizarTrabajadores();

    // Imprime por pantalla las estadisticas finales del inventario
    // y del acumulador de puntos
    void imprimirEstadisticas();
};

#endif // ORCHESTRATOR_H
