#include "../include/ReservaGrupal.h"

ReservaGrupal::ReservaGrupal(): Reserva(){
    cantidadHuespedes = 0;
    huespedes = NULL;
}

ReservaGrupal::ReservaGrupal(int codigo, DTFecha *checkIn, DTFecha *checkOut, EstadoReserva estado, Habitacion *habitacion, Huesped *huesped, Huesped**huespedes, int cantidadHuespedes): Reserva(codigo, checkIn, checkOut, estado, habitacion, huesped){
    this->cantidadHuespedes = cantidadHuespedes;
    this->huespedes = huespedes;
}

ReservaGrupal::~ReservaGrupal(){ 
  for (int i = 0; i< cantidadHuespedes ;i++){
    delete huespedes[i];
  }
  delete [] huespedes;
}


float ReservaGrupal::calcularCosto(){
    float resultado = ((getCheckIn()->cantidadDias(*getCheckOut()))*getHabitacion()->getPrecio())*cantidadHuespedes;
    int fingers = 0;
    for (int i=0; i<cantidadHuespedes; i++){
      if (huespedes[i]->getEsFinger())
        fingers++;
    };

    if (fingers < 2)
      return resultado;
    else
      return resultado-resultado*0.3;
}

bool ReservaGrupal::esIndividual(){
  return false;
}


void ReservaGrupal::imprimirReserva(){
  cout << "---------------------------------" << endl;
  cout << "TipoReserva: Grupal\n";
  cout << "Huespedes: \n";
  for(int i = 0; i <= cantidadHuespedes-1; i++){
    huespedes[i]->imprimirHuesped();
  }
  cout << "---------------------------------" << endl;
  cout << "Fecha Check in: "; getCheckIn()->imprimirFecha();
  cout << "Fecha Check Out: "; getCheckOut()->imprimirFecha();
  cout << "Costo: $" << calcularCosto();
  cout << endl;
}

Huesped** ReservaGrupal::getHuespedes(){
  return huespedes;
}
int ReservaGrupal::getCantHuespedes(){
  return cantidadHuespedes;
}