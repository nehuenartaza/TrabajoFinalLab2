#include "menu.h"
#include "stCarta.h"
#include "Constantes.h"

int main()
{
    arbolDeListasCartas*baseDeDatosDeCartas=inicArbol();

    baseDeDatosDeCartas=cargaArbolDeListasDeCartasUsuario(baseDeDatosDeCartas);

    muestraArbolDeCartas(baseDeDatosDeCartas);
    return 0;
}
