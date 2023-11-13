#include "menu.h"
#include "stCarta.h"
#include "Constantes.h"
#include <time.h>
int main()
{
    ///Carga todo el archivo hasta que nosotros queramos
    char control = 's';
    while(control == 's')
    {
        cargaArchiCartas(cargaCartaUsuario());
        printf("\n Desea continuar? s/n ");
        fflush(stdin);
        scanf("%c", &control)
    }

    muestraArchiCartas();
    return 0;
}





