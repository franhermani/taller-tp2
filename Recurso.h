#ifndef RECURSO_H
#define RECURSO_H

class Recurso {
    char tipo;
public:
    // Constructor
    // Recibe una referencia del tipo de recurso
    explicit Recurso(const char& tipo);

    // Devuelve el tipo del recurso
    const char obtenerTipo() const;
};

#endif // RECURSO_H
