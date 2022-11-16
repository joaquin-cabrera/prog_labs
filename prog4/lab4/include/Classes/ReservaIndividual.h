#ifndef RESERVAINDIVIDUAL_H
#define RESERVAINDIVIDUAL_H

#include "Reserva.h"
#include "../../include/Datatypes/DTReservaIndividual.h"

class ReservaIndividual: public Reserva{
    public:
        ReservaIndividual();
        ReservaIndividual(int, DTFecha*, DTFecha*, Huesped*, Habitacion*,map<string, Huesped*>);
        ~ReservaIndividual();
        void imprimirReserva();
        DTReserva* getDT();
        void getCalificaciones(vector<DTCalificacion>* calificaciones);
        void comentarCalificacion(string respuesta, string comentario);

};


#endif
