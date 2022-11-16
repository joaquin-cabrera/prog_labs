#include "../include/DTFecha.h"

DTFecha::DTFecha(){
    this->dia = this->mes = this->anio = 0;
}

DTFecha::DTFecha(int dia, int mes, int anio){
    if (dia>31 || dia<1){
        throw invalid_argument("El parametro 'dia' debe cumplir: 1<='dia'<=31.");
    }else if (mes>12 || mes <1){
        throw invalid_argument("El parametro 'mes' debe cumplir: 1<='mes'<=12.");
    }else if (anio<1900){
        throw invalid_argument("El parametro 'anio' debe cumplir: 1901<=anio.");
    }else{
        this->dia = dia;
        this->mes = mes;
        this->anio = anio;
    }
}

int DTFecha::getDia(){
    return this->dia;
}
int DTFecha::getMes(){
    return this->mes;
}
int DTFecha::getAnio(){
    return this->anio;
}

int DTFecha::cantidadDias(const DTFecha &f){
    int mayor, menor;
    mayor = (372*this->getAnio()-1) + (31*this->getMes()-1) + (this->getDia());
    menor = (372* f.anio-1) + (31* f.mes-1) + (f.dia);
    int resultado;
    resultado = mayor-menor;
    if (resultado < 0)
        resultado = -1*resultado;
    return resultado;       
}

DTFecha & DTFecha::operator= (const DTFecha &f){
    this->mes = f.mes;
    this->anio = f.anio;
    this->dia = f.dia;
    return *this;
}

bool operator== (const DTFecha &f1, const DTFecha &f2){
    return (f1.dia == f2.dia) && (f1.mes == f2.mes) && (f1.anio == f2.anio);
}

void DTFecha::imprimirFecha(){
    cout << dia << "/" << mes << "/" << anio << endl;
}

