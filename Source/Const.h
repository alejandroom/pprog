#ifndef CONST_H_
#define CONST_H_


#define NO_ID -1 
#define TAM_MAX_CNJ 100
#define TAMANO_PAL 5000
#define MAX_ESPACIOS 100
#define MAX_OBJETOS 100
#define MAX_UNIONES 100
#define BATALLA_FINAL 112		/* Espacio en que tendra lugar la batalla final */
#define MAX_REGLAS 255
#define MAX_REGLAS_TOTAL 500
#define MAX_TEMAS 500
#define MAX_PL  100
#define TAMANO_PAL_XML 5000


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long Id;  
typedef int Tam;

typedef enum {N, S, E, O, ARRIBA, ABAJO} Direccion;

typedef enum {FALSE, TRUE, FINAL} BOOL;

/* Lista de temas posibles 
 * Cada tema tiene asociado una o mas frases
 */
typedef enum {
	IR_SUCCESS=0,
	IR_FAIL, 
	COGER_SUCCESS,
	COGER_FAIL,
	DEJAR_SUCCESS,
	DEJAR_FAIL,
	EXAMINAR_SUCCESS,
	EXAMINAR_FAIL,
	ENCENDER_SUCCESS,
	ENCENDER_FAIL,
	APAGAR_SUCCESS,
	APAGAR_FAIL,
	ABRIR_SUCCESS,
	ABRIR_FAIL,
	DIALOGAR_SUCCESS,
	DIALOGAR_FAIL,
	ATACAR_NO,
	ATACAR_CRIT,
	ATACAR_BASIC,
	ATACAR_FAIL,
	ATACAR_VICTORY,
	ATACAR_DEATH,
	TONTA,
} Tema;

#endif
