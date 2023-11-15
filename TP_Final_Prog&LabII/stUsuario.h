#ifndef STUSUARIO_H_INCLUDED
#define STUSUARIO_H_INCLUDED

#include "stMazo.h"
#include "stNotificaciones.h"

typedef struct
{
    datosUsuario dato;

    stMazo mazo;
    stListaD coleccion;
    stListaD mazoIntercambio;
    stNotificacion buzon;
} stUsuario;

#endif // STUSUARIO_H_INCLUDED
