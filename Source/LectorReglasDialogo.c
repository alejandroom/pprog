/**
* @brief Utilidades del lector de reglas de dialogo
*
* Este modulo contiene las funciones de manejo del
* lector de reglas de dialogo
* @file LectorReglasDialogo.c
* @author Alejandro Ortiz
* @version 1.0
* @date 1-05-2012
*/

#include "LectorReglasDialogo.h"

/**
* @brief Lee las reglas de dialogo a partir de un fichero .txt, mas datos sobre el fichero
* @param fichero nombre del fichero a leer
* @return BOOL TRUE si se lee con exito, FALSE si hay algun error
*/
BOOL lee_reglas(char *fichero){
	FILE *f;
	char linea[TAMANO_PAL];
	int nReglas, num, tema;
	int i,j;
	Regla *regla;
	
	if(fichero==NULL)
		return FALSE;
	
	inicializa_reglas();

	f=fopen(fichero, "r");
	if(f==NULL)
		return FALSE;
	
	do{
		fgets(linea, TAMANO_PAL, f);
		linea[strlen(linea)-1]=0;
	}while(strcmp(linea, "-----"));
	 
	fgets(linea, TAMANO_PAL, f);
	linea[strlen(linea)-1]=0;
	
	nReglas=atoi(linea);
	for(i=0;i<nReglas;i++){
		regla = nueva_regla();
		fgets(linea, TAMANO_PAL, f);
		fgets(linea, TAMANO_PAL, f);
		linea[strlen(linea)-1]=0;
		
		tema=atoi(linea);
		if( linea!=0 && strcmp(linea, "0")==0 ){
			fclose(f);
			return FALSE;
		}
		
		fgets(linea, TAMANO_PAL, f);
		linea[strlen(linea)-1]=0;
		
		if(strcmp(linea, "0")!=0){
			num=atoi(linea);
			if(num==0){
				fclose(f);
				return FALSE;
			}
			fflush(NULL);
			
			inicializa_patrones(regla, num);
			for(j=0;j<num;j++){
				fgets(linea, TAMANO_PAL, f);
				linea[strlen(linea)-1]=0;
				
				annade_patron(regla, linea, j);
			}
		}
		
		fgets(linea, TAMANO_PAL, f);
		linea[strlen(linea)-1]=0;
		
		num=atoi(linea);
		if(num==0){
			fclose(f);
			return FALSE;
		}
		inicializa_plantillas(regla, num);
		for(j=0;j<num;j++){
			fgets(linea, TAMANO_PAL, f);
			linea[strlen(linea)-1]=0;
			
			annade_plantilla(regla, linea, j);
		}
		annade_regla(regla, tema, -1);

		destruye_regla(regla);
	}
	
	fclose(f);
	return TRUE;
}
