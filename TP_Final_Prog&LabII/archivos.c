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

stCarta buscaCartaPorIdEnArchi(int idAbuscar) //Buscca y retorna datos de carta pedidos apartir de un id //////////////////////////// Falta testear
{
    int estado = 0;
    stCarta cartaBuscada;

    FILE * archi = fopen(ARCHI_CARTAS, "rb");
    if(archi)
    {
        while(!feof(archi) && estado == 0)
        {
            fread(&cartaBuscada, sizeof(cartaBuscada), 1, archi);
            if(!feof(archi) && cartaBuscada.id == idAbuscar)
                estado = 1;
        }
        fclose(archi);
    }
    return cartaBuscada;
}

///Archivo de Usuarios
int buscaUltimoIDEnArchiUsuarios()
{
    FILE * archi = fopen(ARCHI_USUARIOS, "rb");
    int ultimoID = 0;
    if(archi)
    {
        datosUsuario usuarioEnArchi;
        fseek(archi, -sizeof(datosUsuario), SEEK_END);
        fread(&usuarioEnArchi, sizeof(datosUsuario), 1, archi);
        ultimoID = usuarioEnArchi.id;

        fclose(archi);
    }
    return ultimoID;
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

datosUsuario iniciarSesion(int * login)
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
                *login = 1;
                fclose(buffer);
            }
        }
    }
    if((*login)==0)
    {
        fclose(buffer);
        printf("\n ERROR: Nombre de usuario o contrasenia incorrectos.\n");
        usuario = vaciarDatosUsuario();
    }

    return usuario;
}

datosUsuario cerrarSesion(int * login)
{
    datosUsuario usuario = vaciarDatosUsuario();
    *login = 0;

    return usuario;
}

datosUsuario buscaUsuarioPorIdEnArchi(int idAbuscar) //Buscca y retorna datos de usuario pedidos apartir de un id //////////////////////////// Falta testear
{
    int estado = 0;
    datosUsuario usuarioBuscado;

    FILE * archi = fopen(ARCHI_USUARIOS, "rb");
    if(archi)
    {
        while(!feof(archi) && estado == 0)
        {
            fread(&usuarioBuscado, sizeof(datosUsuario), 1, archi);
            if(!feof(archi) && usuarioBuscado.id == idAbuscar)
                estado = 1;
        }
        fclose(archi);
    }
    return usuarioBuscado;
}

void muestraUsuariosEnArchi()
{
    FILE * archi = fopen(ARCHI_USUARIOS, "rb");
    if(archi)
    {
        datosUsuario usuarioAMostrar;
        while(!feof(archi))
        {
            fread(&usuarioAMostrar, sizeof(datosUsuario), 1, archi);
            printf("\n --------------------");
            if(!feof(archi))
            {
                printf("\n Id Usuario....: %d", usuarioAMostrar.id);
                printf("\n Nombre Usuario: %s", usuarioAMostrar.nombre);
            }
        }
        printf("\n --------------------");
        fclose(archi);
    }
}

void muestraColeccionIntercambioUsuarioEnArchi(int idDeUsuarioAMostrar)
{
    datosUsuario usuarioQueTieneColeccionAMostrar = buscaUsuarioPorIdEnArchi(idDeUsuarioAMostrar);
    stListaD * coleccionDeUsuarioAMostrar = cargaColeccionPorParametro(usuarioQueTieneColeccionAMostrar);
    muestraMazoIntercambio(coleccionDeUsuarioAMostrar);
}

void hacerIntercambio(stUsuario * usuarioActual)
{
    int idDemandado;
    int cartaDemandada;
    int cartaOfrecida;
    int estado = 0;
    char control = 'n';
    stNotificacion * nuevaNotificacionDeIntercambio;

    do{
    printf("\n Los usuarios Disponibles para intercambio son : ");
    muestraUsuariosEnArchi();

    printf("\n Ingrese Id de Usuario que desea ver coleccion disponible a intercambiar : ");
    scanf("%d", &idDemandado);

    muestraColeccionIntercambioUsuarioEnArchi(idDemandado);

    printf("\n Desea Continuar con este Usuario? s/n ");
    fflush(stdin);
    scanf("%c" , &control);
    }while(control == 'n');

    datosUsuario parteDemandada = buscaUsuarioPorIdEnArchi(idDemandado);
    stListaD * coleccionDemandado = cargaColeccionPorParametro(parteDemandada);
    printf("\n Elija el ID de la carta que Demanda a intercambiar: ");
    scanf("%d", &cartaDemandada);

    muestraMazoIntercambio(usuarioActual->coleccion);
    printf("\n Elija el ID de la carta que Ofrece a intercambiar: ");
    scanf("%d", &cartaOfrecida);

    stCarta demanda = buscarCartaPorIDYLaRetorna(coleccionDemandado , cartaDemandada);
    stCarta oferta = buscarCartaPorIDYLaRetorna(usuarioActual->coleccion , cartaOfrecida);

    usuarioActual->dato = guardaIndicadorBuzon(usuarioActual->dato , usuarioActual->dato , parteDemandada , oferta , demanda);
    parteDemandada = guardaIndicadorBuzon(parteDemandada , usuarioActual->dato , parteDemandada , oferta , demanda);

    nuevaNotificacionDeIntercambio = intercambio(&usuarioActual->coleccion , &coleccionDemandado , usuarioActual->dato.datosBuzon[usuarioActual->dato.validosDatosBuzon-1]);

    agregarAlFinalBuzon(usuarioActual->buzon , nuevaNotificacionDeIntercambio);
    FILE * archi = fopen(ARCHI_USUARIOS, "r+b");
    if(archi)
    {
        datosUsuario usuarioEnArchi;
        while(!feof(archi) && estado == 0)
        {
            fread(&usuarioEnArchi, sizeof(datosUsuario), 1, archi);
            if(!feof(archi) && usuarioEnArchi.id == idDemandado)
                {
                    fseek(archi, -sizeof(stCarta), SEEK_CUR);
                    fread(&usuarioEnArchi, sizeof(datosUsuario), 1, archi);
                    usuarioEnArchi = parteDemandada;
                    fwrite(&usuarioEnArchi , sizeof(datosUsuario) , 1 , archi);
                    estado = 1;
                }
        }
        fclose(archi);
    }
}
