#ifndef IOBSERVER_H
#define IOBSERVER_H

#include "../../include/Datatypes/DTEstadia.h"

class IObserver{
    public:
        virtual void notificar(Estadia* estadia) = 0;
};

#endif