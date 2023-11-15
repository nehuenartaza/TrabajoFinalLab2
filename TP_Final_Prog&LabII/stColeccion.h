#ifndef STCOLECCION_H_INCLUDED
#define STCOLECCION_H_INCLUDED

#include "stCarta.h"

typedef struct {
  stCarta dataColecc;

  struct stColeccion*sigNodo;
  struct stColeccion*antNodo;
}stListaD;

int ContarCartasListaDoble(stListaD*Lista);

#endif // STCOLECCION_H_INCLUDED
