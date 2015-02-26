
/* Author: Irene Colmenar Guindal */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Union.h"

int main() {

    Union *u;

    /* CREAMOS */

    u = nueva_union(1);

    /* INTRODUCIMOS DATOS Y COMPROBAMOS */

    assert(devuelve_id_union(u) == 1);
    une_espacios(u, 2, 3);
    assert(dame_espacio_unido(u, 2) == 3);
    assert(dame_espacio_unido(u, 3) == 2);
    assert(dame_espacio_unido(u, 4) == NO_ID);
    assert(es_union_abrible(u) == TRUE);
    assert(abre_union(u) == TRUE);
    establece_abrible(u, FALSE);
    assert(es_union_abrible(u) == FALSE);
    assert(abre_union(u) == FALSE);
    assert(cierra_union(u));
    imprime_union(u);
    
    /* ELIMINAMOS */
    
    destruye_union(u);
    return 0;
}
