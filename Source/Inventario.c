/**
* @brief Utilidades de inventario
*
* Este modulo contiene las funciones para modificar inventarios
* @file Inventario.c
* @author Juan Manuel Cornet
* @version 1.0
* @date 1-05-2012
*/

#include <stdio.h>
#include <stdlib.h>
#include "Inventario.h"

struct _Inventario{
	Conjunto * obj;
	int maxObjetos;
};

 /**
* @brief Crea un nuevo invnetario
* @return Inventario devuelve un puntero ai nventario
*/
Inventario * nuevo_inventario(){

	Inventario * inv;

	inv=(Inventario *) malloc (sizeof(Inventario));

	if (inv==NULL)
		return NULL;

	inv->obj=nuevo_conjunto();

	if (inv->obj==NULL){
	free(inv);
		return NULL;
	}

	return inv;
}

 /**
* @brief Libera la memoria reservada para un inventario
* @param inv inventario que se va a liberar
*/
void destruye_inventario(Inventario * inv){

	destruye_conjunto(inv->obj);
	free(inv);
}

 /**
* @brief Establece el maximo de objetos de un inventario
* @param inv inventario en el que establecer el numero de objetos
* @param maxObjetos maximo de objetos a fijar en el inventario
* @return Devuelve FALSE si no se ha podido establecer ese numero maximo de objetos
*/
BOOL establece_max_objetos(Inventario * inv, int maxObjetos){

	if (inv==NULL){
		return FALSE;
	}

	if (maxObjetos < 0)
		return FALSE;

	inv->maxObjetos=maxObjetos;

	return TRUE;
}

 /**
* @brief Añade un nuevo objeto al inventario si este no existe ya.
* @param inv inventario al que añadir el objeto
* @param id Id del objeto que se añade al inventario
* @return Devuelve FALSE si no se ha podido añadir el objeto.
*/
BOOL nuevo_obj_inventario(Inventario * inv, Id id){

	if (id==NO_ID)
		return FALSE;

	if (inv==NULL){
		return FALSE;
	}

	if (buscar_obj(inv, id)==TRUE){
		return FALSE;
	}

	if (tamano_conjunto(inv->obj)<inv->maxObjetos){
		if (incluye_id(inv->obj, id)==FALSE){
			return FALSE;
		}
		return TRUE;
	}

	return FALSE;
}

 /**
* @brief Busca un objeto con un ID dado.
* @param inv inventario en el que buscar el objeto
* @param id Id del objeto que se busca en el inventairo
* @return Devuelve FALSE si no se encuentra el objeto
*/
BOOL buscar_obj(Inventario * inv, Id id){

	if (id==NO_ID)
		return FALSE;

	if (inv==NULL){
		return FALSE;
	}

	if (esta_id(inv->obj, id)==TRUE){
		return TRUE;
	}

	return FALSE;
}

 /**
* @brief Elimina un objeto dado de un inventario
* @param inv inventario del que eliminar el objeto
* @param id Id del objeto que se quita del inventario
* @return Devuelve FALSE si no se encuentra el objeto
*/
BOOL quita_obj(Inventario * inv, Id id){

	if (id==NO_ID)
		return FALSE;

	if (inv==NULL){
		return FALSE;
	}

	if (buscar_obj(inv, id)==FALSE){
		return FALSE;
	}

	if (quita_id(inv->obj, id)==FALSE){
		return FALSE;
	}

	return TRUE;
}

 /**
* @brief Devuelve el id de un objeto por su posicion
* @param inv inventario del que eliminar el objeto
* @param pos posicion
* @return Devuelve el Id, NO_ID si hay algun error
*/
Id devuelve_objeto_pos_id (Inventario *inv, int pos){
	if(inv==NULL)
		return NO_ID;
	if (pos>=inv->maxObjetos)
		return NO_ID;
	return (dame_id_pos(inv->obj, pos));
}

 /**
* @brief Devuelve el maximo de objetos
* @param inv inventario
* @return Numero maximo de objetos, -1 en caso de error
*/
int devuelve_max_obj (Inventario *inv){
	if (inv==NULL)
		return -1;
	return inv->maxObjetos;
}

 /**
* @brief Devuelve el numero de objetos del inventario
* @param inv inventario
* @return Numero de objetos, -1 en caso de error
*/
int devuelve_num_obj (Inventario *inv){
	if (inv==NULL)
		return -1;
	return tamano_conjunto(inv->obj);
}

 /**
* @brief Indica si el inventario esta vacio
* @param inv inventario
* @return Devuelve si esta vacio, True si hay algun error
*/
BOOL es_vacio_inventario (Inventario *inv){
	if (inv==NULL)
		return TRUE;
	return es_vacio_conjunto(inv->obj);
}







