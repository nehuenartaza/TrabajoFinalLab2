#include "stMazo.h"
//FUNCIONES PARA LA LISTA SIMPLE QUE TIENE EL MAZO///
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
void InicMazo(stMazo*Pila) //INICIALIZA EL MAZO
{
    Pila->Tope=setNULL();
}
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
        DesapilarMazo(&Pila);
        printf("----------------------------------\n");
    }
}
//FUNCION PARA METER EN EL MAZO Y BORRAR NODO
void CargarMazoAleatoriamente(stMazo*Pila,stListaD*ListaDoble)
{
   int cartas=contarCartasListaDoble(ListaDoble);
   int contador;
   int numeroRandom;
   while(cartas!=0)
   {
        contador=0;
        numeroRandom=rand()%cartas+1;
        ListaDoble=BorrarNodoYMeterEnMazoNodoElegidoConContador(ListaDoble,Pila,numeroRandom,contador+1);
        cartas--;
   }
}


stListaD*BorrarNodoYMeterEnMazoNodoElegidoConContador(stListaD*Lista,stMazo*Pila,int numeroDePosicion,int contador)
{
    if(Lista!=NULL)
    {
        stListaD*Borrar;
        if(contador==numeroDePosicion)
        {
            Borrar=Lista;
            Lista=Lista->sigNodo;
            apilarMazo(Pila,Borrar->dataColecc);
            free(Borrar);

        }
        else
        {
           contador++;
           stListaD*siguiente=Lista->sigNodo;
           stListaD*anterior=Lista;
           while(siguiente!=NULL&&contador!=numeroDePosicion)
           {
                anterior=siguiente;
                siguiente=siguiente->sigNodo;
                contador++;


           }
           if(siguiente!=NULL)
           {
             Borrar=siguiente;
             siguiente=siguiente->sigNodo;
             anterior->sigNodo=Borrar->sigNodo;
             if(siguiente!=NULL)
             {

                siguiente->antNodo=anterior;


             }

            apilarMazo(Pila,Borrar->dataColecc);
            free(Borrar);

           }



        }

    }

    return Lista;


}
