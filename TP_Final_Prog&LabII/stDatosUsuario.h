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
    int idOfertario;
    char nombreOfertario[DIM3];
    stCarta oferta;
}datosOferta;

typedef struct
{
    int idDemandante;
    char nombreDemandante[DIM3];
    stCarta demanda;
}datosDemanda;

typedef struct
{
    datosOferta oferta;
    datosDemanda demanda;
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

} datosUsuario;

//Carga
datosUsuario creaUsuario(); //inicializa los dato del usuario
datosOferta creaOferta(datosUsuario ofertante , stCarta cartaOfrecida);
datosDemanda creaDemanda(datosUsuario demandante , stCarta cartaDemandada);
//Guarda
datosUsuario guardaIndicadorMazo(datosUsuario, stCarta); // guarda datos de 1 carta en el indicador de un usuario
datosUsuario guardaIndicadorColeccion(datosUsuario, stCarta); // guarda datos de las cartas en coleccion
datosUsuario guardaIndicadorBuzon(datosUsuario , datosUsuario , datosUsuario , stCarta , stCarta); // guarda datos del intercambio en buzon
//Maneja
datosUsuario eliminaUsuario(datosUsuario usuarioAEliminar); // "elimina" un usuario
datosUsuario vaciarDatosUsuario();
//Muetra
void muestraIndicadoresColeccion(datosUsuario usuarioAMostrar);
void muestraIndicadoresBuzon(datosUsuario usuarioAMostrar);

#endif // STDATOSUSUARIO_H_INCLUDED
