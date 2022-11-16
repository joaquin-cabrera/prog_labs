#ifndef DTRESERVAINDIVIDUAL_H
#define DTRESERVAINDIVIDUAL_H

#include "DTReserva.h"

class DTReservaIndividual: public DTReserva{
    public:
        DTReservaIndividual();
        DTReservaIndividual(int,DTFecha*,DTFecha*,EstadoReserva,string);
        ~DTReservaIndividual();
        void imprimir();
};

#endif