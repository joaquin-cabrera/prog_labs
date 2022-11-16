#ifndef HABITACION_H
#define HABITACION_H

#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Habitacion{
    private:   
        int numero, capacidad;
        float precio;
    public:
        Habitacion();
        Habitacion(int numero, int capacidad, float precio);
        int getNumero();
        int getCapacidad();
        float getPrecio();
        void imprimirHabitacion();
};

#endif