#include "../include/Sistema.h"
#include <iostream>
#include <string>

#define MAX_HUESPEDES 100
#define MAX_HABITACIONES 100
#define MAX_RESERVAS 100

//revisar si esta bien
Sistema::Sistema(){
    this->huespedes = new Huesped*[MAX_HUESPEDES];
    this->habitaciones = new Habitacion*[MAX_HABITACIONES];
    this->reservas = new Reserva*[MAX_RESERVAS];
    this->cantHuespedes = 0;
    this->cantHabitaciones = 0;
    this->cantReservas = 0;
    for(int i = 0; i < MAX_HUESPEDES; i++){
        this->huespedes[i] = NULL;
    }
    for(int i = 0; i < MAX_HABITACIONES; i++){
        this->habitaciones[i] = NULL;
    }
    for(int i = 0; i < MAX_RESERVAS; i++){
        this->reservas[i] = NULL;
    }
}

Sistema::~Sistema(){
    delete [] huespedes;
    delete [] habitaciones;
    delete [] reservas;
}

//chequea si el huesped esta registrado
//REVISAR
int Sistema::huespedRegistrado(string email){
     int i = 0, res = -1;
     while( (i <= cantHuespedes - 1) && (res == -1) ){
         if(huespedes[i]->getEmail() == email){
            res = i;
         }
         i++;
     }
     return res;
}
//chequea si la habitacion ya existe
//REVISAR
int Sistema::habitacionRegistrada(int numero){
    int i = 0, res = -1;
    while( (i <= cantHabitaciones - 1) && (res == -1) ){
        if(habitaciones[i]->getNumero() == numero){
            res = i;
        }
        i++;
    }
    return res;
}

void Sistema::agregarHuesped(string nombre, string email, bool esFinger){
    if(huespedRegistrado(email) != -1){
        throw invalid_argument("El huesped ya esta registrado");
    } else {
        cantHuespedes++;
        huespedes[cantHuespedes - 1] = new Huesped(nombre, email, esFinger);
    }
}
void Sistema::agregarHabitacion(int numero, float precio, int capacidad){

    if(habitacionRegistrada(numero) != -1){
        throw invalid_argument("La habitacion ya esta registrada");
    } else {
        cantHabitaciones++;
        habitaciones[cantHabitaciones - 1] = new Habitacion(numero, precio, capacidad);
    }
}



void Sistema::registrarReserva(string email, DTReserva *reserva){

    //chequea si el huesped y la habitacion estan registrados
    int posHuesped = huespedRegistrado(email);
    int posHabitacion = habitacionRegistrada(reserva->getHabitacion());
    //datos de la reserva
    int codigo = reserva->getCodigo();
    DTFecha *checkIn = reserva->getCheckIn();
    DTFecha *checkOut = reserva->getCheckOut();
    EstadoReserva estado = reserva->getEstado();

    if(posHuesped == -1){
        throw invalid_argument("Huesped no registrado.");
    } else if (posHabitacion == -1){
        throw invalid_argument("Habitacion no registrada.");
    } else {
        cantReservas++;
        if(reserva->esIndividual()){
            //DYNAMIC CAST
            DTReservaIndividual *paux = dynamic_cast<DTReservaIndividual*>(reserva);
            reservas[cantReservas - 1] = new ReservaIndividual(codigo, checkIn, checkOut, estado, habitaciones[posHabitacion], huespedes[posHuesped], paux->getPagado());
        }else{
            //DYNAMIC CAST
            DTReservaGrupal *ptr = dynamic_cast<DTReservaGrupal*>(reserva);
            int cantHuespedes = ptr->getCantidad_huespedes();
            //creo un arreglo de Huesped con los DTHuesped de reserva para pasarle a ReservaGrupal
            Huesped** auxptr = new Huesped*[ptr->getCantidad_huespedes()];
            for(int i = 0; i <= ptr->getCantidad_huespedes() - 1; i++){
                auxptr[i] = new Huesped(ptr->getHuespedes()[i]->getNombre(), ptr->getHuespedes()[i]->getEmail(), ptr->getHuespedes()[i]->getEsFinger());
            }
            reservas[cantReservas - 1] = new ReservaGrupal(codigo, checkIn, checkOut, estado, habitaciones[posHuesped], huespedes[posHabitacion], auxptr, cantHuespedes);
        }
    }

}

//REVISAR
DTHuesped** Sistema::obtenerHuespedes(int& cantHuespedes){
    DTHuesped **res = new DTHuesped*[this->cantHuespedes];
    cantHuespedes = this->cantHuespedes;
    for(int i = 0; i <= (this->cantHuespedes - 1); i++){
        string nombre = huespedes[i]->getNombre();
        string email = huespedes[i]->getEmail();
        bool esFinger = huespedes[i]->getEsFinger();
        res[i] = new DTHuesped( nombre, email, esFinger ); 

    }

    return res;
}

//REVISAR
DTHabitacion** Sistema::obtenerHabitaciones(int& cantHabitaciones){
    DTHabitacion** res = new DTHabitacion*[this->cantHabitaciones];
    cantHabitaciones = this->cantHabitaciones;
    for(int i = 0; i <= (this->cantHabitaciones - 1); i++){
        int numero = habitaciones[i]->getNumero();
        int capacidad = habitaciones[i]->getCapacidad();
        int precio = habitaciones[i]->getPrecio();
        res[i] = new DTHabitacion(numero, precio, capacidad);
    }
    return res;
}


DTReserva** Sistema::obtenerReservas(DTFecha fecha, int& cantReservas){
    int resSize = 0, j = 0;
    cantReservas = this->cantReservas;

    for(int i = 0; i<=(this->cantReservas - 1); i++){
        if(*reservas[i]->getCheckIn() == fecha){
            resSize++;
        }
    }
    cantReservas = resSize;
    DTReserva** res = new DTReserva*[resSize];


    for(int i = 0; i < this->cantReservas; i++){
        if(*reservas[i]->getCheckIn() == fecha){
            //obtengo los datos de la reserva
            int codigo = reservas[i]->getCodigo();
            DTFecha *checkin = reservas[i]->getCheckIn();
            DTFecha *checkout = reservas[i]->getCheckOut();
            EstadoReserva estado = reservas[i]->getEstado();
            int habitacion = reservas[i]->getHabitacion()->getNumero();
            float costo = reservas[i]->calcularCosto();

            if(reservas[i]->esIndividual()){
                ReservaIndividual *paux = dynamic_cast<ReservaIndividual*>(reservas[i]);
                res[j] = new DTReservaIndividual(codigo,checkin,checkout,estado,costo,habitacion,paux->getPagado());
            } else {
                ReservaGrupal *paux = dynamic_cast<ReservaGrupal*>(reservas[i]);
                Huesped**arrayhuespedes = paux->getHuespedes();
                
                DTHuesped**dthuespedes = new DTHuesped*[paux->getCantHuespedes()];

                for(int i = 0; i < paux->getCantHuespedes(); i++){
                    dthuespedes[i] = new DTHuesped(arrayhuespedes[i]->getNombre(),arrayhuespedes[i]->getEmail(), arrayhuespedes[i]->getEsFinger());
                }
                res[j] = new DTReservaGrupal(codigo,checkin,checkout,estado,costo,habitacion,dthuespedes,paux->getCantHuespedes());

            }
            j++;

        }
    }



    
    // for(int i = 0; i<=(this->cantReservas-1); i++){


        
        
    //     if(reservas[i]->getCheckIn() == pfecha){
        
    //         if(reservas[i]->esIndividual()){
    //             ReservaIndividual *paux = dynamic_cast<ReservaIndividual*>(reservas[i]);
    //             res[j] = new DTReservaIndividual(codigo,checkin,checkout,estado,costo,habitacion,paux->getPagado());
    //         } else {
    //             ReservaGrupal *paux = dynamic_cast<ReservaGrupal*>(reservas[i]);
    //             Huesped**arrayhuespedes = paux->getHuespedes();
    //             int cantHuespedes = paux->getCantHuespedes();
                
    //             DTHuesped**dthuespedes = NULL;
    //             tengo que crear este arreglo de DTHuesped porque no le puedo pasar un arreglo de Huesped a un DTReservagrupal
    //             for(int i = 0; i <= cantHuespedes-1; i++){
    //                 dthuespedes[i] = new DTHuesped(arrayhuespedes[i]->getNombre(),arrayhuespedes[i]->getEmail(), arrayhuespedes[i]->getEsFinger());
    //             }

    //             res[j] = new DTReservaGrupal(codigo,checkin,checkout,estado,costo,habitacion,dthuespedes,cantHuespedes);
    //         }

    //         j++;
    //     }
    // }
    	return res; 
}


DTHuesped** Sistema::listaHuespedes(string* emails, int cantidad_huespedes){
	DTHuesped** resultado = new DTHuesped*[MAX_HUESPEDES];
	for(int j = 0; j <= cantidad_huespedes; j++)
		for(int i = 0; i <= cantHuespedes - 1; i++){
			if (this->huespedes[i]->getEmail() == emails[j]){
				DTHuesped* huesped = new DTHuesped(huespedes[i]->getNombre(), huespedes[i]->getEmail(), huespedes[i]->getEsFinger());
				resultado[j] = huesped;
			}
	}
    return resultado;
}



void Sistema::imprimirHuespedes(){
    cout<<"############ HUESPEDES ############\n";
    for(int i = 0; i <= cantHuespedes - 1; i++){
        this->huespedes[i]->imprimirHuesped();
    }
    cout << "-----------------------------------\n";
}
void Sistema::imprimirHabitaciones(){
    cout << "######## HABITACIONES ########\n";
    for(int i = 0; i <= cantHabitaciones - 1; i++){
        this->habitaciones[i]->imprimirHabitacion();
    }
    cout << "-----------------------------------\n";
}
void Sistema::imprimirReservas(){
    cout << "########## RESERVAS ##########\n";
    for(int i = 0; i <= cantReservas - 1; i++){
        this->reservas[i]->imprimirReserva();
    }
    cout << endl;
    cout << "-----------------------------------\n";
}


int Sistema::getCantHabitaciones(){
    return cantHabitaciones;
}
int Sistema::getCantHuespedes(){
    return cantHuespedes;
}
int Sistema::getCantReservas(){
    return  cantReservas;
}

Huesped** Sistema::getHuespedes(){
    return huespedes;
}
Habitacion** Sistema::getHabitaciones(){
    return habitaciones;
}
Reserva** Sistema::getReservas(){
    return reservas;
}