#ifndef RECURSO_H
#define RECURSO_H

class Recurso {
    char tipo;
public:
    // Constructor
    // Recibe una referencia del tipo de recurso
    explicit Recurso(const char& tipo);

    // Asignacion por copia deshabilitado
    Recurso& operator=(const Recurso&) = delete;

    // Devuelve el tipo del recurso
    const char obtenerTipo() const;
};

#endif // RECURSO_H
