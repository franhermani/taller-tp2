#include <iostream>
#include <fstream>
#include <string>
#include "InputParser.h"

#define OK 0
#define ERROR 1

int processInput(const char *workers_path, const char *map_path);

int processWorkersFile(const char *workers_path);

int processMapFile(const char *map_path);


int main(int argc, char *argv[]) {
    const char *workers_path = argv[1], *map_path = argv[2];

    if (processInput(workers_path, map_path) == ERROR) return ERROR;

    return OK;
}

int processInput(const char *workers_path, const char *map_path) {
    if (processWorkersFile(workers_path) == ERROR) return ERROR;
    if (processMapFile(map_path) == ERROR) return ERROR;

    return OK;
}

int processWorkersFile(const char *workers_path) {
    std::ifstream workers_file;
    workers_file.open(workers_path, std::ifstream::in);
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

int processMapFile(const char *map_path) {
    std::ifstream map_file;
    map_file.open(map_path, std::ifstream::in);
    if (! map_file.good()) {
        std::cout << "Error al abrir el archivo de materias primas\n";
        return ERROR;
    }
    InputParser parser;
    char c;
    while (map_file.get(c)) {
        parser.parseMapChar(c);
    }
    map_file.close();

    return OK;
}
