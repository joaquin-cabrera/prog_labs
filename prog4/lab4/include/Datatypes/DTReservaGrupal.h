#ifndef DTRESERVAGRUPAL_H
#define DTRESERVAGRUPAL_H

#include "DTReserva.h"



class DTReservaGrupal: public DTReserva{
    private:
        int cantidadHospedadosActual;
    public:
        DTReservaGrupal();
        DTReservaGrupal(int,DTFecha*,DTFecha*,EstadoReserva,string);
        ~DTReservaGrupal();
       // int getCantidadHospedadosActual();
        void imprimir();
};

#endif