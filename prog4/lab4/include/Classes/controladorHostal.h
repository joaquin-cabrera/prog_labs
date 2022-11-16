#ifndef CONTROLADORHOSTAL_H
#define CONTROLADORHOSTAL_H

#include "IHostal.h"

class Habitacion;
class Hostal;
class DTHabitacion;

class controladorHostal: public IHostal{
    private:
        DTHostal* dthostal;
        map<string, Hostal*> hostales;
        std::string numero;
        float precio;
        int capacidad;
        
        static controladorHostal* instancia;
        controladorHostal();
    public:
        ~controladorHostal();
        static controladorHostal* getInstance();
        void imprimirHostales();
        bool hostalEnSistema(string);
        bool habitacionEnHostal(string, string);
        void ingresarHostal(string, string, string);
        vector<DTHostal*> listarHostales();
        void datosHabitacion(std::string numero, float precio,int capacidad, DTHostal* hostalEnSistema);
        void agregarHabitacion();
        void cancelarOperacion();
        Hostal* getHostal(string);
        vector<DTHabitacion*> listarHabDisponibles(DTFecha*, DTFecha*, string);
        vector<string> topHostales();
        void detallesHostal(string hostal, vector<DTCalificacion>* calificaciones);
        float getPromedio(string hostal);
        void obtenerHabitaciones(string hostal, vector<DTHabitacion>* habitaciones);
};

#endif
