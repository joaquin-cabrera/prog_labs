#include "../include/DTReserva.h"

DTReserva::DTReserva(){
    this->codigo = 0;
    this->checkIn = NULL;
    this->checkOut = NULL;
    this->costo = 0;
    this->habitacion = 0;
    this->estado = EstadoReserva::Abierta;

}

DTReserva::DTReserva(int codigo,DTFecha *checkIn,DTFecha *checkOut,EstadoReserva estado, float costo, int habitacion){
    this->codigo = codigo;
    this->costo = costo;
    this->habitacion = habitacion;
    this->estado = estado;
    this->checkIn = checkIn;
    this->checkOut = checkOut;
}

DTReserva::~DTReserva(){
    //TODO? ¿Hay que delete checkin y checkout?
    /*al llamar al delete de una individual o grupal, llama su metodo
    virtual y luego se ejecuta este.*/
}

int  DTReserva::getCodigo(){
    return this->codigo;
}

DTFecha * DTReserva::getCheckIn(){
    return this->checkIn;
}

DTFecha * DTReserva::getCheckOut(){
    return this->checkOut;
}

EstadoReserva  DTReserva::getEstado(){
    return this->estado;
}

float  DTReserva::getCosto(){
    return this->costo;
}

int DTReserva::getHabitacion(){
    return this->habitacion;
}

DTReserva & DTReserva::operator= (const DTReserva &r){
    if (this != &r){
        /*delete checkIn;
        delete checkOut;*/
        checkIn = r.checkIn;
        checkOut = r.checkOut;
        checkIn = r.checkIn;
        checkOut = r.checkOut;
        codigo = r.codigo;
        estado = r.estado;
        costo = r.costo;
        habitacion = r.habitacion;
    }
    return *this;
}

bool operator== (const DTReserva &r1, const DTReserva &r2){
    return r1.codigo == r2.codigo;    
}

void DTReserva::imprimirReserva(){
}
