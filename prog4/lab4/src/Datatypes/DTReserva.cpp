#include "../../include/Datatypes/DTReserva.h"

DTReserva::DTReserva(int codigo, DTFecha* checkIn, DTFecha* checkOut, EstadoReserva estado, string numHab){
    this->codigo = codigo;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
    this->estado = estado;
    this->numeroHabitacion = numHab;
}

int DTReserva::getCodigo(){
    return this->codigo;
}

DTFecha* DTReserva::getCheckIn(){
    return this->checkIn;
}
DTFecha* DTReserva::getCheckOut(){
    return this->checkOut;
}

EstadoReserva DTReserva::getEstadoReserva(){
    return this->estado;
}

string DTReserva::getNumHabitacion(){
    return this->numeroHabitacion;
}

void DTReserva::imprimirEstado(){
    switch(this->estado){
        case(EstadoReserva::Abierta):
            cout << "Abierta";        
            break;
        case(EstadoReserva::Cerrada):
            cout << "Cerrada";
            break;
        case(EstadoReserva::Cancelada):
            cout << "Cancelada";
            break;
    }    
}