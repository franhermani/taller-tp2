#ifndef LENIADOR_H
#define LENIADOR_H

#include "Recolector.h"

class Leniador: public Recolector {
public:
    Leniador();
    Leniador(const Leniador& other) = delete;
    Leniador& operator=(const Leniador& other) = delete;
};

#endif // LENIADOR_H
