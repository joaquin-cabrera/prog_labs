#ifndef DTHABITACION_H // include guard
#define DTHABITACION_H

#include <stdio.h>

#include <iostream>
using namespace std;

class DTHabitacion{
    private:
        int numero,capacidad;
        float precio;
    public:
        DTHabitacion(int numero, float precio, int capacidad);
        int getNumero();
        float getPrecio();
        int getCapacidad();
        DTHabitacion & operator= (const DTHabitacion &h);
        friend bool operator== (const DTHabitacion &h1, const DTHabitacion &h2);
        void imprimirHabitacion();
};

#endif /* DTHABITACION_H */