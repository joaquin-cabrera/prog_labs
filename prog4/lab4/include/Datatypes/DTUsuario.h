#ifndef DTUSUARIO_H
#define DTUSUARIO_H

#include <string>
#include <iostream>
using namespace std;

class DTUsuario{
    private:
        string nombre, email, password;
    public:
        DTUsuario();
        DTUsuario(string nombre, string email, string password);
        virtual ~DTUsuario();
        string getNombre();
        string getEmail();
        string getPassword();
        virtual void print();
        void setEmail(string);
        void setNombre(string);
        void setPassword(string);
};

#endif