#include "../../include/Datatypes/DTEmpleado.h"

DTEmpleado::DTEmpleado(string nombre, string email, string password, Cargo cargo) : DTUsuario(nombre, email, password){
    this->cargo = cargo;
}

DTEmpleado::~DTEmpleado(){
}

Cargo DTEmpleado::getCargo(){
    return this->cargo;
}

void DTEmpleado::print(){
    cout << "Nombre: " << DTUsuario::getNombre() << endl;
    cout << "Email: " << DTUsuario::getEmail() << endl;
    cout << "Password: " << DTUsuario::getPassword() << endl;
    cout << "Cargo: ";
    if(getCargo() == Cargo::Administracion){
        cout << "Administracion" << endl;
    }else if(getCargo() == Cargo::Limpieza){
        cout << "Limpieza" << endl;
    }else{
        cout << "Recepcion" << endl;
    }
}