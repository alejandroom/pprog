/* 
 * File:   main.c
 * Author: Juan Manuel
 *
 * Created on 8 de marzo de 2012, 11:03
 */

#include <stdio.h>
#include <stdlib.h>
#include "Inventario.h"

/*
 * 
 */
int main(int argc, char** argv) {
    
    Inventario * inv;
    Id id=168003, id2=97001;
    
    inv=nuevo_inventario(10);
    
    nuevo_obj_inventario(inv, id);
    nuevo_obj_inventario(inv, id2);
    
    buscar_obj(inv, id);
    buscar_obj(inv, id2);
    
    quita_obj(inv, id);
    quita_obj(inv, id2);
    
    destruye_inventario(inv);
    
    return (EXIT_SUCCESS);
}
