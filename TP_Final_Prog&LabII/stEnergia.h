#ifndef STENERGIA_H_INCLUDED
#define STENERGIA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "Constantes.h"

typedef struct {
    int estado;
    char tipoEnergia[DIM3];
} stEnergia;

void muestraEnergia(stEnergia); //Muestra Energia

#endif // STENERGIA_H_INCLUDED
