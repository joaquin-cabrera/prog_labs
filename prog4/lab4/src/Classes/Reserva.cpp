#include "../../include/Classes/Reserva.h"

Reserva::Reserva(int codigo, DTFecha* checkIn, DTFecha* checkOut, Huesped* hue, Habitacion* hab, map<string, Huesped*> listaHospedados){
    this->estado = EstadoReserva::Abierta;
    this->checkIn = checkIn;
    this->checkOut = checkOut; 
    this->estadia = NULL; 
    this->huesped = hue;
    this->habitacion = hab;
    this->codigo = codigo;    
    this->huespedes.insert(listaHospedados.begin(), listaHospedados.end());
}

Reserva::~Reserva(){
    this->huesped = NULL;
    this->habitacion = NULL;
    map<string, Huesped*>::iterator it;
    for( it = huespedes.begin(); it != huespedes.end(); ++it){
        string email = it->first;
        huespedes[email] = NULL; 
    }
    delete this->estadia;
    delete this->checkIn;
    delete this->checkOut;        
}

int Reserva::getCodigo(){ return this->codigo; }
DTFecha* Reserva::getCheckIn(){ return this->checkIn; }
DTFecha* Reserva::getCheckOut(){ return this->checkOut; }
EstadoReserva Reserva::getEstadoReserva(){ return this->estado; }
string Reserva::getNombreHostal(){
    return this->habitacion->getNombreHostal();
}

string Reserva::getNumHabitacion(){
    return this->habitacion->getNumero();
}

vector<DTHuesped*> Reserva::getHuespedes(){
    map<string, Huesped*>::iterator it;
    vector<DTHuesped*> resHuespedes;
    for( it = huespedes.begin(); it != huespedes.end(); ++it){
        resHuespedes.push_back(dynamic_cast<DTHuesped*>(it->second->getDT()));
    }
    return resHuespedes;
}

Estadia* Reserva::getEstadia() {
    return estadia;
}

bool Reserva::esHuesped(string email){
    map<string, Huesped*>::iterator it = huespedes.begin();
    while( it != huespedes.end() && it->second->getEmail() != email){
        ++it;
    }
    return !(it == huespedes.end());
}

bool Reserva::estaCancelada(){
    return this->estado == EstadoReserva::Cancelada;
}

void Reserva::cerrarReserva(){
    this->estado = EstadoReserva::Cerrada;
}

void Reserva::setEstadia(Estadia* est){
    this->estadia = est;
}
Huesped* Reserva::getHuesped(){
    return this->huesped;
}

Habitacion* Reserva::getHabitacion(){
    return this->habitacion;
}