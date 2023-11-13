#include "menu.h"
#include "stCarta.h"
#include "Constantes.h"
#include <time.h>

void buscaSaltoLinea(char arg[])    //Revisa un string buscando salto de linea
{
    arg[strcspn(arg, "\n")] = 0;
}

void * setNULL()
{
    return NULL;
}
