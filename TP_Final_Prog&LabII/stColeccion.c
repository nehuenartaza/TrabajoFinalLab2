#include "stColeccion.h"
int ContarCartasListaDoble(stListaD*Lista)
{
    int respuesta=0;
    if(Lista!=NULL)
    {
        respuesta=1;

        respuesta=respuesta+ContarCartasListaDoble(Lista->sigNodo);

    }


    return respuesta;

}
