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

datosOferta creaOferta(datosUsuario ofertante , stCarta cartaOfrecida)
{
    datosOferta nuevaOferta;

    nuevaOferta.idOfertario = ofertante.id;
    nuevaOferta.oferta = cartaOfrecida;
    strcpy(nuevaOferta.nombreOfertario , ofertante.nombre);

    return nuevaOferta;
}

datosDemanda creaDemanda(datosUsuario demandante , stCarta cartaDemandada)
{
    datosDemanda nuevaDemanda;

    nuevaDemanda.demanda = cartaDemandada;
    nuevaDemanda.idDemandante = demandante.id;
    strcpy(nuevaDemanda.nombreDemandante , demandante.nombre);

    return nuevaDemanda;
}

datosUsuario guardaIndicadorBuzon(datosUsuario datosBuzonACambiar , datosUsuario ofertante , datosUsuario demandante , stCarta cartaOfrecida , stCarta cartaDemandada) // guarda datos del intercambio en buzon
{
    datosBuzonACambiar.datosBuzon[datosBuzonACambiar.validosDatosBuzon].oferta = creaOferta(ofertante , cartaOfrecida);
    datosBuzonACambiar.datosBuzon[datosBuzonACambiar.validosDatosBuzon].demanda = creaDemanda(demandante , cartaDemandada);
    datosBuzonACambiar.validosDatosBuzon++;

    return datosBuzonACambiar;
}

datosUsuario eliminaUsuario(datosUsuario usuarioAEliminar) // "elimina" un usuario
{
    usuarioAEliminar.estado=0;
    return usuarioAEliminar;
}

datosUsuario vaciarDatosUsuario()
{
    datosUsuario usuario;
    usuario.id = 0;
    usuario.estado = 0;
    strcpy(usuario.nombre, "error");
    strcpy(usuario.contra, "error");
    usuario.validosDatosMazo = 0;
    usuario.validosDatosBuzon = 0;
    usuario.validosDatosColeccion = 0;

    return usuario;
}

void muestraIndicadoresColeccion(datosUsuario usuarioAMostrar)
{
    for(int i; i<usuarioAMostrar.validosDatosColeccion ; i++)
    {
        printf("\n %d Id Carta ---- %d Cant Canta");
    }
}
