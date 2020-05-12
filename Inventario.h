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
    Inventario() {}
    Inventario(const Inventario& other) = delete;
    Inventario& operator=(const Inventario& other) = delete;
    void depositarCarbon(Recurso recurso);
    void depositarHierro(Recurso recurso);
    void depositarMadera(Recurso recurso);
    void depositarTrigo(Recurso recurso);
    Recurso consumirCarbon();
    Recurso consumirHierro();
    Recurso consumirMadera();
    Recurso consumirTrigo();
    const int obtenerSobrantesCarbon();
    const int obtenerSobrantesHierro();
    const int obtenerSobrantesMadera();
    const int obtenerSobrantesTrigo();
};

#endif // INVENTARIO_H
