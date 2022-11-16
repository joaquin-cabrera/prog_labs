#include "../../include/Datatypes/DTHabitacion.h"

DTHabitacion::DTHabitacion(string numero, float precio, int capacidad){
    this->numero = numero;
    this->precio = precio;
    this->capacidad = capacidad;
}

DTHabitacion::~DTHabitacion() {

}

string DTHabitacion::getNumero(){ return this->numero; }

void DTHabitacion::imprimir(){
    cout << "Numero: " << numero << "| Precio: " << precio << "| Capacidad: " << capacidad;
}