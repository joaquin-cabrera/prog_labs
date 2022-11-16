// 5320574
#include "../include/binario.h"
#include "../include/cadena.h"
#include "../include/utils.h"
#include "../include/info.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef repBinario *TBinario;

struct repBinario
{
    TInfo dato;
    TBinario izq;
    TBinario der;
};

TBinario crearBinario() { return NULL; }

TBinario insertarEnBinario(TInfo i, TBinario b){
    if (b == NULL){
        b = new repBinario;
        b->dato = i;
        b->izq = b->der = NULL;
    }
    else if (natInfo(b->dato) < natInfo(i)) 
        b->der = insertarEnBinario(i, b->der);
    else {
        b->izq = insertarEnBinario(i, b->izq);} 
    return b;
}


TInfo mayor(TBinario b){   
    if(b->der == NULL) return b->dato;
    else return(mayor(b->der)); 
}

TBinario removerMayor(TBinario b){

    if(b->der != NULL) b->der = removerMayor(b->der);
    else {
        TBinario aux = b;
        b = b->izq;
        delete aux;
    }
    return b;
 
}

static bool esHoja(TBinario b);

static bool esHoja(TBinario b){return b->izq == NULL && b->der == NULL;}

TBinario removerDeBinario(nat elem, TBinario b){ 
    if(b == NULL) return b;
    else if(natInfo(b->dato) < elem) b->der = removerDeBinario(elem, b->der);
    else if(natInfo(b->dato) > elem) b->izq = removerDeBinario(elem, b->izq);
    else{ 
        //caso 1
        if(esHoja(b)){
            liberarInfo(b->dato);
            delete b;
            b = NULL;
            return b;
        } 
        
        //caso 2
        if(b->izq == NULL && b->der != NULL){
            TBinario aux = b;
            b = b->der;
            liberarInfo(aux->dato);
            delete aux;
            return b;
        }
        if(b->izq != NULL && b->der == NULL){
            TBinario aux = b;
            b = b->izq;
            liberarInfo(aux->dato);
            delete aux;
            return b;
        }

        //caso 3
        if(b->izq != NULL && b->der != NULL){
            liberarInfo(b->dato);
            b->dato = mayor(b->izq);
            b->izq = removerMayor(b->izq);
            return b;
        }

    
    }
    return b;
}

void liberarBinario(TBinario b){
    if(b != NULL){
        liberarBinario(b->izq);
        liberarBinario(b->der);
        liberarInfo(b->dato);
        delete b;
    }
} 

bool esVacioBinario(TBinario b) { return b == NULL; }





static int prof(TBinario b, bool &res) {
  if (b == NULL) 
    return 0; 
  int izq, der;
  izq = prof(b->izq, res);
  der = prof(b->der, res);
  int dif = abs(izq - der);
  if (dif > 1) 
    res = false;

  if (izq > der) 
    return izq + 1;
  else 
    return der + 1;
}

bool esAvl(TBinario b){
  bool res = true;
  prof(b , res);
  return res;
}

TInfo raiz(TBinario b) { return (b->dato); }

TBinario izquierdo(TBinario b) { return (b->izq); }

TBinario derecho(TBinario b) { return (b->der); }

TBinario buscarSubarbol(nat elem, TBinario b){

    if(b == NULL) return NULL;

    if(natInfo(b->dato) == elem) {
        TBinario res = b;
        return res;
    }
    else if(natInfo(b->dato) < elem){
        return buscarSubarbol(elem, b->der);
    } else {
        return buscarSubarbol(elem, b->izq);
    }
}


static nat max(nat a, nat b);
static nat max(nat a, nat b){
    if (a >= b){
        return a;
    }
    else{
        return b;
    }
}

nat alturaBinario(TBinario b){
    if(b == NULL) return 0; 
    return max(alturaBinario(b->izq), alturaBinario(b->der)) + 1;
}

nat cantidadBinario(TBinario b){
    if(b == NULL) return 0;
    return 1 + cantidadBinario(b->izq) + cantidadBinario(b->der);
}


static void sumainodos(nat &i, TBinario &b, double &sum){
    if(b != NULL){ 
        sumainodos(i, b->der, sum);
        if(i > 0){
            if(realInfo(b->dato) > 0){ 
                sum = sum + realInfo(b->dato);
                i--;
            }
        }
        sumainodos(i, b->izq, sum);
    }
}

double sumaUltimosPositivos(nat i, TBinario b){
    if (i == 0) return 0;
    else {
        double sum = 0;
        sumainodos(i , b, sum);
        return sum;
    }
}
    

static void aux1(TBinario &b, TCadena &cad){
    if(b != NULL){
        aux1(b->izq, cad);
        insertarAlFinal(copiaInfo(b->dato), cad);
        aux1(b->der, cad);
    }
}

TCadena linealizacion(TBinario b){
    TCadena cad = crearCadena();
    aux1(b, cad);
    return cad;
}

static void insmenor(double &cota, TBinario &b, TBinario &res){
    if(b != NULL){
        if(realInfo(b->dato) < cota){ 
            res = insertarEnBinario(copiaInfo(b->dato), res); 
        }
            insmenor(cota, b->izq, res);
            insmenor(cota, b->der, res); 
    }
}

TBinario menores(double cota, TBinario b){
    TBinario res = crearBinario();
    insmenor(cota, b, res);
    return res;
}




static void printdato(TInfo i){
    ArregloChars imp = infoATexto(i);
    printf(imp);
    delete [] imp;
    printf("\n");
}

static void printguiones(int lvl){
    int i = 1;
    while(i < lvl){
        printf("-");
        i++;
    }
}

static void print2(TBinario root, int lvl){
    if(root != NULL){
        lvl++;
        print2(root->der, lvl);
        printguiones(lvl);
        printdato(root->dato);
        print2(root->izq, lvl);
    }
}

void imprimirBinario(TBinario b){
    int lvl = 0;
    printf("\n");
    print2(b, lvl);      
}


