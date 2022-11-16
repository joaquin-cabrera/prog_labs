#include "../../include/Classes/Hostal.h"


Hostal::Hostal(string nombre, string direccion, string telefono){
    this->nombre = nombre;
    this->direccion = direccion;
    this->telefono = telefono;
    habitaciones = {};
}
string Hostal::getNombre() {  
    return this->nombre; 
}

string Hostal::getTelefono(){ return this->telefono; }
string Hostal::getDireccion(){ return this->direccion; }


void Hostal::imprimirHostal(){
    cout << " Nombre: " << this->nombre << endl;
    cout << " Direccion: " << this->direccion << endl;
    cout << " Telefono: " << this->telefono << endl;
}

DTHostal* Hostal::getDT(){
    DTHostal* dt = new DTHostal(this->nombre, this->direccion, this->telefono);
    return dt;
}

void Hostal::vincularHabitacion(Habitacion* hab){
    habitaciones.push_back(hab);  
}

vector<Habitacion*> Hostal::getHabitaciones(){
    return this->habitaciones;
} 

Habitacion* Hostal::getHabitacion(string numHab){
    vector<Habitacion*>::iterator it = habitaciones.begin();
    Habitacion* h = NULL;
    bool encontro = false;
    while(it != habitaciones.end() && !encontro){
        h = *it;
        if(h->getNumero() == numHab){
            encontro = true;
        }
        ++it;
    }
    return h;
}

void Hostal::getCalificaciones(vector<DTCalificacion>* calificaciones) {
    if(!habitaciones.empty())
        for(vector<Habitacion*>::iterator i = habitaciones.begin(); i != habitaciones.end(); ++i)
            (*i)->getCalificaciones(calificaciones);
}

float Hostal::getPromedio() {
    float resultado = 0;
    float dividir = 1;
    vector<DTCalificacion>* calificaciones = new vector<DTCalificacion>;
    getCalificaciones(calificaciones);
    for (vector<DTCalificacion>::iterator i = calificaciones->begin(); i != calificaciones->end(); ++i) {
        resultado += i->getPuntaje();
        dividir++;
    }
    delete calificaciones;
    return resultado/dividir;
}

void Hostal::getDTHabitaciones(vector<DTHabitacion>* h) {
    if (!habitaciones.empty())
        for (vector<Habitacion*>::iterator i = habitaciones.begin(); i != habitaciones.end(); ++i)
            h->push_back((*i)->getDTHabitacion());     
}