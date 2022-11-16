#include "../../include/Classes/FechaSistema.h"

FechaSistema* FechaSistema::instancia = NULL;
FechaSistema::FechaSistema(){
    instancia = this;
}
FechaSistema* FechaSistema::getInstance(){
    if( instancia == NULL){
        instancia = new FechaSistema();
    } 
    return instancia;
}

void FechaSistema::modificarFecha(DTFecha* fechaNueva){
    this->fecha = fechaNueva;
}

DTFecha* FechaSistema::getDT(){
    return this->fecha;
}