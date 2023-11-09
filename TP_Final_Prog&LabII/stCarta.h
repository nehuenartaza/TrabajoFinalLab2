///Librerias
#ifndef STCARTA_H_INCLUDED
#define STCARTA_H_INCLUDED
#include "stClase.h"
#include "stExpansion.h"

///Estructuras
typedef struct
{
    int id;
    int cant;
    char rareza[DIM3];
    char nombre[DIM2];
    stClase claseCarta;
    stExpansion expancionCarta;
}stCarta;

typedef struct
{
    char inicial;
    struct listaDeCartas*listaDeCartasPorInicial;

    struct arbolDeListasCartas*izquierda;
    struct arbolDeListasCartas*derecha;
}arbolDeListasCartas;

typedef struct
{
    stCarta dato;

    struct listaDeCartas*siguiente;
    struct listaDeCartas*anterior;
}listaDeCartas;

///Prototipados

///Stcarta
//Carga una carta
stCarta cargaCartaUsuario();
//Muestra Carta
void muestraCarta(stCarta cartaAMostrar);

///ListaDoble De Cartas
//Inicializa Lista
listaDeCartas*inicLista();
//Crea Nodo de la Lista de Cartas
listaDeCartas*creaNodoConCarta(stCarta cartaAGuardar);
//Carga Lista de Carta
listaDeCartas*cargaCartas(listaDeCartas*listaACargar);
//Carga al final
listaDeCartas*cargaAFIN(listaDeCartas*listaACargar, listaDeCartas*nuevoNodo);
//Busca Ultimo
listaDeCartas*buscaUltimoNodoListaCartas(listaDeCartas*listaDeCartaARecorrer);
//Muestra Nodo2 Lista Cartas
void muestraListaCartas(listaDeCartas*listaAMostrar);
//Muestra Nodo de la lista
void muestraNodoCarta(listaDeCartas*nodoAMostrar);

///Arboles de Listas
//Inicializa Arbol
arbolDeListasCartas*inicArbol();
//Crea Nodo Arbol
arbolDeListasCartas*creaNodoArbolCartas(char nuevaInicial);
//Busca Nodo Arbol Por Inicial de Pokemon
arbolDeListasCartas*buscaNodoConInicial(arbolDeListasCartas*arbolEnQueBuscar, char inicialABuscar);
//Agrega Nodo Arbol
arbolDeListasCartas*agregarNodoArbol(arbolDeListasCartas*raizActual_F, arbolDeListasCartas*nuevaRaiz_F);
//Muestra Arbol
void muestraArbolDeCartas(arbolDeListasCartas*arbolAMostrar);
//Muestra Raiz
void muestraRaiz(arbolDeListasCartas*raizAMostrar);
//Carga Arbol Usuario
arbolDeListasCartas*cargaArbolDeListasDeCartasUsuario(arbolDeListasCartas*arbolACargar);
#endif // STCARTA_H_INCLUDED
