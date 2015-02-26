/**
* @brief Utilidades de mundo
*
* Este modulo 
* @file Mundo.h
* @author Juan Manuel Cornet, Alejandro Ortiz, Irene Colmenar
* @date 1-05-2012
*/

#ifndef MUNDO_H_
#define MUNDO_H_
typedef struct _mundo Mundo;

#include "Const.h"
#include "Union.h"
#include "Espacio.h"
#include "Objeto.h"
#include "Jugador.h"

/**
* @brief Crea un mundo
* @return Mundo retorna un mundo inicializado
*/ 
Mundo * nuevo_mundo();

/**
* @brief Libera un mundo
* @param m mundo a liberar
*/ 
void destruye_mundo(Mundo * m);

 /**
* @brief Anyade un espacio a un mundo
* @param m Mundo al que anyadir el espacio
* @param id Id del espacio a anyadir
* @return espacio anyadido
*/ 
Espacio * annade_espacio_mundo(Mundo * m, Id id);


/**
* @brief Anyade un objeto a un mundo
* @param m Mundo al que anyadir el objeto
* @param id Id del objeto a anyadir
* @return objeto anyadido
*/ 
Objeto * annade_objeto_mundo(Mundo * m, Id id);


/**
* @brief Anyade un jugador a un mundo
* @param m Mundo al que anyadir el jugador
* @return jugador anyadido
*/ 
Jugador * annade_jugador_mundo(Mundo * m);

/**
* @brief Anyade una union a un mundo
* @param m Mundo al que anyadir el espacio
* @param id Id de la union a anyadir
* @return union anyadida
*/
Union * annade_union_mundo(Mundo * m, Id id);


 /**
* @brief Devuelve una referencia a un espacio de un mundo
* @param m Mundo del que devolver la referencia
* @param id Id del espacio a devolver
* @return espacio buscado o null si no se encuentra
*/ 
Espacio* dame_espacio_mundo(Mundo * m, Id id);

 /**
* @brief Devuelve una referencia a un objeto de un mundo
* @param m Mundo del que devolver la referencia
* @param char nombre del objeto que devolver
* @return objeto buscado o null si no se encuentra
*/
Objeto * dame_objeto_por_nombre (Mundo *m,const char *nombre); 

 
 /**
* @brief Devuelve una referencia a un espacio de un mundo
* @param m Mundo del que devolver la referencia
* @param id Id del objeto a devolver
* @return objeto buscado o null si no se encuentra
*/
Objeto * dame_objeto_mundo(Mundo * m, Id id); 


 /**
* @brief Devuelve una referencia a un jugador de un mundo
* @param m Mundo del que devolver la referencia
* @return jugador buscado o null si no se encuentra 
*/
Jugador* dame_jugador_mundo(Mundo *m);


 /**
* @brief Devuelve una referencia a una union de un mundo
* @param m Mundo del que devolver la referencia
* @param id Id de la union a devolver
* @return union buscado o null si no se encuentra 
*/
Union*   dame_union_mundo(Mundo *m,Id id);


/**
* @brief Devuelve la localizacion de un jugador en un mundo
* @param m Mundo del que devolver la referencia
* @return id Id del jugador 
*/
Id dame_loc_jugador_mundo(Mundo * m); 


 /**
* @brief Devuelve un espacio que esta al norte del actual
* @param m Mundo del que devolver la referencia
* @param id Id del espacio actual
* @return Espacio al norte 
*/
Espacio * dame_espacio_norte(Mundo * m, Id espacio);


 /**
* @brief Devuelve un espacio que esta al sur del actual
* @param m Mundo del que devolver la referencia
* @param id Id del espacio actual
* @return Espacio al sur 
*/
Espacio * dame_espacio_sur(Mundo * m, Id espacio);


 /**
* @brief Devuelve un espacio que esta al este del actual
* @param m Mundo del que devolver la referencia
* @param id Id del espacio actual
* @return Espacio al este 
*/
Espacio * dame_espacio_este(Mundo * m, Id espacio);


 /**
* @brief Devuelve un espacio que esta al oeste del actual
* @param m Mundo del que devolver la referencia
* @param id Id del espacio actual
* @return Espacio al oeste 
*/
Espacio * dame_espacio_oeste(Mundo * m, Id espacio);


 /**
* @brief Devuelve un espacio que esta encima del actual
* @param m Mundo del que devolver la referencia
* @param id Id del espacio actual
* @return Espacio de arriba 
*/
Espacio * dame_espacio_arriba(Mundo * m, Id espacio);


 /**
* @brief Devuelve un espacio que esta debajo del actual
* @param m Mundo del que devolver la referencia
* @param id Id del espacio actual
* @return Espacio de abajo 
*/
Espacio * dame_espacio_abajo(Mundo * m, Id espacio);


  /**
* @brief Devuelve un objeto de un espacio
* @param m Mundo del que devolver la referencia
* @param nombre cadena de caracteres que identifica el objeto
* @param espacio Id del espacio del que obtener el objeto
* @return Objeto del espacio o null si no existe
*/
Objeto * dame_objeto_espacio(Mundo * m, const char * nombre, Id espacio);


 /**
* @brief Muestra la descripcion del espacio del jugador y de sus objetos visibles, sin incluir los ocultos
* @param m Mundo del que devolver la referencia
* @param nombre cadena de caracteres que identifica el objeto
* @return BOOL si ocurre algun error devuelve FALSE
*/
BOOL desc_real_espacio(Mundo * m, char * desc);


 /**
* @brief Cambia la locaclizacion del jugador siempre que la estancia actual este conectada a la destino
* @param m Mundo en el que se produce el cambio
* @param dir Direccion en la que mover el personaje
* @return devuelve FALSE si se produce algun error como que no exista una union en esa direccion 
*		  o el mundo sea NULL, en caso contrario devuelve TRUE 
*/
BOOL mueve_personaje (Mundo * m, Direccion dir);

 /**
* @brief Examina un espacio
* @param m Mundo del que devolver la referencia
* @param esp espacio a examinar
* @param desc cadena de caracteres en la que se guardara la descripcion del espacio
* @return BOOL FALSE si ocurriera algun error, en caso contrario TRUE
*/
BOOL examina_espacio(Mundo * m, Espacio * esp, char * desc);


 /**
* @brief Examina un objeto
* @param m Mundo del que devolver la referencia
* @param esp objeto a examinar
* @param desc cadena de caracteres en la que se guardara la descripcion del objeto
* @return BOOL FALSE si ocurriera algun error, en caso contrario TRUE. 
*		En el caso de que el objeto estuviera oculto, deja de estarlo
*/
BOOL examina_objeto(Mundo * m, Objeto * esp, char * desc);


 /**
* @brief Coger un objeto que no este oculto, sea movil y haya hueco en el inventario dle jugador
* @param m Mundo del que devolver la referencia
* @param obj objeto a coger
* @return BOOL FALSE si ocurriera algun error, en caso contrario TRUE
*/
BOOL coge_objeto(Mundo * m, Objeto * obj); 


/**
* @brief Deja un objeto del inventario en el espacio en el que se encuentre el jugador
* @param m Mundo del que devolver la referencia
* @param obj objeto a dejar
* @return BOOL FALSE si ocurriera algun error, en caso contrario TRUE
*/
BOOL deja_objeto(Mundo * m, Objeto * obj); 


 /**
* @brief Enciende un objeto que sea iluminable y que se encuentre en el inventario o en el espacio actual
* @param m Mundo del que devolver la referencia
* @param obj objeto a encender
* @return BOOL FALSE si ocurriera algun error, en caso contrario TRUE
*		Modifica el campo de luminosidad de un objeto a encendido
*/
BOOL enciende(Mundo * m, Objeto * obj); 


 /**
* @brief Apaga un objeto que sea iluminable y que se encuentre en el inventario o en el espacio actual
* @param m Mundo del que devolver la referencia
* @param obj objeto a apagar
* @return BOOL FALSE si ocurriera algun error, en caso contrario TRUE
*		Modifica el campo de luminosidad de un objeto a apagado
*/
 BOOL apaga(Mundo * m, Objeto * obj); 


 /**
* @brief Ilumina un espacio si hay un objeto en la sala o en el inventario encendido
* @param m Mundo del que devolver la referencia
* @param esp espacio a encender 
* @return BOOL FALSE si ocurriera algun error, en caso contrario TRUE
*		Modifica el campo de luminosidad de un espacio a encnedido
*/
BOOL ilumina_espacio(Mundo * m, Espacio * esp); 


 /**
* @brief Devuelve la localizacion de un objeto
* @param m Mundo del que devolver la referencia
* @param id del objeto del que devolver al referencia
* @return Id Devuelve el id del espacio en el que se encuentra el objeto
*/
Id dame_loc_obj(Mundo *m, Id id);


 /**
* @brief Abre una union
* @param m Mundo del que devolver la referencia
* @param u union a abrir
* @return BOOL devuelve TRUE si todo se produce correctamente, en caso contrario FALSE
* 		Si la union es abrible y el objeto necesario esta disponible, 
*		el campo de abrible de union se pone a TRUE
*/
BOOL abre_union_mundo (Mundo *m, Union *u);


 /**
* @brief Busca una union por su nombre
* @param m Mundo del que devolver la referencia
* @param nombre cadena de caracteres que indica el nombre de la union
* @return si se encuentra la union, la devuelve, y si no, NULL
*/
Union * dame_union_por_nombre(Mundo *m, char *nombre);


 /**
* @brief Devuelve el numero de tema del objeto
* @param m Mundo en que buscar
* @param nombre nombre del objeto
* @return int numero del tema, -1 si hay algun error
*/
int dame_tema(Mundo *m, char *nombre);


 /**
* @brief Apaga el espacio, si es posible
* @param m Mundo en que se encuentra el espacio
* @param esp espacio que apagar
* @return BOOL TRUE si se apaga el espacio, FALSE si no es asi o si hay algun error
*/
BOOL apaga_espacio(Mundo * m, Espacio * esp);


 /**
* @brief Devuelve una lista de los objetos del inventario en la cadena cad
* @param m Mundo de cuyo inventario se quiere la descripcion
* @param cad cadena donde guardar el resultado
* @return BOOL TRUE si se examina con exito, FALSE si no es asi o si hay algun error
*/
BOOL examina_inventario (Mundo *m, char *cad);


 /**
* @brief Devuelve la defensa del jugador (la suma de las defensas de los objetos del inventario)
* @param m Mundo que manejar
* @return int defensa del jugador, 0 si algo falla
*/
int dame_defensa_jugador (Mundo *m);


 /**
* @brief Devuelve el ataque del jugador (la suma de los ataques de los objetos del inventario)
* @param m Mundo que manejar
* @return int ataque del jugador, 0 si algo falla
*/
int dame_ataque_jugador (Mundo *m);


 /**
* @brief Ejecuta la batalla final. Mas informacion en la memoria del modulo mundo
* @param m Mundo sobre el que se ejecuta
* @param cadena lo que se ataca
* @return entero Dependiendo del resultado. Mas informacion en la documentacion tecnica.
*/
int ejecuta_final(Mundo *m, char *cadena);

 /**
* @brief Inicializa la dificultad
* @param m Mundo sobre el que se ejecuta
* @param dificultad cadena con la dificultad escogido
*/
void inicializa_dificultad(Mundo *m, char *dificultad);
#endif
