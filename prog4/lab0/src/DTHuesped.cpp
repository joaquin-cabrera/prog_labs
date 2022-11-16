#include "../include/DTHuesped.h"

DTHuesped::DTHuesped(string nombre, string email, bool esFinger){
    this->nombre = nombre;
    this->email = email;
    this->esFinger = esFinger;
}

string DTHuesped::getNombre(){
    return this->nombre;
}
string DTHuesped::getEmail(){
    return this->email;
}
bool DTHuesped::getEsFinger(){
    return this->esFinger;
}
DTHuesped & DTHuesped::operator= (const DTHuesped &h){
    this->nombre = h.nombre;
    this->email = h.email;
    this->esFinger = h.esFinger;
    return *this;
}

bool operator == (const DTHuesped &h1, const DTHuesped &h2){
    return (h1.email == h2.email);
}

void DTHuesped::imprimirHuesped(){
    cout << "Nombre: " << nombre << endl;
    cout << "Email: " << email << endl;
    cout << "EsFinger: " << esFinger << endl;
}