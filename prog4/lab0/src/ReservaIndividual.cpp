    #include "../include/ReservaIndividual.h"

ReservaIndividual::ReservaIndividual(): Reserva(){
    pagado = false;
}

ReservaIndividual::ReservaIndividual(int codigo, DTFecha *checkIn, DTFecha *checkOut, EstadoReserva estado, Habitacion *habitacion, Huesped *huesped, bool pagado): Reserva(codigo, checkIn, checkOut, estado, habitacion, huesped){
    this->pagado = pagado;
}

float ReservaIndividual::calcularCosto(){
    return (getCheckIn()->cantidadDias(*getCheckOut()))*getHabitacion()->getPrecio();
}

bool ReservaIndividual::esIndividual(){
    return true;
}
bool ReservaIndividual::getPagado(){
    return pagado;
}

void ReservaIndividual::imprimirReserva(){
    cout << "---------------------------------" << endl;
    cout << "TipoReserva: Individual\n";
    cout << "Huesped: " << getHuesped()->getNombre() << endl;
    cout << "Fecha Check In: "; this->getCheckIn()->imprimirFecha();
    cout << "Fecha Check Out: "; this->getCheckOut()->imprimirFecha();
    cout << "Costo: $" << this->calcularCosto();
    cout << endl;
    cout << "Pagado: "; 
    if(pagado)
        cout << "Si" << endl;
    else
        cout << "No" << endl; 
    
}