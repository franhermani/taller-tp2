#include <string>
#include "Orchestrator.h"

#define OK 0
#define ERROR 1

int main(int argc, char *argv[]) {
    Orchestrator orchestrator;
    const std::string trabajadores_path = argv[1], recursos_path = argv[2];

    if (orchestrator.procesarArchivoTrabajadores(trabajadores_path) == ERROR)
        return ERROR;

    orchestrator.iniciarTrabajadores();

    if (orchestrator.procesarArchivoRecursos(recursos_path) == ERROR)
        return ERROR;

    orchestrator.imprimirEstadisticas();

    return OK;
}
