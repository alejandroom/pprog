/* 
 * File:   main.c
 * Author: Juan Manuel Cornet
 *
 * Created on 8 de marzo de 2012, 12:18
 */

#include <stdio.h>
#include <stdlib.h>
#include "Jugador.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    Jugador * jugador;
    char nombre[]="Don Juan";
    char * cadena;
    int maxObjetos=10;
    Id id_espacio=57913, id2, objeto=666666;
    
    jugador=nuevo_jugador();
    
    establece_nombre_jugador(jugador, nombre);
    
    establece_maximo_obj(jugador, maxObjetos);
    
    establece_loc_jugador(jugador, id_espacio);
    
    id2=dame_loc_jugador(jugador);
    
    cadena=dame_nombre_jugador(jugador);
    
    annade_objeto_jugador(jugador, objeto);
    
    buscar_obj_inventario(jugador, objeto);
    
    quita_obj_inventario(jugador, objeto);
            
    destruye_jugador(jugador);             
    
    return (EXIT_SUCCESS);
}

