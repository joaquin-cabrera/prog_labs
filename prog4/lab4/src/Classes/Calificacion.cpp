#include "../../include/Classes/Calificacion.h"

Calificacion::Calificacion() {

}

Calificacion::Calificacion(int puntaje, std::string comentario, DTFecha* fecha) {
    this->puntaje = puntaje;
    this->comentario = comentario;
    this->fecha = fecha;
    respuesta = NULL;
}

Calificacion::~Calificacion() {
    delete fecha;  
}

int Calificacion::getPuntaje() {
    return puntaje;
}

DTFecha* Calificacion::getFecha() {
    return fecha;
}

std::string Calificacion::getComentario() {
    return comentario;
}

bool Calificacion::tieneComentario() {
    return (respuesta != NULL);
}

DTCalificacion Calificacion::getDTCalificacion() {
    return DTCalificacion(this->getPuntaje(), this->getFecha(), this->getComentario(), this->tieneComentario());
}

void Calificacion::comentarCalificacion(string respuesta) {
    this->respuesta = new Comentario(respuesta);
}
