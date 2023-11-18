#include "archivos.h"

///Archivos de Cartas
void cargaArchiCartas(stCarta cartaAGuardar) //carga el archivo
{
    FILE * archi = fopen(ARCHI_CARTAS, "ab");
    if(archi)
    {
        fwrite(&cartaAGuardar, sizeof(stCarta), 1, archi);
        fclose(archi);
    }
    else
        printf("\n El archivo no se abrio correctamente. ");
}

void muestraArchiCartas()
{
    FILE * archi = fopen(ARCHI_CARTAS, "rb");
    if(archi)
    {
        stCarta cartitaAMostrar;
        while(!feof(archi))
        {
            fread(&cartitaAMostrar, sizeof(stCarta), 1, archi);
            if(!feof(archi))
                muestraCarta(cartitaAMostrar);
        }
        fclose(archi);
    }
}

int buscaUltimoIDEnArchi()
{
    FILE * archi = fopen(ARCHI_CARTAS, "rb");
    int ultimoID = 0;
    if(archi)
    {
        stCarta cartitaEnArchi;
        fseek(archi, -sizeof(stCarta), SEEK_END);
        fread(&cartitaEnArchi, sizeof(stCarta), 1, archi);
        ultimoID = cartitaEnArchi.id;

        fclose(archi);
    }
    return ultimoID;
}

arbolDeListasCartas * cargaCartasArchiToArbolDL(arbolDeListasCartas * arbolACargar)
{
    FILE * archi = fopen(ARCHI_CARTAS, "rb");
    if(archi)
    {
        stCarta cartitaACargar;
        while(!feof(archi))
        {
            fread(&cartitaACargar, sizeof(stCarta), 1, archi);
            if(!feof(archi))
                arbolACargar=altaCarta(arbolACargar, cartitaACargar);
        }
        fclose(archi);
    }
    return arbolACargar;
}

void cargaArchiUsuarios(datosUsuario usuarioAGuardar)
{
    FILE * archi = fopen(ARCHI_USUARIOS, "ab");

    if(archi){
        fwrite(&usuarioAGuardar, sizeof(datosUsuario), 1, archi);
        fclose(archi);
    }
    else
        printf("\n El archivo no se abrio correctamente. ");
}

datosUsuario iniciarSesion()
{
    datosUsuario usuario;
    char nombreUsuario[DIM3];
    char contrasenia[DIM3];

    printf("\n Ingrese su nombre de usuario: ");
    fflush(stdin);
    fgets(nombreUsuario, DIM3, stdin);
    buscaSaltoLinea(nombreUsuario);

    printf("\n Ingrese la contrasenia: ");
    fflush(stdin);
    fgets(contrasenia, DIM3, stdin);
    buscaSaltoLinea(contrasenia);

    FILE * buffer = fopen(ARCHI_USUARIOS, "rb");
    if(buffer)
    {
        while(fread(&usuario, sizeof(datosUsuario), 1, buffer)==1)    // recorre todos los usuarios guardados y verifica que coincidan las credenciales
        {
            if(strcmp(usuario.nombre, nombreUsuario)==0 && strcmp(usuario.contra, contrasenia)==0)  // si lo encuentra, cierra el archivo para dejar de recorrerlo
            {
                printf("\n Ha iniciado sesion correctamente! Bienvenido %s \n", usuario.nombre);
                fclose(buffer);
                return usuario;                                                                     // es pecado esto pero no encontre otra forma de poder hacerlo bien, hay dos return en la funcion
            }
        }
    }
    fclose(buffer);
    printf("\n ERROR: Nombre de usuario o contrasenia incorrectos.\n");
    datosUsuario noSeEncontroUsuario = {" ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " ", " "}; // creo una variable "aux" y la lleno con datos inutiles, no se si esta del todo correcto porque hay datos tipo int, char
                                                                                                     // y otros definidos por nosotros con sus respectivos campos
    return noSeEncontroUsuario;
}
