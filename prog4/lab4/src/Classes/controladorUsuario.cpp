#include "../../include/Classes/controladorUsuario.h"

controladorUsuario* controladorUsuario::instancia = NULL;

controladorUsuario::controladorUsuario(){
    instancia = this;
}


controladorUsuario* controladorUsuario::getInstance(){
    if( instancia == NULL ){
        instancia = new controladorUsuario();
    } 
    return instancia;
}

vector<DTUsuario*> controladorUsuario::listarUsuarios(){
    vector <DTUsuario*> r = {};
    for (auto x : this->usuarios){
        r.push_back(x.second->getDT());
    }
    return r;
}


void controladorUsuario::ingresarDatosEmpleado(DTEmpleado user){
    dtuser = new DTEmpleado(user.getNombre(),user.getEmail(),user.getPassword(),user.getCargo());
}

void controladorUsuario::ingresarDatosHuesped(DTHuesped user){
    dtuser = new DTHuesped(user.getNombre(), user.getEmail(), user.getPassword(), user.getEsFinger());
}

bool controladorUsuario::emailDuplicado(){
    return this->usuarios.count(dtuser->getEmail())>0;
}

bool controladorUsuario::emailEnSistema(string email){
    return usuarios[email] != NULL;
}

void controladorUsuario::reingresarEmail(string email){
    this->dtuser->setEmail(email);
}

void controladorUsuario::ingresarEmpleado(){
    DTEmpleado* dtemp = dynamic_cast<DTEmpleado*>(dtuser);
    Empleado * emp = new Empleado(dtemp->getNombre(), dtemp->getEmail(), dtemp->getPassword(), dtemp->getCargo());
    this->usuarios.insert({dtemp->getEmail(), emp});
    this->liberarMemoria();    
}

void controladorUsuario::ingresarHuesped(){
    DTHuesped* dthue = dynamic_cast<DTHuesped*>(dtuser);
    Huesped * hue = new Huesped(dthue->getNombre(), dthue->getEmail(), dthue->getPassword(), dthue->getEsFinger());
    this->usuarios.insert({hue->getEmail(), hue});
    this->liberarMemoria();
}

void controladorUsuario::liberarMemoria(){
    delete dtuser;
}


Usuario* controladorUsuario::getUser(string email){
    return usuarios[email];
}

void controladorUsuario::asignarEmpleado(string emailEmpleado, Cargo cargo, string nombreHostal){
    Empleado * e = dynamic_cast<Empleado *>(usuarios[emailEmpleado]);
    e->setCargo(cargo);
    controladorHostal * ch = controladorHostal::getInstance();
    Hostal * hos = ch->getHostal(nombreHostal);
    e->vincularHostal(hos);
}

vector<DTHuesped*> controladorUsuario::listarHuespedes(){
    map<string, Usuario*>::iterator it;
    vector<DTHuesped*> listaHuespedes;
    for(it = usuarios.begin(); it != usuarios.end(); ++it){
        Huesped* h =  dynamic_cast<Huesped*>(it->second);
        if( h != NULL ){
          listaHuespedes.push_back( new DTHuesped(h->getNombre(), h->getEmail(), h->getPassword(), h->getEsFinger()));  
        }

    }
    return listaHuespedes;
}

string controladorUsuario::trabajaEn(string empleado) {
    Empleado* e = dynamic_cast<Empleado*>(usuarios[empleado]);
    return e->trabajaEn();
}

void controladorUsuario::listarNoEmpleadosDelHostal(string hostal, vector<DTEmpleado*>* no_empleados) {
    for(map<string, Usuario*>::iterator it = usuarios.begin(); it != usuarios.end(); ++it){
        Empleado* e =  dynamic_cast<Empleado*>(it->second);
        if((e != NULL) && (!e->tieneTrabajo())) {
          no_empleados->push_back(new DTEmpleado(e->getNombre(), e->getEmail(), e->getPassword(), e->getCargo()));
        }
    }
}