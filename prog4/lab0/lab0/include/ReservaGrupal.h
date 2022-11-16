#ifndef RESERVAGRUPAL_H
#define RESERVAGRUPAL_H

#include "Reserva.h"
#include "Huesped.h"

class ReservaGrupal: public Reserva{
    private:
        int cantidadHuespedes;
        Huesped**huespedes;
    public:
        ReservaGrupal();
        virtual ~ReservaGrupal();
        ReservaGrupal(int codigo, DTFecha *checkIn, DTFecha *checkOut, EstadoReserva estado, Habitacion *habitacion, Huesped *huesped, Huesped**huespedes, int cantidadHuespedes);
        Huesped** getHuespedes();
        int getCantHuespedes();
        float calcularCosto();
        bool esIndividual();
        void imprimirReserva();
};

#endif