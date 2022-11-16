#ifndef HOSTAL_H
#define HOSTAL_H

#include "Habitacion.h"
#include "../Datatypes/DTHostal.h"
#include "../Datatypes/DTCalificacion.h"
#include "../Datatypes/DTHabitacion.h"


#include <map>
#include <vector>
#include <string>
#include <iostream>

//forward declaration
class Habitacion;

class Hostal{
    private:
        string nombre, direccion, telefono;
        vector<Habitacion*> habitaciones;
    public:
        Hostal();
        Hostal(std::string, std::string, std::string);
        std::string getNombre();
        std::string getDireccion();
        std::string getTelefono();
        vector<Habitacion*> getHabitaciones();
        Habitacion* getHabitacion(string numHab);
        map<std::string, DTHostal*> listarHostales();
        void imprimirHostal();
        DTHostal* getDT();
        void vincularHabitacion(Habitacion* hab);
        float getPromedio();
        void getCalificaciones(vector<DTCalificacion>* calificaciones);
        void getDTHabitaciones(vector<DTHabitacion>* h);
};

#endif