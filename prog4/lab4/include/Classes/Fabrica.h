#ifndef FABRICA_H
#define FABRICA_H

#include "controladorUsuario.h"
#include "controladorHostal.h"
#include "controladorEstadiaReserva.h"

//#include "controladorCalificacionComentario.h"

// SINGLETON
class Fabrica{
    private: 
        Fabrica();
        static Fabrica* instancia;
    public:
        static Fabrica* getInstance();
        static controladorUsuario* getControladorUsuario();
        static controladorHostal* getControladorHostal();    
        static controladorEstadiaReserva* getControladorEstadiaReserva();
};

#endif