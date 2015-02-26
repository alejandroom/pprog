/**
* @brief Utilidades de manejo de acciones
*
* Este modulo contiene las funciones de manejo de acciones
* @file Accion.c
* @author Alejandro Ortiz e Irene Colmenar
* @date 1-05-2012
*/

#include "Accion.h"
#include "Const.h"

enum _TipoAccion{
	JA_IR,
	JA_COGER,
	JA_DEJAR,
	JA_EXAMINAR,
	JA_ENCIENDE,
	JA_APAGA,
	JA_ABRIR,
	JA_DIALOGAR,
	JA_FINAL_BOSS
};

struct _accion {
	TipoAccion id;
	char * od;
};

/**
* @brief Interpreta una accion
* @param quote cadena de caracteres correctamente formada que indica la accion a realizar
* @param ac accion a realizar que incluye el tipo de accion y el objeto directo
* @return BOOL True en caso de que la accion se devuelva correctamente, falso en caso de que ocurra algun error
*/ 
BOOL introduce_accion(char * quote, Accion * ac) {

	char * linea;

	if (quote == NULL || ac == NULL)
		return FALSE;

	linea = strtok(quote, " ");
	ac->od = strtok(NULL, ";");
	
	if (strcmp(linea, "IR") == 0)
		ac->id = JA_IR;
	else if (strcmp(linea, "COGER") == 0)
		ac->id = JA_COGER;
	else if (strcmp(linea, "DEJAR") == 0)
		ac->id = JA_DEJAR;
	else if (strcmp(linea, "EXAMINAR") == 0)
		ac->id = JA_EXAMINAR;
	else if (strcmp(linea, "ENCENDER") == 0)
		ac->id = JA_ENCIENDE;
	else if (strcmp(linea, "APAGAR") == 0)
		ac->id = JA_APAGA;
	else if (strcmp(linea, "ABRIR") == 0)
		ac->id = JA_ABRIR;
	else if (strcmp(linea, "DIALOGAR") == 0)
		ac->id = JA_DIALOGAR;
	else if (strcmp(linea, "ATACAR") == 0)
		ac->id = JA_FINAL_BOSS;
	else
		return FALSE;

	return TRUE;
}

/**
* @brief Crea una accion
* @return Accion* devuelve una accion inicializada a NULL
*/ 
Accion * crea_accion() {

	Accion *auxacc = NULL;
	
	auxacc = (Accion*) malloc(sizeof (Accion));
	
	return auxacc;
}

/**
* @brief Libera una accion
* @param a Accion a liberar
*/ 
void destruye_accion(Accion *a){
	free(a);
}

/**
* @brief Ejecuta una accion sobre el mundo
* @param m mundo sobre el que se realiza la accion
* @param a accion a realizar que incluye el tipo de accion y el objeto directo
* @return int entero que indica la frase que se imprimirá por pantalla dependiendo de la accion ejecutada y su estado
*/ 
int ejecuta_accion(Mundo *m, Accion *a) {
	
	Objeto *objaux;
	Tam max_len = 0;
	int tema;
	char *examinado;
	char plantilla[TAMANO_PAL];
	char respuesta[TAMANO_PAL];
	char descripcion[TAMANO_PAL];
	BOOL retorno=FALSE;

	switch (a->id) {
		case JA_IR:
			if (strcmp(a->od, "NORTE") == 0)
				retorno = mueve_personaje(m, N);
			else if (strcmp(a->od, "SUR") == 0)
				retorno = mueve_personaje(m, S);
			else if (strcmp(a->od, "ESTE") == 0)
				retorno = mueve_personaje(m, E);
			else if (strcmp(a->od, "OESTE") == 0)
				retorno = mueve_personaje(m, O);
			else if (strcmp(a->od, "ARRIBA") == 0)
				retorno = mueve_personaje(m, ARRIBA);
			else if (strcmp(a->od, "ABAJO") == 0)
				retorno = mueve_personaje(m, ABAJO);
			if(retorno==TRUE){
					if (devuelve_luz_espacio(dame_espacio_mundo(m, dame_loc_jugador_mundo(m)))==FALSE){
						if (ilumina_espacio(m, dame_espacio_mundo(m, dame_loc_jugador_mundo(m)))==FALSE){
							return -1;	
						}
					}
					strcpy(plantilla, selecciona_plan_azar(IR_SUCCESS));
					reemplaza_asterisco(respuesta, plantilla, a->od);
					printf("%s\n", respuesta);
					desc_real_espacio(m, respuesta);
					printf("%s\n", respuesta);
					return -3;
			}
			else{
				strcpy(plantilla, selecciona_plan_azar(IR_FAIL));
				reemplaza_asterisco(respuesta, plantilla, a->od);
				printf("%s\n", respuesta);
				return -1;
			}
			break;

		case JA_COGER:
			objaux = dame_objeto_espacio(m, a->od, dame_loc_jugador_mundo(m));
			if (objaux == NULL){
				strcpy(plantilla, selecciona_plan_azar(COGER_FAIL));
				reemplaza_asterisco(respuesta, plantilla, a->od);
				printf("%s\n", respuesta);
				return -1;
			}
			if (coge_objeto(m, objaux)==FALSE){
				strcpy(plantilla, selecciona_plan_azar(COGER_FAIL));
				reemplaza_asterisco(respuesta, plantilla, a->od);
				printf("%s\n", respuesta);
				return -1;			
			}
			strcpy(plantilla, selecciona_plan_azar(COGER_SUCCESS));
			reemplaza_asterisco(respuesta, plantilla, a->od);
			printf("%s\n", respuesta);
			return -2;
			break;

		case JA_DEJAR:
			objaux = dame_objeto_por_nombre(m, a->od);
			if (objaux == NULL){
				strcpy(plantilla, selecciona_plan_azar(DEJAR_FAIL));
				reemplaza_asterisco(respuesta, plantilla, a->od);
				printf("%s\n", respuesta);
				return -1;
			}
			if(deja_objeto(m, objaux)==FALSE){
				strcpy(plantilla, selecciona_plan_azar(DEJAR_FAIL));
				reemplaza_asterisco(respuesta, plantilla, a->od);
				printf("%s\n", respuesta);
				return -1;
			}
			strcpy(plantilla, selecciona_plan_azar(DEJAR_SUCCESS));
			reemplaza_asterisco(respuesta, plantilla, a->od);
			printf("%s\n", respuesta);
			return -2;
		break;

		case JA_EXAMINAR:
			if (ejecuta_examina(m, a, descripcion, max_len) == FALSE) {
				strcpy(plantilla, selecciona_plan_azar(EXAMINAR_FAIL));
				reemplaza_asterisco(respuesta, plantilla, a->od);
				printf("%s\n", respuesta);
				return  - 1;
			}
			strcpy(plantilla, selecciona_plan_azar(EXAMINAR_SUCCESS));
			reemplaza_asterisco(respuesta, plantilla, a->od);
			printf("%s\n", respuesta);
			printf("%s\n", descripcion);
			return -2;
		break;

		case JA_ENCIENDE:
			objaux = dame_objeto_por_nombre(m, a->od);
			if(enciende(m, objaux)==TRUE){
				strcpy(plantilla, selecciona_plan_azar(ENCENDER_SUCCESS));
				reemplaza_asterisco(respuesta, plantilla, a->od);
				printf("%s\n", respuesta);
				return -1;
			}
			strcpy(plantilla, selecciona_plan_azar(ENCENDER_FAIL));
			reemplaza_asterisco(respuesta, plantilla, a->od);
			printf("%s\n", respuesta);
			return -2;
		break;

		case JA_APAGA:
			objaux = dame_objeto_por_nombre(m, a->od);
			if(apaga(m, objaux)==TRUE){
				strcpy(plantilla, selecciona_plan_azar(APAGAR_SUCCESS));
				reemplaza_asterisco(respuesta, plantilla, a->od);
				printf("%s\n", respuesta);
				apaga_espacio(m, dame_espacio_mundo(m, dame_loc_jugador_mundo(m)));
				return -1;
			}
			strcpy(plantilla, selecciona_plan_azar(APAGAR_FAIL));
			reemplaza_asterisco(respuesta, plantilla, a->od);
			printf("%s\n", respuesta);
			return -2;
		break;

		case JA_ABRIR:
			if (abre_union_mundo (m,dame_union_por_nombre(m, a->od))==TRUE){
				strcpy(plantilla, selecciona_plan_azar(ABRIR_SUCCESS));
				reemplaza_asterisco(respuesta, plantilla, a->od);
				printf("%s\n", respuesta);
				return -1;
			}
			strcpy(plantilla, selecciona_plan_azar(ABRIR_FAIL));
			reemplaza_asterisco(respuesta, plantilla, a->od);
			printf("%s\n", respuesta);
			return -2;
		break;

		case JA_DIALOGAR:
			tema = dame_tema(m, a->od);
			if(tema!=-1){
				strcpy(plantilla, selecciona_plan_azar(DIALOGAR_SUCCESS));
			}
			else
				strcpy(plantilla, selecciona_plan_azar(DIALOGAR_FAIL));
			reemplaza_asterisco(respuesta, plantilla, a->od);
			printf("%s\n", respuesta);
			return tema;
		break;

		case JA_FINAL_BOSS:
			tema=ejecuta_final(m, a->od);
			switch(tema){
				case -1:
					strcpy(plantilla, selecciona_plan_azar(ATACAR_NO));
				break;

				case 1:
					strcpy(plantilla, selecciona_plan_azar(ATACAR_CRIT));
				break;

				case 2:
					strcpy(plantilla, selecciona_plan_azar(ATACAR_BASIC));
				break;

				case 3:
					strcpy(plantilla, selecciona_plan_azar(ATACAR_FAIL));
				break;

				case 4:
					strcpy(plantilla, selecciona_plan_azar(ATACAR_VICTORY));
				break;

				case 5:
					strcpy(plantilla, selecciona_plan_azar(ATACAR_DEATH));
				break;
			}

			reemplaza_asterisco(respuesta, plantilla, a->od);
			printf("%s\n", respuesta);
			if(tema==4)
				return -4;
			if(tema==5)
				return -5;
			return -1;
		break;		
	}
}

/*  La descripción se devuelve en el parámetro 
 * examinado que tiene que   haber sido reservado por el cliente. Devuelve TRUE 
 * si todo ha ido bien o FALSE si se ha producido algún error. */


/**
* @brief Ejecuta la acción de examinar
* @param m mundo sobre el que se realiza la accion examinar 
* @param a accion a realizar que incluye el tipo de accion y el objeto directo
* @param examinado cadena de caracteres 
* @param max_len tamaño para la reserva de la cadena.
* @return BOOL en caso de que ocurra algun error devuelve FALSE, en caso contrario TRUE
*/ 
BOOL ejecuta_examina(Mundo *m, Accion *a, char *examinado, Tam max_len) {
	Id id;
	Espacio * espacioaux;
	Objeto *objaux;

	if (m == NULL | a == NULL || examinado == NULL)
		return FALSE;

	id = dame_loc_jugador_mundo(m);

	espacioaux = dame_espacio_mundo(m, id);

	if(a->od==NULL){
		a->od=(char*)malloc(sizeof(char)*strlen("el area")+1);
		strcpy(a->od, "el area");
		return examina_espacio(m, espacioaux, examinado);
	}
	if(strcmp (a->od, "INVENTARIO")==0)
		return examina_inventario (m, examinado);
	
	objaux = dame_objeto_por_nombre(m, a->od);


	if (espacioaux == NULL || objaux == NULL)
		return FALSE;

	return examina_objeto(m, objaux, examinado);
}
