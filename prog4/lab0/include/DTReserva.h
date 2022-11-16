#ifndef DTRESERVA_H // include guard
#define DTRESERVA_H

#include "DTFecha.h"
#include "EstadoReserva.h"

#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;


class DTReserva{
    protected:
        int codigo;
        EstadoReserva estado;
        float costo;
        int habitacion;
        DTFecha *checkIn;
        DTFecha *checkOut;
    public:
        //necesario por herencia
        DTReserva();
        //No estoy seguro es este el cabezal del constructor y si es necesario por lo de abstracta.
        DTReserva(int codigo,DTFecha *checkIn,DTFecha *checkOut,EstadoReserva estado, float costo, int habitacion);
        //Necesita destructor para las fechas?.
        virtual ~DTReserva();
        int getCodigo();
        DTFecha * getCheckIn();
        DTFecha * getCheckOut();
        EstadoReserva getEstado();
        float getCosto();
        int getHabitacion();
        DTReserva & operator= (const DTReserva &r);
        friend bool operator== (const DTReserva &r1, const DTReserva &r2);
        virtual void imprimirReserva();
        virtual bool esIndividual() = 0;
};

#endif /* DTRESERVA_H */