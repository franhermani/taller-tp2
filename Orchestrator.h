#ifndef ORCHESTRATOR_H
#define ORCHESTRATOR_H

#include <string>
#include <vector>
#include "Cola.h"
#include "FileParser.h"
#include "Recolector.h"
#include "Productor.h"
#include "Inventario.h"
#include "AcumuladorPuntos.h"

class Orchestrator {
    FileParser parser;
    Cola colaAgricultores;
    Cola colaLeniadores;
    Cola colaMineros;
    std::vector<Recolector*> recolectores;
    std::vector<Productor*> productores;
    Inventario inventario;
    AcumuladorPuntos acumuladorPuntos;

    // Delega la creacion de trabajadores segun sean recolectores o productores
    void crearTrabajadores(const std::string& trabajador, const int& cant);

    // Crea 'cant' instancias de un recolector con una referencia a 'cola'
    // y al inventario y las agrega al vector de recolectores
    void crearRecolectores(const int& cant, Cola& cola);

    // Crea 'cant' instancias de un productor con las cantidades de recursos,
    // con una referencia al inventario y al acumulador de puntos
    // y las agrega al vector de productores
    void crearProductores(const int& cant, int cant_carbon, int cant_hierro,
                          int cant_madera, int cant_trigo);

    // Crea un recurso del tipo 'c' y lo agrega a la cola correspondiente
    void encolarRecurso(const char& c);

    // Cierra el inventario
    void cerrarInventario();

public:
    // Constructor
    Orchestrator();

    // Constructor y asignacion por copia deshabilitados
    Orchestrator(const Orchestrator& other) = delete;
    Orchestrator& operator=(const Orchestrator& other) = delete;

    // Procesa el archivo de trabajadores haciendo uso del parser
    // y crea las instancias correspondientes
    void procesarArchivoTrabajadores(const std::string& path);

    // Procesa el archivo de recursos haciendo uso del parser
    // y crea las instancias correspondientes
    void procesarArchivoRecursos(const std::string& path);

    // Inicializa los trabajadores (threads) mediante el comando start()
    void iniciarTrabajadores();

    // Finaliza los trabajadores (threads) mediante el comando join()
    void finalizarTrabajadores();

    // Cierra las colas bloqueantes de los recolectores
    void cerrarColas();

    // Imprime por pantalla las estadisticas finales del inventario
    // y del acumulador de puntos
    void imprimirEstadisticas();
};

#endif // ORCHESTRATOR_H
