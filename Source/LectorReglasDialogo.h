/**
* @brief Utilidades del lector de reglas de dialogo
*
* Este modulo contiene los prototipos 
* de las funciones de manejo del
* lector de reglas de dialogo
* @file LectorReglasDialogo.h
* @author Alejandro Ortiz
* @version 1.0
* @date 1-05-2012
*/

#ifndef LECTOR_REGLAS_DIALOGO_H_
#define LECTOR_REGLAS_DIALOGO_H_

#include "ReglasDialogo.h"

/**
* @brief Lee las reglas de dialogo a partir de un fichero .txt, mas datos sobre el fichero
* @param fichero nombre del fichero a leer
* @return BOOL TRUE si se lee con exito, FALSE si hay algun error
*/
BOOL lee_reglas(char *fichero);

#endif /* LECTOR_REGLAS_DIALOGO_H_ */
