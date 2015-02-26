/**
* @brief Utilidades de manejo de objetos
*
* Este modulo contiene los prototipos
* de las funciones de manejo de
* objetos.
* @file Objeto.h
* @author Juan Manuel Cornet
* @version 2.0 Campos extras: tema, defensa y ataque. Y sus funciones correspondientes.
* @date 1-05-2012
*/

#ifndef OBJETO_H
#define	OBJETO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Conjunto.h"

typedef struct _objeto Objeto;

/**
* @brief Crea un nuevo objeto, reservando la memoria correspondiente e inilizalizando sus campos
* @param id identificador que tendra el nuevo objeto
* @return Objeto* nuevo objeto
*/
Objeto * nuevo_obj(Id id);

/**
* @brief Destruye el objeto, liberando la memoria correspondiente
* @param obj objeto a destruir
*/
void destruye_objeto(Objeto * obj);

/**
* @brief Asigna un nuevo tema al objeto
* @param obj objeto a modificar
* @param tema nuevo tema a asignar
* @return BOOL TRUE si se asigna, FALSE si el objeto es nulo
*/
BOOL nuevo_tema_objeto(Objeto * obj, int tema);

/**
* @brief Asigna un nuevo nombre al objeto
* @param o objeto a modificar
* @param s cadena con el nuevo nombre
* @return BOOL TRUE si se asigna, FALSE si el objeto es nulo
*/
BOOL nuevo_nombre_obj(Objeto * o, char * s);

/**
* @brief Asigna una nueva descripcion al objeto
* @param o objeto a modificar
* @param s cadena con la nueva descripcion
* @return BOOL TRUE si se asigna, FALSE si el objeto es nulo
*/
BOOL nueva_desc_obj(Objeto * o, char * s);

/**
* @brief Asigna una nueva descripcion de examinar al objeto
* @param o objeto a modificar
* @param s cadena con la nueva descripcion
* @return BOOL TRUE si se asigna, FALSE si el objeto es nulo
*/
BOOL nueva_desc_examinar_obj(Objeto * o, char * s);

/**
* @brief Asigna una nueva descripcion movil al objeto
* @param o objeto a modificar
* @param s cadena con la nueva descripcion
* @return BOOL TRUE si se asigna, FALSE si el objeto es nulo
*/
BOOL nueva_desc_movil_obj(Objeto * o, char * s);

/**
* @brief Asigna un nuevo valor al campo movil del objeto
* @param o objeto a modificar
* @param b valor a asignar
* @return BOOL TRUE si se asigna, FALSE si el objeto es nulo
*/
BOOL actualiza_movil_obj(Objeto * o, BOOL b);

/**
* @brief Asigna un nuevo valor al campo movido del objeto
* @param o objeto a modificar
* @param b valor a asignar
* @return BOOL TRUE si se asigna, FALSE si el objeto es nulo
*/
BOOL actualiza_movido_objeto(Objeto * obj, BOOL movido);

/**
* @brief Asigna un nuevo valor al campo iluminable del objeto
* @param o objeto a modificar
* @param b valor a asignar
* @return BOOL TRUE si se asigna, FALSE si el objeto es nulo
*/
BOOL actualiza_iluminable_obj(Objeto * o, BOOL b);

/**
* @brief Asigna un nuevo valor al campo ilumina del objeto
* @param o objeto a modificar
* @param b valor a asignar
* @return BOOL TRUE si se asigna, FALSE si el objeto es nulo
*/
BOOL actualiza_ilumina_obj(Objeto * o, BOOL b);

/**
* @brief Asigna un nuevo valor al campo oculto del objeto
* @param o objeto a modificar
* @param b valor a asignar
* @return BOOL TRUE si se asigna, FALSE si el objeto es nulo
*/
BOOL actualiza_oculto_objeto(Objeto * obj, BOOL oculto);

/**
* @brief Devuelve el valor del campo id del objeto
* @param o objeto cuya informacion buscamos
* @return Id id del objeto, NO_ID en caso de objeto nulo
*/
Id dame_id_objeto(Objeto * objeto);

/**
* @brief Devuelve el valor del campo tema del objeto
* @param o objeto cuya informacion buscamos
* @return int tema del objeto, -1 en caso de objeto nulo
*/
int dame_tema_objeto(Objeto * objeto);

/**
* @brief Devuelve el valor del campo nombre del objeto
* @param o objeto cuya informacion buscamos
* @return char* nombre del objeto, NULL en caso de objeto nulo
*/
const char* nombre_objeto(Objeto *obj);

/**
* @brief Devuelve el valor del campo descripcion del objeto
* @param o objeto cuya informacion buscamos
* @return char* descripcion del objeto, NULL en caso de objeto nulo
*/
const char * descripcion_objeto(Objeto * obj);

/**
* @brief Devuelve el valor del campo descMovido del objeto
* @param o objeto cuya informacion buscamos
* @return char* descMovido del objeto, NULL en caso de objeto nulo
*/
char * descripcion_objeto_movido(Objeto * obj);

/**
* @brief Devuelve el valor del campo descExaminar del objeto
* @param o objeto cuya informacion buscamos
* @return char* descExaminar del objeto, NULL en caso de objeto nulo
*/
const char * descripcion_objeto_examinar(Objeto * obj);

/**
* @brief Devuelve el valor del campo movil del objeto
* @param o objeto cuya informacion buscamos
* @return BOOL valor de el campo movil del objeto, FALSE en caso de objeto nulo
*/
BOOL es_movil_objeto(Objeto * obj);

/**
* @brief Devuelve el valor del campo movido del objeto
* @param o objeto cuya informacion buscamos
* @return BOOL valor de el campo movido del objeto, FALSE en caso de objeto nulo
*/
BOOL es_movido_objeto(Objeto * obj);

/**
* @brief Devuelve el valor del campo movido del objeto
* @param o objeto cuya informacion buscamos
* @return BOOL valor de el campo movido del objeto, FALSE en caso de objeto nulo
*/
BOOL ilumina_objeto(Objeto * obj);

/**
* @brief Devuelve el valor del campo encendido del objeto
* @param o objeto cuya informacion buscamos
* @return BOOL valor de el campo encendido del objeto, FALSE en caso de objeto nulo
*/
BOOL es_encendido_objeto(Objeto * obj);

/**
* @brief Devuelve el valor del campo oculto del objeto
* @param o objeto cuya informacion buscamos
* @return BOOL valor de el campo oculto del objeto, FALSE en caso de objeto nulo
*/
BOOL oculta_obj(Objeto * o);

/**
* @brief Imprime los datos del objeto por pantalla
* @param o objeto cuya informacion queremos imprimir
*/
void imprime_objeto(Objeto * obj);

/**
* @brief Asigna el valor def al campo defensa del objeto
* @param o objeto a actualizar
* @param def valor a asignar
* @return BOOL TRUE si se ha asignado bien, FALSE si el objeto es nulo
*/
BOOL establece_defensa(Objeto *o, int def);

/**
* @brief Asigna el valor atk al campo ataque del objeto
* @param o objeto a actualizar
* @param atk valor a asignar
* @return BOOL TRUE si se ha asignado bien, FALSE si el objeto es nulo
*/
BOOL establece_ataque(Objeto *o, int atk);

/**
* @brief Devuelve el valor del campo defensa del objeto
* @param o objeto cuya informacion queremos
* @return int valor del campo defensa, 0 en caso de objeto nulo
*/
int dame_def_obj(Objeto *o);

/**
* @brief Devuelve el valor del campo ataque del objeto
* @param o objeto cuya informacion queremos
* @return int valor del campo ataque, 0 en caso de objeto nulo
*/
int dame_atk_obj(Objeto *o);

#endif	/* OBJETO_H */

