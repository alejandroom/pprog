/**
* @brief Utilidades de interaccion con espacio
*
* Este modulo contiene los prototipos de las funciones de manejo de
* espacios
* @file Espacio.h
* @author Irene Colmenar Guindal
* @version 1.0
* @date 1-05-2012
*/

#ifndef ESPACIO_H_
#define ESPACIO_H_

#include "Const.h"
#include "Conjunto.h"

/*TAD que representa un espacio en el mundo*/
typedef struct _Espacio Espacio;

/**
* @brief Crea un nuevo espacio.
* @return Devuelve un puntero a espacio, si no se ha podido crear se creara un puntero a NULL
*/
Espacio * nuevo_espacio(Id id);


/**
* @brief Destruye un espacio
* @param j jugador a espacio
*/
void destruye_espacio(Espacio * es);

/**
* @brief Establece una descripcion al espacio
* @param e espacio al que se le agrega una descripcion
* @param s cadena de caracteres que contiene la descripcion a anyadir
* @return Devuelve FALSE si no se ha podido poner la descripcion
*/
BOOL nueva_desc_examinar_espacio(Espacio * e, char * s);


/**
* @brief Establece una descripcion al espacio
* @param e espacio al que se le agrega una descripcion
* @param s cadena de caracteres que contiene la descripcion a anyadir
* @return Devuelve FALSE si no se ha podido poner la descripcion
*/
BOOL nueva_desc_espacio(Espacio * e, char * s);

/**
* @brief Establece una union entre el espacio actual y el que indica la id que recibe como argumento
* @param e espacio al que añadirle la union
* @param id Id de la union
* @return Devuelve FALSE si no se ha podido realizar la union
*/
BOOL nueva_union_norte_espacio(Espacio * e, Id id);


/**
* @brief Establece una union entre el espacio actual y el que indica la id que recibe como argumento
* @param e espacio al que añadirle la union
* @param id Id de la union
* @return Devuelve FALSE si no se ha podido realizar la union
*/
BOOL nueva_union_sur_espacio(Espacio * e, Id id);


/**
* @brief Establece una union entre el espacio actual y el que indica la id que recibe como argumento
* @param e espacio al que añadirle la union
* @param id Id de la union
* @return Devuelve FALSE si no se ha podido realizar la union
*/
BOOL nueva_union_este_espacio(Espacio * e, Id id);


/**
* @brief Establece una union entre el espacio actual y el que indica la id que recibe como argumento
* @param e espacio al que añadirle la union
* @param id Id de la union
* @return Devuelve FALSE si no se ha podido realizar la union
*/
BOOL nueva_union_oeste_espacio(Espacio * e, Id id);


/**
* @brief Establece una union entre el espacio actual y el que indica la id que recibe como argumento
* @param e espacio al que añadirle la union
* @param id Id de la union
* @return Devuelve FALSE si no se ha podido realizar la union
*/
BOOL nueva_union_arriba_espacio(Espacio * e, Id id);


/**
* @brief Establece una union entre el espacio actual y el que indica la id que recibe como argumento
* @param e espacio al que añadirle la union
* @param id Id de la union
* @return Devuelve FALSE si no se ha podido realizar la union
*/
BOOL nueva_union_abajo_espacio(Espacio * e, Id id);


/**
* @brief Anyade un objeto a un espacio
* @param e espacio al que anyadirle un objeto
* @param id Id del objeto a anyadir
* @return Devuelve FALSE si no se ha podido anyadir el objeto
*/
BOOL annade_objeto_espacio(Espacio * e, Id id);


/**
* @brief Quita un objeto de un espacio
* @param e espacio del que quitar el objeto
* @param id Id del objeto a quitar
* @return Devuelve FALSE si no se ha podido quitar el objeto
*/
BOOL quita_objeto_espacio(Espacio * es, Id id);


/**
* @brief Ilumina o apaga un espacio
* @param e espacio a modificar
* @param id indica si el espacio se va a apagar o a encender
* @return Devuelve FALSE si no se ha podido realizar encender o apagar el espacio
*/
BOOL actualiza_iluminacion_espacio(Espacio * e, BOOL id);


/**
* @brief Devuelve al descripcion del espacio
* @param es espacio del que se devuelve la descripcion
* @return Devuelve la cadena que contiene la descripcion del espacio, o null si ocurre algun error
*/
const char * desc_espacio(Espacio * es);


/**
* @brief Devuelve la descripcion al examinar un espacio
* @param e espacio dle que se devuelve la descripcion
* @return Devuelve la cadena que contiene la descripcion del espacio, o null si ocurre algun error
*/
const char * descexaminar_Espacio(Espacio * es);


/**
* @brief Devuelve la id del espacio del norte
* @param e espacio actual
* @return Devuelve el id del espacio del norte
*/
Id dame_norte_espacio(Espacio * es);


/**
* @brief Devuelve la id del espacio del sur
* @param e espacio actual
* @return Devuelve el id del espacio del sur
*/
Id dame_sur_espacio(Espacio * es);


/**
* @brief Devuelve la id del espacio del este
* @param e espacio actual
* @return Devuelve el id del espacio del este
*/
Id dame_este_espacio(Espacio * es);


/**
* @brief Devuelve la id del espacio del oeste
* @param e espacio actual
* @return Devuelve el id del espacio del oeste
*/
Id dame_oeste_espacio(Espacio * es);


/**
* @brief Devuelve la id del espacio del arriba
* @param e espacio actual
* @return Devuelve el id del espacio del arriba
*/
Id dame_arriba_espacio(Espacio * es);


/**
* @brief Devuelve la id del espacio del abajo
* @param e espacio actual
* @return Devuelve el id del espacio del abajo
*/
Id dame_abajo_espacio(Espacio * es);


/**
* @brief Imprime el espacio
* @param es espacio a imprimir
* @return Devuelve FALSE si ocurre algun error
*/
BOOL imprime_espacio(Espacio * es);


/**
* @brief Devuelve la id del espacio actual
* @param e espacio actual
* @return Devuelve el id del espacio del actual
*/
Id devuelve_id_espacio (Espacio *es);


/**
* @brief Devuelve el estado de luminosidad de un espacio
* @param esp del que devolver la luminosidad
* @return Devuelve el estado de la luminosidad del lugar
*/
BOOL devuelve_luz_espacio (Espacio *esp);

#endif
