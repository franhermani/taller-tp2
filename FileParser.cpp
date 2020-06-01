#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>
#include <exception>

#include "FileParser.h"
#include "defines.h"

const std::map<std::string, int> FileParser::parsearArchivoTrabajadores(
        const std::string& path) {
    std::ifstream trabajadores_file;
    trabajadores_file.open(path, std::ifstream::in);
    if (! trabajadores_file.good())
        throw std::runtime_error("Error al abrir el archivo "
                                 "de trabajadores\n");

    std::map<std::string, int> trabajadores_map =
            {{AGRICULTORES, 0}, {LENIADORES, 0}, {MINEROS, 0},
             {COCINEROS, 0}, {CARPINTEROS, 0}, {ARMEROS, 0}};

    std::string linea;
    while (getline(trabajadores_file, linea))
        parsearLineaTrabajadores(linea, trabajadores_map);

    trabajadores_file.close();

    return std::move(trabajadores_map);
}

const std::vector<char> FileParser::parsearArchivoRecursos(
        const std::string& path) {
    std::ifstream recursos_file;
    recursos_file.open(path, std::ifstream::in);
    if (! recursos_file.good())
        throw std::runtime_error("Error al abrir el archivo "
                                 "de recursos\n");

    std::vector<char> recursos_vector;
    std::string linea;
    while (getline(recursos_file, linea))
        for (char& c : linea) parsearCaracterRecursos(c, recursos_vector);

    recursos_file.close();

    return std::move(recursos_vector);
}

void FileParser::parsearLineaTrabajadores(const std::string& linea,
        std::map<std::string, int>& trabajadores_map) {
    std::string trabajador = linea.substr(0, linea.find(DELIM)),
            cant = linea.substr(linea.find(DELIM) + 1, std::string::npos);

    if (trabajadores_map.find(trabajador) == trabajadores_map.end())
        throw std::runtime_error("Trabajador inválido en el archivo "
                                 "de trabajadores\n");

    trabajadores_map[trabajador] += std::stoi(cant);
}

void FileParser::parsearCaracterRecursos(const char& c,
        std::vector<char>& recursos_vector) {
    std::vector<char> recursos = {CARBON, HIERRO, MADERA, TRIGO};

    if (std::count(recursos.begin(), recursos.end(), c) > 0)
        recursos_vector.push_back(c);
}
