/* 
 * File:   main.c
 * Author: Juan Manuel Cornet
 *
 * Created on 8 de marzo de 2012, 10:37
 */

#include <stdio.h>
#include <stdlib.h>
#include "Conjunto.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    int tam;
    Conjunto * cj;
    Id id=186002;
    Id id2;
    
    cj=nuevo_conjunto();
    
    incluye_id(cj, id);
    
    esta_id(cj, id);
    
    quita_id(cj, id);
    
    tam=tamano_conjunto(cj);
    
    incluye_id(cj, id);
    
    id2=dame_id_pos(cj, 0);
    
    imprime_conjunto(cj);
    
    quita_id(cj, id);
    
    es_vacio_conjunto(cj);
    
    destruye_conjunto(cj);

    return (EXIT_SUCCESS);
}

