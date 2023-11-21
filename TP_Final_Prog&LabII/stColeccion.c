#include "stColeccion.h"
int contarCartasListaDoble(stListaD * lista)
{
    int cantidad = 0;
    if( lista != NULL )
    {
        cantidad = 1;
        cantidad = cantidad + contarCartasListaDoble(lista->sigNodo);
    }
    return cantidad;
}

stListaD * romperEnlaces(stListaD * nodo)   ///setea sigNodo y antNodo en NULL
{
    nodo->antNodo = setNULL();
    nodo->sigNodo = setNULL();
    return nodo;
}

stListaD * agregarInicioColeccion(stListaD * listaColeccion, stListaD * nuevaCarta) ///agrega al inicio de la colección
{
    nuevaCarta->sigNodo = listaColeccion;
    if ( listaColeccion != NULL )
    {
        listaColeccion->antNodo = nuevaCarta;
    }
    return nuevaCarta;
}

stListaD * agregarFinalColeccion(stListaD * listaColeccion, stListaD * nueva)    ///agrega al final de la colección
{
    stListaD * finalColeccion = retornarUltimaCarta(listaColeccion);
    if ( finalColeccion == NULL )
    {
        listaColeccion = nueva;
    }
    else
    {
        finalColeccion->sigNodo = nueva;
        nueva->antNodo = finalColeccion;
    }
    return listaColeccion;
}

stListaD * agregarPorIDColeccion(stListaD * coleccion, stListaD * nuevo)
{
    if ( coleccion != NULL )
    {
        if ( nuevo->dataColecc.id < coleccion->dataColecc.id )
        {
            nuevo->sigNodo = coleccion;
            coleccion->antNodo = nuevo;
            coleccion = coleccion->antNodo;
        }
        else
        {
            stListaD * aux = coleccion;
            stListaD * seg = coleccion->sigNodo;
            while ( seg != NULL && nuevo->dataColecc.id > seg->dataColecc.id )
            {

                aux = seg;
                seg = seg->sigNodo;
            }
            aux->sigNodo = nuevo;
            nuevo->antNodo = aux;
            if(seg != NULL)
            {
                nuevo->sigNodo = seg;
                seg->antNodo = nuevo;
            }
        }
    }
    else
    {
        coleccion = nuevo;
    }
    return coleccion;
}

stListaD * retornarUltimaCarta(stListaD * lista)    ///devuelve la última carta de la colección
{
    if ( lista != NULL )
    {
        while ( lista->sigNodo != NULL )
        {
            lista = lista->sigNodo;
        }
    }
    return lista;
}

void mostrarListaDoble(stListaD * lista)
{
    while ( lista != NULL )
    {
        muestraCarta(lista->dataColecc);
        lista = lista->sigNodo;
    }
}

void buscarCartasPorStringAproximado(stListaD * lista, char str[])
{
    while ( lista != NULL )
    {
        if ( strstr(lista->dataColecc.nombre, str) != NULL )
        {
            muestraCarta(lista->dataColecc);
        }
        lista = lista->sigNodo;
    }
}

stListaD * eliminarYRetirarCartaDeColeccion(stListaD * lista, stCarta * retirar)  ///busca una coincidencia, copia los datos y decrementa la cantidad en 1, si llega a 0
{
    if ( lista != NULL )
    {
        stListaD * seg = lista;
        while ( seg != NULL && !IDsCartasCoinciden(seg->dataColecc, *retirar) )
        {
            seg = seg->sigNodo;
        }
        if ( seg != NULL )
        {
            if ( ( seg->dataColecc.cant - 1 ) == 0 )    ///solo hay una copia de la carta encontrada,
            {
                lista = borrarNodoDeColeccion(lista, retirar);
            }
            else
            {
                *retirar = seg->dataColecc;
                seg->dataColecc.cant--;
            }
        }
    }
    return lista;
}

bool IDsCartasCoinciden(stCarta arg1, stCarta arg2)
{
    bool coincidencia = false;
    if ( arg1.id == arg2.id )
    {
        coincidencia = true;
    }
    return coincidencia;
}

stListaD * borrarNodoDeColeccion(stListaD * lista, stCarta * borrar)  ///Borra un nodo/carta en la colección
{
    if ( lista != NULL )
    {
        if ( lista->dataColecc.id == (*borrar).id )
        {
            *borrar = lista->dataColecc;
            stListaD * aux = lista;
            lista = lista->sigNodo;
            free(aux);
        }
        else
        {
            stListaD * seg = lista;
            while ( seg != NULL && seg->dataColecc.id != (*borrar).id )
            {
                seg = seg->sigNodo;
            }
            if ( seg != NULL )
            {
                *borrar = seg->dataColecc;
                if ( seg->sigNodo == NULL )
                {
                    seg = seg->antNodo;
                    free(seg->sigNodo);
                    seg->sigNodo = setNULL();
                }
                else
                {
                    stListaD * temp = seg;
                    temp = temp->sigNodo;
                    temp->antNodo = setNULL();
                    temp->antNodo = seg->antNodo;
                    temp = temp->antNodo;
                    temp->sigNodo = setNULL();
                    temp->sigNodo = seg->sigNodo;
                    free(seg);
                }
            }
        }
    }
    return lista;
}

void buscarCartasPorRareza(stListaD * lista, char rareza[])
{
    while ( lista != NULL )
    {
        if ( rarezasCartasCoinciden(lista->dataColecc.rareza, rareza) )
        {
            muestraCarta(lista->dataColecc);
        }
        lista = lista->sigNodo;
    }
}

bool rarezasCartasCoinciden(char arg1[], char arg2[])
{
    bool coincidencia = false;
    if ( strcmp(arg1, arg2) == 0 )
    {
        coincidencia = true;
    }
    return coincidencia;
}

void buscarCartaPorID(stListaD * lista, int id)
{
    while ( lista != NULL )
    {
        if ( lista->dataColecc.id == id )
        {
            muestraCarta(lista->dataColecc);
            break;
        }
        lista = lista->sigNodo;
    }
}

bool verificaSiListaDobleEstaVacia(stListaD * listaD)  // Retorna false si esta vacia, o true si tiene algun nodo cargado
{
    bool rta = false;
    if(listaD != NULL)
        rta = true;

    return rta;
}

///Necesarias para Intercambio
stCarta buscarCartaPorIDYLaRetorna(stListaD * lista, int id)
{
    stCarta cartaBuscada;
    while ( lista != NULL )
    {
        if ( lista->dataColecc.id == id )
        {
            cartaBuscada = lista->dataColecc;
        }
        lista = lista->sigNodo;
    }
    return cartaBuscada;
}

stListaD * creaNodoColeccion(stCarta cartaAGuardar)
{
    stListaD * nuevoNodoColeccion = (stListaD*) malloc(sizeof(stListaD));

    nuevoNodoColeccion->dataColecc = cartaAGuardar;
    nuevoNodoColeccion->sigNodo = setNULL();
    nuevoNodoColeccion->antNodo = setNULL();

    return nuevoNodoColeccion;
}

stListaD * buscaNodoEnColeccionPorId(stListaD * coleccionARevisar, stCarta cartaABuscar)
{
    stListaD * nodoBuscado = setNULL();
    stListaD * auxiliar = coleccionARevisar;

    while(auxiliar != NULL && auxiliar->dataColecc.id != cartaABuscar.id)
        auxiliar = auxiliar->sigNodo;

    if(auxiliar->dataColecc.id == cartaABuscar.id)
        nodoBuscado = auxiliar;

    return nodoBuscado;
}

stListaD * altaCartaEnColeccion(stListaD * coleccionACargar, stCarta cartaACargar)
{
    stListaD * auxiliar = buscaNodoEnColeccionPorId(coleccionACargar, cartaACargar);
    if(auxiliar == NULL)
    {
        auxiliar = creaNodoColeccion(cartaACargar);
        auxiliar->dataColecc.cant = 0;
        coleccionACargar = agregarPorIDColeccion(coleccionACargar, auxiliar);
    }
    auxiliar->dataColecc.cant += 1;
    return coleccionACargar;
}

datosUsuario cargaIndicadoresDeColeccion(stListaD * coleccionAGuardar, datosUsuario usuarioAEditar)
{
    usuarioAEditar.validosDatosColeccion = 0;

    while(coleccionAGuardar !=NULL)
    {
        guardaIndicadorColeccion(usuarioAEditar, coleccionAGuardar->dataColecc);
        coleccionAGuardar = coleccionAGuardar->sigNodo;
    }
    return usuarioAEditar;
}
