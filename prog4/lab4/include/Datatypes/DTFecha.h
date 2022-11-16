#ifndef DTFECHA_H
#define DTFECHA_H

#include <iostream>
using namespace std;

class DTFecha{
    private:
        int dia, mes, anio, hora;
    public:
        DTFecha();
        DTFecha(int, int, int, int);
        ~DTFecha();
        int getDia();
        int getMes();
        int getAnio();
        int getHora();
        /* retorna true si la fecha pasada como paramentro es menor */
        bool fechaMenor(DTFecha*);
        bool fechasIguales(DTFecha*);/* retorna true si las fechas son exactamente iguales */
        bool fechaMayor(DTFecha*); /* retorna true si la fecha pasada como paramentro es mayor */
        void imprimirFecha();
};

#endif