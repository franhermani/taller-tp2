#ifndef ACUMULADOR_PUNTOS_H
#define ACUMULADOR_PUNTOS_H

#include <mutex>
#include <vector>
#include "Recurso.h"

class AcumuladorPuntos {
    std::mutex mutex;
    int puntos;

    // Calcula los puntos que representan la lista de recursos recibida
    const int calcularPuntos(const std::vector<Recurso> recursos) const;

public:
    // Constructor
    AcumuladorPuntos();

    // Constructor y asignacion por copia deshabilitados
    AcumuladorPuntos(const AcumuladorPuntos& other) = delete;
    AcumuladorPuntos& operator=(const AcumuladorPuntos& other) = delete;

    // Suma los puntos correspondientes a la lista de recursos recibida
    void sumarPuntos(const std::vector<Recurso> recursos);

    // Obtiene los puntos acumulados hasta el momento
    const int obtenerPuntos();
};

#endif // ACUMULADOR_PUNTOS_H
