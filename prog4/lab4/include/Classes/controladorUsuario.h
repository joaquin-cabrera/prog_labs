#ifndef CONTROLADORUSUARIO_H
#define CONTROLADORUSUARIO_H

#include "IUsuario.h"



class controladorUsuario : public IUsuario{
    private:
        map<string, Usuario*> usuarios; /* coleccion de usuarios */
        DTUsuario * dtuser;
        static controladorUsuario* instancia;
        controladorUsuario(); /* contructor privado singleton*/
    public:
        static controladorUsuario* getInstance();
        ~controladorUsuario();

        /*crea copia sin compartir memoria*/
        void ingresarDatosEmpleado(DTEmpleado);

        vector<DTUsuario*> listarUsuarios();
        vector<DTHuesped*> listarHuespedes();
        

        /*crea copia sin compartir memoria*/
        void ingresarDatosHuesped(DTHuesped);
        bool emailDuplicado();
        bool emailEnSistema(string);
        void reingresarEmail(string email);
        void ingresarEmpleado();
        void ingresarHuesped();
        void liberarMemoria();
        void asignarEmpleado(string emailEmpleado, Cargo cargo, string nombreHostal);
        Usuario* getUser(string);
        string trabajaEn(string empleado);

        void listarNoEmpleadosDelHostal(string hostal, vector<DTEmpleado*>* no_empleados);

};


#endif