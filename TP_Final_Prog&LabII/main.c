#include "menu.h"
#include "stCarta.h"
#include "Constantes.h"
#include <time.h>
int main()
{
    datosUsuario usuario;
    int login = 0;  // valor 0 indica que no está logueado y se usa para mandar al menu de inicio, valor 1 significa que hay un usuario logueado y se abre el programa.
    int opcion = 0; // variable para navegar por los menues/switch

    // declarar e inicializar resto de variables necesarias

    /*
    do
    {
        system("cls");
        menuLogin();
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            usuario = iniciarSesion(&login);
            system("pause");
            break;
        case 2:
            system("cls");
            cargaArchiUsuarios(creaUsuario());
            printf("\n Cuenta creada satisfactoriamente!\n");
            system("pause");
            break;
        case 0:
            system("cls");
            printf("\nCerrando aplicacion...Hasta luego!\n");
            system("pause");
            break;
        default:
            system("cls");
            printf("\nEl valor ingresado es invalido. Intente nuevamente.\n");
            system("pause");
            break;
        }


        if(login == 1)
        {
            do
            {
                system("cls");
                menuPrincipal();
                scanf("%d", &opcion);

                switch(opcion)
                {
                case 1:
                    do
                    {
                        system("cls");
                        menuBaseDeDatos();
                        scanf("%d", &opcion);

                        switch(opcion)
                        {
                        case 1:
                            system("cls");
                            // agregar funcion para mostrar base de datos completa
                            system("pause");
                            break;
                        case 2:
                            do
                            {
                                system("cls");
                                menuOpcionDeFiltradoBaseDeDatos();
                                scanf("%d", &opcion);

                                switch(opcion)
                                {
                                case 1:
                                    system("cls");
                                    // agregar funcion para filtrar y mostrar cartas por nombre de la base de datos (usar "strstr")
                                    system("pause");
                                    break;
                                case 2:
                                    system("cls");
                                    // agregar funcion para filtrar y mostrar cartas por rareza de la base de datos
                                    system("pause");
                                    break;
                                case 3:
                                    system("cls");
                                    // agregar funcion para filtrar y mostrar cartas de una expansion de la base de datos
                                    system("pause");
                                    break;
                                case 4:
                                    system("cls");
                                    // agregar funcion para filtrar y mostrar cartas de una SUBexpansion de la base de datos
                                    system("pause");
                                    break;
                                case 8:
                                    break;
                                default:
                                    system("cls");
                                    printf("\nEl valor ingresado es invalido. Intente nuevamente.\n");
                                    system("pause");
                                    break;
                                }
                            }
                            while(opcion != 8);
                            break;
                        case 9:
                            break;
                        default:
                            system("cls");
                            printf("\nEl valor ingresado es invalido. Intente nuevamente.\n");
                            system("pause");
                            break;
                        }

                    }
                    while(opcion != 9);
                    break;
                case 2:
                    do
                    {
                        system("cls");
                        menuColeccion1();
                        scanf("%d", &opcion);

                        switch(opcion)
                        {
                        case 1:
                            do
                            {
                                system("cls");
                                menuColeccion2();
                                scanf("%d", &opcion);

                                switch(opcion)
                                {
                                case 1:
                                    system("cls");
                                    // agregar funcion mostrar coleccion completa
                                    system("pause");
                                    break;
                                case 2:
                                    do
                                    {
                                        system("cls");
                                        menuOpcionDeFiltradoColeccion();
                                        scanf("%d", &opcion);

                                        switch(opcion)
                                        {
                                        case 1:
                                            system("cls");
                                            // agregar funcion para filtrar y mostrar cartas por nombre de la coleccion (usar "strstr")
                                            system("pause");
                                            break;
                                        case 2:
                                            system("cls");
                                            // agregar funcion para filtrar y mostrar cartas por rareza de la coleccion
                                            system("pause");
                                            break;
                                        case 3:
                                            system("cls");
                                            // agregar funcion para filtrar y mostrar cartas de una expansion de la coleccion
                                            system("pause");
                                            break;
                                        case 4:
                                            system("cls");
                                            // agregar funcion para filtrar y mostrar cartas de una SUBexpansion de la coleccion
                                            system("pause");
                                            break;
                                        case 7:
                                            break;
                                        default:
                                            system("cls");
                                            printf("\nEl valor ingresado es invalido. Intente nuevamente.\n");
                                            system("pause");
                                            break;
                                        }
                                    }while(opcion != 7);
                                    break;
                                case 8:
                                    break;
                                default:
                                    system("cls");
                                    printf("\nEl valor ingresado es invalido. Intente nuevamente.\n");
                                    system("pause");
                                    break;
                                }
                            }while(opcion != 8);
                        case 2:
                            system("cls");
                            // agregar funcion para agregar cartas a la coleccion desde base de datos (POR ID)
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            // agregar funcion para remover una carta de la coleccion (POR ID)
                            system("pause");
                            break;
                        case 9:
                            break;
                        default:
                            system("cls");
                            printf("\nEl valor ingresado es invalido. Intente nuevamente.\n");
                            system("pause");
                            break;
                        }
                    }while(opcion != 9);
                    break;
                case 3:
                    do
                    {
                        system("cls");
                        menuIntercambio();
                        scanf("%d", &opcion);

                        switch(opcion)
                        {
                        case 1:
                            system("cls");
                            // agregar funcion para mostrar mazo de intercambio completo
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            // agregar funcion para agregar cartas al mazo de intercambio desde la coleccion
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            // agregar funcion para remover cartas del mazo de intercambio desde la coleccion
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            // agregar funcion para realizar un intercambio si el mazo de intercambio esta cargado
                            system("pause");
                            break;
                        case 5:
                            system("cls");

                            system("pause");
                            break;
                        case 9:
                            break;
                        default:
                            system("cls");
                            printf("\nEl valor ingresado es invalido. Intente nuevamente.\n");
                            system("pause");
                            break;
                        }
                    }while(opcion != 9);
                    break;
                case 4:
                    do
                    {
                        system("cls");
                        menuMazo();
                        scanf("%d", &opcion);

                        switch(opcion)
                        {
                        case 1:
                            system("cls");
                            // agregar funcion mostrar mazo completo
                            system("pause");
                            break;
                        case 2:
                            system("cls");
                            // agregar funcion agregar una carta de la coleccion al mazo
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            // agregar funcion remover una carta del mazo
                            system("pause");
                            break;
                        case 4:
                            system("cls");
                            // agregar funcion armar un mazo aleatorio con las cartas disponibles en la coleccion
                            system("pause");
                            break;
                        case 9:
                            break;
                        default:
                            system("cls");
                            printf("\nEl valor ingresado es invalido. Intente nuevamente.\n");
                            system("pause");
                            break;
                        }
                    }while(opcion != 9);
                    break;
                case 9:
                    usuario = cerrarSesion(&login);
                    break;
                default:
                    system("cls");
                    printf("\nEl valor ingresado es invalido. Intente nuevamente.\n");
                    system("pause");
                    break;
                }
            }while(opcion != 9 || login == 1);

        }

    }while(opcion != 0 || login == 0);
    */


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
    return 0;
}





