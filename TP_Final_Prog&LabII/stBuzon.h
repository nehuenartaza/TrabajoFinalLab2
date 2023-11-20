#ifndef STBUZON_H_INCLUDED
#define STBUZON_H_INCLUDED

#include "stColeccion.h"
#include "stDatosUsuario.h"

typedef struct
{
    indicadorBuzon datos;

    struct stNotificacion * siguiente;
} stNotificacion;

typedef struct
{
    stNotificacion * primero;
    stNotificacion * segundo;
} stBuzon;

///Muestra
void muestraMazoIntercambio(stListaD * mazoIntercambioAMostrar); //Muestra Cartas de la coleccion que se pueden intercambiar ///
void muestraCartaAIntercambiar(stCarta cartaInterAMostrar); //Muestra datos de la carta que se intercambio
void muestraNotificacion(stNotificacion*); //Muestra la Notificacion
void muestraTodasNotificaciones(stNotificacion*); //Muestra la Notificacion
void muestraBuzon(stBuzon*); //Muestra Buzon Entero

///Logica
stNotificacion * intercambio(stListaD** , stListaD** , indicadorBuzon datosDeIntercambio); //Intercambia 2 cartas en colecciones distintas

#endif // STBUZON_H_INCLUDED
