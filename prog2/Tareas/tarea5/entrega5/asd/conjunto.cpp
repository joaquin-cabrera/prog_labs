// 5320574

#include "../include/avl.h"
#include "../include/conjunto.h"
#include "../include/iterador.h"
#include "../include/utils.h"
#include "../include/info.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct repConjunto *TConjunto;

struct repConjunto{
    TAvl root;
};


TConjunto crearConjunto(){
    TConjunto res = new repConjunto;
    res->root = NULL;
    return res;
}

TAvl rootset(TConjunto c){
    return c->root;
}

TConjunto singleton(nat elem){
    TConjunto res = crearConjunto();
    res->root = insertarEnAvl(elem, res->root);
    return res;
}


static void unir(TAvl &res, TAvl c){
    if(c != NULL){

        if( buscarEnAvl(raizAvl(c), res) == NULL )
            res = insertarEnAvl(raizAvl(c), res);

        unir(res, derAvl(c));
        unir(res, izqAvl(c));
    }
}

TConjunto unionDeConjuntos(TConjunto c1, TConjunto c2){
    TConjunto res = crearConjunto();
    unir(res->root, c1->root);
    unir(res->root, c2->root);
    return res;
}



static void diff(TAvl &res, TAvl c1, TAvl c2){
    if(c1 != NULL){

        if( buscarEnAvl(raizAvl(c1), c2) == NULL )   
            res = insertarEnAvl(raizAvl(c1), res);
        
        diff(res, izqAvl(c1), c2);
        diff(res, derAvl(c1), c2);

    }
}

TConjunto diferenciaDeConjuntos(TConjunto c1, TConjunto c2){
    TConjunto res = crearConjunto();
    diff(res->root, c1->root, c2->root);
    return res;
}

bool perteneceAConjunto(nat elem, TConjunto c){
    return buscarEnAvl(elem, c->root) != NULL;
}

bool estaVacioConjunto(TConjunto c){ return c->root== NULL;}

nat cardinalidad(TConjunto c){
    return cantidadEnAvl(c->root);
}

TConjunto arregloAConjunto(nat *elems, nat n){
    TConjunto res = crearConjunto();
    res->root = arregloAAvl(elems, n);
    return res;
}

TIterador iteradorDeConjunto(TConjunto c){
    return enOrdenAvl(c->root); 
}

void liberarConjunto(TConjunto c){
    liberarAvl(c->root);
    delete c;
}