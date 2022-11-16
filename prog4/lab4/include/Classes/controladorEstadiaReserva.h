#ifndef CONTROLADORESTADIARESERVA_H
#define CONTROLADORESTADIARESERVA_h
#include "IEstadiaReserva.h"    



class controladorEstadiaReserva: public IEstadiaReserva{
    private:
        static controladorEstadiaReserva* instancia;
        controladorEstadiaReserva();
        map<int, Reserva*> reservas;
        vector<Estadia*> estadias;
    public:
        static controladorEstadiaReserva* getInstance();
        void ingresarReserva(DTFecha*, DTFecha*, string, string, string, map<string, DTHuesped*> listaHospedados);
        void registrarEstadia(DTReserva*, string);
        void finalizarEstadia(int, string);
        void imprimirReservas();
        void cerrarReserva(int);
        void darDeBaja(int);
        vector<DTHuesped*> listarHuespedesReserva(int);
        vector<DTReserva*> getReservasHostal(string);
        vector<DTReserva*> listarReservasNoCanceladas(string);
        vector<DTEstadia*> listarEstadiasHostal(string); 
        DTReserva* getDTReserva(int);
        DTEstadia* getEstadia(string , string);
        bool existeEstadia(string, string);
        int obtenerCodigo(DTFecha*, DTFecha*, string, string);
        void comentarCalificacion(string respuesta, int codigo_reserva, string comentario);
};

#endif