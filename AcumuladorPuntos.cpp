#include <vector>
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
    return OK;
}

int AcumuladorPuntos::obtenerPuntos() {
    return this->puntos;
}
