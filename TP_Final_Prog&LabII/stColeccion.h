#ifndef STCOLECCION_H_INCLUDED
#define STCOLECCION_H_INCLUDED

#include "stCarta.h"
typedef struct {
  stCarta dataColecc;

  struct stColeccion * sigNodo;
  struct stColeccion * antNodo;
}stListaD;

int contarCartasListaDoble(stListaD *);
stListaD * romperEnlaces(stListaD*);
stListaD * agregarInicioColeccion(stListaD *, stListaD *);
stListaD * agregarFinalColeccion(stListaD *, stListaD *);
stListaD * retornarUltimaCarta(stListaD *);
void mostrarListaDoble(stListaD *);

#endif // STCOLECCION_H_INCLUDED
