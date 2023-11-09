///Librerias
#include "stCarta.h"

///Cuerpos
//Carga una carta
stCarta cargaCartaUsuario()
{
    stCarta nuevaCarta;

    printf("\n Ingrese ID de la carta: ");
    scanf("%d", &nuevaCarta.id);

    printf("\n Ingrese Cantidad que tiene de esa carta: ");
    scanf("%d", &nuevaCarta.cant);

    printf("\n Ingrese el Nombre de la carta: ");
    fflush(stdin);
    fgets(nuevaCarta.nombre, DIM2, stdin);
    buscaSaltoLinea(nuevaCarta.nombre);

    printf("\n Ingrese la Rareza de la carta:");
    fflush(stdin);
    fgets(nuevaCarta.rareza, DIM3, stdin);
    buscaSaltoLinea(nuevaCarta.rareza);

    nuevaCarta.claseCarta=cargaClaseUsuario(nuevaCarta.claseCarta);
    nuevaCarta.expancionCarta=cargaExpansionUsuario(nuevaCarta.expancionCarta);

    return nuevaCarta;
}
//Muestra Carta
void muestraCarta(stCarta cartaAMostrar)
{
    printf("\n Id: %d", cartaAMostrar.id);
    printf("\n Nombre: %s", cartaAMostrar.nombre);
    printf("\n Rareza: %s", cartaAMostrar.rareza);
    printf("\n Cantidad: %d", cartaAMostrar.cant);

    muestraClase(cartaAMostrar.claseCarta);
    muestraExpansion(cartaAMostrar.expancionCarta);
}
//Inicializa Lista
listaDeCartas*inicLista()
{
    return NULL;
}
//Crea Nodo de la Lista de Cartas
listaDeCartas*creaNodoConCarta(stCarta cartaAGuardar)
{
    listaDeCartas*nuevoNodoAGuardar=(listaDeCartas*)malloc(sizeof(listaDeCartas));

    nuevoNodoAGuardar->dato=cartaAGuardar;
    nuevoNodoAGuardar->siguiente=NULL;
    nuevoNodoAGuardar->anterior=NULL;

    return nuevoNodoAGuardar;
}
//Carga Lista de Carta
listaDeCartas*cargaCartas(listaDeCartas*listaACargar)
{
    listaDeCartas*nuevaCarta=creaNodoConCarta(cargaCartaUsuario());

    if(listaACargar==NULL)
        listaACargar=nuevaCarta;
    else
        listaACargar=cargaAFIN(listaACargar, nuevaCarta);

    return listaACargar;
}
//Carga al final
listaDeCartas*cargaAFIN(listaDeCartas*listaACargar, listaDeCartas*nuevoNodo)
{
    listaDeCartas*ultimo=buscaUltimoNodoListaCartas(listaACargar);
    if(ultimo!=NULL)
    {
        ultimo->siguiente=nuevoNodo;
        nuevoNodo->anterior=ultimo;
    }
    else
        listaACargar=nuevoNodo;

    return listaACargar;
}
//Busca Ultimo
listaDeCartas*buscaUltimoNodoListaCartas(listaDeCartas*listaDeCartaARecorrer)
{
    listaDeCartas*ultimoNodo = listaDeCartaARecorrer;

    if(listaDeCartaARecorrer != NULL)
    {
        while(ultimoNodo->siguiente!=NULL)
            ultimoNodo=ultimoNodo->siguiente;
    }
    return ultimoNodo;
}
//Muestra Nodo2 Lista Cartas
void muestraListaCartas(listaDeCartas*listaAMostrar)
{
    while(listaAMostrar!=NULL)
    {
        muestraNodoCarta(listaAMostrar);
        listaAMostrar=listaAMostrar->siguiente;
    }
}
//Muestra Nodo de la lista
void muestraNodoCarta(listaDeCartas*nodoAMostrar)
{
    muestraCarta(nodoAMostrar->dato);
}

///Arboles de Listas
//Inicializa Arbol
arbolDeListasCartas*inicArbol()
{
    return NULL;
}
//Crea Nodo Arbol
arbolDeListasCartas*creaNodoArbolCartas(char nuevaInicial)
{
    arbolDeListasCartas*nuevoNodoArbol;

    nuevoNodoArbol->inicial=nuevaInicial;
    nuevoNodoArbol->izquierda=NULL;
    nuevoNodoArbol->derecha=NULL;
    nuevoNodoArbol->listaDeCartasPorInicial=inicLista();

    return nuevoNodoArbol;
}
//Busca Nodo Arbol Por Inicial de Pokemon
arbolDeListasCartas*buscaNodoConInicial(arbolDeListasCartas*raizEnQueBuscar, char inicialABuscar)
{
    arbolDeListasCartas*raizQueBusco = NULL;

    if(raizEnQueBuscar!=NULL)
    {
        if(raizEnQueBuscar->inicial==inicialABuscar)
            raizQueBusco=raizEnQueBuscar;
        else if(raizEnQueBuscar->inicial > inicialABuscar)
            raizQueBusco=buscaNodoConInicial(raizEnQueBuscar->izquierda, inicialABuscar);
        else if(raizEnQueBuscar->inicial < inicialABuscar)
            raizQueBusco=buscaNodoConInicial(raizEnQueBuscar->derecha, inicialABuscar);
    }
    return raizQueBusco; //si devuelve null no lo encontro
}
//Agrega Nodo Arbol
arbolDeListasCartas*agregarNodoArbol(arbolDeListasCartas*raizActual_F, arbolDeListasCartas*nuevaRaiz_F)
{
    if(raizActual_F==NULL)
        raizActual_F=nuevaRaiz_F;
    else
    {
        if(nuevaRaiz_F->inicial < raizActual_F->inicial)
            raizActual_F->izquierda = agregarNodoArbol(raizActual_F->izquierda, nuevaRaiz_F);
        else
            raizActual_F->derecha = agregarNodoArbol(raizActual_F->derecha, nuevaRaiz_F);
    }
    return raizActual_F;
}
//Carga un pokemon por inicial y si no esta crea el nodo de la incial
arbolDeListasCartas*altaCarta(arbolDeListasCartas*raizActual_F, stCarta cartaACargar)
{
    if(raizActual_F!=NULL) //Si raiz es distinto de null trabajo
    {
        arbolDeListasCartas*nodoACargar=buscaNodoConInicial(raizActual_F, cartaACargar.nombre[0]); //busco el nodo de mi arbol con la inicial de mi carta

        if(nodoACargar==NULL)  //Si no encontro el nodo de la incial lo crea
        {
            nodoACargar=creaNodoArbolCartas(cartaACargar.nombre[0]);
            raizActual_F=agregarNodoArbol(raizActual_F, nodoACargar);
        }
        //carga mi carta al nodo
        nodoACargar->listaDeCartasPorInicial=cargaAFIN(nodoACargar->listaDeCartasPorInicial, creaNodoConCarta(cartaACargar));
    }
    return raizActual_F;
}
//Muestra Arbol
void muestraArbolDeCartas(arbolDeListasCartas*arbolAMostrar)
{
    if(arbolAMostrar!=NULL)
    {
        muestraArbolDeCartas(arbolAMostrar->izquierda);
        printf("\n Cartas con inicial: %c", arbolAMostrar->inicial);
        muestraRaiz(arbolAMostrar);
        muestraArbolDeCartas(arbolAMostrar->derecha);
    }
}
//Muestra Raiz
void muestraRaiz(arbolDeListasCartas*raizAMostrar)
{
    muestraListaCartas(raizAMostrar->listaDeCartasPorInicial);
}
//Carga Arbol Usuario
arbolDeListasCartas*cargaArbolDeListasDeCartasUsuario(arbolDeListasCartas*arbolACargar)
{

    stCarta nuevaCarta=cargaCartaUsuario();
    char control='s';

    do
    {
        arbolACargar=altaCarta(arbolACargar, nuevaCarta);
        printf("\nDesea cargar mas cartas? s/n ");
        scanf("%c", &control);
    }
    while(control=='s');

    return arbolACargar;
}
