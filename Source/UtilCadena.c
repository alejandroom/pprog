/**
* @brief Utilidades de manejo de caracteres
*
* Este modulo contiene las funciones de manejo de
* caracteres.
* @file UtilCadena.c
* @author Irene Colmenar
* @version 1.0
* @date 1-05-2012
*/

#include "UtilCadena.h"

/**
* @brief Elimina los caracteres indicados de la cadena
* @param ori cadena de caracteres que limpiar
* @param seps cadena de caracteres que tiene los caracteres a eliminar
* @param dst cadena de caracteres donde guardar el resultado
* @param n longitud de la cadena a modificar
* @return char* dst modificada
*/
extern char * elimina_cars(char * dst, const char * ori, const char * seps, size_t n){
	int i,j;
	
	if (dst == NULL || seps == NULL || strlen(ori) > n)
		return NULL;
		
	strcpy (dst,ori);
	
	for(i=0;dst[i]!=0;i++ )
	{
		for(j=0;seps[j]!=0;j++)
		{
			if (seps[j]==dst[i])
				dst[i]=' ';
		}
	}	  
	
	return dst;   
}

/**
* @brief Pasa la cadena de caracteres a mayusculas
* @param ori cadena de caracteres que modificar
* @param dst cadena de caracteres donde guardar el resultado
* @param n longitud de la cadena a modificar
* @return char* dst modificada
*/
extern char * a_mayusculas(char * dst, const char * ori, size_t n){
	int i;
	
	if (ori == NULL || dst == NULL || strlen (ori) > n)
		return NULL;
		
	strcpy (dst,ori);
	
	for(i=0;dst[i]!=0;i++)
	{
		if (dst[i]>=97)
			dst[i]-=32 ;
	}  
	
	return dst;
}

/**
* @brief Elimina los espacios innecesarios de la cadena
* @param ori cadena de caracteres que limpiar
* @param dst cadena de caracteres donde guardar el resultado
* @param n longitud de la cadena a modificar
* @return char* dst modificada
*/
extern char * limpia_espacios(char * dst, const char * ori, size_t n){
	int i=0,k,j=(n-1);
	
	if (dst ==NULL || ori==NULL  || n<0 || n<strlen(ori))
		return NULL;	
		
	while (i<n && ori[i]==' ')
		i++;	   
			
	while (j>=0 && ori[j]==' ')
		j--;
		   
	for (k=0;i<=j;i++){
		if(ori[i]==' '){
			if(ori[i+1]!=' '){
				dst[k]=ori[i];
				k++;
			}
		}else {
			dst[k]=ori[i];
			k++;
		}
	}
		
	return dst;
}

/**
* @author Alejandro
* @brief Dada una frase y su patron, selecciona el objeto
* @param ori cadena de caracteres que contiene la frase
* @param plan cadena de caracteres que tiene la patron
* @param dst cadena de caracteres donde guardar el resultado
* @return BOOL TRUE en caso de que el objeto se escriba en dst correctamente, FALSE en caso de que ocurra algun error
*/
BOOL dame_objeto(char *dst, char *ori, char *plan){
	int i=0, j=0;
	
	if(dst==NULL || ori==NULL || plan==NULL)
		return FALSE;
		
	while(ori[i]==plan[i] && plan[i]!=0)
		i++;
		
	if(plan[i]==0){
		dst[j]=0;
		return TRUE;
	}
	
	while(ori[i]!=0){
		dst[j]=ori[i];
		i++;
		j++;
	}
	
	dst[j]=0;
	return TRUE;
}

/**
* @author Alejandro
* @brief Dada una plantilla y un objeto, sustituye el asterisco de la plantilla por el objeto
* @param ori cadena de caracteres que contiene la plantilla
* @param obj cadena de caracteres que tiene el objeto
* @param dst cadena de caracteres donde guardar el resultado
* @return BOOL TRUE en caso de que el resultado se escriba en dst correctamente, FALSE en caso de que ocurra algun error
*/
BOOL reemplaza_asterisco(char *dst, char *ori, char *obj){
	int i=0, j=0, k=0;;
	
	if(dst==NULL || ori==NULL || obj==NULL)
		return FALSE;
		
	while(ori[i]!='*' && ori[i]!=0){
		dst[j]=ori[i];
		i++;
		j++;
	}
	
	if(ori[i]==0){
		dst[j]=0;
		return TRUE;
	}
	i++;
	
	while(obj[k]!=0){
		dst[j]=obj[k];
		k++;
		j++;
	}
	
	while(ori[i]!=0){
		dst[j]=ori[i];
		i++;
		j++;
	}
	dst[j]=0;
	
	return TRUE;
}
