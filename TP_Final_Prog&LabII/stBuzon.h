#ifndef STBUZON_H_INCLUDED
#define STBUZON_H_INCLUDED

#include "stColeccion.h"
#include "stDatosUsuario.h"

typedef struct
{
    int idOfertario;
    stListaD * mazoIntercambioOferta;

    int idDemandante;
    stListaD * mazoIntercambioDemandante;

    struct stNotificacion * siguiente;
} stNotificacion;

typedef struct
{
    stNotificacion * primero;
    stNotificacion * segundo;
} stBuzon;

///Muestra
void muestraDatosIntercambio(datosUsuario); //Muestra datos importantes para el intercabio
void muestraNotificacion(stNotificacion*); //Muestra la Notificacion
void muestraTodasNotificaciones(stNotificacion*); //Muestra la Notificacion
void muestraBuzon(stBuzon*); //Muestra Buzon Entero

#endif // STBUZON_H_INCLUDED
