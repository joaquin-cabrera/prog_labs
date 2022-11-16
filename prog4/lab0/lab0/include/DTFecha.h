#ifndef DTFECHA_H // include guard
#define DTFECHA_H

#include <stdio.h>

#include <stdexcept>
#include <iostream>
using namespace std;

class DTFecha {
    private:
        int dia, mes, anio;
    public:
        DTFecha();
        DTFecha(int dia, int mes, int anio);
        int getDia();
        int getMes();
        int getAnio();
        int cantidadDias(const DTFecha &f);
        void imprimirFecha();
        DTFecha & operator= (const DTFecha &f);
        friend bool operator== (const DTFecha &f1, const DTFecha &f2);
};

#endif /* DTFECHA_H */