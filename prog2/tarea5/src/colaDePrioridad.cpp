// 5320574


#include "../include/colaDePrioridad.h"
#include "../include/utils.h"
#include "../include/info.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct repCP *TColaDePrioridad;

struct celda{
    nat epos;
    double valor;
};

struct buck{
    int elem, vpos;
};

struct repCP{
    celda * Parray;
    buck * Earray;
    int tope, cap;
};



static void swap(int i, int j, TColaDePrioridad cp){
    
    //actualizar nuevas posiciones
    int elem1 = cp->Parray[i].epos, elem2 = cp->Parray[j].epos;
    cp->Earray[elem1].vpos = j;
    cp->Earray[elem2].vpos = i;

    //intercambiar posiciones
    celda aux = cp->Parray[i];
    cp->Parray[i] = cp->Parray[j];
    cp->Parray[j] = aux;
}


static int padre(int i){ return i/2; }
static int izq(int i){ return 2*i; }
static int der(int i){ return 2*i + 1; }


TColaDePrioridad crearCP(nat N){
    TColaDePrioridad cp = new repCP;
    cp->Earray = new buck[N+1];
    cp->Parray = new celda[N+1];
    cp->cap = N;
    cp->tope = 0;
    nat i = 1;
    while(i <= N){
        cp->Earray[i].vpos = -1;
        cp->Earray[i].elem = -1;
        i++;
    }
    return cp;
}
    
nat rangoCP(TColaDePrioridad cp){  return cp->cap;  }

static bool menorqpadre(TColaDePrioridad cp, nat i){
    return cp->Parray[i].valor < cp->Parray[padre(i)].valor;
}

static TColaDePrioridad bup(TColaDePrioridad cp, nat i){

    while(i != 1 && menorqpadre(cp, i)){
        swap(i, padre(i), cp);
        i = padre(i);
    }

    return cp;
}


TColaDePrioridad insertarEnCP(nat elem, double valor, TColaDePrioridad cp){ 
    cp->tope++;

    cp->Earray[elem].elem = elem;
    cp->Earray[elem].vpos = cp->tope;

    cp->Parray[cp->tope].valor = valor;
    cp->Parray[cp->tope].epos = elem;

    int i = cp->tope;
    cp = bup(cp, i);

    
    return cp;
}

bool estaVaciaCP(TColaDePrioridad cp){ return cp->tope == 0; }

nat prioritario(TColaDePrioridad cp){
    nat i = cp->Parray[1].epos;
    return cp->Earray[i].elem;
}



static int menorhijo(TColaDePrioridad cp, int i){

    double lp = cp->Parray[izq(i)].valor, min = izq(i);

    if(der(i) <= cp->tope){
        double rp = cp->Parray[der(i)].valor;

        if(lp > rp)
            min = der(i);
    } 
    return min;
}

static bool mayorqhijo(TColaDePrioridad cp, nat i){
    return cp->Parray[i].valor > cp->Parray[menorhijo(cp, i)].valor;
}


TColaDePrioridad eliminarPrioritario(TColaDePrioridad cp){

    cp->Earray[ cp->Parray[1].epos].elem = -1;
    cp->Earray[ cp->Parray[1].epos ].vpos = -1;
    
    swap(1, cp->tope, cp );
    cp->tope--;
    if(cp->tope > 1){
        
        int i = 1;
        while(i <= padre(cp->tope) && mayorqhijo(cp, i)){

            int j =  menorhijo( cp , i );
            swap(i,  j  , cp);
            i =  j;

        }
    } 
    return cp; 
}


bool estaEnCP(nat elem, TColaDePrioridad cp){ return cp->Earray[elem].elem != -1; }

double prioridad(nat elem, TColaDePrioridad cp){ 
    int i = cp->Earray[elem].vpos;
    return cp->Parray[i].valor;
}



TColaDePrioridad actualizarEnCP(nat elem, double valor, TColaDePrioridad cp){

    int i = cp->Earray[elem].vpos;

    if(valor < cp->Parray[i].valor){

        cp->Parray[i].valor = valor;
        cp = bup(cp, i);
    
    } 
    else if (valor > cp->Parray[i].valor){
        
        cp->Parray[i].valor = valor;

        while(i <= padre(cp->tope) && mayorqhijo(cp, i) ){

            int j =  menorhijo( cp, i );
            swap(i,  j  , cp);
            i =  j;

        }
    }
    return cp;
}


void liberarCP(TColaDePrioridad cp){
    delete [] cp->Earray;
    delete [] cp->Parray;
    delete cp;
}
