#include <string>
#include "InputParser.h"
#include "Carbon.h"
#include "Hierro.h"
#include "Madera.h"
#include "Trigo.h"
#include "Agricultor.h"
#include "Leniador.h"
#include "Minero.h"

#define OK 0
#define ERROR 1

int InputParser::parsearLineaTrabajadores(std::string line) {
    return OK;
}

int InputParser::parsearCaracterMapa(char c) {
    // TODO: enviar cada 'materia_prima' a su cola bloqueante
    switch (c) {
        case 'C':
            Carbon carbon;
            break;
        case 'H':
            Hierro hierro;
            break;
        case 'M':
            Madera madera;
            break;
        case 'T':
            Trigo trigo;
            break;
        default:
            printf("Carácter inválido en el archivo de materias primas\n");
            return ERROR;
    }
    return OK;
}
