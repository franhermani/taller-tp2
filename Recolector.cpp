#include <unistd.h>
#include "Recolector.h"
#include "ColaCerradaException.h"

#define SLEEP_TIME 50

Recolector::Recolector(Cola& cola, Inventario& inventario) :
cola(cola), inventario(inventario) {}

void Recolector::run() {
    while (true) {
        try {
            Recurso recurso = cola.desencolar();
            usleep(SLEEP_TIME);
            inventario.depositarRecurso(recurso);
        } catch(ColaCerradaException) {
            break;
        }
    }
}
