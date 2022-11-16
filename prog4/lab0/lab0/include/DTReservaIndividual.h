#ifndef DTRESERVAINDIVIDUAL_H // include guard
#define DTRESERVAINDIVIDUAL_H

#include "DTReserva.h"

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

class DTReservaIndividual : public DTReserva {
    private:
        bool pagado;
    public:
        DTReservaIndividual(int codigo,DTFecha *checkIn,DTFecha *checkOut,EstadoReserva estado, float costo, int habitacion,bool pagado);
        virtual ~DTReservaIndividual();
        bool getPagado();
        void imprimirReserva();
        friend ostream& operator<<(ostream& os, const DTReservaIndividual & r);
        bool esIndividual();

};

#endif /* DTRESERVAINDIVIDUAL_H */