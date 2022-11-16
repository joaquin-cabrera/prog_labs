#include "../include/DTReservaIndividual.h"

DTReservaIndividual::DTReservaIndividual(int codigo,DTFecha *checkIn,DTFecha *checkOut,EstadoReserva estado, float costo, int habitacion,bool pagado)
                    :DTReserva(codigo, checkIn, checkOut, estado, costo, habitacion){
                        
    this->pagado = pagado;
}

DTReservaIndividual::~DTReservaIndividual(){
    //TODO?
    /*cuando llaman, se ejecuta este codigo y luego el destructor de DTReserva*/
}
bool DTReservaIndividual::getPagado(){
    return this->pagado;
}

ostream& operator<<(ostream& os, const DTReservaIndividual& r){
    os << "TipoReserva: Individual" << endl;
    os << "FechaCheckIn: "<< r.checkIn->getDia() <<"/"<<r.checkIn->getMes()<< "/"<<r.checkIn->getAnio() << endl;
    os << "FechaCheckOut: "<< r.checkOut->getDia() <<"/"<<r.checkOut->getMes()<< "/"<<r.checkOut->getAnio() << endl;
    os << "Habitacion: "<< r.habitacion << endl;
    os << "Costo: $"<<r.costo<< endl;
    os << "Pagado: ";
    if (r.pagado){
        os << "Si"<< endl;
    }else{
        os << "No" << endl;
    }
    return os;
}


void DTReservaIndividual::imprimirReserva(){
    cout << "[Reserva Individual]" << endl;
    cout << "codigo: " << this->getCodigo() << endl;
    cout << "costo: " << this->getCosto() << endl;
    cout << "habitacion: " << this->getHabitacion() << endl;
    cout << "fecha de check-in: ";
    this->getCheckIn()->imprimirFecha();
    cout << "fecha de check-out: ";
    this->getCheckOut()->imprimirFecha();
    if(pagado){
        cout << "pagado: true" << endl;
    } else {
        cout << "pagado: false" << endl;
    }
}

bool DTReservaIndividual::esIndividual(){
    return true;
}