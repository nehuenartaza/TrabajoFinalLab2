#include "stCarta.h"

///stExpansion
stExpansion cargaExpansionUsuario(stExpansion expansionACargar) //Carga
{
    printf("\n Ingrese el Titulo de la Expansion: ");
    fflush(stdin);
    fgets(expansionACargar.expansionTitulo, DIM2, stdin);
    buscaSaltoLinea(expansionACargar.expansionTitulo);

    printf("\n Ingrese el SubTitulo de la Expansion: ");
    fflush(stdin);
    fgets(expansionACargar.expansionSubTit, DIM2, stdin);
    buscaSaltoLinea(expansionACargar.expansionTitulo);

    return expansionACargar;
}

void muestraExpansion(stExpansion expansionAMostrar)    //Muestra
{
    printf("\n Expansion.....: %s", expansionAMostrar.expansionTitulo);
    printf("\n Edicion.......: %s", expansionAMostrar.expansionSubTit);
}

///stCarta
stCarta cargaCartaUsuario() //Carga una carta
{
    stCarta nuevaCarta;
    //printf("\n Ingrese ID de la carta: ");
    //scanf("%d", &nuevaCarta.id);
    nuevaCarta.cant = 1;
    printf("\n Ingrese el Nombre de la carta: ");
    fflush(stdin);
    fgets(nuevaCarta.nombre, DIM2, stdin);
    buscaSaltoLinea(nuevaCarta.nombre);
    printf("\n Ingrese la Rareza de la carta: ");
    fflush(stdin);
    fgets(nuevaCarta.rareza, DIM3, stdin);
    buscaSaltoLinea(nuevaCarta.rareza);
    nuevaCarta.claseCarta = cargaClaseUsuario(nuevaCarta.claseCarta);
    nuevaCarta.expansionCarta = cargaExpansionUsuario(nuevaCarta.expansionCarta);
    nuevaCarta.id = buscaUltimoIDEnArchi() + 1;
    return nuevaCarta;
}

void muestraCarta(stCarta cartaAMostrar)    //Muestra Carta
{
    printf("\n Id............: %d", cartaAMostrar.id);
    printf("\n Nombre........: %s", cartaAMostrar.nombre);
    printf("\n Rareza........: %s", cartaAMostrar.rareza);
    printf("\n Cantidad......: %d", cartaAMostrar.cant);
    muestraClase(cartaAMostrar.claseCarta);
    muestraExpansion(cartaAMostrar.expansionCarta);
}

///Lista De Cartas
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
    arbolDeListasCartas * nuevoNodoArbol = (arbolDeListasCartas*)malloc(sizeof(arbolDeListasCartas));
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
        listaDeCartas*nuevaCarta = creaNodoConCarta(cartaACargar); //Creo mi nuevo nodo de lista (una carta nueva) a cargar en el arbol de lista
        char inicialABuscar = nuevaCarta->dato.nombre[0]; //Creo una variable que guarde su inicial
        arbolDeListasCartas * nodoACargar = buscaNodoConInicial(raizActual_F, inicialABuscar); //busco el nodo de mi arbol con la inicial de mi carta
        if(nodoACargar == NULL)  //Si no encontro el nodo de la incial
        {
            nodoACargar = creaNodoArbolCartas(inicialABuscar); //Crea el nodo de la inicial que no encontro
            raizActual_F = agregarNodoArbol(raizActual_F, nodoACargar); //Agrega el nodo con la inicial nueva
        }
        //carga mi carta al nodo
        raizActual_F = agregaCartaANodoDeArbol(raizActual_F, inicialABuscar, nuevaCarta);
    }else
    {
        raizActual_F=creaNodoArbolCartas(cartaACargar.nombre[0]);
        raizActual_F->listaDeCartasPorInicial=cargaAFIN(raizActual_F->listaDeCartasPorInicial, creaNodoConCarta(cartaACargar));
    }
    return raizActual_F;
}

arbolDeListasCartas * agregaCartaANodoDeArbol(arbolDeListasCartas* raizActual_F, char inicialDeNodoArbol, listaDeCartas * nuevaCarta_F)
{
    if(raizActual_F!=NULL)
    {
        if(raizActual_F->inicial == inicialDeNodoArbol)
            raizActual_F->listaDeCartasPorInicial = cargaAFIN(raizActual_F->listaDeCartasPorInicial, nuevaCarta_F);
        else if(inicialDeNodoArbol < raizActual_F->inicial)
            raizActual_F->izquierda = agregaCartaANodoDeArbol(raizActual_F->izquierda, inicialDeNodoArbol, nuevaCarta_F);
        else if(inicialDeNodoArbol > raizActual_F->inicial)
            raizActual_F->derecha = agregaCartaANodoDeArbol(raizActual_F->derecha, inicialDeNodoArbol, nuevaCarta_F);
    }
    return raizActual_F;
}

void muestraArbolDeCartas(arbolDeListasCartas * arbolAMostrar)    //Muestra Arbol
{
    if(arbolAMostrar != NULL)
    {
        muestraArbolDeCartas(arbolAMostrar->izquierda);
        printf("\n -----------------------");
        printf("\n Cartas con inicial: %c", arbolAMostrar->inicial);
        printf("\n -----------------------");
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
    char control = 's';
    do
    {
        stCarta nuevaCarta = cargaCartaUsuario();
        arbolACargar = altaCarta(arbolACargar, nuevaCarta);
        printf("\nDesea cargar mas cartas? s/n ");
        scanf("%c", &control);
    }
    while(control == 's');
    return arbolACargar;
}

