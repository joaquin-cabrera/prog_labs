#ifndef RESERVAINDIVIDUAL_H
#define RESERVAINDIVIDUAL_H

#include "Reserva.h"
#include "Huesped.h"

class ReservaIndividual: public Reserva{
    private:
        bool pagado;
    public:
        ReservaIndividual();
        virtual ~ReservaIndividual()=default;
        ReservaIndividual(int codigo, DTFecha *checkIn, DTFecha *checkOut, EstadoReserva estado, Habitacion *habitacion, Huesped *huesped, bool pagado);
        float calcularCosto();
        bool getPagado();
        bool esIndividual();
        void imprimirReserva();
};

#endif