/* 
 * File:   main.c
 * Author: Juan Manuel Cornet
 *
 * Created on 27 de marzo de 2012, 9:24
 */

#include <stdio.h>
#include <stdlib.h>
#include "Mundo.h"


/*
 * 
 */
int main() {

    Mundo * m;
    Id idaux, idfalsa=4356346, idespacio=111, idobjeto=222, idunion=333;
    Espacio * eaux;
    Objeto * oaux, * opornombre;
    Jugador * jaux;
    Union * uaux;
    Direccion diraux=N;
    char descespacio[1000];
    char descexaminaespacio[1000];
    char descobjeto[1000];
    
    m=nuevo_mundo();
    
    annade_espacio_mundo(m, idespacio);
    
    annade_espacio_mundo(m, idespacio);
    
    annade_objeto_mundo(m, idobjeto);
    
    annade_objeto_mundo(m, idobjeto);
    
    annade_jugador_mundo(m);
    
    annade_union_mundo(m, idunion);
    
    annade_union_mundo(m, idunion);
    
    eaux=dame_espacio_mundo(m, idespacio);
    
    eaux=dame_espacio_mundo(m, idfalsa);
    
    oaux=dame_objeto_mundo(m, idobjeto);
    
    oaux=dame_objeto_mundo(m, idfalsa);
    
    jaux=dame_jugador_mundo(m);

    uaux=dame_union_mundo(m, idunion);
    
    uaux=dame_union_mundo(m, idfalsa);
    
    idaux=dame_loc_jugador_mundo(m);
    
    eaux=dame_espacio_norte(m, idespacio);
    
    mueve_personaje(m, diraux);
    
    eaux=dame_espacio_mundo(m, idespacio);
    
    nueva_desc_espacio(eaux, "Los calabozos de un barco. Apestan a suciedad y sal.");
    
    desc_real_espacio(m, idespacio, descespacio);
    
    printf ("%s\n\n", descespacio);
    
    nueva_desc_examinar_espacio(eaux, "Al examinar los calabozos, ves un barrote de hierro sospechosamente suelto en tu celda.");
    
    actualiza_iluminacion_espacio(eaux, TRUE);
    
    examina_espacio(m, eaux, descexaminaespacio);
    
    oaux=dame_objeto_mundo(m, idobjeto);
    
    nuevo_nombre_obj(oaux, "Farolcete");
    
    opornombre=dame_objeto_por_nombre(m, "Farolcete");
    
    nueva_loc_objeto(oaux, idespacio);
    annade_objeto_espacio(eaux, idobjeto);
    
    nueva_desc_examinar_obj(oaux, "Un viejo farol inservible con una llave oxidada en su interior.");
    
    establece_loc_jugador(jaux, idespacio);
    
    examina_objeto(m, oaux, descobjeto);
    
    actualiza_movil_obj(oaux, TRUE);
    
    establece_maximo_obj(jaux, 10);
    
    coge_objeto(m, oaux);
    
    deja_objeto(m, oaux);
    
    destruye_mundo(m);
    
    return (EXIT_SUCCESS);
}
