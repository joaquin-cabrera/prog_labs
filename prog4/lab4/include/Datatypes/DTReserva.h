#ifndef DTRESERVA_H
#define DTRESERVA_H

#include "DTFecha.h"
#include "EstadoReserva.h"
#include "DTHuesped.h"

#include <vector>

class DTReserva{
    private:
        int codigo;
        DTFecha *checkIn, *checkOut;
        EstadoReserva estado;
        string numeroHabitacion;
        vector<DTHuesped*> huespedes;
    public:
        DTReserva();
        DTReserva(int codigo, DTFecha *checkIn, DTFecha* checkOut, EstadoReserva estado, string numHab);
        ~DTReserva();
        int getCodigo();
        DTFecha* getCheckIn();
        DTFecha* getCheckOut();
        string getNumHabitacion();
        EstadoReserva getEstadoReserva();
        vector<string> getHuespedes();
        void imprimirEstado();
        virtual void imprimir() = 0;

};      

#endif