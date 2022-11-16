#include "../../include/Classes/Huesped.h"

Huesped::Huesped(string nombre, string email, string password, bool esFinger) : Usuario(nombre, email, password){
    this->esFinger = esFinger;
}

DTUsuario* Huesped::getDT(){
    DTUsuario * u = new DTHuesped(getNombre(), getEmail(), getPassword(), getEsFinger());
    return u;
}

bool Huesped::getEsFinger(){
    return esFinger;
}