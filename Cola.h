#ifndef COLA_H
#define COLA_H

#include <mutex>
#include <condition_variable>
#include <queue>
#include "Recurso.h"

class Cola {
    std::mutex mutex;
    std::condition_variable cv;
    std::queue<Recurso> recursos;
    bool estaCerrada;

public:
    // Constructor
    // Inicialmente la cola no esta cerrada
    Cola();

    // Constructor y asignacion por copia deshabilitados
    Cola(const Cola& other) = delete;
    Cola& operator=(const Cola& other) = delete;

    // Agrega un recurso a la cola
    void encolar(Recurso recurso);

    // Quita el recurso mas antiguo de la cola
    Recurso desencolar();

    // Obtiene el largo actual de la cola
    const int obtenerLargo();

    // Cierra la cola
    // Esto implica que no va a recibir mas recursos
    void cerrar();
};

#endif // COLA_H
