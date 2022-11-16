/* 5101344 */

#include "../include/cadena.h"
#include "../include/info.h"
#include "../include/utils.h"
#include "../include/usoTads.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

bool pertenece(nat elem, TCadena cad) {
  TLocalizador buscador = inicioCadena(cad);
  while (esLocalizador(buscador) && elem != natInfo(infoCadena(buscador, cad)))
    buscador = siguiente(buscador, cad);
  return (esLocalizador(buscador));
}

nat longitud(TCadena cad) {
  TLocalizador medidor = inicioCadena(cad);
  nat contador = 0;
  while (esLocalizador(medidor)) {
    contador += 1;
    medidor = siguiente(medidor, cad);
  }
  return contador;
}

bool estaOrdenadaPorNaturales(TCadena cad) {
  TLocalizador comprobar = inicioCadena(cad);
  while (esLocalizador(comprobar) && !esFinalCadena(comprobar, cad) &&
         natInfo(infoCadena(comprobar, cad)) <= natInfo(infoCadena(siguiente(comprobar, cad), cad)))
    comprobar = siguiente(comprobar, cad);
  return (!esLocalizador(comprobar) || esFinalCadena(comprobar, cad));
}

bool hayNatsRepetidos(TCadena cad) {
  TLocalizador comparar = inicioCadena(cad);
  while (esLocalizador(comparar) && !esFinalCadena(comparar, cad) &&
         siguienteClave(natInfo(infoCadena(comparar, cad)), siguiente(comparar, cad), cad) == NULL)
    comparar = siguiente(comparar, cad);
  return (esLocalizador(comparar) && !esFinalCadena(comparar, cad));
}

bool sonIgualesCadena(TCadena c1, TCadena c2) {
  if (longitud(c1) != longitud(c2))
    return false;
  else {
    TLocalizador cursor1 = inicioCadena(c1), cursor2 = inicioCadena(c2);
    while (esLocalizador(cursor1) &&
           sonIgualesInfo(infoCadena(cursor1, c1), infoCadena(cursor2, c2))) {
      cursor1 = siguiente(cursor1, c1);
      cursor2 = siguiente(cursor2, c2);
    }
    return (!esLocalizador(cursor1));
  }
}


TCadena concatenar(TCadena c1, TCadena c2) {
  TCadena unidos;
  TCadena copia1 = copiarSegmento(inicioCadena(c1), finalCadena(c1), c1);
  TCadena copia2 = copiarSegmento(inicioCadena(c2), finalCadena(c2), c2);
  unidos = insertarSegmentoDespues(copia2, finalCadena(copia1), copia1);
  return unidos;
}

TCadena ordenar(TCadena cad) {
  TLocalizador cursor = inicioCadena(cad);
  while (esLocalizador(cursor)) {
    TLocalizador mas_chico = menorEnCadena(cursor, cad);
    cad = intercambiar(cursor, mas_chico, cad);
    cursor = siguiente(cursor, cad);
  }
  return cad;
}

TCadena cambiarTodos(nat original, nat nuevo, TCadena cad) {
  TLocalizador buscador = siguienteClave(original, inicioCadena(cad), cad);
  while (esLocalizador(buscador)) {
    TInfo nuevo_dato = crearInfo(nuevo, realInfo(infoCadena(buscador, cad)));
    liberarInfo(infoCadena(buscador, cad));
    cad = cambiarEnCadena(nuevo_dato, buscador, cad);
    buscador = siguienteClave(original, siguiente(buscador, cad), cad);
  }
  return cad;
}

TCadena subCadena(nat menor, nat mayor, TCadena cad) {
  TLocalizador desde = inicioCadena(cad);
  TLocalizador hasta = finalCadena(cad);
  while (natInfo(infoCadena(desde, cad)) != menor)
    desde = siguiente(desde, cad);
  while (natInfo(infoCadena(hasta, cad)) != mayor)
    hasta = anterior(hasta, cad);
  return copiarSegmento(desde, hasta, cad);
}
