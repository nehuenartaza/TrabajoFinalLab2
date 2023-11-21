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
    stNotificacion * ultimo;
} stBuzon;

///Muestra
void muestraMazoIntercambio(stListaD * mazoIntercambioAMostrar); //Muestra Cartas de la coleccion que se pueden intercambiar ///
void muestraCartaAIntercambiar(stCarta cartaInterAMostrar); //Muestra datos de la carta que se intercambio
void muestraNotificacion(stNotificacion*); //Muestra la Notificacion
void muestraTodasNotificaciones(stNotificacion*); //Muestra la Notificacion
void muestraBuzon(stBuzon*); //Muestra Buzon Entero

///Logica
datosUsuario guardaBuzon(stNotificacion * buzonAGuardar , datosUsuario datosBuzonAGuardar);
void inicStBuzon(stBuzon * buzonAInicializar);
stNotificacion * creaNodoNotificacion(indicadorBuzon informacion);
stNotificacion * intercambio(stListaD ** coleccionDemanda , stListaD ** ColeccionOferta , indicadorBuzon datosDeIntercambio); //Intercambia 2 cartas en colecciones distintas
void agregarAlFinalBuzon(stBuzon * buzonACargar , stNotificacion * notificacionAGuardar);
void eliminaPrimeroDeBuzon(stBuzon * buzonAElimnar);
stNotificacion * extraerNotificacionDeBuzon(stBuzon * buzonAExtraer);
datosUsuario guardaIndicadoresDeBuzon(stBuzon * buzonAGuardar);

#endif // STBUZON_H_INCLUDED
