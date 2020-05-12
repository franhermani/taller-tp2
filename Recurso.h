#ifndef RECURSO_H
#define RECURSO_H

class Recurso {
    char tipo;
public:
    explicit Recurso(const char& tipo) : tipo(tipo) {}
    const char obtenerTipo();
};

#endif // RECURSO_H
