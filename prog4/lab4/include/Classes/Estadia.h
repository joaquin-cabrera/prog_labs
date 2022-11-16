#ifndef ESTADIA_H
#define ESTADIA_H

#include "../Datatypes/DTCalificacion.h"
#include "../Datatypes/DTHostal.h"
#include "../Datatypes/DTEstadia.h"
#include "Empleado.h"
#include <iostream>
#include "Huesped.h"
#include "Reserva.h"
#include "Calificacion.h"


#include <vector>

using namespace std;

class Reserva;
class Empleado;

class Estadia{
    private:
        DTFecha *llegada, *salida;
        Calificacion* calificacion;
        Reserva* reserva;
        Huesped* huesped;
        vector<Empleado*> empleados;
    public:
        Estadia();
        Estadia(DTFecha* llegada, Huesped*, Reserva*); 
        ~Estadia();
        DTCalificacion getDTCalificacion();
        bool tieneCalificacion();
        bool esActiva();
        bool esDeHuesped(string);
        bool estaEnHostal(string);
        void setSalida(DTFecha*);
        string getHostal();
        string getHuesped();
        int getCodigoReserva();
        DTEstadia* getDT();
        void comentarCalificacion(string respuesta);
        void modificar();
        void agregar(Empleado* empleado);
        void eliminar();
};

#endif