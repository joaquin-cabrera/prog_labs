#ifndef HUESPED_H
#define HUESPED_H

#include <iostream>
using std::string;
using std::cout;
using std::endl;

class Huesped{
    private:
        string nombre, email;
        bool esFinger;
    public:
        Huesped();
        Huesped(string nombre, string email, bool esFinger);
        string getNombre();
        string getEmail();
        bool getEsFinger();
        void imprimirHuesped();
};

#endif