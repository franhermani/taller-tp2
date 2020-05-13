#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <mutex>
#include <condition_variable>
#include <vector>
#include "Cola.h"
#include "Recurso.h"

class Inventario {
    std::mutex mutex;
    std::condition_variable cv;
    Cola colaCarbon;
    Cola colaHierro;
    Cola colaMadera;
    Cola colaTrigo;
    bool esta_cerrado;

    // TODO
    bool armarConjunto(std::vector<Recurso>& recursos, const int cant_carbon,
            const int cant_hierro, const int cant_madera,
            const int cant_trigo);

public:
    // Constructor
    Inventario();

    // Constructor y asignacion por copia deshabilitados
    Inventario(const Inventario& other) = delete;
    Inventario& operator=(const Inventario& other) = delete;

    // Deposita un recurso en el inventario
    void depositarRecurso(Recurso recurso);

    // TODO
    std::vector<Recurso> consumirRecursos(const int cant_carbon,
                                          const int cant_hierro,
                                          const int cant_madera,
                                          const int cant_trigo);

    // Cierra el inventario
    // Esto implica que no va a recibir mas recursos
    void cerrar();

    // Obtiene la cantidad actual de carbon en el inventario
    const int obtenerSobrantesCarbon();

    // Obtiene la cantidad actual de hierro en el inventario
    const int obtenerSobrantesHierro();

    // Obtiene la cantidad actual de madera en el inventario
    const int obtenerSobrantesMadera();

    // Obtiene la cantidad actual de trigo en el inventario
    const int obtenerSobrantesTrigo();
};

#endif // INVENTARIO_H
