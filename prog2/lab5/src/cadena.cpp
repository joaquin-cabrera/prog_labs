
/* 5320574 */

#include "../include/cadena.h"
#include "../include/info.h"
#include "../include/utils.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

struct nodo {
    TInfo dato;
    TLocalizador anterior;
    TLocalizador siguiente;
};

struct repCadena {
    TLocalizador inicio;
    TLocalizador final;
};

bool esLocalizador(TLocalizador loc) {return loc != NULL; }

TCadena crearCadena() {
    TCadena res = new repCadena;
    res->inicio = res->final = NULL;
    return res;    
}

void liberarCadena(TCadena cad) {
    TLocalizador a_borrar;
    while (cad->inicio != NULL) {
        a_borrar = cad->inicio;
        cad->inicio = cad->inicio->siguiente;
        liberarInfo(a_borrar->dato);
        delete a_borrar;
    }
    delete cad;
}

bool esVaciaCadena(TCadena cad) {
    return cad->inicio == NULL;}

TLocalizador inicioCadena(TCadena cad){
    TLocalizador res;
    if (esVaciaCadena(cad)) {
       res = NULL;
    } else {
       res = cad->inicio;
       }
    return res;
}

TLocalizador finalCadena(TCadena cad){
  TLocalizador q;
    if (esVaciaCadena(cad)) {
       q = NULL;
    } else {
       q = cad->final;
    } 
  return q;
}

TInfo infoCadena(TLocalizador loc, TCadena cad){return loc->dato;}

TLocalizador siguiente(TLocalizador loc, TCadena cad){
    TLocalizador res;
    if (esFinalCadena(loc, cad)){
        res = NULL;
    } else {
        res = loc->siguiente;
    }
    return res;
}

TLocalizador anterior(TLocalizador loc, TCadena cad){
    TLocalizador q = NULL;
    if (esInicioCadena(loc, cad)){
        return q;
    } else {
        q = loc->anterior;
    }
    return q;
}

bool esFinalCadena(TLocalizador loc, TCadena cad){
    if (esVaciaCadena(cad) || loc == NULL){
        return false;
    } else { 
        return loc->siguiente == NULL;  
    }
}

bool esInicioCadena(TLocalizador loc, TCadena cad){
     if (esVaciaCadena(cad) || loc == NULL){
        return false;
    } else { 
        return loc->anterior == NULL;
    }
}

TCadena insertarAlFinal(TInfo i, TCadena cad){
    TLocalizador nod = new nodo;
    nod->dato = i;
    nod->siguiente = NULL;
    if (esVaciaCadena(cad)){
        cad->inicio = cad->final = nod;
        nod->anterior = NULL;
    } else {
        nod->anterior = cad->final;
        nod->anterior->siguiente = nod;
        cad->final = nod;
    }
    return cad;
}

TCadena insertarAntes(TInfo i, TLocalizador loc, TCadena cad){
    TLocalizador q = new nodo;
    q->dato = i;
    if (!esInicioCadena(loc, cad)){
        TLocalizador p = loc->anterior;
        q->siguiente = loc;
        q->anterior = p;
        p->siguiente = q;
        loc->anterior = q;
    } else {
        cad->inicio->anterior = q;
        q->siguiente = cad->inicio;
        q->anterior = NULL;        
        cad->inicio = q;
    }
    return cad;
}

TCadena removerDeCadena(TLocalizador loc, TCadena cad){  
    if(loc->anterior != NULL && loc->siguiente != NULL){
        loc->anterior->siguiente = loc->siguiente;
        loc->siguiente->anterior = loc->anterior;
    }
    if (loc->anterior == NULL && loc->siguiente != NULL){
        cad->inicio = loc->siguiente;
        loc->siguiente->anterior = NULL;
    }
    if (loc->siguiente == NULL && loc->anterior != NULL){
        cad->final = loc->anterior;
        loc->anterior->siguiente = NULL;
    }
    if (loc->siguiente == NULL && loc->anterior == NULL){
        cad->inicio = cad->final = NULL;
    }
    liberarInfo(loc->dato);
    delete loc;   
    return cad;
}

void imprimirCadena(TCadena cad){
    TLocalizador q;
    q = cad->inicio;
    while (q != NULL){ 
        ArregloChars imp = infoATexto(infoCadena(q, cad));
        printf(imp);
        delete [] imp;
        q = q->siguiente;  
        
    } 
    printf("\n");
}

TLocalizador kesimo(nat k, TCadena cad){
    TLocalizador q;
    nat i = 1;
    if (k == 0){
        q = NULL;
    } else { q = cad->inicio;}   
    while (q != NULL && i<k) {
       i++;    
       q = q->siguiente;
    }return q;
}

bool localizadorEnCadena(TLocalizador loc, TCadena cad){
    TLocalizador cursor = inicioCadena(cad);
    while (esLocalizador(cursor) && (cursor != loc ))
      cursor = siguiente(cursor, cad);
    return esLocalizador(cursor);
}

bool precedeEnCadena(TLocalizador loc1, TLocalizador loc2, TCadena cad){
    bool res;
    res = localizadorEnCadena(loc1, cad);
    if (res) {
        TLocalizador cursor = loc1;
        while (esLocalizador(cursor) && (cursor != loc2))
          cursor = siguiente(cursor, cad);
        res = esLocalizador(cursor);
    }
    return res;
 }
 

TCadena insertarSegmentoDespues(TCadena sgm, TLocalizador loc, TCadena cad) {

  if (esVaciaCadena(cad)){
      cad->inicio = sgm->inicio;
      cad->final = sgm->final;
  } else { 
      if(!esVaciaCadena(sgm)){
          if (esFinalCadena(loc, cad)){

             loc->siguiente = sgm->inicio;
             sgm->inicio->anterior = loc;
             cad->final = sgm->final;  

          } else {


             TLocalizador q = loc->siguiente;
             loc->siguiente = sgm->inicio;
             q->anterior = sgm->final;
             sgm->inicio->anterior = loc;
             sgm->final->siguiente = q;

            }       
        }
    }
      delete sgm;
      return cad;
} 





TCadena copiarSegmento(TLocalizador desde, TLocalizador hasta, TCadena cad){
    TCadena copia = crearCadena();
    if (esVaciaCadena(cad)){
        return copia;
    } else { 
        while (desde!= NULL && desde != hasta->siguiente){
            copia = insertarAlFinal(copiaInfo(desde->dato), copia);
            desde = desde->siguiente;        
        }
    } 
    return copia;

}

TCadena borrarSegmento(TLocalizador desde, TLocalizador hasta, TCadena cad){
    if(!esVaciaCadena(cad)){
        TLocalizador c1 = desde, c2 = desde;
        while(c1 != hasta){
            c2 = c2->siguiente;
            cad = removerDeCadena(c1, cad);
            c1 = c2;
        }
        cad = removerDeCadena(c1, cad);
        return cad;
    }
    else 
    {
       return cad;
    }
}

TCadena cambiarEnCadena(TInfo i, TLocalizador loc, TCadena cad){
    loc->dato = i;
    return cad;
}

TCadena intercambiar(TLocalizador loc1, TLocalizador loc2, TCadena cad){
    TInfo i = loc1->dato;
    loc1->dato = loc2->dato;
    loc2->dato = i;
    return cad;
}

TLocalizador siguienteClave(nat clave, TLocalizador loc, TCadena cad){
  TLocalizador q;
  if (!esVaciaCadena(cad)){
     q = loc;
  } else {
     q = NULL;
  }
  while (q != NULL && natInfo(q->dato) != clave){
        q = q->siguiente;
   }
   return q;
}

TLocalizador anteriorClave(nat clave, TLocalizador loc, TCadena cad){
    TLocalizador q;
    if (!esVaciaCadena(cad)){
        q = loc;
    } else {
        q = NULL;
    }
    while (q != NULL && natInfo(q->dato) != clave){
        q = q->anterior;
    }
    return q;
}

TLocalizador menorEnCadena(TLocalizador loc, TCadena cad){
    TLocalizador pmin = loc;
    nat min = natInfo(loc->dato);
    while(loc != NULL){
        nat aux = natInfo(loc->dato);
        if (aux < min){
            min = aux;
            pmin = loc;
        }
        loc = loc->siguiente;
    }
    return pmin;

}


