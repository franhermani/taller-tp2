#include <mutex>
#include <vector>
#include <map>
#include "AcumuladorPuntos.h"
#include "Lock.h"

AcumuladorPuntos::AcumuladorPuntos() {
    puntos = 0;
}

void AcumuladorPuntos::sumarPuntos(std::vector<Recurso> recursos) {
    Lock lock(mutex);
    puntos += calcularPuntos(recursos);
}

int AcumuladorPuntos::calcularPuntos(std::vector<Recurso> recursos) {
    Lock lock(mutex);

    std::map<char, int> cantidades = {{'C', 0}, {'H', 0}, {'M', 0}, {'T', 0}};
    int puntos_nuevos;

    size_t i;
    for (i = 0; i < recursos.size(); i ++)
        cantidades[recursos[i].obtenerTipo()] += 1;

    if (cantidades['T'] == 2 && cantidades['C'] == 1) {
        puntos_nuevos = 5;
    } else if (cantidades['M'] == 3 && cantidades['H'] == 1) {
        puntos_nuevos = 2;
    } else if (cantidades['C'] == 2 && cantidades['H'] == 2) {
        puntos_nuevos = 3;
    } else {
        puntos_nuevos = 0;
    }
    return puntos_nuevos;
}

int AcumuladorPuntos::obtenerPuntos() {
    return puntos;
}
