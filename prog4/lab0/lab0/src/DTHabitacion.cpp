#include "../include/DTHabitacion.h"

DTHabitacion::DTHabitacion(int numero, float precio, int capacidad){
    this->numero = numero;
    this->precio = precio;
    this->capacidad = capacidad;
}
        
int DTHabitacion::getNumero(){
    return this->numero;
}

float DTHabitacion::getPrecio(){
    return this->precio;
}
int DTHabitacion::getCapacidad(){
    return this->capacidad;
}

DTHabitacion & DTHabitacion::operator= (const DTHabitacion &h){
    this->numero = h.numero;
    this->capacidad = h.capacidad;
    this->precio = h.precio;
    return *this;
}

bool operator== (const DTHabitacion &h1, const DTHabitacion &h2){
    return (h1.numero == h2.numero);//si cambia el precio es la misma hab?
}


void DTHabitacion::imprimirHabitacion(){
    cout << "Numero: " << this->numero << endl;
    cout << "Capacidad: " << this->capacidad << endl;
    cout << "Precio: " << this->precio << endl;
}
