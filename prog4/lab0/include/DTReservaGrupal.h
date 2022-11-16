#ifndef DTRESERVAGRUPAL_H // include guard
#define DTRESERVAGRUPAL_H

#include "DTReserva.h"
#include "DTHuesped.h"

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


class DTReservaGrupal : public DTReserva{
    private:
        DTHuesped ** huespedes;
        int cantidad_huespedes;//agregado para manejar el arreglo
    public:
        DTReservaGrupal(int codigo,DTFecha *checkIn,DTFecha *checkOut, EstadoReserva estado, float costo, int habitacion, DTHuesped** huespedes, int cantidad_huespedes);
        virtual ~DTReservaGrupal();
        DTHuesped * * getHuespedes();
        int getCantidad_huespedes();
        friend ostream& operator<<(ostream& os, const DTReservaGrupal& r);
        virtual void imprimirReserva();
        bool esIndividual();
};

#endif /* DTRESERVAGRUPAL_H */