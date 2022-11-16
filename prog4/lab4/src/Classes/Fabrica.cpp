#include "../../include/Classes/Fabrica.h"

Fabrica* Fabrica::instancia = NULL;

Fabrica::Fabrica(){
    instancia = this;
}

Fabrica* Fabrica::getInstance(){
    if (instancia == NULL)
        instancia = new Fabrica();
    return instancia;    
}

controladorUsuario* Fabrica::getControladorUsuario(){
    return controladorUsuario::getInstance();
}

controladorHostal* Fabrica::getControladorHostal(){
    return controladorHostal::getInstance();
}

controladorEstadiaReserva* Fabrica::getControladorEstadiaReserva(){
    return controladorEstadiaReserva::getInstance();
}