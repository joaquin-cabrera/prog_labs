#include "../include/Habitacion.h"

Habitacion::Habitacion(){
    numero = 0;
    precio = 0;
    capacidad = 0;
}

Habitacion::Habitacion(int numero, int capacidad, float precio){
    this->numero = numero;
    this->capacidad = capacidad;
    this->precio = precio;
}

int Habitacion::getNumero(){ 
    return numero; 
}

int Habitacion::getCapacidad(){ 
    return capacidad; 
}

float Habitacion::getPrecio(){ 
    return precio; 
}

void Habitacion::imprimirHabitacion(){
    cout << "------------------------------\n";
    cout << " Numero: " << numero << endl;
    cout << " Precio: " << precio << "\n";
    cout << " Capacidad: " << capacidad << "\n";
    //cout << "------------------------------\n";
}