#ifndef STDATOSUSUARIO_H_INCLUDED
#define STDATOSUSUARIO_H_INCLUDED

#include "constantes.h"

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
} indicadorBuzon;

typedef struct
{
    int id;
    int estado;
    char nombre[DIM3];
    char contra[DIM3];
    indicadorMazo datosMazo[MAXMAZO];
    indicadorBuzon datosBuzon[DIM3];
    indicadorColeccion datosColeccion[MAXCOLECCION];
    indicadorMazoIntercambio datosMazoIntercambio[MAXCOLECCION];
} datosUsuario;

#endif // STDATOSUSUARIO_H_INCLUDED
