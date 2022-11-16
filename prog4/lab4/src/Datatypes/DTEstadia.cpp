#include "../../include/Datatypes/DTEstadia.h"
DTEstadia::DTEstadia() {

}
DTEstadia::DTEstadia(DTFecha* llegada, int codigo, string email, string nombreHostal, string numhab){
    this->llegada = llegada;
    this->salida = NULL;
    this->codigoReserva = codigo;
    this->emailHuesped = email;
    this->nombreHostal = nombreHostal;
    this->numHab = numHab;
}

DTEstadia::DTEstadia(DTFecha* llegada, DTFecha* salida, int codigo, string email, string nombreHostal, string numhab){
    this->llegada = llegada;
    this->salida = salida;
    this->codigoReserva = codigo;
    this->emailHuesped = email;
    this->nombreHostal = nombreHostal;
    this->numHab = numHab;
}

void DTEstadia::imprimir(){

    cout << "| Hostal: " << nombreHostal << endl;
    cout << "| Huesped: "<< emailHuesped << endl;
    cout << "| Numero de habitacion: " << numHab << endl;
    cout << "| Llegada: ["; llegada->imprimirFecha();
    cout << "] Salida: [";
    if(salida == NULL){
        cout << "Salida sin finalizar.";
    } else {
        cout << "[";
        salida->imprimirFecha();
    }
    cout << "]" << endl;
    cout << "| Codigo reserva: " << this->codigoReserva; 

    
}   

void DTEstadia::imprimirBasic(){
    cout << " | Codigo reserva: " << this->codigoReserva;
    cout << " | Huesped: " << this->emailHuesped;
}

int DTEstadia::getCodigo(){
    return this->codigoReserva;
}

string DTEstadia::getEmail(){
    return emailHuesped;
}

DTFecha* DTEstadia::getSalida() {
    return salida;
}

