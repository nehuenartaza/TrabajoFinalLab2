#ifndef STCARTA_H_INCLUDED
#define STCARTA_H_INCLUDED

#include "stClase.h"
#include "stExpansion.h"
#include "Constantes.h"

typedef struct {
    int id;
    int cant;
    char rareza[DIM4];
    char nombre[DIM2];
    stClase claseCarta;
    stExpansion expansionCarta;
} stCarta;



#endif // STCARTA_H_INCLUDED
