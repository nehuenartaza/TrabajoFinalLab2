#ifndef STDATOSUSUARIO_H_INCLUDED
#define STDATOSUSUARIO_H_INCLUDED

#include "stCarta.h"

typedef struct
{
    int idCartaEnMazo;
    int cantCartaEnMazo;
} indicadorMazo;

typedef struct
{
    int idCartaEnColeccion;
    int cantCartaEnColeccion;
} indicadorColeccion;

typedef struct
{
    int idCartaEnMazoIntercambio;
    int cantCartaEnMazoIntercambio;
} indicadorMazoIntercambio;

typedef struct
{
    int idOfertario;
    int idDemandante;

    indicadorMazoIntercambio oferta;
    indicadorMazoIntercambio demanda;

    int resultado; // 0 espera 1 realizado
} indicadorBuzon;

typedef struct
{
    int id; //asigna automaticamente
    int estado; // 1 activo 0 inactivo
    char nombre[DIM3]; //nombre
    char contra[DIM3]; //contraseña

    indicadorMazo datosMazo[MAXMAZO]; //arreglo que refiere a cartas en el mazo
    int validosDatosMazo;

    indicadorBuzon datosBuzon[DIM3]; //arreglo que refiere a notificaciones en buzon
    int validosDatosBuzon;

    indicadorColeccion datosColeccion[MAXCOLECCION]; //arreglo que refiere a cartas en coleccion
    int validosDatosColeccion;

    indicadorMazoIntercambio datosMazoIntercambio[MAXCOLECCION]; //arreglo que refiere a cartas disponibles a intercambiar
    int validosDatosMazoIntercambio;

} datosUsuario;

datosUsuario creaUsuario(); //inicializa los dato del usuario
datosUsuario guardaIndicadorMazo(datosUsuario, stCarta); // guarda datos de 1 carta en el indicador de un usuario
datosUsuario guardaIndicadorColeccion(datosUsuario, stCarta); // guarda datos de las cartas en coleccion
datosUsuario guardaIndicadorMazoIntercambio(datosUsuario, stCarta); // guarda datos del mazo de intercambio
datosUsuario eliminaUsuario(datosUsuario); // "elimina" un usuario
datosUsuario guardaIndicadorBuzon(datosUsuario, int, int, indicadorMazoIntercambio, indicadorMazoIntercambio, int); // guarda datos de la notificacion


#endif // STDATOSUSUARIO_H_INCLUDED
