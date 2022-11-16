#include "../../include/Datatypes/DTFecha.h"


DTFecha::DTFecha(int dia, int mes, int anio, int hora){
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    this->hora = hora;
}

DTFecha::~DTFecha(){};

int DTFecha::getAnio(){ return this->anio; }
int DTFecha::getMes(){ return this->mes; }
int DTFecha::getDia(){ return this->dia; }
int DTFecha::getHora(){ return this->hora; }

bool DTFecha::fechaMenor(DTFecha* date){

    bool menor = false;

    if( this->anio == date->getAnio()){

        if( this->mes == date->getMes() ){

            if( this->dia == date->getDia() ){

                menor = date->getHora() < this->hora;
                
            } else {
                menor = date->getDia() < this->dia;
            }
        } else {
            menor = date->getMes() < this->mes;
        }
    } else {
        menor = date->getAnio() < this->anio;    
    }
    

    return menor;
}

bool DTFecha::fechasIguales(DTFecha* date){
    return( 
            this->anio == date->getAnio() && 
            this->mes == date->getMes() && 
            this->dia == date->getDia() && 
            this->hora == date->getHora()) ;
}

bool DTFecha::fechaMayor(DTFecha* date){

    bool mayor = false;

    if( this->anio == date->getAnio()){

        if( this->mes == date->getMes() ){

            if( this->dia == date->getDia() ){

                mayor = date->getHora() > this->hora;
                
            } else {
                mayor = date->getDia() > this->dia;
            }
        } else {
            mayor = date->getMes() > this->mes;
        }
    } else {
        mayor = date->getAnio() > this->anio;    
    }
    

    return mayor;
}


void DTFecha::imprimirFecha(){
    cout << dia << "/" << mes << "/" << anio << ", " << hora << "hs";
}