#ifndef DTHOSTAL_H
#define DTHOSTAL_H

#include <string>
#include <iostream>

using namespace std;

class DTHostal{
    private:    
        string nombre, direccion, telefono;
        float promedio;
    public:
        DTHostal();
        DTHostal(string, string, string);
        //~DTHostal();
        string getNombre();
        string getDireccion();
        string getTelefono();
        float getPromedio();
        void imprimir();
};

#endif