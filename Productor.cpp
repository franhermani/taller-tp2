#include "Productor.h"

Productor::Productor(Inventario &inventario, AcumuladorPuntos &acumulador,
        const int cant_carbon, const int cant_hierro,
        const int cant_madera, const int cant_trigo) :
        inventario(inventario), acumulador(acumulador),
        cant_carbon(cant_carbon), cant_hierro(cant_hierro),
        cant_madera(cant_madera), cant_trigo(cant_trigo) {}

void Productor::run() {
//    TODO: recibe el inventario y el acumulador de puntos
//    while (true) {
//
//    }
}
