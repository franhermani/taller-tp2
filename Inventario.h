#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Cola.h"
#include "MateriaPrima.h"

class Inventario {
    Cola colaCarbon;
    Cola colaHierro;
    Cola colaMadera;
    Cola colaTrigo;
public:
    void depositar(MateriaPrima materia_prima);
    MateriaPrima consumir();
};

#endif // INVENTARIO_H
