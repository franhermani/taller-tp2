#include <exception>

#ifndef COLA_CERRADA_EXCEPTION_H
#define COLA_CERRADA_EXCEPTION_H

struct ColaCerradaException : public std::exception {
    const char * what() const throw() {
        return "La cola se encuentra cerrada\n";
    }
};

#endif // COLA_CERRADA_EXCEPTION_H
