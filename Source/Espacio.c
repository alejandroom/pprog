/**
* @brief Utilidades de interaccion con espacio
*
* Este modulo contiene las funciones de manejo de
* espacios
* @file Espacio.c
* @author Irene Colmenar Guindal
* @version 1.0
* @date 1-05-2012
*/

#include "Espacio.h"

/* Funciones para crear y destruir un espacio*/

struct _Espacio {
	Id id;
	char descripcion[TAMANO_PAL + 1];
	char descExaminar[TAMANO_PAL + 1];
	Id norte;
	Id sur;
	Id este;
	Id oeste;
	Id arriba;
	Id abajo;
	BOOL luz;
	Conjunto *objetos_espacio;
};

/**
* @brief Crea un nuevo espacio.
* @return Devuelve un puntero a espacio, si no se ha podido crear se creara un puntero a NULL
*/
Espacio * nuevo_espacio(Id id) {

	Espacio * es;

	if (id == NO_ID)
		return NULL;

	es = (Espacio*) malloc(sizeof (Espacio));

	es->id = id;
	es->norte = NO_ID;
	es->sur = NO_ID;
	es->este = NO_ID;
	es->oeste = NO_ID;
	es->arriba = NO_ID;
	es->abajo = NO_ID;
	es->luz=FALSE;
	es->objetos_espacio = nuevo_conjunto();
	es->descExaminar[0] = '\0';
	es->descripcion[0] = '\0';
	return es;
}

/**
* @brief Destruye un espacio
* @param j jugador a espacio
*/
void destruye_espacio(Espacio * es) {
	int i;
	destruye_conjunto(es->objetos_espacio);
	free(es);
}

/**
* @brief Establece una descripcion al espacio
* @param e espacio al que se le agrega una descripcion
* @param s cadena de caracteres que contiene la descripcion a anyadir
* @return Devuelve FALSE si no se ha podido poner la descripcion
*/
BOOL nueva_desc_examinar_espacio(Espacio * e, char * s){

	if (e == NULL || s == NULL)
		return FALSE;
	if (strlen(s) > TAMANO_PAL)
		return FALSE;
	strcpy(e->descExaminar, s);
	return TRUE;
}

/**
* @brief Establece una descripcion al espacio
* @param e espacio al que se le agrega una descripcion
* @param s cadena de caracteres que contiene la descripcion a anyadir
* @return Devuelve FALSE si no se ha podido poner la descripcion
*/
BOOL nueva_desc_espacio(Espacio * e, char * s){

	if (e == NULL || s == NULL)
		return FALSE;

	if (strlen(s) > TAMANO_PAL){
		return FALSE;
	}

	strcpy(e->descripcion, s);

	return TRUE;
}

/**
* @brief Establece una union entre el espacio actual y el que indica la id que recibe como argumento
* @param e espacio al que añadirle la union
* @param id Id de la union
* @return Devuelve FALSE si no se ha podido realizar la union
*/
BOOL nueva_union_norte_espacio(Espacio * e, Id id){

	if (e == NULL)
		return FALSE;
	e->norte = id;
	return TRUE;
}

/**
* @brief Establece una union entre el espacio actual y el que indica la id que recibe como argumento
* @param e espacio al que añadirle la union
* @param id Id de la union
* @return Devuelve FALSE si no se ha podido realizar la union
*/
BOOL nueva_union_sur_espacio(Espacio * e, Id id){

	if (e == NULL || id == NO_ID)
		return FALSE;
	e->sur = id;
	return TRUE;
}

/**
* @brief Establece una union entre el espacio actual y el que indica la id que recibe como argumento
* @param e espacio al que añadirle la union
* @param id Id de la union
* @return Devuelve FALSE si no se ha podido realizar la union
*/
BOOL nueva_union_este_espacio(Espacio * e, Id id){

	if (e == NULL || id == NO_ID)
		return FALSE;
	e->este = id;
	return TRUE;
}

/**
* @brief Establece una union entre el espacio actual y el que indica la id que recibe como argumento
* @param e espacio al que añadirle la union
* @param id Id de la union
* @return Devuelve FALSE si no se ha podido realizar la union
*/
BOOL nueva_union_oeste_espacio(Espacio * e, Id id){

	if (e == NULL || id == NO_ID)
		return FALSE;
	e->oeste = id;
	return TRUE;
}

/**
* @brief Establece una union entre el espacio actual y el que indica la id que recibe como argumento
* @param e espacio al que añadirle la union
* @param id Id de la union
* @return Devuelve FALSE si no se ha podido realizar la union
*/
BOOL nueva_union_arriba_espacio(Espacio * e, Id id){

	if (e == NULL || id == NO_ID)
		return FALSE;
	e->arriba = id;
	return TRUE;
}

/**
* @brief Establece una union entre el espacio actual y el que indica la id que recibe como argumento
* @param e espacio al que añadirle la union
* @param id Id de la union
* @return Devuelve FALSE si no se ha podido realizar la union
*/
BOOL nueva_union_abajo_espacio(Espacio * e, Id id){

	if (e == NULL || id == NO_ID)
		return FALSE;
	e->abajo = id;
	return TRUE;
}

/**
* @brief Anyade un objeto a un espacio
* @param e espacio al que anyadirle un objeto
* @param id Id del objeto a anyadir
* @return Devuelve FALSE si no se ha podido anyadir el objeto
*/
BOOL annade_objeto_espacio(Espacio * e, Id id){

	if (e == NULL)
		return FALSE;


	return incluye_id(e->objetos_espacio, id);
}

/**
* @brief Quita un objeto de un espacio
* @param e espacio del que quitar el objeto
* @param id Id del objeto a quitar
* @return Devuelve FALSE si no se ha podido quitar el objeto
*/
BOOL quita_objeto_espacio(Espacio *es, Id id) {
	if (es == NULL)
		return FALSE;
	quita_id(es->objetos_espacio, id);
}

/**
* @brief Devuelve la descripcion al examinar un espacio
* @param e espacio dle que se devuelve la descripcion
* @return Devuelve la cadena que contiene la descripcion del espacio, o null si ocurre algun error
*/
const char * descexaminar_Espacio(Espacio * es) {
	return es->descExaminar;
}

/**
* @brief Devuelve al descripcion del espacio
* @param es espacio del que se devuelve la descripcion
* @return Devuelve la cadena que contiene la descripcion del espacio, o null si ocurre algun error
*/
const char * desc_espacio(Espacio * es) {
	return es->descripcion;
}

/**
* @brief Ilumina o apaga un espacio
* @param e espacio a modificar
* @param id indica si el espacio se va a apagar o a encender
* @return Devuelve FALSE si no se ha podido realizar encender o apagar el espacio
*/
BOOL actualiza_iluminacion_espacio(Espacio * e, BOOL id){

	if (e == NULL)
		return FALSE;
	e->luz = id;

	return TRUE;
}

/**
* @brief Devuelve la id del espacio del norte
* @param e espacio actual
* @return Devuelve el id del espacio del norte
*/
Id dame_norte_espacio(Espacio * es) {

	if (es == NULL)
		return NO_ID;
	return es->norte;
}

/**
* @brief Devuelve la id del espacio del sur
* @param e espacio actual
* @return Devuelve el id del espacio del sur
*/
Id dame_sur_espacio(Espacio * es) {

	if (es == NULL)
		return NO_ID;
	return es->sur;
}

/**
* @brief Devuelve la id del espacio del este
* @param e espacio actual
* @return Devuelve el id del espacio del este
*/
Id dame_este_espacio(Espacio * es) {

	if (es == NULL)
		return NO_ID;
	return es->este;
}

/**
* @brief Devuelve la id del espacio del oeste
* @param e espacio actual
* @return Devuelve el id del espacio del oeste
*/
Id dame_oeste_espacio(Espacio * es) {

	if (es == NULL)
		return NO_ID;
	return es->oeste;
}

/**
* @brief Devuelve la id del espacio del arriba
* @param e espacio actual
* @return Devuelve el id del espacio del arriba
*/
Id dame_arriba_espacio(Espacio * es) {

	if (es == NULL)
		return NO_ID;
	return es->arriba;
}

/**
* @brief Devuelve la id del espacio del abajo
* @param e espacio actual
* @return Devuelve el id del espacio del abajo
*/
Id dame_abajo_espacio(Espacio * es) {
	if (es == NULL)
		return NO_ID;
	return es->abajo;
}

/**
* @brief Devuelve el estado de luminosidad de un espacio
* @param esp del que devolver la luminosidad
* @return Devuelve el estado de la luminosidad del lugar
*/
BOOL devuelve_luz_espacio(Espacio *esp) {

	return esp->luz;
}

/**
* @brief Imprime el espacio
* @param es espacio a imprimir
* @return Devuelve FALSE si ocurre algun error
*/
BOOL imprime_espacio(Espacio * es) {

	if (es == NULL)
		return FALSE;

	printf("%ld ", es->id);
	printf("%s ", es->descripcion);
	printf("%s ", es->descExaminar);
	printf("%ld ", es->norte);
	printf("%ld ", es->sur);
	printf("%ld ", es->este);
	printf("%ld ", es->oeste);
	printf("%ld ", es->arriba);
	printf("%ld ", es->abajo);
	printf("%d ", es->luz);
	imprime_conjunto(es->objetos_espacio);

	return TRUE;
}

/**
* @brief Devuelve la id del espacio actual
* @param e espacio actual
* @return Devuelve el id del espacio del actual
*/
Id devuelve_id_espacio(Espacio *es) {

	if (es == NULL)
		return NO_ID;
	return es->id;
}


/**
* @brief Devuelve si un objeto se encuentra en un espacio
* @param esp espacio
* @param id objeto a buscar
* @return Devuelve True o False segun corresponda
*/
BOOL esta_objeto_espacio(Espacio *esp, Id id){
	if(esp==NULL)
		return FALSE;

	return esta_id(esp->objetos_espacio, id);
}
