#ifndef STCOLECCION_H_INCLUDED
#define STCOLECCION_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "stcarta.h"
typedef struct {
  stCarta dataColecc;

  struct stColeccion*sigNodo;
  struct stColeccion*antNodo;
}stListaD;

int ContarCartasListaDoble(stListaD*Lista);

#endif // STCOLECCION_H_INCLUDED
