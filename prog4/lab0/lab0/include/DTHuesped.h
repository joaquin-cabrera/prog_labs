#ifndef DTHUESPED_H // include guard
#define DTHUESPED_H

#include <stdio.h>

#include <iostream>
#include <string>
using namespace std;


class DTHuesped{
    private:
        string nombre;
        string email;
        bool esFinger;
    public:
        DTHuesped(string nombre, string email, bool esFinger);
        string getNombre();
        string getEmail();
        bool getEsFinger();
        DTHuesped & operator= (const DTHuesped &h);
        friend bool operator == (const DTHuesped &h1, const DTHuesped &h2);
        void imprimirHuesped();
        
};

#endif /* DTHUESPED_H */