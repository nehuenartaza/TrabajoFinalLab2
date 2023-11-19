#include "menu.h"
#include "stCarta.h"
#include "Constantes.h"
#include <time.h>
int main()
{
    datosUsuario usuario;
    int login = 0;  // valor 0 indica que no está logueado y se usa para mandar al menu de inicio, valor 1 significa que hay un usuario logueado y se abre el programa.
    int opcion = 0; // variable para navegar por los menues/switch


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





