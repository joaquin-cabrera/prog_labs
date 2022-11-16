#include "../include/Reserva.h"

Reserva::Reserva(){
    codigo = 0;
    checkIn = checkOut = NULL;
    habitacion = NULL;
    huesped = NULL;
    estado = EstadoReserva::Abierta;
}

Reserva::Reserva(int codigo, DTFecha *checkIn, DTFecha *checkOut, EstadoReserva estado, Habitacion *habitacion, Huesped *huesped){
    this->codigo = codigo;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = estado;
    this->habitacion = habitacion;
    this->huesped = huesped;
}

Reserva::~Reserva(){
    delete checkIn;
    delete checkOut;
}

int Reserva::getCodigo(){
    return codigo;
}

EstadoReserva Reserva::getEstado(){
    return estado;
}

DTFecha* Reserva::getCheckIn() {
    return checkIn;
}

DTFecha* Reserva::getCheckOut(){
    return checkOut;
}

Habitacion* Reserva::getHabitacion(){
    return habitacion;
}
Huesped* Reserva::getHuesped(){
    return huesped;
}

void Reserva::setEstado(EstadoReserva estado){
    this->estado = estado;
}
void Reserva::imprimirReserva(){
    
}