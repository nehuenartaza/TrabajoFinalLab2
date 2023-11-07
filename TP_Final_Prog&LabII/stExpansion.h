#ifndef STEXPANCION_H_INCLUDED
#define STEXPANCION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Constantes.h"

typedef struct {
    char expansionTitulo[DIM2];
    char expansionSubTit[DIM2];
} stExpansion;

stExpansion cargaExpansion(char[], char[]);    //Carga
void muestraExpansion(stExpansion);   //Muestra

#endif // STEXPANCION_H_INCLUDED
