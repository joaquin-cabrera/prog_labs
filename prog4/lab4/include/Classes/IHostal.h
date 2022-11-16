#ifndef IHOSTAL_H
#define IHOSTAL_H

#include "Hostal.h"
#include "Habitacion.h"
#include "../Datatypes/DTHostal.h"
#include "../Datatypes/DTHabitacion.h"
#include "../Datatypes/DTFecha.h"
#include "../Datatypes/DTCalificacion.h"

#include <map>
#include <vector>
#include <set>
#include <iostream>
#include <string>

class IHostal{
    public:
        virtual vector<DTHostal*> listarHostales() = 0;
        virtual void ingresarHostal(string, string, string) = 0;
        //virtual void ingresarHabitacion(string, float, int, string);
        virtual void datosHabitacion(std::string numero, float precio,int capacidad, DTHostal* hostalEnSistema) = 0;
        virtual void agregarHabitacion() = 0;
        virtual bool hostalEnSistema(string) = 0;
        virtual vector<DTHabitacion*> listarHabDisponibles(DTFecha*, DTFecha*, string) = 0;
        virtual void cancelarOperacion() = 0;

        virtual vector<string> topHostales() = 0;
        virtual void detallesHostal(string hostal, vector<DTCalificacion>* calificaciones) = 0;
        virtual float getPromedio(string hostal) = 0;
        virtual void obtenerHabitaciones(string hostal, vector<DTHabitacion>* habitaciones) = 0;
};

#endif