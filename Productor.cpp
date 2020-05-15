#include <vector>
#include <unistd.h>
#include "Productor.h"
#include "InventarioCerradoException.h"

#define SLEEP_TIME 60

Productor::Productor(Inventario &inventario, AcumuladorPuntos &acumulador,
        const int cant_carbon, const int cant_hierro,
        const int cant_madera, const int cant_trigo) :
        inventario(inventario), acumulador(acumulador),
        cant_carbon(cant_carbon), cant_hierro(cant_hierro),
        cant_madera(cant_madera), cant_trigo(cant_trigo) {}

void Productor::run() {
    while (true) {
        try {
            std::vector<Recurso> recursos = inventario.consumirRecursos(
                    cant_carbon, cant_hierro, cant_madera, cant_trigo);
            usleep(SLEEP_TIME);
            acumulador.sumarPuntos(std::move(recursos));
        } catch(InventarioCerradoException) {
            break;
        }
    }
}
