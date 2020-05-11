#ifndef ACUMULADORPUNTOS_H
#define ACUMULADORPUNTOS_H

#include <vector>
#include "Recurso.h"

class AcumuladorPuntos {
    int puntos;
    int calcularPuntos(std::vector<Recurso> recursos);
public:
    AcumuladorPuntos();
    AcumuladorPuntos(const AcumuladorPuntos& other) = delete;
    void sumarPuntos(std::vector<Recurso> recursos);
    int obtenerPuntos();
};

#endif // ACUMULADORPUNTOS_H
