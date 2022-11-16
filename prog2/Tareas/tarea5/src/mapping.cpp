// 5320574

#include "../include/mapping.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct list *PLista;  

struct list{
    nat clave;
    double valor;
    PLista lst;
};

struct repMap {
    nat cap, size;
    PLista * array;
};

TMapping crearMap(nat M) {

    TMapping res = new repMap;
    res->cap = M;
    res->size = 0;
    res->array = new PLista[M];
    nat i = 0;

    while(i <= M-1){
        res->array[i] = NULL;
        i++;
    }

    return res;

}


TMapping asociarEnMap(nat clave, double valor, TMapping map){ 

    int i = clave % map->cap;

    PLista lst = new list;
    lst->clave = clave;
    lst->valor = valor;

    if(map->array[i] == NULL)
        lst->lst = NULL;
    else 
        lst->lst = map->array[i];

    map->array[i] = lst;
    
    map->size++; 
    return map;

}


static PLista elim(nat clave, PLista lst){
    PLista temp = lst, ant = temp;
    if(lst != NULL && lst->clave == clave){
        lst = temp->lst;
        delete temp;
        return lst;
    }

    while(temp != NULL && temp->clave != clave){
        ant = temp;
        temp = temp->lst;
    }

    ant->lst = temp->lst;
    delete temp;
    return lst;
}

TMapping desasociarEnMap(nat clave, TMapping map){
    int i = clave % map->cap;
    map->array[i] = elim(clave, map->array[i]);
    map->size--;
    return map;
}


bool existeAsociacionEnMap(nat clave, TMapping map){

    nat pos = clave % map->cap;
    PLista lst = map->array[pos];

    bool result = false;
    while(!result && lst != NULL){
        if(lst->clave == clave)
            return true;
        else 
            lst = lst->lst;
    }

    return result;
} 


double valorEnMap(nat clave, TMapping map){

    int i = clave % map->cap;
    PLista lst = map->array[i];
    
    while(lst != NULL && lst->clave != clave)
        lst = lst->lst;
 
    return lst->valor;

}

bool estaLlenoMap(TMapping map){ return map->size == map->cap; }

static void liberarlst(PLista lst){
    PLista c = lst;
    while(lst != NULL){
        lst = lst->lst;
        delete c;
        c = lst;
    }
}
void liberarMap(TMapping map){

    nat i = 0;
    while(i <= map->cap - 1){
        liberarlst(map->array[i]);
        i++;
    }
    delete [] map->array;
    delete map;

}