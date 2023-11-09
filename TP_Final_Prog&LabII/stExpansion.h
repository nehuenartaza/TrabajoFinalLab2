///Librerias
#ifndef STEXPANCION_H_INCLUDED
#define STEXPANCION_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Constantes.h"

///Estructuras
typedef struct {
    char expansionTitulo[DIM2];
    char expansionSubTit[DIM2];
} stExpansion;

///Prototipados
stExpansion cargaExpansionUsuario(stExpansion);    //Carga
void muestraExpansion(stExpansion);   //Muestra

#endif // STEXPANCION_H_INCLUDED
