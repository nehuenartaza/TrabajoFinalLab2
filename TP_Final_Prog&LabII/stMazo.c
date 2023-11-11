#include "stMazo.h"
//FUNCIONES PARA LA LISTA SIMPLE QUE TIENE EL MAZO///
/*void*setNULL()   //tambien requiere de este
{
    return NULL;

}
*/
mazoSimple*AgregarAlprincipio(mazoSimple*Lista,mazoSimple*NuevaLista) //agrega al principio el nuevo nodo
{
    if(Lista==NULL)
    {
        Lista=NuevaLista;

    }
    else
    {
        NuevaLista->siguiente=Lista;

        Lista=NuevaLista;

    }

    return Lista;
}
mazoSimple*CrearNodo(stCarta dato) //crea el nodo simple para poner en el mazo, que es sacado de stColeccion
{
    mazoSimple*NuevoNodo=(mazoSimple*)malloc(sizeof(mazoSimple));
    NuevoNodo->dato=dato;
    NuevoNodo->siguiente=setNULL();

    return NuevoNodo;
}
stCarta BorrarPrimero(mazoSimple**Lista) //borra el primer nodo de la lista usando puntero doble y lo retorna
{
  stCarta datoAretornar;

    if(Lista!=NULL)
    {
        mazoSimple*Borrar;

        datoAretornar=(*Lista)->dato;
        Borrar=(*Lista);

        (*Lista)=(*Lista)->siguiente;

        free(Borrar);

    }

    return datoAretornar;

}

//FUNCIONES PARA EL MAZO
void apilarMazo(stMazo*Pila,stCarta NuevaCarta)  //apila una carta en el mazo creado
{
    mazoSimple*NuevoNodo=CrearNodo(NuevaCarta);
    Pila->Tope=AgregarAlprincipio(Pila->Tope,NuevoNodo);
}
stCarta DesapilarMazo(stMazo*Pila)   //saca una carta del mazo y retorna la carta
{
    stCarta dato=BorrarPrimero(&(Pila->Tope));  //direccion de memoria del tope para el doble puntero

  return dato;
}
stCarta MostrarTope(stMazo*Pila)   //muestra la carta que esta al tope del mazo
{

    stCarta dato=Pila->Tope->dato;

    return dato;
}
int MazoVacio(stMazo*Pila) //determina si el mazo esta vacio
{

    return Pila->Tope? 0:1;  //vefifica si el tope tiene datos, si no los tiene retorna 0, sino 1
}
void MostrarMazo(stMazo Pila) //muestra el mazo de cartas
{
    printf("MAZO DE CARTAS:\n");
    while(!MazoVacio(&Pila))
    {
        printf("----------------------------------\n");
        muestraCarta((Pila.Tope)->dato);
        DesapilarMazo((&Pila)->Tope);
        printf("----------------------------------\n");
    }
}

//void CargarMazoAleatoriamente(stMazo*Pila) esta nos falta implementar debido a que falta stColeccion

