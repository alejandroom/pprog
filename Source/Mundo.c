/**
* @brief Utilidades de mundo
*
* Este modulo 
* @file Mundo.c
* @author Alejandro Ortiz, Irene Colmenar, Juan Manuel Cornet
* @date 1-05-2012
*/

#include "Const.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Mundo.h"

struct _mundo {
	Espacio * espacios[MAX_ESPACIOS + 1];
	Objeto * objetos[MAX_OBJETOS + 1];
	Union * uniones[MAX_UNIONES + 1];
	Jugador *jugador;
	int vida_malo;
	int vida_prota;
	int atk_malo;
};

/**
* @brief Crea un mundo
* @return Mundo retorna un mundo inicializado
*/ 
Mundo * nuevo_mundo() {
	Mundo * mundoini;
	mundoini = (Mundo*)malloc(sizeof (Mundo));

	mundoini->espacios[0] = NULL;
	mundoini->objetos[0] = NULL;
	mundoini->jugador = NULL;
	mundoini->uniones[0] = NULL;
	mundoini->vida_malo = 1200;
	mundoini->vida_prota = 100;
	mundoini->atk_malo = 5;
	return mundoini;
}

/**
* @brief Libera un mundo
* @param m mundo a liberar
*/ 
void destruye_mundo(Mundo * m) {
	
	int i = 0;

	destruye_jugador(m->jugador);

	while (m->espacios[i] != NULL) {
		destruye_espacio(m->espacios[i]);
		i++;
	}
	
	i=0;
	
	while (m->objetos[i] != NULL) {
		destruye_objeto(m->objetos[i]);
		i++;
	}

	i=0;
	
	while (m->uniones[i] != NULL) {
		destruye_union(m->uniones[i]);
		i++;
	}
	free(m);
}

 /**
* @brief Anyade un espacio a un mundo
* @param m Mundo al que anyadir el espacio
* @param id Id del espacio a anyadir
* @return espacio anyadido
*/ 
Espacio * annade_espacio_mundo(Mundo * m, Id id) {
	
	int posicion = 0, i;
	Id idaux;
	
	while (m->espacios[posicion] != NULL) {
		posicion++;
	}

	if (posicion == MAX_ESPACIOS) { // si el null esta en la ultima posicion entonces no se puede aÃ±adir mas espacios
		return NULL;
	}
	
	for (i=0; i<MAX_ESPACIOS; i++){
		idaux=devuelve_id_espacio(m->espacios[i]);
		if (idaux==NO_ID){
			break;
		}
		if (idaux==id){
			return NULL;
		}
	}
	
	m->espacios[posicion] = nuevo_espacio(id);
	m->espacios[posicion + 1] = NULL;
	
	return m->espacios[posicion];
}

/**
* @brief Anyade un objeto a un mundo
* @param m Mundo al que anyadir el objeto
* @param id Id del objeto a anyadir
* @return objeto anyadido
*/ 
Objeto * annade_objeto_mundo(Mundo * m, Id id) {
	
	int posicion = 0, i;
	Id idaux;

	while (m->objetos[posicion] != NULL) {
		posicion++;
	}

	if (posicion == MAX_OBJETOS) { // si el null estÃ¡ en la ultima posicion entonces no se puede aÃ±adir mas objetos
		return NULL;
	}
	
	for (i=0; i<MAX_OBJETOS && m->objetos[i]!=NULL; i++){
		idaux=dame_id_objeto(m->objetos[i]);
		if (idaux==id){
			return NULL;
		}
	}

	m->objetos[posicion] = nuevo_obj(id);
	m->objetos[posicion + 1] = NULL;
	return m->objetos[posicion];
}

/**
* @brief Anyade un jugador a un mundo
* @param m Mundo al que anyadir el jugador
* @return jugador anyadido
*/ 
Jugador * annade_jugador_mundo(Mundo * m) {
   
   m->jugador=nuevo_jugador();
   if (m->jugador==NULL){
	   return NULL;
   }
   
   return m->jugador;
}

/**
* @brief Anyade una union a un mundo
* @param m Mundo al que anyadir el espacio
* @param id Id de la union a anyadir
* @return union anyadida
*/
Union * annade_union_mundo(Mundo * m, Id id) {
	
	int posicion = 0, i;
	Id idaux;

	while (m->uniones[posicion] != NULL) {
		posicion++;
	}

	if (posicion == MAX_UNIONES) { // si el null estÃ¡ en la ultima posicion entonces no se puede aÃ±adir mas objetos
		return NULL;
	}

	for (i=0; i<MAX_UNIONES; i++){
		idaux=devuelve_id_union(m->uniones[i]);
		if (idaux==NO_ID){
			break;
		}
		if (idaux==id){
			return NULL;
		}
	}
	
	m->uniones[posicion] = nueva_union(id);
	m->uniones[posicion + 1] = NULL;
	return m->uniones[posicion];

}

 /**
* @brief Devuelve una referencia a un espacio de un mundo
* @param m Mundo del que devolver la referencia
* @param id Id del espacio a devolver
* @return espacio buscado o null si no se encuentra
*/ 
Espacio* dame_espacio_mundo(Mundo * m, Id id) {
	
	int i;
	Id idaux;
	
	if (m == NULL) {
		return NULL;
	}
	for (i = 0; i < MAX_ESPACIOS; i++) { // recorre todos los espacios
		idaux=devuelve_id_espacio(m->espacios[i]);
		if (idaux==NO_ID){
			break;
		}
		if (id == idaux) { // compara el id de 1 espacio con el id introducido
			return m->espacios[i]; // devuelve el espacio si coinciden
		}
	}
	return NULL;

}

 /**
* @brief Devuelve una referencia a un objeto de un mundo
* @param m Mundo del que devolver la referencia
* @param char nombre del objeto que devolver
* @return objeto buscado o null si no se encuentra
*/
Objeto * dame_objeto_por_nombre(Mundo *m, const char *nombre) {
	
	int i;
	
	if (nombre == NULL || m == NULL) {
		return NULL;
	}
	for (i = 0; i < MAX_OBJETOS; i++) {
		if (NULL==nombre_objeto(m->objetos[i])){
			return NULL;
		}
		if (strcmp(nombre, nombre_objeto(m->objetos[i])) == 0){
			return m->objetos[i]; 
		}
	}
	return NULL;
}

 /**
* @brief Devuelve una referencia a un espacio de un mundo
* @param m Mundo del que devolver la referencia
* @param id Id del objeto a devolver
* @return objeto buscado o null si no se encuentra
*/
Objeto * dame_objeto_mundo(Mundo * m, Id id) {
	
	int i;
	Id idaux;
	
	if (m == NULL) {
		return NULL;
	}
	for (i = 0; i < MAX_OBJETOS; i++) {// recorre todos los objetos
		idaux=dame_id_objeto(m->objetos[i]);
		if (idaux==NO_ID){
			break;
		}
		if (id == idaux)// compara el id de 1 objeto con el id introducido
		{
			return m->objetos[i]; // devuelve el objeto si coinciden
		}
	}
	return NULL; // si no devuelves null


}

 /**
* @brief Devuelve una referencia a un jugador de un mundo
* @param m Mundo del que devolver la referencia
* @return jugador buscado o null si no se encuentra 
*/
Jugador * dame_jugador_mundo(Mundo *m) {

	return m->jugador;

}

 /**
* @brief Devuelve una referencia a una union de un mundo
* @param m Mundo del que devolver la referencia
* @param id Id de la union a devolver
* @return union buscado o null si no se encuentra 
*/
Union * dame_union_mundo(Mundo *m, Id id) {
	
	int i;
	Id idaux;
	
	if (m == NULL) {
		return NULL;
	}
	for (i = 0; i < MAX_UNIONES; i++) {// recorre todas las uniones
		idaux=devuelve_id_union(m->uniones[i]);
		if (idaux==NO_ID){
			break;
		}
		if (id == idaux)// compara el id de 1 union con el id introducido
		{
			return m->uniones[i]; // devuelve el objeto si coinciden

		}
	}
	return NULL; // si no devuelves null
}

/**
* @brief Devuelve la localizacion de un jugador en un mundo
* @param m Mundo del que devolver la referencia
* @return id Id del jugador 
*/
Id dame_loc_jugador_mundo(Mundo * m) {
	
	if (m == NULL || m->jugador == NULL) {
		return NO_ID;
	}
	return (dame_loc_jugador(m->jugador)); // llama a la funcion de jugador que devuelve el id
}

 /**
* @brief Devuelve un espacio que esta al norte del actual
* @param m Mundo del que devolver la referencia
* @param id Id del espacio actual
* @return Espacio al norte 
*/
Espacio * dame_espacio_norte(Mundo * m, Id espacio) {

	Id idaux;

	if (m == NULL ) {
		return NULL;
	}

	idaux = dame_norte_espacio(dame_espacio_mundo(m, espacio));

	if (idaux == NO_ID) {
		return NULL;
	}
	if (es_union_cerrada(dame_union_mundo(m, idaux))==FALSE){
		return dame_espacio_mundo(m, dame_espacio_unido(dame_union_mundo(m, idaux), espacio));
	}
	
	return NULL; 
}

 /**
* @brief Devuelve un espacio que esta al sur del actual
* @param m Mundo del que devolver la referencia
* @param id Id del espacio actual
* @return Espacio al sur 
*/
Espacio * dame_espacio_sur(Mundo * m, Id espacio) {

	Id idaux;

	if (m == NULL ) {
		return NULL;
	}

	idaux = dame_sur_espacio(dame_espacio_mundo(m, espacio));

	if (idaux == NO_ID) {
		return NULL;
	}

	if (es_union_cerrada(dame_union_mundo(m, idaux))==FALSE){
		return dame_espacio_mundo(m, dame_espacio_unido(dame_union_mundo(m, idaux), espacio));
	}
	
	return NULL;
}

 /**
* @brief Devuelve un espacio que esta al este del actual
* @param m Mundo del que devolver la referencia
* @param id Id del espacio actual
* @return Espacio al este 
*/
Espacio * dame_espacio_este(Mundo * m, Id espacio) {
 
	Id idaux;
	if (m == NULL ) {
		return NULL;
	}
	idaux = dame_este_espacio(dame_espacio_mundo(m, espacio));
	if (idaux == NO_ID) {
		return NULL;
	}
	if (es_union_cerrada(dame_union_mundo(m, idaux))==FALSE){
		return dame_espacio_mundo(m, dame_espacio_unido(dame_union_mundo(m, idaux), espacio));
	}
	
	return NULL;
}

 /**
* @brief Devuelve un espacio que esta al oeste del actual
* @param m Mundo del que devolver la referencia
* @param id Id del espacio actual
* @return Espacio al oeste 
*/
Espacio * dame_espacio_oeste(Mundo * m, Id espacio) {
	
	Id idaux;
	if (m == NULL ) {
		return NULL;
	}
	idaux = dame_oeste_espacio(dame_espacio_mundo(m, espacio));
	if (idaux == NO_ID) {
		return NULL;
	}
	if (es_union_cerrada(dame_union_mundo(m, idaux))==FALSE){
		return dame_espacio_mundo(m, dame_espacio_unido(dame_union_mundo(m, idaux), espacio));
	}
	
	return NULL;
}

 /**
* @brief Devuelve un espacio que esta encima del actual
* @param m Mundo del que devolver la referencia
* @param id Id del espacio actual
* @return Espacio de arriba 
*/
Espacio * dame_espacio_arriba(Mundo * m, Id espacio) {
	
	Id idaux;
	if (m == NULL ) {
		return NULL;
	}
	idaux = dame_arriba_espacio(dame_espacio_mundo(m, espacio));
	if (idaux == NO_ID) {
		return NULL;
	}
	if (es_union_cerrada(dame_union_mundo(m, idaux))==FALSE){
		return dame_espacio_mundo(m, dame_espacio_unido(dame_union_mundo(m, idaux), espacio));
	}
	
	return NULL;
}

 /**
* @brief Devuelve un espacio que esta debajo del actual
* @param m Mundo del que devolver la referencia
* @param id Id del espacio actual
* @return Espacio de abajo 
*/
Espacio * dame_espacio_abajo(Mundo * m, Id espacio) {
	
	Id idaux;
	
	if (m == NULL ) {
		return NULL;
	}
	idaux = dame_abajo_espacio(dame_espacio_mundo(m, espacio));
	if (idaux == NO_ID) {
		return NULL;
	}
	if (es_union_cerrada(dame_union_mundo(m, idaux))==FALSE){
		return dame_espacio_mundo(m, dame_espacio_unido(dame_union_mundo(m, idaux), espacio));
	}
	
	return NULL;
}

  /**
* @brief Devuelve un objeto de un espacio
* @param m Mundo del que devolver la referencia
* @param nombre cadena de caracteres que identifica el objeto
* @param espacio Id del espacio del que obtener el objeto
* @return Objeto del espacio o null si no existe
*/
Objeto * dame_objeto_espacio(Mundo * m, const char * nombre, Id espacio) {
	
	Objeto *auxiliar;
	
	if (m == NULL || nombre == NULL) {
		return NULL;
	}

	auxiliar = dame_objeto_por_nombre(m, nombre);

	if (esta_objeto_espacio(dame_espacio_mundo(m, espacio), dame_id_objeto(auxiliar)) == TRUE) {
		return auxiliar;
	}
	
	return NULL;
}

 /**
* @brief Muestra la descripcion del espacio del jugador y de sus objetos visibles, sin incluir los ocultos
* @param m Mundo del que devolver la referencia
* @param nombre cadena de caracteres que identifica el objeto
* @return BOOL si ocurre algun error devuelve FALSE
*/
BOOL desc_real_espacio(Mundo * m, char * desc) {
	
	Espacio * espacio;
	
	if (m == NULL || desc == NULL){
		return FALSE;
	}

	espacio = dame_espacio_mundo(m, dame_loc_jugador_mundo(m));
	
	if(devuelve_luz_espacio (espacio)==FALSE){
		strcpy(desc, "No puedes ver nada ahi delante!! \n");
		return TRUE;	
	}

	strcpy(desc, desc_espacio(espacio));
	
	return TRUE;
}

 /**
* @brief Cambia la locaclizacion del jugador siempre que la estancia actual este conectada a la destino
* @param m Mundo en el que se produce el cambio
* @param dir Direccion en la que mover el personaje
* @return devuelve FALSE si se produce algun error como que no exista una union en esa direccion 
*		  o el mundo sea NULL, en caso contrario devuelve TRUE 
*/
BOOL mueve_personaje(Mundo * m, Direccion dir) {
	
	Id id;
	Espacio *auxiliar;
	char  linea[100];
	char  lineaux[100];
	
	id = dame_loc_jugador_mundo(m);
	if (dir == N) {
		auxiliar = dame_espacio_norte(m, id);
		if (auxiliar != NULL) {
			id = devuelve_id_espacio(auxiliar);
			if(id==BATALLA_FINAL){
				printf("En la siguiente sala se encuentra el malvado capitan pirata Long John Silver.\nUna vez entres no podras salir... \nDeseas continuar?   ");
				fgets(linea, 100, stdin);
				linea[strlen(linea)-1]='\0';
				elimina_cars(lineaux, linea, ";/:", strlen(linea));
				a_mayusculas(linea, lineaux, strlen(lineaux));
				limpia_espacios(lineaux, linea, strlen(linea));
				if(strcmp(linea, "SI")!=0)
					return FALSE;
				system("clear");
				printf("\t\tFINAL BOSS!!!\n\nLong John Silver se encuentra ante ti! No tiene cara de querer hacer amigos... usa lo que tengas para atacarle...\nSu TORSO, sus PIERNAS, su CABEZA y sus BRAZOS parecen las partes mas vulnerables!\n");
				establece_loc_jugador(m->jugador, id);
				
				return FINAL;
			}
			establece_loc_jugador(m->jugador, id);
			
			return TRUE;
		}
		return FALSE;
	}
	if (dir == S) {
		auxiliar = dame_espacio_sur(m, id);
		if (auxiliar != NULL) {
			id = devuelve_id_espacio(auxiliar);
			if(id==BATALLA_FINAL){
				printf("En la siguiente sala se encuentra el malvado capitan pirata Long John Silver.\nUna vez entres no podras salir... \nDeseas continuar?   ");
				fgets(linea, 100, stdin);
				linea[strlen(linea)-1]='\0';
				elimina_cars(lineaux, linea, ";/:", strlen(linea));
				a_mayusculas(linea, lineaux, strlen(lineaux));
				limpia_espacios(lineaux, linea, strlen(linea));
				if(strcmp(linea, "SI")!=0)
					return FALSE;
				system("clear");
				printf("\t\tFINAL BOSS!!!\n\nLong John Silver se encuentra ante ti! No tiene cara de querer hacer amigos... usa lo que tengas para atacarle...\nSu TORSO, sus PIERNAS, su CABEZA y sus BRAZOS parecen las partes mas vulnerables!\n");
				establece_loc_jugador(m->jugador, id);
				
				return FINAL;
			}
			establece_loc_jugador(m->jugador, id);
			
			return TRUE;
		}
		return FALSE;
	}
	if (dir == E) {
		auxiliar = dame_espacio_este(m, id);
		if (auxiliar != NULL) {
			id = devuelve_id_espacio(auxiliar);
			if(id==BATALLA_FINAL){
				printf("En la siguiente sala se encuentra el malvado capitan pirata Long John Silver.\nUna vez entres no podras salir... \nDeseas continuar?   ");
				fgets(linea, 100, stdin);
				linea[strlen(linea)-1]='\0';
				elimina_cars(lineaux, linea, ";/:", strlen(linea));
				a_mayusculas(linea, lineaux, strlen(lineaux));
				limpia_espacios(lineaux, linea, strlen(linea));
				if(strcmp(linea, "SI")!=0)
					return FALSE;
				system("clear");
				printf("\t\tFINAL BOSS!!!\n\nLong John Silver se encuentra ante ti! No tiene cara de querer hacer amigos... usa lo que tengas para atacarle...\nSu TORSO, sus PIERNAS, su CABEZA y sus BRAZOS parecen las partes mas vulnerables!\n");
				establece_loc_jugador(m->jugador, id);
				
				return FINAL;
			}
			establece_loc_jugador(m->jugador, id);
			
			return TRUE;
		}
		return FALSE;
	}
	if (dir == O) {
		auxiliar = dame_espacio_oeste(m, id);
		if (auxiliar != NULL) {
			id = devuelve_id_espacio(auxiliar);
			if(id==BATALLA_FINAL){
				printf("En la siguiente sala se encuentra el malvado capitan pirata Long John Silver.\nUna vez entres no podras salir... \nDeseas continuar?   ");
				fgets(linea, 100, stdin);
				linea[strlen(linea)-1]='\0';
				elimina_cars(lineaux, linea, ";/:", strlen(linea));
				a_mayusculas(linea, lineaux, strlen(lineaux));
				limpia_espacios(lineaux, linea, strlen(linea));
				if(strcmp(linea, "SI")!=0)
					return FALSE;
				system("clear");
				printf("\t\tFINAL BOSS!!!\n\nLong John Silver se encuentra ante ti! No tiene cara de querer hacer amigos... usa lo que tengas para atacarle...\nSu TORSO, sus PIERNAS, su CABEZA y sus BRAZOS parecen las partes mas vulnerables!\n");
				establece_loc_jugador(m->jugador, id);
				
				return FINAL;
			}
			establece_loc_jugador(m->jugador, id);
			
			return TRUE;
		}
		return FALSE;
	}
	if (dir == ABAJO) {
		auxiliar = dame_espacio_abajo(m, id);
		if (auxiliar != NULL) {
			id = devuelve_id_espacio(auxiliar);
			if(id==BATALLA_FINAL){
				printf("En la siguiente sala se encuentra el malvado capitan pirata Long John Silver.\nUna vez entres no podras salir... \nDeseas continuar?   ");
				fgets(linea, 100, stdin);
				linea[strlen(linea)-1]='\0';
				elimina_cars(lineaux, linea, ";/:", strlen(linea));
				a_mayusculas(linea, lineaux, strlen(lineaux));
				limpia_espacios(lineaux, linea, strlen(linea));
				if(strcmp(linea, "SI")!=0)
					return FALSE;
				system("clear");
				printf("\t\tFINAL BOSS!!!\n\nLong John Silver se encuentra ante ti! No tiene cara de querer hacer amigos... usa lo que tengas para atacarle...\nSu TORSO, sus PIERNAS, su CABEZA y sus BRAZOS parecen las partes mas vulnerables!\n");
				establece_loc_jugador(m->jugador, id);
				
				return FINAL;
			}
			establece_loc_jugador(m->jugador, id);
			
			return TRUE;
		}
		return FALSE;
	}
	if (dir == ARRIBA) {
		auxiliar = dame_espacio_arriba(m, id);
		if (auxiliar != NULL) {
			id = devuelve_id_espacio(auxiliar);
			if(id==BATALLA_FINAL){
				printf("En la siguiente sala se encuentra el malvado capitan pirata Long John Silver.\nUna vez entres no podras salir... \nDeseas continuar?   ");
				fgets(linea, 100, stdin);
				linea[strlen(linea)-1]='\0';
				elimina_cars(lineaux, linea, ";/:", strlen(linea));
				a_mayusculas(linea, lineaux, strlen(lineaux));
				limpia_espacios(lineaux, linea, strlen(linea));
				if(strcmp(linea, "SI")!=0)
					return FALSE;
				system("clear");
				printf("\t\tFINAL BOSS!!!\n\nLong John Silver se encuentra ante ti! No tiene cara de querer hacer amigos... usa lo que tengas para atacarle...\nSu TORSO, sus PIERNAS, su CABEZA y sus BRAZOS parecen las partes mas vulnerables!\n");
				establece_loc_jugador(m->jugador, id);
				
				return FINAL;
			}
			establece_loc_jugador(m->jugador, id);
			
			return TRUE;
		}
		return FALSE;
	}
	
	return FALSE;
}

 /**
* @brief Examina un espacio
* @param m Mundo del que devolver la referencia
* @param esp espacio a examinar
* @param desc cadena de caracteres en la que se guardara la descripcion del espacio
* @return BOOL FALSE si ocurriera algun error, en caso contrario TRUE
*/
BOOL examina_espacio(Mundo * m, Espacio * esp, char * desc) {

	if (devuelve_luz_espacio(esp) == TRUE){
		strcpy(desc, "Descripcion:\n");
		strcat(desc, descexaminar_Espacio(esp)); // copia la descripion de examinar del espacio 
		return TRUE;
	}
	
	return FALSE;
}

 /**
* @brief Examina un objeto
* @param m Mundo del que devolver la referencia
* @param esp objeto a examinar
* @param desc cadena de caracteres en la que se guardara la descripcion del objeto
* @return BOOL FALSE si ocurriera algun error, en caso contrario TRUE. 
*		En el caso de que el objeto estuviera oculto, deja de estarlo
*/
BOOL examina_objeto(Mundo * m, Objeto * obj, char * desc) {
	
	Id id2, idobjeto, id;
	Espacio * espacio;
	
	if (m==NULL || obj==NULL){
		return FALSE;
	}

	idobjeto=dame_id_objeto(obj);
	id2 = dame_loc_jugador_mundo(m);
	espacio=dame_espacio_mundo(m, id2);

	
	if (devuelve_luz_espacio(espacio)==FALSE){
		return FALSE;
	}
	
	id=dame_loc_obj(m, dame_id_objeto(obj));
	if (id!=id2){
		if (buscar_obj_inventario(m->jugador, idobjeto)==FALSE){
			return FALSE;
		}
	}

	strcpy (desc, "Descripcion:\n"); 
	strcat (desc, descripcion_objeto_examinar(obj));
	
	actualiza_oculto_objeto(obj, FALSE);
	
	return TRUE;
}

 /**
* @brief Coger un objeto que no este oculto, sea movil y haya hueco en el inventario dle jugador
* @param m Mundo del que devolver la referencia
* @param obj objeto a coger
* @return BOOL FALSE si ocurriera algun error, en caso contrario TRUE
*/
BOOL coge_objeto(Mundo * m, Objeto * obj) {
	
	Id id;
	BOOL bol;
	Espacio *espacio;

	id = dame_loc_jugador_mundo(m);
	if (id != dame_loc_obj(m, dame_id_objeto(obj))) { // Si el jugador no está en el espacio del objeto devuelve FALSE
		return FALSE;
	}
	bol = oculta_obj(obj);
	if (bol == FALSE) {
		printf("%s\n", descripcion_objeto_movido(obj));
		bol = es_movil_objeto(obj);
		if (bol == TRUE) {
			if (annade_objeto_jugador(m->jugador, dame_id_objeto(obj))==FALSE){ // añadimos el objeto al inventario
				return FALSE;
			}
			espacio = dame_espacio_mundo(m, dame_loc_obj(m, dame_id_objeto(obj)));
			if (quita_objeto_espacio(espacio, dame_id_objeto(obj))==FALSE){ // quitamos el objeto del espacio
				return FALSE;
			} 
			actualiza_movido_objeto(obj, TRUE);
			
			return TRUE;
		}
		return FALSE;

	}
	
	return FALSE;
}

/**
* @brief Deja un objeto del inventario en el espacio en el que se encuentre el jugador
* @param m Mundo del que devolver la referencia
* @param obj objeto a dejar
* @return BOOL FALSE si ocurriera algun error, en caso contrario TRUE
*/
BOOL deja_objeto(Mundo * m, Objeto * obj) {

	Id id;
	Espacio * espacio;
	
	if (buscar_obj_inventario(m->jugador, dame_id_objeto(obj))==FALSE){
		return FALSE;
	}

	if (quita_obj_inventario(m->jugador, dame_id_objeto(obj))==FALSE){ // lo quitamos del inventario	
		return FALSE;
	}
	
	espacio = dame_espacio_mundo(m, dame_loc_jugador(m->jugador));
	id = dame_id_objeto(obj);
	
	if (annade_objeto_espacio(espacio, id)==FALSE){ // lo añadimos al espaciO
		annade_objeto_jugador(m->jugador, dame_id_objeto(obj));
		return FALSE;
	}
	
	return TRUE;
}

 /**
* @brief Enciende un objeto que sea iluminable y que se encuentre en el inventario o en el espacio actual
* @param m Mundo del que devolver la referencia
* @param obj objeto a encender
* @return BOOL FALSE si ocurriera algun error, en caso contrario TRUE
*		Modifica el campo de luminosidad de un objeto a encendido
*/
BOOL enciende(Mundo * m, Objeto * obj) {
	
	BOOL objetoeninventario, objetoensala = FALSE;
	Id id;
	
	id = dame_loc_jugador_mundo(m);

	if (id == dame_loc_obj(m, dame_id_objeto(obj)))
		objetoensala = TRUE;

	objetoeninventario = buscar_obj_inventario(m->jugador, dame_id_objeto(obj));
	if (objetoeninventario == TRUE || objetoensala == TRUE) {
		if(ilumina_objeto(obj)==FALSE){
			return FALSE;
		}
		return actualiza_ilumina_obj(obj, TRUE);
	}
	return FALSE;
}
 /**
* @brief Apaga un objeto que sea iluminable y que se encuentre en el inventario o en el espacio actual
* @param m Mundo del que devolver la referencia
* @param obj objeto a apagar
* @return BOOL FALSE si ocurriera algun error, en caso contrario TRUE
*		Modifica el campo de luminosidad de un objeto a apagado
*/
BOOL apaga(Mundo * m, Objeto * obj) {
	BOOL bol, objetoensala = FALSE;
	Id id;
	
	id = dame_loc_jugador_mundo(m);
   
	if (id == dame_loc_obj(m, dame_id_objeto(obj))) {
		objetoensala = TRUE;
	}

	bol = buscar_obj_inventario(m->jugador, dame_id_objeto(obj));
	if (bol == TRUE || objetoensala == TRUE)
		if (ilumina_objeto(obj) == TRUE)
			return actualiza_ilumina_obj(obj, bol);
		return FALSE;
	return FALSE;
}

 /**
* @brief Ilumina un espacio si hay un objeto en la sala o en el inventario encendido
* @param m Mundo del que devolver la referencia
* @param esp espacio a encender 
* @return BOOL FALSE si ocurriera algun error, en caso contrario TRUE
*		Modifica el campo de luminosidad de un espacio a encnedido
*/
BOOL ilumina_espacio(Mundo * m, Espacio * esp) {
	
	int i;
	Objeto * objeto;  
	BOOL ilumina, encendido, objetoeninventario;

	if (dame_loc_jugador_mundo(m) != devuelve_id_espacio(esp)) { // Si el jugador no está en el espacio devuelve false
		return FALSE;
	}

	for (i = 0; i < MAX_OBJETOS; i++) { // Buscamos si hay algun objeto encendido en la sala
		objeto = dame_objeto_espacio(m, nombre_objeto(m->objetos[i]), devuelve_id_espacio(esp));
		if (objeto != NULL) {
			encendido = es_encendido_objeto(m->objetos[i]);
			if (encendido == TRUE) { 
				actualiza_iluminacion_espacio(esp, TRUE);
				return TRUE;
			}
		}
	}

	for (i = 0; i < MAX_OBJETOS; i++) { // Buscamos si hay algun objeto encendido en el espacio
		objetoeninventario = buscar_obj_inventario(m->jugador, dame_id_objeto(m->objetos[i]));
		if (objetoeninventario == TRUE) {
			encendido = es_encendido_objeto(m->objetos[i]);
			if (encendido == TRUE) {
				actualiza_iluminacion_espacio(esp, TRUE);
				return TRUE;
			}
		}
	}
	return FALSE;
}

 /**
* @brief Apaga el espacio, si es posible
* @param m Mundo en que se encuentra el espacio
* @param esp espacio que apagar
* @return BOOL TRUE si se apaga el espacio, FALSE si no es asi o si hay algun error
*/
BOOL apaga_espacio(Mundo * m, Espacio * esp) {
	
	int i;
	Objeto * objeto;  
	BOOL apagado, objetoeninventario;

   	if (dame_loc_jugador_mundo(m) != devuelve_id_espacio(esp)) { // Si el jugador no está en el espacio que quiere encender devuelve false
			return FALSE;
		}

	if(devuelve_luz_espacio(esp)==FALSE)
		return FALSE;

//Comprueba si hay algún objeto en la sala encendido
   
	for (i = 0; i < MAX_OBJETOS; i++) { // Comprobamos si algun objeto en la sala esta encendido
		objeto = dame_objeto_espacio(m, nombre_objeto(m->objetos[i]), devuelve_id_espacio(esp));
		if (objeto != NULL) {
			apagado = es_encendido_objeto(m->objetos[i]);
			if ( apagado == TRUE) { // Si el objeto está apagado no hacemos nada
		return FALSE;
			}
		}
	}

//Comprueba si hay algún objeto en el inventario encendido
	for (i = 0; i < MAX_OBJETOS; i++) { // comparamos si hay algun objeto en la sala encendido 
		objetoeninventario = buscar_obj_inventario(m->jugador, dame_id_objeto(m->objetos[i]));
		if (objetoeninventario == TRUE) {
			apagado = es_encendido_objeto(m->objetos[i]);
			if (apagado == TRUE) { 
				return FALSE;
			}
		}
	}

	return actualiza_iluminacion_espacio(esp, FALSE);

}

 /**
* @brief Devuelve la localizacion de un objeto
* @param m Mundo del que devolver la referencia
* @param id del objeto del que devolver al referencia
* @return Id Devuelve el id del espacio en el que se encuentra el objeto
*/
Id dame_loc_obj(Mundo *m, Id id){
	int i;
	for(i=0;i<MAX_ESPACIOS && m->espacios[i]!=NULL;i++)
		if(esta_objeto_espacio(m->espacios[i], id)==TRUE)
			return devuelve_id_espacio(m->espacios[i]);
	return NO_ID;
}

 /**
* @brief Devuelve el numero de tema del objeto
* @param m Mundo en que buscar
* @param nombre nombre del objeto
* @return int numero del tema, -1 si hay algun error
*/
int dame_tema(Mundo *m, char *nombre){
	Objeto *obj;
	Id id;
	
	obj = dame_objeto_por_nombre(m, nombre);
	if(obj==NULL)
		return -1;
	if(oculta_obj(obj) == TRUE)
		return -1;
		
	id = dame_loc_obj(m, dame_id_objeto(obj));
	if(id != dame_loc_jugador_mundo(m))
		if(buscar_obj_inventario(m->jugador, dame_id_objeto(obj))==FALSE)
			return -1;

	return dame_tema_objeto(obj);
}

 /**
* @brief Abre una union
* @param m Mundo del que devolver la referencia
* @param u union a abrir
* @return BOOL devuelve TRUE si todo se produce correctamente, en caso contrario FALSE
* 		Si la union es abrible y el objeto necesario esta disponible, 
*		el campo de abrible de union se pone a TRUE
*/
BOOL abre_union_mundo (Mundo *m, Union *u){
	int i;
	if (u==NULL || m ==NULL)
		return FALSE;

	if (dame_espacio_unido(u, dame_loc_jugador_mundo(m))==NO_ID)
		return FALSE;
	if (es_union_abrible(u)==FALSE)
		return FALSE;
	if (es_union_cerrada(u)==FALSE)
		return FALSE;
	if(buscar_obj_inventario(m->jugador, devuelve_key (u))==TRUE)
		return (abre_union(u));
	return FALSE;
}

 /**
* @brief Busca una union por su nombre
* @param m Mundo del que devolver la referencia
* @param nombre cadena de caracteres que indica el nombre de la union
* @return si se encuentra la union, la devuelve, y si no, NULL
*/
Union * dame_union_por_nombre(Mundo *m, char *nombre){

	int i;
	
	if (nombre == NULL || m == NULL) {
		return NULL;
	}
	for (i = 0; i < MAX_UNIONES; i++) {
		if (NULL==devuelve_nombreunion(m->uniones[i])){
			return NULL;
		}
		if(devuelve_nombreunion(m->uniones[i]) != NULL)
			if (strcmp(nombre, devuelve_nombreunion(m->uniones[i])) == 0){
				return m->uniones[i]; 
			}
	}
	return NULL;
}

 /**
* @brief Devuelve una lista de los objetos del inventario en la cadena cad
* @param m Mundo de cuyo inventario se quiere la descripcion
* @param cad cadena donde guardar el resultado
* @return BOOL TRUE si se examina con exito, FALSE si no es asi o si hay algun error
*/
BOOL examina_inventario (Mundo *m, char *cad){
	Inventario *inv;
	Objeto *obj;
	int i;
	char nombre[TAMANO_PAL];
	if (m == NULL || cad == NULL)
		return FALSE;

	inv=devuelve_inventario(m->jugador);
	if (inv==NULL){
		return FALSE;
	}
	strcpy(cad,"\nObjetos: \n");
	if (es_vacio_inventario (inv)==TRUE){
		strcpy(cad,"No hay objetos\n");
		return TRUE;
	}
	for (i=0;i<devuelve_num_obj(inv);i++){
		obj=dame_objeto_mundo(m, devuelve_objeto_pos_id (inv, i));
		if (obj==NULL)
			return FALSE;
		strcpy(nombre,nombre_objeto(obj));
			if (nombre !=NULL){
				strcat(cad,"\t");
				strcat(cad,nombre);
				strcat(cad,"\n");
			}
	}
	return TRUE;
}

 /**
* @brief Ejecuta la batalla final. Mas informacion en la memoria del modulo mundo
* @param m Mundo sobre el que se ejecuta
* @param cadena lo que se ataca
* @return entero Dependiendo del resultado. Mas informacion en la documentacion tecnica.
*/
int ejecuta_final(Mundo *m, char *cadena){
	int prob = (rand() % 99)+1;
	int efectuado = (rand() % dame_ataque_jugador(m)) + 10;
	int recibido = (rand() % m->atk_malo) + m->atk_malo - dame_defensa_jugador(m); 
	if(dame_loc_jugador_mundo(m)!=BATALLA_FINAL)
		return -1;

	if(strcmp(cadena, "CABEZA")==0){
		if(prob<20){		/*basic*/
			m->vida_malo=m->vida_malo-efectuado;
			sprintf(cadena, "%d", m->vida_malo);
			if(m->vida_malo<=0)
				return 4;
			return 2;
		}else if(prob>60){	/*crit*/
			m->vida_malo=m->vida_malo-(efectuado*3);
			sprintf(cadena, "%d", m->vida_malo);
			if(m->vida_malo<=0)
				return 4;
			return 1;
		}else{	 			/*fail*/
			if(recibido>0)
				m->vida_prota=m->vida_prota-recibido;
			sprintf(cadena, "%d", m->vida_prota);
			if(m->vida_prota<=0)
				return 5;
			return 3;
		}
	}
	else if(strcmp(cadena, "PIERNAS")==0){
		if(prob<50){
			m->vida_malo=m->vida_malo-efectuado;
			sprintf(cadena, "%d", m->vida_malo);
			if(m->vida_malo<=0)
				return 4;
			return 2;
		}else if(prob>80){
			m->vida_malo=m->vida_malo-(efectuado*3);
			sprintf(cadena, "%d", m->vida_malo);
			if(m->vida_malo<=0)
				return 4;
			return 1;
		}else{
			if(recibido>0)
				m->vida_prota=m->vida_prota-recibido;
			sprintf(cadena, "%d", m->vida_prota);
			if(m->vida_prota<=0)
				return 5;
			return 3;
		}
	}
	else if(strcmp(cadena, "TORSO")==0){
		if(prob<30){
			m->vida_malo=m->vida_malo-efectuado;
			sprintf(cadena, "%d", m->vida_malo);
			if(m->vida_malo<=0)
				return 4;
			return 2;
		}else if(prob>80){
			m->vida_malo=m->vida_malo-(efectuado*3);
			sprintf(cadena, "%d", m->vida_malo);
			if(m->vida_malo<=0)
				return 4;
			return 1;
		}else{
			if(recibido>0)
				m->vida_prota=m->vida_prota-recibido;
			sprintf(cadena, "%d", m->vida_prota);
			if(m->vida_prota<=0)
				return 5;
			return 3;
		}
	}
	else if(strcmp(cadena, "BRAZOS")==0){
		if(prob<70){
			m->vida_malo=m->vida_malo-efectuado;
			sprintf(cadena, "%d", m->vida_malo);
			if(m->vida_malo<=0)
				return 4;
			return 2;
		}else if(prob>100){
			m->vida_malo=m->vida_malo-(efectuado*3);
			sprintf(cadena, "%d", m->vida_malo);
			if(m->vida_malo<=0)
				return 4;
			return 1;
		}else{
			if(recibido>0)
				m->vida_prota=m->vida_prota-recibido;
			sprintf(cadena, "%d", m->vida_prota);
			if(m->vida_prota<=0)
				return 5;
			return 3;
		}
	}
	else if(strcmp(cadena, "LORO")==0){
		return 4;
	}
	else{
		if(recibido>0)
			m->vida_prota=m->vida_prota-recibido;
		sprintf(cadena, "%d", m->vida_prota);
		if(m->vida_prota<=0)
			return 5;
		return 3;
	}
}

 /**
* @brief Devuelve la defensa del jugador (la suma de las defensas de los objetos del inventario)
* @param m Mundo que manejar
* @return int defensa del jugador, 0 si algo falla
*/
int dame_defensa_jugador (Mundo *m){
	Inventario *inv;
	Objeto *obj;
	int i;
	int defensa = 0;
	
	if (m == NULL)
		return FALSE;

	inv=devuelve_inventario(m->jugador);
	if (inv==NULL)
		return FALSE;
	for (i=0;i<devuelve_num_obj(inv);i++){
		obj=dame_objeto_mundo(m, devuelve_objeto_pos_id (inv, i));
		if (obj!=NULL)
			defensa+=dame_def_obj(obj);
	}
	return defensa;
}

 /**
* @brief Devuelve el ataque del jugador (la suma de los ataques de los objetos del inventario)
* @param m Mundo que manejar
* @return int ataque del jugador, 0 si algo falla
*/
int dame_ataque_jugador (Mundo *m){
	Inventario *inv;
	Objeto *obj;
	int i;
	int ataque = 0;
	
	if (m == NULL)
		return 0;

	inv=devuelve_inventario(m->jugador);
	if (inv==NULL)
		return 0;
	for (i=0;i<devuelve_num_obj(inv);i++){
		obj=dame_objeto_mundo(m, devuelve_objeto_pos_id (inv, i));
		if (obj!=NULL)
			ataque+=dame_atk_obj(obj);
	}
	return ataque;
}

 /**
* @brief Inicializa la dificultad
* @param m Mundo sobre el que se ejecuta
* @param dificultad cadena con la dificultad escogido
*/
void inicializa_dificultad(Mundo *m, char *dificultad){
	if(m==NULL || dificultad==NULL)
		return;
	
	if(strcmp(dificultad, "facil")==0){	
		m->vida_malo = 1200;
		m->atk_malo = 20;
		m->vida_prota = 100;
	}
	else if(strcmp(dificultad, "medio")==0){
		m->vida_malo = 2000;
		m->atk_malo = 50;
		m->vida_prota = 150;
	}
	else if(strcmp(dificultad, "dificil")==0){
		m->vida_malo = 3000;
		m->atk_malo = 100;
		m->vida_prota =200;
	}
}
