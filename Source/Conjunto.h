/**
* @brief Utilidades del Conjunto.h
*
* Este modulo contiene los prototipos
* de las funciones de manejo del conjutno
*
* @file Conjunto.h
* @author Juan Manuel Cornet
* @version 1.0
* @date 1-05-2012
*/


#ifndef CONJUNTO_H
#define	CONJUNTO_H

#include "Const.h"

typedef struct _conjunto Conjunto;

/**
* @brief Crea un conjunto
* @return Conjunto puntero a un conjunto
*/
Conjunto * nuevo_conjunto();


/**
* @brief Libera los recursos reservados para un conjunto de identificadores.
* @param cj Conjunto a liberar
*/
void destruye_conjunto(Conjunto * cj);


/**
* @brief Añade un nuevo identificador al conjunto si no estuviera repetido
* @param c conjunto al que añadir la id
* @param id Id a añadir
* @return Devuelve FALSE si el id ya se encuentra en el conjunto o si el conjunto no existe
*/
BOOL incluye_id(Conjunto * cj, Id id);


/**
* @brief Determina si un ID se encuentra en el conjunto.
* @param c conjunto en el que se verifica si esta el id
* @param id Id a comprobar
* @return Devuelve FALSE si el id no se encuentra en el conjunto
*/
BOOL esta_id(Conjunto * cj, Id id);


/**
* @brief Elimina un ID del conjunto dado.
* @param cj conjunto del que se quiere eliminar
* @param id Id a eliminar
* @return Devuelve FALSE si el ID no se encuentra en el conjunto
*/
BOOL quita_id(Conjunto * cj, Id id);


/**
* @brief Devuelve el tamaño de un conjunto
* @param cj conjunto del que se quiere saber el tamaño
* @return Devuelve el tamaño del conjunto
*/
Tam tamano_conjunto(Conjunto * cj);


/**
* @brief Devuelve el ID almacenado en una determinada posicion
* @param cj conjunto en el que buscar
* @param posicion entero que determina la posicion en la que se quiere buscar
* @return Devuelve FALSE si el ID no esta almacenado en la posicion
*/
Id dame_id_pos(Conjunto * cj, int posicion);


/**
* @brief Determina si un conjunto esta vacio o no
* @param cj conjunto que comprobar
* @return  Devuelve FALSE si el conjunto no esta vacio
*/
BOOL es_vacio_conjunto(Conjunto * cj);

/**
* @brief Imprime un conjunto
* @param cj conjunto a imprimir
*/
void imprime_conjunto(Conjunto * cj);


#endif	/* CONJUNTO_H */

