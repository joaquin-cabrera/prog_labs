// 5320574

#include "../include/avl.h"
#include "../include/colaAvls.h"
#include "../include/utils.h"
#include "../include/info.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct repColaAvls *TColaAvls;
typedef struct pos *Ppos;
struct repColaAvls{
    Ppos frente, back;
};

struct pos{
    TAvl nd;
    Ppos sig;
};


TColaAvls crearColaAvls(){ 
    TColaAvls res = new repColaAvls;
    res->frente = res->back = NULL;
    return res;
}

TColaAvls encolar(TAvl avl, TColaAvls c){

    //crear pos nueva
    Ppos nod = new pos;
    nod->nd = avl;
    nod->sig = NULL;

    if(estaVaciaColaAvls(c)){
        c->frente = nod;
        c->back = nod;
    } else {
        c->back->sig = nod;
        c->back = nod;

    }

    return c;
    
}


TColaAvls desencolar(TColaAvls c){ 
    if(!estaVaciaColaAvls(c)){ 
        Ppos aux = c->frente;
        if(c->frente->sig != NULL){ 
            c->frente = c->frente->sig;
        } else {
            c->frente = NULL;
            c->back = NULL;
        }
        delete aux;
    }
    return c;
}


void liberarColaAvls(TColaAvls c){
    Ppos a_borrar;
    while(c->frente != NULL){
        a_borrar = c->frente;
        c->frente = c->frente->sig;
        delete a_borrar;
    }
    delete c;
}
  
bool estaVaciaColaAvls(TColaAvls c){ return c->frente ==  NULL;}

TAvl frente(TColaAvls c){
    return c->frente->nd; 
}
    
