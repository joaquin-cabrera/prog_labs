#include "../../include/Classes/controladorHostal.h"

controladorHostal* controladorHostal::instancia = NULL;

controladorHostal::controladorHostal() {
    instancia = this;
    this->dthostal = NULL;
}

controladorHostal* controladorHostal::getInstance(){
    if (instancia == NULL){
        instancia = new controladorHostal();
    }
    return instancia;
}


bool controladorHostal::hostalEnSistema(string nombre){
    return hostales[nombre] != NULL;
}

void controladorHostal::ingresarHostal(string nombre, string direccion, string telefono){
    if( !hostalEnSistema(nombre)){
        hostales[nombre] = new Hostal(nombre, direccion, telefono);
    } else {
        //lanzarExepcion
    }
}

void controladorHostal::imprimirHostales(){
    map<string, Hostal*>::iterator it;
    for(it = hostales.begin(); it != hostales.end(); ++it){
        it->second->imprimirHostal();
        cout << endl;
    }
}

vector<DTHostal*> controladorHostal::listarHostales(){
    vector<DTHostal*> a = {};
    for (auto h:hostales){
        a.push_back(h.second->getDT());
    }
    return a;
}

void controladorHostal::datosHabitacion(std::string numero, float precio,int capacidad, DTHostal* h){
    this->numero = numero;
    this->capacidad = capacidad;
    this->precio = precio;
    this->dthostal = new DTHostal(h->getNombre(),h->getDireccion(),h->getTelefono());
}

void controladorHostal::agregarHabitacion(){
    Hostal* hostal = hostales.at(dthostal->getNombre());
    Habitacion* hab = new Habitacion(numero,precio,capacidad,hostal);
    hostal->vincularHabitacion(hab);
    delete dthostal;
}

void controladorHostal::cancelarOperacion(){
    delete dthostal;
}

Hostal* controladorHostal::getHostal(string nombre){
    return hostales[nombre];
}

vector<DTHabitacion*> controladorHostal::listarHabDisponibles(DTFecha* checkIn, DTFecha* checkOut, string hostal){
    vector<DTHabitacion*> habDisponibles;
    vector<Habitacion*>::iterator it;
    vector<Habitacion*> habitacionesHostal = this->hostales[hostal]->getHabitaciones();
    for(it = habitacionesHostal.begin() ; it != habitacionesHostal.end(); ++it){
        Habitacion *h = *it;
        if(h->habDisponible(checkIn, checkOut) ) {
            habDisponibles.push_back(h->getDt());
        }
    }
    
    return habDisponibles;
}

vector<string> controladorHostal::topHostales() {
    map<string, float> top;
    vector<string> resultado;
    for(map<string, Hostal*>::iterator i = hostales.begin(); i != hostales.end(); ++i)
        top.insert(pair<string, float>(i->first, i->second->getPromedio()));
    while(top.size() > 3) {
        string nombrehostal;
        float promedio = 6;
        for (map<string, float>::iterator i = top.begin(); i != top.end(); ++i)
            if (i->second < promedio) {
                promedio = i->second;
                nombrehostal = i->first;
            }
        top.erase(nombrehostal);
    }
    while(top.size() > 0) {
        string menor;
        float promedio = 6;
        for (map<string, float>::iterator i = top.begin(); i != top.end(); ++i)
            if (i->second < promedio) {
                promedio = i->second;
                menor = i->first;
            }
        resultado.push_back(menor);
        top.erase(menor);
    }
    return resultado;
}

void controladorHostal::detallesHostal(string hostal, vector<DTCalificacion>* calificaciones) {
    hostales[hostal]->getCalificaciones(calificaciones);
}

float controladorHostal::getPromedio(string hostal) {
    return hostales[hostal]->getPromedio();
}

void controladorHostal::obtenerHabitaciones(string hostal, vector<DTHabitacion>* habitaciones) {
    hostales[hostal]->getDTHabitaciones(habitaciones);
}


