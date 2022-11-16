// 5320574

#include "../include/pila.h"
#include "../include/colaAvls.h"
#include "../include/avl.h"
#include "../include/utils.h"
#include "../include/info.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


typedef struct repAvl *TAvl;
struct repAvl{
    nat dato;
    nat altura;
    nat cantidad;
    TAvl izq, der;
};

TAvl crearAvl(){ return NULL;}


bool estaVacioAvl(TAvl avl){ return avl == NULL;}

static int max(nat a, nat b){
    if(a <= b)
        return b;
    else 
        return a;
}

static TAvl rightrotation(TAvl y){
    TAvl x = y->izq, t2 = x->der;
    
    //rotar
    x->der = y;
    y->izq = t2;

    //corregir alturas 
    y->altura = max(alturaDeAvl(y->izq), alturaDeAvl(y->der)) + 1;
    x->altura = max(alturaDeAvl(x->izq), alturaDeAvl(x->der)) + 1;

    //corregir cantidades
    y->cantidad = cantidadEnAvl(y->izq) + cantidadEnAvl(y->der) + 1;
    x->cantidad = cantidadEnAvl(x->izq) + cantidadEnAvl(x->der) + 1;

    return x;
}

static TAvl leftrotation(TAvl x){
    TAvl y = x->der, t2 = y->izq;

    //rotar
    y->izq = x;
    x->der = t2;

    //corregir alturas
    x->altura = max(alturaDeAvl(x->izq), alturaDeAvl(x->der)) + 1;
    y->altura = max(alturaDeAvl(y->izq), alturaDeAvl(y->der)) + 1;

    //corregir cantidades
    x->cantidad =  cantidadEnAvl(x->izq) + cantidadEnAvl(x->der) + 1;
    y->cantidad = cantidadEnAvl(y->izq) + cantidadEnAvl(y->der) + 1;

    return y;
}

static int fact(TAvl node){
    return alturaDeAvl(node->izq) - alturaDeAvl(node->der);
}

    
TAvl insertarEnAvl(nat elem, TAvl avl){
    if(avl == NULL){
        avl = new repAvl;
        avl->dato = elem;
        avl->izq = avl->der = NULL;
        avl->altura = 1;
        avl->cantidad = 1;
    } else if(elem > avl->dato) 
        avl->der = insertarEnAvl(elem, avl->der);
      else 
        avl->izq = insertarEnAvl(elem, avl->izq);

    
    avl->altura = 1 + max(alturaDeAvl(avl->izq), alturaDeAvl(avl->der));
    avl->cantidad = 1 + cantidadEnAvl(avl->izq) + cantidadEnAvl(avl->der);

    int bn = fact(avl);

    // LL case : 
    if(bn > 1 && elem < raizAvl(izqAvl(avl)))
        return rightrotation(avl);
    
    // LR Case  
    if (bn > 1 && elem > raizAvl(izqAvl(avl))) {  
        avl->izq = leftrotation(avl->izq);  
        return rightrotation(avl);  
    } 

    // RR case
    if(bn < -1 && elem > raizAvl(derAvl(avl)))
        return leftrotation(avl);

    // RL Case  
    if (bn < -1 && elem < raizAvl(derAvl(avl))) {  
        avl->der = rightrotation(derAvl(avl));  
        return leftrotation(avl);  
    }  

    return avl;

}


TAvl buscarEnAvl(nat elem, TAvl avl){
    if(avl == NULL)
        return NULL;
    if(avl->dato == elem)
        return avl;
    else if(avl->dato < elem)
        return buscarEnAvl(elem, avl->der);  
    else    
        return buscarEnAvl(elem, avl->izq);
}


nat raizAvl(TAvl avl){ return avl->dato;}

TAvl izqAvl(TAvl avl){return avl->izq;}

TAvl derAvl(TAvl avl){return avl->der;}

nat cantidadEnAvl(TAvl avl){
    if(avl == NULL)
        return 0;
    else
        return avl->cantidad;
}

nat alturaDeAvl(TAvl avl){
    if(avl == NULL)
        return 0;
    else 
        return avl->altura;
}


static void insert(TAvl &avl, TIterador &iter){
    if(avl != NULL){
        insert(avl->izq, iter);
        iter = agregarAIterador(avl->dato, iter);
        insert(avl->der, iter);
    }
}

TIterador enOrdenAvl(TAvl avl){
    TIterador iter = crearIterador();
    insert(avl, iter);
    iter = reiniciarIterador(iter);
    return iter;
}

TAvl arregloAAvl(nat *elems, nat n){
    TAvl avl = crearAvl();
    nat i = 0;
    while(i < n){
        avl = insertarEnAvl(elems[i], avl);
        i++;
    }
    return avl;
}



static TAvl build(nat h){
    if(h == 0)
        return NULL;
    else if(h == 1){
        TAvl nod = new repAvl;
        nod->dato = 1;
        nod->izq = nod->der = NULL;
        nod->altura = nod->cantidad = 1;
        return nod;
    }
    else{

        TAvl nod = new repAvl;
        nod->izq = build(h-1);
        nod->der = build(h-2);
        nod->altura = max(alturaDeAvl(nod->izq), alturaDeAvl(nod->der))+ 1;
        nod->cantidad = cantidadEnAvl(nod->izq) + cantidadEnAvl(nod->der) + 1;
        return nod;

    }
}

static void llenar(TAvl &avl, nat n){
    avl->dato = cantidadEnAvl(avl->izq) + n + 1;
    if(avl->izq != NULL) 
        llenar(avl->izq, n);
    if(avl->der != NULL) 
        llenar(avl->der, avl->dato);
}


TAvl avlMin(nat h){
    TAvl res = crearAvl();
    res = build(h);
    nat elem = 0;
    llenar(res, elem);
    return res;
}


void imprimirAvl(TAvl avl){ 
    if(avl != NULL){  
        TAvl cursor = avl;
        TColaAvls q = crearColaAvls();
        TPila s = crearPila(cursor->cantidad + cursor->altura);
        q = encolar(cursor, q);
        TAvl limit = NULL;
        q = encolar(limit, q);
        while(!estaVaciaColaAvls(q)){
            
            cursor = frente(q);
            q = desencolar(q);
            s = apilar(cursor->dato, s);

             //encolar hijos
            if(cursor->der != NULL)
                q = encolar(cursor->der, q);
            if(cursor->izq != NULL)
                q = encolar(cursor->izq, q);

                
            if(frente(q) == limit){ 
                q = desencolar(q);
                if(!estaVaciaColaAvls(q)){ 
                    s = apilar(0, s);
                    q = encolar(limit, q);
                }
            }           
        }
        while(!estaVaciaPila(s)){
            if(cima(s) == 0)
                printf("\n");
            else{ 
                printf("%d",cima(s));
                printf(" ");
            }
            s = desapilar(s);
        }
        printf("\n");
        liberarColaAvls(q);
        liberarPila(s);
    }
}

void liberarAvl(TAvl avl){
    if(avl != NULL){
        liberarAvl(avl->izq);
        liberarAvl(avl->der);
        delete avl;
    }
}
