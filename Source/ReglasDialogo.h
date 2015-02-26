/**
* @brief Utilidades de manejo de reglas en el dialogo
*
* Este modulo contiene los prototipos 
* de las funciones de manejo de
* reglas.
* @file ReglasDialogo.h
* @author Irene Colmenar, Alejandro Ortiz
* @version 2.0 incluidas funciones para reservar memoria, inicializar las reglas y liberarlas
* @date 1-05-2012
*/

#ifndef REGLAS_DIALOGO_H_
#define REGLAS_DIALOGO_H_

#include <stdlib.h>
#include <string.h>
#include "Const.h"

/* Estructura que define una regla de dialogo. 
 * Las reglas se componen de un conjunto de posibles entradas, de un conjunto de posibles respuestas
 * y de un indicador de la ultima plantilla de respuesta empleada.
 *
 * La regla se aplicara si se puede encontrar el patron en la frase introducida por el usuario.
 */
typedef struct _regla Regla;


/**
* @brief Reserva la memoria para una nueva regla
* @return Regla* puntero a la nueva regla, NULL en caso de error
*/
Regla *nueva_regla();

/**
* @brief Libera la memoria correspondiente a una regla
* @param regla Regla a liberar
*/
void destruye_regla(Regla *regla);

/**
* @brief Inicializa el numero de patrones y reserva memoria para estos
* @param regla regla a manejar
* @param patrones numero de patrones
* @return BOOL TRUE si se inicializa y reserva con exito, FALSE si hay algun error
*/
BOOL inicializa_patrones(Regla *regla, int patrones);

/**
* @brief Añade un patron a la regla indicada en la posicion indicada
* @param regla regla a modificar
* @param patron patron a añadir
* @param pos posicion del array de patrones donde añadir el patron
* @return BOOL TRUE si se añade con exito, FALSE si no es asi
*/
BOOL annade_patron(Regla *regla, char *patron, int pos);

/**
* @brief Inicializa el numero de plantillas y reserva memoria para estos
* @param regla regla a manejar
* @param plantillas numero de plantillas
* @return TRUE si se inicializa y reserva con exito, FALSE si hay algun error
*/
BOOL inicializa_plantillas(Regla *regla, int plantillas);

/**
* @brief Añade una plantilla a la regla indicada en la posicion indicada
* @param regla regla a modificar
* @param plantilla plantilla a añadir
* @param pos posicion del array de plantillas donde añadir la plantilla
* @return BOOL TRUE si se añade con exito, FALSE si no es asi
*/
BOOL annade_plantilla(Regla *regla, char *plantilla, int pos);

/**
* @brief Selecciona la siguiente plantilla de salida de una regla
* @param ind_regla numero de la regla
* @return char* plantilla seleccionada
*/
extern char * selecciona_plan_sal(int ind_regla);

/**
* @brief Dada una frase, busca en los patrones de las reglas de un tema dado y devuelve la regla que concuerde
* @param tema numero de tema en que buscar
* @param txt_ent frase
* @return int numero de regla seleccionada
*/
extern int busca_regla(int tema, const char *txt_ent);

/**
* @brief Dado un indice de regla, selecciona una plantilla al azar
* @param ind_regla numero de regla en que busca
* @return char* plantilla resultante
*/
extern char * selecciona_plan_azar(int ind_regla);

/**
* @brief Devuelve el tamaño de un patron concreto de una regla
* @param ind_regla numero de regla
* @param ind_patr_entr numero de patron
* @return int longitud
*/
extern int tam_patron_regla(int ind_regla, int ind_patr_entr);

/**
* @brief Inicializa las reglas, se considera una regla nula cuando el numero de plantillas es -1
*/
void inicializa_reglas();

/**
* @brief Destruye las reglas, liberando la memoria reservada cuando sea necesario
*/
void destruye_reglas();

/**
* @brief Añade un numero de regla(una regla) a un tema
* @param regla numero de regla
* @param tema numero de tema
* @return BOOL TRUE en caso de que la funcion funcione correctamente, FALSE en caso de que ocurra algun error
*/
BOOL annade_regla_temas(int tema, int regla);

/**
* @brief Añade una regla al conjunto de reglas
* @param regla regla que incluir
* @param posicion posicion donde incluir la regla(-1 si no hay preferencias)
* @return BOOL TRUE en caso de que la funcion funcione correctamente, FALSE en caso de que ocurra algun error
*/
BOOL annade_regla_reglas(Regla *regla, int posicion);

/**
* @brief Añade una regla y un tema
* @param regla regla que incluir
* @param tema numero de tema de la regla
* @param posicion posicion donde incluir la regla(-1 si no hay preferencias)
* @return BOOL TRUE en caso de que la funcion funcione correctamente, FALSE en caso de que ocurra algun error
*/
BOOL annade_regla(Regla *regla, int tema, int posicion);

#endif /* REGLAS_DIALOGO_H_ */
