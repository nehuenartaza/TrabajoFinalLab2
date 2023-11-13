#include "listaDoble.h"

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
/* //NO BORRAR, FUNCION PARA EL MAZO, VER BIEN QUE ALMACENA UN STCOLECCION PARA PODER USARLA
void BorrarNodoYMeterEnMazoNodoElegidoConContador(stListaD**Lista,stMazo*Pila,int numeroDePosicion,int contador)
{
    if(Lista!=NULL)
    {
        if(contador!=numeroDePosicion)
        {

            BorrarNodoElegidoConContador((&(*Lista)->sigNodo),numeroDePosicion,contador+1);


        }
        else
        {
            stListaD*Borrar=(*Lista);
            (*Lista)=(*Lista)->sigNodo;
            if((*Lista)!=NULL)
            {
                (*Lista)->antNodo=Borrar->antNodo;
                stListaD*siguiente=(*Lista)->sigNodo;

                if(siguiente!=NULL)
                {
                    siguiente->antNodo=(*Lista);




                }

            }
            apilarMazo(Pila,Borrar->dataColec);   //ACA ME TIRA EL ERROR, EN EL SEGUNDO PARAMETRO, POR EL TIPO DE DATO
            free(Borrar);

        }

    }




}
*/






