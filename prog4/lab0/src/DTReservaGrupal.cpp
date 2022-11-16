#include "../include/DTReservaGrupal.h"


DTReservaGrupal::DTReservaGrupal(int codigo, DTFecha *checkIn, DTFecha *checkOut, EstadoReserva estado, float costo, int habitacion, DTHuesped ** huespedes, int cantidad_huespedes)
                :DTReserva(codigo, checkIn, checkOut, estado, costo, habitacion){
    this->huespedes = huespedes;
    this->cantidad_huespedes = cantidad_huespedes;
}

DTReservaGrupal::~DTReservaGrupal(){
    //delete huespedes;
}

DTHuesped * * DTReservaGrupal::getHuespedes(){
    return this->huespedes;
}

int DTReservaGrupal::getCantidad_huespedes(){
    return this->cantidad_huespedes;
}

ostream& operator<<(ostream& os, const DTReservaGrupal& r){
    os << "TipoReserva: Grupal" << endl;
    os << "FechaCheckIn: "<< r.checkIn->getDia() <<"/"<<r.checkIn->getMes()<< "/"<<r.checkIn->getAnio() << endl;
    os << "FechaCheckOut: "<< r.checkOut->getDia() <<"/"<<r.checkOut->getMes()<< "/"<<r.checkOut->getAnio() << endl;
    os << "Habitacion: "<< r.habitacion << endl;
    os << "Costo: $"<<r.costo<< endl;
    os << "Huespedes: ";
    for (int i = 0; i<r.cantidad_huespedes;i++){
        os << r.huespedes[i]->getNombre() << "-"<<r.huespedes[i]->getEmail() << "-" ;
        if (r.huespedes[i]->getEsFinger()){
            os << "Pagado" << endl;
        }else{
            os << "No pagado" << endl;
        }
    }
    return os;
}

void DTReservaGrupal::imprimirReserva(){
    cout << "[Reserva grupal]" << endl;
    cout << "Codigo: " << this->getCodigo() << endl;
    cout << "Costo: " << this->getCosto() << endl;
    cout << "Habitacion: " << this->getHabitacion() << endl;
    cout << "Fecha de check-in: ";
    this->getCheckIn()->imprimirFecha();
    cout << "Fecha de check-out: ";
    this->getCheckOut()->imprimirFecha();
    cout << "Cantidad de huespedes: " << this->getCantidad_huespedes() << endl;
    cout << "Listado de huespedes: " << endl;
    for (int i=0; i<cantidad_huespedes; i++){
        cout << "Huesped #"<<i << endl;
        huespedes[i]->imprimirHuesped();
    }
    cout << "[Fin reserva grupal]" << endl;
}

bool DTReservaGrupal::esIndividual(){
    return false;
}