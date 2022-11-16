//5320574

#include "../include/grafo.h"
#include "../include/utils.h"
#include "../include/info.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct vertice *Pvertice;

struct vertice{
    nat elem, altura;
    double edgevalue;
    Pvertice der,izq;
};

struct repGrafo{  
    Pvertice * array;
    int par, maxpar, cap;
};

static int max(nat a, nat b){
    if(a <= b)
        return b;
    else 
        return a;
}

static nat alturaDeAvl(Pvertice avl){
    if(avl == NULL)
        return 0;
    else 
        return avl->altura;
}

static int fact(Pvertice node){
    return alturaDeAvl(node->izq) - alturaDeAvl(node->der);
}

static nat raizAvl(Pvertice avl){
     return avl->elem; 
}

static Pvertice izqAvl(Pvertice avl){

    return avl->izq; }

static Pvertice derAvl(Pvertice avl){
    return avl->der; }  

static Pvertice rightrotation(Pvertice y){
    Pvertice x = y->izq, t2 = x->der;
    
    //rotar
    x->der = y;
    y->izq = t2;

    //corregir alturas 
    y->altura = max(alturaDeAvl(y->izq), alturaDeAvl(y->der)) + 1;
    x->altura = max(alturaDeAvl(x->izq), alturaDeAvl(x->der)) + 1;
    return x;
}

static Pvertice leftrotation(Pvertice x){
    Pvertice y = x->der, t2 = y->izq;

    //rotar
    y->izq = x;
    x->der = t2;

    //corregir alturas
    x->altura = max(alturaDeAvl(x->izq), alturaDeAvl(x->der)) + 1;
    y->altura = max(alturaDeAvl(y->izq), alturaDeAvl(y->der)) + 1;

    return y;
}

static Pvertice insertarVecino(nat elem, Pvertice avl, double d){
    if(avl == NULL){
        avl = new vertice;
        avl->elem = elem;
        avl->izq = avl->der = NULL;
        avl->altura = 1;
        avl->edgevalue = d;
    } else if(elem > avl->elem) 
        avl->der = insertarVecino(elem, avl->der, d);
      else 
        avl->izq = insertarVecino(elem, avl->izq, d);


    avl->altura = 1 + max(alturaDeAvl(avl->izq), alturaDeAvl(avl->der));

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

static Pvertice buscarEnAvl(nat elem, Pvertice avl){
    if(avl == NULL)
        return NULL;
    if(avl->elem == elem)
        return avl;
    else if(avl->elem < elem)
        return buscarEnAvl(elem, avl->der);  
    else    
        return buscarEnAvl(elem, avl->izq);
}

static void liberarVecinos(Pvertice avl){
    if(avl != NULL){
        liberarVecinos(avl->izq);
        liberarVecinos(avl->der);
        delete avl;
    }
}

static void insert(Pvertice &avl, TIterador &iter){
    if(avl != NULL){
        insert(avl->izq, iter);
        iter = agregarAIterador(avl->elem, iter);
        insert(avl->der, iter);
    }
}

static TIterador enOrdenVecinos(Pvertice avl){
    TIterador iter = crearIterador();
    insert(avl, iter);
    iter = reiniciarIterador(iter);
    return iter;
}



TGrafo crearGrafo(nat N, nat M){

    TGrafo gp = new repGrafo;
    gp->array = new Pvertice[N+1];
    gp->par = 0;
    gp->maxpar = M;
    gp->cap = N;

    for(nat i = 1; i <= N; i++)
        gp->array[i] = NULL;
    return gp;
}

nat cantidadVertices(TGrafo g){ return g->cap; }

bool hayMParejas(TGrafo g){ return g->par == g->maxpar; }

TGrafo hacerVecinos(nat v1, nat v2, double d, TGrafo g){
    g->par++;
    g->array[v1] = insertarVecino(v2, g->array[v1], d);
    g->array[v2] = insertarVecino(v1, g->array[v2], d);
    return g;
}

bool sonVecinos(nat v1, nat v2, TGrafo g){  return buscarEnAvl(v2, g->array[v1]) != NULL; }

double distancia(nat v1, nat v2, TGrafo g){ return buscarEnAvl(v2, g->array[v1])->edgevalue; }

TIterador vecinos(nat v, TGrafo g){ 
    TIterador iter = enOrdenVecinos(g->array[v]);
    return iter;
}

void liberarGrafo(TGrafo g){
    for(int i = 1; i <= g->cap; i++)
        liberarVecinos(g->array[i]);    

    delete [] g->array;
    delete g;
}