//53205740
/*
  Módulo de definición de 'usoTads'.

  Se definen funciones sobre tads.

  Laboratorio de Programación 2.
  InCo-FIng-UDELAR
 */
#include "../include/cadena.h"
#include "../include/info.h"
#include "../include/utils.h"
#include "../include/usoTads.h"
#include "../include/binario.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

// nueva

static TCadena cadnivelL(nat l, nat i, TBinario b, TCadena cad){

    if(i == l){
        cad = insertarAlFinal(copiaInfo(raiz(b)), cad);
    } else {
        i++;
        if(izquierdo(b) != NULL)cad = cadnivelL(l , i, izquierdo(b), cad);
        if(derecho(b) != NULL)cad = cadnivelL(l , i, derecho(b), cad);
    }
    return cad;
    
}

TCadena nivelEnBinario(nat l, TBinario b){ 
    TCadena cad = crearCadena();
    nat i = 1;
    return cadnivelL(l, i , b , cad);
}

bool esCamino(TCadena c, TBinario b){
    TLocalizador cursor = inicioCadena(c);
    while(b != NULL && cursor != NULL && natInfo(raiz(b)) == natInfo(infoCadena(cursor, c))){
        cursor = siguiente(cursor, c );
        if(cursor == NULL){ 
            if(izquierdo(b) == NULL && derecho(b) == NULL)
                return true;
            else 
                return false;
        } else {
            if(natInfo(infoCadena(cursor, c)) > natInfo(raiz(b)))   
                b = derecho(b);
            else if (natInfo(infoCadena(cursor, c)) < natInfo(raiz(b))) 
                b = izquierdo(b);
            else  
                return false;
        }
    }
    return cursor == NULL && izquierdo(b) == NULL && derecho(b) == NULL;
} 


bool pertenece(nat elem, TCadena cad){
    TLocalizador cursor = inicioCadena(cad);
    while (esLocalizador(cursor) && natInfo(infoCadena(cursor, cad)) != elem){
        cursor = siguiente(cursor, cad);
    }
    return (esLocalizador(cursor));
}

nat longitud(TCadena cad){
    TLocalizador q = inicioCadena(cad);
    nat i = 0;
    while (esLocalizador(q)){
        i++;
        q = siguiente(q, cad);
    }
    return i;
}

bool estaOrdenadaPorNaturales(TCadena cad){
    if (esVaciaCadena(cad)){
        return true;
    } else {
        TLocalizador cursor = inicioCadena(cad);   
        nat aux = natInfo(infoCadena(cursor, cad));
        while(localizadorEnCadena(cursor, cad) && natInfo(infoCadena(cursor, cad)) >= aux){
            aux = natInfo(infoCadena(cursor, cad));
            cursor = siguiente(cursor, cad);           
        } 
        return !esLocalizador(cursor);
    }
}

bool hayNatsRepetidos(TCadena cad){
    TLocalizador c1 = inicioCadena(cad);
    while(c1 != NULL && siguienteClave(natInfo(infoCadena(c1,cad)),siguiente(c1,cad),cad) == NULL){ 
        c1 = siguiente(c1,cad);                      
    }
    return esLocalizador(c1);
}

bool sonIgualesCadena(TCadena c1, TCadena c2){
    TLocalizador cur1 = inicioCadena(c1), cur2 = inicioCadena(c2);
    bool b = false;
    if (longitud(c1) == longitud(c2)){        
        while(cur1 != NULL && sonIgualesInfo(infoCadena(cur1, c1), infoCadena(cur2, c2))){
            cur1 = siguiente(cur1, c1);
            cur2 = siguiente(cur2,c2);
        }
        b = !esLocalizador(cur1);        
    }
        return b;
}

TCadena concatenar(TCadena c1, TCadena c2){
   TCadena cop1 = copiarSegmento(inicioCadena(c1), finalCadena(c1), c1);
   TCadena cop2 = copiarSegmento(inicioCadena(c2), finalCadena(c2), c2);
   TCadena cop3 = insertarSegmentoDespues(cop2, finalCadena(cop1), cop1);   
   return cop3;
}

TCadena ordenar(TCadena cad){
    TCadena aux = cad;
    TLocalizador cursor = inicioCadena(aux);
    while(cursor != finalCadena(aux)){
        TLocalizador q = menorEnCadena(cursor, aux);
        aux = intercambiar(cursor, q, aux);
        cursor = siguiente(cursor, aux);
    }
    return cad; 
}

TCadena cambiarTodos(nat original, nat nuevo, TCadena cad){
    TLocalizador q = inicioCadena(cad);
    while(esLocalizador(q)){
        if(natInfo(infoCadena(q,cad)) == original){
            TInfo aux = crearInfo(nuevo, realInfo(infoCadena(q,cad)));
            liberarInfo(infoCadena(q,cad));
            cad = cambiarEnCadena(aux, q, cad);       
        }
        q = siguiente(q, cad);
    }
    return cad;
}

TCadena subCadena(nat menor, nat mayor, TCadena cad){
    TLocalizador desde = siguienteClave(menor, inicioCadena(cad), cad), mov = desde;
    while ((siguiente(mov,cad) != NULL) && (natInfo(infoCadena(siguiente(mov,cad), cad)) <= mayor)){
        mov = siguiente(mov,cad);
    }
    return copiarSegmento(desde, mov, cad);
}
