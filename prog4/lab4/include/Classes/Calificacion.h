#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "../Datatypes/DTFecha.h"
#include "../Datatypes/DTCalificacionIdentificable.h"
#include "../Datatypes/DTCalificacion.h"
#include "Comentario.h"
#include <iostream>


class Calificacion{
    private:
        int puntaje;
        std::string comentario;
        DTFecha* fecha;
        Comentario* respuesta;
    public:
        Calificacion();
        Calificacion(int puntaje, std::string comentario, DTFecha* fecha);
        ~Calificacion();
        void preEliminarCalificacion();
        bool tieneComentario();
        DTCalificacionIdentificable getDTCalificacionIdentificable();
        bool refiereAlHostal(std::string name);
        int getPuntaje();
        DTFecha* getFecha();
        std::string getComentario();
        DTCalificacion getDTCalificacion();
        void comentarCalificacion(string respuesta);
};

#endif