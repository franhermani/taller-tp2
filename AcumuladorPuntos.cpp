#include <mutex>
#include "AcumuladorPuntos.h"

AcumuladorPuntos::AcumuladorPuntos() {
    puntos = 0;
}

void AcumuladorPuntos::sumarPuntos(const int puntos) {
    std::unique_lock<std::mutex> lock(mutex);
    this->puntos += puntos;
}

const int AcumuladorPuntos::obtenerPuntos() {
    std::unique_lock<std::mutex> lock(mutex);
    return puntos;
}
