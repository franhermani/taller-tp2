#include <mutex>
#include <vector>
#include "Inventario.h"
#include "ColaCerradaException.h"
#include "ColaVaciaException.h"

Inventario::Inventario() : esta_cerrado(false) {}

void Inventario::depositarRecurso(Recurso recurso) {
    std::unique_lock<std::mutex> lock(mutex);

    // TODO: hacer esto polimorfico
    if (recurso.obtenerTipo() == 'C') {
        colaCarbon.encolar(recurso);
    } else if (recurso.obtenerTipo() == 'H') {
        colaHierro.encolar(recurso);
    } else if (recurso.obtenerTipo() == 'M') {
        colaMadera.encolar(recurso);
    } else if (recurso.obtenerTipo() == 'T') {
        colaTrigo.encolar(recurso);
    }
    cv.notify_all();
}

std::vector<Recurso> Inventario::consumirRecursos(const int cant_carbon,
        const int cant_hierro, const int cant_madera, const int cant_trigo) {
    std::unique_lock<std::mutex> lock(mutex);
    std::vector<Recurso> recursos;

    while (armarConjunto(recursos, cant_carbon, cant_hierro, cant_madera,
            cant_trigo)) {
        // TODO: tirar otra exception
        if (esta_cerrado) throw ColaCerradaException();
        cv.wait(lock);
    }
    return recursos;
}

bool Inventario::armarConjunto(std::vector<Recurso>& recursos,
        const int cant_carbon, const int cant_hierro, const int cant_madera,
        const int cant_trigo) {
    try {
        int i;
        for (i = 0; i < cant_carbon; i ++) {
            Recurso carbon = colaCarbon.desencolar();
            recursos.push_back(carbon);
        }
        for (i = 0; i < cant_hierro; i ++) {
            Recurso hierro = colaHierro.desencolar();
            recursos.push_back(hierro);
        }
        for (i = 0; i < cant_madera; i ++) {
            Recurso madera = colaMadera.desencolar();
            recursos.push_back(madera);
        }
        for (i = 0; i < cant_trigo; i ++) {
            Recurso trigo = colaTrigo.desencolar();
            recursos.push_back(trigo);
        }
    } catch(ColaVaciaException) {
        recursos.clear();
        return false;
    }
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
