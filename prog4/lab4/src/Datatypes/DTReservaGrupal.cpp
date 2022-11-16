#include "../../include/Datatypes/DTReservaGrupal.h"


DTReservaGrupal::DTReservaGrupal(int codigo,DTFecha* checkin,DTFecha* checkout ,EstadoReserva estado, string numHab): 
                    DTReserva(codigo,checkin,checkout,estado,numHab){

}
                    
void DTReservaGrupal::imprimir(){
    cout << "[Codigo: " << getCodigo(); 
    cout << " | Habitacion: " << getNumHabitacion();
    cout << " | Check in: "; getCheckIn()->imprimirFecha();
    cout << " | Check out: "; getCheckOut()->imprimirFecha();
    cout << " | Estado: "; imprimirEstado(); cout << "]";
}            