#include <map>
#include "Inventario.h"

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

const std::map<char, int> Inventario::obtenerSobrantes() {
    std::map<char, int> sobrantes;

    sobrantes['C'] = this->colaCarbon.obtenerLargo();
    sobrantes['H'] = this->colaHierro.obtenerLargo();
    sobrantes['M'] = this->colaMadera.obtenerLargo();
    sobrantes['T'] = this->colaTrigo.obtenerLargo();

    return sobrantes;
}
