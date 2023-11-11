#include "menu.h"
#include "stCarta.h"
#include "Constantes.h"
#include <time.h>
int main()
{
    arbolDeListasCartas * arbolDePrueba = setNULL();
    arbolDePrueba = altaCarta(arbolDePrueba, cargaCartaUsuario());
    muestraArbolDeCartas(arbolDePrueba);
    return 0;
}





