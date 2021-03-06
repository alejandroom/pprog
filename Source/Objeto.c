/**
* @brief Utilidades de manejo de objetos
*
* Este modulo contiene las funciones de manejo de
* objetos.
* @file Objeto.c
* @author Juan Manuel Cornet
* @version 2.0 Campos extras: tema, defensa y ataque. Y sus funciones correspondientes.
* @date 1-05-2012
*/

#include "Objeto.h"

struct _objeto {
	Id id;
	char nombre[TAMANO_PAL + 1];
	char descripcion[TAMANO_PAL + 1];
	char descMovido[TAMANO_PAL + 1];
	char descExaminar[TAMANO_PAL + 1];
	BOOL movil;
	BOOL movido;
	BOOL ilumina;
	BOOL encendido;
	BOOL oculto;
	int tema;
	int defensa;
	int ataque;
};

/**
* @brief Crea un nuevo objeto, reservando la memoria correspondiente e inilizalizando sus campos
* @param id identificador que tendra el nuevo objeto
* @return Objeto* nuevo objeto
*/
Objeto * nuevo_obj(Id id){

	Objeto * obj;

	obj = (Objeto *) malloc(sizeof (Objeto));

	if (obj == NULL)
		return obj;

	obj->id = id;
	obj->movil = FALSE;
	obj->movido = FALSE;
	obj->ilumina = FALSE;
	obj->encendido = FALSE;
	obj->oculto = FALSE;
	obj->tema = -1;
	obj->defensa = 0;
	obj->ataque = 0;

	return obj;
}

/**
* @brief Destruye el objeto, liberando la memoria correspondiente
* @param obj objeto a destruir
*/
void destruye_objeto(Objeto * obj){
	free(obj);
}

/**
* @brief Asigna un nuevo tema al objeto
* @param obj objeto a modificar
* @param tema nuevo tema a asignar
* @return BOOL TRUE si se asigna, FALSE si el objeto es nulo
*/
BOOL nuevo_tema_objeto(Objeto * obj, int tema){
	if (obj==NULL)
		return FALSE;
	
	obj->tema=tema;
	
	return TRUE;
}

/**
* @brief Asigna un nuevo nombre al objeto
* @param o objeto a modificar
* @param s cadena con el nuevo nombre
* @return BOOL TRUE si se asigna, FALSE si el objeto es nulo
*/
BOOL nuevo_nombre_obj(Objeto * o, char * s){
	if (strlen(s) > TAMANO_PAL + 1)
		return FALSE;

	if (o == NULL)
		return FALSE;

	strcpy(o->nombre, s);

	return TRUE;
}

/**
* @brief Asigna una nueva descripcion al objeto
* @param o objeto a modificar
* @param s cadena con la nueva descripcion
* @return BOOL TRUE si se asigna, FALSE si el objeto es nulo
*/
BOOL nueva_desc_obj(Objeto * o, char * s){
	if (strlen(s) > TAMANO_PAL + 1)
		return FALSE;

	if (o == NULL)
		return FALSE;

	strcpy(o->descripcion, s);

	return TRUE;
}

/**
* @brief Asigna una nueva descripcion de examinar al objeto
* @param o objeto a modificar
* @param s cadena con la nueva descripcion
* @return BOOL TRUE si se asigna, FALSE si el objeto es nulo
*/
BOOL nueva_desc_examinar_obj(Objeto * o, char * s){
	if (strlen(s) > TAMANO_PAL + 1)
		return FALSE;

	if (o == NULL)
		return FALSE;

	strcpy(o->descExaminar, s);

	return TRUE;
}

/**
* @brief Asigna una nueva descripcion movil al objeto
* @param o objeto a modificar
* @param s cadena con la nueva descripcion
* @return BOOL TRUE si se asigna, FALSE si el objeto es nulo
*/
BOOL nueva_desc_movil_obj(Objeto * o, char * s){

	if (strlen(s) > TAMANO_PAL + 1)
		return FALSE;

	if (o == NULL)
		return FALSE;

	strcpy(o->descMovido, s);

	return TRUE;
}

/**
* @brief Asigna un nuevo valor al campo movil del objeto
* @param o objeto a modificar
* @param b valor a asignar
* @return BOOL TRUE si se asigna, FALSE si el objeto es nulo
*/
BOOL actualiza_movil_obj(Objeto * o, BOOL b){

	if (b != TRUE && b != FALSE)
		return FALSE;

	if (o == NULL)
		return FALSE;

	o->movil = b;

	return TRUE;
}

/**
* @brief Asigna un nuevo valor al campo movido del objeto
* @param o objeto a modificar
* @param b valor a asignar
* @return BOOL TRUE si se asigna, FALSE si el objeto es nulo
*/
BOOL actualiza_movido_objeto(Objeto * obj, BOOL movido){
	if (movido != TRUE && movido != FALSE)
		return FALSE;

	if (obj == NULL)
		return FALSE;

	obj->movido = movido;

	return TRUE;
}

/**
* @brief Asigna un nuevo valor al campo iluminable del objeto
* @param o objeto a modificar
* @param b valor a asignar
* @return BOOL TRUE si se asigna, FALSE si el objeto es nulo
*/
BOOL actualiza_iluminable_obj(Objeto * o, BOOL b){
	if (b != TRUE && b != FALSE)
		return FALSE;

	if (o == NULL)
		return FALSE;

	o->ilumina = b;

	return TRUE;
}

/**
* @brief Asigna un nuevo valor al campo ilumina del objeto
* @param o objeto a modificar
* @param b valor a asignar
* @return BOOL TRUE si se asigna, FALSE si el objeto es nulo
*/
BOOL actualiza_ilumina_obj(Objeto * o, BOOL b){
	if (b != TRUE && b != FALSE)
		return FALSE;

	if (o == NULL)
		return FALSE;
	if (o->encendido==TRUE){
		return FALSE;
	}
	o->encendido = b;

	return TRUE;
}

/**
* @brief Asigna un nuevo valor al campo oculto del objeto
* @param o objeto a modificar
* @param b valor a asignar
* @return BOOL TRUE si se asigna, FALSE si el objeto es nulo
*/
BOOL actualiza_oculto_objeto(Objeto * obj, BOOL oculto){
	if (oculto != TRUE && oculto != FALSE)
		return FALSE;

	if (obj == NULL)
		return FALSE;

	obj->oculto = oculto;

	return TRUE;
}

/**
* @brief Devuelve el valor del campo id del objeto
* @param o objeto cuya informacion buscamos
* @return Id id del objeto, NO_ID en caso de objeto nulo
*/
Id dame_id_objeto(Objeto * objeto){
	if (objeto==NULL)
		return NO_ID;
	
	return objeto->id;
}

/**
* @brief Devuelve el valor del campo tema del objeto
* @param o objeto cuya informacion buscamos
* @return int tema del objeto, -1 en caso de objeto nulo
*/
int dame_tema_objeto(Objeto * objeto){
	if (objeto==NULL)
		return -1;
	
	return objeto->tema;
}

/**
* @brief Devuelve el valor del campo nombre del objeto
* @param o objeto cuya informacion buscamos
* @return char* nombre del objeto, NULL en caso de objeto nulo
*/
const char* nombre_objeto(Objeto *obj){
	if (obj == NULL)
		return NULL;
		
	return obj->nombre;
}

/**
* @brief Devuelve el valor del campo descripcion del objeto
* @param o objeto cuya informacion buscamos
* @return char* descripcion del objeto, NULL en caso de objeto nulo
*/
const char * descripcion_objeto(Objeto * obj){
	if (obj == NULL)
		return NULL;

	return obj->descripcion;
}

/**
* @brief Devuelve el valor del campo descMovido del objeto
* @param o objeto cuya informacion buscamos
* @return char* descMovido del objeto, NULL en caso de objeto nulo
*/
char * descripcion_objeto_movido(Objeto * obj){
	if (obj == NULL)
		return NULL;

	return obj->descMovido;
}

/**
* @brief Devuelve el valor del campo descExaminar del objeto
* @param o objeto cuya informacion buscamos
* @return char* descExaminar del objeto, NULL en caso de objeto nulo
*/
const char * descripcion_objeto_examinar(Objeto * obj){
	if (obj == NULL)
		return NULL;

	return obj->descExaminar;
}

/**
* @brief Devuelve el valor del campo movil del objeto
* @param o objeto cuya informacion buscamos
* @return BOOL valor de el campo movil del objeto, FALSE en caso de objeto nulo
*/
BOOL es_movil_objeto(Objeto * obj){
	if (obj == NULL)
		return FALSE;
		
	return obj->movil;
}

/**
* @brief Devuelve el valor del campo movido del objeto
* @param o objeto cuya informacion buscamos
* @return BOOL valor de el campo movido del objeto, FALSE en caso de objeto nulo
*/
BOOL es_movido_objeto(Objeto * obj){
	if (obj == NULL)
		return FALSE;

	return obj->movido;
}

/**
* @brief Devuelve el valor del campo movido del objeto
* @param o objeto cuya informacion buscamos
* @return BOOL valor de el campo movido del objeto, FALSE en caso de objeto nulo
*/
BOOL ilumina_objeto(Objeto * obj){
	if (obj == NULL)
		return FALSE;

	return obj->ilumina;
}

/**
* @brief Devuelve el valor del campo encendido del objeto
* @param o objeto cuya informacion buscamos
* @return BOOL valor de el campo encendido del objeto, FALSE en caso de objeto nulo
*/
BOOL es_encendido_objeto(Objeto * obj){
	if (obj == NULL)
		return FALSE;

	return obj->encendido;
}

/**
* @brief Devuelve el valor del campo oculto del objeto
* @param o objeto cuya informacion buscamos
* @return BOOL valor de el campo oculto del objeto, FALSE en caso de objeto nulo
*/
BOOL oculta_obj(Objeto * o){
	if (o == NULL)
		return FALSE;

	return o->oculto;
}

/**
* @brief Imprime los datos del objeto por pantalla
* @param o objeto cuya informacion queremos imprimir
*/
void imprime_objeto(Objeto * obj){
	if (obj == NULL)
		printf("Objeto nulo\n\n");

	printf("ID del objeto: %ld\n", obj->id);
	printf("Nombre del objeto: %s\n", obj->nombre);
	printf("Descripcion del objeto: %s\n", obj->descripcion);
	printf("Descripcion del objeto cuando se examina: %s\n", obj->descExaminar);
	printf("Descripcion del objeto cuando se ha movido: %s\n", obj->descMovido);
	printf("Es movil el objeto? (0=NO, 1=SI): %d\n", obj->movil);
	printf("Esta movido el objeto? (0=NO, 1=SI): %d\n", obj->movido);
	printf("Ilumina el objeto? (0=NO, 1=SI): %d\n", obj->ilumina);
	printf("Esta encendido el objeto? (0=NO, 1=SI): %d\n", obj->encendido);
	printf("Esta oculto el objeto? (0=NO, 1=SI): %d\n", obj->oculto);
	printf("Tema: %d\n", obj->tema);
	printf("Ataque: %d\n", obj->ataque);
	printf("Defensa: %d\n\n", obj->defensa);
}

/**
* @brief Asigna el valor def al campo defensa del objeto
* @param o objeto a actualizar
* @param def valor a asignar
* @return BOOL TRUE si se ha asignado bien, FALSE si el objeto es nulo
*/
BOOL establece_defensa(Objeto *o, int def){
	if(o==NULL)
		return FALSE;
		
	o->defensa = def;
	
	return TRUE;
}

/**
* @brief Asigna el valor atk al campo ataque del objeto
* @param o objeto a actualizar
* @param atk valor a asignar
* @return BOOL TRUE si se ha asignado bien, FALSE si el objeto es nulo
*/
BOOL establece_ataque(Objeto *o, int atk){
	if(o==NULL)
		return FALSE;
		
	o->ataque = atk;
	
	return TRUE;
}

/**
* @brief Devuelve el valor del campo defensa del objeto
* @param o objeto cuya informacion queremos
* @return int valor del campo defensa, 0 en caso de objeto nulo
*/
int dame_def_obj(Objeto *o){
	if(o==NULL)
		return 0;
		
	return o->defensa;
}

/**
* @brief Devuelve el valor del campo ataque del objeto
* @param o objeto cuya informacion queremos
* @return int valor del campo ataque, 0 en caso de objeto nulo
*/
int dame_atk_obj(Objeto *o){
	if(o==NULL)
		return 0;
		
	return o->ataque;
}
