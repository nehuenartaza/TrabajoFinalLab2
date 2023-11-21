#ifndef STUSUARIO_H_INCLUDED
#define STUSUARIO_H_INCLUDED

#include "stMazo.h"
#include "stBuzon.h"

typedef struct
{
    datosUsuario dato;

    stMazo * mazo;
    stListaD * coleccion;
    stBuzon buzon;

} stUsuario;

stUsuario cargaDatosUsuario(datosUsuario);
datosUsuario guardaDatosUsuario(stUsuario);

#endif // STUSUARIO_H_INCLUDED
