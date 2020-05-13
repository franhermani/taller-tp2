#include <exception>

#ifndef COLAVACIAEXCEPTION_H
#define COLAVACIAEXCEPTION_H

struct ColaVaciaException : public std::exception {
    const char * what() const throw() {
        return "La cola se encuentra vacia";
    }
};

#endif // COLAVACIAEXCEPTION_H
