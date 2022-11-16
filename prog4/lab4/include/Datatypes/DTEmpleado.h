#ifndef DTEMPLEADO_H
#define DTEMPLEADO_H

#include "DTUsuario.h"
#include "DTNotificacion.h"
#include "Cargo.h"

class DTEmpleado: public DTUsuario{
    private: 
        Cargo cargo;
        /* resolver como agregar notificaciones*/
    public:
        DTEmpleado();
        DTEmpleado(string nombre, string email, string password, Cargo cargo);
        ~DTEmpleado();
        Cargo getCargo();
        virtual void print();
};

#endif