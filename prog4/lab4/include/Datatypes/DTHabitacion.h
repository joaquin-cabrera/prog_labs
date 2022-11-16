#ifndef DTHABITACION_H
#define DTHABITACION_H

#include <iostream>
#include <string>
using namespace std;

class DTHabitacion{
    private:
        std::string numero;
        float precio;
        int capacidad;
    public:
        DTHabitacion();
        DTHabitacion(std::string numero, float precio, int capacidad);
        ~DTHabitacion();
        std::string getNumero();
        float getPrecio();
        int getCapacidad();
        void imprimir();
};

#endif