#include <vector>
#include <map>
#include "AcumuladorPuntos.h"

#define OK 0
#define ERROR 1

AcumuladorPuntos::AcumuladorPuntos() {
    this->puntos = 0;
}

int AcumuladorPuntos::sumarPuntos(std::vector<Recurso> recursos) {
    int nuevos_puntos = this->calcularPuntos(recursos);
    if (nuevos_puntos == ERROR) return ERROR;

    this->puntos += nuevos_puntos;

    return OK;
}

int AcumuladorPuntos::calcularPuntos(std::vector<Recurso> recursos) {
    std::map<char, int> cantidades = {{'C', 0}, {'H', 0}, {'M', 0}, {'T', 0}};
    int puntos = 0;

    size_t i;
    for (i = 0; i < recursos.size(); i ++)
        cantidades[recursos[i].obtenerTipo()] += 1;

    if (cantidades['T'] == 2 && cantidades['C'] == 1) {
        puntos = 5;
    } else if (cantidades['M'] == 3 && cantidades['H'] == 1) {
        puntos = 2;
    } else if (cantidades['C'] == 2 && cantidades['H'] == 2) {
        puntos = 3;
    }
    return puntos;
}

int AcumuladorPuntos::obtenerPuntos() {
    return this->puntos;
}
