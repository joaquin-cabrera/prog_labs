#include "../../include/Datatypes/DTHostal.h"

DTHostal::DTHostal(string nombre, string direccion, string telefono){
    this->nombre = nombre;
    this->direccion = direccion;
    this->telefono = telefono;
    this->promedio = -1;
}

string DTHostal::getNombre(){ return this->nombre; }

string DTHostal::getDireccion(){ return this->direccion; }

string DTHostal::getTelefono(){ return this->telefono; }


void DTHostal::imprimir(){
    cout << this->nombre << " / " << this->direccion << " / " << this->telefono << endl;

}


float DTHostal::getPromedio(){ return 0; }