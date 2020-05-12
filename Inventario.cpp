#include "Inventario.h"

void Inventario::depositarCarbon(Recurso recurso) {
    colaCarbon.encolar(recurso);
}

void Inventario::depositarHierro(Recurso recurso) {
    colaHierro.encolar(recurso);
}

void Inventario::depositarMadera(Recurso recurso) {
    colaMadera.encolar(recurso);
}

void Inventario::depositarTrigo(Recurso recurso) {
    colaTrigo.encolar(recurso);
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
