#ifndef STENTRENADOR_H_INCLUDED
#define STENTRENADOR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Constantes.h"

typedef struct {
    int estado;
    char efecto[DIM1];
} stEntrenador;

///Prototipados
//Muestra Entrenador
void muestraEntrenador(stEntrenador entrenadorAMostrar);

#endif // STENTRENADOR_H_INCLUDED
