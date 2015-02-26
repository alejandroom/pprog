/* 
 * File:   main.c
 * Author: e250625
 *
 * Created on 27 de marzo de 2012, 9:24
 */

#include <stdio.h>
#include <stdlib.h>
#include "Mundo.h"
#include "Accion.h"
#include "UtilCadena.h"
#include "ReglasDialogo.h"
#include "Animacion.h"

int main(int argc, char *argv[]) {

	Mundo *m;
	Accion *a;
	int tema=0, temaaux;
	FILE *fent;
	char  nombre[100];
	char  linea[100];
	char  lineaux[100];
	int i=0;
	
	if(argc!=3){
		printf("Argumentos incorrectos, introduzca el fichero de reglas seguido del fichero xml que contiene el mundo.\n");
		return -1;
	}
	lee_reglas(argv[1]);
	m = nuevo_mundo();
	a = crea_accion();
	
	iniMundo(argv[2], m);

	printf("\nIntroduzca un nivel de dificultad: facil, medio o dificil (si pones un nivel no valido se pondra por defecto en facil, nenaza).\n");
	fgets(nombre, 100, stdin);
	nombre[strlen(nombre)-1]='\0';
	inicializa_dificultad(m, nombre);

	presentacion();
	printf("\nOoooh me duele la cabeza! que ha pasado? Como me llamo?\n");
	fgets(nombre, 100, stdin);
	nombre[strlen(nombre)-1]='\0';
	establece_nombre_jugador(dame_jugador_mundo(m), nombre);
	printf("\nLo ultimo que recuerdo es la terrible tormenta... quizas deberia echar un vistazo por aqui a ver si hay alguna forma de salir de este sitio...\n");
	fgets(linea, 100, stdin);
	desc_real_espacio(m, linea);
	printf("%s\n", linea);

	while (1) {
		printf("\nQue quieres hacer?\n");
		fgets(linea, 100, stdin);
		linea[strlen(linea)-1]='\0';
		system("clear");
		
		if (strcmp(linea,"")!=0){	
			elimina_cars(lineaux, linea, ";/:", strlen(linea));
			a_mayusculas(linea, lineaux, strlen(lineaux));
			limpia_espacios(lineaux, linea, strlen(linea));

			if(strcmp(linea, "CERRAR")==0 || strcmp(linea, "SALIR")==0){

				printf("Seguro que quieres salir?\n");
				fgets(linea, 100, stdin);
				linea[strlen(linea)-1]='\0';
			
				elimina_cars(lineaux, linea, ";/:", strlen(linea));
				a_mayusculas(linea, lineaux, strlen(lineaux));
				limpia_espacios(lineaux, linea, strlen(linea));

				if(strcmp(linea, "SI")==0 || strcmp(linea, "POS CLARO")==0){
					despedida();
					destruye_mundo(m);
					destruye_reglas();
					destruye_accion(a);
					return 0;
				}
			}			

			else if(introduce_accion(lineaux, a)==TRUE){
				temaaux=ejecuta_accion(m, a);
				if (temaaux==-3)
					tema=-1;
				else if (temaaux==-4){
					fgets(linea, 100, stdin);
					ejecuta_victoria(dame_nombre_jugador(dame_jugador_mundo(m)));
					return;
				}else if (temaaux==-5){
					fgets(linea, 100, stdin);
					ejecuta_derrota();
					return;
				}else if(temaaux!=-2 && temaaux!=-1)
					tema=temaaux;
				
			}else{
			   	strcpy(linea, selecciona_plan_azar(busca_regla(tema, lineaux)));
				printf("%s\n", linea);
			}
		}
	}
}
