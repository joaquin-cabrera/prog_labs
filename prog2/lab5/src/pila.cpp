//5320574

#include "../include/pila.h"
#include "../include/utils.h"
#include "../include/info.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct repPila *TPila;
typedef struct nodo *Pnodo;

struct nodo{
    nat elem;
    Pnodo ant, sig;
};

struct repPila{
    Pnodo ini, fin, tope;
};


TPila crearPila(nat tamanio){
    TPila res = new repPila;
    res->tope = NULL;
    res->ini = new nodo;
    res->fin = res->ini;
    res->ini->ant = res->ini->sig = NULL;
    if(tamanio > 1){
        Pnodo cursor = res->ini;
        nat i = 1;
        Pnodo nod = NULL;
        while(i < tamanio){
            nod = new nodo;
            nod->ant = cursor;
            nod->sig = NULL;
            cursor->sig = nod;
            res->fin = nod;
            cursor = nod;
            i++;
        }
    }
    return res;
}

TPila apilar(nat num, TPila p){
    if(p->tope == NULL){
        p->tope = p->ini;
        p->tope->elem = num;
    } else if (p->tope->sig != NULL){
        p->tope = p->tope->sig;
        p->tope->elem = num;
    }
    return p;
}


TPila desapilar(TPila p){
    if(p->tope != NULL){
        p->tope = p->tope->ant;
    }
    return p;
}

void liberarPila(TPila p){
    p->tope = p->ini;
    Pnodo cursor = p->ini;
    while(cursor != NULL){

        cursor = cursor->sig;
        delete p->tope;
        p->tope = cursor; 
        
    }
    delete p;
}

bool estaVaciaPila(TPila p){
        return p->tope == NULL;
} 
 

bool estaLlenaPila(TPila p){
    if(p->tope == NULL)
        return false;
    else 
        return p->tope->sig == NULL;
}

nat cima(TPila p){
    return p->tope->elem;
}