#include "stUsuario.h"

stUsuario cargaDatosUsuario(datosUsuario usuarioACargar)
{
    stUsuario usuarioCargado;

    usuarioCargado.dato = usuarioACargar;
    usuarioCargado.coleccion = cargaColeccionPorParametro(usuarioACargar);
    //usuarioCargado.mazo = cargaMazoPorParametro(usuarioACargar); //////JULI
    cargaBuzonPorParametro(usuarioACargar , &usuarioCargado.buzon);

    return usuarioCargado;
}

datosUsuario guardaDatosUsuario(stUsuario usuarioAGuardar)
{
    datosUsuario usuarioGuardado;

    usuarioGuardado = guardaIndicadoresDeColeccion(usuarioAGuardar.coleccion , usuarioGuardado);
    usuarioGuardado = guardaIndicadoresDeBuzon(&usuarioAGuardar.buzon);
    //usuarioGuardado = guardaIndicadoresDeMazo(); //////JULI
    return usuarioGuardado;
}
