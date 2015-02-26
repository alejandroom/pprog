/**
* @brief Utilidades del lector XML
*
* Este modulo contiene las funciones de manejo del
* lector XML.
* @file Lectorxml.c
* @author Alejandro Ortiz
* @version 1.0
* @date 1-05-2012
*/

#include "Lectorxml.h"

/**
* @brief Inicializa un nuevo mundo a partir de un fichero XML
* @param m mundo a inicializar
* @param fichero nombre del fichero XML
* @return BOOL TRUE si se ha inicializado bien, FALSE si fichero o m son nulos
*/
BOOL iniMundo(char *fichero, Mundo *m){
	if(fichero==NULL && m==NULL)
		return FALSE;

	procesaMundo(fichero, m);

	return TRUE;
}

/**
* @brief Procesa el fichero y va rellenando el mundo
* @param m mundo a inicializar
* @param nombrfich nombre del fichero XML
* @return BOOL TRUE si se ha inicializado bien, FALSE si hay algun error
*/
BOOL procesaMundo(char * nombrfich, Mundo *m){

	xmlDocPtr doc;		/* Puntero a la estructura xmlDoc */
	xmlNodePtr cur;		/* Puntero a la estructura xmlNode */
	xmlNodePtr base;		/* Segundo puntero a la estructura xmlNode */
	xmlNodePtr pnode;		/* Tercer puntero a la estructura xmlNode */
	xmlChar *numero;
	int num;

	/*
	 *	Comprobacion de los argumentos de entrada
	 */
	if((!nombrfich))
		return FALSE;

	/* 
	 * Almacenamiento del fichero XML en memoria
	 */
	doc = xmlParseFile(nombrfich);
	
	if (doc == NULL ){
		fprintf(stderr,"El fichero %s no contiene un documento XML.\n", nombrfich);
		return FALSE;
	}
	
	/*
	 * Acceso al nodo raiz
	 */
	cur = xmlDocGetRootElement(doc);	
	if (cur == NULL){
		fprintf(stderr,"Documento vacio\n");
		xmlFreeDoc(doc);
		return FALSE;
	}
	
	/* 
	 * Comparando nombre de etiqueta
	 */
	if (xmlStrcmp(cur->name, (const xmlChar *) "juego")){
		fprintf(stderr,"Etiqueta incorrecta %s: se esperaba <juego>\n", cur->name);
		xmlFreeDoc(doc);
		return FALSE;
	} 
	
	numero = xmlGetProp(cur, (const xmlChar *) "id");
	if (numero != NULL){
		sscanf((char *) numero, "%d", &num);
		xmlFree(numero);
	}
	
	cur = cur->xmlChildrenNode;
	cur = cur->next;
	base = cur;
	
	if (xmlStrcmp(cur->name, (const xmlChar *) "espacios")){
		fprintf(stderr,"Etiqueta incorrecta %s: se esperaba <espacios>\n", cur->name);
		xmlFreeDoc(doc);
		return FALSE;
	} 

	/*
	 * Recorremos el arbol de espacios
	 */
	cur = base->xmlChildrenNode;
	cur = cur->next;
	
	while (cur!=NULL){
		if(!xmlStrcmp(cur->name, (const xmlChar *) "espacio"))
			if( procesaEspacio(doc, cur, m)!= TRUE){
				xmlFreeDoc(doc);
				return FALSE;
			}	
		cur = cur->next;
		cur = cur->next;
	} 
	
	base=base->next;
	base=base->next;
	cur=base;
	if (xmlStrcmp(cur->name, (const xmlChar *) "uniones")){
		fprintf(stderr,"%d: Etiqueta incorrecta %s: se esperaba <uniones>\n", cur->line, cur->name);
		xmlFreeDoc(doc);
		return FALSE;
	} 
	
	/*
	 * Recorremos el arbol de uniones
	 */
	cur = base->xmlChildrenNode;
	cur = cur->next; 
	
	while (cur!=NULL){
		if(!xmlStrcmp(cur->name, (const xmlChar *) "union"))
			if( procesaUnion (doc, cur, m)!= TRUE){
			xmlFreeDoc(doc);
			return FALSE;
			}	
		cur = cur->next;
		cur = cur->next;
	}
	
	base=base->next;
	base=base->next;
	cur=base;
	
	
	if (xmlStrcmp(cur->name, (const xmlChar *) "objetos")){
		fprintf(stderr,"Etiqueta incorrecta %s: se esperaba <objetos>\n", cur->name);
		xmlFreeDoc(doc);
		return FALSE;
	} 
	
	/*
	 * Recorremos el arbol de objetos
	 */
	cur = base->xmlChildrenNode;
	cur = cur->next; 
	
	while (cur!=NULL){
		if(!xmlStrcmp(cur->name, (const xmlChar *) "objeto"))
			if( procesaObjeto (doc,cur, m) != TRUE){
				xmlFreeDoc(doc);
				return FALSE;
			}	
		cur = cur->next;
		cur = cur->next; 
	}
	
	base=base->next;
	base=base->next;
	cur=base;
	if (xmlStrcmp(cur->name, (const xmlChar *) "jugador")){
		fprintf(stderr,"Etiqueta incorrecta %s: se esperaba <jugador>\n", cur->name);
		xmlFreeDoc(doc);
		return FALSE;
	}
	else if( procesaJugador (doc, cur, m) != TRUE){
		xmlFreeDoc(doc);
		return FALSE;
	}
	
	xmlFreeDoc(doc);
	
	return TRUE;
}

/**
* @brief Procesa un espacio y lo mete en Mundo
* @param m mundo
* @param doc archivo xml
* @param cur puntero al espacio en el fichero
* @return BOOL TRUE si se ha inicializado bien, FALSE si algo falla
*/
BOOL procesaEspacio(xmlDocPtr doc, xmlNodePtr cur, Mundo *m){

	xmlChar * valor=NULL;
	Id num;
	Espacio *esp;
	xmlNodePtr pnode;

	/*
	 * Argumentos de entrada
	 */
	if((!doc) || (!cur))
		return FALSE;

	/*
	 * Obtener el atributo de la etiqueta
	 */
	valor = xmlGetProp(cur, (const xmlChar *) "id");
	if (valor != NULL){
	sscanf((char *) valor, "%ld", &(num));
	xmlFree(valor);
	}
	
	esp=annade_espacio_mundo(m, num);
	if(esp==NULL)
		return FALSE;
	/*
	 * Recorrer las etiquetas anidadas
	 */		
	cur = cur->xmlChildrenNode; /* Primer nodo */
	while (cur != NULL){
		if ((!xmlStrcmp(cur->name, (const xmlChar *) "descripcion"))){
			valor = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);	 
			if(valor!=NULL){
				nueva_desc_espacio(esp, (char*)valor);
				xmlFree(valor);
			}
		} else if ((!xmlStrcmp(cur->name, (const xmlChar *) "edescripcion"))){
			valor = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);	
			if(valor!=NULL){
				nueva_desc_examinar_espacio(esp, (char*)valor);
				xmlFree(valor);
			}
		} else if ((!xmlStrcmp(cur->name, (const xmlChar *) "norte"))){
			valor = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 
			if(valor!=NULL){
				sscanf((char *) valor, "%ld", &num);
				nueva_union_norte_espacio(esp, num);
				xmlFree(valor);
			}
		} else if ((!xmlStrcmp(cur->name, (const xmlChar *) "sur"))){
			valor = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if(valor!=NULL){
				sscanf((char *) valor, "%ld", &num);
				nueva_union_sur_espacio(esp, num);
				xmlFree(valor);
			}
		} else if ((!xmlStrcmp(cur->name, (const xmlChar *) "este"))){
			valor = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 
			if(valor!=NULL){
				sscanf((char *) valor, "%ld", &num);
				nueva_union_este_espacio(esp, num);
				xmlFree(valor);
			}
		} else if ((!xmlStrcmp(cur->name, (const xmlChar *) "oeste"))){
			valor = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if(valor!=NULL){
				sscanf((char *) valor, "%ld", &num);
				nueva_union_oeste_espacio(esp, num);
				xmlFree(valor);
			}
		} else if ((!xmlStrcmp(cur->name, (const xmlChar *) "arriba"))){
			valor = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 
			if(valor!=NULL){
				sscanf((char *) valor, "%ld", &num);
				nueva_union_arriba_espacio(esp, num);
				xmlFree(valor);
			}
		} else if ((!xmlStrcmp(cur->name, (const xmlChar *) "abajo"))){
			valor = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 
			if(valor!=NULL){
				sscanf((char *) valor, "%ld", &num);
				nueva_union_abajo_espacio(esp, num);
				xmlFree(valor);
			}
		} else if ((!xmlStrcmp(cur->name, (const xmlChar *) "objetos"))){
			pnode = cur->xmlChildrenNode;
			pnode = pnode->next;
			while(pnode!=NULL){
				if(!xmlStrcmp(pnode->name, (const xmlChar *) "objeto")){	 
					valor = xmlGetProp(pnode, (const xmlChar *) "id");
					if (valor != NULL){
						sscanf((char *) valor, "%ld", &num);
						annade_objeto_espacio(esp, num);
						xmlFree(valor);
					}
				}
				pnode=pnode->next;
				pnode=pnode->next;
			}
		} else if ((!xmlStrcmp(cur->name, (const xmlChar *) "luz"))){
				valor = xmlGetProp(cur, (const xmlChar *) "valor");
			if (valor != NULL){
				if(strcmp((char*)valor, "VERDADERO")==0)
					actualiza_iluminacion_espacio(esp, TRUE);
				if(strcmp((char*)valor, "FALSO")==0)
					actualiza_iluminacion_espacio(esp, FALSE);
				xmlFree(valor);
			}	 
		}
		cur = cur->next;
	}

	return TRUE;
}

/**
* @brief Procesa una union y lo mete en Mundo
* @param m mundo
* @param doc archivo xml
* @param cur puntero a la union en el fichero
* @return BOOL TRUE si se ha inicializado bien, FALSE si algo falla
*/
BOOL procesaUnion(xmlDocPtr doc, xmlNodePtr cur, Mundo *m){

	xmlChar * valor=NULL;
	Id num, num2;
	Union *un;

	/*
	 * Argumentos de entrada
	 */
	if((!doc) || (!cur))
		return FALSE;

	/*
	 * Obtener el atributo de la etiqueta
	 */
	valor = xmlGetProp(cur, (const xmlChar *) "id");
	if (valor != NULL){
		sscanf((char *) valor, "%ld", &(num));
		xmlFree(valor);
	}
	else
		return FALSE;

	un=annade_union_mundo(m, num);
	num = 0;
	num2 = 0;
	
	if(un==NULL)
		return FALSE;
	/*
	 * Recorrer las etiquetas anidadas
	 */		
	cur = cur->xmlChildrenNode; /* Primer nodo */
	while (cur != NULL){ 
		if ((!xmlStrcmp(cur->name, (const xmlChar *) "nombre"))){
			valor = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);

			if(valor!=NULL){
				escribe_nombreunion(un, (char*)valor);
				xmlFree(valor);
			}
		}else if ((!xmlStrcmp(cur->name, (const xmlChar *) "abrible"))){
			valor = xmlGetProp(cur, (const xmlChar *) "valor"); 
			if (valor != NULL){
				if(strcmp((char*)valor, "VERDADERO")==0)
					establece_abrible(un, TRUE);
				if(strcmp((char*)valor, "FALSO")==0)
					establece_abrible(un, FALSE);
				xmlFree(valor);
			}	 
			
			valor = xmlGetProp(cur, (const xmlChar *) "inicial"); 
			if (valor != NULL){
				if(strcmp((char*)valor, "VERDADERO")==0)
					abre_union(un);
				if(strcmp((char*)valor, "FALSO")==0)
					cierra_union(un);
				xmlFree(valor);
			}	 
		}else if ((!xmlStrcmp(cur->name, (const xmlChar *) "conexion_1"))){
			valor = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);

			if(valor!=NULL){
				sscanf((char *) valor, "%ld", &num);
				xmlFree(valor);
			}
		} else if ((!xmlStrcmp(cur->name, (const xmlChar *) "conexion_2"))){
			valor = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

			if(valor!=NULL){
				sscanf((char *) valor, "%ld", &num2);
				xmlFree(valor);
			}
			
			une_espacios(un, num, num2);
		} else if ((!xmlStrcmp(cur->name, (const xmlChar *) "key"))){
			valor = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 

			if(valor!=NULL){
				sscanf((char *) valor, "%ld", &num);
				escribe_key(un, num);
				xmlFree(valor);
			}
		}	
		cur = cur->next;
	}

	return TRUE;
}

/**
* @brief Procesa un objeto y lo mete en Mundo
* @param m mundo
* @param doc archivo xml
* @param cur puntero al objeto en el fichero
* @return BOOL TRUE si se ha inicializado bien, FALSE si algo falla
*/
BOOL procesaObjeto(xmlDocPtr doc, xmlNodePtr cur, Mundo *m){

	xmlChar * valor=NULL;
	Id num;
	int tema;
	Objeto *obj;
	xmlNodePtr pnode;

	/*
	 * Argumentos de entrada
	 */
	if((!doc) || (!cur))
		return FALSE;

	/*
	 * Obtener el atributo de la etiqueta
	 */
	valor = xmlGetProp(cur, (const xmlChar *) "id");
	if (valor != NULL){
		sscanf((char *) valor, "%ld", &(num));
		xmlFree(valor);
	}
	
	obj=annade_objeto_mundo(m, num);
	if(obj==NULL)
		return FALSE;

	/*
	 * Recorrer las etiquetas anidadas
	 */		
	cur = cur->xmlChildrenNode; /* Primer nodo */
	while (cur != NULL){
		if ((!xmlStrcmp(cur->name, (const xmlChar *) "nombre"))){
			valor = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if(valor!=NULL){
				nuevo_nombre_obj(obj, (char*)valor);
				xmlFree(valor);
			}
		}else if ((!xmlStrcmp(cur->name, (const xmlChar *) "pdescripcion"))){
			valor = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if(valor!=NULL){
				nueva_desc_obj(obj, (char*)valor);
				xmlFree(valor);
			}
		}else if ((!xmlStrcmp(cur->name, (const xmlChar *) "mdescripcion"))){
			valor = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 
			if(valor!=NULL){
				nueva_desc_movil_obj(obj, (char*)valor);
				xmlFree(valor);
			}
		}else if ((!xmlStrcmp(cur->name, (const xmlChar *) "edescripcion"))){
			valor = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1); 
			if(valor!=NULL){
				nueva_desc_examinar_obj(obj, (char*)valor);
				xmlFree(valor);
			}
		} else if ((!xmlStrcmp(cur->name, (const xmlChar *) "movil"))){
			valor = xmlGetProp(cur, (const xmlChar *) "valor"); 
			if (valor != NULL){
				if(strcmp((char*)valor, "VERDADERO")==0)
					actualiza_movil_obj(obj, TRUE);
				if(strcmp((char*)valor, "FALSO")==0)
					actualiza_movil_obj(obj, FALSE);
				xmlFree(valor);
			}	 
		} else if ((!xmlStrcmp(cur->name, (const xmlChar *) "oculto"))){
			valor = xmlGetProp(cur, (const xmlChar *) "valor"); 
			if (valor != NULL){
				if(strcmp((char*)valor, "VERDADERO")==0)
					actualiza_oculto_objeto(obj, TRUE);
				if(strcmp((char*)valor, "FALSO")==0)
					actualiza_oculto_objeto(obj, FALSE);
				xmlFree(valor);
			}	 	
		} else if ((!xmlStrcmp(cur->name, (const xmlChar *) "ilumina"))){
			valor = xmlGetProp(cur, (const xmlChar *) "valor"); 
			if (valor != NULL){
				if(strcmp((char*)valor, "VERDADERO")==0)
					actualiza_iluminable_obj(obj, TRUE);
				if(strcmp((char*)valor, "FALSO")==0)
					actualiza_iluminable_obj(obj, FALSE);
				xmlFree(valor);
			}	 
			
			valor = xmlGetProp(cur, (const xmlChar *) "inicial"); 
			if (valor != NULL){
				if(strcmp((char*)valor, "VERDADERO")==0)
					actualiza_ilumina_obj(obj, TRUE);
				if(strcmp((char*)valor, "FALSO")==0)
					actualiza_ilumina_obj(obj, FALSE);
				xmlFree(valor);
			}	
		} else if ((!xmlStrcmp(cur->name, (const xmlChar *) "tema"))){
				valor = xmlGetProp(cur, (const xmlChar *) "valor");
				if (valor != NULL){
					sscanf((char *) valor, "%d", &(tema));
					nuevo_tema_objeto(obj, tema);
					xmlFree(valor);
				}
		} else if ((!xmlStrcmp(cur->name, (const xmlChar *) "defensa"))){
				valor = xmlGetProp(cur, (const xmlChar *) "valor");
				if (valor != NULL){
					sscanf((char *) valor, "%d", &(tema));
					establece_defensa(obj, tema);
					xmlFree(valor);
				} 
		} else if ((!xmlStrcmp(cur->name, (const xmlChar *) "ataque"))){
				valor = xmlGetProp(cur, (const xmlChar *) "valor");
				if (valor != NULL){
					sscanf((char *) valor, "%d", &(tema));
					establece_ataque(obj, tema);
					xmlFree(valor);
				} 
		}
		cur = cur->next;
	}
	return TRUE;
}

/**
* @brief Procesa un jugador y lo mete en Mundo
* @param m mundo
* @param doc archivo xml
* @param cur puntero al jugador en el fichero
* @return BOOL TRUE si se ha inicializado bien, FALSE si algo falla
*/
BOOL procesaJugador(xmlDocPtr doc, xmlNodePtr cur, Mundo *m){
	
	xmlChar * valor=NULL;
	Id num;
	Jugador *jug;
	xmlNodePtr pnode;
	
	/*
	* Argumentos de entrada
	*/
	if((!doc) || (!cur))
		return FALSE;
	
	jug=annade_jugador_mundo(m);
	
	/*
	* Recorrer las etiquetas anidadas
	*/		
	cur = cur->xmlChildrenNode; /* Primer nodo */
	cur = cur->next;

	while(cur!=NULL){
		if ((!xmlStrcmp(cur->name, (const xmlChar *) "localizacion"))){
			valor = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if (valor != NULL){
				sscanf((char *) valor, "%ld", &num);
				establece_loc_jugador(jug, num);
				xmlFree(valor);
			}
		}else if ((!xmlStrcmp(cur->name, (const xmlChar *) "max_objetos"))){
			valor = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
			if (valor != NULL){
				sscanf((char *) valor, "%ld", &num);
				establece_maximo_obj(jug, num);
				xmlFree(valor);
			}
		} else if ((!xmlStrcmp(cur->name, (const xmlChar *) "objetos"))){
			pnode = cur->xmlChildrenNode;
			pnode = pnode->next;
			while(pnode!=NULL){
				if(!xmlStrcmp(pnode->name, (const xmlChar *) "objeto")){ 
					valor = xmlGetProp(pnode, (const xmlChar *) "id");	 
					if (valor != NULL){
						sscanf((char *) valor, "%ld", &num);
						annade_objeto_jugador(jug, num);
						xmlFree(valor);
					}
				}	
				pnode=pnode->next;
				pnode=pnode->next;
			}
		}
		cur = cur->next;
	}
	return TRUE;
}
