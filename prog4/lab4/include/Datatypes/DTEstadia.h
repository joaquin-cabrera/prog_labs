#ifndef DTESTADIA_H
#define DTESTADIA_H

#include "DTFecha.h"
#include <iostream>

using namespace std;

class DTEstadia{
    private:
        DTFecha *llegada, *salida;
        int codigoReserva;
        string emailHuesped, nombreHostal, numHab;
    public:
        DTEstadia();
        DTEstadia(DTFecha*, int, string, string, string);
        DTEstadia(DTFecha*, DTFecha*, int, string, string, string);
        ~DTEstadia();
        DTFecha getLlegada();
        DTFecha* getSalida();
        string getEmail();
       int getCodigo();
        void imprimir();
        void imprimirBasic();
};

#endif