#ifndef STCARTA_H_INCLUDED
#define STCARTA_H_INCLUDED

#include "stClase.h"
#include "stExpansion.h"

typedef struct
{
    int id;
    int cant;
    char rareza[DIM3];
    char nombre[DIM2];
    stClase claseCarta;
    stExpansion expansionCarta;
}stCarta;

typedef struct
{
    char inicial;
    struct listaDeCartas * listaDeCartasPorInicial;

    struct arbolDeListasCartas * izquierda;
    struct arbolDeListasCartas * derecha;
}arbolDeListasCartas;

typedef struct
{
    stCarta dato;

    struct listaDeCartas * siguiente;
    struct listaDeCartas * anterior;
}listaDeCartas;

///Stcarta
stCarta cargaCartaUsuario();    //Carga una carta
void muestraCarta(stCarta);   //Muestra Carta

///ListaDoble De Cartas
listaDeCartas * creaNodoConCarta(stCarta);  //Crea Nodo de la Lista de Cartas
listaDeCartas * cargaCartas(listaDeCartas *);  //Carga Lista de Carta
listaDeCartas * cargaAFIN(listaDeCartas *, listaDeCartas *);   //Carga al final
listaDeCartas * buscaUltimoNodoListaCartas(listaDeCartas *);  //Busca Ultimo
void muestraListaCartas(listaDeCartas *);   //Muestra Nodo2 Lista Cartas
void muestraNodoCarta(listaDeCartas *);  //Muestra Nodo de la lista

///Arboles de Listas
arbolDeListasCartas * creaNodoArbolCartas(char); //Crea Nodo Arbol
arbolDeListasCartas * buscaNodoConInicial(arbolDeListasCartas *, char); //Busca Nodo Arbol Por Inicial de Pokemon
arbolDeListasCartas * agregarNodoArbol(arbolDeListasCartas *, arbolDeListasCartas *);    //Agrega Nodo Arbol
void muestraArbolDeCartas(arbolDeListasCartas *);   //Muestra Arbol
void muestraRaiz(arbolDeListasCartas *); //Muestra Raiz
arbolDeListasCartas * cargaArbolDeListasDeCartasUsuario(arbolDeListasCartas *);    //Carga Arbol Usuario
arbolDeListasCartas * agregaCartaANodoDeArbol(arbolDeListasCartas* raizActual_F, char inicialDeNodoArbol, listaDeCartas * nuevaCarta_F);
arbolDeListasCartas * altaCarta(arbolDeListasCartas * raizActual_F, stCarta cartaACargar);   //Carga un pokemon por inicial y si no esta crea el nodo de la incial

#endif // STCARTA_H_INCLUDED
