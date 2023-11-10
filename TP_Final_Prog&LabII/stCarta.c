#include "stCarta.h"
#include "menu.h"

stCarta cargaCartaUsuario() //Carga una carta
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
    nuevaCarta.claseCarta = cargaClaseUsuario(nuevaCarta.claseCarta);
    nuevaCarta.expansionCarta = cargaExpansionUsuario(nuevaCarta.expansionCarta);
    return nuevaCarta;
}

void muestraCarta(stCarta cartaAMostrar)    //Muestra Carta
{
    printf("\n Id: %d", cartaAMostrar.id);
    printf("\n Nombre: %s", cartaAMostrar.nombre);
    printf("\n Rareza: %s", cartaAMostrar.rareza);
    printf("\n Cantidad: %d", cartaAMostrar.cant);
    muestraClase(cartaAMostrar.claseCarta);
    muestraExpansion(cartaAMostrar.expansionCarta);
}

listaDeCartas * creaNodoConCarta(stCarta cartaAGuardar)   //Crea Nodo de la Lista de Cartas
{
    listaDeCartas * nuevoNodoAGuardar = (listaDeCartas*)malloc(sizeof(listaDeCartas));
    nuevoNodoAGuardar->dato = cartaAGuardar;
    nuevoNodoAGuardar->siguiente = setNULL();
    nuevoNodoAGuardar->anterior = setNULL();
    return nuevoNodoAGuardar;
}

listaDeCartas * cargaCartas(listaDeCartas * listaACargar)   //Carga Lista de Carta
{
    listaDeCartas * nuevaCarta = creaNodoConCarta(cargaCartaUsuario());
    if(listaACargar == NULL)
        listaACargar = nuevaCarta;
    else
        listaACargar = cargaAFIN(listaACargar, nuevaCarta);
    return listaACargar;
}

listaDeCartas * cargaAFIN(listaDeCartas * listaACargar, listaDeCartas * nuevoNodo)    //Carga al final
{
    listaDeCartas * ultimo = buscaUltimoNodoListaCartas(listaACargar);
    if(ultimo!=NULL)
    {
        ultimo->siguiente = nuevoNodo;
        nuevoNodo->anterior = ultimo;
    }
    else
        listaACargar = nuevoNodo;
    return listaACargar;
}

listaDeCartas * buscaUltimoNodoListaCartas(listaDeCartas * listaDeCartaARecorrer)   //Busca Ultimo
{
    listaDeCartas * ultimoNodo = listaDeCartaARecorrer;

    if(listaDeCartaARecorrer != NULL)
    {
        while(ultimoNodo->siguiente != NULL)
            ultimoNodo = ultimoNodo->siguiente;
    }
    return ultimoNodo;
}

void muestraListaCartas(listaDeCartas * listaAMostrar)    //Muestra Nodo2 Lista Cartas
{
    while(listaAMostrar != NULL)
    {
        muestraNodoCarta(listaAMostrar);
        listaAMostrar = listaAMostrar->siguiente;
    }
}

void muestraNodoCarta(listaDeCartas * nodoAMostrar)   //Muestra Nodo de la lista
{
    muestraCarta(nodoAMostrar->dato);
}

///Arboles de Listas
arbolDeListasCartas * creaNodoArbolCartas(char nuevaInicial)  //Crea Nodo Arbol
{
    arbolDeListasCartas * nuevoNodoArbol;
    nuevoNodoArbol->inicial = nuevaInicial;
    nuevoNodoArbol->izquierda = setNULL();
    nuevoNodoArbol->derecha = setNULL();
    nuevoNodoArbol->listaDeCartasPorInicial = setNULL();
    return nuevoNodoArbol;
}

arbolDeListasCartas * buscaNodoConInicial(arbolDeListasCartas * raizEnQueBuscar, char inicialABuscar)   //Busca Nodo Arbol Por Inicial de Pokemon
{
    arbolDeListasCartas * raizQueBusco = setNULL();

    if(raizEnQueBuscar != NULL)
    {
        if(raizEnQueBuscar->inicial == inicialABuscar)
            raizQueBusco = raizEnQueBuscar;
        else if(raizEnQueBuscar->inicial > inicialABuscar)
            raizQueBusco = buscaNodoConInicial(raizEnQueBuscar->izquierda, inicialABuscar);
        else if(raizEnQueBuscar->inicial < inicialABuscar)
            raizQueBusco = buscaNodoConInicial(raizEnQueBuscar->derecha, inicialABuscar);
    }
    return raizQueBusco; //si devuelve NULL no lo encontro
}

arbolDeListasCartas * agregarNodoArbol(arbolDeListasCartas * raizActual_F, arbolDeListasCartas * nuevaRaiz_F) //Agrega Nodo Arbol
{
    if(raizActual_F == NULL)
        raizActual_F = nuevaRaiz_F;
    else
    {
        if(nuevaRaiz_F->inicial < raizActual_F->inicial)
            raizActual_F->izquierda = agregarNodoArbol(raizActual_F->izquierda, nuevaRaiz_F);
        else
            raizActual_F->derecha = agregarNodoArbol(raizActual_F->derecha, nuevaRaiz_F);
    }
    return raizActual_F;
}

arbolDeListasCartas * altaCarta(arbolDeListasCartas * raizActual_F, stCarta cartaACargar)   //Carga un pokemon por inicial y si no esta crea el nodo de la incial
{
    if(raizActual_F != NULL) //Si raiz es distinto de NULL trabajo
    {
        arbolDeListasCartas * nodoACargar = buscaNodoConInicial(raizActual_F, cartaACargar.nombre[0]); //busco el nodo de mi arbol con la inicial de mi carta
        if(nodoACargar == NULL)  //Si no encontro el nodo de la incial lo crea
        {
            nodoACargar = creaNodoArbolCartas(cartaACargar.nombre[0]);
            raizActual_F = agregarNodoArbol(raizActual_F, nodoACargar);
        }
        //carga mi carta al nodo
        nodoACargar->listaDeCartasPorInicial = cargaAFIN(nodoACargar->listaDeCartasPorInicial, creaNodoConCarta(cartaACargar));
    }
    return raizActual_F;
}

void muestraArbolDeCartas(arbolDeListasCartas * arbolAMostrar)    //Muestra Arbol
{
    if(arbolAMostrar != NULL)
    {
        muestraArbolDeCartas(arbolAMostrar->izquierda);
        printf("\n Cartas con inicial: %c", arbolAMostrar->inicial);
        muestraRaiz(arbolAMostrar);
        muestraArbolDeCartas(arbolAMostrar->derecha);
    }
}

void muestraRaiz(arbolDeListasCartas * raizAMostrar)  //Muestra Raiz
{
    muestraListaCartas(raizAMostrar->listaDeCartasPorInicial);
}

arbolDeListasCartas * cargaArbolDeListasDeCartasUsuario(arbolDeListasCartas * arbolACargar) //Carga Arbol Usuario
{
    stCarta nuevaCarta = cargaCartaUsuario();
    char control='s';
    do
    {
        arbolACargar = altaCarta(arbolACargar, nuevaCarta);
        printf("\nDesea cargar mas cartas? s/n ");
        scanf("%c", &control);
    }
    while(control == 's');
    return arbolACargar;
}

