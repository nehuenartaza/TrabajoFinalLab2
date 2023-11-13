#ifndef LISTADOBLE_H_INCLUDED
#define LISTADOBLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "stColeccion.h"
#include "stMazo.h"

typedef struct {
    stColeccion dataColec;
    struct stListaD * sigNodo;
    struct stListaD * antNodo;
} stListaD;

int ContarCartasListaDoble(stListaD*Lista);
//void BorrarNodoYMeterEnMazoNodoElegidoConContador(stListaD**Lista,stMazo*Pila,int numeroDePosicion,int contador); revisar si usamos stCarta o stColeccion

#endif // LISTADOBLE_H_INCLUDED
