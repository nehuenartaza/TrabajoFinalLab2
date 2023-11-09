///Librerias
#ifndef STPOKEMON_H_INCLUDED
#define STPOKEMON_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Constantes.h"

///Estructuras
typedef struct {
    int estado;
    int puntosAtaque;
    char tipo[DIM3];
    char ataqueNro1[DIM1];
    char ataqueNro2[DIM1];
} stPokemon;

///Prototipados
stPokemon cargaPokemon(int, char[], char[], char[]); //Carga Pokemon
void muestraPokemon(stPokemon); //Muestra Pokemon

#endif // STPOKEMON_H_INCLUDED
