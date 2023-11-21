#include "menu.h"



void menuLogin()
{
    printf("\n Bienvenido a la aplicacion (nombre o no se)\n");

    printf("\n1- Iniciar sesion.");
    printf("\n2- Crear cuenta nueva.");
    printf("\n0- Salir del programa.");

    printf("\n\n");
}


void menuPrincipal()
{
    printf("\n1- Base de datos de cartas.");
    printf("\n2- Coleccion.");
    printf("\n3- Intercambio.(NO ENTRAR ACA TODAVIA, FALTAN TERMINAR FUNCIONES)");  // NO OLVIDARSE ESTO
    printf("\n4- Mazo de juego.");
    printf("\n9- Guardar y cerrar sesion.");
    printf("\n\n");
}


void menuBaseDeDatos()
{
    printf("\n1- Mostrar base de datos completa.");
    printf("\n2- Filtrar y mostrar cartas por parametro.");
    printf("\n9- Volver.");
    printf("\n\n");
}

void menuOpcionDeFiltradoBaseDeDatos()
{
    printf("\nQué caracteristica desea filtrar?");
    printf("\n\n1- Nombre");
    printf("\n2- Rareza");
    printf("\n3- Expansion");
    printf("\n4- Subexpansion");
    printf("\n8- Volver.");
    printf("\n\n");
}

void menuOpcionDeFiltradoColeccion()
{
    printf("\nQué caracteristica desea filtrar?");
    printf("\n\n1- Nombre");
    printf("\n2- Rareza");
    printf("\n3- Expansion");
    printf("\n4- Subexpansion");
    printf("\n7- Volver.");
    printf("\n\n");
}

void menuColeccion1()
{
    /*  AGREGAR PARAMETRO COLECCION PARA QUE FUNCIONEN
    int cartasTotales = contadorCartasTotalesEnColeccion();
    int pokemon = contadorCartasPokemonEnColeccion();
    int entrenador = contadorCartasEntrenadorEnColeccion();
    int energia = contadorCartasEnergiaEnColeccion();

    float promPokemon = (float) (pokemon/cartasTotales)*100;
    float promEntrenador = (float) (entrenador/cartasTotales)*100;
    float promEnergia = (float) (energia/cartasTotales)*100;

    printf("\nActualmente contiene %d cartas en su coleccion.", cartasTotales);
    printf("\nContiene %d de %.1f cartas de clase Pokemon.", pokemon, promPokemon);
    printf("\nContiene %d de %.1f cartas de clase Entrenador.", entrenador, promEntrenador);
    printf("\nContiene %d de %.1f cartas de clase Energia.", energia, promEnergia);

    */

    printf("\n1- Ver mi coleccion.");
    printf("\n2- Agregar cartas a mi coleccion (por ID).");
    printf("\n3- Remover cartas de mi coleccion (por ID).");  // esta opcion la ponemos junto al menu de agregar carta o la dejamos separada en su propio menu??
    printf("\n9- Volver.");
    printf("\n\n");
}

void menuColeccion2()
{
    printf("\n1- Mostrar coleccion completa.");
    printf("\n2- Filtrar y mostrar coleccion por parametro.");
    printf("\n8- Volver.");
    printf("\n\n");
}

void menuIntercambio()      // prototipo super prototipo SUJETO A CAMBIOS
{
    printf("\n1- Ver mazo de intercambio.");
    printf("\n2- Agregar cartas al mazo de intercambio.");
    printf("\n3- Remover cartas del mazo de intercambio.");  // idem que con la coleccion, ponemos agregar/remover juntos o separados?
    printf("\n4- Realizar intercambio.");
    printf("\n5- Buzon de notificaciones.");
    printf("\n9- Volver.");
    printf("\n\n");
}

/*
void menuBuzonNotificacion()        // Esto habria que implementarlo o no??
{

}
*/
void menuMazo()
{
    printf("\n1- Mostrar mazo.");
    printf("\n2- Agregar carta al mazo.");
    printf("\n3- Remover carta del mazo.");       // idem que con la coleccion, ponemos agregar/remover juntos o separados?
    printf("\n4- Armar mazo aleatorio.");
    printf("\n9- Volver.");
    printf("\n\n");
}

void menuFINAL()
{
    datosUsuario usuario;
    int login = 0;  // valor 0 indica que no está logueado y se usa para mandar al menu de inicio, valor 1 significa que hay un usuario logueado y se abre el programa.
    int opcion = 0; // variable para navegar por los menues/switch
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
}
