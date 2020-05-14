#include <exception>

#ifndef INVENTARIO_CERRADO_EXCEPTION_H
#define INVENTARIO_CERRADO_EXCEPTION_H

struct InventarioCerradoException : public std::exception {
    const char * what() const throw() {
        return "El inventario se encuentra cerrado";
    }
};

#endif // INVENTARIO_CERRADO_EXCEPTION_H
