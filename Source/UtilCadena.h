/**
* @brief Utilidades de manejo de caracteres
*
* Este modulo contiene los prototipos
* de las funciones de manejo de
* caracteres.
* @file UtilCadena.h
* @author Irene Colmenar
* @version 1.0
* @date 1-05-2012
*/

#ifndef UTILCADENA_H_
#define UTILCADENA_H_

#include <stdlib.h>
#include <string.h>
#include "Const.h"

/**
* @brief Elimina los caracteres indicados de la cadena
* @param ori cadena de caracteres que limpiar
* @param seps cadena de caracteres que tiene los caracteres a eliminar
* @param dst cadena de caracteres donde guardar el resultado
* @param n longitud de la cadena a modificar
* @return char* dst modificada
*/
extern char * elimina_cars(char * dst, const char * ori, const char * seps, size_t n);

/**
* @brief Pasa la cadena de caracteres a mayusculas
* @param ori cadena de caracteres que modificar
* @param dst cadena de caracteres donde guardar el resultado
* @param n longitud de la cadena a modificar
* @return char* dst modificada
*/
extern char * a_mayusculas(char * dst, const char * ori, size_t n);

/**
* @brief Elimina los espacios innecesarios de la cadena
* @param ori cadena de caracteres que limpiar
* @param dst cadena de caracteres donde guardar el resultado
* @param n longitud de la cadena a modificar
* @return char* dst modificada
*/
extern char * limpia_espacios(char * dst, const char * ori, size_t n);

/**
* @author Alejandro
* @brief Dada una frase y su patron, selecciona el objeto
* @param ori cadena de caracteres que contiene la frase
* @param plan cadena de caracteres que tiene la patron
* @param dst cadena de caracteres donde guardar el resultado
* @return BOOL TRUE en caso de que el objeto se escriba en dst correctamente, FALSE en caso de que ocurra algun error
*/
BOOL dame_objeto(char *dst, char *ori, char *plan);

/**
* @author Alejandro
* @brief Dada una plantilla y un objeto, sustituye el asterisco de la plantilla por el objeto
* @param ori cadena de caracteres que contiene la plantilla
* @param obj cadena de caracteres que tiene el objeto
* @param dst cadena de caracteres donde guardar el resultado
* @return BOOL TRUE en caso de que el resultado se escriba en dst correctamente, FALSE en caso de que ocurra algun error
*/
BOOL reemplaza_asterisco(char *dst, char *ori, char *obj);

#endif /* UTILCADENA_H_ */


