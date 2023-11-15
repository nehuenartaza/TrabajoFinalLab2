#ifndef STNOTIFICACIONES_H_INCLUDED
#define STNOTIFICACIONES_H_INCLUDED

#include "stDatosUsuario.h"

typedef struct
{
    int idOfertario;
    stListaD mazoIntercambioOferta;

    int idDemandante;
    stListaD mazoIntercambioDemandante;
} stNotificacion;

#endif // STNOTIFICACIONES_H_INCLUDED
