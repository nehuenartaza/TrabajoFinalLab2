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

stListaD * agregarInicioColeccion(stListaD * listaColeccion, stListaD * nuevaCarta) ///agrega al inicio de la colecci�n
{
    nuevaCarta->sigNodo = listaColeccion;
    if ( listaColeccion != NULL )
    {
        listaColeccion->antNodo = nuevaCarta;
    }
    return nuevaCarta;
}

stListaD * agregarFinalColeccion(stListaD * listaColeccion, stListaD * nueva)    ///agrega al final de la colecci�n
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
        if ( nuevo->dataColecc.id == coleccion->dataColecc.id )     //Si se encontr� repetida se suma 1 a la cantidad
        {
            coleccion->dataColecc.cant++;
        }
        else if ( nuevo->dataColecc.id < coleccion->dataColecc.id )
        {
            nuevo->sigNodo = coleccion;
            coleccion->antNodo = nuevo;
            coleccion = coleccion->antNodo;
        }
        else
        {
            stListaD * aux = coleccion;
            stListaD * seg = coleccion->sigNodo;
            while ( seg != NULL && ( nuevo->dataColecc.id > seg->dataColecc.id || nuevo->dataColecc.id != seg->dataColecc.id ) )
            {
                aux = seg;
                seg = seg->sigNodo;
            }
            if(seg != NULL)
            {
                if ( nuevo->dataColecc.id == seg->dataColecc.id )     //si se repite se le suma 1, caso contrario hace los enlaces
                {
                    seg->dataColecc.cant++;
                }
                else
                {
                    nuevo->sigNodo = seg;
                    seg->antNodo = nuevo;
                    aux->sigNodo = nuevo;
                    nuevo->antNodo = aux;
                }
            }
            else
            {
                aux->sigNodo = nuevo;
                nuevo->antNodo = aux;
            }
        }
    }
    else
    {
        coleccion = nuevo;
    }
    return coleccion;
}


stListaD * retornarUltimaCarta(stListaD * lista)    ///devuelve la �ltima carta de la colecci�n
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

void mostrarCartasPorStringAproximado(stListaD * lista, char str[])
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

stListaD * borrarNodoDeColeccion(stListaD * lista, stCarta * borrar)  ///Borra un nodo/carta en la colecci�n
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

void mostrarCartasPorRareza(stListaD * lista, char rareza[])
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
    if ( strcmpi(arg1, arg2) == 0 )
    {
        coincidencia = true;
    }
    return coincidencia;
}

void mostrarCartaPorID(stListaD * lista, int id)
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

stListaD * buscarYRetornarNodoCartaPorID(stListaD * lista, int id)
{
    stListaD * aux = setNULL();
    while ( lista != NULL )
    {
        if ( lista->dataColecc.id == id )
        {
            aux = lista;
            break;
        }
        lista = lista->sigNodo;
    }
    return aux;
}

bool verificaSiListaDobleEstaVacia(stListaD * listaD)  // Retorna false si esta vacia, o true si tiene algun nodo cargado
{
    bool rta = false;
    if(listaD != NULL)
        rta = true;

    return rta;
}

void mostrarCartasPorClasePokemon(stListaD * coleccion)
{
    while ( coleccion != NULL )
    {
        if ( coleccion->dataColecc.claseCarta.datosPokemon.estado == 1 )
        {
            muestraCarta(coleccion->dataColecc);
        }
        coleccion = coleccion->sigNodo;
    }
}

void mostrarCartasPorClaseEnergia(stListaD * coleccion)
{
    while ( coleccion != NULL )
    {
        if ( coleccion->dataColecc.claseCarta.datosEnergia.estado == 1 )
        {
            muestraCarta(coleccion->dataColecc);
        }
        coleccion = coleccion->sigNodo;
    }
}

void mostrarCartasPorClaseEntrenador(stListaD * coleccion)
{
    while ( coleccion != NULL )
    {
        if ( coleccion->dataColecc.claseCarta.datosEntrenador.estado == 1 )
        {
            muestraCarta(coleccion->dataColecc);
        }
        coleccion = coleccion->sigNodo;
    }
}

void mostrarCartasPorExpansion(stListaD * coleccion, char expan[])
{
    while ( coleccion != NULL )
    {
        if ( strstr(coleccion->dataColecc.expansionCarta.expansionTitulo, expan) != NULL )
        {
            muestraCarta(coleccion->dataColecc);
        }
        coleccion = coleccion->sigNodo;
    }
}

void mostrarCartasPorExpansionAuxiliar(stListaD * coleccion, char expan[])   ///muestra las cartas de la colecci�n por subt�tulo de la expansi�n
{
    while ( coleccion != NULL )
    {
        if ( strstr(coleccion->dataColecc.expansionCarta.expansionSubTit, expan) != NULL )
        {
            muestraCarta(coleccion->dataColecc);
        }
        coleccion = coleccion->sigNodo;
    }
}

///Necesarias para Intercambio
stCarta buscarCartaPorIDYLaRetorna(stListaD * lista, int id)
{
    stCarta cartaBuscada;

    cartaBuscada.id=-1;
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
    {

        auxiliar = auxiliar->sigNodo;

    }
    if(auxiliar!=NULL)
    {
        if(auxiliar->dataColecc.id == cartaABuscar.id)
        {
            nodoBuscado = auxiliar;
        }


    }

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

datosUsuario guardaIndicadoresDeColeccion(stListaD * coleccionAGuardar, datosUsuario usuarioAEditar)
{
    usuarioAEditar.validosDatosColeccion = 0;

    while(coleccionAGuardar !=NULL)
    {
        usuarioAEditar = guardaIndicadorColeccion(usuarioAEditar, coleccionAGuardar->dataColecc);
        coleccionAGuardar = coleccionAGuardar->sigNodo;
    }
    return usuarioAEditar;
}

int contadorCartasTotalesEnColeccion(stListaD * coleccion)
{
    int cont = 0;

    while(coleccion != NULL)
    {
        cont = cont + coleccion->dataColecc.cant;
        coleccion = coleccion->sigNodo;
    }

    return cont;
}

int contadorCartasPokemonEnColeccion(stListaD * coleccion)
{
    int cont = 0;

    while(coleccion != NULL)
    {
        if(coleccion->dataColecc.claseCarta.datosPokemon.estado == 1)
            cont = cont + coleccion->dataColecc.cant;
        coleccion = coleccion->sigNodo;
    }

    return cont;
}

int contadorCartasEntrenadorEnColeccion(stListaD * coleccion)
{
    int cont = 0;

    while(coleccion != NULL)
    {
        if(coleccion->dataColecc.claseCarta.datosEntrenador.estado == 1)
            cont = cont + coleccion->dataColecc.cant;
        coleccion = coleccion->sigNodo;
    }

    return cont;
}

int contadorCartasEnergiaEnColeccion(stListaD * coleccion)
{
    int cont = 0;

    while(coleccion != NULL)
    {
        if(coleccion->dataColecc.claseCarta.datosEnergia.estado == 1)
            cont = cont + coleccion->dataColecc.cant;
        coleccion = coleccion->sigNodo;
    }

    return cont;
}

