#include <unistd.h>
#include "Recolector.h"
#include "ColaCerradaException.h"

#define SLEEP_TIME 50

void Recolector::run() {
    /*
    while (true) {
        try {
            Recurso recurso = cola.desencolar();
            usleep(SLEEP_TIME);
            // TODO: cambiar este depositar por algo generico
            inventario.depositarTrigo(recurso);
        } catch(ColaCerradaException) {
            break;
        }
    }
     */
}
