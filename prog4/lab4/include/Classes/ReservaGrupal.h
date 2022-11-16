#ifndef RESERVAGRUPAL_H
#define RESERVAGRUPAL_H

#include "Reserva.h"
#include "../Datatypes/DTReservaGrupal.h"

class ReservaGrupal: public Reserva{
    private:
        vector<Estadia*> estadias;
        int cantHospedados;
    public:
        ReservaGrupal();
        ReservaGrupal(int, DTFecha*, DTFecha*, Huesped*, Habitacion*, map<string, Huesped*>);
        ~ReservaGrupal();
        void imprimirReserva();
        DTReserva* getDT();
        void getCalificaciones(vector<DTCalificacion>* calificaciones);
        void agregarEstadia(Estadia*);
        void comentarCalificacion(string respuesta, string comentario);
};
 
#endif