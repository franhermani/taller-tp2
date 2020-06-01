#include <string>
#include <vector>
#include <map>

#ifndef FILE_PARSER_H
#define FILE_PARSER_H

class FileParser {
    // Parsea una linea del archivo de trabajadores y actualiza
    // el mapa segun lo procesado
    void parsearLineaTrabajadores(const std::string& linea,
            std::map<std::string, int>& trabajadores_map);

    // Parsea una linea del archivo de recursos y actualiza
    // el vector segun lo procesado
    void parsearCaracterRecursos(const char& c,
            std::vector<char>& recursos_vector);

public:
    // Parsea el archivo de trabajadores y devuelve un mapa
    // con el formato {'trabajador', cantidad}
    const std::map<std::string, int> parsearArchivoTrabajadores(
            const std::string& path);

    // Parsea el archivo de recursos y devuelve un vector
    // con todos los recursos validos
    const std::vector<char> parsearArchivoRecursos(
            const std::string& path);
};

#endif // FILE_PARSER_H
