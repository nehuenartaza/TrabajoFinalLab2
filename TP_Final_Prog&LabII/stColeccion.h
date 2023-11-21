#ifndef STCOLECCION_H_INCLUDED
#define STCOLECCION_H_INCLUDED

#include "stDatosUsuario.h"


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
void buscarCartasPorStringAproximado(stListaD *, char[]);
stListaD * eliminarYRetirarCartaDeColeccion(stListaD *, stCarta *); ///elimina 1 unidad de una carta en la colección pero se retorna el dato extraído para un intercambio (no setea la cantidad de la carta extraída en 1)
bool IDsCartasCoinciden(stCarta, stCarta);
stListaD * borrarNodoDeColeccion(stListaD *, stCarta *);    ///borra una carta de la colección, generalmente porque la cantidad de la carta es 0, va de la mano con eliminarYRetirar...
void buscarCartasPorRareza(stListaD *, char[]);
bool rarezasCartasCoinciden(char[], char[]);
void buscarCartaPorID(stListaD *, int);
bool verificaSiListaDobleEstaVacia(stListaD *); // Retorna false si esta vacia, o true si tiene algun nodo cargado
///Necesarias para Intercambio
stCarta buscarCartaPorIDYLaRetorna(stListaD * lista, int id);
stListaD * creaNodoColeccion(stCarta cartaAGuardar);
stListaD * buscaNodoEnColeccionPorId(stListaD * coleccionARevisar , stCarta cartaABuscar);
stListaD * altaCartaEnColeccion(stListaD * coleccionACargar , stCarta cartaACargar);

#endif // STCOLECCION_H_INCLUDED
