#include "../../include/Classes/controladorEstadiaReserva.h"

controladorEstadiaReserva* controladorEstadiaReserva::instancia = nullptr;

controladorEstadiaReserva::controladorEstadiaReserva(){
    instancia = this;
}

controladorEstadiaReserva* controladorEstadiaReserva::getInstance(){
    if( instancia == nullptr){
        instancia = new controladorEstadiaReserva();
    }
    return instancia;
}

void controladorEstadiaReserva::ingresarReserva(DTFecha* checkIn, DTFecha* checkOut, string hostalNombre, string habNum, string email, map<string, DTHuesped*> listaHospedados){

    int codigo = reservas.size() + 1;
    controladorHostal* ch = controladorHostal::getInstance();
    controladorUsuario* cu = controladorUsuario::getInstance();
    Habitacion* hab = ch->getHostal(hostalNombre)->getHabitacion(habNum);
    Huesped* hue = dynamic_cast<Huesped*>(cu->getUser(email));

    map<string, Huesped*> hosp;
    map<string, DTHuesped*>::iterator it;
    for(it = listaHospedados.begin(); it != listaHospedados.end(); ++it){
        Huesped* h = new Huesped(it->second->getNombre(), it->second->getEmail(), it->second->getPassword(), it->second->getEsFinger());
        hosp[h->getEmail()] = h;
    }

    if(listaHospedados.size() == 1){
        ReservaIndividual* r = new ReservaIndividual(codigo,checkIn, checkOut, hue, hab, hosp);
        reservas[codigo] = r;
        hab->agregarRes(r);
    } else {
        ReservaGrupal* r = new ReservaGrupal(codigo,checkIn, checkOut, hue, hab, hosp);
        reservas[codigo] = r;
        hab->agregarRes(r);
    }

}



void controladorEstadiaReserva::imprimirReservas(){
    map<int, Reserva*>::iterator it;
    for(it = reservas.begin(); it != reservas.end(); ++it ){
        it->second->imprimirReserva();
    }
}

    
vector<DTReserva*> controladorEstadiaReserva::getReservasHostal(string nombreHostal){
    map<int, Reserva*>::iterator it;
    vector<DTReserva*> reservasHostal;
    for(it = reservas.begin(); it != reservas.end(); ++it){
        if(it->second->getNombreHostal() == nombreHostal){
            reservasHostal.push_back(it->second->getDT());
        }
    }
    return reservasHostal;
}

vector<DTHuesped*> controladorEstadiaReserva::listarHuespedesReserva(int codigo){
    vector<DTHuesped*> huespedesReserva = this->reservas[codigo]->getHuespedes();
    return huespedesReserva;
}


vector<DTReserva*> controladorEstadiaReserva::listarReservasNoCanceladas(string email){
    map<int, Reserva*>::iterator it;
    vector<DTReserva*> listaRes;
    for(it = reservas.begin(); it != reservas.end(); ++it){
        if( it->second->esHuesped(email) && !it->second->estaCancelada()){
            listaRes.push_back(it->second->getDT());
        }
    }	
    return listaRes;
}   

void controladorEstadiaReserva::registrarEstadia(DTReserva* res, string email){
    
    controladorUsuario* cu = controladorUsuario::getInstance();
    FechaSistema* fs = FechaSistema::getInstance();
    DTFecha *llegada = fs->getDT();
    Reserva* r = reservas[res->getCodigo()];
    Huesped* u = dynamic_cast<Huesped*>(cu->getUser(email));
    Estadia* est = new Estadia(llegada,u,r);

    reservas[res->getCodigo()]->cerrarReserva();
    
    if( dynamic_cast<DTReservaGrupal*>(res) != NULL ){
        dynamic_cast<ReservaGrupal*>(reservas[res->getCodigo()])->agregarEstadia(est);
    } else {
        reservas[res->getCodigo()]->setEstadia(est);
    }
    estadias.push_back(est);
}

bool controladorEstadiaReserva::existeEstadia(string email, string hostal){
    vector<Estadia*>::iterator it = estadias.begin();
    while( it != estadias.end() && ((*it)->getHuesped() != email || (*it)->getHostal() != hostal || !(*it)->esActiva())){
        ++it;
    }
    return !(it == estadias.end());
}

void controladorEstadiaReserva::finalizarEstadia(int codigoReserva, string email){
    FechaSistema* fs = FechaSistema::getInstance();
    DTFecha* salida = fs->getDT();
    vector<Estadia*>::iterator it = estadias.begin();
    while(it != estadias.end() &&  ((*it)->getCodigoReserva() || codigoReserva || (*it)->getHuesped() != email)){
        ++it;
    }

    (*it)->setSalida(salida);
}

void controladorEstadiaReserva::cerrarReserva(int code){
    reservas[code]->cerrarReserva();
}

vector<DTEstadia*> controladorEstadiaReserva::listarEstadiasHostal(string hostal){
    vector<Estadia*>::iterator it;
    vector<DTEstadia*> listaEstadias;
    for(it = estadias.begin(); it != estadias.end(); ++it){
        if( reservas[(*it)->getCodigoReserva()]->getNombreHostal() == hostal ){
            listaEstadias.push_back( (*it)->getDT() );
        }
    }
    return listaEstadias;
}


int controladorEstadiaReserva::obtenerCodigo(DTFecha* checkIn, DTFecha* checkOut, string hostal, string hab){
    vector<DTReserva*> lista = getReservasHostal(hostal);
    vector<DTReserva*>::iterator it;
    int codigo = 0;
    bool b = false; 
    for(it = lista.begin(); it != lista.end() && !b; ++it){
        DTFecha* f1 = (*it)->getCheckIn();
        DTFecha* f2 = (*it)->getCheckOut();
        string habitacion = (*it)->getNumHabitacion();
    
        if( checkIn->fechasIguales(f1) && checkOut->fechasIguales(f2) && habitacion == hab){
            codigo = (*it)->getCodigo();
            b = true;
        }
    }


    return codigo;
}


void controladorEstadiaReserva::darDeBaja(int codigo){
    Reserva* h = reservas[codigo];
    h->getHabitacion()->cerrarReseva(codigo);
    reservas.erase(codigo);
    delete h;
}

DTReserva* controladorEstadiaReserva::getDTReserva(int i){
    return reservas[i]->getDT();
}

DTEstadia* controladorEstadiaReserva::getEstadia(string hostal, string email){
    vector<Estadia*>::iterator it = estadias.begin();
    while(it != estadias.end() && (*it)->getHostal() != hostal && (*it)->getHuesped() != email){
        ++it;
    }
        
    return (*it)->getDT();
}

void controladorEstadiaReserva::comentarCalificacion(string respuesta, int codigo_reserva, string comentario) {
    reservas[codigo_reserva]->comentarCalificacion(respuesta, comentario);
}
