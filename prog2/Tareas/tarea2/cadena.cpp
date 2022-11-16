/*5429576*/
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
    assert( ((cad->inicio == NULL) && (cad->final == NULL)) || ((cad->inicio != NULL) && (cad->final != NULL)) );
    return ((cad->inicio == NULL)); /* && (cad -> final == NULL) */
}

TLocalizador inicioCadena(TCadena cad)
{
    TLocalizador res;
    if (esVaciaCadena(cad)) {
       res = NULL;
    } else {
       res = cad->inicio;
    }
    return res;
}

TLocalizador finalCadena(TCadena cad){

    TLocalizador res;
    if (esVaciaCadena(cad)) {
       res = NULL;
    } else {
       res = cad->final;
    }
    return res;

}
TInfo infoCadena(TLocalizador loc, TCadena cad){

    return loc -> dato;

}

TLocalizador siguiente(TLocalizador loc, TCadena cad){
    assert(localizadorEnCadena(loc, cad));
    TLocalizador res;
    if (esFinalCadena(loc, cad)){
        res = NULL;
    } else {
        res = loc->siguiente;
    }
    return res;
}

TLocalizador anterior(TLocalizador loc, TCadena cad){

    TLocalizador res;
    if (esInicioCadena(loc, cad)){
        res = NULL;
    } else {
        res = loc->anterior;
    }
    return res;
}

bool esFinalCadena(TLocalizador loc, TCadena cad){

    if ((!esVaciaCadena(cad)) && (loc != NULL) && (loc->siguiente == NULL)) {
        return true;
    } else {
        return false;
    }
    
}

bool esInicioCadena(TLocalizador loc, TCadena cad) {

    if ((!esVaciaCadena(cad)) && (loc != NULL) && (loc->anterior == NULL)) {
        return true;
    } else {
        return false;
    }

}

TCadena insertarAlFinal(TInfo i, TCadena cad) {

    TLocalizador element = new nodo;

    element->dato = i;
    element->siguiente = NULL;

    if (!esVaciaCadena(cad)) {

        cad->final->siguiente = element;
        element->anterior = cad->final;
        cad->final = element;

    } else {
        
        element->anterior = NULL;
        cad->inicio = cad->final = element;
    }

    return cad;

}

TCadena insertarAntes(TInfo i, TLocalizador loc, TCadena cad) {

    assert(localizadorEnCadena(loc, cad));

    //Creo nuevo elemento
    TLocalizador element = new nodo;    
    
    //Cargo datos a Elemento y lo ubico en posición
    element->dato = i;
    element->siguiente = loc;

    //Amparo el caso que el loc sea el inicio de la cadena
    if (!esInicioCadena(loc, cad))
    {
        //Ubico Elemento en Cadena
        TLocalizador aux = loc->anterior;
        loc->anterior = element;
        element->anterior = aux;

        aux->siguiente = element;
    } else {
        loc->anterior = element;
        element->anterior = NULL;
        cad->inicio = element;
    }

    return cad;
}

TCadena removerDeCadena(TLocalizador loc, TCadena cad) {

    if (esInicioCadena(loc, cad) || esFinalCadena(loc, cad))
    {
        if (esInicioCadena(loc, cad) && esFinalCadena(loc, cad)) {
            cad->inicio = cad->final = NULL;
        } else {
            if (esInicioCadena(loc, cad))
            {
                cad->inicio = siguiente(loc, cad);
                loc->siguiente->anterior = NULL;
            } else {
                cad->final = anterior(loc, cad);
                loc->anterior->siguiente = NULL;
            }
        }
    } else {
        loc->anterior->siguiente = siguiente(loc, cad);
        loc->siguiente->anterior = anterior(loc, cad);
    }

    // bool IsAmbos = false, IsUno = false;

    // if (esInicioCadena(loc, cad) && esFinalCadena(loc, cad)) {
    //     cad->inicio = cad->final = NULL;
    //     IsAmbos = true;
    // }

    // if (esInicioCadena(loc, cad) && !IsAmbos)
    // {
    //     cad->inicio = siguiente(loc, cad);
    //     loc->siguiente->anterior = NULL;
    // }
    
    // if (esFinalCadena(loc, cad) && !IsAmbos)
    // {
    //     cad->final = anterior(loc, cad);
    //     loc->anterior->siguiente = NULL;
    // }

    // if (!IsUno)
    // {
    //     loc->anterior->siguiente = siguiente(loc, cad);
    //     loc->siguiente->anterior = anterior(loc, cad);
    // }

    liberarInfo(loc->dato);
    delete loc;
    return cad;
}

void imprimirCadena(TCadena cad) {

    TLocalizador aux = inicioCadena(cad);

    while (aux != NULL) {

        ArregloChars texto = infoATexto(infoCadena(aux, cad));
        printf(texto);

        delete[] texto;

        aux = siguiente(aux, cad);
    }

    /* Print SaltoDeLinea */
    printf("\n");

}

TLocalizador kesimo(nat k, TCadena cad) {

    nat i = 1;
    TLocalizador aux = inicioCadena(cad);

    while ((i<k) && (aux != NULL)) {
        i+=1;
        aux = aux->siguiente;
    }

    if ((i<k) || (k == 0)){
        aux = NULL;
    } 
    
    return aux;
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
        assert(!res || localizadorEnCadena(loc2, cad));
    }
    return res;
}

TCadena insertarSegmentoDespues(TCadena sgm, TLocalizador loc, TCadena cad) {
    
    if (!esVaciaCadena(sgm)) {
        if (esVaciaCadena(cad)) {
            cad->inicio = sgm->inicio;
            cad->final = sgm->final;
        } else {

            sgm->inicio->anterior = loc;
            sgm->final->siguiente = loc->siguiente;

            if (esFinalCadena(loc, cad))
            {
                cad->final = sgm->final;
            } else {
                loc->siguiente->anterior = sgm->final;
            }

            loc->siguiente = sgm->inicio;
        }
    }

    delete sgm;
    return cad;
}

TCadena copiarSegmento(TLocalizador desde, TLocalizador hasta, TCadena cad) {

    TLocalizador cursor = desde;
    TCadena nuevaCadena = crearCadena();
    TLocalizador last = NULL;

    while ((cursor != NULL) && (cursor != hasta->siguiente))
    {   
        //Creo elemento nuevo para copiar de cadena
        TLocalizador elemento = new nodo;

        //Guardo datos en nuevo elemento
        elemento->anterior = last;
        elemento->dato = copiaInfo(cursor->dato);
        elemento->siguiente = NULL;

        //Fijo como ultimo elemento de la nueva cadena el actual
        nuevaCadena->final = elemento;

        if (cursor == desde) {
            nuevaCadena->inicio = elemento;
        } else
        {
            //Enlazo cadena
            last->siguiente = elemento;
        }
        
        last = elemento;

        cursor = siguiente(cursor, cad);
    }

    return nuevaCadena;
}

TCadena borrarSegmento(TLocalizador desde, TLocalizador hasta, TCadena cad) {

    if (!esVaciaCadena(cad)) {
        TLocalizador cursor = desde;
        while (cursor!=hasta)
        {
            cursor = siguiente(cursor, cad);
            cad = removerDeCadena(cursor->anterior, cad);
        }
        cad = removerDeCadena(cursor, cad);       
    }
    
    return cad;
}


TCadena cambiarEnCadena(TInfo i, TLocalizador loc, TCadena cad) {
    loc->dato = i;
    return cad;
}

TCadena intercambiar(TLocalizador loc1, TLocalizador loc2, TCadena cad) {
    
    //Guardo Dato de Loc1 en auxiliar para no perderlo
    TInfo aux = infoCadena(loc1, cad);

    //Intercambio Datos
    loc1->dato = loc2->dato;
    loc2->dato = aux;

    return cad;
}

TLocalizador siguienteClave(nat clave, TLocalizador loc, TCadena cad) {

    if (esVaciaCadena(cad))
    {
        return NULL;
    }

    TLocalizador cursor = loc;

    while ((cursor != NULL) && (natInfo(infoCadena(cursor, cad)) != clave))
    {
        cursor = siguiente(cursor, cad);
    }
    
    return cursor;

}

TLocalizador anteriorClave(nat clave, TLocalizador loc, TCadena cad) {

    if (esVaciaCadena(cad))
    {
        return NULL;
    }

    TLocalizador cursor = loc;

    while ((cursor != NULL) && (natInfo(infoCadena(cursor, cad)) != clave))
    {
        cursor = anterior(cursor, cad);
    }
    
    return cursor;

}

TLocalizador menorEnCadena(TLocalizador loc, TCadena cad) {

    TLocalizador cursor = loc, minimo = loc;
    nat menor = natInfo(infoCadena(loc, cad));

    while ((cursor != NULL))
    {
        if (natInfo(infoCadena(cursor, cad)) < menor) {
            menor = natInfo(infoCadena(cursor, cad));
            minimo = cursor;
        }

        cursor = siguiente(cursor, cad);
    }
    
    return minimo;

}