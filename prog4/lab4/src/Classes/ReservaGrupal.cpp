#include "../../include/Classes/ReservaGrupal.h"

ReservaGrupal::ReservaGrupal(int codigo,DTFecha* checkIn, DTFecha* checkOut, Huesped* hue, Habitacion* hab, map<string, Huesped*> listaHospedados) : 
                Reserva(codigo, checkIn, checkOut,hue,hab,listaHospedados){

    this->cantHospedados = listaHospedados.size();  
}

ReservaGrupal::~ReservaGrupal(){
    vector<Estadia*>::iterator it;
    for(it = estadias.begin(); it != estadias.end(); ++it){
        delete (*it);
    }
}

void ReservaGrupal::imprimirReserva(){
    cout << "codigo: " << this->getCodigo() << endl;
    cout << "check in: "; getCheckIn()->imprimirFecha(); cout << endl;
    cout << "check out: "; getCheckOut()->imprimirFecha(); cout << endl;
}

DTReserva* ReservaGrupal::getDT(){
    DTReservaGrupal* r = new DTReservaGrupal(getCodigo(),getCheckIn(),getCheckOut(),getEstadoReserva(),getNumHabitacion());
    return r;
}

void ReservaGrupal::getCalificaciones(vector<DTCalificacion>* calificaciones) {
    if(getEstadia() != NULL)
        calificaciones->push_back(getEstadia()->getDTCalificacion());
    for(vector<Estadia*>::iterator i = estadias.begin(); i != estadias.end(); ++i) {
        if((*i)->tieneCalificacion()) {
            DTCalificacion c = (*i)->getDTCalificacion();
            c.setCodigoReserva(this->getCodigo());
            calificaciones->push_back(c);
        }
    }
}

void ReservaGrupal::agregarEstadia(Estadia* est){
    this->estadias.push_back(est);
}

void ReservaGrupal::comentarCalificacion(string respuesta, string comentario) {
    for (vector<Estadia*>::iterator i = estadias.begin(); i != estadias.end(); ++i) {
        if (((*i)->tieneCalificacion()) && ((*i)->getDTCalificacion().getComentario() == comentario))
            (*i)->comentarCalificacion(respuesta);
    }
}