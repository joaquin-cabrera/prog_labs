#ifndef RESERVA_H
#define RESERVA_H

#include "controladorHostal.h"
#include "controladorUsuario.h"

#include "Estadia.h"
#include "../Datatypes/DTFecha.h"
#include "../Datatypes/EstadoReserva.h"
#include "../Datatypes/DTReservaIndividual.h"
#include "../Datatypes/DTReservaGrupal.h"

#include <string>
#include <iostream>

using namespace std;
//forward declarations
class DTHuesped;
class Huesped;
class Habitacion;
class Estadia;


class Reserva{
    private:
        int codigo;
        DTFecha* checkIn;
        DTFecha* checkOut;
        EstadoReserva estado;
        Huesped* huesped;
        Habitacion* habitacion;
        Estadia* estadia;
        map<string, Huesped*> huespedes;
    public:
        Reserva();
        Reserva(int, DTFecha*, DTFecha*, Huesped*, Habitacion*, map<string, Huesped*>);
        virtual ~Reserva();
        int getCodigo();
        DTFecha* getCheckIn();
        DTFecha* getCheckOut();
        EstadoReserva getEstadoReserva();
        string getNombreHostal();
        string getNumHabitacion();
        vector<DTHuesped*> getHuespedes();
        Huesped* getHuesped();
        Habitacion* getHabitacion();
        float getCosto();
        Estadia* getEstadia();
        virtual void imprimirReserva() = 0;
        virtual DTReserva* getDT() = 0;
        void setEstadia(Estadia*);
        bool esHuesped(string);
        bool estaCancelada();
        void cerrarReserva();
        virtual void getCalificaciones(vector<DTCalificacion>* calificaciones) = 0;
        virtual void comentarCalificacion(string respuesta, string comentario) = 0;
};

#endif