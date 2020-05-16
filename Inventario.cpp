#include <mutex>
#include <vector>
#include "defines.h"
#include "Inventario.h"
#include "InventarioCerradoException.h"

Inventario::Inventario() : esta_cerrado(false) {}

void Inventario::depositarRecurso(Recurso recurso) {
    std::unique_lock<std::mutex> lock(mutex);

    if (recurso.obtenerTipo() == CARBON) {
        colaCarbon.encolar(recurso);
    } else if (recurso.obtenerTipo() == HIERRO) {
        colaHierro.encolar(recurso);
    } else if (recurso.obtenerTipo() == MADERA) {
        colaMadera.encolar(recurso);
    } else if (recurso.obtenerTipo() == TRIGO) {
        colaTrigo.encolar(recurso);
    }
    cv.notify_all();
}

const std::vector<Recurso> Inventario::consumirRecursos(const int cant_carbon,
        const int cant_hierro, const int cant_madera, const int cant_trigo) {
    std::unique_lock<std::mutex> lock(mutex);
    std::vector<Recurso> recursos;

    while (! armarConjunto(recursos, cant_carbon, cant_hierro, cant_madera,
                           cant_trigo)) {
        if (esta_cerrado) throw InventarioCerradoException();
        cv.wait(lock);
    }
    return recursos;
}

const bool Inventario::armarConjunto(std::vector<Recurso>& recursos,
        const int cant_carbon, const int cant_hierro, const int cant_madera,
        const int cant_trigo) {
    if (cant_carbon > colaCarbon.obtenerLargo() ||
        cant_hierro > colaHierro.obtenerLargo() ||
        cant_madera > colaMadera.obtenerLargo() ||
        cant_trigo > colaTrigo.obtenerLargo()) return false;

    int i;
    for (i = 0; i < cant_carbon; i ++)
        recursos.push_back(colaCarbon.desencolar());
    for (i = 0; i < cant_hierro; i ++)
        recursos.push_back(colaHierro.desencolar());
    for (i = 0; i < cant_madera; i ++)
        recursos.push_back(colaMadera.desencolar());
    for (i = 0; i < cant_trigo; i ++)
        recursos.push_back(colaTrigo.desencolar());

    return true;
}

void Inventario::cerrar() {
    std::unique_lock<std::mutex> lock(mutex);
    esta_cerrado = true;
    cv.notify_all();
}

const int Inventario::obtenerSobrantesCarbon() {
    return colaCarbon.obtenerLargo();
}

const int Inventario::obtenerSobrantesHierro() {
    return colaHierro.obtenerLargo();
}

const int Inventario::obtenerSobrantesMadera() {
    return colaMadera.obtenerLargo();
}

const int Inventario::obtenerSobrantesTrigo() {
    return colaTrigo.obtenerLargo();
}
