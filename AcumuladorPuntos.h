#ifndef ACUMULADORPUNTOS_H
#define ACUMULADORPUNTOS_H

#include <mutex>
#include <vector>
#include "Recurso.h"

class AcumuladorPuntos {
    std::mutex mutex;
    int puntos;

    // Calcula los puntos que representan la lista de recursos recibida
    const int calcularPuntos(std::vector<Recurso> recursos);

public:
    // Constructor
    AcumuladorPuntos();

    // Constructor y asignacion por copia deshabilitados
    AcumuladorPuntos(const AcumuladorPuntos& other) = delete;
    AcumuladorPuntos& operator=(const AcumuladorPuntos& other) = delete;

    // Suma los puntos correspondientes a la lista de recursos recibida
    void sumarPuntos(std::vector<Recurso> recursos);

    // Obtiene los puntos acumulados hasta el momento
    const int obtenerPuntos();
};

#endif // ACUMULADORPUNTOS_H
