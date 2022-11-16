#include "../../include/Classes/Habitacion.h"

Habitacion::Habitacion(){
    numero = "";
    precio = 0.0;
    capacidad = 0;
    hostal = nullptr;
}
Habitacion::Habitacion(std::string numero, float precio, int capacidad, Hostal* hostal){
    this->numero = numero;
    this->precio = precio;
    this->capacidad = capacidad;
    this->hostal = hostal;
}

std::string Habitacion::getNumero(){
    return numero;
}

float Habitacion::getPrecio(){
    return precio;
}

int Habitacion::getCapacidad(){
    return capacidad;
}


bool Habitacion::habDisponible(DTFecha* f1, DTFecha* f2){
    map<int,Reserva*>::iterator it = reservas.begin();
    bool disponible = true;
    if(!reservas.empty()){
        while( it != reservas.end() && disponible){

            DTFecha* checkIn = it->second->getCheckIn();
            DTFecha* checkOut = it->second->getCheckOut();

            disponible = (checkIn->fechaMenor(f1) && checkIn->fechaMenor(f2)) || (checkOut->fechaMayor(f1) && checkOut->fechaMayor(f2));

            checkIn = checkOut = NULL;

            ++it;
        }
    } 

    return disponible;
}


DTHabitacion* Habitacion::getDt(){
    DTHabitacion* dtHab = new DTHabitacion(getNumero(), getPrecio(),getCapacidad());
    return dtHab;
}

string Habitacion::getNombreHostal(){
    return this->hostal->getNombre();
}

void Habitacion::agregarRes(Reserva* res){
    reservas[res->getCodigo()] = res;
}

void Habitacion::getCalificaciones(vector<DTCalificacion>* calificaciones) {
    for(map<int, Reserva*>::iterator i = reservas.begin(); i != reservas.end(); i++)
        i->second->getCalificaciones(calificaciones);
}

DTHabitacion Habitacion::getDTHabitacion() {
    return DTHabitacion(this->getNumero(), this->getPrecio(), this->getCapacidad());
}

void Habitacion::cerrarReseva(int codigo){
    reservas[codigo] = NULL;
}