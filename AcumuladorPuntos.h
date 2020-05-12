#ifndef ACUMULADORPUNTOS_H
#define ACUMULADORPUNTOS_H

#include <mutex>
#include <vector>
#include "Recurso.h"

class AcumuladorPuntos {
    std::mutex mutex;
    int puntos;
    const int calcularPuntos(std::vector<Recurso> recursos);
public:
    AcumuladorPuntos();
    AcumuladorPuntos(const AcumuladorPuntos& other) = delete;
    AcumuladorPuntos& operator=(const AcumuladorPuntos& other) = delete;
    void sumarPuntos(std::vector<Recurso> recursos);
    const int obtenerPuntos();
};

#endif // ACUMULADORPUNTOS_H
