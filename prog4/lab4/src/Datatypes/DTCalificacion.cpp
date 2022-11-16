#include "../../include/Datatypes/DTCalificacion.h"

DTCalificacion::DTCalificacion(int puntaje, DTFecha* fecha, std::string comentario, bool comentado) {
    this->comentario = comentario;
    this->puntaje = puntaje;
    this->fecha = fecha;
    this->comentado = comentado;
    this->codigoreserva = 0;
}

DTCalificacion::DTCalificacion(int puntaje, DTFecha* fecha, std::string comentario, bool comentado, int codigoreserva) {
    this->comentario = comentario;
    this->puntaje = puntaje;
    this->fecha = fecha;
    this->comentado = comentado;
    this->codigoreserva = codigoreserva;
}

DTCalificacion::~DTCalificacion(){
    delete fecha;
}

int DTCalificacion::getPuntaje() {
    return puntaje;
}

DTFecha* DTCalificacion::getFecha() {
    return fecha;
}

std::string DTCalificacion::getComentario() {
    return comentario;
}

bool DTCalificacion::getComentado() {
    return comentado;
}

void DTCalificacion::setCodigoReserva(int codigo) {
    this->codigoreserva = codigo;
}

int DTCalificacion::getCodigoReserva() {
    return codigoreserva;
}