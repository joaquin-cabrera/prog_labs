#ifndef FECHASISTEMA_H
#define FECHASISTEMA_H

#include "../Datatypes/DTFecha.h"

class FechaSistema{
    private:
        DTFecha* fecha;
        static FechaSistema* instancia;
        FechaSistema();
    public: 
        static FechaSistema* getInstance();
        void modificarFecha(DTFecha*);
        DTFecha* getDT();
};


#endif