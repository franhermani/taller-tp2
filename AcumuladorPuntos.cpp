#include <mutex>
#include <vector>
#include <map>
#include "defines.h"
#include "AcumuladorPuntos.h"

AcumuladorPuntos::AcumuladorPuntos() {
    puntos = 0;
}

void AcumuladorPuntos::sumarPuntos(const std::vector<Recurso> recursos) {
    std::unique_lock<std::mutex> lock(mutex);
    puntos += calcularPuntos(recursos);
}

const int AcumuladorPuntos::calcularPuntos(
        const std::vector<Recurso> recursos) const {
    std::map<char, int> cantidades = {{CARBON, 0}, {HIERRO, 0},
                                      {MADERA, 0}, {TRIGO, 0}};
    int puntos_nuevos = 0;

    size_t i;
    for (i = 0; i < recursos.size(); i ++)
        cantidades[recursos[i].obtenerTipo()] += 1;

    if (cantidades[TRIGO] == CANT_T_COCINERO &&
        cantidades[CARBON] == CANT_C_COCINERO) {
        puntos_nuevos = PUNTOS_COCINERO;
    } else if (cantidades[MADERA] == CANT_M_CARPINTERO &&
               cantidades[HIERRO] == CANT_H_CARPINTERO) {
        puntos_nuevos = PUNTOS_CARPINTERO;
    } else if (cantidades[CARBON] == CANT_C_ARMERO &&
               cantidades[HIERRO] == CANT_H_ARMERO) {
        puntos_nuevos = PUNTOS_ARMERO;
    }
    return puntos_nuevos;
}

const int AcumuladorPuntos::obtenerPuntos() {
    std::unique_lock<std::mutex> lock(mutex);
    return puntos;
}
