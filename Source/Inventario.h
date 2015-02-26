/**
* @brief Utilidades de inventario
*
* Este modulo contiene los prototipos de las funciones para modificar inventarios
* @file Inventario.h
* @author Juan Manuel Cornet
* @version 1.0
* @date 1-05-2012
*/

#ifndef INVENTARIO_H
#define	INVENTARIO_H

#include "Const.h"
#include "Conjunto.h"

typedef struct _Inventario Inventario;

 /**
* @brief Crea un nuevo invnetario
* @return Inventario devuelve un puntero ai nventario
*/
Inventario * nuevo_inventario();


 /**
* @brief Establece el maximo de objetos de un inventario
* @param inv inventario en el que establecer el numero de objetos
* @param maxObjetos maximo de objetos a fijar en el inventario
* @return Devuelve FALSE si no se ha podido establecer ese numero maximo de objetos
*/
BOOL establece_max_objetos(Inventario * inv, int maxObjetos);


 /**
* @brief Libera la memoria reservada para un inventario
* @param inv inventario que se va a liberar
*/
void destruye_inventario(Inventario * inv);


 /**
* @brief Añade un nuevo objeto al inventario si este no existe ya.
* @param inv inventario al que añadir el objeto
* @param id Id del objeto que se añade al inventario
* @return Devuelve FALSE si no se ha podido añadir el objeto.
*/
BOOL nuevo_obj_inventario(Inventario * inv, Id id);


 /**
* @brief Busca un objeto con un ID dado.
* @param inv inventario en el que buscar el objeto
* @param id Id del objeto que se busca en el inventairo
* @return Devuelve FALSE si no se encuentra el objeto
*/
BOOL buscar_obj(Inventario * inv, Id id);

 /**
* @brief Elimina un objeto dado de un inventario
* @param inv inventario del que eliminar el objeto
* @param id Id del objeto que se quita del inventario
* @return Devuelve FALSE si no se encuentra el objeto
*/

BOOL quita_obj(Inventario * inv, Id id);

 /**
* @brief Devuelve el id de un objeto por su posicion
* @param inv inventario del que eliminar el objeto
* @param pos posicion
* @return Devuelve el Id, NO_ID si hay algun error
*/
Id devuelve_objeto_pos_id (Inventario *inv, int pos);
 /**
* @brief Devuelve el maximo de objetos
* @param inv inventario
* @return Numero maximo de objetos, -1 en caso de error
*/
int devuelve_max_obj (Inventario *inv);

 /**
* @brief Devuelve el numero de objetos del inventario
* @param inv inventario
* @return Numero de objetos, -1 en caso de error
*/
int devuelve_num_obj (Inventario *inv);

 /**
* @brief Indica si el inventario esta vacio
* @param inv inventario
* @return Devuelve si esta vacio, True si hay algun error
*/
BOOL es_vacio_inventario (Inventario *inv);

#endif	/* INVENTARIO_H */
