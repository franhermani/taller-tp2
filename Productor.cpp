#include <vector>
#include <map>
#include <unistd.h>
#include <utility>
#include "Productor.h"
#include "defines.h"
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
            int puntos = calcularPuntos(std::move(recursos));
            acumulador.sumarPuntos(puntos);
        } catch(InventarioCerradoException) {
            break;
        }
    }
}

const int Productor::calcularPuntos(const std::vector<Recurso> recursos)
const {
    std::map<char, int> cantidades = {{CARBON, 0}, {HIERRO, 0},
                                      {MADERA, 0}, {TRIGO, 0}};
    int puntos_nuevos = 0;
    size_t i;
    for (i = 0; i < recursos.size(); i ++)
        cantidades[recursos[i].obtenerTipo()] += 1;

    if (cantidades[TRIGO] == CANT_T_COCINERO &&
        cantidades[CARBON] == CANT_C_COCINERO) {
        puntos_nuevos = PUNTOS_COCINERO;
    } else if (cantidades[MADERA] == CANT_M_CARPINTERO &&
               cantidades[HIERRO] == CANT_H_CARPINTERO) {
        puntos_nuevos = PUNTOS_CARPINTERO;
    } else if (cantidades[CARBON] == CANT_C_ARMERO &&
               cantidades[HIERRO] == CANT_H_ARMERO) {
        puntos_nuevos = PUNTOS_ARMERO;
    }
    return puntos_nuevos;
}
