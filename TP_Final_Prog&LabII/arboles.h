#ifndef ARBOLES_H_INCLUDED
#define ARBOLES_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "stColeccion.h"

typedef struct {
    struct stlistaD * coleccion;
    struct stArbol * ramaDer;
    struct stArbol * ramaIzq;
} stArbol;



#endif // ARBOLES_H_INCLUDED
