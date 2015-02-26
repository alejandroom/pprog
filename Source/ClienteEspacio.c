
/*Autor: Irene Colmenar*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Espacio.h"


int main() {
    Espacio *es;
    char desc[25]=("cadenadeprueba");
    char descex[25]=("cadenadepruebasegunda");
    
    es=nuevo_espacio(1);
    nueva_desc_examinar_espacio(es, descex);
    nueva_desc_espacio(es, desc);
    nueva_union_norte_espacio(es, 2);
    nueva_union_sur_espacio(es, 3);
    nueva_union_este_espacio(es, 4);
    nueva_union_oeste_espacio(es, 5);
    nueva_union_arriba_espacio(es, 6);
    nueva_union_abajo_espacio(es, 7);
    annade_objeto_espacio(es, 8);
    
    assert (dame_norte_espacio(es)==2);
    assert (dame_sur_espacio(es)==3);
    assert(dame_este_espacio(es)==4);
    assert (dame_oeste_espacio(es)==5);
    assert (dame_arriba_espacio(es)==6);
    assert (dame_abajo_espacio(es)==7);
    
    assert(quita_objeto_espacio(es, 8)==TRUE);
    assert(devuelve_id_espacio (es)==1);
    
    return (EXIT_SUCCESS);
}

