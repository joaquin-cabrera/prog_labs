#ifndef DTCALIFICACION_H
#define DTCALIFICACION_H

#include "DTFecha.h"
#include <iostream>
#include "../Classes/Calificacion.h"


class DTCalificacion{
    private:
        int puntaje;
        DTFecha* fecha;
        std::string comentario;
        bool comentado;
        int codigoreserva;
    public:
        DTCalificacion(int puntaje, DTFecha* fecha, std::string comentario, bool comentado);
        DTCalificacion(int puntaje, DTFecha* fecha, std::string comentario, bool comentado, int codigoreserva);
        ~DTCalificacion();
        int getPuntaje();
        DTFecha* getFecha();
        std::string getComentario();
        bool getComentado();
        void setCodigoReserva(int codigo);
        int getCodigoReserva();
};

#endif