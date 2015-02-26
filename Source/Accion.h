/**
* @brief Utilidades de manejo de acciones
*
* Este modulo contiene los prototipos de manejo de acciones
* @file Accion.h
* @author Alejandro Ortiz e Irene Colmenar
* @date 1-05-2012
*/

#include "Mundo.h"
#include "ReglasDialogo.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef ACCION_H_
#define ACCION_H_


typedef enum _TipoAccion TipoAccion;
typedef struct _accion Accion;


/**
* @brief Interpreta una accion
* @param quote cadena de caracteres correctamente formada que indica la accion a realizar
* @param ac accion a realizar que incluye el tipo de accion y el objeto directo
* @return BOOL TRUE en caso de que la accion se devuelva correctamente, FALSE en caso de que ocurra algun error
*/
BOOL introduce_accion(char * quote, Accion * ac);

/**
* @brief Crea una accion
* @return Accion* devuelve una accion inicializada a NULL
*/

Accion * crea_accion();
/**
* @brief Libera una accion
* @param a Accion a liberar
*/

void destruye_accion(Accion *a);
/**
* @brief Ejecuta una accion sobre el mundo
* @param m mundo sobre el que se realiza la accion
* @param a accion a realizar que incluye el tipo de accion y el objeto directo
* @return int entero que indica la frase que se imprimirá por pantalla dependiendo de la accion ejecutada y su estado. Mas informacion en la documentacion tecnica.
*/
int ejecuta_accion(Mundo *m, Accion *a);

/**
* @brief Ejecuta la acción de examinar
* @param m mundo sobre el que se realiza la accion examinar
* @param a accion a realizar que incluye el tipo de accion y el objeto directo
* @param examinado cadena de caracteres
* @param max_len tamaño para la reserva de la cadena.
* @return BOOL en caso de que ocurra algun error devuelve FALSE, en caso contrario TRUE
*/
BOOL ejecuta_examina(Mundo *m, Accion *a, char *examinado, Tam max_len);

#endif	/* ACCION_H_*/
