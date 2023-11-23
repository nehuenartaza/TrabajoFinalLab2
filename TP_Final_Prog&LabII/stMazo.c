#include "stMazo.h"
//FUNCIONES PARA LA LISTA SIMPLE QUE TIENE EL MAZO///
mazoSimple*VerRepetidosSimple(mazoSimple*Lista,mazoSimple*ListaVerificar,int*verificar) //VERIFICA SI NO SE REPITE EL ID, SI LO HACE, SE SUMA SU CANTIDAD
{
    if(Lista!=NULL)
    {
        if(Lista->dato.id==ListaVerificar->dato.id)
        {
            Lista->dato.cant++;
            (*verificar)=1;
        }
        else
        {
            mazoSimple*seguidora=Lista->siguiente;
            while(seguidora!=NULL&&seguidora->dato.id!=ListaVerificar->dato.id)
            {

                seguidora=seguidora->siguiente;


            }
            if(seguidora!=NULL)
            {
               seguidora->dato.cant++;
               (*verificar)=1;

            }

        }



    }
    return Lista;
}
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
    if(*Lista!=NULL)
    {
        if((*Lista)->dato.cant>1)
        {
            (*Lista)->dato.cant--;
            datoAretornar=(*Lista)->dato;
            datoAretornar.cant=1;
        }
        else
        {
            mazoSimple*Borrar;

            datoAretornar=(*Lista)->dato;
            Borrar=(*Lista);

            (*Lista)=(*Lista)->siguiente;

            free(Borrar);

        }


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
    int dato=0;
    mazoSimple*NuevoNodo=CrearNodo(NuevaCarta);
    Pila->Tope=VerRepetidosSimple(Pila->Tope,NuevoNodo,&dato);
    if(dato==0)
    {
        Pila->Tope=AgregarAlprincipio(Pila->Tope,NuevoNodo);
    }
}
stCarta DesapilarMazo(stMazo*Pila)   //saca una carta del mazo y retorna la carta
{
    stCarta dato;

   dato=BorrarPrimero(&(Pila->Tope));  //direccion de memoria del tope para el doble puntero

  return dato;
}
stCarta MostrarTope(stMazo*Pila)   //muestra la carta que esta al tope del mazo
{

    stCarta dato=Pila->Tope->dato;

    return dato;
}
int ContarMazo(stMazo Pila)
{
    int cant=0;
    cant=ContarMazoSimple(Pila.Tope);
    return cant;
}
int ContarMazoSimple(mazoSimple*Lista)
{
    int dato=0;
    if(Lista!=NULL)
    {
        dato=Lista->dato.cant+ContarMazoSimple(Lista->siguiente);


    }

    return dato;

}
int MazoVacio(stMazo*Pila) //determina si el mazo esta vacio
{

    return Pila->Tope? 0:1;  //vefifica si el tope tiene datos, si no los tiene retorna 0, sino 1
}
void VaciarMazo(stMazo*Pila)  //desapila el mazo hasta que este vacio
{
    if(MazoVacio(Pila))
    {

        printf("\nEl Mazo ya esta Vacio.\n");

    }
    else
    {
        while(!MazoVacio(Pila))
        {
            DesapilarMazo(Pila);
        }
      printf("\n El mazo se ha vaciado correctamente\n");
    }

}

void MostrarMazo(stMazo Pila) //muestra el mazo de cartas , accediendo de forma recursiva a la lista simple
{
    if(MazoVacio(&Pila))
    {
        printf("\n El Mazo esta Vacio.\n");

    }
    else
    {
       printf("\n Mazo de cartas:\n");

       MostrarMazoSimple(Pila.Tope);

    }


}
void MostrarMazoSimple(mazoSimple*Lista)
{
    if(Lista!=NULL)
    {
        printf("----------------------------------\n");
        muestraCarta(Lista->dato);
        printf("----------------------------------\n");
        MostrarMazoSimple(Lista->siguiente);



    }
}
//FUNCION PARA METER EN EL MAZO Y BORRAR NODO
void CargarMazoAleatoriamente(stMazo*Pila,stListaD*ListaDoble) //recibimos una copia de la coleccion, no la original
{
   int cartas=contarCartasListaDoble(ListaDoble);
    //contamos sus cartas para ver con cuantas trabajamos para apilar
   int contador;
   int numeroRandom;
   while(cartas!=0&&(ContarMazo(*Pila))<MAXMAZO) //el programa solo podra llenar el mazo hasta que el mazo no llegue a su limite o se vacien las cartas de la copia de la coleccion
   {
        contador=0;
        numeroRandom=rand()%cartas+1;
        ListaDoble=BorrarNodoYMeterEnMazoNodoElegidoConContador(ListaDoble,Pila,numeroRandom,contador+1);
        cartas=contarCartasListaDoble(ListaDoble);
   }

     printf("\n Se ha implementado el Mazo aleatorio correctamente\n");

}


stListaD*BorrarNodoYMeterEnMazoNodoElegidoConContador(stListaD*Lista,stMazo*Pila,int numeroDePosicion,int contador)
{
    if(Lista!=NULL)
    {
        stCarta dato;
        stListaD*Borrar;
        if(contador==numeroDePosicion)          //encuentra la posicion en donde se encuentra el nodo que se apilara al mazo
        {                                       //pueden suceder dos cosas

            if(Lista->dataColecc.cant>1)        //la copia de la coleccion puede tener mas de una carta por lo tanto, no se borra el nodo
            {
                Lista->dataColecc.cant--;       //se resta la cantidad de la lista,se hace una copia para no afectar la original y se agrega al mazo
                dato=Lista->dataColecc;
                dato.cant=1;
                apilarMazo(Pila,dato);

            }
            else
            {
                Borrar=Lista;                           //caso contrario si solo tiene una cantidad de una carta, se borra de la lista y se agrega al mazo
                Lista=Lista->sigNodo;
                apilarMazo(Pila,Borrar->dataColecc);
                free(Borrar);


            }


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
                if(siguiente->dataColecc.cant>1)
                {
                    siguiente->dataColecc.cant--;
                    dato=siguiente->dataColecc;
                    dato.cant=1;
                    apilarMazo(Pila,dato);

                }
                else
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

    }

    return Lista;


}
datosUsuario guardaIndicadoresdeMazo(stMazo*ColeccionAguardar,datosUsuario UsuarioAeditar)
{
   UsuarioAeditar.validosDatosMazo=0;
   while(!MazoVacio(ColeccionAguardar))
   {
        UsuarioAeditar=guardaIndicadorMazo(UsuarioAeditar,ColeccionAguardar->Tope->dato);

        DesapilarMazo(ColeccionAguardar);

   }

    return UsuarioAeditar;
}
