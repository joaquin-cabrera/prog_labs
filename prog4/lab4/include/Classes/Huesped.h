#ifndef HUESPED_H
#define HUESPED_H

#include "Usuario.h"
#include "../../include/Datatypes/DTHuesped.h"

class Huesped: public Usuario{
    private:
        bool esFinger;
    public:
        Huesped();
        Huesped(string, string, string, bool);
        ~Huesped();
        bool getEsFinger();
        DTUsuario* getDT();
};

#endif