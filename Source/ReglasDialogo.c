/**
* @brief Utilidades de manejo de reglas en el dialogo
*
* Este modulo contiene las funciones de manejo de
* reglas.
* @file ReglasDialogo.c
* @author Alejandro Ortiz Irene Colmenar
* @version 2.0 incluidas funciones para reservar memoria, inicializar las reglas y liberarlas
* @date 1-05-2012
*/

#include "ReglasDialogo.h"

struct _regla 
{
  char ** patr_ent;      /* Si una cadena esta contenida en este vector, entonces se ejecuta esta regla */
  int num_patr_ent; /*Numero de posibles mensajes de entrada*/
  char ** plan_sal;   /*Conjunto de mensajes a imprimir por pantalla, en caso de que el usuario haya introducido algun mensaje contenido en entrada*/
  int num_plan_sal; /*Numero de respuestas posibles*/
  int ult;            /* Ultima respuesta que se ha mostrado por pantalla */
};

/* Lista con el conjunto de reglas que guian el dialogo */
Regla l_regla[MAX_REGLAS_TOTAL];

/* Lista que define la relacion entre temas y reglas. Cada tema tiene asociada 
	una o mas reglas. Varios temas pueden compartir la misma regla.
	La reglas se comprueban siguiendo el orden especificado en el tema.
*/
static int l_tema[MAX_TEMAS][MAX_REGLAS];

/**
* @brief Reserva la memoria para una nueva regla
* @return Regla* puntero a la nueva regla, NULL en caso de error
*/
Regla *nueva_regla(){
	Regla *regla;

	regla = (Regla*) malloc(sizeof(Regla));
	
	regla->num_patr_ent = 0;
	regla->num_plan_sal = -1;
	regla->ult = -1;

	return regla;
}

/**
* @brief Libera la memoria correspondiente a una regla
* @param regla Regla a liberar
*/
void destruye_regla(Regla *regla){
	int j;

	if(regla == NULL)
		return;

	if(regla->num_patr_ent!=0){
		for(j=0;j<regla->num_patr_ent;j++)
			free(regla->patr_ent[j]);
		free(regla->patr_ent);
	}

	for(j=0;j<regla->num_plan_sal;j++)
		free(regla->plan_sal[j]);
	free(regla->plan_sal);
	free(regla);
}

/**
* @brief Inicializa el numero de patrones y reserva memoria para estos
* @param regla regla a manejar
* @param patrones numero de patrones
* @return BOOL TRUE si se inicializa y reserva con exito, FALSE si hay algun error
*/
BOOL inicializa_patrones(Regla *regla, int patrones){
	if(regla == NULL)
		return FALSE;

	regla->num_patr_ent=patrones;
	regla->patr_ent=(char**)malloc(sizeof(char*)*patrones);
	if(regla->patr_ent == NULL)
		return FALSE;

	return TRUE;
}

/**
* @brief Añade un patron a la regla indicada en la posicion indicada
* @param regla regla a modificar
* @param patron patron a añadir
* @param pos posicion del array de patrones donde añadir el patron
* @return BOOL TRUE si se añade con exito, FALSE si no es asi
*/
BOOL annade_patron(Regla *regla, char *patron, int pos){
	if(regla == NULL || patron  == NULL)
		return FALSE;

	if(regla->num_patr_ent < pos)
		return FALSE;
	
	regla->patr_ent[pos]=(char*)malloc(sizeof(char)*(strlen(patron)+1));
	if(regla->patr_ent[pos] == NULL)
		 return FALSE;

	strcpy(regla->patr_ent[pos], patron);
	
	return TRUE;
}

/**
* @brief Inicializa el numero de plantillas y reserva memoria para estos
* @param regla regla a manejar
* @param plantillas numero de plantillas
* @return TRUE si se inicializa y reserva con exito, FALSE si hay algun error
*/
BOOL inicializa_plantillas(Regla *regla, int plantillas){
	if(regla == NULL)
		return FALSE;

	regla->num_plan_sal=plantillas;
	regla->plan_sal=(char**)malloc(sizeof(char*)*plantillas);
	if(regla->plan_sal == NULL)
		return FALSE;

	return TRUE;
}

/**
* @brief Añade una plantilla a la regla indicada en la posicion indicada
* @param regla regla a modificar
* @param plantilla plantilla a añadir
* @param pos posicion del array de plantillas donde añadir la plantilla
* @return BOOL TRUE si se añade con exito, FALSE si no es asi
*/
BOOL annade_plantilla(Regla *regla, char *plantilla, int pos){
	if(regla == NULL || plantilla  == NULL)
		return FALSE;

	if(regla->num_plan_sal < pos)
		return FALSE;
	
	regla->plan_sal[pos]=(char*)malloc(sizeof(char)*(strlen(plantilla)+1));
	if(regla->plan_sal[pos] == NULL)
		 return FALSE;

	strcpy(regla->plan_sal[pos], plantilla);
	
	return TRUE;
}

/**
* @brief Selecciona la siguiente plantilla de salida de una regla
* @param ind_regla numero de la regla
* @return char* plantilla seleccionada
*/
extern char * selecciona_plan_sal(int ind_regla){
	if((l_regla[ind_regla].num_plan_sal)-1==l_regla[ind_regla].ult){
		l_regla[ind_regla].ult=-1;
	}
	
	l_regla[ind_regla].ult++;
	
	return l_regla[ind_regla].plan_sal[l_regla[ind_regla].ult]; 
}

/**
* @brief Dada una frase, busca en los patrones de las reglas de un tema dado y devuelve la regla que concuerde
* @param tema numero de tema en que buscar
* @param txt_ent frase
* @return int numero de regla seleccionada
*/
extern int busca_regla(int tema, const char *txt_ent){
	int i=0;
	
	if(txt_ent==NULL || tema==-1)
		return TONTA;

	while (l_tema[tema][i]!=-1)
	{		
		if((strstr(txt_ent, l_regla[l_tema[tema][i]].patr_ent[0]))!=NULL){		 
		return l_tema[tema][i];
		}
		i++;
	}	 
		
	return TONTA;
} 

/**
* @brief Dado un indice de regla, selecciona una plantilla al azar
* @param ind_regla numero de regla en que busca
* @return char* plantilla resultante
*/
extern char * selecciona_plan_azar(int ind_regla){
		int a;	
		
		a = l_regla[ind_regla].num_plan_sal;
		a=rand() % a;
		
		return (l_regla[ind_regla].plan_sal[a]);
}

/**
* @brief Devuelve el tamaño de un patron concreto de una regla
* @param ind_regla numero de regla
* @param ind_patr_entr numero de patron
* @return int longitud
*/
extern int tam_patron_regla(int ind_regla, int ind_patr_entr){
	if (ind_regla<0 || ind_regla>44 || ind_patr_entr>l_regla[ind_regla].num_patr_ent)
		return 0;
		
	return (strlen (l_regla [l_tema[ind_patr_entr][ind_regla]].plan_sal[ind_patr_entr]));
}

/**
* @brief Inicializa las reglas, se considera una regla nula cuando el numero de plantillas es -1
*/
void inicializa_reglas(){
	int i;
	
	for(i=0;i<MAX_REGLAS_TOTAL;i++)
		l_regla[i].num_plan_sal=-1;
	for(i=0;i<MAX_TEMAS;i++)
		l_tema[i][0]=-1;	
}

/**
* @brief Destruye las reglas, liberando la memoria reservada cuando sea necesario
*/
void destruye_reglas(){
	int i, j;
	
	for(i=0;i<MAX_REGLAS_TOTAL;i++){
		if(l_regla[i].num_plan_sal!=-1){
			if(l_regla[i].num_patr_ent!=0){
				for(j=0;j<l_regla[i].num_patr_ent;j++)
					free(l_regla[i].patr_ent[j]);
				free(l_regla[i].patr_ent);
			}
			
			for(j=0;j<l_regla[i].num_plan_sal;j++)
				free(l_regla[i].plan_sal[j]);
			free(l_regla[i].plan_sal);
		
			l_regla[i].num_plan_sal=-1;
		}
	}
}

/**
* @brief Añade un numero de regla(una regla) a un tema
* @param regla numero de regla
* @param tema numero de tema
* @return BOOL TRUE en caso de que la funcion funcione correctamente, FALSE en caso de que ocurra algun error
*/
BOOL annade_regla_temas(int tema, int regla){
	int i;
	
	if(tema==-1)
		return TRUE;

	for(i=0;l_tema[tema][i]!=-1 && i<MAX_REGLAS-1;i++);

	if(i==MAX_REGLAS-1)
		return FALSE;
		
	l_tema[tema][i]=regla;
	l_tema[tema][i+1]=-1;

	return TRUE;
}

/**
* @brief Añade una regla al conjunto de reglas
* @param regla regla que incluir
* @param posicion posicion donde incluir la regla(-1 si no hay preferencias)
* @return BOOL TRUE en caso de que la funcion funcione correctamente, FALSE en caso de que ocurra algun error
*/
BOOL annade_regla_reglas(Regla *regla, int posicion){
	int i;
	
	if(regla==NULL || posicion>=MAX_REGLAS_TOTAL)
		return FALSE;
	
	if(l_regla[posicion].num_plan_sal!=-1)
		return FALSE;
		
	l_regla[posicion].num_patr_ent=regla->num_patr_ent;
	if(l_regla[posicion].num_patr_ent!=0){
		l_regla[posicion].patr_ent=(char**)malloc(sizeof(char*)*regla->num_patr_ent);
		for(i=0;i<regla->num_patr_ent;i++){
			l_regla[posicion].patr_ent[i]=(char*)malloc(sizeof(char)*(strlen(regla->patr_ent[i])+1));
			strcpy(l_regla[posicion].patr_ent[i], regla->patr_ent[i]);
		}
		}
	l_regla[posicion].num_plan_sal=regla->num_plan_sal;
	l_regla[posicion].plan_sal=(char**)malloc(sizeof(char*)*regla->num_plan_sal);
	for(i=0;i<regla->num_plan_sal;i++){
		l_regla[posicion].plan_sal[i]=(char*)malloc(sizeof(char)*(strlen(regla->plan_sal[i])+1));
		strcpy(l_regla[posicion].plan_sal[i], regla->plan_sal[i]);
	}
	
	l_regla[posicion].ult=-1;
	
	return TRUE;
}

/**
* @brief Añade una regla y un tema
* @param regla regla que incluir
* @param tema numero de tema de la regla
* @param posicion posicion donde incluir la regla(-1 si no hay preferencias)
* @return BOOL TRUE en caso de que la funcion funcione correctamente, FALSE en caso de que ocurra algun error
*/
BOOL annade_regla(Regla *regla, int tema, int posicion){
	int i;
	
	if(posicion!=-1){	
		if(annade_regla_reglas(regla, posicion)==TRUE)
			if(annade_regla_temas(tema, posicion)==TRUE)
				return TRUE;
		l_regla[posicion].num_plan_sal=-1;
		
		return FALSE;
	}
	
	for(i=0;l_regla[i].num_plan_sal!=-1 && i<MAX_REGLAS_TOTAL;i++);
	if(annade_regla_temas(tema, i)==TRUE)
		return annade_regla_reglas(regla, i);
		
	return FALSE;
}
