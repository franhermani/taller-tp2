#include "Inventario.h"

Inventario::Inventario() {
    this->colaCarbon = Cola();
    this->colaHierro = Cola();
    this->colaMadera = Cola();
    this->colaTrigo = Cola();
}

void Inventario::depositarCarbon(Recurso recurso) {
    this->colaCarbon.encolar(recurso);
}

void Inventario::depositarHierro(Recurso recurso) {
    this->colaHierro.encolar(recurso);
}

void Inventario::depositarMadera(Recurso recurso) {
    this->colaMadera.encolar(recurso);
}

void Inventario::depositarTrigo(Recurso recurso) {
    this->colaTrigo.encolar(recurso);
}

Recurso Inventario::consumirCarbon() {
    return this->colaCarbon.desencolar();
}

Recurso Inventario::consumirHierro() {
    return this->colaHierro.desencolar();
}

Recurso Inventario::consumirMadera() {
    return this->colaMadera.desencolar();
}

Recurso Inventario::consumirTrigo() {
    return this->colaTrigo.desencolar();
}

const int Inventario::obtenerSobrantesCarbon() {
    return this->colaCarbon.obtenerLargo();
}

const int Inventario::obtenerSobrantesHierro() {
    return this->colaHierro.obtenerLargo();
}

const int Inventario::obtenerSobrantesMadera() {
    return this->colaMadera.obtenerLargo();
}

const int Inventario::obtenerSobrantesTrigo() {
    return this->colaTrigo.obtenerLargo();
}
