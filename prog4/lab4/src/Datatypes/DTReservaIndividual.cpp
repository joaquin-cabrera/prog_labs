#include "../../include/Datatypes/DTReservaIndividual.h"


DTReservaIndividual::DTReservaIndividual(int codigo,DTFecha* checkin,DTFecha* checkout ,EstadoReserva estado, string numHab): 
                    DTReserva(codigo,checkin,checkout,estado,numHab){}


void DTReservaIndividual::imprimir(){
    cout << "[Codigo: " << getCodigo(); 
    cout << " | Habitacion: " << getNumHabitacion();
    cout << " | Check in: "; getCheckIn()->imprimirFecha();
    cout << " | Check out: "; getCheckOut()->imprimirFecha();
    cout << " | Estado: "; imprimirEstado(); cout << "]";
    
}