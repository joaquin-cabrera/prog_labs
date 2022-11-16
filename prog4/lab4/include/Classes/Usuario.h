#ifndef USUARIO_H
#define USUARIO_H

#include "../Datatypes/DTUsuario.h"

#include <stdio.h>
#include <string>

using namespace std;

class Usuario{
    private:
        string nombre, email, password;      
    public:
        Usuario();
        Usuario(string, string, string);
        ~Usuario();
        string getNombre();
        string getEmail();
        string getPassword();
        virtual DTUsuario* getDT();
};

#endif