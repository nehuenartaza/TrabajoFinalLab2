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
