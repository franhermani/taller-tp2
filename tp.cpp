#include <string>
#include <iostream>
#include <exception>
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
    bool error = false;

    try {
        orchestrator.procesarArchivoTrabajadores(trabajadores_path);
        orchestrator.iniciarTrabajadores();
        try {
            orchestrator.procesarArchivoRecursos(recursos_path);
        } catch(std::runtime_error& e) {
            std::cerr << e.what();
            error = true;
        }
        orchestrator.cerrarColas();
        orchestrator.finalizarTrabajadores();
        if (error) return ERROR;
        orchestrator.imprimirEstadisticas();
    } catch(std::exception& e) {
        std::cerr << e.what();
        return ERROR;
    } catch(...) {
        std::cerr << "Error inesperado\n";
        return ERROR;
    }
    return OK;
}
