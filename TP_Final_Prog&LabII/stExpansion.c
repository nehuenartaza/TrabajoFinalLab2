#include "stExpansion.h"

stExpansion cargaExpansion(char titulo_F[], char subTitulo_F[]) //Carga
{
    stExpansion expaACargar;

    strcpy(expaACargar.expansionTitulo, titulo_F);
    strcpy(expaACargar.expansionSubTit, subTitulo_F);

    return expaACargar;
}

void muestraExpansion(stExpansion expansionAMostrar)    //Muestra
{
    printf("\n Expansion: %s", expansionAMostrar.expansionTitulo);
    printf("\n Edicion..: %s", expansionAMostrar.expansionSubTit);
}
