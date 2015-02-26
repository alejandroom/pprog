/* 
 * File:   main.c
 * Author: Juan Manuel Cornet
 *
 * Created on 8 de marzo de 2012, 11:24
 */

#include <stdio.h>
#include <stdlib.h>
#include "Objeto.h"

/*
 * 
 */
int main(int argc, char** argv) {

    Id idObjeto1=00000001;
    Objeto * objeto1;
    const char * descripcion;
    const char * descExaminar;
    const char * descMovido;
    BOOL bol;
    
    objeto1=nuevo_obj(idObjeto1);
    
    nuevo_nombre_obj(objeto1, "Farol");
    
    nueva_desc_obj(objeto1, "Un viejo farol inservible que se encuentra sobre una mesa derruida.");
    
    nueva_desc_examinar_obj(objeto1, "Al examinar el objeto puedes ver que en su interior hay una vieja llave.");
    
    nueva_desc_movil_obj(objeto1, "El viejo farol se encuentra ahora en tu posesion.");
    
    actualiza_movil_obj(objeto1, TRUE);
    
    actualiza_movido_objeto(objeto1, TRUE);
    
    actualiza_iluminable_obj(objeto1, FALSE);
    
    actualiza_ilumina_obj(objeto1, FALSE);
    
    actualiza_oculto_objeto(objeto1, FALSE);
    
    descripcion=descripcion_objeto(objeto1);
    
    descMovido=descripcion_objeto_movido(objeto1);
    
    descExaminar=descripcion_objeto_examinar(objeto1);
    
    bol=es_movil_objeto(objeto1);
    
    bol=es_movido_objeto(objeto1);
    
    bol=ilumina_objeto(objeto1);
    
    bol=es_encendido_objeto(objeto1);
    
    bol=oculta_obj(objeto1);
    
    imprime_objeto(objeto1);
    
    destruye_objeto(objeto1);   
    
    return (EXIT_SUCCESS);
}

