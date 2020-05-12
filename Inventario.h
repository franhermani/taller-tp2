#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Cola.h"
#include "Recurso.h"

class Inventario {
    Cola colaCarbon;
    Cola colaHierro;
    Cola colaMadera;
    Cola colaTrigo;

public:
    // Constructor
    Inventario() {}

    // Constructor y asignacion por copia deshabilitados
    Inventario(const Inventario& other) = delete;
    Inventario& operator=(const Inventario& other) = delete;

    // Deposita un recurso en el inventario
    void depositarRecurso(Recurso recurso);

    Recurso consumirCarbon();
    Recurso consumirHierro();
    Recurso consumirMadera();
    Recurso consumirTrigo();

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
