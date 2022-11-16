#ifndef INFOHOSTAL_H
#define INFOHOSTAL_H

#include "DTCalificacion.h"
#include "DTHabitacion.h"
#include "DTReserva.h"
#include <iostream>

class InfoHostal{
    private:
        std::string nombre, direccion, telefono;
        float promedio;
        // resolver las colecciones
    public:
        InfoHostal();
        InfoHostal(std::string nombre, std::string direccion, std::string telefono, float promedio);
        ~InfoHostal();
        std::string getNombre();
        std::string getDireccion();
        std::string getTelefono();
        float getPromedio();
};

#endif