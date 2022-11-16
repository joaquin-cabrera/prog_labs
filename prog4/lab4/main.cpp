#include "include/Classes/Fabrica.h"
#include <iostream>


void imprimirListaHostales(vector<DTHostal*> listaHostales){
    vector<DTHostal*>::iterator it;
    int contador = 0;
    for(it = listaHostales.begin() ; it != listaHostales.end(); ++it){
        cout << contador << "- ";
        DTHostal* dt = *it;
        dt->imprimir();
        contador++;
    }
};

void imprimirHabitaciones(vector<DTHabitacion*> listaHabitaciones){
    vector<DTHabitacion*>::iterator it;
    int contador = 0;
    for(it = listaHabitaciones.begin(); it != listaHabitaciones.end(); ++it){
        cout << contador << "- ";
        DTHabitacion* dt = *it;
        dt->imprimir();
        contador++;
        cout << endl;
    }
}

void imprimirHuespedes(vector<DTHuesped*> listaHuesped){
    vector<DTHuesped*>::iterator it;
    int contador = 0;
    for(it = listaHuesped.begin(); it != listaHuesped.end(); ++it){
        cout << contador << "- ";
        DTHuesped* dt = *it;
        dt->imprimirBasic();
        cout << endl;
        contador++;        
    }
}

void imprimirDatosHuespedes(vector<DTHuesped*> listaHuesped){
    vector<DTHuesped*>::iterator it;
    for(it = listaHuesped.begin(); it != listaHuesped.end(); ++it){
        DTHuesped* dt = *it;
        cout << " ";
        dt->imprimirBasic();
        cout << endl;
    }
}

void imprimirEmpleados(vector<DTEmpleado*> listaEmpleado){
    vector<DTEmpleado*>::iterator it;
    int contador = 0;
    for(it = listaEmpleado.begin(); it != listaEmpleado.end(); ++it){
        cout << contador << "- ";
        DTEmpleado* dt = *it;
        dt->print();
        cout << endl;
        contador++;        
    }
}


void imprimirReservas(vector<DTReserva*> listaReservas){
    vector<DTReserva*>::iterator it;
    int contador = 0;
    for(it = listaReservas.begin(); it != listaReservas.end(); ++it){
        cout << contador << "- ";
        DTReserva* dt = *it;
        IEstadiaReserva* cer = Fabrica::getControladorEstadiaReserva();
        vector<DTHuesped*> huespedes = cer->listarHuespedesReserva(dt->getCodigo());
        dt->imprimir();
        cout << endl << "Huespedes de la reserva: " << endl;
        imprimirDatosHuespedes(huespedes);
        cout << endl;
        contador++;        
    }
}

void imprimirBasicReservas(vector<DTReserva*> listaReservas){
    vector<DTReserva*>::iterator it;
     for(it = listaReservas.begin(); it != listaReservas.end(); ++it){
        cout << " ";
        DTReserva* dt = *it;
        IEstadiaReserva* cer = Fabrica::getControladorEstadiaReserva();
        vector<DTHuesped*> huespedes = cer->listarHuespedesReserva(dt->getCodigo());
        dt->imprimir();
        cout << endl;      
    }

}

int traerPosicion(vector<DTReserva*> listaReservas, int codigo){
    vector<DTReserva*>::iterator it = listaReservas.begin();
    int pos = 0;
    while(it != listaReservas.end() && (*it)->getCodigo() != codigo){
        pos++;
        ++it;
    }
    return pos;
}

DTFecha* ingresarFecha(){
  int dia, mes, anio, hora;
  cout << "Dia: "; cin >> dia;
  while(dia > 30 || dia < 1){
    cout << "Valor incorrecto, ingrese otro: ";
    cin >> dia;
  }

  cout << "Mes: "; cin >> mes;
  while(mes > 12 || mes < 1){
    cout << "Valor incorrecto, ingrese otro: ";
    cin >> mes;
  }
  cout << "Anio: "; cin >> anio;
  while(anio < 1900){
    cout << "Valor incorrecto, ingrese otro: ";
    cin >> anio;  
  }
  cout << "Hora: "; cin >> hora;
  while(hora > 23 || hora < 0){
    cout << "Valor incorrecto, ingrese otro: ";
    cin >> hora;
  }

  return new DTFecha(dia, mes, anio, hora);
}




int main(){
    cout << endl;

    IHostal* ch = Fabrica::getControladorHostal();
    IUsuario* cu = Fabrica::getControladorUsuario();
    IEstadiaReserva* cer = Fabrica::getControladorEstadiaReserva();
    FechaSistema* fs = FechaSistema::getInstance();


    DTFecha* f = new DTFecha(1,1,1901,12);
    fs->modificarFecha(f);
    
    //MENU
    cout << "__________________________________________" << endl;
    cout << "|        LABORATORIO 4 - Grupo 32        | "<< endl;
    cout << "|________________________________________|" << endl << endl;

    int teclado = -1;
    do{
        cout << "========[SELECCIONE UNA OPERACION]========" << endl;
        cout << "|  0- Cargar datos de prueba             |" << endl;
        cout << "|  1- Alta de Usuario                    |" << endl;
        cout << "|  2- Alta de Hostal                     |"<< endl;
        cout << "|  3- Alta de Habitacion                 |" << endl;
        cout << "|  4- Asignar Empleado a Hostal          |" << endl;
        cout << "|  5- Realizar Reserva                   |" << endl;
        cout << "|  6- Consulta top 3 Hostales            |" << endl;
        cout << "|  7- Registrar Estadia                  |" << endl;
        cout << "|  8- Finalizar Estadia                  |" << endl;
        cout << "|  9- Calificar Estadia                  |" << endl;
        cout << "| 10- Comentar Calificacion              |" << endl;
        cout << "| 11- Consulta de Usuario                |" << endl;
        cout << "| 12- Consulta de Hostal                 |" << endl;
        cout << "| 13- Consulta de Reserva                |" << endl;
        cout << "| 14- Consulta de Estadia                |" << endl;
        cout << "| 15- Baja de Reserva                    |" << endl;
        cout << "| 16- Suscribirse a Notificaciones       |" << endl;
        cout << "| 17- Consulta de Notificaciones         |" << endl;
        cout << "| 18- Eliminar Suscripcion               |" << endl;
        cout << "| 19- Modificar Fecha del Sistema        |" << endl;
        cout << "| 20- Salir                              |" << endl;
        cout << "|________________________________________|" << endl;
        cin >> teclado;
        switch(teclado){
            case 0:{
                //ingresar empleados
                DTEmpleado * E1 = new DTEmpleado("Emilia","emilia@mail.com","123",Cargo::Recepcion);
                cu->ingresarDatosEmpleado(*E1);
                cu->ingresarEmpleado();
                DTEmpleado * E2 = new DTEmpleado("Leonargo","leo@mail.com","123",Cargo::Recepcion);
                cu->ingresarDatosEmpleado(*E2);
                cu->ingresarEmpleado();
                DTEmpleado * E3 =new DTEmpleado("Alina","alina@mail.com","123",Cargo::Administracion);
                cu->ingresarDatosEmpleado(*E3);
                cu->ingresarEmpleado();;
                DTEmpleado * E4 =new DTEmpleado("Barliman","barli@mail.com","123",Cargo::Recepcion);
                cu->ingresarDatosEmpleado(*E4);
                cu->ingresarEmpleado();

                //ingresar huespedes
                DTHuesped * H1 = new DTHuesped("Sofia","sofia@mail.com","123",true);
                cu->ingresarDatosHuesped(*H1);
                cu->ingresarHuesped();
                DTHuesped * H2 = new DTHuesped("Frodo","frodo@mail.com","123",true);
                cu->ingresarDatosHuesped(*H2);
                cu->ingresarHuesped();
                DTHuesped * H3 = new DTHuesped("Sam","sam@mail.com","123",false);
                cu->ingresarDatosHuesped(*H3);
                cu->ingresarHuesped();
                DTHuesped * H4 = new DTHuesped("Merry","merry@mail.com","123",false);
                cu->ingresarDatosHuesped(*H4);
                cu->ingresarHuesped();
                DTHuesped * H5 = new DTHuesped("Pippin","pippin@mail.com","123",false);
                cu->ingresarDatosHuesped(*H5);
                cu->ingresarHuesped();
                DTHuesped * H6 = new DTHuesped("Seba","seba@mail.com","123",true);
                cu->ingresarDatosHuesped(*H6);
                cu->ingresarHuesped();

                //ingresar hostales
                ch->ingresarHostal("La posada del finger","Av de la playa 123, Maldonado","099111111");
                DTHostal * HO1 = new DTHostal("La posada del finger","Av de la playa 123, Maldonado","099111111");
                ch->ingresarHostal("Mochileros","Rambla Costanera 333, Rocha","42579512");
                DTHostal * HO2 = new DTHostal("Mochileros","Rambla Costanera 333, Rocha","42579512");
                ch->ingresarHostal("El Pony Pisador","Bree (preguntar por Gandalf)","000");
                DTHostal * HO3 = new DTHostal("El Pony Pisador","Bree (preguntar por Gandalf)","000");
                ch->ingresarHostal("Altos de Fing ","Av del Toro 1424 ","099892992");
                //DTHostal * HO4 = new DTHostal("Altos de Fing ","Av del Toro 1424 ","099892992");
                ch->ingresarHostal("Caverna Lujosa","Amaya 2515","233233235");
                DTHostal * HO5 = new DTHostal("Caverna Lujosa","Amaya 2515","233233235");

                //ingresar habitaciones
                ch->datosHabitacion("1",40.0,2,HO1);
                ch->agregarHabitacion();
                ch->datosHabitacion("2",10.0,7,HO1);
                ch->agregarHabitacion();
                ch->datosHabitacion("3",30.0,3,HO1);
                ch->agregarHabitacion();
                ch->datosHabitacion("4",5.0,12,HO1);
                ch->agregarHabitacion();
                ch->datosHabitacion("5",3.0,2,HO5);
                ch->agregarHabitacion();
                ch->datosHabitacion("6",9.0,5,HO3);
                ch->agregarHabitacion();

                //asignacion de empleados a hostels
                cu->asignarEmpleado( E1->getEmail(), Cargo::Recepcion, HO1->getNombre());
                cu->asignarEmpleado( E2->getEmail(), Cargo::Recepcion, HO2->getNombre());
                cu->asignarEmpleado( E3->getEmail(), Cargo::Administracion, HO2->getNombre());
                cu->asignarEmpleado( E4->getEmail(), Cargo::Recepcion, HO3->getNombre());

                //reservas
                DTFecha* CI1 = new DTFecha(1,5,2022,14);
                DTFecha* CO1 = new DTFecha(10,5,2022,10);
                DTFecha* CI2 = new DTFecha(4,1,2001,20);
                DTFecha* CO2 = new DTFecha(5,1,2001,14);
                DTFecha* CI3 = new DTFecha(7,6,2022,14);
                DTFecha* CO3 = new DTFecha(30,6,2022,11);
                DTFecha* CI4 = new DTFecha(10,6,2022,14);
                DTFecha* CO4 = new DTFecha(30,6,2022,11);   

                map<string, DTHuesped*> listaHosp1, listaHosp2, listaHosp3;
                listaHosp1[H1->getEmail()] = H1;
                listaHosp2[H6->getEmail()] = H6;
                
                listaHosp3[H2->getEmail()] = H2;
                listaHosp3[H3->getEmail()] = H3;
                listaHosp3[H4->getEmail()] = H4;
                listaHosp3[H5->getEmail()] = H5;
        
                //R1
                cer->ingresarReserva(CI1, CO1, HO1->getNombre(),"1", H1->getEmail(), listaHosp1);
                //R2
                cer->ingresarReserva(CI2, CO2, HO3->getNombre(),"1", H2->getEmail(), listaHosp3);
                //R3
                cer->ingresarReserva(CI3, CO3, HO1->getNombre(),"3", H1->getEmail(), listaHosp1);
                //R4
                cer->ingresarReserva(CI4, CO4, HO5->getNombre(),"1", H6->getEmail(), listaHosp2);

                // int codigoR1 = cer->obtenerCodigo(CI1,CO1,HO1->getNombre(),"1");   
                // int codigoR2 = cer->obtenerCodigo(CI2,CO2,HO3->getNombre(),"1");
                // int codigoR3 = cer->obtenerCodigo(CI3,CO3,HO1->getNombre(),"3");
                // int codigoR4 = cer->obtenerCodigo(CI4,CO4,HO5->getNombre(),"1");  

                // cout << "Codigo R1: " << codigoR1 << endl;
                // cout << "Codigo R2: " << codigoR2 << endl;
                // cout << "CODIGOR R3: " << codigoR3 << endl;
                // cout << "Codigo R4: " << codigoR4 << endl;

                DTReserva* r1 = cer->getDTReserva(1);
                DTReserva* r2 = cer->getDTReserva(2);
                DTReserva* r4 = cer->getDTReserva(4);

                DTFecha* llegada1 = new DTFecha(1,5,2022,18);
                fs->modificarFecha(llegada1);
                cer->registrarEstadia(r1, H1->getEmail());
                 
                DTFecha* llegada2 = new DTFecha(4,1,2001,21);
                fs->modificarFecha(llegada2);
                cer->registrarEstadia(r2, H2->getEmail());
                cer->registrarEstadia(r2, H3->getEmail());
                cer->registrarEstadia(r2, H4->getEmail());
                cer->registrarEstadia(r2, H5->getEmail());

                DTFecha* llegada3 = new DTFecha(7,6,2022,18);
                fs->modificarFecha(llegada3);
                cer->registrarEstadia(r4, H6->getEmail());

                //delete DT
                delete E1;
                delete E2;
                delete E3;
                delete E4;
                delete H1;
                delete H2;
                delete H3;
                delete H4;
                delete H5;
                delete H6;
                delete HO1;
                delete HO3;
                delete HO5;
                break;
            }
            case 1:{
                string nombre;
                string email;
                string pass;
                char tipo_usuario='u';

                cout << "[Ingrese los datos del usuario:]" << endl;
                cout << "Nombre(string): ";
                cin >> nombre;
                cout << "Email(string): ";
                cin >> email;
                cout << "Password(string): ";
                cin >> pass;
                do{
                    cout << "Tipo de usuario [e=Empleado, h=Huesped]: ";
                    cin >> tipo_usuario;
                    switch(tipo_usuario){
                        case 'e':{
                            DTEmpleado *user;
                            Cargo cargo;
                            char teclado_cargo='c';
                            do{
                                cout << "Cargo: [a=Administracion, l=Limpieza, r=Recepcion]: ";
                                cin >> teclado_cargo;
                                switch(teclado_cargo){
                                    case 'a':{
                                        cargo = Cargo::Administracion;
                                        break;
                                    }
                                    case 'l':{
                                        cargo = Cargo::Limpieza;
                                        break;
                                    }
                                    case 'r':{
                                        cargo = Cargo::Recepcion;
                                        break;
                                    }default:{
                                        cout << "ERROR: Cargo seleccionado invalido.";
                                    }
                                }
                            }while(teclado_cargo!='a' && teclado_cargo!='l' && teclado_cargo!='r');
                            user = new DTEmpleado(nombre,email,pass,cargo);
                            cu->ingresarDatosEmpleado(*user);
                            delete user;
                            break;//fin empleado
                        }
                        case 'h':{
                            DTHuesped *user;
                            bool finger;
                            char teclado_finger='f';
                            do{
                                cout << "Finger [0=Falso, 1=Verdadero]: ";
                                cin >> teclado_finger;
                                switch(teclado_finger){
                                    case '0':{
                                        finger = false;
                                        break;
                                    }
                                    case '1':{
                                        finger = true;
                                        break;
                                    }
                                    default:{
                                        cout << "ERROR: El valor ingresado debe ser 0 o 1.";
                                    }
                                }
                            }while(teclado_finger!='0' && teclado_finger!='1');
                            user = new DTHuesped(nombre,email,pass,finger);
                            cu->ingresarDatosHuesped(*user);
                            delete user;
                            break;//fin bifurcacion ingreso de datos huesped
                        }
                        default:{
                            cout << "ERROR: Tipo de usuario no valido" << endl;
                        }
                    }
                }while(tipo_usuario!= 'e' && tipo_usuario!= 'h');//fin ingreso datos usuario

                bool duplicado= cu->emailDuplicado();
                while(duplicado){
                    char teclado_yn='x';
                    cout << "Error: Existe un usuario con el mismo email." << endl;
                    cout << "Desea ingresar un nuevo email? [y/n]: ";
                    cin >> teclado_yn;
                    if(teclado_yn!='y' && teclado_yn!='n'){
                        cout << "ERROR: ingrese y/n." << endl;
                    }else if (teclado_yn=='y'){
                        cout << "Email: ";
                        cin >> email;
                        cu->reingresarEmail(email);
                        duplicado= cu->emailDuplicado();
                    }else{
                        cout << "El proceso de alta de usuario ha sido cancelado." << endl;
                        break;
                    }
                }
                if(!duplicado){
                    char teclado_yn='x';
                    pregunta_realizar_cambios_alta_usuario:
                    cout << "Desea hacer efectivos los cambios? [y/n]: ";
                    cin >> teclado_yn;
                    if(teclado_yn!='y' && teclado_yn!='n'){
                        cout << "ERROR: ingrese y/n." << endl;
                        goto pregunta_realizar_cambios_alta_usuario;
                    }else if(teclado_yn=='y'){
                        if(tipo_usuario=='e'){
                            cu->ingresarEmpleado();
                        }else{
                            cu->ingresarHuesped();
                        }

                    }else{
                        cout << "Se ha cancelado el proceso de alta." << endl;
                    }
                }
                break;
            }
            case 2:{
                string nombre="";
                string direccion="";
                string telefono="";
                cout << "Ingrese los datos del Hostal:" << endl;
                cout << "Nombre(string): ";
                cin >> nombre;
                cout << "Direccion(string): ";
                cin >> direccion;
                cout << "Telefono(string): ";
                cin >> telefono;

                if(ch->hostalEnSistema(nombre)){
                    cout << "ERROR: El hostal no ha sido ingresado." << endl;
                    cout << "       Ya existe un hostal llamado '" << nombre << "' en el sistema." << endl;
                }else{
                    ch->ingresarHostal(nombre,direccion,telefono);
                }
                break;
            }
            case 3:{
                vector<DTHostal*> dthostales = ch->listarHostales();
                int contador=0;
                cout << "==========================================" << endl;
                cout << "nombre;direccion;telefono" << endl;
                for (auto h:dthostales){
                    cout << contador << "- "<< h->getNombre() <<";"<<h->getDireccion()<<";"<<h->getTelefono()<<endl;
                    contador++;
                }
                if(dthostales.size()==0){
                    cout << "No hay hostales en el sistema"<<endl;
                    cout << "==========================================" << endl;
                }else{
                    int numero_hostal;
                    cout << "==========================================" << endl;
                    cout << "Seleccione un hostal [0-"<<contador-1<<"]: ";
                    cin >> numero_hostal;
                    string numero;
                    float precio;
                    int capacidad;
                    cout << "[Ingrese datos de la habitacion]:" << endl;
                    cout << "Numero(string): ";
                    cin >> numero;
                    cout << "Precio(float): ";
                    cin >> precio;
                    cout << "Capacidad(int): ";
                    cin >> capacidad;
                    ch->datosHabitacion(numero,precio,capacidad,dthostales.at(numero_hostal));
                    cout << "Desea hacer los cambios permanentes? [y/n]:" << endl;
                    char teclado_yn;
                    cin >> teclado_yn;
                    if(teclado_yn=='y'){
                        ch->agregarHabitacion();
                    }else{
                        ch->cancelarOperacion();
                    }

                }

                for(auto x:dthostales){
                    delete x;
                }
                dthostales.clear();

                break;
            }
            case 4: {
                vector<DTHostal*> listaHostales = ch->listarHostales();
                if (listaHostales.empty()) {
                    cout << "No hay hostales en el sistema" << endl;
                    break;
                }
                imprimirListaHostales(listaHostales);
                cout << "Seleccione un hostal: " << endl;
                int h;
                cin >> h; // hostal
                vector<DTEmpleado*>* no_empleados = new vector<DTEmpleado*>;
                cu->listarNoEmpleadosDelHostal(listaHostales[h]->getNombre(), no_empleados);
                if (no_empleados->empty()) {
                    cout << "No hay empleados disponibles para el hostal seleccionado" << endl;
                    break;
                }
                imprimirEmpleados(*no_empleados);
                cout << "Seleccione un empleado: ";
                int e;
                cin >> e; //empleado
                cout << "Seleccione un cargo: " << endl << "1- Administracion" << endl << "2- Limpieza" << endl << "3- Recepcion" << endl;
                int c; //cargo
                cin >> c;
                Cargo cargo;
                if (c == 1)
                    cargo = Cargo::Administracion;
                if (c == 2)
                    cargo = Cargo::Limpieza;
                if (c == 3)
                    cargo = Cargo::Recepcion;
                cu->asignarEmpleado((*no_empleados)[e]->getEmail(), cargo, listaHostales[h]->getNombre());
                cout << "Empleado asignado" << endl;
                break;
            }
            case 5:{

                cout << "|REALIZAR RESERVA|" << endl << endl;
                unsigned int entrada;
                vector<DTHostal*> listaHostales = ch->listarHostales();
                
                
                if(listaHostales.empty()){
                    cout << "No hay Hostales en el Sistema." << endl << endl;
                    break;
                }

                cout << "| Seleccione un Hostal |" << endl;
                imprimirListaHostales(listaHostales);
                //seleccionar hostal
                cout << "Numero de Hostal [0-"<<listaHostales.size()-1<<"]: ";
                cin >> entrada;
                while( entrada < 0 || entrada > listaHostales.size() - 1){
                    cout << "Numero invalido. " << "Ingrese otro numero: " ;
                    cin >> entrada;
                }
                cout << endl;
                string nombreHostal = listaHostales.at(entrada)->getNombre();

                //ingresar checkIn y check Out
                cout << "| Ingrese fecha de Check In |" << endl;
                DTFecha* checkIn = ingresarFecha();
                cout << "Fecha de Check In: "; 
                checkIn->imprimirFecha();
                cout << endl << endl;
                cout << "| Ingrese fecha de Check Out |" << endl;
                DTFecha* checkOut = ingresarFecha();
                cout << "Fecha de Check Out: ";
                checkOut->imprimirFecha();
                cout << endl << endl;
                
                //indicar si es individual o grupal
                char tipoReserva;
                cout << "| Tipo de Reserva |" << endl;
                cout << "[ Individual = i, Grupal = g ]: ";
                cin >> tipoReserva; 
                cout << endl;
                // while(tipoReserva != "i" || tipoReserva != "g"){
                //     //invalid argument
                //     cin >> tipoReserva;
                // }

                
                //usuario selecciona habitacion disponible
                vector<DTHabitacion*> habDisponibles = ch->listarHabDisponibles(checkIn, checkOut, nombreHostal);
                if(habDisponibles.empty()){
                    cout << nombreHostal << " no tiene habitaciones disponibles en esas fechas. " << endl << endl;
                    break;
                } 
                cout << "Habitaciones disponibles en ["<< nombreHostal<< "] desde ["; checkIn->imprimirFecha(); 
                cout << "] hasta ["; checkOut->imprimirFecha(); cout << "] :"<< endl;
                imprimirHabitaciones(habDisponibles);
                cout << "Seleccione una Habitacion [0 - " << habDisponibles.size() - 1 << "]: ";
                cin >> entrada; cout << endl;
                string numHab = habDisponibles.at(entrada)->getNumero();

                //usuario indica huesped que realiza la reserva
                cout << "| Reserva a nombre de: |" << endl;
                vector<DTHuesped*> listaHuespedes = cu->listarHuespedes();
                if(listaHuespedes.empty()){
                    cout << "No hay ningun Huesped en el sistema. " << endl;
                    break;
    
                }

                imprimirHuespedes(listaHuespedes);
                cout << "Seleccione un Huesped [0 - " << listaHuespedes.size() - 1 << "]: ";
                cin >> entrada;
                string emailHuesped = listaHuespedes.at(entrada)->getEmail();

                map<string, DTHuesped*> listaHospedados; 
                listaHospedados[emailHuesped] = listaHuespedes.at(entrada);

                //si es grupal indica todos los huespedes
                cout << endl;
                if(tipoReserva == 'g'){
                    unsigned int nroHuesped = 0;// cantHuespedes;
                    unsigned int max = listaHuespedes.size();
                    listaHospedados[emailHuesped] = new DTHuesped(listaHuespedes.at(entrada)->getNombre(), emailHuesped, listaHuespedes.at(entrada)->getPassword(),
                                                                listaHuespedes.at(entrada)->getEsFinger());
                    cout << "| Indique Huespedes de la Reserva |" << endl;
                    cout << " Escriba el numero [" << -1 << "] cuando termino de agregar. " << endl; 
                    imprimirHuespedes(listaHuespedes);
                    while( nroHuesped < max &&  nroHuesped >= 0 && nroHuesped != 99){
                        cout << "Seleccione un Huesped [0 - " << listaHuespedes.size() - 1 << "]: ";
                        cin >> nroHuesped;
            
                        //agregar Huesped a listaHospedados
                        if( nroHuesped >= 0 && nroHuesped < max){
                            string nombre = listaHuespedes.at(nroHuesped)->getNombre();
                            string email = listaHuespedes.at(nroHuesped)->getEmail();
                            string pass = listaHuespedes.at(nroHuesped)->getPassword();
                            bool esFinger = listaHuespedes.at(nroHuesped)->getEsFinger();
                            listaHospedados[email] = new DTHuesped(nombre, email, pass, esFinger);
                            cout << "["<< email << "] agregado a la lista. " << endl;
                        }
                    }
                }


            
                
                cout << "Desea hacer los cambios permanentes? [y/n]: ";
                char teclado_yn;
                cin >> teclado_yn;
                if(teclado_yn == 'y'){
                    if(tipoReserva == 'i'){
                        cer->ingresarReserva(checkIn, checkOut, nombreHostal,numHab,emailHuesped, listaHospedados);
                        cout << "Reserva Individual ingresada" << endl;
                    } else {
                        cer->ingresarReserva(checkIn, checkOut, nombreHostal, numHab, emailHuesped, listaHospedados);
                        cout << "Reserva Grupal ingresada" << endl;
                    }

                } else if( teclado_yn == 'n'){
                    //no ingresa
                } else {
                    //valor incorrecto
                }
                cout << endl;
                //confirma o cancela

      

                break;
            }
            case 6: {
                int opcion;
                int numero = 1;
                map<int, string> elegir;
                vector<string> hostales = ch->topHostales();
                if(hostales.empty()) {
                    cout << "No hay hostales en el sistema" << endl;
                    break;
                }
                cout << endl << "TOP HOSTALES:" << endl;
                for (vector<string>::iterator i = hostales.begin(); i != hostales.end(); ++i) {
                    cout << numero << ": " << i->data() << " -> Promedio (" << ch->getPromedio(i->data()) << ")" << endl;
                    elegir.insert(pair<int, string>(numero,i->data()));
                    numero += 1;
                }
                cout << "Seleccione el numero del hostal que quiere conocer los detalles (0 si no quiere):" << endl;
                cin >> opcion; 
                cout << endl;
                if (opcion == 0)
                    break;
                if (opcion > numero) {
                    cout << "Opcion no valida" << endl;
                    break;
                }
                vector<DTCalificacion>* calificaciones = new vector<DTCalificacion>;
                ch->detallesHostal(elegir[opcion], calificaciones);
                if (!calificaciones->empty())
                    for (vector<DTCalificacion>::iterator i = calificaciones->begin(); i != calificaciones->end(); ++i) {
                        cout << "Calificacion: " << i->getPuntaje() << endl;
                        cout << "Comentario: " << i->getComentario() << endl;
                    }
                else 
                    cout << "No tiene calificaciones ni comentarios" << endl;    
                cout << endl;
                delete calificaciones;
                break;
            }
            case 7:{

                unsigned int entrada;
                vector<DTHostal*> listaHostales = ch->listarHostales();
                if(listaHostales.empty()){
                    cout << "No hay Hostales en el Sistema." << endl << endl;
                    break;
                }

                cout << "| Seleccione un Hostal |" << endl;
                imprimirListaHostales(listaHostales);
                //seleccionar hostal
                cout << "Numero de Hostal [0-"<<listaHostales.size()-1<<"]: ";
                cin >> entrada;
                while( entrada < 0 || entrada > listaHostales.size() - 1){
                    cout << "Numero invalido. " << "Ingrese otro numero: " ;
                    cin >> entrada;
                }
                cout << endl;
                string nombreHostal = listaHostales.at(entrada)->getNombre();
                
                string emailHuesped;
                cout << "| Escriba el email del huesped |" << endl;
                cout << "Email: "; cin >> emailHuesped;
                
                while(!cu->emailEnSistema(emailHuesped)){
                    cout << "EL email no existe en el sistema, ingrese otro. " << endl;
                    cout << "Email: "; cin >> emailHuesped;
                }
                if(cer->existeEstadia(emailHuesped, listaHostales.at(entrada)->getNombre())){
                    cout << "Ya existe una estadia activa." << endl;
                    break;
                }
                cout << endl;
                vector<DTReserva*> reservas = cer->listarReservasNoCanceladas(emailHuesped);
                cout << "| Reservas en [" << nombreHostal << "] de ["<< emailHuesped << "] |" << endl;
                imprimirReservas(reservas);

                cout << "Numero de Reserva [0-"<<reservas.size()-1<<"]: ";
                cin >> entrada;
                while( entrada < 0 || entrada > reservas.size() - 1){
                    cout << "Numero invalido. " << "Ingrese otro numero: " ;
                    cin >> entrada;
                }

                DTReserva* res = reservas.at(entrada);

                cer->registrarEstadia(res, emailHuesped);
                cer->cerrarReserva(res->getCodigo());

                cout << "Estadia Registrada." << endl;
                break;
            }
            case 8:{
                unsigned int entrada;
                vector<DTHostal*> listaHostales = ch->listarHostales();
                if(listaHostales.empty()){
                    cout << "No hay Hostales en el Sistema." << endl << endl;
                    break;
                }
                cout << "| Seleccione un Hostal |" << endl;
                imprimirListaHostales(listaHostales);
                //seleccionar hostal
                cout << "Numero de Hostal [0-"<<listaHostales.size()-1<<"]: ";
                cin >> entrada;
                while( entrada < 0 || entrada > listaHostales.size() - 1){
                    cout << "Numero invalido. " << "Ingrese otro numero: " ;
                    cin >> entrada;
                }
                string nombreHostal = listaHostales.at(entrada)->getNombre();
                cout << endl;

                string email;
                cout << "Escriba el email del Huesped: " ; cin >> email;
                
                if( !cer->existeEstadia(email, nombreHostal) ){
                    cout << "No existe ninguna estadia para: " << email << endl;
                    break;
                } else{
                    DTEstadia* est = cer->getEstadia(nombreHostal, email);
                    cer->finalizarEstadia(est->getCodigo(), email);
                }

                cout << "Estadia Finalizada. " << endl;
                break;
            }
            case 9: {
                vector<DTHostal*> hostales = ch->listarHostales();
                if(hostales.empty()) {
                    cout << "No hay Hostales en el Sistema." << endl << endl;
                    break;
                }
                imprimirListaHostales(hostales);
                unsigned int h;
                cout << "Seleccione un hostal: ";
                cin >> h;
                if ((h >= hostales.size()) || (h < 0)) {
                    cout << "Numero no valido" << endl << endl;
                    break;
                }
                vector<DTHostal*>::iterator iter = hostales.begin();
                for(unsigned int i = 0; i < h; i++)
                    ++iter; //iter apunta al hostal que seleccione
                



                cout << "Ingresa el email del huesped: ";
                string mail;
                cin >> mail;

                vector<DTEstadia*> estadiasnofinalizadas = cer->listarEstadiasHostal((*iter)->getNombre());
                if(estadiasnofinalizadas.empty()) {
                    cout << "No hay estadias en el Sistema." << endl << endl;
                    break;
                }
                //imprime de prueba
                for (vector<DTEstadia*>::iterator i = estadiasnofinalizadas.begin(); i != estadiasnofinalizadas.end(); ++i) {
                    (*i)->imprimir();
                    cout << endl;
                }
                //borrar elementos
                for (vector<DTEstadia*>::iterator i = estadiasnofinalizadas.begin(); i != estadiasnofinalizadas.end(); ++i) {
                    if (((*i)->getEmail() != mail) || ((*i)->getSalida() != NULL)) {
                        estadiasnofinalizadas.erase(i);
                    }
                }

                //imprime lo que pode
                if(estadiasnofinalizadas.empty()) {
                    cout << "No hay estadias en el Sistema." << endl << endl;
                    break;
                }
                for (vector<DTEstadia*>::iterator i = estadiasnofinalizadas.begin(); i != estadiasnofinalizadas.end(); ++i) {
                    (*i)->imprimir();
                    cout << endl;
                }



                break;
            }
            case 10: {
                string email_empleado;
                cout << "Ingrese Email del empleado: ";
                cin >> email_empleado;
                if (!cu->emailEnSistema(email_empleado)) {
                    cout << "No existe ese empleado" << endl;
                    break;
                }
                if (cu->trabajaEn(email_empleado) == "No tiene hostal") {
                    cout << "El empleado no trabaja para ningun hostal" << endl;
                    break;
                }
                vector<DTCalificacion>* calificaciones = new vector<DTCalificacion>;
                ch->detallesHostal(cu->trabajaEn(email_empleado), calificaciones);
                for (vector<DTCalificacion>::iterator i = calificaciones->begin(); i != calificaciones->end(); ++i)
                    if (i->getComentado())
                        calificaciones->erase(i);
                int contador = 1;
                int opcion = 0;
                if (!calificaciones->empty()) {
                    for (vector<DTCalificacion>::iterator i = calificaciones->begin(); i != calificaciones->end(); ++i) {
                        cout << "Comentario (" << contador << "): " << i->getComentario() << endl;
                        contador++;
                    }
                    cout << "Seleccione el comentario a responder: ";
                    cin >> opcion;
                    cout << "Respuesta: " << endl;
                    string respuesta;
                    cin.ignore();
                    getline(cin, respuesta);
                    vector<DTCalificacion>::iterator iter = calificaciones->begin();
                    for (int i = 0; i < opcion-1; i++)
                        ++iter; //iter queda apuntando a la calificacion que elegi
                    int codigo_reserva = iter->getCodigoReserva();
                    cer->comentarCalificacion(respuesta, codigo_reserva, iter->getComentario());
                    cout << "Respuesta actualizada" << endl;

                } else
                    cout << "No hay comentarios sin responder" << endl;

                break;
            }
            case 11:{

                vector<DTUsuario*> dtusuarios = cu->listarUsuarios();
                cout << "[Lista de Usuarios ingresados en el sistema]:" << endl;
                cout << "==========================================" << endl;
                int contador=0;
                for ( auto u : dtusuarios){
                    cout <<contador << "- " << u->getEmail()<<endl;
                    contador++;
                }
                if(dtusuarios.size()==0){
                    cout << "No hay usuarios registrados en el sistema." << endl;
                    cout << "==========================================" << endl;
                }else{
                    cout << "==========================================" << endl;
                    int teclado_usuario;
                    cout << "Seleccione un usuario [0-"<<contador-1<<"]:";
                    cin >> teclado_usuario;
                    DTEmpleado* emp = dynamic_cast<DTEmpleado*>(dtusuarios.at(teclado_usuario));
                    if( emp!=nullptr ){
                        cu->ingresarDatosEmpleado(*emp);
                        emp->print();
                        cout << "Trabaja Hostal: "<< cu->trabajaEn(emp->getEmail()) << endl;
                    }else {
                        DTHuesped* hue = dynamic_cast<DTHuesped*>(dtusuarios.at(teclado_usuario));
                        if(hue!=nullptr){
                            cu->ingresarDatosHuesped(*hue);
                            hue->print();
                        }else{
                            cout << "ERROR: No se puedo efectuar el dynamic cast." << endl;
                        }
                    }

                }
                // rompe el menu

                // for (auto x :dtusuarios){
                //     delete x;
                // }
                // dtusuarios.clear();
                break;
            }
            case 12: {
                vector<DTHostal*> hostales = ch->listarHostales();
                if(hostales.empty()) {
                    cout << "No hay Hostales en el Sistema." << endl << endl;
                    break;
                }
                imprimirListaHostales(hostales);
                unsigned int h;
                cout << "Seleccione un hostal: ";
                cin >> h;
                if ((h >= hostales.size()) || (h < 0)) {
                    cout << "Numero no valido" << endl << endl;
                    break;
                }
                vector<DTHostal*>::iterator iter = hostales.begin();
                for(unsigned int i = 0; i < h; i++)
                    ++iter;
                cout << "Nombre: " << (*iter)->getNombre() << endl;
                cout << "Direccion: " << (*iter)->getDireccion() << endl;
                cout << "Telefono: " << (*iter)->getTelefono() << endl;
                cout << "Promedio: " << (*iter)->getPromedio() << endl;
                vector<DTCalificacion>* calificaciones = new vector<DTCalificacion>;
                ch->detallesHostal((*iter)->getNombre(), calificaciones);
                if (!calificaciones->empty()) {
                    cout << "Comentarios: " << endl;
                    for (vector<DTCalificacion>::iterator i = calificaciones->begin(); i != calificaciones->end(); ++i) {
                        cout << "Calificacion: " << i->getPuntaje() << endl;
                        cout << "Comentario: " << i->getComentario() << endl;
                    }
                }
                else 
                    cout << "No tiene comentarios" << endl;    
                vector<DTHabitacion>* habitaciones = new vector<DTHabitacion>;
                ch->obtenerHabitaciones((*iter)->getNombre(), habitaciones);
                if (!habitaciones->empty()) {
                    cout << "Habitaciones: " << endl;
                    for (vector<DTHabitacion>::iterator i = habitaciones->begin(); i != habitaciones->end(); ++i) {
                        i->imprimir();
                        cout << endl;
                    }
                }   
                else
                    cout << "No hay habitaciones" << endl;      
                vector<DTReserva*> reservas = cer->getReservasHostal((*iter)->getNombre());
                if (!reservas.empty()) {
                    cout << "Reservas: " << endl;
                    imprimirReservas(reservas);
                }
                else
                    cout << "No hay reservas" << endl;
///////////////////////////////////////////////////////////////////
                //faltan listar reservas q se han hecho en ese hostal
                delete habitaciones;
                delete calificaciones;
                break;
            }
            case 13:{
                unsigned int entrada;
                vector<DTHostal*> listaHostales = ch->listarHostales();

                if(listaHostales.empty()){
                    cout << "No hay Hostales en el Sistema." << endl << endl;
                    break;
                }
                cout << "| Seleccione un Hostal |" << endl;
                imprimirListaHostales(listaHostales);
                //seleccionar hostal
                cout << "Numero de Hostal [0-"<<listaHostales.size()-1<<"]: ";
                cin >> entrada;
                while( entrada < 0 || entrada > listaHostales.size() - 1){
                    cout << "Numero invalido. " << "Ingrese otro numero: " ;
                    cin >> entrada;
                }
                string nombreHostal = listaHostales.at(entrada)->getNombre();
                cout << endl;
                //obtener reservas del hostal seleccionado
                vector<DTReserva*> listaReservasHostal = cer->getReservasHostal(nombreHostal);
                vector<DTHuesped*> listaHuespedesReserva;
                if(listaReservasHostal.empty()){
                    cout << "No hay ninguna reserva en "<<nombreHostal<< "."<< endl << endl;
                    break;
                }
                cout << "Reservas en " << nombreHostal << ": " << endl;
                imprimirReservas(listaReservasHostal);

                cout << endl;
                break;
            }
            case 14:{
                unsigned int entrada;
                vector<DTHostal*> listaHostales = ch->listarHostales();

                if(listaHostales.empty()){
                    cout << "No hay Hostales en el Sistema." << endl << endl;
                    break;
                }
                cout << "| Seleccione un Hostal |" << endl;
                imprimirListaHostales(listaHostales);
                //seleccionar hostal
                cout << "Numero de Hostal [0-"<<listaHostales.size()-1<<"]: ";
                cin >> entrada;
                while( entrada < 0 || entrada > listaHostales.size() - 1){
                    cout << "Numero invalido. " << "Ingrese otro numero: " ;
                    cin >> entrada;
                }
                string nombreHostal = listaHostales.at(entrada)->getNombre();
                cout << endl;


                vector<DTEstadia*> listaEstadias = cer->listarEstadiasHostal(nombreHostal);

                if(listaEstadias.empty()){
                    cout << " El hostal no tiene ninguna estadia. " << endl;
                    break;
                }

                cout << "| Seleccione una Estadia |"<< endl;
                vector<DTEstadia*>::iterator it;
                int contador = 0;
                for(it = listaEstadias.begin(); it != listaEstadias.end(); ++it){
                    cout << contador << "- ";
                    (*it)->imprimirBasic();
                    cout << endl;
                    contador++;                    
                }
                cout << endl;
                cout << "Numero de Estadia: [0-"<<listaEstadias.size()-1<<"]: " ; cin >> entrada;
                cout << endl;

                DTEstadia* dt = listaEstadias.at(entrada);
                dt->imprimir();

                cout << endl << endl;
                break;
            }
            case 15:{
                unsigned int entrada; char opt;
                vector<DTHostal*> listaHostales = ch->listarHostales();
                if(listaHostales.empty()){
                    cout << "No hay Hostales en el Sistema." << endl << endl;
                    break;
                }
                cout << "| Seleccione un Hostal |" << endl;
                imprimirListaHostales(listaHostales);
                //seleccionar hostal
                cout << "Numero de Hostal [0-"<<listaHostales.size()-1<<"]: ";
                cin >> entrada;
                while( entrada < 0 || entrada > listaHostales.size() - 1){
                    cout << "Numero invalido. " << "Ingrese otro numero: " ;
                    cin >> entrada;
                }
                string nombreHostal = listaHostales.at(entrada)->getNombre();
                cout << endl;

                
                vector<DTReserva*> listaReservasHostal = cer->getReservasHostal(nombreHostal);
                if(listaReservasHostal.empty()){
                    cout << "No hay ninguna reserva en "<<nombreHostal<< "."<< endl << endl;
                    break;
                }
                cout << "Reservas en " << nombreHostal << ": " << endl;
                imprimirBasicReservas(listaReservasHostal);

                unsigned int codigo;
                cout << "Codigo de la Reserva a dar de baja: "; cin >> codigo;
                cout << endl;
                unsigned int pos = traerPosicion(listaReservasHostal, codigo);

                if(pos > listaReservasHostal.size() - 1){
                    cout << "Codigo no valido. Ingrese otro: ";
                    cin >> codigo;
                }
                cout << "Desea confirmar la baja de: |";listaReservasHostal.at(pos)->imprimir(); cout << "| ?" << endl; 
                
                cout << "[y/n]: "; cin >> opt;

                while(opt != 'y' && opt != 'n'){
                    cout << "Valor Incorrecto. Ingrese otro: "; 
                    cin >> opt;
                }

                if(opt == 'y'){
                    cer->darDeBaja(codigo);
                } else if(opt == 'n'){
                    break;
                }
                cout << "Reserva dada de baja." << endl;    
                break;
            }
            case 16:{
                break;
            }
            case 17:{
                break;
            }
            case 18:{
                break;
            }
            case 19:{
                cout << "| Ingrese la fecha |" << endl;
                DTFecha* fecha = ingresarFecha();
                fs->modificarFecha(fecha);
                break;
            }
            case 20:{
                //Liberar memoria
                break;
            }
            default:{
                cout << "ERROR: EL valor " << teclado << " no pertenece al rango [0-19]" << endl;
            }
        }

        if ((teclado > 20) || (teclado < 0))
            cout << endl << "OPCION NO VALIDA" << endl;
    }while(teclado != 20);

    cout << endl;
    return 0;
}
