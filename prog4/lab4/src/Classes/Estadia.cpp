#include "../../include/Classes/Estadia.h"

Estadia::Estadia() {

}

Estadia::Estadia(DTFecha* llegada, Huesped* hue, Reserva* res) {
    this->llegada = llegada;
    this->huesped = hue;
    this->reserva = res;
    this->salida = NULL;
}

Estadia::~Estadia() {
    delete llegada;
    delete salida;
    delete calificacion;
}

bool Estadia::esActiva(){ return salida == NULL; }
bool Estadia::esDeHuesped(string email){ return this->huesped->getEmail() == email; }
bool Estadia::estaEnHostal(string hostal){ return this->reserva->getNombreHostal() == hostal; }
int Estadia::getCodigoReserva(){ return this->reserva->getCodigo(); }

string Estadia::getHostal(){ return this->reserva->getNombreHostal(); }
string Estadia::getHuesped(){ return this->huesped->getEmail(); }

DTCalificacion Estadia::getDTCalificacion(){
    return calificacion->getDTCalificacion();
}

void Estadia::setSalida(DTFecha* salida){
    this->salida = salida;
}

bool Estadia::tieneCalificacion() {
    return calificacion != NULL;
}

DTEstadia* Estadia::getDT(){
    return new DTEstadia(this->llegada,this->salida,this->reserva->getCodigo(),this->huesped->getEmail(), this->reserva->getNombreHostal(), this->reserva->getNumHabitacion() );
}

void Estadia::comentarCalificacion(string respuesta) {
    calificacion->comentarCalificacion(respuesta);
}

void Estadia::modificar() {
    for(vector<Empleado*>::iterator i = empleados.begin(); i != empleados.end(); ++i) {
        (*i)->notificar(this);
    }
}

void Estadia::agregar(Empleado* empleado) {

}

void Estadia::eliminar() {

}