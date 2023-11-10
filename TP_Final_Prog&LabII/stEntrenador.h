#ifndef STENTRENADOR_H_INCLUDED
#define STENTRENADOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Constantes.h"

typedef struct {
    int estado;
    char efecto[DIM1];
} stEntrenador;

void muestraEntrenador(stEntrenador);    //Muestra Entrenador

#endif // STENTRENADOR_H_INCLUDED
