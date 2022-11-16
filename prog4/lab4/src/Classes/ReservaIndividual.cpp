#include "../../include/Classes/ReservaIndividual.h"

ReservaIndividual::ReservaIndividual(int codigo, DTFecha* checkIn, DTFecha* checkOut, Huesped* hue, Habitacion* hab, map<string,Huesped*> listaHospedados):
                    Reserva(codigo, checkIn, checkOut, hue, hab, listaHospedados){

}

ReservaIndividual::~ReservaIndividual(){

}

void ReservaIndividual::imprimirReserva(){
    cout << "Codigo: " << this->getCodigo() << endl;
    cout << "Check In: "; getCheckIn()->imprimirFecha();
    cout << "Check Out: "; getCheckOut()->imprimirFecha();
    cout << "Tipo: Individual";
}


DTReserva* ReservaIndividual::getDT(){
    return new DTReservaIndividual(getCodigo(),getCheckIn(),getCheckOut(),getEstadoReserva(),getNumHabitacion());
}

void ReservaIndividual::getCalificaciones(vector<DTCalificacion>* calificaciones) {
    if(getEstadia() != NULL) {
        DTCalificacion c = getEstadia()->getDTCalificacion();
        c.setCodigoReserva(this->getCodigo());
        calificaciones->push_back(c);
    }   
}

void ReservaIndividual::comentarCalificacion(string respuesta, string comentario) {
    this->getEstadia()->comentarCalificacion(respuesta);
}