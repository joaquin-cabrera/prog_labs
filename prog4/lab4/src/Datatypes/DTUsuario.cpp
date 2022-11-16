#include "../../include/Datatypes/DTUsuario.h"

DTUsuario::DTUsuario(){
    this->nombre = "";
    this->email = "";
    this->password = "";
}

DTUsuario::DTUsuario(string nombre, string email, string password){
    this->nombre = nombre;
    this->email = email;
    this->password = password;
}

DTUsuario::~DTUsuario(){
}

string DTUsuario::getNombre(){
    return this->nombre;
}
string DTUsuario::getEmail(){
    return this->email;
}
string DTUsuario::getPassword(){
    return this->password;
}

void DTUsuario::print(){
}


void DTUsuario::setEmail(string email) { this->email = email; }
void DTUsuario::setNombre(string nombre){ this->nombre = nombre; }
void DTUsuario::setPassword(string password){this->password = password; }