#include "Inventario.h"

Inventario::Inventario() {}

void Inventario::depositarRecurso(Recurso recurso) {
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
}

Recurso Inventario::consumirCarbon() {
    return colaCarbon.desencolar();
}

Recurso Inventario::consumirHierro() {
    return colaHierro.desencolar();
}

Recurso Inventario::consumirMadera() {
    return colaMadera.desencolar();
}

Recurso Inventario::consumirTrigo() {
    return colaTrigo.desencolar();
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
