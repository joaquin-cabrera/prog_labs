#include "../include/Huesped.h"

Huesped::Huesped(){
    nombre = "0";
    email = "0";
    esFinger = false;
}

Huesped::Huesped(string nombre, string email, bool esFinger){
    this->nombre = nombre;
    this->email = email;
    this->esFinger = esFinger;
}

string Huesped::getNombre(){
    return nombre;
}

string Huesped::getEmail(){
    return email;
}

bool Huesped::getEsFinger(){ 
    return esFinger; 
}

void Huesped::imprimirHuesped(){
    cout << "\n";
   // cout << " Nombre: " << nombre << endl;
    cout << " Email: " << email << "\n";
  //  cout << " EsFinger: " << esFinger << "\n";
  //cout << "------------------------------\n";
  cout << endl;
}