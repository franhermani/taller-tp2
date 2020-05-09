#include <string>
#include <iterator>
#include <algorithm>
#include <iostream>
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
#define NUM_WORK 6

int InputParser::parsearLineaTrabajadores(std::string line) {
    std::string workers[NUM_WORK] = {"Agricultores", "Leniadores", "Mineros",
                                     "Cocineros", "Carpinteros", "Armeros"};

    std::string delimiter = "=";
    std::string worker = line.substr(0, line.find(delimiter));
    std::string quant = line.substr(line.find(delimiter)+1, std::string::npos);

    bool worker_ok = false;
    int i;
    for (i = 0; i < NUM_WORK; i ++) {
        if (workers[i] == worker) {
            worker_ok = true;
            break;
        }
    }
    if (! worker_ok) {
        std::cout << "Trabajador inválido";
        return ERROR;
    }
    try {
        int quant_i = std::stoi(quant);
        // TODO: crear quant_i workers
    }
    catch (std::invalid_argument) {
        std::cout << "Cantidad inválida";
        return ERROR;
    }
    return OK;
}

int InputParser::parsearCaracterMapa(char c) {
    // TODO: enviar cada 'materia_prima' a su cola bloqueante
    switch (c) {
        case 'C':
            //Carbon carbon;
            break;
        case 'H':
            //Hierro hierro;
            break;
        case 'M':
            //Madera madera;
            break;
        case 'T':
            //Trigo trigo;
            break;
        case '\n':
            break;
        default:
            std::cout << "Materia prima inválida\n";
            return ERROR;
    }
    return OK;
}
