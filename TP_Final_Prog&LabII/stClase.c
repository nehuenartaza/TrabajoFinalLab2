#include "stClase.h"

stClase cargaClasePokemon(stClase claseACargar_F)   //Cargar de cada caso
{
    stPokemon pokemonAGuardar;
    pokemonAGuardar.estado = 1;
    printf("\n Ingrese Hit Points del Pokemon: ");
    scanf("%d", &pokemonAGuardar.puntosAtaque);
    printf("\n Ingrese Tipo del Pokemon: ");
    fflush(stdin);
    fgets(pokemonAGuardar.tipo, DIM3, stdin);
    buscaSaltoLinea(pokemonAGuardar.tipo);
    char opcion;
    printf("\n El pokemon tiene 2 ataques? s/n ");
    scanf("%c", &opcion);
    if(opcion == 's')
    {
        printf("\n Ingrese el Ataque Nro 1 del Pokemon: ");
        fflush(stdin);
        fgets(pokemonAGuardar.ataqueNro1, DIM1, stdin);
        buscaSaltoLinea(pokemonAGuardar.ataqueNro1);
        printf("\n Ingrese el Ataque Nro 2 del Pokemon: ");
        fflush(stdin);
        fgets(pokemonAGuardar.ataqueNro2, DIM1, stdin);
        buscaSaltoLinea(pokemonAGuardar.ataqueNro2);
    }
    else
    {
        printf("\n Ingrese el Ataque del Pokemon: ");
        fflush(stdin);
        fgets(pokemonAGuardar.ataqueNro1, DIM1, stdin);
        buscaSaltoLinea(pokemonAGuardar.ataqueNro1);
        strcpy(pokemonAGuardar.ataqueNro2, "Ninguno.");
    }
    claseACargar_F.datosPokemon = pokemonAGuardar;
    claseACargar_F.datosEnergia.estado = 0;
    claseACargar_F.datosEntrenador.estado = 0;
    return claseACargar_F;
}

stClase cargaClaseEnergia(stClase claseACargar_F)
{
    stEnergia energiaAGuardar;
    energiaAGuardar.estado = 1;
    printf("\n Ingrese Tipo de la Energia: ");
    fflush(stdin);
    fgets(energiaAGuardar.tipoEnergia, DIM3, stdin);
    buscaSaltoLinea(energiaAGuardar.tipoEnergia);
    claseACargar_F.datosEnergia = energiaAGuardar;
    claseACargar_F.datosPokemon.estado = 0;
    claseACargar_F.datosEntrenador.estado = 0;
    return claseACargar_F;
}

stClase cargaClaseEntrenador(stClase claseACargar_F)
{
    stEntrenador entrenadorAGuardar;
    entrenadorAGuardar.estado = 1;

    printf("\n Ingrese Efecto del Entrenador: ");
    fflush(stdin);
    fgets(entrenadorAGuardar.efecto, DIM1, stdin);
    buscaSaltoLinea(entrenadorAGuardar.efecto);

    claseACargar_F.datosEntrenador = entrenadorAGuardar;
    claseACargar_F.datosPokemon.estado = 0;
    claseACargar_F.datosEnergia.estado = 0;

    return claseACargar_F;
}

stClase cargaClaseUsuario(stClase claseACargar_F)   //Carga Preguntando que caso
{
    int opcion;
    do
    {
        printf("\n Que Clase quiere cargar?");
        printf("\n Ingrese 1 para Pokemon");
        printf("\n Ingrese 2 para Energia");
        printf("\n Ingrese 3 para Entrenador");
        printf("\n Su eleccion es: ");
        scanf("%d", &opcion);

        if(opcion == 1)
            claseACargar_F = cargaClasePokemon(claseACargar_F);
        else if(opcion == 2)
            claseACargar_F = cargaClaseEnergia(claseACargar_F);
        else if(opcion == 3)
            claseACargar_F = cargaClaseEntrenador(claseACargar_F);
        else
            printf("\n Opcion Invalida. \n");
    }
    while(validaOpcionCargaClaseUsuario(opcion) == 0);

    return claseACargar_F;
}

void muestraClase(stClase claseAMostrar)    //Muestra la clase
{
    if(claseAMostrar.datosPokemon.estado == 1)
        muestraPokemon(claseAMostrar.datosPokemon);
    else if(claseAMostrar.datosEntrenador.estado == 1)
        muestraEntrenador(claseAMostrar.datosEntrenador);
    else if(claseAMostrar.datosEnergia.estado == 1)
        muestraEnergia(claseAMostrar.datosEnergia);
}

int validaOpcionCargaClaseUsuario(int opcion_F) //Valida Opcion
{
    int rta;

    if(opcion_F == 1 || opcion_F == 2 || opcion_F == 3)
        rta = 1;
    else
        rta = 0;

    return rta;
}
