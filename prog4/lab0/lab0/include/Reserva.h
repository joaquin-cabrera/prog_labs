#ifndef RESERVA_H
#define RESERVA_H

#include "DTFecha.h"
#include "EstadoReserva.h"
#include "Habitacion.h"
#include "Huesped.h"

class Reserva{
    private: 
        int codigo;
        DTFecha *checkIn, *checkOut;
        EstadoReserva estado;
        Habitacion *habitacion;
        Huesped *huesped;
    public:
        Reserva();
        Reserva(int codigo, DTFecha *checkIn, DTFecha *checkOut, EstadoReserva estado, Habitacion *habitacion, Huesped *huesped);
        virtual ~Reserva();
        int getCodigo();
        EstadoReserva getEstado();
        DTFecha *getCheckIn();
        DTFecha *getCheckOut();
        Habitacion *getHabitacion();
        Huesped *getHuesped();
        void setEstado(EstadoReserva estado);
        virtual float calcularCosto() = 0;
        virtual bool esIndividual() = 0; 
        virtual void imprimirReserva();
};

#endif