/**
* @brief Utilidades de manejo de uniones
*
* Este modulo contiene las funciones de manejo de
* uniones.
* @file Union.c
* @author Irene Colmenar 
* @version 2.0 incluidos campos nombre y key y las modificaciones para manejarlos
* @date 1-05-2012
*/

#include "Union.h"

struct _Union {
	char nombre[TAMANO_PAL];
	Id id;
	Id espacio1;
	Id espacio2;
	BOOL abrible;
	BOOL cerrada;
	Id key;
};

/**
* @brief Crea una union, reservando la memoria e inicializando sus valores
* @param id identificador con que se inicializara la union
* @return Union* union resultante
*/
Union * nueva_union(Id id){
	Union * u;
	
	if (id == NO_ID)
		return NULL;
		
	u = (Union*) malloc(sizeof (Union));
	if (u==NULL){
		return NULL;
	}
	
	u->id = id;;
	u->espacio1=NO_ID;
	u->espacio2=NO_ID;
	u->key=NO_ID;
	
	return u;
}

/**
* @brief Destruye una union, liberando la memoria que tenga reservada
* @param u union a eliminar
*/
void destruye_union(Union * u){
	free(u);
}

/**
* @brief Asigna a los espacios de la union los valores dados
* @param u union a modificar
* @param id1 identificador del primer espacio
* @param id2 identificador del segundo espacio
* @return BOOL TRUE en caso de que los valores se asignen correctamente, FALSE en caso de que ocurra algun error
*/
BOOL une_espacios(Union * u, Id e1, Id e2){
	if (u == NULL || e1 == NO_ID || e2 == NO_ID)
		return FALSE;
		
	u->espacio1 = e1;
	u->espacio2 = e2;
	establece_abrible(u, TRUE); 
	
	return TRUE;
}

/**
* @brief Establece el valor del campo abrible de la union indicada
* @param u union a modificar
* @param b valor BOOL a asignar
* @return BOOL TRUE en caso de que los valores se asignen correctamente, FALSE en caso de que ocurra algun error
*/
BOOL establece_abrible(Union * u, BOOL b){ 
	if (u == NULL)
		return FALSE;
		
	u->abrible = b;
	
	return TRUE;
}

/**
* @brief Abre la union indicada
* @param u union a modificar
* @return BOOL TRUE en caso de que los valores se asignen correctamente, FALSE en caso de que ocurra algun error
*/
BOOL abre_union(Union * u){
	if (u == NULL)
		return FALSE;
		
	if (u->abrible==TRUE){
		u->cerrada = FALSE;
		return TRUE;
	}
	
	return FALSE;
}

/**
* @brief Cierra la union indicada
* @param u union a modificar
* @return BOOL TRUE en caso de que los valores se asignen correctamente, FALSE en caso de que ocurra algun error
*/
BOOL cierra_union(Union * u){
	if (u == NULL)
		return FALSE;
		
	u->cerrada = TRUE;
	
	return TRUE;
}

/**
* @brief Establece el valor del campo nombre de la union indicada
* @param u union a modificar
* @param nombre cadena de caracteres a asignar
* @return BOOL TRUE en caso de que los valores se asignen correctamente, FALSE en caso de que ocurra algun error
*/
BOOL escribe_nombreunion(Union *u, char *nombre){
	if(u==NULL || nombre==NULL)
		return FALSE;
		
	strcpy (u->nombre,nombre);
	
	return TRUE;
}

/**
* @brief Establece el valor del campo key de la union indicada
* @param u union a modificar
* @param key identificador a asignar
* @return BOOL TRUE en caso de que se escriba correctamente, FALSE en caso de que ocurra algun error
*/
BOOL escribe_key (Union * u, Id key){
	if (u==NULL)
		return FALSE;
		
	u->key=key;
	
	return TRUE;
}

/**
* @brief Devuelve el campo id de la union indicada
* @param u union cuya id se busca
* @return Id valor id de la union, NO_ID en casi de union nula
*/
Id devuelve_id_union(Union *u){
	if (u == NULL)
		return NO_ID;
		
	return u->id;
}

/**
* @brief Dada una union y un espacio, se devuelve el segundo espacio de la union
* @param u union cuyo segundo espacio se busca
* @param e1 id de uno de los espacios
* @return Id identificador del segundo espacio, NO_ID si la union es nula o si nu une el espacio dado
*/
Id dame_espacio_unido(Union * u, Id e1){
	if (u == NULL)
		return NO_ID;
		
	if (u->espacio1 == e1)
		return u->espacio2;
	else if (u->espacio2 == e1)
		return u->espacio1;
	else
		return NO_ID;
}

/**
* @brief Dada una union, devuelve el valor del campo abrible
* @param u union cuyo campo abrible se busca
* @return BOOL TRUE si es abrible, FALSE si no lo es o si la union es nula
*/
BOOL es_union_abrible(Union * u){
	if (u == NULL)
		return FALSE;
		
	return u->abrible;
}

/**
* @brief Dada una union, devuelve el valor del campo cerrada
* @param u union cuyo campo cerrada se busca
* @return BOOL TRUE si esta cerrada, FALSE si no lo esta o si la union es nula
*/
BOOL es_union_cerrada(Union * u){
	if (u==NULL){
		return TRUE;
	}
	
	return u->cerrada;
}

/**
* @brief Dada una union, devuelve el valor del campo nombre
* @param u union cuyo campo nombre se busca
* @return char* nombre de la union
*/
char* devuelve_nombreunion(Union *u){
	if (u==NULL)
		return NULL;
		
	return u->nombre;
}

/**
* @brief Dada una union, devuelve el valor del campo key
* @param u union cuyo campo key se busca
* @return Id identificador correspondiente al campo key, NO_ID si la union es nula
*/
Id devuelve_key (Union *u){
	if (u==NULL)
		return NO_ID;
		
	return u->key;
}

/**
* @brief Imprime la union dada, incluida para facilitar debugs
* @param u union que se quiere imprimir
*/
void imprime_union(Union * u){
	if (u == NULL){
		printf("Union nula\n\n");
		return;
	}
	
	printf("Nombre: %s\n", u->nombre);
	printf("Id: %ld\n", u->id);
	printf("Espacio 1: %ld\n", u->espacio1);
	printf("Espacio 2: %ld\n", u->espacio2);
	printf("Abrible: %d\n", u->abrible);
	printf("Cerrada: %d\n", u->cerrada);
	printf("Key: %ld\n\n", u->key);
}
