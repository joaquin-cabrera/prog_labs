#include "../../include/Datatypes/DTHuesped.h"

DTHuesped::DTHuesped(string nombre, string email, string password, bool esFinger) : DTUsuario(nombre, email, password){
    this->esFinger = esFinger;
}

DTHuesped::~DTHuesped(){
}

bool DTHuesped::getEsFinger(){ return this->esFinger; }

void DTHuesped::print(){
    cout << "Nombre: " << DTUsuario::getNombre() << endl;
    cout << "Email: " << DTUsuario::getEmail() << endl;
    cout << "Password: " << DTUsuario::getPassword() << endl;
    cout << "esFinger: " << getEsFinger() << endl;
}

void DTHuesped::imprimirBasic(){
    cout << "Nombre: " << getNombre() << " | Email: " << getEmail();
}