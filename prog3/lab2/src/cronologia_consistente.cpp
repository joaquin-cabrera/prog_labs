/* 5320574 */
/*
  Módulo de implementación de `cronologia_consistente'.

  Laboratorio de Programación 3.
  InCo-FIng-UDELAR
*/
#include <stdio.h>
#include <grafo.h>
#include <lista.h>

#include "../include/cronologia_consistente.h"



static Lista crearOrdenTopologico(Grafo g){

	Lista orden_topologico = crear_lista();
	Lista in_nulo = crear_lista();
	nat n = cantidad_vertices(g);
	nat* grado_entrante = new nat[n + 1];
	nat elemsInsertados = 0;

	for(nat i = 1; i <= n; i++){
		grado_entrante[i] = in_grado(i,g);
		if(in_grado(i,g) == 0){
			insertar_al_final(i,in_nulo);
		}	
	}

	while(!es_vacia_lista(in_nulo) && elemsInsertados < n){
		nat v = primero(in_nulo);
		insertar_al_final(v, orden_topologico);
		elemsInsertados++;
		Lista adyacentes_v = adyacentes(v, g);
		comienzo(adyacentes_v);
		while(existe_actual(adyacentes_v)){
			grado_entrante[actual(adyacentes_v)]--;
			if(grado_entrante[actual(adyacentes_v)] == 0){
				insertar_al_final(actual(adyacentes_v),in_nulo);
			}
			siguiente(adyacentes_v);
		}
		remover_al_inicio(in_nulo);
	}
 
	delete[] grado_entrante;
	destruir_lista(in_nulo);
	if(cantidad_elementos(orden_topologico) < n){
		destruir_lista(orden_topologico);
		Lista returnvacio = crear_lista();
		return returnvacio;
	} else {
		return orden_topologico;
	}
}



Cronologia cronologia_consistente(nat n, ListaDatos tipo1, ListaDatos tipo2){
  
	bool existe_cr_consistente = false; 
	Cronologia cr = new evento[2*n];
	nat f = 2*n;

	Grafo g = crear_grafo(f, true);
	for(nat i = 1; i <= f; i++){
		agregar_vertice(i, g);
	}
	for(nat i = 1; i <= n; i++){
		agregar_arista(i, i + n, g);
	}
	while(!es_vacia_lista_datos(tipo1)){
		dato d = primer_dato(tipo1);
		agregar_arista(id1(d) + n, id2(d), g);
		tipo1 = resto_datos(tipo1);
	}
	while(!es_vacia_lista_datos(tipo2)){
		dato d = primer_dato(tipo2);
		agregar_arista(id1(d), id2(d) + n, g);
		agregar_arista(id2(d), id1(d) + n, g);
		tipo2 = resto_datos(tipo2);
	}

	Lista orden_topologico = crearOrdenTopologico(g);
	existe_cr_consistente = !es_vacia_lista(orden_topologico);

	if(existe_cr_consistente) { // si existe, retornarla en cr

		comienzo(orden_topologico);
		nat pos = 0;
		while(existe_actual(orden_topologico)){
			evento e;
			nat v = actual(orden_topologico);
			if( v > n ){
				e.id = v - n;
				e.tipo = tipo_evento::muere;
			} else {
				e.id = v;
				e.tipo = tipo_evento::nace;
			}
			cr[pos] = e;
			pos++;
			siguiente(orden_topologico);
		}

		destruir_lista(orden_topologico);
		destruir_grafo(g);
		return cr;	
	} else {// si no existe, liberar la memoria asociada a cr y retornar NULL   
		destruir_lista(orden_topologico);
		destruir_grafo(g);
		delete[] cr;
		return NULL;
	}
} 
