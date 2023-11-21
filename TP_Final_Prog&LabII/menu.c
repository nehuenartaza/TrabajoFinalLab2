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
    printf("\nQue caracteristica desea filtrar?\n");
    printf("\n1- Nombre");
    printf("\n2- Clase: Pokemon");
    printf("\n3- Clase: Entrenador");
    printf("\n4- Clase: Energia");
    printf("\n5- Rareza");
    printf("\n6- Expansion");
    printf("\n7- Subexpansion");
    printf("\n8- Volver.");
    printf("\n\n");
}

void menuOpcionDeFiltradoColeccion()
{
    printf("\nQue caracteristica desea filtrar?\n");
    printf("\n1- Nombre");
    printf("\n2- Clase: Pokemon");
    printf("\n3- Clase: Entrenador");
    printf("\n4- Clase: Energia");
    printf("\n5- Rareza");
    printf("\n6- Expansion");
    printf("\n7- Subexpansion");
    printf("\n10- Volver.");
    printf("\n\n");
}

void menuColeccion1()
{
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
    stUsuario usuario;
    datosUsuario usuarioACargar;
    int login = 0;  // valor 0 indica que no está logueado y se usa para mandar al menu de inicio, valor 1 significa que hay un usuario logueado y se abre el programa.
    int opcion = 0; // variable para navegar por los menues/switch
    arbolDeListasCartas * baseDeDatos = setNULL();
    baseDeDatos = cargaCartasArchiToArbolDL(baseDeDatos);
    char parametroDeBusqueda[DIM2];
    int idBuscado = 0;
    stListaD * aux = setNULL();
    int cartasTotales = 0, pokemon = 0, entrenador = 0, energia = 0;
    float promPokemon = 0, promEntrenador = 0, promEnergia = 0;

    do
    {
        system("cls");
        menuLogin();
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            usuario.dato = iniciarSesion(&login);
            system("pause");
            break;
        case 2:
            system("cls");
            usuarioACargar = creaUsuario();
            usuarioACargar.id = buscaUltimoIDEnArchiUsuarios() + 1;
            cargaArchiUsuarios(usuarioACargar);
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
                usuario.coleccion = cargaColeccionPorParametro(usuario.dato);
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
                            muestraArbolDeCartas(baseDeDatos);
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
                                    printf("\nIntroduzca el nombre de carta que busca: ");
                                    fflush(stdin);
                                    fgets(parametroDeBusqueda, DIM2, stdin);
                                    buscaSaltoLinea(parametroDeBusqueda);
                                    muestraArchiCartasPorNombre(parametroDeBusqueda);
                                    system("pause");
                                    break;
                                case 2:
                                    system("cls");
                                    muestraArchiCartasPokemon();
                                    system("pause");
                                    break;
                                case 3:
                                    system("cls");
                                    muestraArchiCartasEntrenador();
                                    system("pause");
                                    break;
                                case 4:
                                    system("cls");
                                    muestraArchiCartasEnergia();
                                    system("pause");
                                    break;
                                case 5:
                                    system("cls");
                                    printf("\nIntroduzca la rareza de carta que busca: ");
                                    printf("\nOpciones validas: 'Comun'; 'Poco Comun';'Rara'\n");
                                    fflush(stdin);
                                    fgets(parametroDeBusqueda, DIM2, stdin);
                                    buscaSaltoLinea(parametroDeBusqueda);
                                    muestraArchiCartasPorRareza(parametroDeBusqueda);
                                    system("pause");
                                    break;
                                case 6:
                                    system("cls");
                                    printf("\nIntroduzca el nombre de expansion que busca: ");
                                    fflush(stdin);
                                    fgets(parametroDeBusqueda, DIM2, stdin);
                                    buscaSaltoLinea(parametroDeBusqueda);
                                    muestraArchiCartasPorExpansion(parametroDeBusqueda);
                                    system("pause");
                                    break;
                                case 7:
                                    system("cls");
                                    printf("\nIntroduzca el nombre de subexpansion que busca: ");
                                    fflush(stdin);
                                    fgets(parametroDeBusqueda, DIM2, stdin);
                                    buscaSaltoLinea(parametroDeBusqueda);
                                    muestraArchiCartasPorSubExpansion(parametroDeBusqueda); // teniamos el problema en esta
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
                    system("cls");
                    do
                    {
                        system("cls");
                        menuColeccion1();
                        scanf("%d", &opcion);

                        switch(opcion)
                        {
                        case 1:
                            system("cls");
                            if(usuario.coleccion == NULL)
                            {
                                printf("\nSu coleccion esta vacia.\n");
                                system("pause");
                                break;
                            }
                            do
                            {
                                system("cls");
                                menuColeccion2();
                                cartasTotales = contadorCartasTotalesEnColeccion(usuario.coleccion);
                                pokemon = contadorCartasPokemonEnColeccion(usuario.coleccion);
                                entrenador = contadorCartasEntrenadorEnColeccion(usuario.coleccion);
                                energia = contadorCartasEnergiaEnColeccion(usuario.coleccion);

                                promPokemon = (float) (pokemon/cartasTotales)*100;
                                promEntrenador = (float) (entrenador/cartasTotales)*100;
                                promEnergia = (float) (energia/cartasTotales)*100;

                                printf("\nActualmente contiene %d cartas en su coleccion.", cartasTotales);
                                printf("\nContiene %d de %d (%.1f%)cartas de clase Pokemon.", pokemon, cartasTotales, promPokemon);
                                printf("\nContiene %d de %d (%.1f) cartas de clase Entrenador.", entrenador, cartasTotales, promEntrenador);
                                printf("\nContiene %d de %d (%.1f) cartas de clase Energia.\n", energia, cartasTotales, promEnergia);
                                scanf("%d", &opcion);

                                switch(opcion)
                                {
                                case 1:
                                    system("cls");
                                    mostrarListaDoble(usuario.coleccion);
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
                                            printf("\nIntroduzca el nombre de la carta que busca: ");
                                            fflush(stdin);
                                            fgets(parametroDeBusqueda, DIM2, stdin);
                                            buscaSaltoLinea(parametroDeBusqueda);
                                            mostrarCartasPorStringAproximado(usuario.coleccion, parametroDeBusqueda);
                                            system("pause");
                                            break;
                                        case 2:
                                            system("cls");
                                            mostrarCartasPorClasePokemon(usuario.coleccion);
                                            system("pause");
                                            break;
                                        case 3:
                                            system("cls");
                                            mostrarCartasPorClaseEntrenador(usuario.coleccion);
                                            system("pause");
                                            break;
                                        case 4:
                                            system("cls");
                                            mostrarCartasPorClaseEnergia(usuario.coleccion);
                                            system("pause");
                                            break;
                                        case 5:
                                            system("cls");
                                            printf("\nIntroduzca la rareza de la carta que busca: ");
                                            printf("\nOpciones validas: 'Comun'; 'Poco Comun';'Rara'\n");
                                            fflush(stdin);
                                            fgets(parametroDeBusqueda, DIM2, stdin);
                                            buscaSaltoLinea(parametroDeBusqueda);
                                            mostrarCartasPorRareza(usuario.coleccion, parametroDeBusqueda);
                                            system("pause");
                                            break;
                                        case 6:
                                            system("cls");
                                            printf("\nIntroduzca el nombre de expansion que busca: ");
                                            fflush(stdin);
                                            fgets(parametroDeBusqueda, DIM2, stdin);
                                            buscaSaltoLinea(parametroDeBusqueda);
                                            mostrarCartasPorExpansion(usuario.coleccion, parametroDeBusqueda);
                                            system("pause");
                                            break;
                                        case 7:
                                            system("cls");
                                            printf("\nIntroduzca el nombre de subexpansion que busca: ");
                                            fflush(stdin);
                                            fgets(parametroDeBusqueda, DIM2, stdin);
                                            buscaSaltoLinea(parametroDeBusqueda);
                                            mostrarCartasPorExpansionAuxiliar(usuario.coleccion, parametroDeBusqueda);
                                            system("pause");
                                            break;
                                        case 10:
                                            break;
                                        default:
                                            system("cls");
                                            printf("\nEl valor ingresado es invalido. Intente nuevamente.\n");
                                            system("pause");
                                            break;
                                        }
                                    }
                                    while(opcion != 10);
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
                        case 2:
                            system("cls");
                            printf("\nIngrese el numero de ID de la carta a agregar: ");
                            scanf("%d", &idBuscado);
                            if(buscaCartaPorIdEnArchi(idBuscado).id == idBuscado)
                            {
                                usuario.coleccion = agregarPorIDColeccion(usuario.coleccion, creaNodoColeccion(buscaCartaPorIdEnArchi(idBuscado)));
                                printf("\nCarta cargada exitosamente.");
                            }
                            else
                                printf("\nNo se encontro una carta con ese ID\n");
                            system("pause");
                            break;
                        case 3:
                            system("cls");
                            if(usuario.coleccion == NULL)
                            {
                                printf("\nSu coleccion esta vacia.\n");
                                system("pause");
                                break;
                            }
                            printf("\nIngrese el numero de ID de la carta a remover: ");
                            scanf("%d", &idBuscado);
                            if(buscaNodoEnColeccionPorId(usuario.coleccion, buscarCartaPorIDYLaRetorna(usuario.coleccion, idBuscado)) != NULL)
                            {
                                stCarta cartaAux = buscarCartaPorIDYLaRetorna(usuario.coleccion, idBuscado);
                                usuario.coleccion = eliminarYRetirarCartaDeColeccion(usuario.coleccion, &cartaAux);
                                printf("\nCarta borrada exitosamente.\n");
                            }
                            else
                                printf("\nNo se encontro una carta con ese ID\n");
                            system("pause");
                            break;
                        case 9:
                            usuario.dato = guardaIndicadoresDeColeccion(usuario.coleccion, usuario.dato);
                            guardaDatosNuevos(usuario.dato);
                            muestraIndicadoresColeccion(usuario.dato);
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
                    }
                    while(opcion != 9);
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
                    }
                    while(opcion != 9);
                    break;
                case 9:
                    usuario.dato = cerrarSesion(&login);
                    break;
                default:
                    system("cls");
                    printf("\nEl valor ingresado es invalido. Intente nuevamente.\n");
                    system("pause");
                    break;
                }
            }
            while(opcion != 9 || login == 1);

        }

    }
    while(opcion != 0 && login == 0);
}
