#ifndef STCOLECCION_H_INCLUDED
#define STCOLECCION_H_INCLUDED

#include "stDatosUsuario.h"


typedef struct {
  stCarta dataColecc;

  struct stListaD * sigNodo;
  struct stListaD * antNodo;
}stListaD;


int contarCartasListaDoble(stListaD *);
stListaD * romperEnlaces(stListaD*);
stListaD * agregarInicioColeccion(stListaD *, stListaD *);
stListaD * agregarFinalColeccion(stListaD *, stListaD *);
stListaD * retornarUltimaCarta(stListaD *);

stListaD * agregarPorIDColeccion(stListaD *, stListaD *);
void mostrarListaDoble(stListaD *);
void mostrarCartasPorStringAproximado(stListaD *, char[]);
stListaD * eliminarYRetirarCartaDeColeccion(stListaD *, stCarta *); ///elimina 1 unidad de una carta en la colección pero se retorna el dato extraído para un intercambio (no setea la cantidad de la carta extraída en 1)
bool IDsCartasCoinciden(stCarta, stCarta);
stListaD * borrarNodoDeColeccion(stListaD *, stCarta *);    ///borra una carta de la colección, generalmente porque la cantidad de la carta es 0, va de la mano con eliminarYRetirar...
void mostrarCartasPorRareza(stListaD *, char[]);
bool rarezasCartasCoinciden(char[], char[]);
void mostrarCartaPorID(stListaD *, int);
stListaD * buscarYRetornarCartaPorID(stListaD *, int);
bool verificaSiListaDobleEstaVacia(stListaD *); // Retorna false si esta vacia, o true si tiene algun nodo cargado
void mostrarCartasPorClasePokemon(stListaD *);
void mostrarCartasPorClaseEnergia(stListaD *);
void mostrarCartasPorClaseEntrenador(stListaD *);
void mostarCartasPorExpansion(stListaD *, char[]);
void mostarCartasPorExpansionAuxiliar(stListaD *, char[]);

///Necesarias para Intercambio
stCarta buscarCartaPorIDYLaRetorna(stListaD * lista, int id);
stListaD * creaNodoColeccion(stCarta cartaAGuardar);
stListaD * buscaNodoEnColeccionPorId(stListaD * coleccionARevisar , stCarta cartaABuscar);
stListaD * altaCartaEnColeccion(stListaD * coleccionACargar , stCarta cartaACargar);
datosUsuario guardaIndicadoresDeColeccion(stListaD * coleccionAGuardar, datosUsuario usuarioAEditar);

//Funciones para estadisticas
int contadorCartasTotalesEnColeccion(stListaD *);
int contadorCartasPokemonEnColeccion(stListaD *);
int contadorCartasEntrenadorEnColeccion(stListaD *);
int contadorCartasEnergiaEnColeccion(stListaD *);

#endif // STCOLECCION_H_INCLUDED
