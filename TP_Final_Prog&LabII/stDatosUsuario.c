#include "stDatosUsuario.h"

datosUsuario creaUsuario() //inicializa los dato del usuario
{
    datosUsuario nuevoUsuario;
    nuevoUsuario.estado = 1;

    printf("\n Ingrese el Nombre de su Usuario: ");
    fflush(stdin);
    fgets(nuevoUsuario.nombre, DIM3, stdin);
    buscaSaltoLinea(nuevoUsuario.nombre);

    printf("\n Ingrese la Contraseña de su Usuario: ");
    fflush(stdin);
    fgets(nuevoUsuario.contra, DIM3, stdin);
    buscaSaltoLinea(nuevoUsuario.contra);

    nuevoUsuario.validosDatosBuzon = 0;
    nuevoUsuario.validosDatosColeccion = 0;
    nuevoUsuario.validosDatosMazo = 0;
    nuevoUsuario.validosDatosMazoIntercambio = 0;

    return nuevoUsuario;
}

datosUsuario guardaIndicadorMazo(datosUsuario datosMazoACambiar, stCarta cartaAAgregar) // guarda datos de 1 carta en el indicador de un usuario
{
    datosMazoACambiar.datosMazo[datosMazoACambiar.validosDatosMazo].idCartaEnMazo = cartaAAgregar.id;
    datosMazoACambiar.datosMazo[datosMazoACambiar.validosDatosMazo].cantCartaEnMazo = cartaAAgregar.cant;

    datosMazoACambiar.validosDatosMazo++;

    return datosMazoACambiar;
}

datosUsuario guardaIndicadorColeccion(datosUsuario datosColeccionACambiar, stCarta cartaAAgregar) // guarda datos de las cartas en coleccion
{
    datosColeccionACambiar.datosColeccion[datosColeccionACambiar.validosDatosColeccion].idCartaEnColeccion = cartaAAgregar.id;
    datosColeccionACambiar.datosColeccion[datosColeccionACambiar.validosDatosColeccion].cantCartaEnColeccion = cartaAAgregar.cant;

    datosColeccionACambiar.validosDatosColeccion++;

    return datosColeccionACambiar;
}

datosUsuario guardaIndicadorMazoIntercambio(datosUsuario datosMazoIntercambioACambiar, stCarta cartaAAgregar) // guarda datos del mazo de intercambio
{
    datosMazoIntercambioACambiar.datosMazoIntercambio[datosMazoIntercambioACambiar.validosDatosMazoIntercambio].idCartaEnMazoIntercambio = cartaAAgregar.id;
    datosMazoIntercambioACambiar.datosMazoIntercambio[datosMazoIntercambioACambiar.validosDatosMazoIntercambio].cantCartaEnMazoIntercambio = cartaAAgregar.cant;

    datosMazoIntercambioACambiar.validosDatosMazoIntercambio++;

    return datosMazoIntercambioACambiar;
}

datosUsuario eliminaUsuario(datosUsuario usuarioAEliminar) // "elimina" un usuario
{
    usuarioAEliminar.estado=0;
    return usuarioAEliminar;
}

datosUsuario guardaIndicadorBuzon(datosUsuario usuarioANotificar, int idOfer, int idDeman, indicadorMazoIntercambio oferta_F, indicadorMazoIntercambio demanda_F, int resultado_F) // guarda datos de la notificacion
{
    usuarioANotificar.datosBuzon[usuarioANotificar.validosDatosBuzon].idOfertario = idOfer;
    usuarioANotificar.datosBuzon[usuarioANotificar.validosDatosBuzon].idDemandante = idDeman;
    usuarioANotificar.datosBuzon[usuarioANotificar.validosDatosBuzon].oferta = oferta_F;
    usuarioANotificar.datosBuzon[usuarioANotificar.validosDatosBuzon].demanda = demanda_F;
    usuarioANotificar.datosBuzon[usuarioANotificar.validosDatosBuzon].resultado = resultado_F;

    usuarioANotificar.validosDatosBuzon++;
    return usuarioANotificar;
}


