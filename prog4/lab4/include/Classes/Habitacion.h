#ifndef HABITACION_H
#define HABITACION_H

#include "Reserva.h"
#include "../Datatypes/DTFecha.h"
#include "../Datatypes/DTHabitacion.h"
#include "../Datatypes/DTCalificacion.h"  


#include <string>
#include <map>
#include <vector>

//forward declaration
class controladorHostal;
class Hostal;
class Reserva;

using namespace std;

class Habitacion{
  private:
    std::string numero;
    float precio;
    int capacidad;
    Hostal* hostal;
    map<int,Reserva*> reservas;
  public:
    Habitacion();
    Habitacion(string, float, int, Hostal*);
    string getNumero();
    float getPrecio();
    int getCapacidad();
    bool habDisponible(DTFecha*, DTFecha*);
    DTHabitacion* getDt();
    string getNombreHostal();
    void agregarRes(Reserva*);
    void getCalificaciones(vector<DTCalificacion>* calificaciones);
    void cerrarReseva(int codigo);
    DTHabitacion getDTHabitacion();
};


#endif
