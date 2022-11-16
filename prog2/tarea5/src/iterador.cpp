//5320574
#include "../include/iterador.h"
#include "../include/utils.h"
#include "../include/info.h"

#include <assert.h>
#include <stdlib.h>

typedef struct nodoIt *PNodoIt;

typedef struct repIterador *TIterador;


struct nodoIt{
    nat elem;
    PNodoIt sig;
} ;

struct repIterador {
    PNodoIt inicio, actual, fin;
    bool bloqueado;
} ;

TIterador crearIterador(){
    TIterador res = new repIterador;
    res->actual = res->inicio = res->fin = NULL;
    res->bloqueado = false;
    return res;
}

TIterador agregarAIterador(nat elem, TIterador iter){
    if(!iter->bloqueado){ 

        PNodoIt nod = new nodoIt;
        nod->elem = elem;   
        nod->sig = NULL;

        if(iter->fin != NULL){ 
            iter->fin->sig = nod;
            iter->fin = nod; 
        }  else   
            iter->inicio = iter->fin = nod;
    }
    return iter;
}

TIterador reiniciarIterador(TIterador iter){
    if(iter->inicio != NULL){
        iter->actual = iter->inicio;
    }
    iter->bloqueado = true;
    return iter;
}

TIterador avanzarIterador(TIterador iter){
    if(estaDefinidaActual(iter)){
        iter->actual = iter->actual->sig;
    }
    return iter;
}

nat actualEnIterador(TIterador iter){
    return iter->actual->elem;
}

bool estaDefinidaActual(TIterador iter){
    return iter->actual != NULL;
}

void liberarIterador(TIterador iter){
    PNodoIt cursor = iter->inicio;
    iter->actual = iter->inicio;
    while(cursor != NULL){

        cursor = cursor->sig;
        delete iter->actual;
        iter->actual = cursor;

    }
  delete iter;
}