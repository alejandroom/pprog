/**
* @brief Utilidades del Conjunto.h
*
* Este modulo contiene las funciones de manejo del conjutno
*
* @file Conjunto.c
* @author Juan Manuel Cornet
* @version 1.0
* @date 1-05-2012
*/

/*
 * File:   Conjunto.c
 * Author: Juan Manuel Cornet
 *
 * Created on 8 de marzo de 2012, 10:37
 */
#include <stdio.h>
#include <stdlib.h>
#include "Conjunto.h"

struct _conjunto{
	Id elems[TAM_MAX_CNJ];
	int card;
};

/**
* @brief Crea un conjunto
* @return Conjunto puntero a un conjunto
*/
Conjunto * nuevo_conjunto(){

	int i;
	Conjunto * cj;

	cj=(Conjunto *) malloc (sizeof(Conjunto));
	if (cj==NULL)
		return cj;

	for (i=0; i<TAM_MAX_CNJ; i++){
		cj->elems[i]=NO_ID;
	}
	cj->card=0;

	return cj;
}

/**
* @brief Libera los recursos reservados para un conjunto de identificadores.
* @param cj Conjunto a liberar
*/
void destruye_conjunto(Conjunto * cj){

	free(cj);
}

/**
* @brief Añade un nuevo identificador al conjunto si no estuviera repetido
* @param c conjunto al que añadir la id
* @param id Id a añadir
* @return Devuelve FALSE si el id ya se encuentra en el conjunto o si el conjunto no existe
*/
BOOL incluye_id(Conjunto * cj, Id id){

	int i;

	if (id==NO_ID)
		return FALSE;

	if (cj==NULL){
		return FALSE;
	}

	if (esta_id(cj, id)==TRUE){
		return FALSE;
	}

	for (i=0; i<TAM_MAX_CNJ; i++){
		if (cj->elems[i]==NO_ID){
			cj->elems[i]=id;
			cj->card++;
			return TRUE;
		}
	}
}

/**
* @brief Determina si un ID se encuentra en el conjunto.
* @param c conjunto en el que se verifica si esta el id
* @param id Id a comprobar
* @return Devuelve FALSE si el id no se encuentra en el conjunto
*/
BOOL esta_id(Conjunto * cj, Id id){

	int i;

	if (id==NO_ID)
		return FALSE;

	if (cj==NULL){
		return FALSE;
	}

	for (i=0; i<TAM_MAX_CNJ; i++){
		if (cj->elems[i]== id){
			return TRUE;
		}
	}

	return FALSE;
}

/**
* @brief Elimina un ID del conjunto dado.
* @param cj conjunto del que se quiere eliminar
* @param id Id a eliminar
* @return Devuelve FALSE si el ID no se encuentra en el conjunto
*/
BOOL quita_id(Conjunto * cj, Id id){

	int i;

	if (id==NO_ID)
		return FALSE;

	if (cj==NULL){
		return FALSE;
	}

	if (esta_id(cj, id)==FALSE){
		return FALSE;
	}

	for (i=0; i<TAM_MAX_CNJ; i++){
		if (cj->elems[i]== id){
			cj->elems[i]=NO_ID;
			cj->card--;
			return TRUE;
		}
	}
}

/**
* @brief Devuelve el tamaño de un conjunto
* @param cj conjunto del que se quiere saber el tamaño
* @return Devuelve el tamaño del conjunto
*/
Tam tamano_conjunto(Conjunto * cj){

	if (cj==NULL){
		return 0;
	}

	return cj->card;
}

/**
* @brief Devuelve el ID almacenado en una determinada posicion
* @param cj conjunto en el que buscar
* @param posicion entero que determina la posicion en la que se quiere buscar
* @return Devuelve FALSE si el ID no esta almacenado en la posicion
*/
Id dame_id_pos(Conjunto * cj, int posicion){

	if (cj==NULL){
		return NO_ID;
	}

	if (es_vacio_conjunto(cj)==TRUE){
		return NO_ID;
	}

	return cj->elems[posicion];
}

/**
* @brief Determina si un conjunto esta vacio o no
* @param cj conjunto que comprobar
* @return  Devuelve FALSE si el conjunto no esta vacio
*/
BOOL es_vacio_conjunto(Conjunto * cj){

	if (cj==NULL){
		return FALSE;
	}

	if (cj->card==0){
		return TRUE;
	}

	return FALSE;
}

/**
* @brief Imprime un conjunto
* @param cj conjunto a imprimir
*/
void imprime_conjunto(Conjunto * cj){

	int i;

	for (i=0; i<TAM_MAX_CNJ; i++){
		if (cj->elems[i]!=NO_ID){
			printf ("Posicion: %d\tID: %ld\n\n", i, cj->elems[i]);
		}
	}
}


