#include "../../include/Classes/Usuario.h"

Usuario::Usuario(){
    this->nombre = "";
    this->email = "";
    this->password = "";
}

Usuario::Usuario(string nombre, string email, string password){
    this->nombre = nombre;
    this->email = email;
    this->password = password;
}

string Usuario::getNombre(){
    return nombre;
}

string Usuario::getEmail(){
    return email;
}

string Usuario::getPassword(){
    return password;
}

DTUsuario* Usuario::getDT(){
    return {};
}