#include "menu.h"
#include "stCarta.h"
#include "Constantes.h"
#include <time.h>
int main()
{
    // muestraUsuariosEnArchi();
     menuFINAL();

    /*
    ///DEBUG PARA PROBAR INTERCAMBIO
    datosUsuario usuarioNroUno;
    stListaD * coleccionNroUno = setNULL();

    datosUsuario usuarioNroDos;
    stListaD * coleccionNroDos = setNULL();

    printf("\n -----------------------");
    printf("\n Coleccion Nro Uno: \n");
    printf("\n -----------------------");
    coleccionNroUno = agregarPorIDColeccion(coleccionNroUno, creaNodoColeccion(buscaCartaPorIdEnArchi(1)));
    coleccionNroUno = agregarPorIDColeccion(coleccionNroUno, creaNodoColeccion(buscaCartaPorIdEnArchi(2)));
    coleccionNroUno = agregarPorIDColeccion(coleccionNroUno, creaNodoColeccion(buscaCartaPorIdEnArchi(3)));
    coleccionNroUno = agregarPorIDColeccion(coleccionNroUno, creaNodoColeccion(buscaCartaPorIdEnArchi(4)));
    coleccionNroUno = agregarPorIDColeccion(coleccionNroUno, creaNodoColeccion(buscaCartaPorIdEnArchi(5)));
    mostrarListaDoble(coleccionNroUno);

    printf("\n -----------------------");
    printf("\n Coleccion Nro Dos: \n");
    printf("\n -----------------------");
    coleccionNroDos = agregarPorIDColeccion(coleccionNroDos, creaNodoColeccion(buscaCartaPorIdEnArchi(6)));
    coleccionNroDos = agregarPorIDColeccion(coleccionNroDos, creaNodoColeccion(buscaCartaPorIdEnArchi(7)));
    coleccionNroDos = agregarPorIDColeccion(coleccionNroDos, creaNodoColeccion(buscaCartaPorIdEnArchi(8)));
    coleccionNroDos = agregarPorIDColeccion(coleccionNroDos, creaNodoColeccion(buscaCartaPorIdEnArchi(9)));
    coleccionNroDos = agregarPorIDColeccion(coleccionNroDos, creaNodoColeccion(buscaCartaPorIdEnArchi(10)));
    mostrarListaDoble(coleccionNroDos);

    system("pause");
    system("cls");

    indicadorBuzon nuevoBuzon;
    indicadorBuzon nuevoBuzonParaSegundo;
    nuevoBuzon.demanda = creaDemanda(usuarioNroUno, buscaCartaPorIdEnArchi(3));
    nuevoBuzon.oferta = creaOferta(usuarioNroDos, buscaCartaPorIdEnArchi(8));

    usuarioNroUno.datosBuzon[usuarioNroUno.validosDatosBuzon] = nuevoBuzon;
    usuarioNroUno.validosDatosBuzon++;
    printf("\n Validos del primer usuario vale %d ", usuarioNroUno.validosDatosBuzon);
    usuarioNroDos.datosBuzon[usuarioNroDos.validosDatosBuzon] = nuevoBuzon;
    usuarioNroDos.validosDatosBuzon++;
    printf("\n Validos del segundo usuario vale %d ", usuarioNroDos.validosDatosBuzon);

    printf("\n\n");
    system("pause");
    system("cls");

    printf("\n Usuario Nro 1: ");
    muestraIndicadoresBuzon(usuarioNroUno);
    printf("\n Usuario Nro 2: ");
    muestraIndicadoresBuzon(usuarioNroDos); ///SE ROMPE ACA PESE A TENER MISMO CODIGO NO CARGA DE MISMA MANERA LOS ARREGLOS

    printf("\n\n");
    system("pause");
    system("cls");

    stNotificacion * nuevaNotifi = intercambio( &coleccionNroUno, &coleccionNroDos, nuevoBuzon);
    printf("\n Nueva Notificacion: \n");
    muestraNotificacion(nuevaNotifi);

    system("pause");
    system("cls");

    printf("\n Nueva Coleccion Nro Uno: \n");
    mostrarListaDoble(coleccionNroUno);
    printf("\n Nueva Coleccion Nro Dos: \n");
    mostrarListaDoble(coleccionNroDos);
    */

    /*
    ///Carga todo el archivo hasta que nosotros queramos
    printf("\n ---------------Archi---------------");
    muestraArchiCartas();

    char control = 's';
    while(control == 's')
    {
        cargaArchiCartas(cargaCartaUsuario());
        printf("\n Desea continuar? s/n ");
        fflush(stdin);
        scanf("%c", &control);
    }

    printf("\n ---------------Archi Nuevo---------------");
    muestraArchiCartas();
    */

    return 0;
}


