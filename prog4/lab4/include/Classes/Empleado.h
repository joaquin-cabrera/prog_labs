#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <set>

#include "Usuario.h"
#include "Hostal.h"
#include "Estadia.h"
#include "IObserver.h"
#include "../../include/Datatypes/Cargo.h"
#include "../../include/Datatypes/DTEmpleado.h"
#include "../Datatypes/DTNotificacion.h"

//forward declarations
class Hostal;


class Empleado: public Usuario, public IObserver{
    private:
        Cargo cargo;
//        set<DTNotificacion*> notif; 
        bool subscrito;
        Hostal * trabajo;
        vector<Estadia*> notificaciones;
    public:
        Empleado();
        Empleado(string nombre, string email, string password, Cargo cargo);
        ~Empleado();
        Cargo getCargo();
        DTUsuario* getDT();
        bool tieneTrabajo();

        void setCargo(Cargo cargo);

        void vincularHostal(Hostal *);

        string trabajaEn();

        void notificar(Estadia* estadia);
};



#endif