#include "stBuzon.h"

///Muestra
void muestraMazoIntercambio(stListaD * mazoIntercambioAMostrar) //Muestra Cartas de la coleccion que se pueden intercambiar
{
    if(mazoIntercambioAMostrar == NULL)
        printf("\n No hay cartas para intercambiar. ");
    else
    {
        stListaD * auxiliar = mazoIntercambioAMostrar;
        while (auxiliar != NULL)
        {
            muestraCarta(auxiliar->dataColecc);
            auxiliar = auxiliar->sigNodo;
        }
    }
}

void muestraCartaAIntercambiar(stCarta cartaInterAMostrar)
{
    printf("\n Id...............: %d", cartaInterAMostrar.id);
    printf("\n Nombre...........: %s", cartaInterAMostrar.nombre);
    printf("\n Rareza...........: %s", cartaInterAMostrar.rareza);
    muestraClase(cartaInterAMostrar.claseCarta);
    muestraExpansion(cartaInterAMostrar.expansionCarta);
}

void muestraNotificacion(stNotificacion * notificacionAMostrar)
{
    printf("\n Id Demandante....: %d", notificacionAMostrar->datos.demanda.idDemandante);
    printf("\n Nombre Demandante: %s", notificacionAMostrar->datos.demanda.nombreDemandante);
    muestraCarta(notificacionAMostrar->datos.demanda.demanda);
    printf("\n Id Ofertario.....: %d", notificacionAMostrar->datos.oferta.idOfertario);
    printf("\n Nombre Ofertario.: %s", notificacionAMostrar->datos.oferta.nombreOfertario);
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
    if(buzonAMostrar->primero != NULL)
    {
        stNotificacion * notificacionExtraida;
        printf("\n ---------- BUZON ---------- ");
        while(buzonAMostrar->primero != NULL)
        {
            notificacionExtraida = extraerNotificacionDeBuzon(buzonAMostrar);
            muestraNotificacion(notificacionExtraida);
            system("pause");
            system("cls");
        }
        printf("\n ---------- BUZON VACIO ---------- ");
    }
    else
        printf("\n ---------- BUZON VACIO ---------- ");
}

///Logica
void inicStBuzon(stBuzon * buzonAInicializar)
{
    buzonAInicializar->primero = setNULL();
    buzonAInicializar->ultimo = setNULL();
}

stNotificacion * creaNodoNotificacion(indicadorBuzon informacion)
{
    stNotificacion * nuevaNotifi = (stNotificacion*) malloc(sizeof(stNotificacion));

    nuevaNotifi->siguiente = setNULL();
    nuevaNotifi->datos = informacion;

    return nuevaNotifi;
}

stNotificacion * intercambio(stListaD ** coleccionDemanda, stListaD ** ColeccionOferta, indicadorBuzon datosDeIntercambio)   //Intercambia 2 cartas en colecciones distintas
{
    stNotificacion * nuevaNotificacion = creaNodoNotificacion(datosDeIntercambio);

    (*coleccionDemanda) = altaCartaEnColeccion((*coleccionDemanda), datosDeIntercambio.oferta.oferta);
    (*coleccionDemanda) = eliminarYRetirarCartaDeColeccion((*coleccionDemanda), &datosDeIntercambio.demanda.demanda);

    (*ColeccionOferta) = altaCartaEnColeccion((*ColeccionOferta), datosDeIntercambio.demanda.demanda);
    (*ColeccionOferta) = eliminarYRetirarCartaDeColeccion((*ColeccionOferta), &datosDeIntercambio.oferta.oferta);

    return nuevaNotificacion;
}

void agregarAlFinalBuzon(stBuzon * buzonACargar, stNotificacion * notificacionAGuardar)
{
    if(buzonACargar->primero == NULL)
    {
        buzonACargar->primero = notificacionAGuardar;
        buzonACargar->ultimo = notificacionAGuardar;
    }
    else
    {
        buzonACargar->ultimo->siguiente = notificacionAGuardar;
        buzonACargar->ultimo = notificacionAGuardar;
    }
}

void eliminaPrimeroDeBuzon(stBuzon * buzonAElimnar)
{
    if(buzonAElimnar->primero != NULL)
    {
        stNotificacion * auxiliar = buzonAElimnar->primero;
        buzonAElimnar->primero = buzonAElimnar->primero->siguiente;
        free(auxiliar);

        if(buzonAElimnar->primero == NULL)
            inicStBuzon(buzonAElimnar);
    }
}

datosUsuario guardaBuzon(stNotificacion * buzonAGuardar, datosUsuario datosBuzonAGuardar)
{
    datosBuzonAGuardar.datosBuzon[datosBuzonAGuardar.validosDatosBuzon].demanda = buzonAGuardar->datos.demanda;
    datosBuzonAGuardar.datosBuzon[datosBuzonAGuardar.validosDatosBuzon].oferta = buzonAGuardar->datos.oferta;
    datosBuzonAGuardar.validosDatosBuzon++;

    return datosBuzonAGuardar;
}

stNotificacion * extraerNotificacionDeBuzon(stBuzon * buzonAExtraer)
{
    stNotificacion * notificacionExtraida = setNULL();
    if(buzonAExtraer->primero != NULL)
    {
        notificacionExtraida = buzonAExtraer->primero;
        eliminaPrimeroDeBuzon(buzonAExtraer);
    }
    return notificacionExtraida;
}

datosUsuario guardaIndicadoresDeBuzon(stBuzon * buzonAGuardar)
{
    datosUsuario infoAGuardar;
    stNotificacion * auxiliar = buzonAGuardar->primero;
    while(auxiliar != NULL)
    {
        infoAGuardar = guardaBuzon(auxiliar, infoAGuardar);
        auxiliar = auxiliar->siguiente;
    }
    return infoAGuardar;
}
