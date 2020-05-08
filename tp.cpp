#include "Orchestrator.h"

#define OK 0
#define ERROR 1

int main(int argc, char *argv[]) {
    Orchestrator orchestrator;
    const char *workers_path = argv[1], *map_path = argv[2];

    if (orchestrator.procesarArchivoTrabajadores(workers_path) == ERROR)
        return ERROR;

    if (orchestrator.procesarArchivoMapa(map_path) == ERROR)
        return ERROR;

    return OK;
}
