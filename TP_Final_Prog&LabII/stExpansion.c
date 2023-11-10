#include "stExpansion.h"


stExpansion cargaExpansionUsuario(stExpansion expansionACargar) //Carga
{
    printf("\n Ingrese el Titulo de la Expansion:");
    fflush(stdin);
    fgets(expansionACargar.expansionTitulo, DIM2, stdin);
    buscaSaltoLinea(expansionACargar.expansionTitulo);

    printf("\n Ingrese el SubTitulo de la Expansion:");
    fflush(stdin);
    fgets(expansionACargar.expansionSubTit, DIM2, stdin);
    buscaSaltoLinea(expansionACargar.expansionTitulo);

    return expansionACargar;
}

void muestraExpansion(stExpansion expansionAMostrar)    //Muestra
{
    printf("\n Expansion: %s", expansionAMostrar.expansionTitulo);
    printf("\n Edicion..: %s", expansionAMostrar.expansionSubTit);
}
