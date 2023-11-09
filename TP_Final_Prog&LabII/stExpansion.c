///Librerias
#include "stExpansion.h"

///Cuerpos
//Carga
stExpansion cargaExpansionUsuario(stExpansion expancionACargar)
{
    printf("\n Ingrese el Titulo de la Expansion:");
    fflush(stdin);
    fgets(expancionACargar.expansionTitulo, DIM, stdin);
    buscaSaltoLinea(expancionACargar.expansionTitulo);

    printf("\n Ingrese el SubTitulo de la Expansion:");
    fflush(stdin);
    fgets(expancionACargar.expansionSubTit, DIM, stdin);
    buscaSaltoLinea(expancionACargar.expansionTitulo);

    return expancionACargar;
}
//Muestra
void muestraExpansion(stExpansion expansionAMostrar)
{
    printf("\n Expansion: %s", expansionAMostrar.expansionTitulo);
    printf("\n Edicion..: %s", expansionAMostrar.expansionSubTit);
}
