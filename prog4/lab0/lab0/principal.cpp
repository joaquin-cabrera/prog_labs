#include <stdio.h>

#include "include/DTFecha.h"
#include "include/DTHabitacion.h"
#include "include/DTHuesped.h"

#include "include/DTReserva.h"
#include "include/DTReservaIndividual.h"
#include "include/DTReservaGrupal.h"
#include "include/Sistema.h"

using std::cin;

    

int main(){

    Sistema *s = new Sistema();

//     //REGISTRO de habitaciones y huespedes
//     s->agregarHabitacion(100, 50, 4);
//     s->agregarHabitacion(101, 55, 4);

//     s->agregarHuesped("joaco", "joaco@joaco", true);
//     s->agregarHuesped("juan", "juan@juan", false);

//     EstadoReserva state1 = EstadoReserva::Abierta;
//     DTFecha *checkIn = new DTFecha(1, 1, 2000);
//     DTFecha *checkOut = new DTFecha(10, 1, 2000);

//     //Arreglo de DTHuespedes
//     DTHuesped** hs1 = new DTHuesped*[2];
//     hs1[0] = new DTHuesped("pepe", "joaco@joaco", true);
//     hs1[1] = new DTHuesped("fiori", "juan@juan", false);	
    
//     DTReserva *ri1 = new DTReservaIndividual(1010, checkIn, checkOut, EstadoReserva::Abierta, 110, 100, true);
//     DTReserva *ri2 = new DTReservaIndividual(1011, checkIn, checkIn, EstadoReserva::Abierta, 120, 101, false);

//    DTReserva *rg1 = new DTReservaGrupal(2010, checkIn, checkOut, state1, 100, 100, hs1, 2);

    
//     s->registrarReserva("juan@juan", ri1);
//     s->registrarReserva("joaco@joaco", ri2);
//     s->registrarReserva("juan@juan", rg1);


    // s->imprimirHabitaciones();
    // s->imprimirHuespedes();
    // s->imprimirReservas();

         cout << "Bienvenidos a la primera tarea de P4, porfavor elija la accion a realizar:" << endl;

        bool nosalir = true;
        while(nosalir){ 
            cout << "-----------------------------------------------" << endl;
            cout << "|1. Agregar Huesped                            |" << endl;
            cout << "|2. Agregar Habitacion                         |" << endl;
            cout << "|3. Obtener Huespedes                          |" << endl;
            cout << "|4. Obtener Habitaciones                       |" << endl;
            cout << "|5. Registrar Reserva                          |" << endl;
            cout << "|6. Obtener Reservas                           |" << endl;
            cout << "|7. Salir                                      |" << endl;
            cout << "-----------------------------------------------" << endl;

            int opcion;
            cin >> opcion;

            switch(opcion){
                case  1:{
                    cout << "Por favor ingrese el nombre del huesped" << endl;
                    string nombre;
                    cin >> nombre;

                    cout << "Por favor ingrese el email del huesped" << endl;
                    string email;
                    cin >> email;
                    
                    char letra;
                    bool esFinger;
                    do{
                        cout << "Por favor responda Y si el huesped es finger, N si no lo es" << endl;
                        cin >> letra;
                        if((letra == 'Y') || (letra == 'y'))
                            esFinger = true;
                        else if ((letra == 'N') || (letra == 'n'))
                            esFinger = false;
                        else 
                            cout << "¡OPCION NO VALIDA!, INGRESE OTRA" << endl;    
                    }while((letra != 'Y') && (letra != 'y') && (letra != 'N') &&( letra != 'n'));  

                    s->agregarHuesped(nombre, email, esFinger);
                    cout << "Huesped ingresado correctamente" <<endl;
                break;
                }
                case  2:{
                    cout << "Por favor ingrese el numero de la habitacion" << endl;
                    int numero;
                    cin >> numero;

                    cout << "Por favor ingrese el precio de la habitacion" << endl;
                    int precio;
                    cin >> precio;

                    cout << "Por favor ingrese la capacidad de la habitacion" << endl;
                    int capacidad;
                    cin >> capacidad;

                    s->agregarHabitacion(numero, capacidad, precio);
                    cout << "Habitacion ingresada correctamente" << endl;
                break;
                }
                case  3:{
                    int cantHuespedes = 0;
                    DTHuesped** listaHuespedes = s->obtenerHuespedes(cantHuespedes);
                    for (int i = 0; i <= cantHuespedes-1; i++){
                        listaHuespedes[i]->imprimirHuesped();
                    }
                    for (int i = 0; i <= cantHuespedes-1; i++){
                        delete listaHuespedes[i];
                    }
                    delete[] listaHuespedes;
                break;
                }
                case  4:{
                    int cantHabitaciones = 0;
                    DTHabitacion** listaHabitaciones = s->obtenerHabitaciones(cantHabitaciones);
                    for (int i = 0; i <= cantHabitaciones-1; i++){
                        listaHabitaciones[i]->imprimirHabitacion();
                    }
                    for (int i = 0; i <= cantHabitaciones-1; i++){
                        delete listaHabitaciones[i];
                    }
                    delete[] listaHabitaciones;
                break;
                }
                case  5:{
                    cout << "Por favor denos el dia del check in" << endl;
                    int dia1;
                    cin >> dia1;
                    cout << "Por favor denos el mes del check in"<< endl;
                    int mes1;
                    cin >> mes1;
                    cout << "Por favor denos el anio del check in" << endl;
                    int anio1;
                    cin >> anio1;
                    DTFecha* checkIn = new DTFecha(dia1,  mes1, anio1);
                    cout << "Por favor denos el dia del check out" << endl;
                    int dia2;
                    cin >> dia2;
                    cout << "Por favor denos el mes del check out"<< endl;
                    int mes2;
                    cin >> mes2;
                    cout << "Por favor denos el anio del check out" << endl;
                    int anio2;
                    cin >> anio2;
                    DTFecha* checkOut = new DTFecha(dia2,  mes2, anio2);
                    cout << "Por favor denos el costo de la reserva" << endl;
                    float costo;
                    cin >> costo;
                    cout << "Por favor denos el codigo de la reserva" << endl;
                    int codigo;
                    cin >> codigo;
                    cout << "Por favor denos el numero de habitacion de la reserva" << endl;
                    int habitacion;
                    cin >> habitacion;
                    cout << "Si la reserva esta abierta escriba 1 si la reserva esta cerrada escriba 2 si la reserva esta cancelada escriba 3" << endl;
                    int estado;
                    EstadoReserva estadoReserva;
                    cin >> estado;
                    switch(estado) {
                        case 1:{
                            estadoReserva = EstadoReserva::Abierta;
                            break;
                        }
                        case 2:{
                            estadoReserva = EstadoReserva::Cerrada;
                            break;
                        }
                        case 3:{
                            estadoReserva = EstadoReserva::Cancelada;
                            break;
                        }
                    }
                    cout << "Por favor presione 1 si la reserva es individual o 2 si la reserva es grupal" << endl;
                    cin >> estado;
                    switch(estado){
                        case 1:{
                            cout << "Por favor presione 1 si la reserva fue pagada o 2 en otro caso" << endl;
                            cin >> estado;
                            bool pagado = (estado == 1);
                            cout << "Por favor denos el email del huesped" << endl;
                            string email;
                            cin >> email;
                            DTReserva* reserva = new DTReservaIndividual(codigo, checkIn, checkOut, estadoReserva, costo, habitacion, pagado);
                            s->registrarReserva(email, reserva);
                            delete reserva;
                            cout << "Reserva registrada exitosamente" << endl;
                            break;
                        }
                        case 2:{
                            cout << "Por favor denos la cantidad de huespedes" << endl;
                            int cantidad_huespedes;
                            cin >> cantidad_huespedes;
                            string* huespedes = new string[cantidad_huespedes];
                            for (int i = 0; i < cantidad_huespedes; i++) {
                                cout << "Por favor denos el email del "<< i << " huesped" << endl;
                                cin >> huespedes[i];
                            }
                            DTHuesped** listaHuespedes = s->listaHuespedes(huespedes, cantidad_huespedes);
                            DTReserva* reserva = new DTReservaGrupal(codigo, checkIn, checkOut, estadoReserva, costo, habitacion, listaHuespedes, cantidad_huespedes);
                            s->registrarReserva(huespedes[0], reserva);
                            delete reserva;
                            cout << "Reserva registrada exitosamente" << endl;
							for(int j = 0; j <= cantidad_huespedes; j++){
							delete[] listaHuespedes[j];
							}
							delete[] listaHuespedes;
                            delete[] huespedes;
                            break;
                        }
                    }
                    break;
                }
                case  6:{
                    cout << "Por favor denos el dia las reservas" << endl;
                    int dia;
                    cin >> dia;
                    cout << "Por favor denos el mes las reservas"<< endl;
                    int mes;
                    cin >> mes;
                    cout << "Por favor denos el anio las reservas" << endl;
                    int anio;
                    cin >> anio;
                    DTFecha* fecha = new DTFecha(dia,  mes, anio);
                    int cantReservas = 0;
                    DTReserva** listaReservas = s->obtenerReservas(*fecha,cantReservas);

                    for (int i = 0; i <= cantReservas-1; i++){
                        DTReservaIndividual * aux = dynamic_cast<DTReservaIndividual*>(listaReservas[i]);
                        if(aux==nullptr){
                             DTReservaGrupal * aux = dynamic_cast<DTReservaGrupal*>(listaReservas[i]);
                            if(aux == nullptr){
                                cout << "Error durante el dynamic cast." << endl;
                            }else{
                                cout << *aux;
                                delete aux;
                            }
                        }else{
                            cout << *aux;
                            delete aux;
                        }
                    }
                    cout << endl;
                    delete[] listaReservas;
                    delete fecha;
                    break;
                }
                case  7:{
                    for (int i = 0; i<s->getCantHuespedes(); i++)
                        delete s->getHuespedes()[i];
                    for (int i = 0; i<s->getCantHabitaciones(); i++)
                        delete s->getHabitaciones()[i];
                    for (int i = 0; i<s->getCantReservas(); i++)
                        delete s->getReservas()[i];
                    delete s;
                    nosalir = false;
                    break;
                }
            }
        };
	    return 0; 
}
