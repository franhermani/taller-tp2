#include "Inventario.h"

void Inventario::depositarCarbon(Carbon carbon) {
    this->colaCarbon.encolar(carbon);
}

void Inventario::depositarHierro(Hierro hierro) {
    this->colaHierro.encolar(hierro);
}

void Inventario::depositarMadera(Madera madera) {
    this->colaMadera.encolar(madera);
}

void Inventario::depositarTrigo(Trigo trigo) {
    this->colaTrigo.encolar(trigo);
}

Carbon Inventario::consumirCarbon() {
    return this->colaCarbon.desencolar();
}

Hierro Inventario::consumirHierro() {
    return this->colaHierro.desencolar();
}

Madera Inventario::consumirMadera() {
    return this->colaMadera.desencolar();
}

Trigo Inventario::consumirTrigo() {
    return this->colaTrigo.desencolar();
}
