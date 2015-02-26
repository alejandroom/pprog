/**
* @brief Utilidades de manejo de uniones
*
* Este modulo contiene los prototipos 
* de las funciones de manejo de
* uniones.
* @file Union.h
* @author Irene Colmenar
* @version 2.0 incluidos campos nombre y key y las modificaciones para manejarlos
* @date 1-05-2012
*/

#ifndef UNION_H_
#define UNION_H_

#include <stdio.h>
#include <stdlib.h>
#include "Const.h"

typedef struct _Union Union;

/**
* @brief Crea una union, reservando la memoria e inicializando sus valores
* @param id identificador con que se inicializara la union
* @return Union* union resultante
*/
Union * nueva_union(Id id);

/**
* @brief Destruye una union, liberando la memoria que tenga reservada
* @param u union a eliminar
*/
void destruye_union(Union * u);

/**
* @brief Asigna a los espacios de la union los valores dados
* @param u union a modificar
* @param id1 identificador del primer espacio
* @param id2 identificador del segundo espacio
* @return BOOL TRUE en caso de que los valores se asignen correctamente, FALSE en caso de que ocurra algun error
*/
BOOL une_espacios(Union * u, Id e1, Id e2);

/**
* @brief Establece el valor del campo abrible de la union indicada
* @param u union a modificar
* @param b valor BOOL a asignar
* @return BOOL TRUE en caso de que los valores se asignen correctamente, FALSE en caso de que ocurra algun error
*/
BOOL establece_abrible(Union * u, BOOL b);

/**
* @brief Abre la union indicada
* @param u union a modificar
* @return BOOL TRUE en caso de que los valores se asignen correctamente, FALSE en caso de que ocurra algun error
*/
BOOL abre_union(Union * u);

/**
* @brief Cierra la union indicada
* @param u union a modificar
* @return BOOL TRUE en caso de que los valores se asignen correctamente, FALSE en caso de que ocurra algun error
*/
BOOL cierra_union(Union * u);

/**
* @brief Establece el valor del campo nombre de la union indicada
* @param u union a modificar
* @param nombre cadena de caracteres a asignar
* @return BOOL TRUE en caso de que los valores se asignen correctamente, FALSE en caso de que ocurra algun error
*/
BOOL escribe_nombreunion(Union *u, char *nombre);

/**
* @brief Establece el valor del campo key de la union indicada
* @param u union a modificar
* @param key identificador a asignar
* @return BOOL TRUE en caso de que se escriba correctamente, FALSE en caso de que ocurra algun error
*/
BOOL escribe_key (Union * u, Id key);

/**
* @brief Devuelve el campo id de la union indicada
* @param u union cuya id se busca
* @return Id valor id de la union, NO_ID en casi de union nula
*/
Id devuelve_id_union(Union *u);

/**
* @brief Dada una union y un espacio, se devuelve el segundo espacio de la union
* @param u union cuyo segundo espacio se busca
* @param e1 id de uno de los espacios
* @return Id identificador del segundo espacio, NO_ID si la union es nula o si nu une el espacio dado
*/
Id dame_espacio_unido(Union * u, Id e1);

/**
* @brief Dada una union, devuelve el valor del campo abrible
* @param u union cuyo campo abrible se busca
* @return BOOL TRUE si es abrible, FALSE si no lo es o si la union es nula
*/
BOOL es_union_abrible(Union * u);

/**
* @brief Dada una union, devuelve el valor del campo cerrada
* @param u union cuyo campo cerrada se busca
* @return BOOL TRUE si esta cerrada, FALSE si no lo esta o si la union es nula
*/
BOOL es_union_cerrada(Union * u);

/**
* @brief Dada una union, devuelve el valor del campo nombre
* @param u union cuyo campo nombre se busca
* @return char* nombre de la union
*/
char* devuelve_nombreunion(Union *u);

/**
* @brief Dada una union, devuelve el valor del campo key
* @param u union cuyo campo key se busca
* @return Id identificador correspondiente al campo key, NO_ID si la union es nula
*/
Id devuelve_key (Union *u);

/**
* @brief Imprime la union dada, incluida para facilitar debugs
* @param u union que se quiere imprimir
*/
void imprime_union(Union * u);

#endif
