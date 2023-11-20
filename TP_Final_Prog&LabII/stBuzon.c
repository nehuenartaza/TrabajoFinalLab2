#include "stBuzon.h"

///Muestra
void muestraMazoIntercambio(stListaD * mazoIntercambioAMostrar) //Muestra Cartas de la coleccion que se pueden intercambiar
{
    stListaD * auxiliar = mazoIntercambioAMostrar;
    while (auxiliar =! NULL)
    {
        if(auxiliar->dataColecc.cant >= 2)
            muestraCarta(auxiliar->dataColecc);
    }
}

void muestraCartaAIntercambiar(stCarta cartaInterAMostrar)
{
    printf("\n Id............: %d", cartaInterAMostrar.id);
    printf("\n Nombre........: %s", cartaInterAMostrar.nombre);
    printf("\n Rareza........: %s", cartaInterAMostrar.rareza);
    muestraClase(cartaInterAMostrar.claseCarta);
    muestraExpansion(cartaInterAMostrar.expansionCarta);
}

void muestraNotificacion(stNotificacion * notificacionAMostrar)
{
    printf("\n Id Demandante: %d", notificacionAMostrar->datos.demanda.idDemandante);
    printf("\n Nombre Demandante: %s", notificacionAMostrar->datos.demanda.nombreDemandante);
    muestraCarta(notificacionAMostrar->datos.demanda.demanda);
    printf("\n Id Ofertario: %d", notificacionAMostrar->datos.oferta.idOfertario);
    printf("\n Nombre Ofertario: %s", notificacionAMostrar->datos.oferta.nombreOfertario);
    muestraCarta(notificacionAMostrar->datos.oferta.oferta);
}

void muestraTodasNotificaciones(stNotificacion * notificacionesAMostrar) //Muestra la Notificacion
{
    stNotificacion * auxiliar = notificacionesAMostrar;
    while(auxiliar != NULL)
    {
        muestraNotificacion(auxiliar);
        auxiliar = auxiliar->siguiente;
    }
}

void muestraBuzon(stBuzon * buzonAMostrar) //Muestra Buzon Entero
{
    muestraTodasNotificaciones(buzonAMostrar->primero);
}

///Logica
stNotificacion * creaNodoNotificacion(indicadorBuzon informacion)
{
    stNotificacion * nuevaNotifi = (stNotificacion*) malloc(sizeof(stNotificacion));

    nuevaNotifi->siguiente = setNULL();
    nuevaNotifi->datos = informacion;

    return nuevaNotifi;
}
stListaD * creaNodoColeccion(stCarta cartaAGuardar)
{
    stListaD * nuevoNodoColeccion = (stListaD*) malloc(sizeof(stListaD));

    nuevoNodoColeccion->dataColecc = cartaAGuardar;
    nuevoNodoColeccion->sigNodo = setNULL();
    nuevoNodoColeccion->antNodo = setNULL();

    return nuevoNodoColeccion;
}

stListaD * buscaNodoEnColeccionPorId(stListaD * coleccionARevisar , stCarta cartaABuscar)
{
    stListaD * nodoBuscado = setNULL();
    stListaD * auxiliar = coleccionARevisar;

    while(auxiliar != NULL && auxiliar->dataColecc.id != cartaABuscar.id)
        auxiliar = auxiliar->sigNodo;

    if(auxiliar->dataColecc.id == cartaABuscar.id)
        nodoBuscado = auxiliar;

    return nodoBuscado;
}

stListaD * altaCartaEnColeccion(stListaD * coleccionACargar , stCarta cartaACargar)
{
    stListaD * auxiliar = buscaNodoEnColeccionPorId(coleccionACargar , cartaACargar);
    if(auxiliar == NULL)
    {
        auxiliar = creaNodoColeccion(cartaACargar);
        auxiliar->dataColecc.cant = 0;
        coleccionACargar = agregarPorIDColeccion(coleccionACargar , auxiliar);
    }
    auxiliar->dataColecc.cant += 1;
    return coleccionACargar;
}

stNotificacion * intercambio(stListaD ** coleccionDemanda , stListaD ** ColeccionOferta , indicadorBuzon datosDeIntercambio) //Intercambia 2 cartas en colecciones distintas
{
    stNotificacion * nuevaNotificacion = creaNodoNotificacion(datosDeIntercambio);

    (*coleccionDemanda) = altaCarta((*coleccionDemanda) , datosDeIntercambio.oferta.oferta);
    (*ColeccionOferta) = altaCarta((*ColeccionOferta) , datosDeIntercambio.demanda.demanda);

    return nuevaNotificacion;
}

/* Idea General del realizar un intercambio
void realizarIntercambio()
{
    //Supongo que ya tengo los datos de mi usuarioActual
    //Abro archibo de usuarios
    //Muestro los id nombre y coleccionDeIntercambio de todos
    //doy a elegir id de usuario
    //elijo id de carta a intercambiar de su coleccion
    //elijo id de carta en mi coleccion de intercambio
    // uso funcion intercambio
    // envio lo que retorna al buzon de cada usuario
}
*/
