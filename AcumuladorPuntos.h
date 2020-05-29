#ifndef ACUMULADOR_PUNTOS_H
#define ACUMULADOR_PUNTOS_H

#include <mutex>
#include <vector>
#include "Recurso.h"

class AcumuladorPuntos {
    std::mutex mutex;
    int puntos;

public:
    // Constructor
    AcumuladorPuntos();

    // Constructor y asignacion por copia deshabilitados
    AcumuladorPuntos(const AcumuladorPuntos& other) = delete;
    AcumuladorPuntos& operator=(const AcumuladorPuntos& other) = delete;

    // Suma los puntos correspondientes a la lista de recursos recibida
    void sumarPuntos(const int puntos);

    // Obtiene los puntos acumulados hasta el momento
    const int obtenerPuntos();
};

#endif // ACUMULADOR_PUNTOS_H
