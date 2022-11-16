#ifndef DTCALIFICACIONIDENTIFICABLE_H
#define DTCALIFICACIONIDENTIFICABLE_H

#include "DTCalificacion.h"
#include <iostream>

class DTCalificacion;

class DTCalificacionIdentificable{
    private:
        DTCalificacion* calificacion;
        std::string emailHuesped;
        int codigoReserva;
    public:
        DTCalificacionIdentificable();
        DTCalificacionIdentificable(DTCalificacion calificacion, std::string emailHuesped, int codigoReserva);
        ~DTCalificacionIdentificable();
        DTCalificacion getCalificacion();
        std::string getEmailHuesped();
        int getCodigoReserva();
};

#endif