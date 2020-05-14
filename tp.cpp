#include <string>
#include <iostream>
#include "Orchestrator.h"

#define OK 0
#define ERROR 1
#define NUM_PARAMS 3

int main(int argc, char *argv[]) {
    if (argc != NUM_PARAMS) {
        std::cout << "Uso: ./tp <archivo_trabajadores> <archivo_recursos>\n";
        return ERROR;
    }
    Orchestrator orchestrator;
    const std::string trabajadores_path = argv[1], recursos_path = argv[2];

    if (orchestrator.procesarArchivoTrabajadores(trabajadores_path) == ERROR)
        return ERROR;

    orchestrator.iniciarTrabajadores();

    if (orchestrator.procesarArchivoRecursos(recursos_path) == ERROR)
        return ERROR;

    orchestrator.finalizarTrabajadores();
    orchestrator.imprimirEstadisticas();

    return OK;
}
