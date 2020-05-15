#include <exception>

#ifndef COLACERRADAEXCEPTION_H
#define COLACERRADAEXCEPTION_H

struct ColaCerradaException : public std::exception {
    const char * what() const throw() {
        return "La cola se encuentra cerrada\n";
    }
};

#endif // COLACERRADAEXCEPTION_H
