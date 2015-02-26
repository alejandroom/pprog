/**
* @brief Utilidades del lector XML
*
* Este modulo contiene los prototipos 
* de las funciones de manejo del
* lector XML.
* @file Lectorxml.h
* @author Alejandro
* @version 1.0
* @date 1-05-2012
*/

#ifndef LECTOR_XML_H
#define LECTOR_XML_H

#include "Const.h"
#include "Mundo.h"
#include "Espacio.h"
#include "Objeto.h"
#include "Union.h"
#include "Jugador.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libxml/xmlmemory.h>
#include <libxml/parser.h>

/**
* @brief Inicializa un nuevo mundo a partir de un fichero XML
* @param m mundo a inicializar
* @param fichero nombre del fichero XML
* @return BOOL TRUE si se ha inicializado bien, FALSE si fichero o m son nulos
*/
BOOL iniMundo(char *fichero, Mundo *m);

/**
* @brief Procesa el fichero y va rellenando el mundo
* @param m mundo a inicializar
* @param nombrfich nombre del fichero XML
* @return BOOL TRUE si se ha inicializado bien, FALSE si hay algun error
*/
BOOL procesaMundo(char * nombrfich, Mundo *m);

/**
* @brief Procesa un espacio y lo mete en Mundo
* @param m mundo
* @param doc archivo xml
* @param cur puntero al espacio en el fichero
* @return BOOL TRUE si se ha inicializado bien, FALSE si algo falla
*/
BOOL procesaEspacio(xmlDocPtr doc, xmlNodePtr cur, Mundo *m);

/**
* @brief Procesa una union y lo mete en Mundo
* @param m mundo
* @param doc archivo xml
* @param cur puntero a la union en el fichero
* @return BOOL TRUE si se ha inicializado bien, FALSE si algo falla
*/
BOOL procesaUnion(xmlDocPtr doc, xmlNodePtr cur, Mundo *m);

/**
* @brief Procesa un objeto y lo mete en Mundo
* @param m mundo
* @param doc archivo xml
* @param cur puntero al objeto en el fichero
* @return BOOL TRUE si se ha inicializado bien, FALSE si algo falla
*/
BOOL procesaObjeto(xmlDocPtr doc, xmlNodePtr cur, Mundo *m);

/**
* @brief Procesa un jugador y lo mete en Mundo
* @param m mundo
* @param doc archivo xml
* @param cur puntero al jugador en el fichero
* @return BOOL TRUE si se ha inicializado bien, FALSE si algo falla
*/
BOOL procesaJugador(xmlDocPtr doc, xmlNodePtr cur, Mundo *m);

#endif /* LECTOR_XML_H */
