#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Cola.h"
#include "Carbon.h"
#include "Hierro.h"
#include "Madera.h"
#include "Trigo.h"

class Inventario {
    Cola colaCarbon;
    Cola colaHierro;
    Cola colaMadera;
    Cola colaTrigo;
public:
    void depositarCarbon(Carbon carbon);
    void depositarHierro(Hierro hierro);
    void depositarMadera(Madera madera);
    void depositarTrigo(Trigo trigo);
    Carbon consumirCarbon();
    Hierro consumirHierro();
    Madera consumirMadera();
    Trigo consumirTrigo();
};

#endif // INVENTARIO_H
