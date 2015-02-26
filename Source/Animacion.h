/**
* @brief Utilidades de animaciones
*
* Este modulo contiene los prototipos 
* de las funciones con animaciones.
* @file Animacion.h
* @author Alejandro Ortiz
* @version 1.0
* @date 1-05-2012
*/

#ifndef ANIMACION_H_
#define ANIMACION_H_

#include <stdio.h>
#include <stdlib.h>

/**
* @brief Despedida del juego
*/
void despedida();

/**
* @brief Presentacion del juego(titulo)
*/
void presentacion();

/**
* @brief Animacion de fin de juego (Victoria)
* @paran nombre nombre del jugador
*/
void ejecuta_victoria(char *nombre);

/**
* @brief Animacion de GAME OVER
*/
void ejecuta_derrota();

#endif
