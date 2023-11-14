#ifndef STMAZO_H_INCLUDED
#define STMAZO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "stCarta.h"
#include "stColeccion.h"
///Estructura

//LA LISTA SIMPLE DEL MAZO
typedef struct{
 stCarta dato;
 struct mazoSimple*siguiente;
}mazoSimple;

//EL MAZO
typedef struct
{
  mazoSimple*Tope;
}stMazo;

//FUNCIONES DE LA LISTA SIMPLE DEL MAZO
mazoSimple*AgregarAlprincipio(mazoSimple*,mazoSimple*);
mazoSimple*CrearNodo(stCarta);
stCarta BorrarPrimero(mazoSimple**);

//FUNCIONES PARA EL MAZO
void apilarMazo(stMazo*,stCarta);
stCarta DesapilarMazo(stMazo*);
stCarta MostrarTope(stMazo*);
int MazoVacio(stMazo*);
void MostrarMazo(stMazo);
void CargarMazoAleatoriamente(stMazo*Pila,stListaD**ListaDoble);
void BorrarNodoYMeterEnMazoNodoElegidoConContador(stListaD**Lista,stMazo*Pila,int numeroDePosicion,int contador);





///Prototipado



#endif // STMAZO_H_INCLUDED
