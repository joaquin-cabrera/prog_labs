#include "../../include/Classes/Empleado.h"


Empleado::Empleado(string nombre, string email, string password, Cargo cargo) : Usuario(nombre, email, password){
    this->cargo = cargo;
    this->trabajo = NULL;
}

DTUsuario* Empleado::getDT(){
    DTUsuario * u = new DTEmpleado(getNombre(),getEmail(),getPassword(),getCargo());
    return u;
}

Cargo Empleado::getCargo(){
    return cargo;
}

void Empleado::setCargo(Cargo cargo){
    this->cargo = cargo;
}

void Empleado::vincularHostal(Hostal *hostal){
    trabajo = hostal;
}

string Empleado::trabajaEn() {
    if (tieneTrabajo())
        return trabajo->getNombre();
    else
        return "No tiene hostal";  
}

bool Empleado::tieneTrabajo() {
    return trabajo != NULL;
}

void Empleado::notificar(Estadia* estadia) {
    notificaciones.push_back(estadia);
}