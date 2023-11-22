#include "menu.h"
#include "stCarta.h"
#include "Constantes.h"
#include <time.h>
int main()
{
    // muestraUsuariosEnArchi();
    // menuFINAL();



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


