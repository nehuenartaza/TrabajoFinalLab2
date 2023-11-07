#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "stColeccion.h"

typedef struct {
    stColeccion dataColec;
    struct stListaD * sigNodo;
    struct stListaD * antNodo;
} stListaD;

#endif // LISTADOBLE_H_INCLUDED
