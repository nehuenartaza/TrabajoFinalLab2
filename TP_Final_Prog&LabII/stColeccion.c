#include "stColeccion.h"
int contarCartasListaDoble(stListaD * lista)
{
    int cantidad = 0;
    if( lista != NULL ) {
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
    if ( listaColeccion != NULL ) {
        listaColeccion->antNodo = nuevaCarta;
    }
    return nuevaCarta;
}

stListaD * agregarFinalColeccion(stListaD * listaColeccion, stListaD * nueva)    ///agrega al final de la colecci�n
{
    stListaD * finalColeccion = retornarUltimaCarta(listaColeccion);
    if ( finalColeccion == NULL ) {
         listaColeccion = nueva;
    } else {
            finalColeccion->sigNodo = nueva;
            nueva->antNodo = finalColeccion;
        }
    return listaColeccion;
}

stListaD * agregarPorIDColeccion(stListaD * coleccion, stListaD * nuevo)
{
    if ( coleccion != NULL ) {
        if ( nuevo->dataColecc.id < coleccion->dataColecc.id ) {
            nuevo->sigNodo = coleccion;
            coleccion->antNodo = nuevo;
            coleccion = coleccion->antNodo;
        } else {
                stListaD * aux = coleccion;
                stListaD * seg = coleccion->sigNodo;
                while ( seg != NULL && nuevo->dataColecc.id > seg->dataColecc.id ) {

                    aux = seg;
                    seg = seg->sigNodo;
                }
                aux->sigNodo = nuevo;
                nuevo->antNodo = aux;
                if(seg != NULL) {
                    nuevo->sigNodo = seg;
                    seg->antNodo = nuevo;
                }
            }
    } else {
            coleccion = nuevo;
        }
    return coleccion;
}

stListaD * retornarUltimaCarta(stListaD * lista)    ///devuelve la �ltima carta de la colecci�n
{
    if ( lista != NULL ) {
        while ( lista->sigNodo != NULL ) {
            lista = lista->sigNodo;
        }
    }
    return lista;
}

void MostrarListaDoble(stListaD*Lista)
{
    if(Lista!=NULL)
    {
      muestraCarta(Lista->dataColecc);
    }

}

