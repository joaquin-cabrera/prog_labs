#ifndef IUSUARIO_H
#define IUSUARIO_H

#include "Empleado.h"
#include "Huesped.h"
#include "../Datatypes/DTUsuario.h"
#include "../Datatypes/DTEmpleado.h"
#include "../Datatypes/DTHuesped.h"
#include "controladorHostal.h"

#include <map> 
#include <vector>

class IUsuario{
    public:
        virtual vector<DTUsuario*> listarUsuarios() = 0;
        virtual void ingresarDatosEmpleado(DTEmpleado) = 0;
        virtual void ingresarDatosHuesped(DTHuesped) = 0;
        virtual bool emailDuplicado() = 0;
        virtual bool emailEnSistema(string) = 0;
        virtual void reingresarEmail(string) = 0;
        virtual void ingresarEmpleado() = 0;
        virtual void ingresarHuesped() = 0;
        virtual void liberarMemoria() = 0;
        virtual vector<DTHuesped*> listarHuespedes() = 0;
        virtual string trabajaEn(string empleado) = 0;
        virtual void listarNoEmpleadosDelHostal(string hostal, vector<DTEmpleado*>* no_empleados) = 0;
        virtual void asignarEmpleado(string emailEmpleado, Cargo cargo, string nombreHostal) = 0;
};

#endif