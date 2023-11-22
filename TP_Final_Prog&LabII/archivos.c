#include "archivos.h"

///Archivos de Cartas
//Carga
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

//Muestra
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

void muestraArchiCartasPorNombre(char nombrePokemonAMostrar[]) //Muestra Base de datos por nombre recibido por parametro
{
    FILE * archi = fopen(ARCHI_CARTAS, "rb");
    if(archi)
    {
        stCarta cartitaAMostrar;
        while(!feof(archi))
        {
            fread(&cartitaAMostrar, sizeof(stCarta), 1, archi);
            if(!feof(archi) && strstr(cartitaAMostrar.nombre, nombrePokemonAMostrar) != NULL)
                muestraCarta(cartitaAMostrar);
        }
        fclose(archi);
    }
}

void muestraArchiCartasPorRareza(char rarezaAMostrar[]) //Muestra Base de datos Por rarezas Recibidas por parametro
{
    FILE * archi = fopen(ARCHI_CARTAS, "rb");
    if(archi)
    {
        stCarta cartitaAMostrar;
        while(!feof(archi))
        {
            fread(&cartitaAMostrar, sizeof(stCarta), 1, archi);
            if(!feof(archi) && strcmpi(cartitaAMostrar.rareza, rarezaAMostrar) == 0)
                muestraCarta(cartitaAMostrar);
        }
        fclose(archi);
    }
}

void muestraArchiCartasPorExpansion(char expansionAMostrar[]) //Muestra Base de datos Por Expansion
{
    FILE * archi = fopen(ARCHI_CARTAS, "rb");
    if(archi)
    {
        stCarta cartitaAMostrar;
        while(!feof(archi))
        {
            fread(&cartitaAMostrar, sizeof(stCarta), 1, archi);
            if(!feof(archi) && strcmpi(cartitaAMostrar.expansionCarta.expansionTitulo, expansionAMostrar) == 0 )
                muestraCarta(cartitaAMostrar);
        }
        fclose(archi);
    }
}

void muestraArchiCartasPorSubExpansion(char subExpansionAMostrar[]) //Muestra Base de datos Por SubExpansion
{
    FILE * archi = fopen(ARCHI_CARTAS, "rb");
    if(archi)
    {
        stCarta cartitaAMostrar;
        while(!feof(archi))
        {
            fread(&cartitaAMostrar, sizeof(stCarta), 1, archi);
            if(!!feof(archi) && strcmpi(cartitaAMostrar.expansionCarta.expansionSubTit, subExpansionAMostrar) == 0 ) // por alguna razon nunca entra al "if"
                muestraCarta(cartitaAMostrar);
        }
        fclose(archi);
    }
}

void muestraArchiCartasPorClase(char claseAMostrar[])
{
    if(strcmp(claseAMostrar, "Pokemon") == 0)
        muestraArchiCartasPokemon();
    else if(strcmp(claseAMostrar, "Energia") == 0)
        muestraArchiCartasEnergia();
    else if(strcmp(claseAMostrar, "Entrenador") == 0)
        muestraArchiCartasEntrenador();
    else
        printf("\n Esa clase no existe ");
}

void muestraArchiCartasPokemon()
{
    FILE * archi = fopen(ARCHI_CARTAS, "rb");
    if(archi)
    {
        stCarta cartitaAMostrar;
        while(!feof(archi))
        {
            fread(&cartitaAMostrar, sizeof(stCarta), 1, archi);
            if(!feof(archi) && cartitaAMostrar.claseCarta.datosPokemon.estado == 1)
                muestraCarta(cartitaAMostrar);
        }
        fclose(archi);
    }
}

void muestraArchiCartasEnergia()
{
    FILE * archi = fopen(ARCHI_CARTAS, "rb");
    if(archi)
    {
        stCarta cartitaAMostrar;
        while(!feof(archi))
        {
            fread(&cartitaAMostrar, sizeof(stCarta), 1, archi);
            if(!feof(archi) && cartitaAMostrar.claseCarta.datosEnergia.estado == 1)
                muestraCarta(cartitaAMostrar);
        }
        fclose(archi);
    }
}

void muestraArchiCartasEntrenador()
{
    FILE * archi = fopen(ARCHI_CARTAS, "rb");
    if(archi)
    {
        stCarta cartitaAMostrar;
        while(!feof(archi))
        {
            fread(&cartitaAMostrar, sizeof(stCarta), 1, archi);
            if(!feof(archi) && cartitaAMostrar.claseCarta.datosEntrenador.estado == 1)
                muestraCarta(cartitaAMostrar);
        }
        fclose(archi);
    }
}

//Busqueda
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
//Carga Del Usuario
void cargaArchiUsuarios(datosUsuario usuarioAGuardar)
{
    FILE * archi = fopen(ARCHI_USUARIOS, "ab");

    if(archi)
    {
        fwrite(&usuarioAGuardar, sizeof(datosUsuario), 1, archi);
        fclose(archi);
    }
    else
        printf("\n El archivo no se abrio correctamente. \n");
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

//Carga Datos del Usuario
stListaD * cargaColeccionPorParametro(datosUsuario datosUsuarioACargar)
{
    int idABuscar;
    int datosCargados = 0;
    stListaD * coleccionACargar = setNULL();
    stCarta cartaACargar;
    while(datosCargados < datosUsuarioACargar.validosDatosColeccion)
    {
        idABuscar = datosUsuarioACargar.datosColeccion[datosCargados].idCartaEnColeccion;
        cartaACargar = buscaCartaPorIdEnArchi(idABuscar);
        cartaACargar.cant = datosUsuarioACargar.datosColeccion[datosCargados].cantCartaEnColeccion;
        coleccionACargar = agregarPorIDColeccion(coleccionACargar, creaNodoColeccion(cartaACargar));
        datosCargados++;
    }
    return coleccionACargar;
}
void cargaMazoPorParametro(stMazo *P,datosUsuario datosuarioAcargar)
{
    int idAbuscar;

    int datoscargados=0;


    InicMazo(P);

    stCarta CartaACargar;

    while(datoscargados<datosuarioAcargar.validosDatosMazo)
    {
        idAbuscar=datosuarioAcargar.datosMazo[datoscargados].idCartaEnMazo;
        CartaACargar=buscaCartaPorIdEnArchi(idAbuscar);
        CartaACargar.cant=datosuarioAcargar.datosMazo[datoscargados].cantCartaEnMazo;
        apilarMazo(P,CartaACargar);
        datoscargados++;
    }

}

void cargaBuzonPorParametro(datosUsuario datosUsuarioACargar, stBuzon * buzonACargar)
{
    int datosCargados = 0;
    stNotificacion * notificacionAGuardar = setNULL();
    while(datosCargados < datosUsuarioACargar.validosDatosBuzon)
    {
        notificacionAGuardar = creaNodoNotificacion(datosUsuarioACargar.datosBuzon[datosCargados]);
        agregarAlFinalBuzon(buzonACargar, notificacionAGuardar);
        datosCargados++;
    }
}

//Muestra Datos Usuario
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

void muestraUsuariosAIntercambiarEnArchi(datosUsuario usuarioActual)
{
    FILE * archi = fopen(ARCHI_USUARIOS, "rb");
    if(archi)
    {
        datosUsuario usuarioAMostrar;
        while(!feof(archi))
        {
            fread(&usuarioAMostrar, sizeof(datosUsuario), 1, archi);
            printf("\n --------------------");
            if(!feof(archi) && usuarioActual.id != usuarioAMostrar.id)
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

//Busqueda
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

//Manejo Del Sistema
void hacerIntercambio(stUsuario * usuarioActual)
{
    int idDemandado;
    int cartaDemandada;
    int cartaOfrecida;
    int estado = 0;
    char control = 'n';
    stNotificacion * nuevaNotificacionDeIntercambio;

    do
    {
        printf("\n Los usuarios Disponibles para intercambio son : ");
        muestraUsuariosAIntercambiarEnArchi(usuarioActual->dato);

        printf("\n Ingrese Id de Usuario que desea ver coleccion disponible a intercambiar : ");
        scanf("%d", &idDemandado);

        muestraColeccionIntercambioUsuarioEnArchi(idDemandado);

        printf("\n Desea Continuar con este Usuario? s/n ");
        fflush(stdin);
        scanf("%c", &control);
    }
    while(control == 'n');

    datosUsuario parteDemandada = buscaUsuarioPorIdEnArchi(idDemandado);
    stListaD * coleccionDemandado = cargaColeccionPorParametro(parteDemandada);
    printf("\n Elija el ID de la carta que Demanda a intercambiar: ");
    scanf("%d", &cartaDemandada);

    muestraMazoIntercambio(usuarioActual->coleccion);
    printf("\n Elija el ID de la carta que Ofrece a intercambiar: ");
    scanf("%d", &cartaOfrecida);

    stCarta demanda = buscarCartaPorIDYLaRetorna(coleccionDemandado, cartaDemandada);
    stCarta oferta = buscarCartaPorIDYLaRetorna(usuarioActual->coleccion, cartaOfrecida);

    usuarioActual->dato = guardaIndicadorBuzon(usuarioActual->dato, usuarioActual->dato, parteDemandada, oferta, demanda);
    parteDemandada = guardaIndicadorBuzon(parteDemandada, usuarioActual->dato, parteDemandada, oferta, demanda);

    nuevaNotificacionDeIntercambio = intercambio(&usuarioActual->coleccion, &coleccionDemandado, usuarioActual->dato.datosBuzon[usuarioActual->dato.validosDatosBuzon-1]);

    agregarAlFinalBuzon(&usuarioActual->buzon, nuevaNotificacionDeIntercambio);
    FILE * archi = fopen(ARCHI_USUARIOS, "r+b");
    if(archi)
    {
        datosUsuario usuarioEnArchi;
        while(!feof(archi))
        {
            fread(&usuarioEnArchi, sizeof(datosUsuario), 1, archi);
            if(!feof(archi) && usuarioEnArchi.id == idDemandado)
            {
                fseek(archi, -sizeof(datosUsuario), SEEK_CUR);
                usuarioEnArchi = parteDemandada;
                fwrite(&usuarioEnArchi, sizeof(datosUsuario), 1, archi);
                break;
            }
        }
        fclose(archi);
    }
    printf("\n Intercambio realizado. ");
}

//Guardado De Datos
void guardaDatosNuevos(datosUsuario usuarioACambiar) // guarda los datos del usuario
{
    FILE * archi = fopen(ARCHI_USUARIOS, "r+b");
    if(archi)
    {
        datosUsuario usuarioEnArchi;
        while(!feof(archi))
        {
            fread(&usuarioEnArchi, sizeof(datosUsuario), 1, archi);
            if(!feof(archi) && usuarioEnArchi.id == usuarioACambiar.id)
            {
                fseek(archi, -sizeof(datosUsuario), SEEK_CUR);
                usuarioEnArchi = usuarioACambiar;
                fwrite(&usuarioEnArchi, sizeof(datosUsuario), 1, archi);
                break;
            }
        }
        fclose(archi);
    }
}
