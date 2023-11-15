#include "constantes.h"

void buscaSaltoLinea(char arg[])    //Revisa un string buscando salto de linea
{
    arg[strcspn(arg, "\n")] = 0;
}

void * setNULL()
{
    return NULL;
}
