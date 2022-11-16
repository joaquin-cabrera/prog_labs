#ifndef DTHUESPED_H
#define DTHUESPED_H

#include "DTUsuario.h"

class DTHuesped: public DTUsuario{
    private:
        bool esFinger;
    public:
        DTHuesped();
        DTHuesped(string nombre, string email, string password, bool es);
        ~DTHuesped();
        bool getEsFinger();
        virtual void print();
        void imprimirBasic();
};

#endif