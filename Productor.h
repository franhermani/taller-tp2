#ifndef PRODUCTOR_H
#define PRODUCTOR_H

#include "Trabajador.h"
#include "Inventario.h"
#include "AcumuladorPuntos.h"

class Productor: public Trabajador {
    Inventario& inventario;
    AcumuladorPuntos& acumulador;
    int cant_carbon;
    int cant_hierro;
    int cant_madera;
    int cant_trigo;

public:
    // Constructor
    // Recibe una referencia del inventario y del acumulador de puntos
    // Tambien recibe las cantidades que precisa de cada recurso
    Productor(Inventario& inventario, AcumuladorPuntos& acumulador,
              const int cant_carbon, const int cant_hierro,
              const int cant_madera, const int cant_trigo);

    // Constructor y asignacion por copia deshabilitados
    Productor(const Productor& other) = delete;
    Productor& operator=(const Productor& other) = delete;

    // Intenta obtener un conjunto de recursos del inventario y
    // depositarlos en el acumulador de puntos
    virtual void run() override;
};

#endif // PRODUCTOR_H
