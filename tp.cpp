#include <iostream>
#include <fstream>
#include <string>

#define OK 0
#define ERROR 1

int process_input(const char *workers_path, const char *map_path);

int process_workers_file(const char *workers_path);

int process_map_file(const char *map_path);


int main(int argc, char *argv[]) {
    const char *workers_path = argv[1], *map_path = argv[2];

    if (process_input(workers_path, map_path) == ERROR) return ERROR;

    return OK;
}

int process_input(const char *workers_path, const char *map_path) {
    if (process_workers_file(workers_path) == ERROR) return ERROR;
    if (process_map_file(map_path) == ERROR) return ERROR;

    return OK;
}

int process_workers_file(const char *workers_path) {
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

int process_map_file(const char *map_path) {
    std::ifstream map_file;
    map_file.open(map_path, std::ifstream::in);
    if (! map_file.good()) {
        std::cout << "Error al abrir el archivo de materias primas\n";
        return ERROR;
    }
    char materia_prima;
    while (map_file.get(materia_prima)) {
        // TODO: enviar cada 'materia_prima' a su cola bloqueante
    }
    map_file.close();

    return OK;
}
