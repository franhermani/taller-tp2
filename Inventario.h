#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <map>
#include "Cola.h"
#include "Recurso.h"

class Inventario {
    Cola colaCarbon;
    Cola colaHierro;
    Cola colaMadera;
    Cola colaTrigo;
public:
    void depositarCarbon(Recurso recurso);
    void depositarHierro(Recurso recurso);
    void depositarMadera(Recurso recurso);
    void depositarTrigo(Recurso recurso);
    Recurso consumirCarbon();
    Recurso consumirHierro();
    Recurso consumirMadera();
    Recurso consumirTrigo();
    const std::map<char, int> obtenerSobrantes();
};

#endif // INVENTARIO_H
