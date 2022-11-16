/* 5320574 */
/*

  Módulo de implementación de `asignacion_residencias'.

  Laboratorio de Programación 3.
  InCo-FIng-UDELAR
 */

#include "../include/asignacion_residencias.h"
#include "../include/cola.h"
#include <cstddef>

Asignacion asignarResidencias(nat m, nat* C, nat n, nat** hPrefs, nat** ePrefs){

  Asignacion res = crear_asignacion();
  
  Cola hospitalesConCupos = crear_cola();
  //nat siguienteEstudiante[m];
  nat* siguienteEstudiante = new nat[m];

  for(nat i = 0; i <= m - 1; i++){
    encolar(i ,hospitalesConCupos);
    siguienteEstudiante[i] = 0;
  }

  //hospital asignado al estudiante i
  //nat hospitalAsignado[n];
  nat* hospitalAsignado = new nat[n];
  for(nat i = 0; i <= n - 1; i++){
    hospitalAsignado[i] = m + 1;
  }
  
  //matriz que en la casilla i,j tiene la posicion en el ranking del estudiante i sobre el hospital j;
 // nat rankHospital[n][m];
  nat** rankHospital = new nat*[n];
  for(nat i = 0; i <= n - 1; i++){
    rankHospital[i] = new nat[m];
  }
  for(nat i = 0; i <= n - 1; i++){
    for(nat j = 0; j <= m - 1; j++){
      rankHospital[i][ ePrefs[i][j] ] = j;
    }
  }

  while( !es_vacia_cola(hospitalesConCupos) ){

    nat h = frente(hospitalesConCupos);
    nat e = hPrefs[h][siguienteEstudiante[h]]; //estudiante mas alto al que aun no se le propuso
    nat hprima = hospitalAsignado[e]; 
    
    if( hprima == (m + 1) ){

      hospitalAsignado[e] = h;
      C[h]--;      

    } else {

      if( rankHospital[e][h] < rankHospital[e][hprima] ){

        hospitalAsignado[e] = h;
        C[h]--;      
        C[hprima]++;
        if( C[hprima] > 0){
          encolar(hprima, hospitalesConCupos);
        }

      }  
    }
    siguienteEstudiante[h]++;
    if( C[h] == 0 ){
      desencolar(hospitalesConCupos);
    }
  }

  //crear asignacion
  for(nat i = 0; i <= n - 1; i++){
    if(hospitalAsignado[i] < m + 1){
      par p;
      p.hid = hospitalAsignado[i];
      p.eid = i;
      insertar_par(p, res);
    }
  }


  //######################################################
  //borrar las cosas
  for(nat i = 0; i <= n - 1; i++){
    delete [] rankHospital[i];
  }
  delete [] rankHospital;
  delete [] siguienteEstudiante;
  delete [] hospitalAsignado;
  destruir_cola(hospitalesConCupos);
  //#######################################################
  
  return res; // se debe retornar algo de tipo asignacion
}
