#ifndef IESTADIARESERVA_H
#define IESTADIARESERVA_H

#include "Reserva.h"
#include "ReservaIndividual.h"
#include "ReservaGrupal.h"
#include "Estadia.h"
#include "controladorUsuario.h"
#include "controladorHostal.h"
#include "FechaSistema.h"

#include "../Datatypes/DTReservaIndividual.h"
#include "../Datatypes/DTReservaGrupal.h"
#include "../Datatypes/DTReserva.h"



#include <iostream> 
#include <map>


class IEstadiaReserva{
    public:
        virtual void ingresarReserva(DTFecha*, DTFecha*, string, string, string, map<string, DTHuesped*> listaHospedados) = 0;
        virtual void registrarEstadia(DTReserva*, string) = 0;
        virtual void finalizarEstadia(int, string) = 0;
        virtual void cerrarReserva(int) = 0;
        virtual void darDeBaja(int) = 0;
        virtual void imprimirReservas() = 0;
        virtual vector<DTReserva*> getReservasHostal(string) = 0;
        virtual vector<DTHuesped*> listarHuespedesReserva(int) = 0;
        virtual vector<DTReserva*> listarReservasNoCanceladas(string) = 0;
        virtual vector<DTEstadia*> listarEstadiasHostal(string) = 0;
        virtual DTReserva* getDTReserva(int) = 0;
        virtual DTEstadia* getEstadia(string Hostal, string) = 0;
        virtual bool existeEstadia(string, string) = 0;
        virtual int obtenerCodigo(DTFecha*, DTFecha*, string, string) = 0;
        virtual void comentarCalificacion(string respuesta, int codigo_reserva, string comentario) = 0;
};

#endif