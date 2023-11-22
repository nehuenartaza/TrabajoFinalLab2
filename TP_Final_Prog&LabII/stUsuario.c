#include "stUsuario.h"

stUsuario cargaDatosUsuario(datosUsuario usuarioACargar)
{
    stUsuario usuarioCargado;

    usuarioCargado.dato = usuarioACargar;
    usuarioCargado.coleccion = cargaColeccionPorParametro(usuarioACargar);
    cargaMazoPorParametro(usuarioCargado.mazo,usuarioACargar);
    cargaBuzonPorParametro(usuarioACargar , &usuarioCargado.buzon);

    return usuarioCargado;
}

datosUsuario guardaDatosUsuario(stUsuario usuarioAGuardar)
{
    datosUsuario usuarioGuardado;

    usuarioGuardado = guardaIndicadoresDeColeccion(usuarioAGuardar.coleccion , usuarioGuardado);
    usuarioGuardado = guardaIndicadoresDeBuzon(&usuarioAGuardar.buzon);
    usuarioGuardado = guardaIndicadoresdeMazo(usuarioAGuardar.mazo,usuarioGuardado);

    return usuarioGuardado;
}
