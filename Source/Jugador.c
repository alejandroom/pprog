/**
* @brief Utilidades de interaccion del jugador
*
* Este modulo contiene las funciones de manejo de
* jugador.
* @file Jugador.c
* @author Juan Manuel Cornet
* @version 1.0
* @date 1-05-2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Jugador.h"

struct _jugador{
	char nombre[TAMANO_PAL+1];
	Id localizacion;
	Inventario * inventario;
};

/**
* @brief Crea un nuevo jugador.
* @return Devuelve un puntero a jugador, si no se ha podido crear se creara un puntero a NULL
*/
Jugador * nuevo_jugador(){
	
	Jugador * j;
	
	j=(Jugador *) malloc (sizeof(Jugador));
	
	if (j==NULL)
		return j;
	
	j->inventario=nuevo_inventario();
	
	if (j->inventario==NULL)
		return j;
	
	j->localizacion=NO_ID;
	
	return j;
}

/**
* @brief Destruye un jugador
* @param j jugador a liberar
*/
void destruye_jugador(Jugador * j){
	
	destruye_inventario(j->inventario);
	free(j);
}

/**
* @brief Establece el nombre de un jugador 
* @param j jugador que se va a nombrar
* @param nombre cadena de caracteres con el nombre que se le pondra a l jugador
* @return Devuelve FALSE si no se ha podido poner el nombre
*/
BOOL establece_nombre_jugador(Jugador * j, char * nombre){
	
	if (strlen(nombre)>TAMANO_PAL+1)
		return FALSE;
	
	if (j==NULL){
		return FALSE;
	}
	
	strcpy(j->nombre, nombre);
	
	return TRUE;
}

/**
* @brief Establece el maximo de objetos que puede llevar un jugador encima.
* @param j jugador al que se le establecera el numero de objetos maximos de su inventario
* @param nobj numero maximo de objetos a estabalcer
* @return Devuelve FALSE si no se ha podido establecer ese numero maximo de objetos
*/
BOOL establece_maximo_obj(Jugador * j, unsigned int nobj){
	
	if (j==NULL){
		return FALSE;
	}
	
	if (establece_max_objetos(j->inventario, nobj)==FALSE){
		return FALSE;
	}
	
	return TRUE;
}

/**
* @brief Establece la localizacion de un jugador.
* @param j jugador al que se le establece una localizacion nueva
* @param id del espacio nuevo
* @return Devuelve FALSE si no se puede modificar la ubicacion del jugador
*/
BOOL establece_loc_jugador(Jugador * j, Id id){
	
	if (id==NO_ID)
		return FALSE;
	
	if (j==NULL){
		return FALSE;
	}
	
	j->localizacion=id;
	
	return TRUE;
}

/**
* @brief Devuelve la localizacion actual del jugador.
* @param j jugador del que se devuelve su localizacion
* @return Devuelve un ID correspondiente al espacio en el que se encuentra el jugador.
*/
Id dame_loc_jugador(Jugador * j){
	
	if (j==NULL){
		return NO_ID;
	}
	
	return j->localizacion;
}

/**
* @brief Devuelve el nombre del jugador.
* @param j jugador del que obtener el nombre
* @return   Devuelve una cadena de caracteres que contiene el nombre del jugador
*/
char * dame_nombre_jugador(Jugador * j){
	
	if (j==NULL){
		return NULL;
	}
	
	return j->nombre;
}

/**
* @brief Anyade un objeto al inventario del jugador
* @param o jugador al que añadir el objeto
* @param id Id del objeto a añadir
* @return  Devuelve FALSE si no se puede añadir el objeto al inventario.
*/
BOOL annade_objeto_jugador(Jugador * o, Id id){
	
	if (o==NULL){
		return FALSE;
	}
	
	if (nuevo_obj_inventario(o->inventario, id)==FALSE){
		return FALSE;
	}
	
	return TRUE;
}

/**
* @brief Busca un objeto en el inventario del jugador
* @param j jugador que tiene el inventario donde se buscara el objeto
* @param id Id del objeto a buscar
* @return   Devuelve FALSE si el objeto no se encuentra en el inventario
*/
BOOL buscar_obj_inventario(Jugador * j, Id id){
	
	if (j==NULL){
		return FALSE;
	}
	
	if (buscar_obj(j->inventario, id)==FALSE){
		return FALSE;
	}
	
	return TRUE;
}

/**
* @brief Elimina un objeto del inventario de un jugador
* @param j jugador al que se le quita el objeto
* @param id Id del objeto a quitar
* @return   Devuelve FALSE si el objeto a eliminar no se encuentra en el inventario del jugador
*/
BOOL quita_obj_inventario(Jugador * j, Id id){
	
	if (j==NULL){
		return FALSE;
	}
	
	if (quita_obj(j->inventario, id)==FALSE){
		return FALSE;
	}
	
	return TRUE;
}

/**
* @brief Devuelve el inventario del jugador
* @param j jugador que tiene el inventario
* @return   Devuelve un puntero al inventario del jugador, null si no se encuentra
*/
Inventario * devuelve_inventario (Jugador *j){
	if (j == NULL)
		return NULL;
	return j->inventario;
}


