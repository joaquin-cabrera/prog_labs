#include "../include/DTHuesped.h"
#include "../include/DTHabitacion.h"
#include "../include/DTReserva.h"
#include "../include/Huesped.h"
#include "../include/Habitacion.h"
#include "../include/Reserva.h"
#include "../include/ReservaIndividual.h"
#include "../include/ReservaGrupal.h"
#include "../include/DTReservaIndividual.h"
#include "../include/EstadoReserva.h"
#include "../include/DTReserva.h"
#include "../include/DTReservaGrupal.h"
#include "../include/DTHuesped.h"
#include "../include/DTHabitacion.h"
#include "../include/DTFecha.h"

#include <iostream>
using namespace std;

class Sistema{
    private:
        Huesped **huespedes;
        Habitacion **habitaciones;
        Reserva **reservas;
        int cantHuespedes, cantHabitaciones, cantReservas;
    public:
        Sistema();
        ~Sistema();
        void agregarHuesped(string nombre, string email, bool esFinger);    
        void agregarHabitacion(int numero, float precio, int capacidad);
        void registrarReserva(string email, DTReserva* reserva);

        DTHuesped** obtenerHuespedes(int& cantHuespedes);
        DTHabitacion** obtenerHabitaciones(int& cantHabitaciones);
        DTReserva** obtenerReservas(DTFecha fecha, int& cantReservas);

        int huespedRegistrado(string email);
        int habitacionRegistrada(int numero);
		
		DTHuesped** listaHuespedes(string* huespedes, int cantidad_huespedes);
    
        void imprimirHuespedes();
        void imprimirHabitaciones();
        void imprimirReservas();

        int getCantHabitaciones();
        int getCantHuespedes();
        int getCantReservas();

        Huesped**getHuespedes();
        Habitacion**getHabitaciones();
        Reserva**getReservas();
};