#include <exception>

#ifndef COLAVACIAEXCEPTION_H
#define COLAVACIAEXCEPTION_H

struct ColaVaciaException : public std::exception {
    const char * what() const throw() {
        return "No hay elementos para desencolar";
    }
};

#endif // COLAVACIAEXCEPTION_H
